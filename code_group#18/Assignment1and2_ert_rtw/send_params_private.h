/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params_private.h
 *
 * Code generated for Simulink model 'Assignment1and2'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Nov 29 23:29:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_send_params_private_h_
#define RTW_HEADER_send_params_private_h_
#include <string.h>
#ifndef Assignment1and2_COMMON_INCLUDES_
# define Assignment1and2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_I2C.h"
#endif                                 /* Assignment1and2_COMMON_INCLUDES_ */

extern void send_params_Init(void);
extern void send_params_Term(void);

#endif                                 /* RTW_HEADER_send_params_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
