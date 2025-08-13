/*********************** dSPACE target specific file *************************

   Header file PWM_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 23.1 (02-May-2023)
   Fri Jul  4 12:20:58 2025

   Copyright 2025, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_PWM_trc_ptr_h_
#define RTI_HEADER_PWM_trc_ptr_h_

/* Include the model header file. */
#include "PWM.h"
#include "PWM_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_PWM_real_T_0;
EXTERN_C volatile boolean_T *p_0_PWM_boolean_T_1;
EXTERN_C volatile real_T *p_1_PWM_real_T_0;
EXTERN_C volatile real_T *p_2_PWM_real_T_0;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void PWM_rti_init_trc_pointers(void);

#endif                                 /* RTI_HEADER_PWM_trc_ptr_h_ */
