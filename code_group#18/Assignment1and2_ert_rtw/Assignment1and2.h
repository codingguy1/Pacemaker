/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1and2.h
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

#ifndef RTW_HEADER_Assignment1and2_h_
#define RTW_HEADER_Assignment1and2_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef Assignment1and2_COMMON_INCLUDES_
# define Assignment1and2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#include "MW_I2C.h"
#endif                                 /* Assignment1and2_COMMON_INCLUDES_ */

#include "Assignment1and2_types.h"

/* Child system includes */
#include "send_params_private.h"
#include "send_params.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T TxDataLocChar[71];
  uint8_T TmpSignalConversionAtSerial[71];
  real_T FXOS87006AxesSensor[3];       /* '<S5>/FXOS8700 6-Axes Sensor' */
  uint8_T RxDataLocChar[11];
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T green_out;                    /* '<S5>/Adaptive Rate FSM' */
  real_T red_out;                      /* '<S5>/Adaptive Rate FSM' */
  real_T blue_out;                     /* '<S5>/Adaptive Rate FSM' */
  real_T PACE_CHARGE_CTRL;             /* '<Root>/Main State Flowchart' */
  real_T VENT_PACE_CTRL;               /* '<Root>/Main State Flowchart' */
  real_T ATR_PACE_CTRL;                /* '<Root>/Main State Flowchart' */
  real_T ATR_GND_CTRL;                 /* '<Root>/Main State Flowchart' */
  real_T VENT_GND_CTRL;                /* '<Root>/Main State Flowchart' */
  real_T PACE_GND_CTRL;                /* '<Root>/Main State Flowchart' */
  real_T Z_VENT_CTRL;                  /* '<Root>/Main State Flowchart' */
  real_T Z_ATR_CTRL;                   /* '<Root>/Main State Flowchart' */
  real_T FRONTEND_CTRL;                /* '<Root>/Main State Flowchart' */
  real32_T DataTypeConversion;         /* '<S1>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<S1>/Data Type Conversion1' */
  real32_T lower_rate_limit;
  real32_T upper_rate_limit;
  real32_T maximum_sensor_rate;
  real32_T atrial_amplitude;
  real32_T ventricular_amplitude;
  real32_T atrial_pulse_width;
  real32_T ventricular_pulse_width;
  real32_T atrial_sensitivity;
  real32_T ventricular_sensitivity;
  real32_T ARP;
  real32_T VRP;
  real32_T activity_threshold;
  real32_T reaction_time;
  real32_T response_factor;
  real32_T recovery_time;
  real32_T TmpLatchAtAtrial_SignalOutport1;
  real32_T TmpLatchAtVent_SignalOutport1;
  real32_T lower_rate_limit_f;         /* '<Root>/Serial Communication' */
  real32_T upper_rate_limit_b;         /* '<Root>/Serial Communication' */
  real32_T maximum_sensor_rate_p;      /* '<Root>/Serial Communication' */
  real32_T atrial_amplitude_o;         /* '<Root>/Serial Communication' */
  real32_T ventricular_amplitude_g;    /* '<Root>/Serial Communication' */
  real32_T atrial_pulse_width_f;       /* '<Root>/Serial Communication' */
  real32_T ventricular_pulse_width_n;  /* '<Root>/Serial Communication' */
  real32_T atrial_sensitivity_k;       /* '<Root>/Serial Communication' */
  real32_T ventricular_sensitivity_c;  /* '<Root>/Serial Communication' */
  real32_T ARP_o;                      /* '<Root>/Serial Communication' */
  real32_T VRP_g;                      /* '<Root>/Serial Communication' */
  real32_T activity_threshold_m;       /* '<Root>/Serial Communication' */
  real32_T reaction_time_k;            /* '<Root>/Serial Communication' */
  real32_T response_factor_c;          /* '<Root>/Serial Communication' */
  real32_T recovery_time_e;            /* '<Root>/Serial Communication' */
  real32_T y;                          /* '<S5>/interval converter' */
  real32_T adaptive_rate;              /* '<S5>/Adaptive Rate FSM' */
  real32_T y_l;                        /* '<S4>/Vent_Amp Calculator' */
  real32_T y_c;                        /* '<S4>/VRP Limiter' */
  real32_T y_d;                        /* '<S4>/VPW Limiter' */
  real32_T y_n;                        /* '<S4>/URL Limiter' */
  real32_T y_i;                        /* '<S4>/URL Function' */
  real32_T y_nn;                       /* '<S4>/LRL Limiter' */
  real32_T y_l0;                       /* '<S4>/LRI Function' */
  real32_T y_id;                       /* '<S4>/Atri_Amp Calculator' */
  real32_T y_lk;                       /* '<S4>/ARP Limiter' */
  real32_T y_b;                        /* '<S4>/APW Limiter' */
  real32_T PACING_REF_PWM;             /* '<Root>/Main State Flowchart' */
  uint16_T PVARP;
  uint16_T PVARP_l;                    /* '<Root>/Serial Communication' */
  uint8_T BytePack15[4];               /* '<S6>/Byte Pack15' */
  uint8_T BytePack16[4];               /* '<S6>/Byte Pack16' */
  uint8_T BytePack17[4];               /* '<S6>/Byte Pack17' */
  uint8_T BytePack1[4];                /* '<S6>/Byte Pack1' */
  uint8_T BytePack4[4];                /* '<S6>/Byte Pack4' */
  uint8_T BytePack8[4];                /* '<S6>/Byte Pack8' */
  uint8_T BytePack10[4];               /* '<S6>/Byte Pack10' */
  uint8_T BytePack3[4];                /* '<S6>/Byte Pack3' */
  uint8_T BytePack9[4];                /* '<S6>/Byte Pack9' */
  uint8_T BytePack5[4];                /* '<S6>/Byte Pack5' */
  uint8_T BytePack[4];                 /* '<S6>/Byte Pack' */
  uint8_T BytePack6[2];                /* '<S6>/Byte Pack6' */
  uint8_T BytePack2[4];                /* '<S6>/Byte Pack2' */
  uint8_T BytePack11[4];               /* '<S6>/Byte Pack11' */
  uint8_T BytePack12[4];               /* '<S6>/Byte Pack12' */
  uint8_T BytePack7[4];                /* '<S6>/Byte Pack7' */
  uint8_T BytePack13[4];               /* '<S6>/Byte Pack13' */
  uint8_T BytePack14[4];               /* '<S6>/Byte Pack14' */
  uint8_T b_SwappedDataBytes[2];
  uint8_T Mode;                        /* '<Root>/Serial Communication' */
  uint8_T y_g;                         /* '<S4>/Mode Limiter' */
  uint8_T SerialReceive_o1[11];        /* '<Root>/Serial Receive' */
  uint8_T SerialReceive_o2;            /* '<Root>/Serial Receive' */
  uint8_T b_RegisterValue;
  uint8_T status;
  boolean_T VENT_CMP_DETECT;           /* '<S1>/VENT_CMP_DETECT' */
  boolean_T ATR_CMP_DETECT;            /* '<S1>/ATR_CMP_DETECT' */
} B_Assignment1and2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_As_T obj; /* '<S5>/Moving Average' */
  g_dsp_private_SlidingWindowAv_T gobj_1;/* '<S5>/Moving Average' */
  g_dsp_private_SlidingWindowAv_T gobj_2;/* '<S5>/Moving Average' */
  freedomk64f_fxos8700_Assignme_T obj_o;/* '<S5>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_Assig_T obj_p;/* '<S1>/VENT_CMP_DETECT' */
  freedomk64f_DigitalRead_Assig_T obj_d;/* '<S1>/ATR_CMP_DETECT' */
  freedomk64f_AnalogInput_Assig_T obj_oo;/* '<S1>/AtrSignalIn' */
  freedomk64f_AnalogInput_Assig_T obj_ok;/* '<S1>/VentSignalIn' */
  freedomk64f_SCIRead_Assignmen_T obj_j;/* '<Root>/Serial Receive' */
  freedomk64f_DigitalWrite_Assi_T obj_i;/* '<S5>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_h;/* '<S5>/Digital Write2' */
  freedomk64f_DigitalWrite_Assi_T obj_b;/* '<S5>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_f;/* '<S2>/Digital Write' */
  freedomk64f_DigitalWrite_Assi_T obj_c;/* '<S2>/Digital Write4' */
  freedomk64f_DigitalWrite_Assi_T obj_e;/* '<S2>/Digital Write3' */
  freedomk64f_DigitalWrite_Assi_T obj_n;/* '<S2>/Digital Write6' */
  freedomk64f_DigitalWrite_Assi_T obj_bj;/* '<S2>/Digital Write5' */
  freedomk64f_DigitalWrite_Assi_T obj_pd;/* '<S2>/Digital Write7' */
  freedomk64f_DigitalWrite_Assi_T obj_il;/* '<S2>/Digital Write2' */
  freedomk64f_DigitalWrite_Assi_T obj_ey;/* '<S2>/Digital Write1' */
  freedomk64f_DigitalWrite_Assi_T obj_i4;/* '<S2>/Digital Write8' */
  freedomk64f_PWMOutput_Assignm_T obj_pv;/* '<S2>/PWM Output1' */
  freedomk64f_PWMOutput_Assignm_T obj_k;/* '<S2>/PWM Output' */
  freedomk64f_PWMOutput_Assignm_T obj_a;/* '<S2>/PWM Output2' */
  freedomk64f_SCIWrite_Assignme_T obj_m;/* '<S6>/Serial Transmit' */
  uint32_T temporalCounter_i1;         /* '<S5>/Adaptive Rate FSM' */
  uint32_T temporalCounter_i1_g;       /* '<Root>/Main State Flowchart' */
  uint8_T is_c12_Assignment1and2;      /* '<Root>/Serial Communication' */
  uint8_T is_active_c13_Assignment1and2;/* '<S5>/Adaptive Rate FSM' */
  uint8_T is_c13_Assignment1and2;      /* '<S5>/Adaptive Rate FSM' */
  uint8_T is_active_c3_Assignment1and2;/* '<Root>/Main State Flowchart' */
  uint8_T is_c3_Assignment1and2;       /* '<Root>/Main State Flowchart' */
  uint8_T is_AOOR;                     /* '<Root>/Main State Flowchart' */
  uint8_T is_AAI;                      /* '<Root>/Main State Flowchart' */
  uint8_T is_AAIR;                     /* '<Root>/Main State Flowchart' */
  uint8_T is_VVI;                      /* '<Root>/Main State Flowchart' */
  uint8_T is_AOO;                      /* '<Root>/Main State Flowchart' */
  uint8_T is_VVIR;                     /* '<Root>/Main State Flowchart' */
  uint8_T is_VOOR;                     /* '<Root>/Main State Flowchart' */
  uint8_T is_VOO;                      /* '<Root>/Main State Flowchart' */
  boolean_T objisempty_d;              /* '<S5>/FXOS8700 6-Axes Sensor' */
  boolean_T objisempty_d2;             /* '<S5>/Moving Average' */
  boolean_T objisempty_c;              /* '<S5>/Digital Write1' */
  boolean_T objisempty_g;              /* '<S5>/Digital Write2' */
  boolean_T objisempty_g2;             /* '<S5>/Digital Write3' */
  boolean_T objisempty_p;              /* '<S2>/Digital Write' */
  boolean_T objisempty_b;              /* '<S2>/Digital Write4' */
  boolean_T objisempty_l;              /* '<S2>/Digital Write3' */
  boolean_T objisempty_a;              /* '<S2>/Digital Write6' */
  boolean_T objisempty_o;              /* '<S2>/Digital Write5' */
  boolean_T objisempty_m;              /* '<S2>/Digital Write7' */
  boolean_T objisempty_k;              /* '<S2>/Digital Write2' */
  boolean_T objisempty_cu;             /* '<S2>/Digital Write1' */
  boolean_T objisempty_m3;             /* '<S2>/Digital Write8' */
  boolean_T objisempty_n;              /* '<S2>/PWM Output1' */
  boolean_T objisempty_f;              /* '<S2>/PWM Output' */
  boolean_T objisempty_h;              /* '<S2>/PWM Output2' */
  boolean_T objisempty_ap;             /* '<S1>/AtrSignalIn' */
  boolean_T objisempty_fv;             /* '<S1>/VentSignalIn' */
  boolean_T objisempty_lk;             /* '<S1>/VENT_CMP_DETECT' */
  boolean_T objisempty_lf;             /* '<S1>/ATR_CMP_DETECT' */
  boolean_T objisempty_mc;             /* '<Root>/Serial Receive' */
} DW_Assignment1and2_T;

