/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1.c
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

#include "Assignment1.h"
#include "Assignment1_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Assignmen_IN_Ventricular_Pacing ((uint8_T)9U)
#define Assignment1_IN_AAI             ((uint8_T)1U)
#define Assignment1_IN_AOO_discharge   ((uint8_T)2U)
#define Assignment1_IN_Atrial_Pacing   ((uint8_T)3U)
#define Assignment1_IN_CHARGING        ((uint8_T)4U)
#define Assignment1_IN_No_Pacing       ((uint8_T)5U)
#define Assignment1_IN_Select_mode     ((uint8_T)6U)
#define Assignment1_IN_VOO_discharge   ((uint8_T)7U)
#define Assignment1_IN_VVI             ((uint8_T)8U)
#define Assignment1_IN_delay           ((uint8_T)10U)

/* Block signals (default storage) */
B_Assignment1_T Assignment1_B;

/* Block states (default storage) */
DW_Assignment1_T Assignment1_DW;

/* Real-time model */
RT_MODEL_Assignment1_T Assignment1_M_;
RT_MODEL_Assignment1_T *const Assignment1_M = &Assignment1_M_;

/* Forward declaration for local functions */
static void A_SystemCore_rele_ep(const freedomk64f_DigitalRead_Assig_T *obj);
static void A_SystemCore_dele_ep(const freedomk64f_DigitalRead_Assig_T *obj);
static void Assignment1_matlabCodegenHa_ep(freedomk64f_DigitalRead_Assig_T *obj);
static void Assignment1_SystemCore_release(const freedomk64f_DigitalWrite_Assi_T
  *obj);
static void Assignment1_SystemCore_delete(const freedomk64f_DigitalWrite_Assi_T *
  obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_Assi_T *obj);
static void Assig_SystemCore_release_j3b1we(const
  freedomk64f_PWMOutput_Assignm_T *obj);
static void Assign_SystemCore_delete_j3b1we(const
  freedomk64f_PWMOutput_Assignm_T *obj);
static void matlabCodegenHandle_matl_j3b1we(freedomk64f_PWMOutput_Assignm_T *obj);
static void Assignment_SystemCore_release_j(const
  freedomk64f_AnalogInput_Assig_T *obj);
static void Assignment1_SystemCore_delete_j(const
  freedomk64f_AnalogInput_Assig_T *obj);
static void matlabCodegenHandle_matlabCod_j(freedomk64f_AnalogInput_Assig_T *obj);
static void A_SystemCore_rele_ep(const freedomk64f_DigitalRead_Assig_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void A_SystemCore_dele_ep(const freedomk64f_DigitalRead_Assig_T *obj)
{
  A_SystemCore_rele_ep(obj);
}

static void Assignment1_matlabCodegenHa_ep(freedomk64f_DigitalRead_Assig_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    A_SystemCore_dele_ep(obj);
  }
}

static void Assignment1_SystemCore_release(const freedomk64f_DigitalWrite_Assi_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Assignment1_SystemCore_delete(const freedomk64f_DigitalWrite_Assi_T *
  obj)
{
  Assignment1_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_DigitalWrite_Assi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignment1_SystemCore_delete(obj);
  }
}

static void Assig_SystemCore_release_j3b1we(const
  freedomk64f_PWMOutput_Assignm_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void Assign_SystemCore_delete_j3b1we(const
  freedomk64f_PWMOutput_Assignm_T *obj)
{
  Assig_SystemCore_release_j3b1we(obj);
}

static void matlabCodegenHandle_matl_j3b1we(freedomk64f_PWMOutput_Assignm_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assign_SystemCore_delete_j3b1we(obj);
  }
}

static void Assignment_SystemCore_release_j(const
  freedomk64f_AnalogInput_Assig_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_AnalogIn_Stop(obj->MW_ANALOGIN_HANDLE);
    MW_AnalogIn_Close(obj->MW_ANALOGIN_HANDLE);
  }
}

static void Assignment1_SystemCore_delete_j(const
  freedomk64f_AnalogInput_Assig_T *obj)
{
  Assignment_SystemCore_release_j(obj);
}

static void matlabCodegenHandle_matlabCod_j(freedomk64f_AnalogInput_Assig_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignment1_SystemCore_delete_j(obj);
  }
}

