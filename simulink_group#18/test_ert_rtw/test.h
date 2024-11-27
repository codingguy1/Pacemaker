/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.h
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov 26 19:47:45 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <string.h>
#include <stddef.h>
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"

/* Child system includes */
#include "send_params_private.h"
#include "send_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T TxPinLoc;
  real32_T off_time;
  real32_T off_time_l;                 /* '<Root>/Chart' */
  uint16_T switch_time;
  uint16_T switch_time_i;              /* '<Root>/Chart' */
  uint8_T BytePack1[4];                /* '<S3>/Byte Pack1' */
  uint8_T BytePackaa[2];               /* '<S3>/Byte Packaa' */
  uint8_T blue_enable;                 /* '<Root>/Chart' */
  uint8_T green_enable;                /* '<Root>/Chart' */
  uint8_T red_enable;                  /* '<Root>/Chart' */
} B_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_SCIRead_test_T obj;      /* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_test_T obj_l;   /* '<S3>/Serial Transmit' */
  freedomk64f_DigitalWrite_test_T obj_lh;/* '<S4>/Digital Write1' */
  freedomk64f_DigitalWrite_test_T obj_m;/* '<S4>/Digital Write2' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart1' */
  uint8_T is_active_c1_test;           /* '<Root>/Chart1' */
  uint8_T is_c1_test;                  /* '<Root>/Chart1' */
  uint8_T is_c3_test;                  /* '<Root>/Chart' */
} DW_test_T;

/* Parameters (default storage) */
struct P_test_T_ {
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_test_T test_P;

/* Block signals (default storage) */
extern B_test_T test_B;

/* Block states (default storage) */
extern DW_test_T test_DW;

/* Model entry point functions */
extern void test_initialize(void);
extern void test_step(void);
extern void test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_T *const test_M;

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
 * '<Root>' : 'test'
 * '<S1>'   : 'test/Chart'
 * '<S2>'   : 'test/Chart1'
 * '<S3>'   : 'test/Function-Call Subsystem'
 * '<S4>'   : 'test/Subsystem'
 */
#endif                                 /* RTW_HEADER_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
