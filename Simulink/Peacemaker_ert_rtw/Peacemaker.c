/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Peacemaker.c
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

#include "Peacemaker.h"
#include "Peacemaker_private.h"

/* Named constants for Chart: '<Root>/Main' */
#define Peacemaker_IN_AAI              ((uint8_T)1U)
#define Peacemaker_IN_AAI_CHARGE       ((uint8_T)1U)
#define Peacemaker_IN_AAI_PACE         ((uint8_T)2U)
#define Peacemaker_IN_AOO              ((uint8_T)2U)
#define Peacemaker_IN_AOO_CHARGE       ((uint8_T)1U)
#define Peacemaker_IN_AOO_PACE         ((uint8_T)2U)
#define Peacemaker_IN_IDLE_STATE       ((uint8_T)3U)
#define Peacemaker_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define Peacemaker_IN_VOO              ((uint8_T)4U)
#define Peacemaker_IN_VOO_CHARGE       ((uint8_T)1U)
#define Peacemaker_IN_VOO_PACE         ((uint8_T)2U)
#define Peacemaker_IN_VVI              ((uint8_T)5U)
#define Peacemaker_IN_VVI_CHARGE       ((uint8_T)1U)
#define Peacemaker_IN_VVI_PACE         ((uint8_T)2U)

/* Block signals (default storage) */
B_Peacemaker_T Peacemaker_B;

/* Block states (default storage) */
DW_Peacemaker_T Peacemaker_DW;

/* Real-time model */
RT_MODEL_Peacemaker_T Peacemaker_M_;
RT_MODEL_Peacemaker_T *const Peacemaker_M = &Peacemaker_M_;

/* Forward declaration for local functions */
static void Peacema_enter_atomic_VVI_CHARGE(void);
static void Peacema_enter_atomic_AAI_CHARGE(void);
static void Peacemaker_AAI(const real_T *Divide, const boolean_T *DigitalRead1);
static void Peacema_enter_atomic_AOO_CHARGE(void);
static void Peacema_enter_atomic_VOO_CHARGE(void);
static void Peacemaker_SystemCore_release(const freedomk64f_DigitalRead_Peace_T *
  obj);
static void Peacemaker_SystemCore_delete(const freedomk64f_DigitalRead_Peace_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalRead_Peace_T *obj);
static void Peacemake_SystemCore_release_kw(const
  freedomk64f_DigitalWrite_Peac_T *obj);
static void Peacemaker_SystemCore_delete_kw(const
  freedomk64f_DigitalWrite_Peac_T *obj);
static void matlabCodegenHandle_matlabCo_kw(freedomk64f_DigitalWrite_Peac_T *obj);
static void Peacema_SystemCore_release_kw0p(const
  freedomk64f_PWMOutput_Peacema_T *obj);
static void Peacemak_SystemCore_delete_kw0p(const
  freedomk64f_PWMOutput_Peacema_T *obj);
static void matlabCodegenHandle_matlab_kw0p(freedomk64f_PWMOutput_Peacema_T *obj);

