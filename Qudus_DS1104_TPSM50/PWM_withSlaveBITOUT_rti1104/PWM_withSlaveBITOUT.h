/*
 * PWM_withSlaveBITOUT.h
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

#ifndef RTW_HEADER_PWM_withSlaveBITOUT_h_
#define RTW_HEADER_PWM_withSlaveBITOUT_h_
#ifndef PWM_withSlaveBITOUT_COMMON_INCLUDES_
#define PWM_withSlaveBITOUT_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <def1104.h>
#include <slvdsp1104.h>
#include <rti_slv1104.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                /* PWM_withSlaveBITOUT_COMMON_INCLUDES_ */

#include "PWM_withSlaveBITOUT_types.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Probe[2];                     /* '<S12>/Probe' */
  real_T Sum;                          /* '<S12>/Sum' */
  real_T Product;                      /* '<S12>/Product' */
  real_T Bias;                         /* '<S16>/Bias' */
  real_T Gain;                         /* '<S16>/Gain' */
  real_T RoundingFunction;             /* '<S16>/Rounding Function' */
  real_T Gain1;                        /* '<S16>/Gain1' */
  real_T Sum1;                         /* '<S16>/Sum1' */
  real_T Initial;                      /* '<S13>/Initial' */
  real_T Integrator;                   /* '<S13>/Integrator' */
  real_T Product1;                     /* '<S12>/Product1' */
  real_T Bias_g;                       /* '<S12>/Bias' */
  real_T Product2;                     /* '<S12>/Product2' */
  real_T RoundingFunction_o;           /* '<S12>/Rounding Function' */
  real_T Product3;                     /* '<S12>/Product3' */
  real_T Sum1_k;                       /* '<S12>/Sum1' */
  real_T Bias_f;                       /* '<S20>/Bias' */
  real_T Gain_n;                       /* '<S20>/Gain' */
  real_T RoundingFunction_d;           /* '<S20>/Rounding Function' */
  real_T Gain1_g;                      /* '<S20>/Gain1' */
  real_T Sum1_h;                       /* '<S20>/Sum1' */
  real_T Initial_m;                    /* '<S17>/Initial' */
  real_T Integrator_b;                 /* '<S17>/Integrator' */
  real_T MultiportSwitch;              /* '<S6>/Multiport Switch' */
  real_T Gain1_b;                      /* '<S6>/Gain1' */
  real_T Saturation;                   /* '<S6>/Saturation' */
  real_T Gain_m;                       /* '<S6>/Gain' */
  real_T Bias_fd;                      /* '<S6>/Bias' */
  real_T Probe_b[2];                   /* '<S27>/Probe' */
  real_T Sum_p;                        /* '<S27>/Sum' */
  real_T Product_e;                    /* '<S27>/Product' */
  real_T Bias_k;                       /* '<S31>/Bias' */
  real_T Gain_e;                       /* '<S31>/Gain' */
  real_T RoundingFunction_m;           /* '<S31>/Rounding Function' */
  real_T Gain1_e;                      /* '<S31>/Gain1' */
  real_T Sum1_o;                       /* '<S31>/Sum1' */
  real_T Initial_g;                    /* '<S28>/Initial' */
  real_T Integrator_a;                 /* '<S28>/Integrator' */
  real_T Product1_a;                   /* '<S27>/Product1' */
  real_T Bias_p;                       /* '<S27>/Bias' */
  real_T Product2_p;                   /* '<S27>/Product2' */
  real_T RoundingFunction_mb;          /* '<S27>/Rounding Function' */
  real_T Product3_f;                   /* '<S27>/Product3' */
  real_T Sum1_m;                       /* '<S27>/Sum1' */
  real_T Bias_l;                       /* '<S35>/Bias' */
  real_T Gain_f;                       /* '<S35>/Gain' */
  real_T RoundingFunction_dy;          /* '<S35>/Rounding Function' */
  real_T Gain1_p;                      /* '<S35>/Gain1' */
  real_T Sum1_e;                       /* '<S35>/Sum1' */
  real_T Initial_j;                    /* '<S32>/Initial' */
  real_T Integrator_h;                 /* '<S32>/Integrator' */
  real_T MultiportSwitch_j;            /* '<S21>/Multiport Switch' */
  real_T Gain1_l;                      /* '<S21>/Gain1' */
  real_T Saturation_j;                 /* '<S21>/Saturation' */
  real_T Gain_o;                       /* '<S21>/Gain' */
  real_T Bias_h;                       /* '<S21>/Bias' */
  real_T Sum4;                         /* '<S21>/Sum4' */
  real_T Switch;                       /* '<S26>/Switch' */
  real_T Switch_l;                     /* '<S25>/Switch' */
  real_T Sum5;                         /* '<S21>/Sum5' */
  real_T Sum3;                         /* '<S21>/Sum3' */
  real_T Sum4_c;                       /* '<S6>/Sum4' */
  real_T Switch_n;                     /* '<S11>/Switch' */
  real_T Switch_e;                     /* '<S10>/Switch' */
  real_T Sum5_l;                       /* '<S6>/Sum5' */
  real_T Sum3_c;                       /* '<S6>/Sum3' */
  boolean_T Compare;                   /* '<S7>/Compare' */
  boolean_T Compare_d;                 /* '<S14>/Compare' */
  boolean_T Compare_h;                 /* '<S15>/Compare' */
  boolean_T LogicalOperator;           /* '<S13>/Logical Operator' */
  boolean_T Compare_i;                 /* '<S18>/Compare' */
  boolean_T Compare_n;                 /* '<S19>/Compare' */
  boolean_T LogicalOperator_a;         /* '<S17>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S3>/Relational Operator' */
  boolean_T LogicalOperator_m;         /* '<S3>/Logical Operator' */
  boolean_T DataTypeConversion2;       /* '<S3>/Data Type Conversion2' */
  boolean_T Compare_c;                 /* '<S22>/Compare' */
  boolean_T Compare_l;                 /* '<S29>/Compare' */
  boolean_T Compare_cw;                /* '<S30>/Compare' */
  boolean_T LogicalOperator_g;         /* '<S28>/Logical Operator' */
  boolean_T Compare_n3;                /* '<S33>/Compare' */
  boolean_T Compare_b;                 /* '<S34>/Compare' */
  boolean_T LogicalOperator_k;         /* '<S32>/Logical Operator' */
  boolean_T RelationalOperator_d;      /* '<S4>/Relational Operator' */
  boolean_T LogicalOperator_h;         /* '<S4>/Logical Operator' */
  boolean_T DataTypeConversion2_c;     /* '<S4>/Data Type Conversion2' */
} B_PWM_withSlaveBITOUT_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S13>/Integrator' */
  real_T Integrator_DSTATE_e;          /* '<S17>/Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S28>/Integrator' */
  real_T Integrator_DSTATE_i;          /* '<S32>/Integrator' */
  boolean_T Initial_FirstOutputTime;   /* '<S13>/Initial' */
  boolean_T Initial_FirstOutputTime_h; /* '<S17>/Initial' */
  boolean_T Initial_FirstOutputTime_n; /* '<S28>/Initial' */
  boolean_T Initial_FirstOutputTime_j; /* '<S32>/Initial' */
} DW_PWM_withSlaveBITOUT_T;

