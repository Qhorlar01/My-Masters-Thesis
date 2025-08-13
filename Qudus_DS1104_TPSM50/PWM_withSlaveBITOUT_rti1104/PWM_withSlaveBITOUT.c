/*
 * PWM_withSlaveBITOUT.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "PWM_withSlaveBITOUT".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Jul 17 17:59:20 2025
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PWM_withSlaveBITOUT_trc_ptr.h"
#include "PWM_withSlaveBITOUT.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>

/* Block signals (default storage) */
B_PWM_withSlaveBITOUT_T PWM_withSlaveBITOUT_B;

/* Block states (default storage) */
DW_PWM_withSlaveBITOUT_T PWM_withSlaveBITOUT_DW;

/* Real-time model */
static RT_MODEL_PWM_withSlaveBITOUT_T PWM_withSlaveBITOUT_M_;
RT_MODEL_PWM_withSlaveBITOUT_T *const PWM_withSlaveBITOUT_M =
  &PWM_withSlaveBITOUT_M_;

/* Model output function */
void PWM_withSlaveBITOUT_output(void)
{
  real_T u0;
  real_T u1;
  real_T u2;

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S7>/Constant'
   */
  PWM_withSlaveBITOUT_B.Compare = (PWM_withSlaveBITOUT_P.Constant_Value_h !=
    PWM_withSlaveBITOUT_P.Constant_Value);

  /* Sum: '<S12>/Sum' incorporates:
   *  Constant: '<S12>/Constant'
   */
  PWM_withSlaveBITOUT_B.Sum = PWM_withSlaveBITOUT_P.PWMGenerator_Tper -
    PWM_withSlaveBITOUT_B.Probe[0];

  /* Product: '<S12>/Product' incorporates:
   *  Constant: '<S12>/Constant'
   */
  PWM_withSlaveBITOUT_B.Product = PWM_withSlaveBITOUT_P.PWMGenerator_Tper /
    PWM_withSlaveBITOUT_B.Sum;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  PWM_withSlaveBITOUT_B.Compare_d = (PWM_withSlaveBITOUT_DW.Integrator_DSTATE <
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDiscr);

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   */
  PWM_withSlaveBITOUT_B.Compare_h = (PWM_withSlaveBITOUT_DW.Integrator_DSTATE >=
    PWM_withSlaveBITOUT_P.PWMGenerator_Tper);

  /* Logic: '<S13>/Logical Operator' */
  PWM_withSlaveBITOUT_B.LogicalOperator = (PWM_withSlaveBITOUT_B.Compare_d ||
    PWM_withSlaveBITOUT_B.Compare_h);

  /* Bias: '<S16>/Bias' */
  u0 = -PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDiscr;

  /* Bias: '<S16>/Bias' */
  PWM_withSlaveBITOUT_B.Bias = PWM_withSlaveBITOUT_DW.Integrator_DSTATE + u0;

  /* Gain: '<S16>/Gain' incorporates:
   *  Gain: '<S16>/Gain1'
   */
  u1 = PWM_withSlaveBITOUT_P.PWMGenerator_Tper -
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDiscr;
  u0 = 1.0 / u1;

  /* Gain: '<S16>/Gain' */
  PWM_withSlaveBITOUT_B.Gain = u0 * PWM_withSlaveBITOUT_B.Bias;

  /* Rounding: '<S16>/Rounding Function' */
  PWM_withSlaveBITOUT_B.RoundingFunction = floor(PWM_withSlaveBITOUT_B.Gain);

  /* Gain: '<S16>/Gain1' */
  u0 = u1;

  /* Gain: '<S16>/Gain1' */
  PWM_withSlaveBITOUT_B.Gain1 = u0 * PWM_withSlaveBITOUT_B.RoundingFunction;

  /* Sum: '<S16>/Sum1' */
  PWM_withSlaveBITOUT_B.Sum1 = PWM_withSlaveBITOUT_DW.Integrator_DSTATE -
    PWM_withSlaveBITOUT_B.Gain1;

  /* InitialCondition: '<S13>/Initial' */
  if (PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime) {
    PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime = false;

    /* InitialCondition: '<S13>/Initial' */
    PWM_withSlaveBITOUT_B.Initial =
      PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_a;
  } else {
    /* InitialCondition: '<S13>/Initial' */
    PWM_withSlaveBITOUT_B.Initial = PWM_withSlaveBITOUT_B.Sum1;
  }

  /* End of InitialCondition: '<S13>/Initial' */

  /* DiscreteIntegrator: '<S13>/Integrator' */
  if (PWM_withSlaveBITOUT_B.LogicalOperator) {
    PWM_withSlaveBITOUT_DW.Integrator_DSTATE = PWM_withSlaveBITOUT_B.Initial;
  }

  /* DiscreteIntegrator: '<S13>/Integrator' */
  PWM_withSlaveBITOUT_B.Integrator = PWM_withSlaveBITOUT_DW.Integrator_DSTATE;

  /* Product: '<S12>/Product1' */
  PWM_withSlaveBITOUT_B.Product1 = PWM_withSlaveBITOUT_B.Product *
    PWM_withSlaveBITOUT_B.Integrator;

  /* Bias: '<S12>/Bias' */
  PWM_withSlaveBITOUT_B.Bias_g = PWM_withSlaveBITOUT_B.Probe[0] +
    PWM_withSlaveBITOUT_P.PWMGenerator_Tper;

  /* Product: '<S12>/Product2' */
  PWM_withSlaveBITOUT_B.Product2 = PWM_withSlaveBITOUT_B.Product1 /
    PWM_withSlaveBITOUT_B.Bias_g;

  /* Rounding: '<S12>/Rounding Function' */
  PWM_withSlaveBITOUT_B.RoundingFunction_o = floor
    (PWM_withSlaveBITOUT_B.Product2);

  /* Product: '<S12>/Product3' */
  PWM_withSlaveBITOUT_B.Product3 = PWM_withSlaveBITOUT_B.RoundingFunction_o *
    PWM_withSlaveBITOUT_B.Bias_g;

  /* Sum: '<S12>/Sum1' */
  PWM_withSlaveBITOUT_B.Sum1_k = PWM_withSlaveBITOUT_B.Product1 -
    PWM_withSlaveBITOUT_B.Product3;

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  PWM_withSlaveBITOUT_B.Compare_i = (PWM_withSlaveBITOUT_DW.Integrator_DSTATE_e <
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_f);

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S6>/Constant10'
   *  MultiPortSwitch: '<S6>/Multiport Switch'
   *  Sum: '<S6>/Sum4'
   */
  u1 = 2.0 * PWM_withSlaveBITOUT_P.PWMGenerator_Tper;
  u0 = u1;

  /* RelationalOperator: '<S19>/Compare' */
  PWM_withSlaveBITOUT_B.Compare_n = (PWM_withSlaveBITOUT_DW.Integrator_DSTATE_e >=
    u0);

  /* Logic: '<S17>/Logical Operator' */
  PWM_withSlaveBITOUT_B.LogicalOperator_a = (PWM_withSlaveBITOUT_B.Compare_i ||
    PWM_withSlaveBITOUT_B.Compare_n);

  /* Bias: '<S20>/Bias' */
  u0 = -PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_f;

  /* Bias: '<S20>/Bias' */
  PWM_withSlaveBITOUT_B.Bias_f = PWM_withSlaveBITOUT_DW.Integrator_DSTATE_e + u0;

  /* Gain: '<S20>/Gain' incorporates:
   *  Gain: '<S20>/Gain1'
   */
  u2 = 2.0 * PWM_withSlaveBITOUT_P.PWMGenerator_Tper -
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_f;
  u0 = 1.0 / u2;

  /* Gain: '<S20>/Gain' */
  PWM_withSlaveBITOUT_B.Gain_n = u0 * PWM_withSlaveBITOUT_B.Bias_f;

  /* Rounding: '<S20>/Rounding Function' */
  PWM_withSlaveBITOUT_B.RoundingFunction_d = floor(PWM_withSlaveBITOUT_B.Gain_n);

  /* Gain: '<S20>/Gain1' */
  u0 = u2;

  /* Gain: '<S20>/Gain1' */
  PWM_withSlaveBITOUT_B.Gain1_g = u0 * PWM_withSlaveBITOUT_B.RoundingFunction_d;

  /* Sum: '<S20>/Sum1' */
  PWM_withSlaveBITOUT_B.Sum1_h = PWM_withSlaveBITOUT_DW.Integrator_DSTATE_e -
    PWM_withSlaveBITOUT_B.Gain1_g;

  /* InitialCondition: '<S17>/Initial' */
  if (PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_h) {
    PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_h = false;

    /* InitialCondition: '<S17>/Initial' */
    PWM_withSlaveBITOUT_B.Initial_m = PWM_withSlaveBITOUT_P.PWMGenerator_Tdelay;
  } else {
    /* InitialCondition: '<S17>/Initial' */
    PWM_withSlaveBITOUT_B.Initial_m = PWM_withSlaveBITOUT_B.Sum1_h;
  }

  /* End of InitialCondition: '<S17>/Initial' */

  /* DiscreteIntegrator: '<S17>/Integrator' */
  if (PWM_withSlaveBITOUT_B.LogicalOperator_a) {
    PWM_withSlaveBITOUT_DW.Integrator_DSTATE_e = PWM_withSlaveBITOUT_B.Initial_m;
  }

  /* DiscreteIntegrator: '<S17>/Integrator' */
  PWM_withSlaveBITOUT_B.Integrator_b =
    PWM_withSlaveBITOUT_DW.Integrator_DSTATE_e;

  /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  switch ((int32_T)PWM_withSlaveBITOUT_P.Carriercounter_CarrCount) {
   case 1:
    /* MultiPortSwitch: '<S6>/Multiport Switch' */
    PWM_withSlaveBITOUT_B.MultiportSwitch = PWM_withSlaveBITOUT_B.Sum1_k;
    break;

   case 2:
    /* Sum: '<S6>/Sum3' incorporates:
     *  Constant: '<S6>/Constant6'
     */
    PWM_withSlaveBITOUT_B.Sum3_c = PWM_withSlaveBITOUT_P.PWMGenerator_Tper -
      PWM_withSlaveBITOUT_B.Sum1_k;

    /* MultiPortSwitch: '<S6>/Multiport Switch' */
    PWM_withSlaveBITOUT_B.MultiportSwitch = PWM_withSlaveBITOUT_B.Sum3_c;
    break;

   default:
    /* Sum: '<S6>/Sum4' incorporates:
     *  Constant: '<S6>/Constant10'
     */
    u0 = u1;

    /* Sum: '<S6>/Sum4' */
    PWM_withSlaveBITOUT_B.Sum4_c = u0 - PWM_withSlaveBITOUT_B.Integrator_b;

    /* Switch: '<S11>/Switch' */
    if (PWM_withSlaveBITOUT_B.Sum4_c > PWM_withSlaveBITOUT_P.PWMGenerator_Tper)
    {
      /* Switch: '<S11>/Switch' incorporates:
       *  Constant: '<S11>/Constant2'
       */
      PWM_withSlaveBITOUT_B.Switch_n = PWM_withSlaveBITOUT_P.Constant2_Value_g;
    } else {
      /* Switch: '<S11>/Switch' */
      PWM_withSlaveBITOUT_B.Switch_n = PWM_withSlaveBITOUT_B.Sum4_c;
    }

    /* End of Switch: '<S11>/Switch' */

    /* Switch: '<S10>/Switch' */
    if (PWM_withSlaveBITOUT_B.Integrator_b >
        PWM_withSlaveBITOUT_P.PWMGenerator_Tper) {
      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/Constant2'
       */
      PWM_withSlaveBITOUT_B.Switch_e = PWM_withSlaveBITOUT_P.Constant2_Value;
    } else {
      /* Switch: '<S10>/Switch' */
      PWM_withSlaveBITOUT_B.Switch_e = PWM_withSlaveBITOUT_B.Integrator_b;
    }

    /* End of Switch: '<S10>/Switch' */

    /* Sum: '<S6>/Sum5' */
    PWM_withSlaveBITOUT_B.Sum5_l = PWM_withSlaveBITOUT_B.Switch_e +
      PWM_withSlaveBITOUT_B.Switch_n;

    /* MultiPortSwitch: '<S6>/Multiport Switch' */
    PWM_withSlaveBITOUT_B.MultiportSwitch = PWM_withSlaveBITOUT_B.Sum5_l;
    break;
  }

  /* Gain: '<S6>/Gain1' */
  u0 = 1.0 / PWM_withSlaveBITOUT_P.PWMGenerator_Tper;

  /* Gain: '<S6>/Gain1' */
  PWM_withSlaveBITOUT_B.Gain1_b = u0 * PWM_withSlaveBITOUT_B.MultiportSwitch;

  /* Saturate: '<S6>/Saturation' */
  u0 = PWM_withSlaveBITOUT_B.Gain1_b;
  u1 = PWM_withSlaveBITOUT_P.Saturation_LowerSat;
  u2 = PWM_withSlaveBITOUT_P.Saturation_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S6>/Saturation' */
    PWM_withSlaveBITOUT_B.Saturation = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S6>/Saturation' */
    PWM_withSlaveBITOUT_B.Saturation = u1;
  } else {
    /* Saturate: '<S6>/Saturation' */
    PWM_withSlaveBITOUT_B.Saturation = u0;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Gain: '<S6>/Gain' */
  PWM_withSlaveBITOUT_B.Gain_m = PWM_withSlaveBITOUT_P.Carriercounter_Range *
    PWM_withSlaveBITOUT_B.Saturation;

  /* Bias: '<S6>/Bias' */
  u0 = -PWM_withSlaveBITOUT_P.Carriercounter_Range + 1.0;

  /* Bias: '<S6>/Bias' */
  PWM_withSlaveBITOUT_B.Bias_fd = PWM_withSlaveBITOUT_B.Gain_m + u0;

  /* RelationalOperator: '<S3>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant'
   */
  PWM_withSlaveBITOUT_B.RelationalOperator =
    (PWM_withSlaveBITOUT_P.Constant_Value_h >= PWM_withSlaveBITOUT_B.Bias_fd);

  /* Logic: '<S3>/Logical Operator' */
  PWM_withSlaveBITOUT_B.LogicalOperator_m = (PWM_withSlaveBITOUT_B.Compare &&
    PWM_withSlaveBITOUT_B.RelationalOperator);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' */
  PWM_withSlaveBITOUT_B.DataTypeConversion2 =
    PWM_withSlaveBITOUT_B.LogicalOperator_m;

  /* S-Function (rti_commonblock): '<S2>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:SLV_BIT_IO Group:BIT_OUT */
  if (PWM_withSlaveBITOUT_B.DataTypeConversion2 > 0) {
    ds1104_slave_dsp_bit_io_set(1, rti_slv1104_fcn_index[10],
      SLVDSP1104_BIT_IO_BIT4_MSK);
  } else {
    ds1104_slave_dsp_bit_io_clear(1, rti_slv1104_fcn_index[13],
      SLVDSP1104_BIT_IO_BIT4_MSK);
  }

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S22>/Constant'
   */
  PWM_withSlaveBITOUT_B.Compare_c = (PWM_withSlaveBITOUT_P.Constant1_Value !=
    PWM_withSlaveBITOUT_P.Constant_Value_l);

  /* Sum: '<S27>/Sum' incorporates:
   *  Constant: '<S27>/Constant'
   */
  PWM_withSlaveBITOUT_B.Sum_p = PWM_withSlaveBITOUT_P.PWMGenerator1_Tper -
    PWM_withSlaveBITOUT_B.Probe_b[0];

  /* Product: '<S27>/Product' incorporates:
   *  Constant: '<S27>/Constant'
   */
  PWM_withSlaveBITOUT_B.Product_e = PWM_withSlaveBITOUT_P.PWMGenerator1_Tper /
    PWM_withSlaveBITOUT_B.Sum_p;

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  PWM_withSlaveBITOUT_B.Compare_l = (PWM_withSlaveBITOUT_DW.Integrator_DSTATE_o <
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_p);

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   */
  PWM_withSlaveBITOUT_B.Compare_cw = (PWM_withSlaveBITOUT_DW.Integrator_DSTATE_o
    >= PWM_withSlaveBITOUT_P.PWMGenerator1_Tper);

  /* Logic: '<S28>/Logical Operator' */
  PWM_withSlaveBITOUT_B.LogicalOperator_g = (PWM_withSlaveBITOUT_B.Compare_l ||
    PWM_withSlaveBITOUT_B.Compare_cw);

  /* Bias: '<S31>/Bias' */
  u0 = -PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_p;

  /* Bias: '<S31>/Bias' */
  PWM_withSlaveBITOUT_B.Bias_k = PWM_withSlaveBITOUT_DW.Integrator_DSTATE_o + u0;

  /* Gain: '<S31>/Gain' incorporates:
   *  Gain: '<S31>/Gain1'
   */
  u1 = PWM_withSlaveBITOUT_P.PWMGenerator1_Tper -
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_p;
  u0 = 1.0 / u1;

  /* Gain: '<S31>/Gain' */
  PWM_withSlaveBITOUT_B.Gain_e = u0 * PWM_withSlaveBITOUT_B.Bias_k;

  /* Rounding: '<S31>/Rounding Function' */
  PWM_withSlaveBITOUT_B.RoundingFunction_m = floor(PWM_withSlaveBITOUT_B.Gain_e);

  /* Gain: '<S31>/Gain1' */
  u0 = u1;

  /* Gain: '<S31>/Gain1' */
  PWM_withSlaveBITOUT_B.Gain1_e = u0 * PWM_withSlaveBITOUT_B.RoundingFunction_m;

  /* Sum: '<S31>/Sum1' */
  PWM_withSlaveBITOUT_B.Sum1_o = PWM_withSlaveBITOUT_DW.Integrator_DSTATE_o -
    PWM_withSlaveBITOUT_B.Gain1_e;

  /* InitialCondition: '<S28>/Initial' */
  if (PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_n) {
    PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_n = false;

    /* InitialCondition: '<S28>/Initial' */
    PWM_withSlaveBITOUT_B.Initial_g =
      PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_i;
  } else {
    /* InitialCondition: '<S28>/Initial' */
    PWM_withSlaveBITOUT_B.Initial_g = PWM_withSlaveBITOUT_B.Sum1_o;
  }

  /* End of InitialCondition: '<S28>/Initial' */

  /* DiscreteIntegrator: '<S28>/Integrator' */
  if (PWM_withSlaveBITOUT_B.LogicalOperator_g) {
    PWM_withSlaveBITOUT_DW.Integrator_DSTATE_o = PWM_withSlaveBITOUT_B.Initial_g;
  }

  /* DiscreteIntegrator: '<S28>/Integrator' */
  PWM_withSlaveBITOUT_B.Integrator_a =
    PWM_withSlaveBITOUT_DW.Integrator_DSTATE_o;

  /* Product: '<S27>/Product1' */
  PWM_withSlaveBITOUT_B.Product1_a = PWM_withSlaveBITOUT_B.Product_e *
    PWM_withSlaveBITOUT_B.Integrator_a;

  /* Bias: '<S27>/Bias' */
  PWM_withSlaveBITOUT_B.Bias_p = PWM_withSlaveBITOUT_B.Probe_b[0] +
    PWM_withSlaveBITOUT_P.PWMGenerator1_Tper;

  /* Product: '<S27>/Product2' */
  PWM_withSlaveBITOUT_B.Product2_p = PWM_withSlaveBITOUT_B.Product1_a /
    PWM_withSlaveBITOUT_B.Bias_p;

  /* Rounding: '<S27>/Rounding Function' */
  PWM_withSlaveBITOUT_B.RoundingFunction_mb = floor
    (PWM_withSlaveBITOUT_B.Product2_p);

  /* Product: '<S27>/Product3' */
  PWM_withSlaveBITOUT_B.Product3_f = PWM_withSlaveBITOUT_B.RoundingFunction_mb *
    PWM_withSlaveBITOUT_B.Bias_p;

  /* Sum: '<S27>/Sum1' */
  PWM_withSlaveBITOUT_B.Sum1_m = PWM_withSlaveBITOUT_B.Product1_a -
    PWM_withSlaveBITOUT_B.Product3_f;

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   */
  PWM_withSlaveBITOUT_B.Compare_n3 = (PWM_withSlaveBITOUT_DW.Integrator_DSTATE_i
    < PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_h);

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S21>/Constant10'
   *  Constant: '<S34>/Constant'
   *  MultiPortSwitch: '<S21>/Multiport Switch'
   *  Sum: '<S21>/Sum4'
   */
  u1 = 2.0 * PWM_withSlaveBITOUT_P.PWMGenerator1_Tper;
  u0 = u1;

  /* RelationalOperator: '<S34>/Compare' */
  PWM_withSlaveBITOUT_B.Compare_b = (PWM_withSlaveBITOUT_DW.Integrator_DSTATE_i >=
    u0);

  /* Logic: '<S32>/Logical Operator' */
  PWM_withSlaveBITOUT_B.LogicalOperator_k = (PWM_withSlaveBITOUT_B.Compare_n3 ||
    PWM_withSlaveBITOUT_B.Compare_b);

  /* Bias: '<S35>/Bias' */
  u0 = -PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_h;

  /* Bias: '<S35>/Bias' */
  PWM_withSlaveBITOUT_B.Bias_l = PWM_withSlaveBITOUT_DW.Integrator_DSTATE_i + u0;

  /* Gain: '<S35>/Gain' incorporates:
   *  Gain: '<S35>/Gain1'
   */
  u2 = 2.0 * PWM_withSlaveBITOUT_P.PWMGenerator1_Tper -
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_h;
  u0 = 1.0 / u2;

  /* Gain: '<S35>/Gain' */
  PWM_withSlaveBITOUT_B.Gain_f = u0 * PWM_withSlaveBITOUT_B.Bias_l;

  /* Rounding: '<S35>/Rounding Function' */
  PWM_withSlaveBITOUT_B.RoundingFunction_dy = floor(PWM_withSlaveBITOUT_B.Gain_f);

  /* Gain: '<S35>/Gain1' */
  u0 = u2;

  /* Gain: '<S35>/Gain1' */
  PWM_withSlaveBITOUT_B.Gain1_p = u0 * PWM_withSlaveBITOUT_B.RoundingFunction_dy;

  /* Sum: '<S35>/Sum1' */
  PWM_withSlaveBITOUT_B.Sum1_e = PWM_withSlaveBITOUT_DW.Integrator_DSTATE_i -
    PWM_withSlaveBITOUT_B.Gain1_p;

  /* InitialCondition: '<S32>/Initial' */
  if (PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_j) {
    PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_j = false;

    /* InitialCondition: '<S32>/Initial' */
    PWM_withSlaveBITOUT_B.Initial_j = PWM_withSlaveBITOUT_P.PWMGenerator1_Tdelay;
  } else {
    /* InitialCondition: '<S32>/Initial' */
    PWM_withSlaveBITOUT_B.Initial_j = PWM_withSlaveBITOUT_B.Sum1_e;
  }

  /* End of InitialCondition: '<S32>/Initial' */

  /* DiscreteIntegrator: '<S32>/Integrator' */
  if (PWM_withSlaveBITOUT_B.LogicalOperator_k) {
    PWM_withSlaveBITOUT_DW.Integrator_DSTATE_i = PWM_withSlaveBITOUT_B.Initial_j;
  }

  /* DiscreteIntegrator: '<S32>/Integrator' */
  PWM_withSlaveBITOUT_B.Integrator_h =
    PWM_withSlaveBITOUT_DW.Integrator_DSTATE_i;

  /* MultiPortSwitch: '<S21>/Multiport Switch' incorporates:
   *  Constant: '<S21>/Constant2'
   */
  switch ((int32_T)PWM_withSlaveBITOUT_P.Carriercounter_CarrCount_m) {
   case 1:
    /* MultiPortSwitch: '<S21>/Multiport Switch' */
    PWM_withSlaveBITOUT_B.MultiportSwitch_j = PWM_withSlaveBITOUT_B.Sum1_m;
    break;

   case 2:
    /* Sum: '<S21>/Sum3' incorporates:
     *  Constant: '<S21>/Constant6'
     */
    PWM_withSlaveBITOUT_B.Sum3 = PWM_withSlaveBITOUT_P.PWMGenerator1_Tper -
      PWM_withSlaveBITOUT_B.Sum1_m;

    /* MultiPortSwitch: '<S21>/Multiport Switch' */
    PWM_withSlaveBITOUT_B.MultiportSwitch_j = PWM_withSlaveBITOUT_B.Sum3;
    break;

   default:
    /* Sum: '<S21>/Sum4' incorporates:
     *  Constant: '<S21>/Constant10'
     */
    u0 = u1;

    /* Sum: '<S21>/Sum4' */
    PWM_withSlaveBITOUT_B.Sum4 = u0 - PWM_withSlaveBITOUT_B.Integrator_h;

    /* Switch: '<S26>/Switch' */
    if (PWM_withSlaveBITOUT_B.Sum4 > PWM_withSlaveBITOUT_P.PWMGenerator1_Tper) {
      /* Switch: '<S26>/Switch' incorporates:
       *  Constant: '<S26>/Constant2'
       */
      PWM_withSlaveBITOUT_B.Switch = PWM_withSlaveBITOUT_P.Constant2_Value_i;
    } else {
      /* Switch: '<S26>/Switch' */
      PWM_withSlaveBITOUT_B.Switch = PWM_withSlaveBITOUT_B.Sum4;
    }

    /* End of Switch: '<S26>/Switch' */

    /* Switch: '<S25>/Switch' */
    if (PWM_withSlaveBITOUT_B.Integrator_h >
        PWM_withSlaveBITOUT_P.PWMGenerator1_Tper) {
      /* Switch: '<S25>/Switch' incorporates:
       *  Constant: '<S25>/Constant2'
       */
      PWM_withSlaveBITOUT_B.Switch_l = PWM_withSlaveBITOUT_P.Constant2_Value_a;
    } else {
      /* Switch: '<S25>/Switch' */
      PWM_withSlaveBITOUT_B.Switch_l = PWM_withSlaveBITOUT_B.Integrator_h;
    }

    /* End of Switch: '<S25>/Switch' */

    /* Sum: '<S21>/Sum5' */
    PWM_withSlaveBITOUT_B.Sum5 = PWM_withSlaveBITOUT_B.Switch_l +
      PWM_withSlaveBITOUT_B.Switch;

    /* MultiPortSwitch: '<S21>/Multiport Switch' */
    PWM_withSlaveBITOUT_B.MultiportSwitch_j = PWM_withSlaveBITOUT_B.Sum5;
    break;
  }

  /* Gain: '<S21>/Gain1' */
  u0 = 1.0 / PWM_withSlaveBITOUT_P.PWMGenerator1_Tper;

  /* Gain: '<S21>/Gain1' */
  PWM_withSlaveBITOUT_B.Gain1_l = u0 * PWM_withSlaveBITOUT_B.MultiportSwitch_j;

  /* Saturate: '<S21>/Saturation' */
  u0 = PWM_withSlaveBITOUT_B.Gain1_l;
  u1 = PWM_withSlaveBITOUT_P.Saturation_LowerSat_a;
  u2 = PWM_withSlaveBITOUT_P.Saturation_UpperSat_m;
  if (u0 > u2) {
    /* Saturate: '<S21>/Saturation' */
    PWM_withSlaveBITOUT_B.Saturation_j = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S21>/Saturation' */
    PWM_withSlaveBITOUT_B.Saturation_j = u1;
  } else {
    /* Saturate: '<S21>/Saturation' */
    PWM_withSlaveBITOUT_B.Saturation_j = u0;
  }

  /* End of Saturate: '<S21>/Saturation' */

  /* Gain: '<S21>/Gain' */
  PWM_withSlaveBITOUT_B.Gain_o = PWM_withSlaveBITOUT_P.Carriercounter_Range_l *
    PWM_withSlaveBITOUT_B.Saturation_j;

  /* Bias: '<S21>/Bias' */
  u0 = -PWM_withSlaveBITOUT_P.Carriercounter_Range_l + 1.0;

  /* Bias: '<S21>/Bias' */
  PWM_withSlaveBITOUT_B.Bias_h = PWM_withSlaveBITOUT_B.Gain_o + u0;

  /* RelationalOperator: '<S4>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  PWM_withSlaveBITOUT_B.RelationalOperator_d =
    (PWM_withSlaveBITOUT_P.Constant1_Value >= PWM_withSlaveBITOUT_B.Bias_h);

  /* Logic: '<S4>/Logical Operator' */
  PWM_withSlaveBITOUT_B.LogicalOperator_h = (PWM_withSlaveBITOUT_B.Compare_c &&
    PWM_withSlaveBITOUT_B.RelationalOperator_d);

  /* DataTypeConversion: '<S4>/Data Type Conversion2' */
  PWM_withSlaveBITOUT_B.DataTypeConversion2_c =
    PWM_withSlaveBITOUT_B.LogicalOperator_h;

  /* S-Function (rti_commonblock): '<S1>/S-Function1' */
  /* This comment workarounds a code generation problem */

  /* dSPACE I/O Board DS1104 #1 Unit:SLV_BIT_IO Group:BIT_OUT */
  if (PWM_withSlaveBITOUT_B.DataTypeConversion2_c > 0) {
    ds1104_slave_dsp_bit_io_set(1, rti_slv1104_fcn_index[10],
      SLVDSP1104_BIT_IO_BIT1_MSK);
  } else {
    ds1104_slave_dsp_bit_io_clear(1, rti_slv1104_fcn_index[13],
      SLVDSP1104_BIT_IO_BIT1_MSK);
  }
}

