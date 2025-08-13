/*
 * PWM.h
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

#ifndef RTW_HEADER_PWM_h_
#define RTW_HEADER_PWM_h_
#ifndef PWM_COMMON_INCLUDES_
#define PWM_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* PWM_COMMON_INCLUDES_ */

#include "PWM_types.h"
#include <string.h>
#include <math.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Probe[2];                     /* '<S14>/Probe' */
  real_T Sum;                          /* '<S14>/Sum' */
  real_T Product;                      /* '<S14>/Product' */
  real_T Integrator;                   /* '<S15>/Integrator' */
  real_T Product1;                     /* '<S14>/Product1' */
  real_T Bias;                         /* '<S14>/Bias' */
  real_T Product2;                     /* '<S14>/Product2' */
  real_T RoundingFunction;             /* '<S14>/Rounding Function' */
  real_T Product3;                     /* '<S14>/Product3' */
  real_T Sum1;                         /* '<S14>/Sum1' */
  real_T Integrator_p;                 /* '<S16>/Integrator' */
  real_T MultiportSwitch;              /* '<S8>/Multiport Switch' */
  real_T Gain1;                        /* '<S8>/Gain1' */
  real_T Saturation;                   /* '<S8>/Saturation' */
  real_T Gain;                         /* '<S8>/Gain' */
  real_T Bias_m;                       /* '<S8>/Bias' */
  real_T DataTypeConversion2;          /* '<S5>/Data Type Conversion2' */
  real_T DataTypeConversion;           /* '<S15>/Data Type Conversion' */
  real_T DataTypeConversion_p;         /* '<S16>/Data Type Conversion' */
  real_T Probe_o[2];                   /* '<S23>/Probe' */
  real_T Sum_g;                        /* '<S23>/Sum' */
  real_T Product_d;                    /* '<S23>/Product' */
  real_T Integrator_m;                 /* '<S24>/Integrator' */
  real_T Product1_i;                   /* '<S23>/Product1' */
  real_T Bias_f;                       /* '<S23>/Bias' */
  real_T Product2_d;                   /* '<S23>/Product2' */
  real_T RoundingFunction_e;           /* '<S23>/Rounding Function' */
  real_T Product3_i;                   /* '<S23>/Product3' */
  real_T Sum1_i;                       /* '<S23>/Sum1' */
  real_T Integrator_c;                 /* '<S25>/Integrator' */
  real_T MultiportSwitch_k;            /* '<S17>/Multiport Switch' */
  real_T Gain1_a;                      /* '<S17>/Gain1' */
  real_T Saturation_k;                 /* '<S17>/Saturation' */
  real_T Gain_o;                       /* '<S17>/Gain' */
  real_T Bias_c;                       /* '<S17>/Bias' */
  real_T DataTypeConversion2_c;        /* '<S6>/Data Type Conversion2' */
  real_T DataTypeConversion_k;         /* '<S24>/Data Type Conversion' */
  real_T DataTypeConversion_j;         /* '<S25>/Data Type Conversion' */
  real_T Sum4;                         /* '<S17>/Sum4' */
  real_T Switch;                       /* '<S22>/Switch' */
  real_T Switch_i;                     /* '<S21>/Switch' */
  real_T Sum5;                         /* '<S17>/Sum5' */
  real_T Sum3;                         /* '<S17>/Sum3' */
  real_T Sum4_m;                       /* '<S8>/Sum4' */
  real_T Switch_h;                     /* '<S13>/Switch' */
  real_T Switch_k;                     /* '<S12>/Switch' */
  real_T Sum5_g;                       /* '<S8>/Sum5' */
  real_T Sum3_o;                       /* '<S8>/Sum3' */
  boolean_T Compare;                   /* '<S9>/Compare' */
  boolean_T RelationalOperator;        /* '<S5>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S5>/Logical Operator' */
  boolean_T Compare_o;                 /* '<S1>/Compare' */
  boolean_T Compare_n;                 /* '<S18>/Compare' */
  boolean_T RelationalOperator_m;      /* '<S6>/Relational Operator' */
  boolean_T LogicalOperator_p;         /* '<S6>/Logical Operator' */
  boolean_T Compare_b;                 /* '<S2>/Compare' */
} B_PWM_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S15>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S16>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S24>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S25>/Integrator' */
} X_PWM_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_PWM_T[4];
typedef real_T PeriodicRngX_PWM_T[8];

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S15>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S16>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S24>/Integrator' */
  real_T Integrator_CSTATE_j;          /* '<S25>/Integrator' */
} XDot_PWM_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S15>/Integrator' */
  boolean_T Integrator_CSTATE_o;       /* '<S16>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S24>/Integrator' */
  boolean_T Integrator_CSTATE_j;       /* '<S25>/Integrator' */
} XDis_PWM_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_PWM_T_ {
  real_T Carriercounter_CarrCount;   /* Mask Parameter: Carriercounter_CarrCount
                                      * Referenced by: '<S8>/Constant2'
                                      */
  real_T Carriercounter_CarrCount_j;
                                   /* Mask Parameter: Carriercounter_CarrCount_j
                                    * Referenced by: '<S17>/Constant2'
                                    */
  real_T Carriercounter_Range;         /* Mask Parameter: Carriercounter_Range
                                        * Referenced by:
                                        *   '<S8>/Bias'
                                        *   '<S8>/Gain'
                                        */
  real_T Carriercounter_Range_j;       /* Mask Parameter: Carriercounter_Range_j
                                        * Referenced by:
                                        *   '<S17>/Bias'
                                        *   '<S17>/Gain'
                                        */
  real_T PWMGenerator_Tdelay;          /* Mask Parameter: PWMGenerator_Tdelay
                                        * Referenced by: '<S16>/Integrator'
                                        */
  real_T PWMGenerator1_Tdelay;         /* Mask Parameter: PWMGenerator1_Tdelay
                                        * Referenced by: '<S25>/Integrator'
                                        */
  real_T PWMGenerator_Tper;            /* Mask Parameter: PWMGenerator_Tper
                                        * Referenced by:
                                        *   '<S8>/Constant10'
                                        *   '<S8>/Constant6'
                                        *   '<S8>/Gain1'
                                        *   '<S12>/Switch'
                                        *   '<S13>/Switch'
                                        *   '<S14>/Bias'
                                        *   '<S14>/Constant'
                                        */
  real_T PWMGenerator1_Tper;           /* Mask Parameter: PWMGenerator1_Tper
                                        * Referenced by:
                                        *   '<S17>/Constant10'
                                        *   '<S17>/Constant6'
                                        *   '<S17>/Gain1'
                                        *   '<S21>/Switch'
                                        *   '<S22>/Switch'
                                        *   '<S23>/Bias'
                                        *   '<S23>/Constant'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S1>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S2>/Constant'
                                      */
  real_T IntegratorwithWrappedStateDiscr;
                              /* Mask Parameter: IntegratorwithWrappedStateDiscr
                               * Referenced by: '<S15>/Integrator'
                               */
  real_T IntegratorwithWrappedStateDis_h;
                              /* Mask Parameter: IntegratorwithWrappedStateDis_h
                               * Referenced by: '<S24>/Integrator'
                               */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 0.7
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Integrator_WrappedStateUpperVal;/* Expression: WrappedStateUpperValue
                                          * Referenced by: '<S15>/Integrator'
                                          */
  real_T Integrator_WrappedStateLowerVal;/* Expression: WrappedStateLowerValue
                                          * Referenced by: '<S15>/Integrator'
                                          */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Integrator_WrappedStateUpperV_e;/* Expression: WrappedStateUpperValue
                                          * Referenced by: '<S16>/Integrator'
                                          */
  real_T Integrator_WrappedStateLowerV_b;/* Expression: WrappedStateLowerValue
                                          * Referenced by: '<S16>/Integrator'
                                          */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 0.7
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Integrator_WrappedStateUpperV_p;/* Expression: WrappedStateUpperValue
                                          * Referenced by: '<S24>/Integrator'
                                          */
  real_T Integrator_WrappedStateLowerV_p;/* Expression: WrappedStateLowerValue
                                          * Referenced by: '<S24>/Integrator'
                                          */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Integrator_WrappedStateUpperV_c;/* Expression: WrappedStateUpperValue
                                          * Referenced by: '<S25>/Integrator'
                                          */
  real_T Integrator_WrappedStateLowerV_f;/* Expression: WrappedStateLowerValue
                                          * Referenced by: '<S25>/Integrator'
                                          */
  real_T Constant2_Value_g4;           /* Expression: 0
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Constant3_Value_i;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PWM_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_PWM_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_PWM_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][4];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PWM_T PWM_P;

/* Block signals (default storage) */
extern B_PWM_T PWM_B;

/* Continuous states (default storage) */
extern X_PWM_T PWM_X;

/* Model entry point functions */
extern void PWM_initialize(void);
extern void PWM_output(void);
extern void PWM_update(void);
extern void PWM_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PWM_T *const PWM_M;

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
 * '<Root>' : 'PWM'
 * '<S1>'   : 'PWM/Compare To Constant'
 * '<S2>'   : 'PWM/Compare To Constant1'
 * '<S3>'   : 'PWM/DS1104BIT_OUT_C2'
 * '<S4>'   : 'PWM/DS1104BIT_OUT_C3'
 * '<S5>'   : 'PWM/PWM Generator'
 * '<S6>'   : 'PWM/PWM Generator1'
 * '<S7>'   : 'PWM/RTI Data'
 * '<S8>'   : 'PWM/PWM Generator/Carrier counter'
 * '<S9>'   : 'PWM/PWM Generator/Compare To Zero'
 * '<S10>'  : 'PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S11>'  : 'PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S12>'  : 'PWM/PWM Generator/Carrier counter/Limitation'
 * '<S13>'  : 'PWM/PWM Generator/Carrier counter/Limitation1'
 * '<S14>'  : 'PWM/PWM Generator/Carrier counter/scale'
 * '<S15>'  : 'PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Continuous'
 * '<S16>'  : 'PWM/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Continuous'
 * '<S17>'  : 'PWM/PWM Generator1/Carrier counter'
 * '<S18>'  : 'PWM/PWM Generator1/Compare To Zero'
 * '<S19>'  : 'PWM/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S20>'  : 'PWM/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S21>'  : 'PWM/PWM Generator1/Carrier counter/Limitation'
 * '<S22>'  : 'PWM/PWM Generator1/Carrier counter/Limitation1'
 * '<S23>'  : 'PWM/PWM Generator1/Carrier counter/scale'
 * '<S24>'  : 'PWM/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Continuous'
 * '<S25>'  : 'PWM/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Continuous'
 * '<S26>'  : 'PWM/RTI Data/RTI Data Store'
 * '<S27>'  : 'PWM/RTI Data/RTI Data Store/RTI Data Store'
 * '<S28>'  : 'PWM/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_PWM_h_ */