/* Function for Chart: '<Root>/Main' */
static void Peacema_enter_atomic_VVI_CHARGE(void)
{
  /* Constant: '<S1>/AMPLITUDE' */
  Peacemaker_B.PACING_REF_PWM = Peacemaker_P.AMPLITUDE_Value;
  Peacemaker_B.PACE_CHARGE_CTRL = 1.0;
  Peacemaker_B.VENT_PACE_CTRL = 0.0;
  Peacemaker_B.VENT_GND_CTRL = 1.0;
  Peacemaker_B.PACE_GND_CTRL = 1.0;
  Peacemaker_B.Z_VENT_CTRL = 0.0;
  Peacemaker_B.FRONTEND_CTRL = 1.0;

  /* Constant: '<S1>/threshold' */
  Peacemaker_B.VENT_CMP_REF_PWM = Peacemaker_P.threshold_Value;
  Peacemaker_B.ATR_PACE_CTRL = 0.0;
  Peacemaker_B.ATR_GND_CTRL = 0.0;
  Peacemaker_B.Z_ATR_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Main' */
static void Peacema_enter_atomic_AAI_CHARGE(void)
{
  /* Constant: '<S1>/AMPLITUDE' */
  Peacemaker_B.PACING_REF_PWM = Peacemaker_P.AMPLITUDE_Value;
  Peacemaker_B.PACE_CHARGE_CTRL = 1.0;
  Peacemaker_B.ATR_PACE_CTRL = 0.0;
  Peacemaker_B.ATR_GND_CTRL = 1.0;
  Peacemaker_B.PACE_GND_CTRL = 1.0;
  Peacemaker_B.Z_ATR_CTRL = 0.0;
  Peacemaker_B.FRONTEND_CTRL = 1.0;

  /* Constant: '<S1>/threshold' */
  Peacemaker_B.ATR_CMP_REF_PWM = Peacemaker_P.threshold_Value;
  Peacemaker_B.VENT_PACE_CTRL = 0.0;
  Peacemaker_B.VENT_GND_CTRL = 0.0;
  Peacemaker_B.Z_VENT_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Main' */
static void Peacemaker_AAI(const real_T *Divide, const boolean_T *DigitalRead1)
{
  /* Constant: '<S1>/Mode' */
  if (Peacemaker_P.Mode_Value != 2.0) {
    Peacemaker_DW.is_AAI = Peacemaker_IN_NO_ACTIVE_CHILD;
    Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_IDLE_STATE;
  } else if (Peacemaker_DW.is_AAI == Peacemaker_IN_AAI_CHARGE) {
    Peacemaker_B.PACE_CHARGE_CTRL = 1.0;
    Peacemaker_B.ATR_PACE_CTRL = 0.0;
    Peacemaker_B.ATR_GND_CTRL = 1.0;
    Peacemaker_B.PACE_GND_CTRL = 1.0;
    Peacemaker_B.Z_ATR_CTRL = 0.0;
    Peacemaker_B.FRONTEND_CTRL = 1.0;
    Peacemaker_B.VENT_PACE_CTRL = 0.0;
    Peacemaker_B.VENT_GND_CTRL = 0.0;
    Peacemaker_B.Z_VENT_CTRL = 0.0;

    /* Constant: '<S1>/Arp' */
    if (Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
        (Peacemaker_P.Arp_Value)) {
      /* Constant: '<S1>/Pulse_Width' */
      if ((Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil((*Divide -
             Peacemaker_P.Arp_Value) - Peacemaker_P.Pulse_Width_Value)) &&
          (!*DigitalRead1)) {
        Peacemaker_DW.is_AAI = Peacemaker_IN_AAI_PACE;
        Peacemaker_DW.temporalCounter_i1 = 0U;

        /* Constant: '<S1>/AMPLITUDE' */
        Peacemaker_B.PACING_REF_PWM = Peacemaker_P.AMPLITUDE_Value;
        Peacemaker_B.PACE_CHARGE_CTRL = 0.0;
        Peacemaker_B.ATR_PACE_CTRL = 1.0;
        Peacemaker_B.ATR_GND_CTRL = 0.0;
        Peacemaker_B.PACE_GND_CTRL = 1.0;
        Peacemaker_B.Z_ATR_CTRL = 0.0;
        Peacemaker_B.FRONTEND_CTRL = 1.0;

        /* Constant: '<S1>/threshold' */
        Peacemaker_B.ATR_CMP_REF_PWM = Peacemaker_P.threshold_Value;
        Peacemaker_B.VENT_PACE_CTRL = 0.0;
        Peacemaker_B.VENT_GND_CTRL = 0.0;
        Peacemaker_B.Z_VENT_CTRL = 0.0;
      } else {
        if (*DigitalRead1) {
          Peacemaker_DW.is_AAI = Peacemaker_IN_AAI_CHARGE;
          Peacemaker_DW.temporalCounter_i1 = 0U;
          Peacema_enter_atomic_AAI_CHARGE();
        }
      }
    }

    /* End of Constant: '<S1>/Arp' */
  } else {
    /* case IN_AAI_PACE: */
    Peacemaker_B.PACE_CHARGE_CTRL = 0.0;
    Peacemaker_B.ATR_PACE_CTRL = 1.0;
    Peacemaker_B.ATR_GND_CTRL = 0.0;
    Peacemaker_B.PACE_GND_CTRL = 1.0;
    Peacemaker_B.Z_ATR_CTRL = 0.0;
    Peacemaker_B.FRONTEND_CTRL = 1.0;
    Peacemaker_B.VENT_PACE_CTRL = 0.0;
    Peacemaker_B.VENT_GND_CTRL = 0.0;
    Peacemaker_B.Z_VENT_CTRL = 0.0;

    /* Constant: '<S1>/Pulse_Width' */
    if (Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
        (Peacemaker_P.Pulse_Width_Value)) {
      Peacemaker_DW.is_AAI = Peacemaker_IN_AAI_CHARGE;
      Peacemaker_DW.temporalCounter_i1 = 0U;
      Peacema_enter_atomic_AAI_CHARGE();
    }
  }

  /* End of Constant: '<S1>/Mode' */
}

/* Function for Chart: '<Root>/Main' */
static void Peacema_enter_atomic_AOO_CHARGE(void)
{
  /* Constant: '<S1>/AMPLITUDE' */
  Peacemaker_B.PACING_REF_PWM = Peacemaker_P.AMPLITUDE_Value;
  Peacemaker_B.PACE_CHARGE_CTRL = 1.0;
  Peacemaker_B.ATR_PACE_CTRL = 0.0;
  Peacemaker_B.ATR_GND_CTRL = 1.0;
  Peacemaker_B.PACE_GND_CTRL = 1.0;
  Peacemaker_B.Z_ATR_CTRL = 0.0;
  Peacemaker_B.VENT_PACE_CTRL = 0.0;
  Peacemaker_B.VENT_GND_CTRL = 0.0;
  Peacemaker_B.Z_VENT_CTRL = 0.0;
  Peacemaker_B.BLUE_LED = 0.0;
  Peacemaker_B.RED_LED = 1.0;
}

/* Function for Chart: '<Root>/Main' */
static void Peacema_enter_atomic_VOO_CHARGE(void)
{
  /* Constant: '<S1>/AMPLITUDE' */
  Peacemaker_B.PACING_REF_PWM = Peacemaker_P.AMPLITUDE_Value;
  Peacemaker_B.PACE_CHARGE_CTRL = 1.0;
  Peacemaker_B.VENT_PACE_CTRL = 0.0;
  Peacemaker_B.VENT_GND_CTRL = 1.0;
  Peacemaker_B.PACE_GND_CTRL = 1.0;
  Peacemaker_B.Z_VENT_CTRL = 0.0;
  Peacemaker_B.ATR_PACE_CTRL = 0.0;
  Peacemaker_B.ATR_GND_CTRL = 0.0;
  Peacemaker_B.Z_ATR_CTRL = 0.0;
  Peacemaker_B.BLUE_LED = 0.0;
  Peacemaker_B.RED_LED = 1.0;
}

static void Peacemaker_SystemCore_release(const freedomk64f_DigitalRead_Peace_T *
  obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Peacemaker_SystemCore_delete(const freedomk64f_DigitalRead_Peace_T
  *obj)
{
  Peacemaker_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalRead_Peace_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Peacemaker_SystemCore_delete(obj);
  }
}

static void Peacemake_SystemCore_release_kw(const
  freedomk64f_DigitalWrite_Peac_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Peacemaker_SystemCore_delete_kw(const
  freedomk64f_DigitalWrite_Peac_T *obj)
{
  Peacemake_SystemCore_release_kw(obj);
}

static void matlabCodegenHandle_matlabCo_kw(freedomk64f_DigitalWrite_Peac_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Peacemaker_SystemCore_delete_kw(obj);
  }
}

static void Peacema_SystemCore_release_kw0p(const
  freedomk64f_PWMOutput_Peacema_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void Peacemak_SystemCore_delete_kw0p(const
  freedomk64f_PWMOutput_Peacema_T *obj)
{
  Peacema_SystemCore_release_kw0p(obj);
}

static void matlabCodegenHandle_matlab_kw0p(freedomk64f_PWMOutput_Peacema_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Peacemak_SystemCore_delete_kw0p(obj);
  }
}

/* Model step function */
void Peacemaker_step(void)
{
  boolean_T tmp;
  real_T Divide;
  boolean_T DigitalRead1;

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/BPM'
   *  Constant: '<S1>/msec'
   */
  Divide = Peacemaker_P.msec_Value / Peacemaker_P.BPM_Value;

  /* MATLABSystem: '<S1>/Digital Read' */
  if (Peacemaker_DW.obj.SampleTime != Peacemaker_P.DigitalRead_SampleTime) {
    Peacemaker_DW.obj.SampleTime = Peacemaker_P.DigitalRead_SampleTime;
  }

  tmp = MW_digitalIO_read(Peacemaker_DW.obj.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S1>/Digital Read1' */
  if (Peacemaker_DW.obj_k.SampleTime != Peacemaker_P.DigitalRead1_SampleTime) {
    Peacemaker_DW.obj_k.SampleTime = Peacemaker_P.DigitalRead1_SampleTime;
  }

  DigitalRead1 = MW_digitalIO_read(Peacemaker_DW.obj_k.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/Digital Read1' */

  /* Chart: '<Root>/Main' incorporates:
   *  Constant: '<S1>/AMPLITUDE'
   *  Constant: '<S1>/Mode'
   *  Constant: '<S1>/Pulse_Width'
   *  Constant: '<S1>/Vrp'
   *  Constant: '<S1>/threshold'
   *  MATLABSystem: '<S1>/Digital Read'
   */
  if (Peacemaker_DW.temporalCounter_i1 < MAX_uint32_T) {
    Peacemaker_DW.temporalCounter_i1++;
  }

  if (Peacemaker_DW.is_active_c3_Peacemaker == 0U) {
    Peacemaker_DW.is_active_c3_Peacemaker = 1U;
    Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_IDLE_STATE;
  } else {
    switch (Peacemaker_DW.is_c3_Peacemaker) {
     case Peacemaker_IN_AAI:
      Peacemaker_AAI(&Divide, &DigitalRead1);
      break;

     case Peacemaker_IN_AOO:
      if (Peacemaker_P.Mode_Value != 0.0) {
        Peacemaker_DW.is_AOO = Peacemaker_IN_NO_ACTIVE_CHILD;
        Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_IDLE_STATE;
      } else if (Peacemaker_DW.is_AOO == Peacemaker_IN_AOO_CHARGE) {
        Peacemaker_B.PACE_CHARGE_CTRL = 1.0;
        Peacemaker_B.ATR_PACE_CTRL = 0.0;
        Peacemaker_B.ATR_GND_CTRL = 1.0;
        Peacemaker_B.PACE_GND_CTRL = 1.0;
        Peacemaker_B.Z_ATR_CTRL = 0.0;
        Peacemaker_B.VENT_PACE_CTRL = 0.0;
        Peacemaker_B.VENT_GND_CTRL = 0.0;
        Peacemaker_B.Z_VENT_CTRL = 0.0;
        Peacemaker_B.BLUE_LED = 0.0;
        Peacemaker_B.RED_LED = 1.0;
        if (Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(Divide -
             Peacemaker_P.Pulse_Width_Value)) {
          Peacemaker_DW.is_AOO = Peacemaker_IN_AOO_PACE;
          Peacemaker_DW.temporalCounter_i1 = 0U;
          Peacemaker_B.PACING_REF_PWM = Peacemaker_P.AMPLITUDE_Value;
          Peacemaker_B.PACE_CHARGE_CTRL = 0.0;
          Peacemaker_B.ATR_PACE_CTRL = 1.0;
          Peacemaker_B.ATR_GND_CTRL = 0.0;
          Peacemaker_B.PACE_GND_CTRL = 1.0;
          Peacemaker_B.Z_ATR_CTRL = 0.0;
          Peacemaker_B.VENT_PACE_CTRL = 0.0;
          Peacemaker_B.VENT_GND_CTRL = 0.0;
          Peacemaker_B.Z_VENT_CTRL = 0.0;
          Peacemaker_B.BLUE_LED = 1.0;
          Peacemaker_B.RED_LED = 0.0;
        }
      } else {
        /* case IN_AOO_PACE: */
        Peacemaker_B.PACE_CHARGE_CTRL = 0.0;
        Peacemaker_B.ATR_PACE_CTRL = 1.0;
        Peacemaker_B.ATR_GND_CTRL = 0.0;
        Peacemaker_B.PACE_GND_CTRL = 1.0;
        Peacemaker_B.Z_ATR_CTRL = 0.0;
        Peacemaker_B.VENT_PACE_CTRL = 0.0;
        Peacemaker_B.VENT_GND_CTRL = 0.0;
        Peacemaker_B.Z_VENT_CTRL = 0.0;
        Peacemaker_B.BLUE_LED = 1.0;
        Peacemaker_B.RED_LED = 0.0;
        if (Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
            (Peacemaker_P.Pulse_Width_Value)) {
          Peacemaker_DW.is_AOO = Peacemaker_IN_AOO_CHARGE;
          Peacemaker_DW.temporalCounter_i1 = 0U;
          Peacema_enter_atomic_AOO_CHARGE();
        }
      }
      break;

     case Peacemaker_IN_IDLE_STATE:
      if (Peacemaker_P.Mode_Value == 0.0) {
        Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_AOO;
        Peacemaker_DW.is_AOO = Peacemaker_IN_AOO_CHARGE;
        Peacemaker_DW.temporalCounter_i1 = 0U;
        Peacema_enter_atomic_AOO_CHARGE();
      } else if (Peacemaker_P.Mode_Value == 1.0) {
        Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_VOO;
        Peacemaker_DW.is_VOO = Peacemaker_IN_VOO_CHARGE;
        Peacemaker_DW.temporalCounter_i1 = 0U;
        Peacema_enter_atomic_VOO_CHARGE();
      } else if (Peacemaker_P.Mode_Value == 2.0) {
        Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_AAI;
        Peacemaker_DW.is_AAI = Peacemaker_IN_AAI_CHARGE;
        Peacemaker_DW.temporalCounter_i1 = 0U;
        Peacema_enter_atomic_AAI_CHARGE();
      } else {
        if (Peacemaker_P.Mode_Value == 3.0) {
          Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_VVI;
          Peacemaker_DW.is_VVI = Peacemaker_IN_VVI_CHARGE;
          Peacemaker_DW.temporalCounter_i1 = 0U;
          Peacema_enter_atomic_VVI_CHARGE();
        }
      }
      break;

     case Peacemaker_IN_VOO:
      if (Peacemaker_P.Mode_Value != 1.0) {
        Peacemaker_DW.is_VOO = Peacemaker_IN_NO_ACTIVE_CHILD;
        Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_IDLE_STATE;
      } else if (Peacemaker_DW.is_VOO == Peacemaker_IN_VOO_CHARGE) {
        Peacemaker_B.PACE_CHARGE_CTRL = 1.0;
        Peacemaker_B.VENT_PACE_CTRL = 0.0;
        Peacemaker_B.VENT_GND_CTRL = 1.0;
        Peacemaker_B.PACE_GND_CTRL = 1.0;
        Peacemaker_B.Z_VENT_CTRL = 0.0;
        Peacemaker_B.ATR_PACE_CTRL = 0.0;
        Peacemaker_B.ATR_GND_CTRL = 0.0;
        Peacemaker_B.Z_ATR_CTRL = 0.0;
        Peacemaker_B.BLUE_LED = 0.0;
        Peacemaker_B.RED_LED = 1.0;
        if (Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil(Divide -
             Peacemaker_P.Pulse_Width_Value)) {
          Peacemaker_DW.is_VOO = Peacemaker_IN_VOO_PACE;
          Peacemaker_DW.temporalCounter_i1 = 0U;
          Peacemaker_B.PACING_REF_PWM = Peacemaker_P.AMPLITUDE_Value;
          Peacemaker_B.PACE_CHARGE_CTRL = 0.0;
          Peacemaker_B.VENT_PACE_CTRL = 1.0;
          Peacemaker_B.VENT_GND_CTRL = 0.0;
          Peacemaker_B.PACE_GND_CTRL = 1.0;
          Peacemaker_B.Z_VENT_CTRL = 0.0;
          Peacemaker_B.ATR_PACE_CTRL = 0.0;
          Peacemaker_B.ATR_GND_CTRL = 0.0;
          Peacemaker_B.Z_ATR_CTRL = 0.0;
          Peacemaker_B.BLUE_LED = 1.0;
          Peacemaker_B.RED_LED = 0.0;
        }
      } else {
        /* case IN_VOO_PACE: */
        Peacemaker_B.PACE_CHARGE_CTRL = 0.0;
        Peacemaker_B.VENT_PACE_CTRL = 1.0;
        Peacemaker_B.VENT_GND_CTRL = 0.0;
        Peacemaker_B.PACE_GND_CTRL = 1.0;
        Peacemaker_B.Z_VENT_CTRL = 0.0;
        Peacemaker_B.ATR_PACE_CTRL = 0.0;
        Peacemaker_B.ATR_GND_CTRL = 0.0;
        Peacemaker_B.Z_ATR_CTRL = 0.0;
        Peacemaker_B.BLUE_LED = 1.0;
        Peacemaker_B.RED_LED = 0.0;
        if (Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
            (Peacemaker_P.Pulse_Width_Value)) {
          Peacemaker_DW.is_VOO = Peacemaker_IN_VOO_CHARGE;
          Peacemaker_DW.temporalCounter_i1 = 0U;
          Peacema_enter_atomic_VOO_CHARGE();
        }
      }
      break;

     default:
      /* case IN_VVI: */
      if (Peacemaker_P.Mode_Value != 3.0) {
        Peacemaker_DW.is_VVI = Peacemaker_IN_NO_ACTIVE_CHILD;
        Peacemaker_DW.is_c3_Peacemaker = Peacemaker_IN_IDLE_STATE;
      } else if (Peacemaker_DW.is_VVI == Peacemaker_IN_VVI_CHARGE) {
        Peacemaker_B.PACE_CHARGE_CTRL = 1.0;
        Peacemaker_B.VENT_PACE_CTRL = 0.0;
        Peacemaker_B.VENT_GND_CTRL = 1.0;
        Peacemaker_B.PACE_GND_CTRL = 1.0;
        Peacemaker_B.Z_VENT_CTRL = 0.0;
        Peacemaker_B.FRONTEND_CTRL = 1.0;
        Peacemaker_B.ATR_PACE_CTRL = 0.0;
        Peacemaker_B.ATR_GND_CTRL = 0.0;
        Peacemaker_B.Z_ATR_CTRL = 0.0;
        if (Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
            (Peacemaker_P.Vrp_Value)) {
          if ((Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil((Divide -
                 Peacemaker_P.Vrp_Value) - Peacemaker_P.Pulse_Width_Value)) && (
               !tmp)) {
            Peacemaker_DW.is_VVI = Peacemaker_IN_VVI_PACE;
            Peacemaker_DW.temporalCounter_i1 = 0U;
            Peacemaker_B.PACING_REF_PWM = Peacemaker_P.AMPLITUDE_Value;
            Peacemaker_B.PACE_CHARGE_CTRL = 0.0;
            Peacemaker_B.VENT_PACE_CTRL = 1.0;
            Peacemaker_B.VENT_GND_CTRL = 0.0;
            Peacemaker_B.PACE_GND_CTRL = 1.0;
            Peacemaker_B.Z_VENT_CTRL = 0.0;
            Peacemaker_B.FRONTEND_CTRL = 1.0;
            Peacemaker_B.VENT_CMP_REF_PWM = Peacemaker_P.threshold_Value;
            Peacemaker_B.ATR_PACE_CTRL = 0.0;
            Peacemaker_B.ATR_GND_CTRL = 0.0;
            Peacemaker_B.Z_ATR_CTRL = 0.0;
          } else {
            if (tmp) {
              Peacemaker_DW.is_VVI = Peacemaker_IN_VVI_CHARGE;
              Peacemaker_DW.temporalCounter_i1 = 0U;
              Peacema_enter_atomic_VVI_CHARGE();
            }
          }
        }
      } else {
        /* case IN_VVI_PACE: */
        Peacemaker_B.PACE_CHARGE_CTRL = 0.0;
        Peacemaker_B.VENT_PACE_CTRL = 1.0;
        Peacemaker_B.VENT_GND_CTRL = 0.0;
        Peacemaker_B.PACE_GND_CTRL = 1.0;
        Peacemaker_B.Z_VENT_CTRL = 0.0;
        Peacemaker_B.FRONTEND_CTRL = 1.0;
        Peacemaker_B.ATR_PACE_CTRL = 0.0;
        Peacemaker_B.ATR_GND_CTRL = 0.0;
        Peacemaker_B.Z_ATR_CTRL = 0.0;
        if (Peacemaker_DW.temporalCounter_i1 >= (uint32_T)ceil
            (Peacemaker_P.Pulse_Width_Value)) {
          Peacemaker_DW.is_VVI = Peacemaker_IN_VVI_CHARGE;
          Peacemaker_DW.temporalCounter_i1 = 0U;
          Peacema_enter_atomic_VVI_CHARGE();
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Main' */

  /* MATLABSystem: '<S3>/Digital Write' */
  MW_digitalIO_write(Peacemaker_DW.obj_j.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write1' */
  MW_digitalIO_write(Peacemaker_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write2' */
  MW_digitalIO_write(Peacemaker_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write3' */
  MW_digitalIO_write(Peacemaker_DW.obj_jy.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output' */
  MW_PWM_SetDutyCycle(Peacemaker_DW.obj_p.MW_PWM_HANDLE,
                      Peacemaker_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write4' */
  MW_digitalIO_write(Peacemaker_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write5' */
  MW_digitalIO_write(Peacemaker_DW.obj_nc.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write6' */
  MW_digitalIO_write(Peacemaker_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write7' */
  MW_digitalIO_write(Peacemaker_DW.obj_j1.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write8' */
  MW_digitalIO_write(Peacemaker_DW.obj_f.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output1' */
  MW_PWM_SetDutyCycle(Peacemaker_DW.obj_m.MW_PWM_HANDLE,
                      Peacemaker_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/PWM Output2' */
  MW_PWM_SetDutyCycle(Peacemaker_DW.obj_km.MW_PWM_HANDLE,
                      Peacemaker_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write9' */
  MW_digitalIO_write(Peacemaker_DW.obj_nf.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.BLUE_LED != 0.0);

  /* MATLABSystem: '<S3>/Digital Write10' */
  MW_digitalIO_write(Peacemaker_DW.obj_et.MW_DIGITALIO_HANDLE,
                     Peacemaker_B.RED_LED != 0.0);
}

/* Model initialize function */
void Peacemaker_initialize(void)
{
  {
    freedomk64f_DigitalRead_Peace_T *obj;
    freedomk64f_DigitalWrite_Peac_T *obj_0;
    freedomk64f_PWMOutput_Peacema_T *obj_1;

    /* Start for MATLABSystem: '<S1>/Digital Read' */
    Peacemaker_DW.obj.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj.isInitialized = 0;
    Peacemaker_DW.obj.SampleTime = -1.0;
    Peacemaker_DW.obj.matlabCodegenIsDeleted = false;
    Peacemaker_DW.obj.SampleTime = Peacemaker_P.DigitalRead_SampleTime;
    obj = &Peacemaker_DW.obj;
    Peacemaker_DW.obj.isSetupComplete = false;
    Peacemaker_DW.obj.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Peacemaker_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Read1' */
    Peacemaker_DW.obj_k.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_k.isInitialized = 0;
    Peacemaker_DW.obj_k.SampleTime = -1.0;
    Peacemaker_DW.obj_k.matlabCodegenIsDeleted = false;
    Peacemaker_DW.obj_k.SampleTime = Peacemaker_P.DigitalRead1_SampleTime;
    obj = &Peacemaker_DW.obj_k;
    Peacemaker_DW.obj_k.isSetupComplete = false;
    Peacemaker_DW.obj_k.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Peacemaker_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    Peacemaker_DW.obj_j.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_j.isInitialized = 0;
    Peacemaker_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_j;
    Peacemaker_DW.obj_j.isSetupComplete = false;
    Peacemaker_DW.obj_j.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Peacemaker_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write1' */
    Peacemaker_DW.obj_h.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_h.isInitialized = 0;
    Peacemaker_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_h;
    Peacemaker_DW.obj_h.isSetupComplete = false;
    Peacemaker_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Peacemaker_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write2' */
    Peacemaker_DW.obj_n.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_n.isInitialized = 0;
    Peacemaker_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_n;
    Peacemaker_DW.obj_n.isSetupComplete = false;
    Peacemaker_DW.obj_n.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Peacemaker_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write3' */
    Peacemaker_DW.obj_jy.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_jy.isInitialized = 0;
    Peacemaker_DW.obj_jy.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_jy;
    Peacemaker_DW.obj_jy.isSetupComplete = false;
    Peacemaker_DW.obj_jy.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Peacemaker_DW.obj_jy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    Peacemaker_DW.obj_p.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_p.isInitialized = 0;
    Peacemaker_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &Peacemaker_DW.obj_p;
    Peacemaker_DW.obj_p.isSetupComplete = false;
    Peacemaker_DW.obj_p.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Peacemaker_DW.obj_p.MW_PWM_HANDLE);
    Peacemaker_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write4' */
    Peacemaker_DW.obj_l.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_l.isInitialized = 0;
    Peacemaker_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_l;
    Peacemaker_DW.obj_l.isSetupComplete = false;
    Peacemaker_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Peacemaker_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write5' */
    Peacemaker_DW.obj_nc.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_nc.isInitialized = 0;
    Peacemaker_DW.obj_nc.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_nc;
    Peacemaker_DW.obj_nc.isSetupComplete = false;
    Peacemaker_DW.obj_nc.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Peacemaker_DW.obj_nc.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write6' */
    Peacemaker_DW.obj_e.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_e.isInitialized = 0;
    Peacemaker_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_e;
    Peacemaker_DW.obj_e.isSetupComplete = false;
    Peacemaker_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Peacemaker_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write7' */
    Peacemaker_DW.obj_j1.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_j1.isInitialized = 0;
    Peacemaker_DW.obj_j1.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_j1;
    Peacemaker_DW.obj_j1.isSetupComplete = false;
    Peacemaker_DW.obj_j1.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Peacemaker_DW.obj_j1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write8' */
    Peacemaker_DW.obj_f.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_f.isInitialized = 0;
    Peacemaker_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_f;
    Peacemaker_DW.obj_f.isSetupComplete = false;
    Peacemaker_DW.obj_f.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Peacemaker_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output1' */
    Peacemaker_DW.obj_m.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_m.isInitialized = 0;
    Peacemaker_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_1 = &Peacemaker_DW.obj_m;
    Peacemaker_DW.obj_m.isSetupComplete = false;
    Peacemaker_DW.obj_m.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Peacemaker_DW.obj_m.MW_PWM_HANDLE);
    Peacemaker_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output2' */
    Peacemaker_DW.obj_km.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_km.isInitialized = 0;
    Peacemaker_DW.obj_km.matlabCodegenIsDeleted = false;
    obj_1 = &Peacemaker_DW.obj_km;
    Peacemaker_DW.obj_km.isSetupComplete = false;
    Peacemaker_DW.obj_km.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Peacemaker_DW.obj_km.MW_PWM_HANDLE);
    Peacemaker_DW.obj_km.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write9' */
    Peacemaker_DW.obj_nf.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_nf.isInitialized = 0;
    Peacemaker_DW.obj_nf.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_nf;
    Peacemaker_DW.obj_nf.isSetupComplete = false;
    Peacemaker_DW.obj_nf.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Peacemaker_DW.obj_nf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write10' */
    Peacemaker_DW.obj_et.matlabCodegenIsDeleted = true;
    Peacemaker_DW.obj_et.isInitialized = 0;
    Peacemaker_DW.obj_et.matlabCodegenIsDeleted = false;
    obj_0 = &Peacemaker_DW.obj_et;
    Peacemaker_DW.obj_et.isSetupComplete = false;
    Peacemaker_DW.obj_et.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Peacemaker_DW.obj_et.isSetupComplete = true;
  }
}

/* Model terminate function */
void Peacemaker_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Read' */
  matlabCodegenHandle_matlabCodeg(&Peacemaker_DW.obj);

  /* Terminate for MATLABSystem: '<S1>/Digital Read1' */
  matlabCodegenHandle_matlabCodeg(&Peacemaker_DW.obj_k);

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_j);

  /* Terminate for MATLABSystem: '<S3>/Digital Write1' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_h);

  /* Terminate for MATLABSystem: '<S3>/Digital Write2' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_n);

  /* Terminate for MATLABSystem: '<S3>/Digital Write3' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_jy);

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  matlabCodegenHandle_matlab_kw0p(&Peacemaker_DW.obj_p);

  /* Terminate for MATLABSystem: '<S3>/Digital Write4' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/Digital Write5' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_nc);

  /* Terminate for MATLABSystem: '<S3>/Digital Write6' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_e);

  /* Terminate for MATLABSystem: '<S3>/Digital Write7' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_j1);

  /* Terminate for MATLABSystem: '<S3>/Digital Write8' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_f);

  /* Terminate for MATLABSystem: '<S3>/PWM Output1' */
  matlabCodegenHandle_matlab_kw0p(&Peacemaker_DW.obj_m);

  /* Terminate for MATLABSystem: '<S3>/PWM Output2' */
  matlabCodegenHandle_matlab_kw0p(&Peacemaker_DW.obj_km);

  /* Terminate for MATLABSystem: '<S3>/Digital Write9' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_nf);

  /* Terminate for MATLABSystem: '<S3>/Digital Write10' */
  matlabCodegenHandle_matlabCo_kw(&Peacemaker_DW.obj_et);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
