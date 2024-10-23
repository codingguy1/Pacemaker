/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Averynicefile.h
 *
 * Code generated for Simulink model 'Averynicefile'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Oct 23 12:00:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Averynicefile_h_
#define RTW_HEADER_Averynicefile_h_
#include <math.h>
#include <stddef.h>
#ifndef Averynicefile_COMMON_INCLUDES_
# define Averynicefile_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* Averynicefile_COMMON_INCLUDES_ */

#include "Averynicefile_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T output_atr_heartbeat;         /* '<Root>/Chart' */
  real_T output_vent_heartbeat;        /* '<Root>/Chart' */
  real_T ATR_GND_CTRL;                 /* '<Root>/Chart' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Chart' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Chart' */
  real_T PACING_REF_PWM;               /* '<Root>/Chart' */
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Chart' */
  real_T PACE_GND_CTRL;                /* '<Root>/Chart' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Chart' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Chart' */
  real_T VENT_GND_CTRL;                /* '<Root>/Chart' */
  real_T FRONTEND_CTRL;                /* '<Root>/Chart' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Chart' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Chart' */
} B_Averynicefile_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Avery_T obj; /* '<Root>/Digital Read' */
  freedomk64f_DigitalRead_Avery_T obj_m;/* '<Root>/Digital Read1' */
  freedomk64f_DigitalWrite_Aver_T obj_h;/* '<Root>/ATR_GND_CTRL' */
  freedomk64f_DigitalWrite_Aver_T obj_e;/* '<Root>/ATR_PACE_CTRL' */
  freedomk64f_DigitalWrite_Aver_T obj_hy;/* '<Root>/Digital Write' */
  freedomk64f_DigitalWrite_Aver_T obj_k;/* '<Root>/Digital Write1' */
  freedomk64f_DigitalWrite_Aver_T obj_d;/* '<Root>/Digital Write2' */
  freedomk64f_DigitalWrite_Aver_T obj_j;/* '<Root>/PACE_CHARGE_CTRL' */
  freedomk64f_DigitalWrite_Aver_T obj_b;/* '<Root>/PACE_GND_CTRL' */
  freedomk64f_DigitalWrite_Aver_T obj_g;/* '<Root>/VENT_GND_CTRL' */
  freedomk64f_DigitalWrite_Aver_T obj_n;/* '<Root>/VENT_PACE_CTRL' */
  freedomk64f_DigitalWrite_Aver_T obj_o;/* '<Root>/Z_ATR_CTRL' */
  freedomk64f_DigitalWrite_Aver_T obj_hb;/* '<Root>/Z_VENT_CTRL' */
  freedomk64f_PWMOutput_Averyni_T obj_a;/* '<Root>/PWM Output' */
  freedomk64f_PWMOutput_Averyni_T obj_jn;/* '<Root>/PWM Output1' */
  freedomk64f_PWMOutput_Averyni_T obj_bg;/* '<Root>/PWM Output2' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c3_Averynicefile;  /* '<Root>/Chart' */
  uint8_T is_c3_Averynicefile;         /* '<Root>/Chart' */
} DW_Averynicefile_T;

/* Parameters (default storage) */
struct P_Averynicefile_T_ {
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read1'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<Root>/Digital Read'
                                        */
  real_T LRL_Value;                    /* Expression: 1000
                                        * Referenced by: '<Root>/LRL'
                                        */
  real_T URL_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/URL'
                                        */
  real_T atr_amp_Value;                /* Expression: 1
                                        * Referenced by: '<Root>/atr_amp'
                                        */
  real_T atr_PW_Value;                 /* Expression: 0.4
                                        * Referenced by: '<Root>/atr_PW'
                                        */
  real_T ARP_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/ARP'
                                        */
  real_T PVARP_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/PVARP'
                                        */
  real_T state_determine_Value;        /* Expression: 2
                                        * Referenced by: '<Root>/state_determine'
                                        */
  real_T hysteresis_Value;             /* Expression: 300
                                        * Referenced by: '<Root>/hysteresis'
                                        */
  real_T rate_smoothing_Value;         /* Expression: 1
                                        * Referenced by: '<Root>/rate_smoothing'
                                        */
  real_T vent_PW_Value;                /* Expression: 1
                                        * Referenced by: '<Root>/vent_PW'
                                        */
  real_T vent_amp_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/vent_amp'
                                        */
  real_T VRP_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/VRP'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Averynicefile_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Averynicefile_T Averynicefile_P;

/* Block signals (default storage) */
extern B_Averynicefile_T Averynicefile_B;

/* Block states (default storage) */
extern DW_Averynicefile_T Averynicefile_DW;

/* Model entry point functions */
extern void Averynicefile_initialize(void);
extern void Averynicefile_step(void);
extern void Averynicefile_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Averynicefile_T *const Averynicefile_M;

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
 * '<Root>' : 'Averynicefile'
 * '<S1>'   : 'Averynicefile/Chart'
 */
#endif                                 /* RTW_HEADER_Averynicefile_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
