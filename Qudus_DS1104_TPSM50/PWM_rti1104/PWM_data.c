/*
 * PWM_data.c
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

#include "PWM.h"

/* Block parameters (default storage) */
P_PWM_T PWM_P = {
  /* Mask Parameter: Carriercounter_CarrCount
   * Referenced by: '<S8>/Constant2'
   */
  1.0,

  /* Mask Parameter: Carriercounter_CarrCount_j
   * Referenced by: '<S17>/Constant2'
   */
  1.0,

  /* Mask Parameter: Carriercounter_Range
   * Referenced by:
   *   '<S8>/Bias'
   *   '<S8>/Gain'
   */
  1.0,

  /* Mask Parameter: Carriercounter_Range_j
   * Referenced by:
   *   '<S17>/Bias'
   *   '<S17>/Gain'
   */
  1.0,

  /* Mask Parameter: PWMGenerator_Tdelay
   * Referenced by: '<S16>/Integrator'
   */
  0.0,

  /* Mask Parameter: PWMGenerator1_Tdelay
   * Referenced by: '<S25>/Integrator'
   */
  5.0E-5,

  /* Mask Parameter: PWMGenerator_Tper
   * Referenced by:
   *   '<S8>/Constant10'
   *   '<S8>/Constant6'
   *   '<S8>/Gain1'
   *   '<S12>/Switch'
   *   '<S13>/Switch'
   *   '<S14>/Bias'
   *   '<S14>/Constant'
   */
  0.0001,

  /* Mask Parameter: PWMGenerator1_Tper
   * Referenced by:
   *   '<S17>/Constant10'
   *   '<S17>/Constant6'
   *   '<S17>/Gain1'
   *   '<S21>/Switch'
   *   '<S22>/Switch'
   *   '<S23>/Bias'
   *   '<S23>/Constant'
   */
  0.0001,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S1>/Constant'
   */
  0.7,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S2>/Constant'
   */
  0.7,

  /* Mask Parameter: IntegratorwithWrappedStateDiscr
   * Referenced by: '<S15>/Integrator'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_h
   * Referenced by: '<S24>/Integrator'
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S9>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant'
   */
  0.0,

  /* Expression: 0.7
   * Referenced by: '<Root>/Constant'
   */
  0.7,

  /* Expression: WrappedStateUpperValue
   * Referenced by: '<S15>/Integrator'
   */
  0.0001,

  /* Expression: WrappedStateLowerValue
   * Referenced by: '<S15>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Constant2'
   */
  0.0,

  /* Expression: WrappedStateUpperValue
   * Referenced by: '<S16>/Integrator'
   */
  0.0002,

  /* Expression: WrappedStateLowerValue
   * Referenced by: '<S16>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S8>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant3'
   */
  1.0,

  /* Expression: 0.7
   * Referenced by: '<Root>/Constant1'
   */
  0.7,

  /* Expression: WrappedStateUpperValue
   * Referenced by: '<S24>/Integrator'
   */
  0.0001,

  /* Expression: WrappedStateLowerValue
   * Referenced by: '<S24>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S21>/Constant2'
   */
  0.0,

  /* Expression: WrappedStateUpperValue
   * Referenced by: '<S25>/Integrator'
   */
  0.0002,

  /* Expression: WrappedStateLowerValue
   * Referenced by: '<S25>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S17>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S17>/Constant3'
   */
  1.0
};
