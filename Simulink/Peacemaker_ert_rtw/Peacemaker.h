/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Peacemaker.h
 *
 * Code generated for Simulink model 'Peacemaker'.
 *
 * Model version                  : 1.39
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Oct 23 16:02:42 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Peacemaker_h_
#define RTW_HEADER_Peacemaker_h_
#include <math.h>
#include <stddef.h>
#ifndef Peacemaker_COMMON_INCLUDES_
# define Peacemaker_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#endif                                 /* Peacemaker_COMMON_INCLUDES_ */

#include "Peacemaker_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ATR_GND_CTRL;                 /* '<Root>/Main' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Main' */
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Main' */
  real_T PACE_GND_CTRL;                /* '<Root>/Main' */
  real_T PACING_REF_PWM;               /* '<Root>/Main' */
  real_T VENT_GND_CTRL;                /* '<Root>/Main' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Main' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Main' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Main' */
  real_T FRONTEND_CTRL;                /* '<Root>/Main' */
  real_T VENT_CMP_REF_PWM;             /* '<Root>/Main' */
  real_T ATR_CMP_REF_PWM;              /* '<Root>/Main' */
  real_T BLUE_LED;                     /* '<Root>/Main' */
  real_T RED_LED;                      /* '<Root>/Main' */
} B_Peacemaker_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_DigitalRead_Peace_T obj; /* '<S1>/Digital Read' */
  freedomk64f_DigitalRead_Peace_T obj_k;/* '<S1>/Digital Read1' */
  freedomk64f_DigitalWrite_Peac_T obj_j;/* '<S3>/Digital Write' */
  freedomk64f_DigitalWrite_Peac_T obj_h;/* '<S3>/Digital Write1' */
  freedomk64f_DigitalWrite_Peac_T obj_n;/* '<S3>/Digital Write2' */
  freedomk64f_DigitalWrite_Peac_T obj_jy;/* '<S3>/Digital Write3' */
  freedomk64f_DigitalWrite_Peac_T obj_l;/* '<S3>/Digital Write4' */
  freedomk64f_DigitalWrite_Peac_T obj_nc;/* '<S3>/Digital Write5' */
  freedomk64f_DigitalWrite_Peac_T obj_e;/* '<S3>/Digital Write6' */
  freedomk64f_DigitalWrite_Peac_T obj_j1;/* '<S3>/Digital Write7' */
  freedomk64f_DigitalWrite_Peac_T obj_f;/* '<S3>/Digital Write8' */
  freedomk64f_DigitalWrite_Peac_T obj_nf;/* '<S3>/Digital Write9' */
  freedomk64f_DigitalWrite_Peac_T obj_et;/* '<S3>/Digital Write10' */
  freedomk64f_PWMOutput_Peacema_T obj_p;/* '<S3>/PWM Output' */
  freedomk64f_PWMOutput_Peacema_T obj_m;/* '<S3>/PWM Output1' */
  freedomk64f_PWMOutput_Peacema_T obj_km;/* '<S3>/PWM Output2' */
  uint32_T temporalCounter_i1;         /* '<Root>/Main' */
  uint8_T is_active_c3_Peacemaker;     /* '<Root>/Main' */
  uint8_T is_c3_Peacemaker;            /* '<Root>/Main' */
  uint8_T is_AOO;                      /* '<Root>/Main' */
  uint8_T is_VVI;                      /* '<Root>/Main' */
  uint8_T is_AAI;                      /* '<Root>/Main' */
  uint8_T is_VOO;                      /* '<Root>/Main' */
} DW_Peacemaker_T;

/* Parameters (default storage) */
struct P_Peacemaker_T_ {
  real_T DigitalRead1_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S1>/Digital Read1'
                                        */
  real_T DigitalRead_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S1>/Digital Read'
                                        */
  real_T AMPLITUDE_Value;              /* Expression: 60
                                        * Referenced by: '<S1>/AMPLITUDE'
                                        */
  real_T msec_Value;                   /* Expression: 60000
                                        * Referenced by: '<S1>/msec'
                                        */
  real_T BPM_Value;                    /* Expression: 120
                                        * Referenced by: '<S1>/BPM'
                                        */
  real_T Pulse_Width_Value;            /* Expression: 1
                                        * Referenced by: '<S1>/Pulse_Width'
                                        */
  real_T Mode_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Mode'
                                        */
  real_T threshold_Value;              /* Expression: 66
                                        * Referenced by: '<S1>/threshold'
                                        */
  real_T Arp_Value;                    /* Expression: 0
                                        * Referenced by: '<S1>/Arp'
                                        */
  real_T Vrp_Value;                    /* Expression: 100
                                        * Referenced by: '<S1>/Vrp'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Peacemaker_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Peacemaker_T Peacemaker_P;

/* Block signals (default storage) */
extern B_Peacemaker_T Peacemaker_B;

/* Block states (default storage) */
extern DW_Peacemaker_T Peacemaker_DW;

/* Model entry point functions */
extern void Peacemaker_initialize(void);
extern void Peacemaker_step(void);
extern void Peacemaker_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Peacemaker_T *const Peacemaker_M;

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
 * '<Root>' : 'Peacemaker'
 * '<S1>'   : 'Peacemaker/Input'
 * '<S2>'   : 'Peacemaker/Main'
 * '<S3>'   : 'Peacemaker/Output'
 */
#endif                                 /* RTW_HEADER_Peacemaker_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