/* Parameters (default storage) */
struct P_Assignment1and2_T_ {
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S1>/ATR_CMP_DETECT'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S1>/VENT_CMP_DETECT'
                                        */
  real_T VentSignalIn_SampleTime;      /* Expression: SampleTime
                                        * Referenced by: '<S1>/VentSignalIn'
                                        */
  real_T AtrSignalIn_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S1>/AtrSignalIn'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S5>/FXOS8700 6-Axes Sensor'
                                         */
  uint8_T Multiply_Gain;               /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S5>/Multiply'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Assignment1and2_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_Assignment1and2_T Assignment1and2_P;

/* Block signals (default storage) */
extern B_Assignment1and2_T Assignment1and2_B;

/* Block states (default storage) */
extern DW_Assignment1and2_T Assignment1and2_DW;

/* Model entry point functions */
extern void Assignment1and2_initialize(void);
extern void Assignment1and2_step(void);
extern void Assignment1and2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Assignment1and2_T *const Assignment1and2_M;

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
 * '<Root>' : 'Assignment1and2'
 * '<S1>'   : 'Assignment1and2/Hardware Input'
 * '<S2>'   : 'Assignment1and2/Hardware Output'
 * '<S3>'   : 'Assignment1and2/Main State Flowchart'
 * '<S4>'   : 'Assignment1and2/Parameter Input'
 * '<S5>'   : 'Assignment1and2/Rate Adaptive Pacing'
 * '<S6>'   : 'Assignment1and2/Send Parameters'
 * '<S7>'   : 'Assignment1and2/Serial Communication'
 * '<S8>'   : 'Assignment1and2/Parameter Input/APW Limiter'
 * '<S9>'   : 'Assignment1and2/Parameter Input/ARP Limiter'
 * '<S10>'  : 'Assignment1and2/Parameter Input/Atri_Amp Calculator'
 * '<S11>'  : 'Assignment1and2/Parameter Input/Atri_Amp Limiter'
 * '<S12>'  : 'Assignment1and2/Parameter Input/LRI Function'
 * '<S13>'  : 'Assignment1and2/Parameter Input/LRL Limiter'
 * '<S14>'  : 'Assignment1and2/Parameter Input/Mode Limiter'
 * '<S15>'  : 'Assignment1and2/Parameter Input/URL Function'
 * '<S16>'  : 'Assignment1and2/Parameter Input/URL Limiter'
 * '<S17>'  : 'Assignment1and2/Parameter Input/VPW Limiter'
 * '<S18>'  : 'Assignment1and2/Parameter Input/VRP Limiter'
 * '<S19>'  : 'Assignment1and2/Parameter Input/Vent_Amp Calculator'
 * '<S20>'  : 'Assignment1and2/Parameter Input/Vent_Amp Limiter'
 * '<S21>'  : 'Assignment1and2/Rate Adaptive Pacing/Adaptive Rate FSM'
 * '<S22>'  : 'Assignment1and2/Rate Adaptive Pacing/interval converter'
 */
#endif                                 /* RTW_HEADER_Assignment1and2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
