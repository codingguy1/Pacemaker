/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1.c
 *
 * Code generated for Simulink model 'Assignment1'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Oct 25 22:59:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Assignment1.h"
#include "Assignment1_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Assignmen_IN_Ventricular_Pacing ((uint8_T)2U)
#define Assignment1_IN_AAI             ((uint8_T)1U)
#define Assignment1_IN_AOO             ((uint8_T)2U)
#define Assignment1_IN_AOO_Charge      ((uint8_T)1U)
#define Assignment1_IN_Atrial_Pacing   ((uint8_T)2U)
#define Assignment1_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment1_IN_OFF             ((uint8_T)3U)
#define Assignment1_IN_VOO             ((uint8_T)4U)
#define Assignment1_IN_VOO_Charge      ((uint8_T)1U)
#define Assignment1_IN_VVI             ((uint8_T)5U)
#define Assignment1_IN_VVI_Charge      ((uint8_T)1U)
#define Assignment1_IN_inhibited_ARP   ((uint8_T)3U)
#define Assignment1_IN_inhibited_VRP   ((uint8_T)3U)
#define Assignment1_IN_sense           ((uint8_T)4U)

/* Block signals (default storage) */
B_Assignment1_T Assignment1_B;

/* Block states (default storage) */
DW_Assignment1_T Assignment1_DW;

/* Real-time model */
RT_MODEL_Assignment1_T Assignment1_M_;
RT_MODEL_Assignment1_T *const Assignment1_M = &Assignment1_M_;

/* Forward declaration for local functions */
static void Assignm_enter_atomic_AOO_Charge(const real_T *y_k);
static void Assignment1_AAI(const real_T *y_l, const real_T *y_lk, const real_T *
  y_k, const real_T *y_g, const real_T *y_b, const boolean_T *DigitalRead);
static void Assignment1_AOO(const real_T *y_l, const real_T *y_k, const real_T
  *y_g, const real_T *y_b);
static void Assignm_enter_atomic_VOO_Charge(const real_T *y_k);
static void Assign_SystemCore_release_j3b1w(const
  freedomk64f_DigitalRead_Assig_T *obj);
static void Assignm_SystemCore_delete_j3b1w(const
  freedomk64f_DigitalRead_Assig_T *obj);
static void matlabCodegenHandle_matla_j3b1w(freedomk64f_DigitalRead_Assig_T *obj);
static void Assi_SystemCore_release_j3b1wei(const
  freedomk64f_DigitalWrite_Assi_T *obj);
static void Assig_SystemCore_delete_j3b1wei(const
  freedomk64f_DigitalWrite_Assi_T *obj);
static void matlabCodegenHandle_mat_j3b1wei(freedomk64f_DigitalWrite_Assi_T *obj);
static void SystemCore_relea_j3b1wei5ggv3l5(const
  freedomk64f_PWMOutput_Assignm_T *obj);
static void SystemCore_delet_j3b1wei5ggv3l5(const
  freedomk64f_PWMOutput_Assignm_T *obj);
static void matlabCodegenHan_j3b1wei5ggv3l5(freedomk64f_PWMOutput_Assignm_T *obj);
static void Assignment1_SystemCore_release(const freedomk64f_AnalogInput_Assig_T
  *obj);
static void Assignment1_SystemCore_delete(const freedomk64f_AnalogInput_Assig_T *
  obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_AnalogInput_Assig_T *obj);

/*
 * Output and update for atomic system:
 *    '<S2>/ARP Limiter'
 *    '<S2>/VRP Limiter'
 */