/* Model update function */
void PWM_withSlaveBITOUT_update(void)
{
  /* Update for DiscreteIntegrator: '<S13>/Integrator' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  PWM_withSlaveBITOUT_DW.Integrator_DSTATE +=
    PWM_withSlaveBITOUT_P.Integrator_gainval *
    PWM_withSlaveBITOUT_P.Constant3_Value;

  /* Update for DiscreteIntegrator: '<S17>/Integrator' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  PWM_withSlaveBITOUT_DW.Integrator_DSTATE_e +=
    PWM_withSlaveBITOUT_P.Integrator_gainval_p *
    PWM_withSlaveBITOUT_P.Constant3_Value;

  /* Update for DiscreteIntegrator: '<S28>/Integrator' incorporates:
   *  Constant: '<S21>/Constant3'
   */
  PWM_withSlaveBITOUT_DW.Integrator_DSTATE_o +=
    PWM_withSlaveBITOUT_P.Integrator_gainval_l *
    PWM_withSlaveBITOUT_P.Constant3_Value_l;

  /* Update for DiscreteIntegrator: '<S32>/Integrator' incorporates:
   *  Constant: '<S21>/Constant3'
   */
  PWM_withSlaveBITOUT_DW.Integrator_DSTATE_i +=
    PWM_withSlaveBITOUT_P.Integrator_gainval_j *
    PWM_withSlaveBITOUT_P.Constant3_Value_l;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PWM_withSlaveBITOUT_M->Timing.clockTick0)) {
    ++PWM_withSlaveBITOUT_M->Timing.clockTickH0;
  }

  PWM_withSlaveBITOUT_M->Timing.taskTime0 =
    PWM_withSlaveBITOUT_M->Timing.clockTick0 *
    PWM_withSlaveBITOUT_M->Timing.stepSize0 +
    PWM_withSlaveBITOUT_M->Timing.clockTickH0 *
    PWM_withSlaveBITOUT_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void PWM_withSlaveBITOUT_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)PWM_withSlaveBITOUT_M, 0,
                sizeof(RT_MODEL_PWM_withSlaveBITOUT_T));
  PWM_withSlaveBITOUT_M->Timing.stepSize0 = 5.0E-5;

  /* block I/O */
  (void) memset(((void *) &PWM_withSlaveBITOUT_B), 0,
                sizeof(B_PWM_withSlaveBITOUT_T));

  /* states (dwork) */
  (void) memset((void *)&PWM_withSlaveBITOUT_DW, 0,
                sizeof(DW_PWM_withSlaveBITOUT_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    PWM_withSlaveBITOUT_rti_init_trc_pointers();
  }

  /* Start for Probe: '<S12>/Probe' */
  PWM_withSlaveBITOUT_B.Probe[0] = 5.0E-5;
  PWM_withSlaveBITOUT_B.Probe[1] = 0.0;

  /* Start for InitialCondition: '<S13>/Initial' */
  PWM_withSlaveBITOUT_B.Initial =
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_a;

  /* Start for InitialCondition: '<S13>/Initial' */
  PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime = true;

  /* Start for InitialCondition: '<S17>/Initial' */
  PWM_withSlaveBITOUT_B.Initial_m = PWM_withSlaveBITOUT_P.PWMGenerator_Tdelay;

  /* Start for InitialCondition: '<S17>/Initial' */
  PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_h = true;

  /* Start for Probe: '<S27>/Probe' */
  PWM_withSlaveBITOUT_B.Probe_b[0] = 5.0E-5;
  PWM_withSlaveBITOUT_B.Probe_b[1] = 0.0;

  /* Start for InitialCondition: '<S28>/Initial' */
  PWM_withSlaveBITOUT_B.Initial_g =
    PWM_withSlaveBITOUT_P.IntegratorwithWrappedStateDis_i;

  /* Start for InitialCondition: '<S28>/Initial' */
  PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_n = true;

  /* Start for InitialCondition: '<S32>/Initial' */
  PWM_withSlaveBITOUT_B.Initial_j = PWM_withSlaveBITOUT_P.PWMGenerator1_Tdelay;

  /* Start for InitialCondition: '<S32>/Initial' */
  PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime_j = true;

  /* InitializeConditions for DiscreteIntegrator: '<S13>/Integrator' */
  PWM_withSlaveBITOUT_DW.Integrator_DSTATE = PWM_withSlaveBITOUT_B.Initial;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Integrator' */
  PWM_withSlaveBITOUT_DW.Integrator_DSTATE_e = PWM_withSlaveBITOUT_B.Initial_m;

  /* InitializeConditions for DiscreteIntegrator: '<S28>/Integrator' */
  PWM_withSlaveBITOUT_DW.Integrator_DSTATE_o = PWM_withSlaveBITOUT_B.Initial_g;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Integrator' */
  PWM_withSlaveBITOUT_DW.Integrator_DSTATE_i = PWM_withSlaveBITOUT_B.Initial_j;
}

/* Model terminate function */
void PWM_withSlaveBITOUT_terminate(void)
{
  /* (no terminate code required) */
}
