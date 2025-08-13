/***************************************************************************

   Source file PWM_withSlaveBITOUT_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1104 23.1 (02-May-2023)
   Thu Jul 17 17:59:20 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "PWM_withSlaveBITOUT_trc_ptr.h"
#include "PWM_withSlaveBITOUT.h"
#include "PWM_withSlaveBITOUT_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_PWM_withSlaveBITOUT_real_T_0 = NULL;
volatile boolean_T *p_0_PWM_withSlaveBITOUT_boolean_T_1 = NULL;
volatile real_T *p_1_PWM_withSlaveBITOUT_real_T_0 = NULL;
volatile real_T *p_2_PWM_withSlaveBITOUT_real_T_0 = NULL;
volatile boolean_T *p_2_PWM_withSlaveBITOUT_boolean_T_1 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_PWM_withSlaveBITOUT_real_T_0 = &PWM_withSlaveBITOUT_B.Probe[0];
  p_0_PWM_withSlaveBITOUT_boolean_T_1 = &PWM_withSlaveBITOUT_B.Compare;
  p_1_PWM_withSlaveBITOUT_real_T_0 =
    &PWM_withSlaveBITOUT_P.Carriercounter_CarrCount;
  p_2_PWM_withSlaveBITOUT_real_T_0 = &PWM_withSlaveBITOUT_DW.Integrator_DSTATE;
  p_2_PWM_withSlaveBITOUT_boolean_T_1 =
    &PWM_withSlaveBITOUT_DW.Initial_FirstOutputTime;
}

void PWM_withSlaveBITOUT_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