void Assignment1_ARPLimiter(real_T rtu_u, real_T *rty_y)
{
  *rty_y = rtu_u;
  if (rtu_u > 500.0) {
    *rty_y = 500.0;
  } else {
    if (rtu_u < 150.0) {
      *rty_y = 0.0;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Assignm_enter_atomic_AOO_Charge(const real_T *y_k)
{
  Assignment1_B.PACING_REF_PWM = *y_k;
  Assignment1_B.ATR_CMP_REF_PWM = 70.0;
  Assignment1_B.PACE_CHARGE_CTRL = 1.0;
  Assignment1_B.PACE_GND_CTRL = 1.0;
  Assignment1_B.ATR_PACE_CTRL = 0.0;
  Assignment1_B.ATR_GND_CTRL = 1.0;
  Assignment1_B.VENT_PACE_CTRL = 0.0;
  Assignment1_B.VENT_GND_CTRL = 0.0;
  Assignment1_B.Z_ATR_CTRL = 0.0;
  Assignment1_B.Z_VENT_CTRL = 0.0;
  Assignment1_B.FRONTEND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Chart' */
static void Assignment1_AAI(const real_T *y_l, const real_T *y_lk, const real_T *
  y_k, const real_T *y_g, const real_T *y_b, const boolean_T *DigitalRead)
{
  if (*y_g != 3.0) {
    Assignment1_DW.is_AAI = Assignment1_IN_NO_ACTIVE_CHILD;
    Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_OFF;
    Assignment1_B.ATR_PACE_CTRL = 0.0;
    Assignment1_B.VENT_PACE_CTRL = 0.0;
  } else {
    switch (Assignment1_DW.is_AAI) {
     case Assignment1_IN_AOO_Charge:
      Assignment1_B.ATR_CMP_REF_PWM = 70.0;
      Assignment1_B.PACE_CHARGE_CTRL = 1.0;
      Assignment1_B.PACE_GND_CTRL = 1.0;
      Assignment1_B.ATR_PACE_CTRL = 0.0;
      Assignment1_B.ATR_GND_CTRL = 1.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      Assignment1_B.VENT_GND_CTRL = 0.0;
      Assignment1_B.Z_ATR_CTRL = 0.0;
      Assignment1_B.Z_VENT_CTRL = 0.0;
      Assignment1_B.FRONTEND_CTRL = 0.0;
      Assignment1_DW.is_AAI = Assignment1_IN_inhibited_ARP;
      Assignment1_DW.temporalCounter_i1 = 0U;
      break;

     case Assignment1_IN_Atrial_Pacing:
      Assignment1_B.ATR_CMP_REF_PWM = 70.0;
      Assignment1_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1_B.PACE_GND_CTRL = 1.0;
      Assignment1_B.ATR_PACE_CTRL = 1.0;
      Assignment1_B.ATR_GND_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      Assignment1_B.VENT_GND_CTRL = 0.0;
      Assignment1_B.Z_ATR_CTRL = 0.0;
      Assignment1_B.Z_VENT_CTRL = 0.0;
      if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(*y_b)) {
        Assignment1_DW.is_AAI = Assignment1_IN_AOO_Charge;
        Assignm_enter_atomic_AOO_Charge(y_k);
      }
      break;

     case Assignment1_IN_inhibited_ARP:
      if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(*y_lk)) {
        Assignment1_DW.is_AAI = Assignment1_IN_sense;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignment1_B.FRONTEND_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_sense: */
      Assignment1_B.FRONTEND_CTRL = 1.0;
      if (*DigitalRead) {
        Assignment1_DW.is_AAI = Assignment1_IN_sense;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignment1_B.FRONTEND_CTRL = 1.0;
      } else {
        if ((Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(*y_l - *y_lk)) &&
            (!*DigitalRead)) {
          Assignment1_DW.is_AAI = Assignment1_IN_Atrial_Pacing;
          Assignment1_DW.temporalCounter_i1 = 0U;
          Assignment1_B.PACING_REF_PWM = *y_k;
          Assignment1_B.ATR_CMP_REF_PWM = 70.0;
          Assignment1_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1_B.PACE_GND_CTRL = 1.0;
          Assignment1_B.ATR_PACE_CTRL = 1.0;
          Assignment1_B.ATR_GND_CTRL = 0.0;
          Assignment1_B.VENT_PACE_CTRL = 0.0;
          Assignment1_B.VENT_GND_CTRL = 0.0;
          Assignment1_B.Z_ATR_CTRL = 0.0;
          Assignment1_B.Z_VENT_CTRL = 0.0;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Assignment1_AOO(const real_T *y_l, const real_T *y_k, const real_T
  *y_g, const real_T *y_b)
{
  if (*y_g != 1.0) {
    Assignment1_DW.is_AOO = Assignment1_IN_NO_ACTIVE_CHILD;
    Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_OFF;
    Assignment1_B.ATR_PACE_CTRL = 0.0;
    Assignment1_B.VENT_PACE_CTRL = 0.0;
  } else if (Assignment1_DW.is_AOO == Assignment1_IN_AOO_Charge) {
    Assignment1_B.ATR_CMP_REF_PWM = 70.0;
    Assignment1_B.PACE_CHARGE_CTRL = 1.0;
    Assignment1_B.PACE_GND_CTRL = 1.0;
    Assignment1_B.ATR_PACE_CTRL = 0.0;
    Assignment1_B.ATR_GND_CTRL = 1.0;
    Assignment1_B.VENT_PACE_CTRL = 0.0;
    Assignment1_B.VENT_GND_CTRL = 0.0;
    Assignment1_B.Z_ATR_CTRL = 0.0;
    Assignment1_B.Z_VENT_CTRL = 0.0;
    Assignment1_B.FRONTEND_CTRL = 0.0;
    if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(*y_l - *y_b)) {
      Assignment1_DW.is_AOO = Assignment1_IN_Atrial_Pacing;
      Assignment1_DW.temporalCounter_i1 = 0U;
      Assignment1_B.PACING_REF_PWM = *y_k;
      Assignment1_B.ATR_CMP_REF_PWM = 70.0;
      Assignment1_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1_B.PACE_GND_CTRL = 1.0;
      Assignment1_B.ATR_PACE_CTRL = 1.0;
      Assignment1_B.ATR_GND_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      Assignment1_B.VENT_GND_CTRL = 0.0;
      Assignment1_B.Z_ATR_CTRL = 0.0;
      Assignment1_B.Z_VENT_CTRL = 0.0;
    }
  } else {
    /* case IN_Atrial_Pacing: */
    Assignment1_B.ATR_CMP_REF_PWM = 70.0;
    Assignment1_B.PACE_CHARGE_CTRL = 0.0;
    Assignment1_B.PACE_GND_CTRL = 1.0;
    Assignment1_B.ATR_PACE_CTRL = 1.0;
    Assignment1_B.ATR_GND_CTRL = 0.0;
    Assignment1_B.VENT_PACE_CTRL = 0.0;
    Assignment1_B.VENT_GND_CTRL = 0.0;
    Assignment1_B.Z_ATR_CTRL = 0.0;
    Assignment1_B.Z_VENT_CTRL = 0.0;
    if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(*y_b)) {
      Assignment1_DW.is_AOO = Assignment1_IN_AOO_Charge;
      Assignment1_DW.temporalCounter_i1 = 0U;
      Assignm_enter_atomic_AOO_Charge(y_k);
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Assignm_enter_atomic_VOO_Charge(const real_T *y_k)
{
  Assignment1_B.PACING_REF_PWM = *y_k;
  Assignment1_B.VENT_CMP_REF_PWM = 70.0;
  Assignment1_B.PACE_CHARGE_CTRL = 1.0;
  Assignment1_B.PACE_GND_CTRL = 1.0;
  Assignment1_B.ATR_PACE_CTRL = 0.0;
  Assignment1_B.ATR_GND_CTRL = 0.0;
  Assignment1_B.VENT_PACE_CTRL = 0.0;
  Assignment1_B.VENT_GND_CTRL = 1.0;
  Assignment1_B.Z_ATR_CTRL = 0.0;
  Assignment1_B.Z_VENT_CTRL = 0.0;
  Assignment1_B.FRONTEND_CTRL = 0.0;
}

static void Assign_SystemCore_release_j3b1w(const
  freedomk64f_DigitalRead_Assig_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Assignm_SystemCore_delete_j3b1w(const
  freedomk64f_DigitalRead_Assig_T *obj)
{
  Assign_SystemCore_release_j3b1w(obj);
}

static void matlabCodegenHandle_matla_j3b1w(freedomk64f_DigitalRead_Assig_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignm_SystemCore_delete_j3b1w(obj);
  }
}

static void Assi_SystemCore_release_j3b1wei(const
  freedomk64f_DigitalWrite_Assi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Assig_SystemCore_delete_j3b1wei(const
  freedomk64f_DigitalWrite_Assi_T *obj)
{
  Assi_SystemCore_release_j3b1wei(obj);
}

static void matlabCodegenHandle_mat_j3b1wei(freedomk64f_DigitalWrite_Assi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assig_SystemCore_delete_j3b1wei(obj);
  }
}

static void SystemCore_relea_j3b1wei5ggv3l5(const
  freedomk64f_PWMOutput_Assignm_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void SystemCore_delet_j3b1wei5ggv3l5(const
  freedomk64f_PWMOutput_Assignm_T *obj)
{
  SystemCore_relea_j3b1wei5ggv3l5(obj);
}

static void matlabCodegenHan_j3b1wei5ggv3l5(freedomk64f_PWMOutput_Assignm_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SystemCore_delet_j3b1wei5ggv3l5(obj);
  }
}

static void Assignment1_SystemCore_release(const freedomk64f_AnalogInput_Assig_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_AnalogIn_Stop(obj->MW_ANALOGIN_HANDLE);
    MW_AnalogIn_Close(obj->MW_ANALOGIN_HANDLE);
  }
}

static void Assignment1_SystemCore_delete(const freedomk64f_AnalogInput_Assig_T *
  obj)
{
  Assignment1_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_AnalogInput_Assig_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignment1_SystemCore_delete(obj);
  }
}

/* Model step function */
void Assignment1_step(void)
{
  real_T u;
  boolean_T tmp;
  real_T u_0;
  real_T y;
  real_T y_l;
  real_T y_lk;
  real_T y_g;
  real_T y_b;
  boolean_T DigitalRead;

  /* MATLAB Function: '<S2>/Mode Limiter' incorporates:
   *  Constant: '<S2>/Mode'
   */
  y_g = Assignment1_P.Mode_Value;
  if (Assignment1_P.Mode_Value > 4.0) {
    y_g = 0.0;
  } else {
    if (Assignment1_P.Mode_Value < 1.0) {
      y_g = 0.0;
    }
  }

  /* End of MATLAB Function: '<S2>/Mode Limiter' */

  /* MATLAB Function: '<S2>/APW Limiter' incorporates:
   *  Constant: '<S2>/Constant5'
   */
  y_b = Assignment1_P.Constant5_Value;
  if (Assignment1_P.Constant5_Value > 20.0) {
    y_b = 20.0;
  } else {
    if (Assignment1_P.Constant5_Value < 1.0) {
      y_b = 1.0;
    }
  }

  /* End of MATLAB Function: '<S2>/APW Limiter' */

  /* MATLAB Function: '<S2>/VPW Limiter' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  u = Assignment1_P.Constant4_Value;
  if (Assignment1_P.Constant4_Value > 20.0) {
    u = 20.0;
  } else {
    if (Assignment1_P.Constant4_Value < 1.0) {
      u = 1.0;
    }
  }

  /* MATLABSystem: '<S2>/Digital Read1' */
  if (Assignment1_DW.obj_k1.SampleTime != Assignment1_P.DigitalRead1_SampleTime)
  {
    Assignment1_DW.obj_k1.SampleTime = Assignment1_P.DigitalRead1_SampleTime;
  }

  tmp = MW_digitalIO_read(Assignment1_DW.obj_k1.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/Digital Read' */
  if (Assignment1_DW.obj_g.SampleTime != Assignment1_P.DigitalRead_SampleTime) {
    Assignment1_DW.obj_g.SampleTime = Assignment1_P.DigitalRead_SampleTime;
  }

  DigitalRead = MW_digitalIO_read(Assignment1_DW.obj_g.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S2>/Digital Read' */

  /* MATLAB Function: '<S2>/LRL Limiter' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  y_l = Assignment1_P.Constant3_Value;
  if (Assignment1_P.Constant3_Value > 175.0) {
    y_l = 175.0;
  } else {
    if (Assignment1_P.Constant3_Value < 30.0) {
      y_l = 30.0;
    }
  }

  /* MATLAB Function: '<S2>/ARP Limiter' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  Assignment1_ARPLimiter(Assignment1_P.Constant2_Value, &y_lk);

  /* MATLAB Function: '<S2>/VRP Limiter' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  Assignment1_ARPLimiter(Assignment1_P.Constant1_Value, &y);

  /* MATLAB Function: '<S2>/Amp Limiter' incorporates:
   *  Constant: '<S2>/Constant7'
   */
  u_0 = Assignment1_P.Constant7_Value;
  if (Assignment1_P.Constant7_Value >= 100.0) {
    u_0 = 100.0;
  } else {
    if (Assignment1_P.Constant7_Value < 1.0) {
      u_0 = 1.0;
    }
  }

  /* MATLAB Function: '<S2>/LRI Function' incorporates:
   *  MATLAB Function: '<S2>/LRL Limiter'
   */
  y_l = 60000.0 / y_l;

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLAB Function: '<S2>/Amp Limiter'
   *  MATLAB Function: '<S2>/VPW Limiter'
   *  MATLABSystem: '<S2>/Digital Read1'
   */
  if (Assignment1_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_DW.temporalCounter_i1++;
  }

  if (Assignment1_DW.is_active_c3_Assignment1 == 0U) {
    Assignment1_DW.is_active_c3_Assignment1 = 1U;
    Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_OFF;
    Assignment1_B.ATR_PACE_CTRL = 0.0;
    Assignment1_B.VENT_PACE_CTRL = 0.0;
  } else {
    switch (Assignment1_DW.is_c3_Assignment1) {
     case Assignment1_IN_AAI:
      Assignment1_AAI(&y_l, &y_lk, &u_0, &y_g, &y_b, &DigitalRead);
      break;

     case Assignment1_IN_AOO:
      Assignment1_AOO(&y_l, &u_0, &y_g, &y_b);
      break;

     case Assignment1_IN_OFF:
      Assignment1_B.ATR_PACE_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      if (y_g == 3.0) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_AAI;
        Assignment1_DW.is_AAI = Assignment1_IN_AOO_Charge;
        Assignm_enter_atomic_AOO_Charge(&u_0);
      } else if (y_g == 1.0) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_AOO;
        Assignment1_DW.is_AOO = Assignment1_IN_AOO_Charge;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignm_enter_atomic_AOO_Charge(&u_0);
      } else if (y_g == 4.0) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_VVI;
        Assignment1_DW.is_VVI = Assignment1_IN_VVI_Charge;
        Assignment1_B.PACING_REF_PWM = u_0;
        Assignment1_B.VENT_CMP_REF_PWM = 70.0;
        Assignment1_B.PACE_CHARGE_CTRL = 1.0;
        Assignment1_B.PACE_GND_CTRL = 1.0;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.ATR_GND_CTRL = 0.0;
        Assignment1_B.VENT_PACE_CTRL = 0.0;
        Assignment1_B.VENT_GND_CTRL = 1.0;
        Assignment1_B.Z_ATR_CTRL = 0.0;
        Assignment1_B.Z_VENT_CTRL = 0.0;
      } else {
        if (y_g == 2.0) {
          Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_VOO;
          Assignment1_DW.is_VOO = Assignment1_IN_VOO_Charge;
          Assignment1_DW.temporalCounter_i1 = 0U;
          Assignm_enter_atomic_VOO_Charge(&u_0);
        }
      }
      break;

     case Assignment1_IN_VOO:
      if (y_g != 2.0) {
        Assignment1_DW.is_VOO = Assignment1_IN_NO_ACTIVE_CHILD;
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_OFF;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.VENT_PACE_CTRL = 0.0;
      } else if (Assignment1_DW.is_VOO == Assignment1_IN_VOO_Charge) {
        Assignment1_B.VENT_CMP_REF_PWM = 70.0;
        Assignment1_B.PACE_CHARGE_CTRL = 1.0;
        Assignment1_B.PACE_GND_CTRL = 1.0;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.ATR_GND_CTRL = 0.0;
        Assignment1_B.VENT_PACE_CTRL = 0.0;
        Assignment1_B.VENT_GND_CTRL = 1.0;
        Assignment1_B.Z_ATR_CTRL = 0.0;
        Assignment1_B.Z_VENT_CTRL = 0.0;
        Assignment1_B.FRONTEND_CTRL = 0.0;
        if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(y_l - u)) {
          Assignment1_DW.is_VOO = Assignmen_IN_Ventricular_Pacing;
          Assignment1_DW.temporalCounter_i1 = 0U;
          Assignment1_B.PACING_REF_PWM = u_0;
          Assignment1_B.VENT_CMP_REF_PWM = 70.0;
          Assignment1_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1_B.PACE_GND_CTRL = 1.0;
          Assignment1_B.ATR_PACE_CTRL = 0.0;
          Assignment1_B.ATR_GND_CTRL = 0.0;
          Assignment1_B.Z_ATR_CTRL = 0.0;
          Assignment1_B.Z_VENT_CTRL = 0.0;
          Assignment1_B.VENT_PACE_CTRL = 1.0;
          Assignment1_B.VENT_GND_CTRL = 0.0;
        }
      } else {
        /* case IN_Ventricular_Pacing: */
        Assignment1_B.VENT_CMP_REF_PWM = 70.0;
        Assignment1_B.PACE_CHARGE_CTRL = 0.0;
        Assignment1_B.PACE_GND_CTRL = 1.0;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.ATR_GND_CTRL = 0.0;
        Assignment1_B.Z_ATR_CTRL = 0.0;
        Assignment1_B.Z_VENT_CTRL = 0.0;
        Assignment1_B.VENT_PACE_CTRL = 1.0;
        Assignment1_B.VENT_GND_CTRL = 0.0;
        if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(u)) {
          Assignment1_DW.is_VOO = Assignment1_IN_VOO_Charge;
          Assignment1_DW.temporalCounter_i1 = 0U;
          Assignm_enter_atomic_VOO_Charge(&u_0);
        }
      }
      break;

     default:
      /* case IN_VVI: */
      if (y_g != 4.0) {
        Assignment1_DW.is_VVI = Assignment1_IN_NO_ACTIVE_CHILD;
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_OFF;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.VENT_PACE_CTRL = 0.0;
      } else {
        switch (Assignment1_DW.is_VVI) {
         case Assignment1_IN_VVI_Charge:
          Assignment1_B.VENT_CMP_REF_PWM = 70.0;
          Assignment1_B.PACE_CHARGE_CTRL = 1.0;
          Assignment1_B.PACE_GND_CTRL = 1.0;
          Assignment1_B.ATR_PACE_CTRL = 0.0;
          Assignment1_B.ATR_GND_CTRL = 0.0;
          Assignment1_B.VENT_PACE_CTRL = 0.0;
          Assignment1_B.VENT_GND_CTRL = 1.0;
          Assignment1_B.Z_ATR_CTRL = 0.0;
          Assignment1_B.Z_VENT_CTRL = 0.0;
          Assignment1_DW.is_VVI = Assignment1_IN_inhibited_VRP;
          Assignment1_DW.temporalCounter_i1 = 0U;
          break;

         case Assignmen_IN_Ventricular_Pacing:
          Assignment1_B.VENT_CMP_REF_PWM = 70.0;
          Assignment1_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1_B.PACE_GND_CTRL = 1.0;
          Assignment1_B.ATR_PACE_CTRL = 0.0;
          Assignment1_B.ATR_GND_CTRL = 0.0;
          Assignment1_B.Z_ATR_CTRL = 0.0;
          Assignment1_B.Z_VENT_CTRL = 0.0;
          Assignment1_B.VENT_PACE_CTRL = 1.0;
          Assignment1_B.VENT_GND_CTRL = 0.0;
          if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(u)) {
            Assignment1_DW.is_VVI = Assignment1_IN_VVI_Charge;
            Assignment1_B.PACING_REF_PWM = u_0;
            Assignment1_B.VENT_CMP_REF_PWM = 70.0;
            Assignment1_B.PACE_CHARGE_CTRL = 1.0;
            Assignment1_B.PACE_GND_CTRL = 1.0;
            Assignment1_B.ATR_PACE_CTRL = 0.0;
            Assignment1_B.ATR_GND_CTRL = 0.0;
            Assignment1_B.VENT_PACE_CTRL = 0.0;
            Assignment1_B.VENT_GND_CTRL = 1.0;
            Assignment1_B.Z_ATR_CTRL = 0.0;
            Assignment1_B.Z_VENT_CTRL = 0.0;
          }
          break;

         case Assignment1_IN_inhibited_VRP:
          if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(y - u)) {
            Assignment1_DW.is_VVI = Assignment1_IN_sense;
            Assignment1_DW.temporalCounter_i1 = 0U;
            Assignment1_B.FRONTEND_CTRL = 1.0;
          }
          break;

         default:
          /* case IN_sense: */
          Assignment1_B.FRONTEND_CTRL = 1.0;
          if (tmp) {
            Assignment1_DW.is_VVI = Assignment1_IN_sense;
            Assignment1_DW.temporalCounter_i1 = 0U;
            Assignment1_B.FRONTEND_CTRL = 1.0;
          } else {
            if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(y_l - y)) {
              Assignment1_DW.is_VVI = Assignmen_IN_Ventricular_Pacing;
              Assignment1_DW.temporalCounter_i1 = 0U;
              Assignment1_B.PACING_REF_PWM = u_0;
              Assignment1_B.VENT_CMP_REF_PWM = 70.0;
              Assignment1_B.PACE_CHARGE_CTRL = 0.0;
              Assignment1_B.PACE_GND_CTRL = 1.0;
              Assignment1_B.ATR_PACE_CTRL = 0.0;
              Assignment1_B.ATR_GND_CTRL = 0.0;
              Assignment1_B.Z_ATR_CTRL = 0.0;
              Assignment1_B.Z_VENT_CTRL = 0.0;
              Assignment1_B.VENT_PACE_CTRL = 1.0;
              Assignment1_B.VENT_GND_CTRL = 0.0;
            }
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S3>/Digital Write' */
  MW_digitalIO_write(Assignment1_DW.obj_mb.MW_DIGITALIO_HANDLE,
                     Assignment1_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment1_DW.obj_j.MW_PWM_HANDLE,
                      Assignment1_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write1' */
  MW_digitalIO_write(Assignment1_DW.obj_p5.MW_DIGITALIO_HANDLE,
                     Assignment1_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S3>/PWM Output1' */
  MW_PWM_SetDutyCycle(Assignment1_DW.obj_f.MW_PWM_HANDLE,
                      Assignment1_B.PACING_REF_PWM);

  /* MATLABSystem: '<S3>/PWM Output2' */
  MW_PWM_SetDutyCycle(Assignment1_DW.obj_pg.MW_PWM_HANDLE,
                      Assignment1_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S3>/Digital Write2' */
  MW_digitalIO_write(Assignment1_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Assignment1_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write3' */
  MW_digitalIO_write(Assignment1_DW.obj_i.MW_DIGITALIO_HANDLE,
                     Assignment1_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write4' */
  MW_digitalIO_write(Assignment1_DW.obj_k0.MW_DIGITALIO_HANDLE,
                     Assignment1_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write6' */
  MW_digitalIO_write(Assignment1_DW.obj_o.MW_DIGITALIO_HANDLE,
                     Assignment1_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write7' */
  MW_digitalIO_write(Assignment1_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Assignment1_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write5' */
  MW_digitalIO_write(Assignment1_DW.obj_l1.MW_DIGITALIO_HANDLE,
                     Assignment1_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S3>/Digital Write8' */
  MW_digitalIO_write(Assignment1_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Assignment1_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Analog Input' */
  if (Assignment1_DW.obj.SampleTime != Assignment1_P.AnalogInput_SampleTime) {
    Assignment1_DW.obj.SampleTime = Assignment1_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj.MW_ANALOGIN_HANDLE, &y_g, 7);

  /* End of MATLABSystem: '<S2>/Analog Input' */

  /* MATLABSystem: '<S2>/Analog Input1' */
  if (Assignment1_DW.obj_p.SampleTime != Assignment1_P.AnalogInput1_SampleTime)
  {
    Assignment1_DW.obj_p.SampleTime = Assignment1_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj_p.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj_p.MW_ANALOGIN_HANDLE, &y_g, 7);

  /* End of MATLABSystem: '<S2>/Analog Input1' */

  /* MATLABSystem: '<S2>/Analog Input2' */
  if (Assignment1_DW.obj_m.SampleTime != Assignment1_P.AnalogInput2_SampleTime)
  {
    Assignment1_DW.obj_m.SampleTime = Assignment1_P.AnalogInput2_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj_m.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj_m.MW_ANALOGIN_HANDLE, &y_g, 7);

  /* End of MATLABSystem: '<S2>/Analog Input2' */

  /* MATLABSystem: '<S2>/Analog Input3' */
  if (Assignment1_DW.obj_k.SampleTime != Assignment1_P.AnalogInput3_SampleTime)
  {
    Assignment1_DW.obj_k.SampleTime = Assignment1_P.AnalogInput3_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj_k.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj_k.MW_ANALOGIN_HANDLE, &y_g, 7);

  /* End of MATLABSystem: '<S2>/Analog Input3' */

  /* MATLABSystem: '<S2>/Analog Input4' */
  if (Assignment1_DW.obj_py.SampleTime != Assignment1_P.AnalogInput4_SampleTime)
  {
    Assignment1_DW.obj_py.SampleTime = Assignment1_P.AnalogInput4_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj_py.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj_py.MW_ANALOGIN_HANDLE, &y_g, 7);

  /* End of MATLABSystem: '<S2>/Analog Input4' */
}

/* Model initialize function */
void Assignment1_initialize(void)
{
  {
    freedomk64f_DigitalRead_Assig_T *obj;
    freedomk64f_DigitalWrite_Assi_T *obj_0;
    freedomk64f_PWMOutput_Assignm_T *obj_1;
    freedomk64f_AnalogInput_Assig_T *obj_2;
    MW_AnalogIn_TriggerSource_Type trigger_val;

    /* Start for MATLABSystem: '<S2>/Digital Read1' */
    Assignment1_DW.obj_k1.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_k1.isInitialized = 0;
    Assignment1_DW.obj_k1.SampleTime = -1.0;
    Assignment1_DW.obj_k1.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_k1.SampleTime = Assignment1_P.DigitalRead1_SampleTime;
    obj = &Assignment1_DW.obj_k1;
    Assignment1_DW.obj_k1.isSetupComplete = false;
    Assignment1_DW.obj_k1.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment1_DW.obj_k1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    Assignment1_DW.obj_g.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_g.isInitialized = 0;
    Assignment1_DW.obj_g.SampleTime = -1.0;
    Assignment1_DW.obj_g.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_g.SampleTime = Assignment1_P.DigitalRead_SampleTime;
    obj = &Assignment1_DW.obj_g;
    Assignment1_DW.obj_g.isSetupComplete = false;
    Assignment1_DW.obj_g.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment1_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    Assignment1_DW.obj_mb.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_mb.isInitialized = 0;
    Assignment1_DW.obj_mb.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_mb;
    Assignment1_DW.obj_mb.isSetupComplete = false;
    Assignment1_DW.obj_mb.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_DW.obj_mb.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output' */
    Assignment1_DW.obj_j.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_j.isInitialized = 0;
    Assignment1_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_DW.obj_j;
    Assignment1_DW.obj_j.isSetupComplete = false;
    Assignment1_DW.obj_j.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_DW.obj_j.MW_PWM_HANDLE);
    Assignment1_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write1' */
    Assignment1_DW.obj_p5.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_p5.isInitialized = 0;
    Assignment1_DW.obj_p5.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_p5;
    Assignment1_DW.obj_p5.isSetupComplete = false;
    Assignment1_DW.obj_p5.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1_DW.obj_p5.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output1' */
    Assignment1_DW.obj_f.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_f.isInitialized = 0;
    Assignment1_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_DW.obj_f;
    Assignment1_DW.obj_f.isSetupComplete = false;
    Assignment1_DW.obj_f.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_DW.obj_f.MW_PWM_HANDLE);
    Assignment1_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM Output2' */
    Assignment1_DW.obj_pg.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_pg.isInitialized = 0;
    Assignment1_DW.obj_pg.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_DW.obj_pg;
    Assignment1_DW.obj_pg.isSetupComplete = false;
    Assignment1_DW.obj_pg.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_DW.obj_pg.MW_PWM_HANDLE);
    Assignment1_DW.obj_pg.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write2' */
    Assignment1_DW.obj_l.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_l.isInitialized = 0;
    Assignment1_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_l;
    Assignment1_DW.obj_l.isSetupComplete = false;
    Assignment1_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write3' */
    Assignment1_DW.obj_i.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_i.isInitialized = 0;
    Assignment1_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_i;
    Assignment1_DW.obj_i.isSetupComplete = false;
    Assignment1_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write4' */
    Assignment1_DW.obj_k0.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_k0.isInitialized = 0;
    Assignment1_DW.obj_k0.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_k0;
    Assignment1_DW.obj_k0.isSetupComplete = false;
    Assignment1_DW.obj_k0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_DW.obj_k0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write6' */
    Assignment1_DW.obj_o.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_o.isInitialized = 0;
    Assignment1_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_o;
    Assignment1_DW.obj_o.isSetupComplete = false;
    Assignment1_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write7' */
    Assignment1_DW.obj_b.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_b.isInitialized = 0;
    Assignment1_DW.obj_b.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_b;
    Assignment1_DW.obj_b.isSetupComplete = false;
    Assignment1_DW.obj_b.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write5' */
    Assignment1_DW.obj_l1.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_l1.isInitialized = 0;
    Assignment1_DW.obj_l1.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_l1;
    Assignment1_DW.obj_l1.isSetupComplete = false;
    Assignment1_DW.obj_l1.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_DW.obj_l1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write8' */
    Assignment1_DW.obj_h.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_h.isInitialized = 0;
    Assignment1_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_h;
    Assignment1_DW.obj_h.isSetupComplete = false;
    Assignment1_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment1_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input' */
    Assignment1_DW.obj.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj.isInitialized = 0;
    Assignment1_DW.obj.SampleTime = -1.0;
    Assignment1_DW.obj.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj.SampleTime = Assignment1_P.AnalogInput_SampleTime;
    obj_2 = &Assignment1_DW.obj;
    Assignment1_DW.obj.isSetupComplete = false;
    Assignment1_DW.obj.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(20U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input1' */
    Assignment1_DW.obj_p.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_p.isInitialized = 0;
    Assignment1_DW.obj_p.SampleTime = -1.0;
    Assignment1_DW.obj_p.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_p.SampleTime = Assignment1_P.AnalogInput1_SampleTime;
    obj_2 = &Assignment1_DW.obj_p;
    Assignment1_DW.obj_p.isSetupComplete = false;
    Assignment1_DW.obj_p.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj_p.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input2' */
    Assignment1_DW.obj_m.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_m.isInitialized = 0;
    Assignment1_DW.obj_m.SampleTime = -1.0;
    Assignment1_DW.obj_m.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_m.SampleTime = Assignment1_P.AnalogInput2_SampleTime;
    obj_2 = &Assignment1_DW.obj_m;
    Assignment1_DW.obj_m.isSetupComplete = false;
    Assignment1_DW.obj_m.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj_m.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input3' */
    Assignment1_DW.obj_k.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_k.isInitialized = 0;
    Assignment1_DW.obj_k.SampleTime = -1.0;
    Assignment1_DW.obj_k.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_k.SampleTime = Assignment1_P.AnalogInput3_SampleTime;
    obj_2 = &Assignment1_DW.obj_k;
    Assignment1_DW.obj_k.isSetupComplete = false;
    Assignment1_DW.obj_k.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj_k.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input4' */
    Assignment1_DW.obj_py.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_py.isInitialized = 0;
    Assignment1_DW.obj_py.SampleTime = -1.0;
    Assignment1_DW.obj_py.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_py.SampleTime = Assignment1_P.AnalogInput4_SampleTime;
    obj_2 = &Assignment1_DW.obj_py;
    Assignment1_DW.obj_py.isSetupComplete = false;
    Assignment1_DW.obj_py.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj_py.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj_py.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Digital Read1' */
  matlabCodegenHandle_matla_j3b1w(&Assignment1_DW.obj_k1);

  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  matlabCodegenHandle_matla_j3b1w(&Assignment1_DW.obj_g);

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_mb);

  /* Terminate for MATLABSystem: '<S3>/PWM Output' */
  matlabCodegenHan_j3b1wei5ggv3l5(&Assignment1_DW.obj_j);

  /* Terminate for MATLABSystem: '<S3>/Digital Write1' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_p5);

  /* Terminate for MATLABSystem: '<S3>/PWM Output1' */
  matlabCodegenHan_j3b1wei5ggv3l5(&Assignment1_DW.obj_f);

  /* Terminate for MATLABSystem: '<S3>/PWM Output2' */
  matlabCodegenHan_j3b1wei5ggv3l5(&Assignment1_DW.obj_pg);

  /* Terminate for MATLABSystem: '<S3>/Digital Write2' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_l);

  /* Terminate for MATLABSystem: '<S3>/Digital Write3' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_i);

  /* Terminate for MATLABSystem: '<S3>/Digital Write4' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_k0);

  /* Terminate for MATLABSystem: '<S3>/Digital Write6' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_o);

  /* Terminate for MATLABSystem: '<S3>/Digital Write7' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_b);

  /* Terminate for MATLABSystem: '<S3>/Digital Write5' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_l1);

  /* Terminate for MATLABSystem: '<S3>/Digital Write8' */
  matlabCodegenHandle_mat_j3b1wei(&Assignment1_DW.obj_h);

  /* Terminate for MATLABSystem: '<S2>/Analog Input' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/Analog Input1' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_p);

  /* Terminate for MATLABSystem: '<S2>/Analog Input2' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_m);

  /* Terminate for MATLABSystem: '<S2>/Analog Input3' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_k);

  /* Terminate for MATLABSystem: '<S2>/Analog Input4' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_py);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
