/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Averynicefile.c
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

#include "Averynicefile.h"
#include "Averynicefile_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Averynicefile_IN_AAI_Hysterisis ((uint8_T)1U)
#define Averynicefile_IN_AAI_active    ((uint8_T)2U)
#define Averynicefile_IN_AAI_active1   ((uint8_T)3U)
#define Averynicefile_IN_AOO_active    ((uint8_T)4U)
#define Averynicefile_IN_AOO_active1   ((uint8_T)5U)
#define Averynicefile_IN_IDLE          ((uint8_T)6U)
#define Averynicefile_IN_VOO_active    ((uint8_T)7U)
#define Averynicefile_IN_VOO_active1   ((uint8_T)8U)
#define Averynicefile_IN_VVI_Hysteresis ((uint8_T)9U)
#define Averynicefile_IN_VVI_active    ((uint8_T)10U)
#define Averynicefile_IN_VVI_active1   ((uint8_T)11U)

/* Block signals (default storage) */
B_Averynicefile_T Averynicefile_B;

/* Block states (default storage) */
DW_Averynicefile_T Averynicefile_DW;

/* Real-time model */
RT_MODEL_Averynicefile_T Averynicefile_M_;
RT_MODEL_Averynicefile_T *const Averynicefile_M = &Averynicefile_M_;

/* Forward declaration for local functions */
static void Averyni_enter_atomic_VVI_active(void);
static void Ave_enter_atomic_AAI_Hysterisis(void);
static void Averynicefile_AAI_Hysterisis(const boolean_T *DigitalRead);
static void Averynicefile_AAI_active(const boolean_T *DigitalRead);
static void Averyni_enter_atomic_AAI_active(void);
static void Averyni_enter_atomic_AOO_active(void);
static void Averyn_enter_atomic_VVI_active1(void);
static void SystemCore_relea_gmmp4fpqp1jlwp(const
  freedomk64f_DigitalRead_Avery_T *obj);
static void SystemCore_delet_gmmp4fpqp1jlwp(const
  freedomk64f_DigitalRead_Avery_T *obj);
static void matlabCodegenHan_gmmp4fpqp1jlwp(freedomk64f_DigitalRead_Avery_T *obj);
static void Averynicefil_SystemCore_release(const
  freedomk64f_DigitalWrite_Aver_T *obj);
static void Averynicefile_SystemCore_delete(const
  freedomk64f_DigitalWrite_Aver_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_Aver_T *obj);
static void Averyni_SystemCore_release_gmmp(const
  freedomk64f_PWMOutput_Averyni_T *obj);
static void Averynic_SystemCore_delete_gmmp(const
  freedomk64f_PWMOutput_Averyni_T *obj);
static void matlabCodegenHandle_matlab_gmmp(freedomk64f_PWMOutput_Averyni_T *obj);

