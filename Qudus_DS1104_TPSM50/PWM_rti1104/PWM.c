/*
 * PWM.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "PWM".
 *
 * Model version              : 1.20
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Jul  4 12:20:58 2025
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PWM_trc_ptr.h"
#include "PWM.h"
#include <math.h>
#include "rtwtypes.h"
#include "PWM_private.h"

/* Block signals (default storage) */
B_PWM_T PWM_B;

/* Continuous states */
X_PWM_T PWM_X;

/* Periodic continuous states */
PeriodicIndX_PWM_T PWM_PeriodicIndX;
PeriodicRngX_PWM_T PWM_PeriodicRngX;

/* Real-time model */
static RT_MODEL_PWM_T PWM_M_;
RT_MODEL_PWM_T *const PWM_M = &PWM_M_;

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  PWM_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       4,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void PWM_output(void)
{
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(PWM_M)) {
    /* set solver stop time */
    if (!(PWM_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PWM_M->solverInfo, ((PWM_M->Timing.clockTickH0 + 1)
        * PWM_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PWM_M->solverInfo, ((PWM_M->Timing.clockTick0 + 1) *
        PWM_M->Timing.stepSize0 + PWM_M->Timing.clockTickH0 *
        PWM_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PWM_M)) {
    PWM_M->Timing.t[0] = rtsiGetT(&PWM_M->solverInfo);
  }

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S9>/Constant'
   */
  PWM_B.Compare = (PWM_P.Constant_Value_j != PWM_P.Constant_Value);

  /* Sum: '<S14>/Sum' incorporates:
   *  Constant: '<S14>/Constant'
   */
  PWM_B.Sum = PWM_P.PWMGenerator_Tper - PWM_B.Probe[0];

  /* Product: '<S14>/Product' incorporates:
   *  Constant: '<S14>/Constant'
   */
  PWM_B.Product = PWM_P.PWMGenerator_Tper / PWM_B.Sum;

  /* Integrator: '<S15>/Integrator' */
  PWM_B.Integrator = PWM_X.Integrator_CSTATE;

  /* Product: '<S14>/Product1' */
  PWM_B.Product1 = PWM_B.Product * PWM_B.Integrator;

  /* Bias: '<S14>/Bias' */
  PWM_B.Bias = PWM_B.Probe[0] + PWM_P.PWMGenerator_Tper;

  /* Product: '<S14>/Product2' */
  PWM_B.Product2 = PWM_B.Product1 / PWM_B.Bias;

  /* Rounding: '<S14>/Rounding Function' */
  PWM_B.RoundingFunction = floor(PWM_B.Product2);

  /* Product: '<S14>/Product3' */
  PWM_B.Product3 = PWM_B.RoundingFunction * PWM_B.Bias;

  /* Sum: '<S14>/Sum1' */
  PWM_B.Sum1 = PWM_B.Product1 - PWM_B.Product3;

  /* Integrator: '<S16>/Integrator' */
  PWM_B.Integrator_p = PWM_X.Integrator_CSTATE_o;

  /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  switch ((int32_T)PWM_P.Carriercounter_CarrCount) {
   case 1:
    /* MultiPortSwitch: '<S8>/Multiport Switch' */
    PWM_B.MultiportSwitch = PWM_B.Sum1;
    break;

   case 2:
    /* Sum: '<S8>/Sum3' incorporates:
     *  Constant: '<S8>/Constant6'
     */
    PWM_B.Sum3_o = PWM_P.PWMGenerator_Tper - PWM_B.Sum1;

    /* MultiPortSwitch: '<S8>/Multiport Switch' */
    PWM_B.MultiportSwitch = PWM_B.Sum3_o;
    break;

   default:
    /* Sum: '<S8>/Sum4' incorporates:
     *  Constant: '<S8>/Constant10'
     */
    u0 = 2.0 * PWM_P.PWMGenerator_Tper;

    /* Sum: '<S8>/Sum4' */
    PWM_B.Sum4_m = u0 - PWM_B.Integrator_p;

    /* Switch: '<S13>/Switch' */
    if (PWM_B.Sum4_m > PWM_P.PWMGenerator_Tper) {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant2'
       */
      PWM_B.Switch_h = PWM_P.Constant2_Value_g;
    } else {
      /* Switch: '<S13>/Switch' */
      PWM_B.Switch_h = PWM_B.Sum4_m;
    }

    /* End of Switch: '<S13>/Switch' */

    /* Switch: '<S12>/Switch' */
    if (PWM_B.Integrator_p > PWM_P.PWMGenerator_Tper) {
      /* Switch: '<S12>/Switch' incorporates:
       *  Constant: '<S12>/Constant2'
       */
      PWM_B.Switch_k = PWM_P.Constant2_Value;
    } else {
      /* Switch: '<S12>/Switch' */
      PWM_B.Switch_k = PWM_B.Integrator_p;
    }

    /* End of Switch: '<S12>/Switch' */

    /* Sum: '<S8>/Sum5' */
    PWM_B.Sum5_g = PWM_B.Switch_k + PWM_B.Switch_h;

    /* MultiPortSwitch: '<S8>/Multiport Switch' */
    PWM_B.MultiportSwitch = PWM_B.Sum5_g;
    break;
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

  /* Gain: '<S8>/Gain1' */
  u0 = 1.0 / PWM_P.PWMGenerator_Tper;

  /* Gain: '<S8>/Gain1' */
  PWM_B.Gain1 = u0 * PWM_B.MultiportSwitch;

  /* Saturate: '<S8>/Saturation' */
  u0 = PWM_B.Gain1;
  u1 = PWM_P.Saturation_LowerSat;
  u2 = PWM_P.Saturation_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S8>/Saturation' */
    PWM_B.Saturation = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S8>/Saturation' */
    PWM_B.Saturation = u1;
  } else {
    /* Saturate: '<S8>/Saturation' */
    PWM_B.Saturation = u0;
  }

  /* End of Saturate: '<S8>/Saturation' */

  /* Gain: '<S8>/Gain' */
  PWM_B.Gain = PWM_P.Carriercounter_Range * PWM_B.Saturation;

  /* Bias: '<S8>/Bias' */
  u0 = -PWM_P.Carriercounter_Range + 1.0;

  /* Bias: '<S8>/Bias' */
  PWM_B.Bias_m = PWM_B.Gain + u0;

  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant'
   */
  PWM_B.RelationalOperator = (PWM_P.Constant_Value_j >= PWM_B.Bias_m);

  /* Logic: '<S5>/Logical Operator' */
  PWM_B.LogicalOperator = (PWM_B.Compare && PWM_B.RelationalOperator);

  /* DataTypeConversion: '<S5>/Data Type Conversion2' */
  PWM_B.DataTypeConversion2 = PWM_B.LogicalOperator;

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  PWM_B.Compare_o = (PWM_B.DataTypeConversion2 <= PWM_P.CompareToConstant_const);
  if (rtmIsMajorTimeStep(PWM_M)) {
    /* S-Function (rti_commonblock): '<S3>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:BIT_IO Group:BIT_OUT */
    if (PWM_B.Compare_o > 0) {
      ds1104_bit_io_set(DS1104_DIO2);
    } else {
      ds1104_bit_io_clear(DS1104_DIO2);
    }

    /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    PWM_B.DataTypeConversion = PWM_P.Constant3_Value;

    /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    PWM_B.DataTypeConversion_p = PWM_P.Constant3_Value;
  }

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S18>/Constant'
   */
  PWM_B.Compare_n = (PWM_P.Constant1_Value != PWM_P.Constant_Value_m);

  /* Sum: '<S23>/Sum' incorporates:
   *  Constant: '<S23>/Constant'
   */
  PWM_B.Sum_g = PWM_P.PWMGenerator1_Tper - PWM_B.Probe_o[0];

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S23>/Constant'
   */
  PWM_B.Product_d = PWM_P.PWMGenerator1_Tper / PWM_B.Sum_g;

  /* Integrator: '<S24>/Integrator' */
  PWM_B.Integrator_m = PWM_X.Integrator_CSTATE_l;

  /* Product: '<S23>/Product1' */
  PWM_B.Product1_i = PWM_B.Product_d * PWM_B.Integrator_m;

  /* Bias: '<S23>/Bias' */
  PWM_B.Bias_f = PWM_B.Probe_o[0] + PWM_P.PWMGenerator1_Tper;

  /* Product: '<S23>/Product2' */
  PWM_B.Product2_d = PWM_B.Product1_i / PWM_B.Bias_f;

  /* Rounding: '<S23>/Rounding Function' */
  PWM_B.RoundingFunction_e = floor(PWM_B.Product2_d);

  /* Product: '<S23>/Product3' */
  PWM_B.Product3_i = PWM_B.RoundingFunction_e * PWM_B.Bias_f;

  /* Sum: '<S23>/Sum1' */
  PWM_B.Sum1_i = PWM_B.Product1_i - PWM_B.Product3_i;

  /* Integrator: '<S25>/Integrator' */
  PWM_B.Integrator_c = PWM_X.Integrator_CSTATE_j;

  /* MultiPortSwitch: '<S17>/Multiport Switch' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  switch ((int32_T)PWM_P.Carriercounter_CarrCount_j) {
   case 1:
    /* MultiPortSwitch: '<S17>/Multiport Switch' */
    PWM_B.MultiportSwitch_k = PWM_B.Sum1_i;
    break;

   case 2:
    /* Sum: '<S17>/Sum3' incorporates:
     *  Constant: '<S17>/Constant6'
     */
    PWM_B.Sum3 = PWM_P.PWMGenerator1_Tper - PWM_B.Sum1_i;

    /* MultiPortSwitch: '<S17>/Multiport Switch' */
    PWM_B.MultiportSwitch_k = PWM_B.Sum3;
    break;

   default:
    /* Sum: '<S17>/Sum4' incorporates:
     *  Constant: '<S17>/Constant10'
     */
    u0 = 2.0 * PWM_P.PWMGenerator1_Tper;

    /* Sum: '<S17>/Sum4' */
    PWM_B.Sum4 = u0 - PWM_B.Integrator_c;

    /* Switch: '<S22>/Switch' */
    if (PWM_B.Sum4 > PWM_P.PWMGenerator1_Tper) {
      /* Switch: '<S22>/Switch' incorporates:
       *  Constant: '<S22>/Constant2'
       */
      PWM_B.Switch = PWM_P.Constant2_Value_g4;
    } else {
      /* Switch: '<S22>/Switch' */
      PWM_B.Switch = PWM_B.Sum4;
    }

    /* End of Switch: '<S22>/Switch' */

    /* Switch: '<S21>/Switch' */
    if (PWM_B.Integrator_c > PWM_P.PWMGenerator1_Tper) {
      /* Switch: '<S21>/Switch' incorporates:
       *  Constant: '<S21>/Constant2'
       */
      PWM_B.Switch_i = PWM_P.Constant2_Value_a;
    } else {
      /* Switch: '<S21>/Switch' */
      PWM_B.Switch_i = PWM_B.Integrator_c;
    }

    /* End of Switch: '<S21>/Switch' */

    /* Sum: '<S17>/Sum5' */
    PWM_B.Sum5 = PWM_B.Switch_i + PWM_B.Switch;

    /* MultiPortSwitch: '<S17>/Multiport Switch' */
    PWM_B.MultiportSwitch_k = PWM_B.Sum5;
    break;
  }

  /* End of MultiPortSwitch: '<S17>/Multiport Switch' */

  /* Gain: '<S17>/Gain1' */
  u0 = 1.0 / PWM_P.PWMGenerator1_Tper;

  /* Gain: '<S17>/Gain1' */
  PWM_B.Gain1_a = u0 * PWM_B.MultiportSwitch_k;

  /* Saturate: '<S17>/Saturation' */
  u0 = PWM_B.Gain1_a;
  u1 = PWM_P.Saturation_LowerSat_c;
  u2 = PWM_P.Saturation_UpperSat_g;
  if (u0 > u2) {
    /* Saturate: '<S17>/Saturation' */
    PWM_B.Saturation_k = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S17>/Saturation' */
    PWM_B.Saturation_k = u1;
  } else {
    /* Saturate: '<S17>/Saturation' */
    PWM_B.Saturation_k = u0;
  }

  /* End of Saturate: '<S17>/Saturation' */

  /* Gain: '<S17>/Gain' */
  PWM_B.Gain_o = PWM_P.Carriercounter_Range_j * PWM_B.Saturation_k;

  /* Bias: '<S17>/Bias' */
  u0 = -PWM_P.Carriercounter_Range_j + 1.0;

  /* Bias: '<S17>/Bias' */
  PWM_B.Bias_c = PWM_B.Gain_o + u0;

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  PWM_B.RelationalOperator_m = (PWM_P.Constant1_Value >= PWM_B.Bias_c);

  /* Logic: '<S6>/Logical Operator' */
  PWM_B.LogicalOperator_p = (PWM_B.Compare_n && PWM_B.RelationalOperator_m);

  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  PWM_B.DataTypeConversion2_c = PWM_B.LogicalOperator_p;

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  PWM_B.Compare_b = (PWM_B.DataTypeConversion2_c <=
                     PWM_P.CompareToConstant1_const);
  if (rtmIsMajorTimeStep(PWM_M)) {
    /* S-Function (rti_commonblock): '<S4>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:BIT_IO Group:BIT_OUT */
    if (PWM_B.Compare_b > 0) {
      ds1104_bit_io_set(DS1104_DIO3);
    } else {
      ds1104_bit_io_clear(DS1104_DIO3);
    }

    /* DataTypeConversion: '<S24>/Data Type Conversion' incorporates:
     *  Constant: '<S17>/Constant3'
     */
    PWM_B.DataTypeConversion_k = PWM_P.Constant3_Value_i;

    /* DataTypeConversion: '<S25>/Data Type Conversion' incorporates:
     *  Constant: '<S17>/Constant3'
     */
    PWM_B.DataTypeConversion_j = PWM_P.Constant3_Value_i;
  }
}

/* Model update function */
void PWM_update(void)
{
  if (rtmIsMajorTimeStep(PWM_M)) {
    rt_ertODEUpdateContinuousStates(&PWM_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PWM_M->Timing.clockTick0)) {
    ++PWM_M->Timing.clockTickH0;
  }

  PWM_M->Timing.t[0] = rtsiGetSolverStopTime(&PWM_M->solverInfo);

  {
    /* Update absolute timer for sample time: [1.0E-5s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    PWM_M->Timing.clockTick1++;
    if (!PWM_M->Timing.clockTick1) {
      PWM_M->Timing.clockTickH1++;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void PWM_derivatives(void)
{
  XDot_PWM_T *_rtXdot;
  _rtXdot = ((XDot_PWM_T *) PWM_M->derivs);

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE = PWM_B.DataTypeConversion;

  /* Derivatives for Integrator: '<S16>/Integrator' */
  _rtXdot->Integrator_CSTATE_o = PWM_B.DataTypeConversion_p;

  /* Derivatives for Integrator: '<S24>/Integrator' */
  _rtXdot->Integrator_CSTATE_l = PWM_B.DataTypeConversion_k;

  /* Derivatives for Integrator: '<S25>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = PWM_B.DataTypeConversion_j;
}

/* Model initialize function */
void PWM_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)PWM_M, 0,
                sizeof(RT_MODEL_PWM_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PWM_M->solverInfo, &PWM_M->Timing.simTimeStep);
    rtsiSetTPtr(&PWM_M->solverInfo, &rtmGetTPtr(PWM_M));
    rtsiSetStepSizePtr(&PWM_M->solverInfo, &PWM_M->Timing.stepSize0);
    rtsiSetdXPtr(&PWM_M->solverInfo, &PWM_M->derivs);
    rtsiSetContStatesPtr(&PWM_M->solverInfo, (real_T **) &PWM_M->contStates);
    rtsiSetNumContStatesPtr(&PWM_M->solverInfo, &PWM_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PWM_M->solverInfo,
      &PWM_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PWM_M->solverInfo,
      &PWM_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PWM_M->solverInfo,
      &PWM_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PWM_M->solverInfo, (&rtmGetErrorStatus(PWM_M)));
    rtsiSetRTModelPtr(&PWM_M->solverInfo, PWM_M);
  }

  rtsiSetSimTimeStep(&PWM_M->solverInfo, MAJOR_TIME_STEP);
  PWM_M->intgData.f[0] = PWM_M->odeF[0];
  PWM_M->contStates = ((X_PWM_T *) &PWM_X);
  PWM_M->periodicContStateIndices = ((int_T*) PWM_PeriodicIndX);
  PWM_M->periodicContStateRanges = ((real_T*) PWM_PeriodicRngX);
  rtsiSetSolverData(&PWM_M->solverInfo, (void *)&PWM_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&PWM_M->solverInfo, false);
  rtsiSetSolverName(&PWM_M->solverInfo,"ode1");
  rtmSetTPtr(PWM_M, &PWM_M->Timing.tArray[0]);
  PWM_M->Timing.stepSize0 = 1.0E-5;

  /* block I/O */
  (void) memset(((void *) &PWM_B), 0,
                sizeof(B_PWM_T));

  /* states (continuous) */
  {
    (void) memset((void *)&PWM_X, 0,
                  sizeof(X_PWM_T));
  }

  /* Periodic continuous states */
  {
    (void) memset((void*) PWM_PeriodicIndX, 0,
                  4*sizeof(int_T));
    (void) memset((void*) PWM_PeriodicRngX, 0,
                  8*sizeof(real_T));
  }

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    PWM_rti_init_trc_pointers();
  }

  /* Start for Probe: '<S14>/Probe' */
  PWM_B.Probe[0] = 0.0;
  PWM_B.Probe[1] = 0.0;

  /* Start for Probe: '<S23>/Probe' */
  PWM_B.Probe_o[0] = 0.0;
  PWM_B.Probe_o[1] = 0.0;

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  PWM_X.Integrator_CSTATE = PWM_P.IntegratorwithWrappedStateDiscr;

  /* InitializeConditions for Integrator: '<S16>/Integrator' */
  PWM_X.Integrator_CSTATE_o = PWM_P.PWMGenerator_Tdelay;

  /* InitializeConditions for Integrator: '<S24>/Integrator' */
  PWM_X.Integrator_CSTATE_l = PWM_P.IntegratorwithWrappedStateDis_h;

  /* InitializeConditions for Integrator: '<S25>/Integrator' */
  PWM_X.Integrator_CSTATE_j = PWM_P.PWMGenerator1_Tdelay;

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[4] = { 0, 1, 2, 3 };

    real_T rootPeriodicContStateRanges[8] = { 0.0, 0.0001, 0.0, 0.0002, 0.0,
      0.0001, 0.0, 0.0002 };

    (void) memcpy((void*)PWM_PeriodicIndX, rootPeriodicContStateIndices,
                  4*sizeof(int_T));
    (void) memcpy((void*)PWM_PeriodicRngX, rootPeriodicContStateRanges,
                  8*sizeof(real_T));
  }
}

/* Model terminate function */
void PWM_terminate(void)
{
  /* (no terminate code required) */
}