/* Model step function */
void Assignment1_step(void)
{
  boolean_T rtb_DigitalRead1_0;
  boolean_T rtb_DigitalRead_0;
  real_T tmp;

  /* MATLABSystem: '<S2>/Digital Read1' */
  if (Assignment1_DW.obj_n.SampleTime != Assignment1_P.DigitalRead1_SampleTime)
  {
    Assignment1_DW.obj_n.SampleTime = Assignment1_P.DigitalRead1_SampleTime;
  }

  rtb_DigitalRead1_0 = MW_digitalIO_read
    (Assignment1_DW.obj_n.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S2>/Digital Read' */
  if (Assignment1_DW.obj_cn.SampleTime != Assignment1_P.DigitalRead_SampleTime)
  {
    Assignment1_DW.obj_cn.SampleTime = Assignment1_P.DigitalRead_SampleTime;
  }

  rtb_DigitalRead_0 = MW_digitalIO_read
    (Assignment1_DW.obj_cn.MW_DIGITALIO_HANDLE);

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/atrial_pulse_width'
   *  Constant: '<Root>/mode'
   *  Constant: '<Root>/ventricular_pulse_width'
   *  MATLABSystem: '<S2>/Digital Read'
   *  MATLABSystem: '<S2>/Digital Read1'
   */
  if (Assignment1_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1_DW.temporalCounter_i1++;
  }

  if (Assignment1_DW.is_active_c3_Assignment1 == 0U) {
    Assignment1_DW.is_active_c3_Assignment1 = 1U;
    Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_CHARGING;
    Assignment1_DW.temporalCounter_i1 = 0U;
    Assignment1_B.ATR_PACE_CTRL = 0.0;
    Assignment1_B.VENT_PACE_CTRL = 0.0;
    Assignment1_B.PACE_CHARGE_CTRL = 1.0;
    Assignment1_B.FRONTEND_CTRL = 0.0;
  } else {
    switch (Assignment1_DW.is_c3_Assignment1) {
     case Assignment1_IN_AAI:
      Assignment1_B.FRONTEND_CTRL = 1.0;
      if (rtb_DigitalRead_0) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_AAI;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignment1_B.FRONTEND_CTRL = 1.0;
      } else {
        if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(60.0 /
             Assignment1_P.Constant3_Value * 1000.0)) {
          Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_Atrial_Pacing;
          Assignment1_DW.temporalCounter_i1 = 0U;
          Assignment1_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1_B.PACE_GND_CTRL = 1.0;
          Assignment1_B.ATR_PACE_CTRL = 1.0;
          Assignment1_B.ATR_GND_CTRL = 0.0;
          Assignment1_B.Z_ATR_CTRL = 0.0;
          Assignment1_B.Z_VENT_CTRL = 0.0;
          Assignment1_B.VENT_GND_CTRL = 0.0;
          Assignment1_B.VENT_PACE_CTRL = 0.0;
        }
      }
      break;

     case Assignment1_IN_AOO_discharge:
      Assignment1_B.PACE_GND_CTRL = 1.0;
      Assignment1_B.Z_ATR_CTRL = 0.0;
      Assignment1_B.Z_VENT_CTRL = 0.0;
      Assignment1_B.ATR_GND_CTRL = 1.0;
      Assignment1_B.VENT_GND_CTRL = 0.0;
      Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_CHARGING;
      Assignment1_DW.temporalCounter_i1 = 0U;
      Assignment1_B.ATR_PACE_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      Assignment1_B.PACE_CHARGE_CTRL = 1.0;
      Assignment1_B.FRONTEND_CTRL = 0.0;
      break;

     case Assignment1_IN_Atrial_Pacing:
      Assignment1_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1_B.PACE_GND_CTRL = 1.0;
      Assignment1_B.ATR_PACE_CTRL = 1.0;
      Assignment1_B.ATR_GND_CTRL = 0.0;
      Assignment1_B.Z_ATR_CTRL = 0.0;
      Assignment1_B.Z_VENT_CTRL = 0.0;
      Assignment1_B.VENT_GND_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Assignment1_P.atrial_pulse_width_Value)) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_AOO_discharge;
        Assignment1_B.PACE_GND_CTRL = 1.0;
        Assignment1_B.VENT_PACE_CTRL = 0.0;
        Assignment1_B.Z_ATR_CTRL = 0.0;
        Assignment1_B.Z_VENT_CTRL = 0.0;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.ATR_GND_CTRL = 1.0;
        Assignment1_B.VENT_GND_CTRL = 0.0;
      }
      break;

     case Assignment1_IN_CHARGING:
      Assignment1_B.ATR_PACE_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      Assignment1_B.PACE_CHARGE_CTRL = 1.0;
      Assignment1_B.FRONTEND_CTRL = 0.0;
      if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(60.0 /
           Assignment1_P.Constant3_Value * 1000.0)) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_Select_mode;
      } else {
        if ((Assignment1_P.mode_Value == 3.0) || (Assignment1_P.mode_Value ==
             4.0)) {
          Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_delay;
        }
      }
      break;

     case Assignment1_IN_No_Pacing:
      Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_CHARGING;
      Assignment1_DW.temporalCounter_i1 = 0U;
      Assignment1_B.ATR_PACE_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      Assignment1_B.PACE_CHARGE_CTRL = 1.0;
      Assignment1_B.FRONTEND_CTRL = 0.0;
      break;

     case Assignment1_IN_Select_mode:
      if (Assignment1_P.mode_Value == 2.0) {
        Assignment1_DW.is_c3_Assignment1 = Assignmen_IN_Ventricular_Pacing;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignment1_B.PACE_CHARGE_CTRL = 0.0;
        Assignment1_B.PACE_GND_CTRL = 1.0;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.ATR_GND_CTRL = 0.0;
        Assignment1_B.Z_ATR_CTRL = 0.0;
        Assignment1_B.Z_VENT_CTRL = 0.0;
        Assignment1_B.VENT_GND_CTRL = 0.0;
        Assignment1_B.VENT_PACE_CTRL = 1.0;
      } else if (Assignment1_P.mode_Value == 5.0) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_No_Pacing;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.VENT_PACE_CTRL = 0.0;
      } else {
        if (Assignment1_P.mode_Value == 1.0) {
          Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_Atrial_Pacing;
          Assignment1_DW.temporalCounter_i1 = 0U;
          Assignment1_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1_B.PACE_GND_CTRL = 1.0;
          Assignment1_B.ATR_PACE_CTRL = 1.0;
          Assignment1_B.ATR_GND_CTRL = 0.0;
          Assignment1_B.Z_ATR_CTRL = 0.0;
          Assignment1_B.Z_VENT_CTRL = 0.0;
          Assignment1_B.VENT_GND_CTRL = 0.0;
          Assignment1_B.VENT_PACE_CTRL = 0.0;
        }
      }
      break;

     case Assignment1_IN_VOO_discharge:
      Assignment1_B.PACE_GND_CTRL = 1.0;
      Assignment1_B.Z_ATR_CTRL = 0.0;
      Assignment1_B.Z_VENT_CTRL = 0.0;
      Assignment1_B.ATR_GND_CTRL = 0.0;
      Assignment1_B.VENT_GND_CTRL = 1.0;
      Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_CHARGING;
      Assignment1_DW.temporalCounter_i1 = 0U;
      Assignment1_B.ATR_PACE_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 0.0;
      Assignment1_B.PACE_CHARGE_CTRL = 1.0;
      Assignment1_B.FRONTEND_CTRL = 0.0;
      break;

     case Assignment1_IN_VVI:
      Assignment1_B.FRONTEND_CTRL = 1.0;
      if (rtb_DigitalRead1_0) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_VVI;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignment1_B.FRONTEND_CTRL = 1.0;
      } else {
        if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil(60.0 /
             Assignment1_P.Constant3_Value * 1000.0)) {
          Assignment1_DW.is_c3_Assignment1 = Assignmen_IN_Ventricular_Pacing;
          Assignment1_DW.temporalCounter_i1 = 0U;
          Assignment1_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1_B.PACE_GND_CTRL = 1.0;
          Assignment1_B.ATR_PACE_CTRL = 0.0;
          Assignment1_B.ATR_GND_CTRL = 0.0;
          Assignment1_B.Z_ATR_CTRL = 0.0;
          Assignment1_B.Z_VENT_CTRL = 0.0;
          Assignment1_B.VENT_GND_CTRL = 0.0;
          Assignment1_B.VENT_PACE_CTRL = 1.0;
        }
      }
      break;

     case Assignmen_IN_Ventricular_Pacing:
      Assignment1_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1_B.PACE_GND_CTRL = 1.0;
      Assignment1_B.ATR_PACE_CTRL = 0.0;
      Assignment1_B.ATR_GND_CTRL = 0.0;
      Assignment1_B.Z_ATR_CTRL = 0.0;
      Assignment1_B.Z_VENT_CTRL = 0.0;
      Assignment1_B.VENT_GND_CTRL = 0.0;
      Assignment1_B.VENT_PACE_CTRL = 1.0;
      if (Assignment1_DW.temporalCounter_i1 >= (uint32_T)ceil
          (Assignment1_P.ventricular_pulse_width_Value)) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_VOO_discharge;
        Assignment1_B.PACE_GND_CTRL = 1.0;
        Assignment1_B.VENT_PACE_CTRL = 0.0;
        Assignment1_B.Z_ATR_CTRL = 0.0;
        Assignment1_B.Z_VENT_CTRL = 0.0;
        Assignment1_B.ATR_PACE_CTRL = 0.0;
        Assignment1_B.ATR_GND_CTRL = 0.0;
        Assignment1_B.VENT_GND_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_delay: */
      if (Assignment1_P.mode_Value == 4.0) {
        Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_VVI;
        Assignment1_DW.temporalCounter_i1 = 0U;
        Assignment1_B.FRONTEND_CTRL = 1.0;
      } else {
        if (Assignment1_P.mode_Value == 3.0) {
          Assignment1_DW.is_c3_Assignment1 = Assignment1_IN_AAI;
          Assignment1_DW.temporalCounter_i1 = 0U;
          Assignment1_B.FRONTEND_CTRL = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(Assignment1_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Assignment1_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write1' */
  MW_digitalIO_write(Assignment1_DW.obj_p.MW_DIGITALIO_HANDLE,
                     Assignment1_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write2' */
  MW_digitalIO_write(Assignment1_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Assignment1_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write3' */
  MW_digitalIO_write(Assignment1_DW.obj_i.MW_DIGITALIO_HANDLE,
                     Assignment1_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write4' */
  MW_digitalIO_write(Assignment1_DW.obj_k.MW_DIGITALIO_HANDLE,
                     Assignment1_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write5' */
  MW_digitalIO_write(Assignment1_DW.obj_l1.MW_DIGITALIO_HANDLE,
                     Assignment1_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write6' */
  MW_digitalIO_write(Assignment1_DW.obj_o2.MW_DIGITALIO_HANDLE,
                     Assignment1_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write7' */
  MW_digitalIO_write(Assignment1_DW.obj_by.MW_DIGITALIO_HANDLE,
                     Assignment1_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write8' */
  MW_digitalIO_write(Assignment1_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Assignment1_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/PWM Output1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MW_PWM_SetDutyCycle(Assignment1_DW.obj_f.MW_PWM_HANDLE,
                      Assignment1_P.Constant_Value);

  /* MATLABSystem: '<S2>/PWM Output2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  MW_PWM_SetDutyCycle(Assignment1_DW.obj_pg.MW_PWM_HANDLE,
                      Assignment1_P.Constant1_Value);

  /* MATLABSystem: '<S2>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  MW_PWM_SetDutyCycle(Assignment1_DW.obj_je.MW_PWM_HANDLE,
                      Assignment1_P.Constant2_Value);

  /* MATLABSystem: '<S2>/Analog Input' */
  if (Assignment1_DW.obj.SampleTime != Assignment1_P.AnalogInput_SampleTime) {
    Assignment1_DW.obj.SampleTime = Assignment1_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj.MW_ANALOGIN_HANDLE, &tmp, 7);

  /* End of MATLABSystem: '<S2>/Analog Input' */

  /* MATLABSystem: '<S2>/Analog Input1' */
  if (Assignment1_DW.obj_c.SampleTime != Assignment1_P.AnalogInput1_SampleTime)
  {
    Assignment1_DW.obj_c.SampleTime = Assignment1_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj_c.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj_c.MW_ANALOGIN_HANDLE, &tmp, 7);

  /* End of MATLABSystem: '<S2>/Analog Input1' */

  /* MATLABSystem: '<S2>/Analog Input2' */
  if (Assignment1_DW.obj_o.SampleTime != Assignment1_P.AnalogInput2_SampleTime)
  {
    Assignment1_DW.obj_o.SampleTime = Assignment1_P.AnalogInput2_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj_o.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj_o.MW_ANALOGIN_HANDLE, &tmp, 7);

  /* End of MATLABSystem: '<S2>/Analog Input2' */

  /* MATLABSystem: '<S2>/Analog Input3' */
  if (Assignment1_DW.obj_j.SampleTime != Assignment1_P.AnalogInput3_SampleTime)
  {
    Assignment1_DW.obj_j.SampleTime = Assignment1_P.AnalogInput3_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj_j.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj_j.MW_ANALOGIN_HANDLE, &tmp, 7);

  /* End of MATLABSystem: '<S2>/Analog Input3' */

  /* MATLABSystem: '<S2>/Analog Input4' */
  if (Assignment1_DW.obj_b.SampleTime != Assignment1_P.AnalogInput4_SampleTime)
  {
    Assignment1_DW.obj_b.SampleTime = Assignment1_P.AnalogInput4_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1_DW.obj_b.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1_DW.obj_b.MW_ANALOGIN_HANDLE, &tmp, 7);

  /* End of MATLABSystem: '<S2>/Analog Input4' */

  /* MATLABSystem: '<Root>/Digital Write' */
  MW_digitalIO_write(Assignment1_DW.obj_e.MW_DIGITALIO_HANDLE, false);
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
    Assignment1_DW.obj_n.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_n.isInitialized = 0;
    Assignment1_DW.obj_n.SampleTime = -1.0;
    Assignment1_DW.obj_n.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_n.SampleTime = Assignment1_P.DigitalRead1_SampleTime;
    obj = &Assignment1_DW.obj_n;
    Assignment1_DW.obj_n.isSetupComplete = false;
    Assignment1_DW.obj_n.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment1_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Read' */
    Assignment1_DW.obj_cn.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_cn.isInitialized = 0;
    Assignment1_DW.obj_cn.SampleTime = -1.0;
    Assignment1_DW.obj_cn.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_cn.SampleTime = Assignment1_P.DigitalRead_SampleTime;
    obj = &Assignment1_DW.obj_cn;
    Assignment1_DW.obj_cn.isSetupComplete = false;
    Assignment1_DW.obj_cn.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment1_DW.obj_cn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    Assignment1_DW.obj_m.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_m.isInitialized = 0;
    Assignment1_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_m;
    Assignment1_DW.obj_m.isSetupComplete = false;
    Assignment1_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    Assignment1_DW.obj_p.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_p.isInitialized = 0;
    Assignment1_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_p;
    Assignment1_DW.obj_p.isSetupComplete = false;
    Assignment1_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write2' */
    Assignment1_DW.obj_l.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_l.isInitialized = 0;
    Assignment1_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_l;
    Assignment1_DW.obj_l.isSetupComplete = false;
    Assignment1_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write3' */
    Assignment1_DW.obj_i.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_i.isInitialized = 0;
    Assignment1_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_i;
    Assignment1_DW.obj_i.isSetupComplete = false;
    Assignment1_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write4' */
    Assignment1_DW.obj_k.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_k.isInitialized = 0;
    Assignment1_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_k;
    Assignment1_DW.obj_k.isSetupComplete = false;
    Assignment1_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write5' */
    Assignment1_DW.obj_l1.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_l1.isInitialized = 0;
    Assignment1_DW.obj_l1.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_l1;
    Assignment1_DW.obj_l1.isSetupComplete = false;
    Assignment1_DW.obj_l1.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1_DW.obj_l1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write6' */
    Assignment1_DW.obj_o2.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_o2.isInitialized = 0;
    Assignment1_DW.obj_o2.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_o2;
    Assignment1_DW.obj_o2.isSetupComplete = false;
    Assignment1_DW.obj_o2.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1_DW.obj_o2.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write7' */
    Assignment1_DW.obj_by.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_by.isInitialized = 0;
    Assignment1_DW.obj_by.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_by;
    Assignment1_DW.obj_by.isSetupComplete = false;
    Assignment1_DW.obj_by.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1_DW.obj_by.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write8' */
    Assignment1_DW.obj_h.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_h.isInitialized = 0;
    Assignment1_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_h;
    Assignment1_DW.obj_h.isSetupComplete = false;
    Assignment1_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment1_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output1' */
    Assignment1_DW.obj_f.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_f.isInitialized = 0;
    Assignment1_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_DW.obj_f;
    Assignment1_DW.obj_f.isSetupComplete = false;
    Assignment1_DW.obj_f.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_DW.obj_f.MW_PWM_HANDLE);
    Assignment1_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output2' */
    Assignment1_DW.obj_pg.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_pg.isInitialized = 0;
    Assignment1_DW.obj_pg.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_DW.obj_pg;
    Assignment1_DW.obj_pg.isSetupComplete = false;
    Assignment1_DW.obj_pg.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_DW.obj_pg.MW_PWM_HANDLE);
    Assignment1_DW.obj_pg.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    Assignment1_DW.obj_je.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_je.isInitialized = 0;
    Assignment1_DW.obj_je.matlabCodegenIsDeleted = false;
    obj_1 = &Assignment1_DW.obj_je;
    Assignment1_DW.obj_je.isSetupComplete = false;
    Assignment1_DW.obj_je.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1_DW.obj_je.MW_PWM_HANDLE);
    Assignment1_DW.obj_je.isSetupComplete = true;

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
    Assignment1_DW.obj_c.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_c.isInitialized = 0;
    Assignment1_DW.obj_c.SampleTime = -1.0;
    Assignment1_DW.obj_c.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_c.SampleTime = Assignment1_P.AnalogInput1_SampleTime;
    obj_2 = &Assignment1_DW.obj_c;
    Assignment1_DW.obj_c.isSetupComplete = false;
    Assignment1_DW.obj_c.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(19U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj_c.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input2' */
    Assignment1_DW.obj_o.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_o.isInitialized = 0;
    Assignment1_DW.obj_o.SampleTime = -1.0;
    Assignment1_DW.obj_o.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_o.SampleTime = Assignment1_P.AnalogInput2_SampleTime;
    obj_2 = &Assignment1_DW.obj_o;
    Assignment1_DW.obj_o.isSetupComplete = false;
    Assignment1_DW.obj_o.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(18U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj_o.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input3' */
    Assignment1_DW.obj_j.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_j.isInitialized = 0;
    Assignment1_DW.obj_j.SampleTime = -1.0;
    Assignment1_DW.obj_j.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_j.SampleTime = Assignment1_P.AnalogInput3_SampleTime;
    obj_2 = &Assignment1_DW.obj_j;
    Assignment1_DW.obj_j.isSetupComplete = false;
    Assignment1_DW.obj_j.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj_j.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Analog Input4' */
    Assignment1_DW.obj_b.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_b.isInitialized = 0;
    Assignment1_DW.obj_b.SampleTime = -1.0;
    Assignment1_DW.obj_b.matlabCodegenIsDeleted = false;
    Assignment1_DW.obj_b.SampleTime = Assignment1_P.AnalogInput4_SampleTime;
    obj_2 = &Assignment1_DW.obj_b;
    Assignment1_DW.obj_b.isSetupComplete = false;
    Assignment1_DW.obj_b.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1_DW.obj_b.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Assignment1_DW.obj_b.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Write' */
    Assignment1_DW.obj_e.matlabCodegenIsDeleted = true;
    Assignment1_DW.obj_e.isInitialized = 0;
    Assignment1_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &Assignment1_DW.obj_e;
    Assignment1_DW.obj_e.isSetupComplete = false;
    Assignment1_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Assignment1_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Digital Read1' */
  Assignment1_matlabCodegenHa_ep(&Assignment1_DW.obj_n);

  /* Terminate for MATLABSystem: '<S2>/Digital Read' */
  Assignment1_matlabCodegenHa_ep(&Assignment1_DW.obj_cn);

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_m);

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_p);

  /* Terminate for MATLABSystem: '<S2>/Digital Write2' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_l);

  /* Terminate for MATLABSystem: '<S2>/Digital Write3' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_i);

  /* Terminate for MATLABSystem: '<S2>/Digital Write4' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_k);

  /* Terminate for MATLABSystem: '<S2>/Digital Write5' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_l1);

  /* Terminate for MATLABSystem: '<S2>/Digital Write6' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_o2);

  /* Terminate for MATLABSystem: '<S2>/Digital Write7' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_by);

  /* Terminate for MATLABSystem: '<S2>/Digital Write8' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_h);

  /* Terminate for MATLABSystem: '<S2>/PWM Output1' */
  matlabCodegenHandle_matl_j3b1we(&Assignment1_DW.obj_f);

  /* Terminate for MATLABSystem: '<S2>/PWM Output2' */
  matlabCodegenHandle_matl_j3b1we(&Assignment1_DW.obj_pg);

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  matlabCodegenHandle_matl_j3b1we(&Assignment1_DW.obj_je);

  /* Terminate for MATLABSystem: '<S2>/Analog Input' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/Analog Input1' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_c);

  /* Terminate for MATLABSystem: '<S2>/Analog Input2' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_o);

  /* Terminate for MATLABSystem: '<S2>/Analog Input3' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_j);

  /* Terminate for MATLABSystem: '<S2>/Analog Input4' */
  matlabCodegenHandle_matlabCod_j(&Assignment1_DW.obj_b);

  /* Terminate for MATLABSystem: '<Root>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&Assignment1_DW.obj_e);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