/* Function for Chart: '<Root>/Chart' */
static void Averyni_enter_atomic_VVI_active(void)
{
  Averynicefile_B.FRONTEND_CTRL = 1.0;
  Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
  Averynicefile_B.PACING_REF_PWM = 30.0;
  Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
  Averynicefile_B.PACE_GND_CTRL = 1.0;
  Averynicefile_B.ATR_PACE_CTRL = 0.0;
  Averynicefile_B.ATR_GND_CTRL = 0.0;
  Averynicefile_B.Z_ATR_CTRL = 0.0;
  Averynicefile_B.Z_VENT_CTRL = 0.0;
  Averynicefile_B.VENT_GND_CTRL = 1.0;
  Averynicefile_B.VENT_PACE_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Ave_enter_atomic_AAI_Hysterisis(void)
{
  Averynicefile_B.FRONTEND_CTRL = 1.0;
  Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
  Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
  Averynicefile_B.PACING_REF_PWM = 50.0;
  Averynicefile_B.PACE_GND_CTRL = 1.0;
  Averynicefile_B.ATR_PACE_CTRL = 0.0;
  Averynicefile_B.ATR_GND_CTRL = 1.0;
  Averynicefile_B.VENT_PACE_CTRL = 0.0;
  Averynicefile_B.VENT_GND_CTRL = 0.0;
  Averynicefile_B.Z_ATR_CTRL = 0.0;
  Averynicefile_B.Z_VENT_CTRL = 0.0;
  Averynicefile_B.output_atr_heartbeat = 1.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Averynicefile_AAI_Hysterisis(const boolean_T *DigitalRead)
{
  /* Constant: '<Root>/LRL' incorporates:
   *  Constant: '<Root>/hysteresis'
   */
  if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
      (Averynicefile_P.LRL_Value + Averynicefile_P.hysteresis_Value)) {
    Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AAI_active1;
    Averynicefile_DW.temporalCounter_i1 = 0U;
    Averynicefile_B.FRONTEND_CTRL = 0.0;
    Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
    Averynicefile_B.PACE_CHARGE_CTRL = 0.0;
    Averynicefile_B.PACE_GND_CTRL = 1.0;
    Averynicefile_B.ATR_PACE_CTRL = 1.0;
    Averynicefile_B.ATR_GND_CTRL = 0.0;
    Averynicefile_B.VENT_PACE_CTRL = 0.0;
    Averynicefile_B.VENT_GND_CTRL = 0.0;
    Averynicefile_B.Z_ATR_CTRL = 0.0;
    Averynicefile_B.Z_VENT_CTRL = 0.0;
  } else if (*DigitalRead) {
    Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AAI_Hysterisis;
    Averynicefile_DW.temporalCounter_i1 = 0U;
    Ave_enter_atomic_AAI_Hysterisis();
  } else {
    Averynicefile_B.FRONTEND_CTRL = 1.0;
    Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
    Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
    Averynicefile_B.PACING_REF_PWM = 50.0;
    Averynicefile_B.PACE_GND_CTRL = 1.0;
    Averynicefile_B.ATR_PACE_CTRL = 0.0;
    Averynicefile_B.ATR_GND_CTRL = 1.0;
    Averynicefile_B.VENT_PACE_CTRL = 0.0;
    Averynicefile_B.VENT_GND_CTRL = 0.0;
    Averynicefile_B.Z_ATR_CTRL = 0.0;
    Averynicefile_B.Z_VENT_CTRL = 0.0;
    Averynicefile_B.output_atr_heartbeat = 1.0;
  }

  /* End of Constant: '<Root>/LRL' */
}

/* Function for Chart: '<Root>/Chart' */
static void Averynicefile_AAI_active(const boolean_T *DigitalRead)
{
  /* Constant: '<Root>/LRL' */
  if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
      (Averynicefile_P.LRL_Value)) {
    Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AAI_active1;
    Averynicefile_DW.temporalCounter_i1 = 0U;
    Averynicefile_B.FRONTEND_CTRL = 0.0;
    Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
    Averynicefile_B.PACE_CHARGE_CTRL = 0.0;
    Averynicefile_B.PACE_GND_CTRL = 1.0;
    Averynicefile_B.ATR_PACE_CTRL = 1.0;
    Averynicefile_B.ATR_GND_CTRL = 0.0;
    Averynicefile_B.VENT_PACE_CTRL = 0.0;
    Averynicefile_B.VENT_GND_CTRL = 0.0;
    Averynicefile_B.Z_ATR_CTRL = 0.0;
    Averynicefile_B.Z_VENT_CTRL = 0.0;
  } else {
    if (*DigitalRead) {
      Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AAI_Hysterisis;
      Averynicefile_DW.temporalCounter_i1 = 0U;
      Ave_enter_atomic_AAI_Hysterisis();
    }
  }

  /* End of Constant: '<Root>/LRL' */
}

