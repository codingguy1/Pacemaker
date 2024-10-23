/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1.h
 *
 * Code generated for Simulink model 'Assignment1'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Oct 23 10:07:31 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Assignment1_h_
#define RTW_HEADER_Assignment1_h_
#include <math.h>
#include <stddef.h>
#ifndef Assignment1_COMMON_INCLUDES_
# define Assignment1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                                 /* Assignment1_COMMON_INCLUDES_ */

#include "Assignment1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Chart' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Chart' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Chart' */
  real_T ATR_GND_CTRL;                 /* '<Root>/Chart' */
  real_T VENT_GND_CTRL;                /* '<Root>/Chart' */
  real_T PACE_GND_CTRL;                /* '<Root>/Chart' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Chart' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Chart' */
  real_T FRONTEND_CTRL;                /* '<Root>/Chart' */
} B_Assignment1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_AnalogInput_Assig_T obj; /* '<S2>/Analog Input' */
  freedomk64f_AnalogInput_Assig_T obj_c;/* '<S2>/Analog Input1' */
  freedomk64f_AnalogInput_Assig_T obj_o;/* '<S2>/Analog Input2' */
  freedomk64f_AnalogInput_Assig_T obj_j;/* '<S2>/Analog Input3' */
  freedomk64f_AnalogInput_Assig_T obj_b;/* '<S2>/Analog Input4' */
  freedomk64f_DigitalRead_Assig_T obj_n;/* '<S2>/Digital Read1' */
  freedomk64f_DigitalRead_Assig_T obj_cn;/* '<S2>/Digital Read' */
  freedomk64f_DigitalWrite_Assi_T obj_m;/* '<S2>/Digital Write' */
  freedomk64f_DigitalWrite_Assi_T obj_p;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_l;/* '<S2>/Digital Write2' */
  freedomk64f_DigitalWrite_Assi_T obj_i;/* '<S2>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_k;/* '<S2>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_l1;/* '<S2>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_o2;/* '<S2>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_by;/* '<S2>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_h;/* '<S2>/Digital Write8' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<Root>/Digital Write' */
  freedomk64f_PWMOutput_Assignm_T obj_f;/* '<S2>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_pg;/* '<S2>/PWM Output2' */
  freedomk64f_PWMOutput_Assignm_T obj_je;/* '<S2>/PWM Output' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_Assignment1;    /* '<Root>/Chart' */
  uint8_T is_c3_Assignment1;           /* '<Root>/Chart' */
} DW_Assignment1_T;

/* Parameters (default storage) */
struct P_Assignment1_T_ {
  real_T AnalogInput4_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Analog Input4'
                                        */
  real_T AnalogInput3_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Analog Input3'
                                        */
  real_T AnalogInput2_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Analog Input2'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Analog Input1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Analog Input'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read'
                                        */
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S2>/Digital Read1'
                                        */
  real_T mode_Value;                   /* Expression: 3
                                        * Referenced by: '<Root>/mode'
                                        */
  real_T atrial_pulse_width_Value;     /* Expression: 1
                                        * Referenced by: '<Root>/atrial_pulse_width'
                                        */
  real_T ventricular_pulse_width_Value;/* Expression: 1
                                        * Referenced by: '<Root>/ventricular_pulse_width'
                                        */
  real_T Constant3_Value;              /* Expression: 60
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant_Value;               /* Expression: 100
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 70
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Assignment1_T Assignment1_P;

/* Block signals (default storage) */
extern B_Assignment1_T Assignment1_B;

/* Block states (default storage) */
extern DW_Assignment1_T Assignment1_DW;

/* Model entry point functions */
extern void Assignment1_initialize(void);
extern void Assignment1_step(void);
extern void Assignment1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment1_T *const Assignment1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/AND' : Unused code path elimination
 * Block '<Root>/AND1' : Unused code path elimination
 * Block '<Root>/AND2' : Unused code path elimination
 * Block '<Root>/AND3' : Unused code path elimination
 * Block '<Root>/Constant4' : Unused code path elimination
 * Block '<Root>/Constant5' : Unused code path elimination
 * Block '<Root>/Constant6' : Unused code path elimination
 * Block '<Root>/Constant7' : Unused code path elimination
 * Block '<Root>/Equal' : Unused code path elimination
 * Block '<Root>/Equal1' : Unused code path elimination
 * Block '<Root>/Equal2' : Unused code path elimination
 * Block '<Root>/Equal3' : Unused code path elimination
 */

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
 * '<Root>' : 'Assignment1'
 * '<S1>'   : 'Assignment1/Chart'
 * '<S2>'   : 'Assignment1/Subsystem Reference'
 */
#endif                                 /* RTW_HEADER_Assignment1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