/* Parameters (default storage) */
struct P_PWM_withSlaveBITOUT_T_ {
  real_T Carriercounter_CarrCount;   /* Mask Parameter: Carriercounter_CarrCount
                                      * Referenced by: '<S6>/Constant2'
                                      */
  real_T Carriercounter_CarrCount_m;
                                   /* Mask Parameter: Carriercounter_CarrCount_m
                                    * Referenced by: '<S21>/Constant2'
                                    */
  real_T Carriercounter_Range;         /* Mask Parameter: Carriercounter_Range
                                        * Referenced by:
                                        *   '<S6>/Bias'
                                        *   '<S6>/Gain'
                                        */
  real_T Carriercounter_Range_l;       /* Mask Parameter: Carriercounter_Range_l
                                        * Referenced by:
                                        *   '<S21>/Bias'
                                        *   '<S21>/Gain'
                                        */
  real_T PWMGenerator_Tdelay;          /* Mask Parameter: PWMGenerator_Tdelay
                                        * Referenced by: '<S17>/Initial'
                                        */
  real_T PWMGenerator1_Tdelay;         /* Mask Parameter: PWMGenerator1_Tdelay
                                        * Referenced by: '<S32>/Initial'
                                        */
  real_T PWMGenerator_Tper;            /* Mask Parameter: PWMGenerator_Tper
                                        * Referenced by:
                                        *   '<S6>/Constant10'
                                        *   '<S6>/Constant6'
                                        *   '<S6>/Gain1'
                                        *   '<S10>/Switch'
                                        *   '<S11>/Switch'
                                        *   '<S12>/Bias'
                                        *   '<S12>/Constant'
                                        *   '<S15>/Constant'
                                        *   '<S16>/Gain'
                                        *   '<S16>/Gain1'
                                        *   '<S19>/Constant'
                                        *   '<S20>/Gain'
                                        *   '<S20>/Gain1'
                                        */
  real_T PWMGenerator1_Tper;           /* Mask Parameter: PWMGenerator1_Tper
                                        * Referenced by:
                                        *   '<S21>/Constant10'
                                        *   '<S21>/Constant6'
                                        *   '<S21>/Gain1'
                                        *   '<S25>/Switch'
                                        *   '<S26>/Switch'
                                        *   '<S27>/Bias'
                                        *   '<S27>/Constant'
                                        *   '<S30>/Constant'
                                        *   '<S31>/Gain'
                                        *   '<S31>/Gain1'
                                        *   '<S34>/Constant'
                                        *   '<S35>/Gain'
                                        *   '<S35>/Gain1'
                                        */
  real_T IntegratorwithWrappedStateDiscr;
                              /* Mask Parameter: IntegratorwithWrappedStateDiscr
                               * Referenced by:
                               *   '<S14>/Constant'
                               *   '<S16>/Bias'
                               *   '<S16>/Gain'
                               *   '<S16>/Gain1'
                               */
  real_T IntegratorwithWrappedStateDis_f;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_f
                               * Referenced by:
                               *   '<S18>/Constant'
                               *   '<S20>/Bias'
                               *   '<S20>/Gain'
                               *   '<S20>/Gain1'
                               */
  real_T IntegratorwithWrappedStateDis_p;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_p
                               * Referenced by:
                               *   '<S29>/Constant'
                               *   '<S31>/Bias'
                               *   '<S31>/Gain'
                               *   '<S31>/Gain1'
                               */
  real_T IntegratorwithWrappedStateDis_h;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_h
                               * Referenced by:
                               *   '<S33>/Constant'
                               *   '<S35>/Bias'
                               *   '<S35>/Gain'
                               *   '<S35>/Gain1'
                               */
  real_T IntegratorwithWrappedStateDis_a;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_a
                               * Referenced by: '<S13>/Initial'
                               */
  real_T IntegratorwithWrappedStateDis_i;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_i
                               * Referenced by: '<S28>/Initial'
                               */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 0.7
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S13>/Integrator'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Integrator_gainval_p;       /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S17>/Integrator'
                                      */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 0.7
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S28>/Integrator'
                                      */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S25>/Constant2'
                                        */
  real_T Integrator_gainval_j;       /* Computed Parameter: Integrator_gainval_j
                                      * Referenced by: '<S32>/Integrator'
                                      */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S26>/Constant2'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: 1
                                        * Referenced by: '<S21>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 0
                                        * Referenced by: '<S21>/Saturation'
                                        */
  real_T Constant3_Value_l;            /* Expression: 1
                                        * Referenced by: '<S21>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PWM_withSlaveBITOUT_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_PWM_withSlaveBITOUT_T PWM_withSlaveBITOUT_P;

/* Block signals (default storage) */
extern B_PWM_withSlaveBITOUT_T PWM_withSlaveBITOUT_B;

/* Block states (default storage) */
extern DW_PWM_withSlaveBITOUT_T PWM_withSlaveBITOUT_DW;

/* Model entry point functions */
extern void PWM_withSlaveBITOUT_initialize(void);
extern void PWM_withSlaveBITOUT_output(void);
extern void PWM_withSlaveBITOUT_update(void);
extern void PWM_withSlaveBITOUT_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PWM_withSlaveBITOUT_T *const PWM_withSlaveBITOUT_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PWM_withSlaveBITOUT'
 * '<S1>'   : 'PWM_withSlaveBITOUT/DS1104SL_DSP_BIT_OUT_C1'
 * '<S2>'   : 'PWM_withSlaveBITOUT/DS1104SL_DSP_BIT_OUT_C4'
 * '<S3>'   : 'PWM_withSlaveBITOUT/PWM Generator'
 * '<S4>'   : 'PWM_withSlaveBITOUT/PWM Generator1'
 * '<S5>'   : 'PWM_withSlaveBITOUT/RTI Data'
 * '<S6>'   : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter'
 * '<S7>'   : 'PWM_withSlaveBITOUT/PWM Generator/Compare To Zero'
 * '<S8>'   : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S9>'   : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S10>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Limitation'
 * '<S11>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Limitation1'
 * '<S12>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/scale'
 * '<S13>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S14>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S15>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant1'
 * '<S16>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Reinitialization'
 * '<S17>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete'
 * '<S18>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant'
 * '<S19>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant1'
 * '<S20>'  : 'PWM_withSlaveBITOUT/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Reinitialization'
 * '<S21>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter'
 * '<S22>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Compare To Zero'
 * '<S23>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S24>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S25>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Limitation'
 * '<S26>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Limitation1'
 * '<S27>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/scale'
 * '<S28>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S29>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S30>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant1'
 * '<S31>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Reinitialization'
 * '<S32>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete'
 * '<S33>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant'
 * '<S34>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant1'
 * '<S35>'  : 'PWM_withSlaveBITOUT/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Reinitialization'
 * '<S36>'  : 'PWM_withSlaveBITOUT/RTI Data/RTI Data Store'
 * '<S37>'  : 'PWM_withSlaveBITOUT/RTI Data/RTI Data Store/RTI Data Store'
 * '<S38>'  : 'PWM_withSlaveBITOUT/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_PWM_withSlaveBITOUT_h_ */