/* Function for Chart: '<Root>/Chart' */
static void Averyni_enter_atomic_AAI_active(void)
{
  Averynicefile_B.FRONTEND_CTRL = 1.0;
  Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
  Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
  Averynicefile_B.PACING_REF_PWM = 50.0;
  Averynicefile_B.PACE_GND_CTRL = 1.0;
  Averynicefile_B.ATR_PACE_CTRL = 0.0;
  Averynicefile_B.ATR_GND_CTRL = 1.0;
  Averynicefile_B.VENT_PACE_CTRL = 0.0;
  Averynicefile_B.VENT_GND_CTRL = 0.0;
  Averynicefile_B.Z_ATR_CTRL = 0.0;
  Averynicefile_B.Z_VENT_CTRL = 0.0;
  Averynicefile_B.output_atr_heartbeat = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Averyni_enter_atomic_AOO_active(void)
{
  Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
  Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
  Averynicefile_B.PACING_REF_PWM = 50.0;
  Averynicefile_B.PACE_GND_CTRL = 1.0;
  Averynicefile_B.ATR_PACE_CTRL = 0.0;
  Averynicefile_B.ATR_GND_CTRL = 1.0;
  Averynicefile_B.VENT_PACE_CTRL = 0.0;
  Averynicefile_B.VENT_GND_CTRL = 0.0;
  Averynicefile_B.Z_ATR_CTRL = 0.0;
  Averynicefile_B.Z_VENT_CTRL = 0.0;
  Averynicefile_B.output_atr_heartbeat = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Averyn_enter_atomic_VVI_active1(void)
{
  Averynicefile_B.FRONTEND_CTRL = 1.0;
  Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
  Averynicefile_B.PACING_REF_PWM = 30.0;
  Averynicefile_B.PACE_CHARGE_CTRL = 0.0;
  Averynicefile_B.PACE_GND_CTRL = 1.0;
  Averynicefile_B.VENT_PACE_CTRL = 1.0;
  Averynicefile_B.ATR_PACE_CTRL = 0.0;
  Averynicefile_B.ATR_GND_CTRL = 0.0;
  Averynicefile_B.Z_ATR_CTRL = 0.0;
  Averynicefile_B.Z_VENT_CTRL = 0.0;
  Averynicefile_B.VENT_GND_CTRL = 0.0;
}

static void SystemCore_relea_gmmp4fpqp1jlwp(const
  freedomk64f_DigitalRead_Avery_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void SystemCore_delet_gmmp4fpqp1jlwp(const
  freedomk64f_DigitalRead_Avery_T *obj)
{
  SystemCore_relea_gmmp4fpqp1jlwp(obj);
}

static void matlabCodegenHan_gmmp4fpqp1jlwp(freedomk64f_DigitalRead_Avery_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delet_gmmp4fpqp1jlwp(obj);
  }
}

static void Averynicefil_SystemCore_release(const
  freedomk64f_DigitalWrite_Aver_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Averynicefile_SystemCore_delete(const
  freedomk64f_DigitalWrite_Aver_T *obj)
{
  Averynicefil_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_Aver_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Averynicefile_SystemCore_delete(obj);
  }
}

static void Averyni_SystemCore_release_gmmp(const
  freedomk64f_PWMOutput_Averyni_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void Averynic_SystemCore_delete_gmmp(const
  freedomk64f_PWMOutput_Averyni_T *obj)
{
  Averyni_SystemCore_release_gmmp(obj);
}

static void matlabCodegenHandle_matlab_gmmp(freedomk64f_PWMOutput_Averyni_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Averynic_SystemCore_delete_gmmp(obj);
  }
}

/* Model step function */
void Averynicefile_step(void)
{
  boolean_T tmp;
  boolean_T DigitalRead;

  /* MATLABSystem: '<Root>/Digital Read' */
  if (Averynicefile_DW.obj.SampleTime != Averynicefile_P.DigitalRead_SampleTime)
  {
    Averynicefile_DW.obj.SampleTime = Averynicefile_P.DigitalRead_SampleTime;
  }

  DigitalRead = MW_digitalIO_read(Averynicefile_DW.obj.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<Root>/Digital Read' */

  /* MATLABSystem: '<Root>/Digital Read1' */
  if (Averynicefile_DW.obj_m.SampleTime !=
      Averynicefile_P.DigitalRead1_SampleTime) {
    Averynicefile_DW.obj_m.SampleTime = Averynicefile_P.DigitalRead1_SampleTime;
  }

  tmp = MW_digitalIO_read(Averynicefile_DW.obj_m.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/LRL'
   *  Constant: '<Root>/atr_PW'
   *  Constant: '<Root>/hysteresis'
   *  Constant: '<Root>/state_determine'
   *  Constant: '<Root>/vent_PW'
   *  MATLABSystem: '<Root>/Digital Read1'
   */
  if (Averynicefile_DW.temporalCounter_i1 < MAX_uint32_T) {
    Averynicefile_DW.temporalCounter_i1++;
  }

  if (Averynicefile_DW.is_active_c3_Averynicefile == 0U) {
    Averynicefile_DW.is_active_c3_Averynicefile = 1U;
    Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_IDLE;
    Averynicefile_B.output_vent_heartbeat = 0.0;
    Averynicefile_B.output_atr_heartbeat = 0.0;
  } else {
    switch (Averynicefile_DW.is_c3_Averynicefile) {
     case Averynicefile_IN_AAI_Hysterisis:
      Averynicefile_AAI_Hysterisis(&DigitalRead);
      break;

     case Averynicefile_IN_AAI_active:
      Averynicefile_AAI_active(&DigitalRead);
      break;

     case Averynicefile_IN_AAI_active1:
      if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Averynicefile_P.atr_PW_Value)) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AAI_active;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyni_enter_atomic_AAI_active();
      }
      break;

     case Averynicefile_IN_AOO_active:
      if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Averynicefile_P.LRL_Value)) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AOO_active1;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 0.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 1.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.VENT_PACE_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
      } else {
        Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
        Averynicefile_B.PACING_REF_PWM = 50.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 1.0;
        Averynicefile_B.VENT_PACE_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.output_atr_heartbeat = 0.0;
      }
      break;

     case Averynicefile_IN_AOO_active1:
      if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Averynicefile_P.atr_PW_Value)) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AOO_active;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyni_enter_atomic_AOO_active();
      } else {
        Averynicefile_B.ATR_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 0.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 1.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.VENT_PACE_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
      }
      break;

     case Averynicefile_IN_IDLE:
      if (Averynicefile_P.state_determine_Value == 1.0) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VOO_active;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACING_REF_PWM = 30.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 1.0;
        Averynicefile_B.VENT_PACE_CTRL = 0.0;
      } else if (Averynicefile_P.state_determine_Value == 3.0) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VVI_active;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyni_enter_atomic_VVI_active();
      } else if (Averynicefile_P.state_determine_Value == 2.0) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AAI_active;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyni_enter_atomic_AAI_active();
      } else if (Averynicefile_P.state_determine_Value == 0.0) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_AOO_active;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyni_enter_atomic_AOO_active();
      } else {
        Averynicefile_B.output_vent_heartbeat = 0.0;
        Averynicefile_B.output_atr_heartbeat = 0.0;
      }
      break;

     case Averynicefile_IN_VOO_active:
      if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Averynicefile_P.LRL_Value)) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VOO_active1;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACING_REF_PWM = 30.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 0.0;
        Averynicefile_B.VENT_PACE_CTRL = 1.0;
      } else {
        Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACING_REF_PWM = 30.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 1.0;
        Averynicefile_B.VENT_PACE_CTRL = 0.0;
      }
      break;

     case Averynicefile_IN_VOO_active1:
      if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Averynicefile_P.vent_PW_Value)) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VOO_active;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACING_REF_PWM = 30.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 1.0;
        Averynicefile_B.VENT_PACE_CTRL = 0.0;
      } else {
        Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACING_REF_PWM = 30.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 0.0;
        Averynicefile_B.VENT_PACE_CTRL = 1.0;
      }
      break;

     case Averynicefile_IN_VVI_Hysteresis:
      if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Averynicefile_P.LRL_Value + Averynicefile_P.hysteresis_Value)) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VVI_active1;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyn_enter_atomic_VVI_active1();
      } else if (tmp) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VVI_Hysteresis;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyni_enter_atomic_VVI_active();
      } else {
        Averynicefile_B.FRONTEND_CTRL = 1.0;
        Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACING_REF_PWM = 30.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 1.0;
        Averynicefile_B.VENT_PACE_CTRL = 0.0;
      }
      break;

     case Averynicefile_IN_VVI_active:
      if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Averynicefile_P.LRL_Value)) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VVI_active1;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyn_enter_atomic_VVI_active1();
      } else if (tmp) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VVI_Hysteresis;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyni_enter_atomic_VVI_active();
      } else {
        Averynicefile_B.FRONTEND_CTRL = 1.0;
        Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACING_REF_PWM = 30.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 1.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 1.0;
        Averynicefile_B.VENT_PACE_CTRL = 0.0;
      }
      break;

     default:
      /* case IN_VVI_active1: */
      if (Averynicefile_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Averynicefile_P.vent_PW_Value)) {
        Averynicefile_DW.is_c3_Averynicefile = Averynicefile_IN_VVI_active;
        Averynicefile_DW.temporalCounter_i1 = 0U;
        Averyni_enter_atomic_VVI_active();
      } else {
        Averynicefile_B.FRONTEND_CTRL = 1.0;
        Averynicefile_B.VENT_CMP_REF_PWM = 90.0;
        Averynicefile_B.PACING_REF_PWM = 30.0;
        Averynicefile_B.PACE_CHARGE_CTRL = 0.0;
        Averynicefile_B.PACE_GND_CTRL = 1.0;
        Averynicefile_B.VENT_PACE_CTRL = 1.0;
        Averynicefile_B.ATR_PACE_CTRL = 0.0;
        Averynicefile_B.ATR_GND_CTRL = 0.0;
        Averynicefile_B.Z_ATR_CTRL = 0.0;
        Averynicefile_B.Z_VENT_CTRL = 0.0;
        Averynicefile_B.VENT_GND_CTRL = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/ATR_GND_CTRL' */
  MW_digitalIO_write(Averynicefile_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/ATR_PACE_CTRL' */
  MW_digitalIO_write(Averynicefile_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(Averynicefile_DW.obj_hy.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.output_atr_heartbeat != 0.0);

  /* MATLABSystem: '<Root>/Digital Write1' */
  MW_digitalIO_write(Averynicefile_DW.obj_k.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.output_vent_heartbeat != 0.0);

  /* MATLABSystem: '<Root>/Digital Write2' */
  MW_digitalIO_write(Averynicefile_DW.obj_d.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/PACE_CHARGE_CTRL' */
  MW_digitalIO_write(Averynicefile_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/PACE_GND_CTRL' */
  MW_digitalIO_write(Averynicefile_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/PWM Output' */
  MW_PWM_SetDutyCycle(Averynicefile_DW.obj_a.MW_PWM_HANDLE,
                      Averynicefile_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output1' */
  MW_PWM_SetDutyCycle(Averynicefile_DW.obj_jn.MW_PWM_HANDLE,
                      Averynicefile_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<Root>/PWM Output2' */
  MW_PWM_SetDutyCycle(Averynicefile_DW.obj_bg.MW_PWM_HANDLE,
                      Averynicefile_B.PACING_REF_PWM);

  /* MATLABSystem: '<Root>/VENT_GND_CTRL' */
  MW_digitalIO_write(Averynicefile_DW.obj_g.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<Root>/VENT_PACE_CTRL' */
  MW_digitalIO_write(Averynicefile_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Z_ATR_CTRL' */
  MW_digitalIO_write(Averynicefile_DW.obj_o.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<Root>/Z_VENT_CTRL' */
  MW_digitalIO_write(Averynicefile_DW.obj_hb.MW_DIGITALIO_HANDLE,
                     Averynicefile_B.Z_VENT_CTRL != 0.0);
}

/* Model initialize function */
void Averynicefile_initialize(void)
{
  {
    freedomk64f_DigitalRead_Avery_T *obj;
    freedomk64f_DigitalWrite_Aver_T *obj_0;
    freedomk64f_PWMOutput_Averyni_T *obj_1;

    /* Start for MATLABSystem: '<Root>/Digital Read' */
    Averynicefile_DW.obj.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj.isInitialized = 0;
    Averynicefile_DW.obj.SampleTime = -1.0;
    Averynicefile_DW.obj.matlabCodegenIsDeleted = false;
    Averynicefile_DW.obj.SampleTime = Averynicefile_P.DigitalRead_SampleTime;
    obj = &Averynicefile_DW.obj;
    Averynicefile_DW.obj.isSetupComplete = false;
    Averynicefile_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Averynicefile_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Read1' */
    Averynicefile_DW.obj_m.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_m.isInitialized = 0;
    Averynicefile_DW.obj_m.SampleTime = -1.0;
    Averynicefile_DW.obj_m.matlabCodegenIsDeleted = false;
    Averynicefile_DW.obj_m.SampleTime = Averynicefile_P.DigitalRead1_SampleTime;
    obj = &Averynicefile_DW.obj_m;
    Averynicefile_DW.obj_m.isSetupComplete = false;
    Averynicefile_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Averynicefile_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/ATR_GND_CTRL' */
    Averynicefile_DW.obj_h.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_h.isInitialized = 0;
    Averynicefile_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_h;
    Averynicefile_DW.obj_h.isSetupComplete = false;
    Averynicefile_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Averynicefile_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/ATR_PACE_CTRL' */
    Averynicefile_DW.obj_e.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_e.isInitialized = 0;
    Averynicefile_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_e;
    Averynicefile_DW.obj_e.isSetupComplete = false;
    Averynicefile_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Averynicefile_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    Averynicefile_DW.obj_hy.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_hy.isInitialized = 0;
    Averynicefile_DW.obj_hy.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_hy;
    Averynicefile_DW.obj_hy.isSetupComplete = false;
    Averynicefile_DW.obj_hy.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Averynicefile_DW.obj_hy.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write1' */
    Averynicefile_DW.obj_k.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_k.isInitialized = 0;
    Averynicefile_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_k;
    Averynicefile_DW.obj_k.isSetupComplete = false;
    Averynicefile_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Averynicefile_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write2' */
    Averynicefile_DW.obj_d.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_d.isInitialized = 0;
    Averynicefile_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_d;
    Averynicefile_DW.obj_d.isSetupComplete = false;
    Averynicefile_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Averynicefile_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PACE_CHARGE_CTRL' */
    Averynicefile_DW.obj_j.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_j.isInitialized = 0;
    Averynicefile_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_j;
    Averynicefile_DW.obj_j.isSetupComplete = false;
    Averynicefile_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Averynicefile_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PACE_GND_CTRL' */
    Averynicefile_DW.obj_b.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_b.isInitialized = 0;
    Averynicefile_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_b;
    Averynicefile_DW.obj_b.isSetupComplete = false;
    Averynicefile_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Averynicefile_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output' */
    Averynicefile_DW.obj_a.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_a.isInitialized = 0;
    Averynicefile_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_1 = &Averynicefile_DW.obj_a;
    Averynicefile_DW.obj_a.isSetupComplete = false;
    Averynicefile_DW.obj_a.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Averynicefile_DW.obj_a.MW_PWM_HANDLE);
    Averynicefile_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output1' */
    Averynicefile_DW.obj_jn.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_jn.isInitialized = 0;
    Averynicefile_DW.obj_jn.matlabCodegenIsDeleted = false;
    obj_1 = &Averynicefile_DW.obj_jn;
    Averynicefile_DW.obj_jn.isSetupComplete = false;
    Averynicefile_DW.obj_jn.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Averynicefile_DW.obj_jn.MW_PWM_HANDLE);
    Averynicefile_DW.obj_jn.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM Output2' */
    Averynicefile_DW.obj_bg.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_bg.isInitialized = 0;
    Averynicefile_DW.obj_bg.matlabCodegenIsDeleted = false;
    obj_1 = &Averynicefile_DW.obj_bg;
    Averynicefile_DW.obj_bg.isSetupComplete = false;
    Averynicefile_DW.obj_bg.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Averynicefile_DW.obj_bg.MW_PWM_HANDLE);
    Averynicefile_DW.obj_bg.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/VENT_GND_CTRL' */
    Averynicefile_DW.obj_g.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_g.isInitialized = 0;
    Averynicefile_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_g;
    Averynicefile_DW.obj_g.isSetupComplete = false;
    Averynicefile_DW.obj_g.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Averynicefile_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/VENT_PACE_CTRL' */
    Averynicefile_DW.obj_n.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_n.isInitialized = 0;
    Averynicefile_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_n;
    Averynicefile_DW.obj_n.isSetupComplete = false;
    Averynicefile_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Averynicefile_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Z_ATR_CTRL' */
    Averynicefile_DW.obj_o.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_o.isInitialized = 0;
    Averynicefile_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_o;
    Averynicefile_DW.obj_o.isSetupComplete = false;
    Averynicefile_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Averynicefile_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Z_VENT_CTRL' */
    Averynicefile_DW.obj_hb.matlabCodegenIsDeleted = true;
    Averynicefile_DW.obj_hb.isInitialized = 0;
    Averynicefile_DW.obj_hb.matlabCodegenIsDeleted = false;
    obj_0 = &Averynicefile_DW.obj_hb;
    Averynicefile_DW.obj_hb.isSetupComplete = false;
    Averynicefile_DW.obj_hb.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Averynicefile_DW.obj_hb.isSetupComplete = true;
  }
}

/* Model terminate function */
void Averynicefile_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Digital Read' */
  matlabCodegenHan_gmmp4fpqp1jlwp(&Averynicefile_DW.obj);

  /* Terminate for MATLABSystem: '<Root>/Digital Read1' */
  matlabCodegenHan_gmmp4fpqp1jlwp(&Averynicefile_DW.obj_m);

  /* Terminate for MATLABSystem: '<Root>/ATR_GND_CTRL' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_h);

  /* Terminate for MATLABSystem: '<Root>/ATR_PACE_CTRL' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_e);

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_hy);

  /* Terminate for MATLABSystem: '<Root>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_k);

  /* Terminate for MATLABSystem: '<Root>/Digital Write2' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_d);

  /* Terminate for MATLABSystem: '<Root>/PACE_CHARGE_CTRL' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_j);

  /* Terminate for MATLABSystem: '<Root>/PACE_GND_CTRL' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_b);

  /* Terminate for MATLABSystem: '<Root>/PWM Output' */
  matlabCodegenHandle_matlab_gmmp(&Averynicefile_DW.obj_a);

  /* Terminate for MATLABSystem: '<Root>/PWM Output1' */
  matlabCodegenHandle_matlab_gmmp(&Averynicefile_DW.obj_jn);

  /* Terminate for MATLABSystem: '<Root>/PWM Output2' */
  matlabCodegenHandle_matlab_gmmp(&Averynicefile_DW.obj_bg);

  /* Terminate for MATLABSystem: '<Root>/VENT_GND_CTRL' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_g);

  /* Terminate for MATLABSystem: '<Root>/VENT_PACE_CTRL' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/Z_ATR_CTRL' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_o);

  /* Terminate for MATLABSystem: '<Root>/Z_VENT_CTRL' */
  matlabCodegenHandle_matlabCodeg(&Averynicefile_DW.obj_hb);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
