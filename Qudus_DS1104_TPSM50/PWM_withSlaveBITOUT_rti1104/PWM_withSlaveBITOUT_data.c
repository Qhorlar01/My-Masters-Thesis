/*
 * PWM_withSlaveBITOUT_data.c
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

#include "PWM_withSlaveBITOUT.h"

/* Block parameters (default storage) */
P_PWM_withSlaveBITOUT_T PWM_withSlaveBITOUT_P = {
  /* Mask Parameter: Carriercounter_CarrCount
   * Referenced by: '<S6>/Constant2'
   */
  1.0,

  /* Mask Parameter: Carriercounter_CarrCount_m
   * Referenced by: '<S21>/Constant2'
   */
  1.0,

  /* Mask Parameter: Carriercounter_Range
   * Referenced by:
   *   '<S6>/Bias'
   *   '<S6>/Gain'
   */
  1.0,

  /* Mask Parameter: Carriercounter_Range_l
   * Referenced by:
   *   '<S21>/Bias'
   *   '<S21>/Gain'
   */
  1.0,

  /* Mask Parameter: PWMGenerator_Tdelay
   * Referenced by: '<S17>/Initial'
   */
  0.0,

  /* Mask Parameter: PWMGenerator1_Tdelay
   * Referenced by: '<S32>/Initial'
   */
  0.00025,

  /* Mask Parameter: PWMGenerator_Tper
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
  0.0005,

  /* Mask Parameter: PWMGenerator1_Tper
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
  0.0005,

  /* Mask Parameter: IntegratorwithWrappedStateDiscr
   * Referenced by:
   *   '<S14>/Constant'
   *   '<S16>/Bias'
   *   '<S16>/Gain'
   *   '<S16>/Gain1'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_f
   * Referenced by:
   *   '<S18>/Constant'
   *   '<S20>/Bias'
   *   '<S20>/Gain'
   *   '<S20>/Gain1'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_p
   * Referenced by:
   *   '<S29>/Constant'
   *   '<S31>/Bias'
   *   '<S31>/Gain'
   *   '<S31>/Gain1'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_h
   * Referenced by:
   *   '<S33>/Constant'
   *   '<S35>/Bias'
   *   '<S35>/Gain'
   *   '<S35>/Gain1'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_a
   * Referenced by: '<S13>/Initial'
   */
  0.0,

  /* Mask Parameter: IntegratorwithWrappedStateDis_i
   * Referenced by: '<S28>/Initial'
   */
  0.00025,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/Constant'
   */
  0.0,

  /* Expression: 0.7
   * Referenced by: '<Root>/Constant'
   */
  0.7,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S13>/Integrator'
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S10>/Constant2'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S17>/Integrator'
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S11>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant3'
   */
  1.0,

  /* Expression: 0.7
   * Referenced by: '<Root>/Constant1'
   */
  0.7,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S28>/Integrator'
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S25>/Constant2'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_j
   * Referenced by: '<S32>/Integrator'
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S26>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S21>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S21>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S21>/Constant3'
   */
  1.0
};
