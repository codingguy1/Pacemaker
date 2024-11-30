/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1and2.c
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

#include "Assignment1and2.h"
#include "Assignment1and2_private.h"

/* Named constants for Chart: '<Root>/Main State Flowchart' */
#define Assignmen_IN_Ventricular_Pacing ((uint8_T)2U)
#define Assignment1a_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Assignment1and2_IN_AAI         ((uint8_T)1U)
#define Assignment1and2_IN_AAIR        ((uint8_T)2U)
#define Assignment1and2_IN_AOO         ((uint8_T)3U)
#define Assignment1and2_IN_AOOR        ((uint8_T)4U)
#define Assignment1and2_IN_AOOR_Charge ((uint8_T)1U)
#define Assignment1and2_IN_AOO_Charge  ((uint8_T)1U)
#define Assignment1and2_IN_OFF         ((uint8_T)5U)
#define Assignment1and2_IN_VOO         ((uint8_T)6U)
#define Assignment1and2_IN_VOOR        ((uint8_T)7U)
#define Assignment1and2_IN_VOOR_Charge ((uint8_T)1U)
#define Assignment1and2_IN_VOO_Charge  ((uint8_T)1U)
#define Assignment1and2_IN_VVI         ((uint8_T)8U)
#define Assignment1and2_IN_VVIR        ((uint8_T)9U)
#define Assignment1and2_IN_VVI_Charge  ((uint8_T)1U)
#define Assignment1and2_IN_delay       ((uint8_T)3U)
#define Assignment1and2_IN_sense       ((uint8_T)5U)
#define Assignment1and_IN_Atrial_Pacing ((uint8_T)2U)
#define Assignment1and_IN_inhibited_ARP ((uint8_T)4U)
#define Assignment1and_IN_inhibited_VRP ((uint8_T)4U)

/* Named constants for Chart: '<S5>/Adaptive Rate FSM' */
#define Assignm_IN_Reached_dessire_rate ((uint8_T)4U)
#define Assignment1and2_IN_Decrease    ((uint8_T)1U)
#define Assignment1and2_IN_Increase    ((uint8_T)2U)
#define Assignment1and2_IN_Init        ((uint8_T)3U)
#define Assignment1and_IN_wait_decrease ((uint8_T)5U)
#define Assignment1and_IN_wait_increase ((uint8_T)6U)

/* Named constants for Chart: '<Root>/Serial Communication' */
#define Assignment1and2_IN_ECHO_PARAM  ((uint8_T)1U)
#define Assignment1and2_IN_INITIAL     ((uint8_T)2U)
#define Assignment1and2_IN_SET_PARAM   ((uint8_T)3U)
#define Assignment1and2_IN_STANDBY     ((uint8_T)4U)

/* Block signals (default storage) */
B_Assignment1and2_T Assignment1and2_B;

/* Block states (default storage) */
DW_Assignment1and2_T Assignment1and2_DW;

/* Real-time model */
RT_MODEL_Assignment1and2_T Assignment1and2_M_;
RT_MODEL_Assignment1and2_T *const Assignment1and2_M = &Assignment1and2_M_;

/* Forward declaration for local functions */
static void Assign_enter_atomic_AOOR_Charge(void);
static void Assignment1and2_AAI(void);
static void Assignment1and2_AAIR(void);
static void Assignment1and2_AOO(void);
static void Assignment1and2_AOOR(void);
static void Assign_enter_atomic_VOOR_Charge(void);
static void Assignment1and2_OFF(void);
static void Assignment1and2_VOO(void);
static void Assignment1and2_VOOR(void);
static void Assignment_SystemCore_release_n(const
  freedomk64f_SCIRead_Assignmen_T *obj);
static void Assignment1_SystemCore_delete_n(const
  freedomk64f_SCIRead_Assignmen_T *obj);
static void matlabCodegenHandle_matlabCod_n(freedomk64f_SCIRead_Assignmen_T *obj);
static void Assignm_SystemCore_release_nebn(const
  freedomk64f_AnalogInput_Assig_T *obj);
static void Assignme_SystemCore_delete_nebn(const
  freedomk64f_AnalogInput_Assig_T *obj);
static void matlabCodegenHandle_matlab_nebn(freedomk64f_AnalogInput_Assig_T *obj);
static void Assignmen_SystemCore_release_ne(const
  freedomk64f_DigitalRead_Assig_T *obj);
static void Assignment_SystemCore_delete_ne(const
  freedomk64f_DigitalRead_Assig_T *obj);
static void matlabCodegenHandle_matlabCo_ne(freedomk64f_DigitalRead_Assig_T *obj);
static void A_SystemCore_rele_a(const freedomk64f_fxos8700_Assignme_T *obj);
static void A_SystemCore_dele_a(const freedomk64f_fxos8700_Assignme_T *obj);
static void Assignment1an_matlabCodegenHa_a(freedomk64f_fxos8700_Assignme_T *obj);
static void A_SystemCore_rele_lr(b_freedomk64f_I2CMasterWrite__T *obj);
static void A_SystemCore_dele_lr(b_freedomk64f_I2CMasterWrite__T *obj);
static void Assignment1a_matlabCodegenHa_lr(b_freedomk64f_I2CMasterWrite__T *obj);
static void A_SystemCore_rele_i(dsp_simulink_MovingAverage_As_T *obj);
static void A_SystemCore_dele_i(dsp_simulink_MovingAverage_As_T *obj);
static void Assignment1an_matlabCodegenHa_i(dsp_simulink_MovingAverage_As_T *obj);
static void As_SystemCore_release_nebna4py5(const
  freedomk64f_DigitalWrite_Assi_T *obj);
static void Ass_SystemCore_delete_nebna4py5(const
  freedomk64f_DigitalWrite_Assi_T *obj);
static void matlabCodegenHandle_m_nebna4py5(freedomk64f_DigitalWrite_Assi_T *obj);
static void Assig_SystemCore_release_nebna4(const
  freedomk64f_PWMOutput_Assignm_T *obj);
static void Assign_SystemCore_delete_nebna4(const
  freedomk64f_PWMOutput_Assignm_T *obj);
static void matlabCodegenHandle_matl_nebna4(freedomk64f_PWMOutput_Assignm_T *obj);
static void Assignment1a_SystemCore_setup_n(freedomk64f_SCIRead_Assignmen_T *obj);
static void Assignment1_SystemCore_setup_ne(freedomk64f_fxos8700_Assignme_T *obj);

/*
 * Output and update for atomic system:
 *    '<S4>/ARP Limiter'
 *    '<S4>/VRP Limiter'
 */
void Assignment1and2_ARPLimiter(real32_T rtu_u, real32_T *rty_y)
{
  *rty_y = rtu_u;
  if (rtu_u > 500.0F) {
    *rty_y = 500.0F;
  } else {
    if (rtu_u < 150.0F) {
      *rty_y = 0.0F;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S4>/Atri_Amp Calculator'
 *    '<S4>/Vent_Amp Calculator'
 */
void Assignment1a_Atri_AmpCalculator(real32_T rtu_u, real32_T *rty_y)
{
  *rty_y = rtu_u / 5.0F * 100.0F;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Atri_Amp Limiter'
 *    '<S4>/Vent_Amp Limiter'
 */
void Assignment1and2_Atri_AmpLimiter(real32_T rtu_u, real32_T *rty_y)
{
  *rty_y = rtu_u;
  if (rtu_u >= 5.0F) {
    *rty_y = 5.0F;
  } else {
    if (rtu_u < 0.5F) {
      *rty_y = 0.0F;
    }
  }
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assign_enter_atomic_AOOR_Charge(void)
{
  Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
  Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
  Assignment1and2_B.PACE_GND_CTRL = 1.0;
  Assignment1and2_B.ATR_PACE_CTRL = 0.0;
  Assignment1and2_B.ATR_GND_CTRL = 1.0;
  Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  Assignment1and2_B.VENT_GND_CTRL = 0.0;
  Assignment1and2_B.Z_ATR_CTRL = 0.0;
  Assignment1and2_B.Z_VENT_CTRL = 0.0;
  Assignment1and2_B.FRONTEND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assignment1and2_AAI(void)
{
  if (Assignment1and2_B.y_g != 3) {
    Assignment1and2_DW.is_AAI = Assignment1a_IN_NO_ACTIVE_CHILD;
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  } else {
    switch (Assignment1and2_DW.is_AAI) {
     case Assignment1and2_IN_AOO_Charge:
      Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
      Assignment1and2_B.PACE_GND_CTRL = 1.0;
      Assignment1and2_B.ATR_PACE_CTRL = 0.0;
      Assignment1and2_B.ATR_GND_CTRL = 1.0;
      Assignment1and2_B.VENT_PACE_CTRL = 0.0;
      Assignment1and2_B.VENT_GND_CTRL = 0.0;
      Assignment1and2_B.Z_ATR_CTRL = 0.0;
      Assignment1and2_B.Z_VENT_CTRL = 0.0;
      Assignment1and2_B.FRONTEND_CTRL = 0.0;
      Assignment1and2_DW.is_AAI = Assignment1and_IN_inhibited_ARP;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      break;

     case Assignment1and_IN_Atrial_Pacing:
      Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1and2_B.PACE_GND_CTRL = 1.0;
      Assignment1and2_B.ATR_PACE_CTRL = 1.0;
      Assignment1and2_B.ATR_GND_CTRL = 0.0;
      Assignment1and2_B.VENT_PACE_CTRL = 0.0;
      Assignment1and2_B.VENT_GND_CTRL = 0.0;
      Assignment1and2_B.Z_ATR_CTRL = 0.0;
      Assignment1and2_B.Z_VENT_CTRL = 0.0;
      if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_b) {
        Assignment1and2_DW.is_AAI = Assignment1and2_IN_AOO_Charge;
        Assign_enter_atomic_AOOR_Charge();
      }
      break;

     case Assignment1and2_IN_delay:
      if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_lk) {
        Assignment1and2_DW.is_AAI = Assignment1and2_IN_sense;
        Assignment1and2_DW.temporalCounter_i1_g = 0U;
        Assignment1and2_B.FRONTEND_CTRL = 1.0;
      }
      break;

     case Assignment1and_IN_inhibited_ARP:
      if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_lk) {
        Assignment1and2_DW.is_AAI = Assignment1and2_IN_sense;
        Assignment1and2_DW.temporalCounter_i1_g = 0U;
        Assignment1and2_B.FRONTEND_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_sense: */
      Assignment1and2_B.FRONTEND_CTRL = 1.0;
      if (Assignment1and2_B.ATR_CMP_DETECT) {
        Assignment1and2_DW.is_AAI = Assignment1and2_IN_delay;
        Assignment1and2_DW.temporalCounter_i1_g = 0U;
      } else {
        if ((Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_l0 -
             Assignment1and2_B.y_lk) && (!Assignment1and2_B.ATR_CMP_DETECT)) {
          Assignment1and2_DW.is_AAI = Assignment1and_IN_Atrial_Pacing;
          Assignment1and2_DW.temporalCounter_i1_g = 0U;
          Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
          Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1and2_B.PACE_GND_CTRL = 1.0;
          Assignment1and2_B.ATR_PACE_CTRL = 1.0;
          Assignment1and2_B.ATR_GND_CTRL = 0.0;
          Assignment1and2_B.VENT_PACE_CTRL = 0.0;
          Assignment1and2_B.VENT_GND_CTRL = 0.0;
          Assignment1and2_B.Z_ATR_CTRL = 0.0;
          Assignment1and2_B.Z_VENT_CTRL = 0.0;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assignment1and2_AAIR(void)
{
  if (Assignment1and2_B.y_g != 7) {
    Assignment1and2_DW.is_AAIR = Assignment1a_IN_NO_ACTIVE_CHILD;
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  } else {
    switch (Assignment1and2_DW.is_AAIR) {
     case Assignment1and2_IN_AOO_Charge:
      Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
      Assignment1and2_B.PACE_GND_CTRL = 1.0;
      Assignment1and2_B.ATR_PACE_CTRL = 0.0;
      Assignment1and2_B.ATR_GND_CTRL = 1.0;
      Assignment1and2_B.VENT_PACE_CTRL = 0.0;
      Assignment1and2_B.VENT_GND_CTRL = 0.0;
      Assignment1and2_B.Z_ATR_CTRL = 0.0;
      Assignment1and2_B.Z_VENT_CTRL = 0.0;
      Assignment1and2_B.FRONTEND_CTRL = 0.0;
      Assignment1and2_DW.is_AAIR = Assignment1and_IN_inhibited_ARP;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      break;

     case Assignment1and_IN_Atrial_Pacing:
      Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1and2_B.PACE_GND_CTRL = 1.0;
      Assignment1and2_B.ATR_PACE_CTRL = 1.0;
      Assignment1and2_B.ATR_GND_CTRL = 0.0;
      Assignment1and2_B.VENT_PACE_CTRL = 0.0;
      Assignment1and2_B.VENT_GND_CTRL = 0.0;
      Assignment1and2_B.Z_ATR_CTRL = 0.0;
      Assignment1and2_B.Z_VENT_CTRL = 0.0;
      if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_b) {
        Assignment1and2_DW.is_AAIR = Assignment1and2_IN_AOO_Charge;
        Assign_enter_atomic_AOOR_Charge();
      }
      break;

     case Assignment1and2_IN_delay:
      if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_lk) {
        Assignment1and2_DW.is_AAIR = Assignment1and2_IN_sense;
        Assignment1and2_DW.temporalCounter_i1_g = 0U;
        Assignment1and2_B.FRONTEND_CTRL = 1.0;
      }
      break;

     case Assignment1and_IN_inhibited_ARP:
      if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_lk) {
        Assignment1and2_DW.is_AAIR = Assignment1and2_IN_sense;
        Assignment1and2_DW.temporalCounter_i1_g = 0U;
        Assignment1and2_B.FRONTEND_CTRL = 1.0;
      }
      break;

     default:
      /* case IN_sense: */
      Assignment1and2_B.FRONTEND_CTRL = 1.0;
      if (Assignment1and2_B.ATR_CMP_DETECT) {
        Assignment1and2_DW.is_AAIR = Assignment1and2_IN_delay;
        Assignment1and2_DW.temporalCounter_i1_g = 0U;
      } else {
        if ((Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y -
             Assignment1and2_B.y_lk) && (!Assignment1and2_B.ATR_CMP_DETECT)) {
          Assignment1and2_DW.is_AAIR = Assignment1and_IN_Atrial_Pacing;
          Assignment1and2_DW.temporalCounter_i1_g = 0U;
          Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
          Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1and2_B.PACE_GND_CTRL = 1.0;
          Assignment1and2_B.ATR_PACE_CTRL = 1.0;
          Assignment1and2_B.ATR_GND_CTRL = 0.0;
          Assignment1and2_B.VENT_PACE_CTRL = 0.0;
          Assignment1and2_B.VENT_GND_CTRL = 0.0;
          Assignment1and2_B.Z_ATR_CTRL = 0.0;
          Assignment1and2_B.Z_VENT_CTRL = 0.0;
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assignment1and2_AOO(void)
{
  if (Assignment1and2_B.y_g != 1) {
    Assignment1and2_DW.is_AOO = Assignment1a_IN_NO_ACTIVE_CHILD;
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  } else if (Assignment1and2_DW.is_AOO == Assignment1and2_IN_AOO_Charge) {
    Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.ATR_GND_CTRL = 1.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_GND_CTRL = 0.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    Assignment1and2_B.FRONTEND_CTRL = 0.0;
    if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_l0 -
        Assignment1and2_B.y_b) {
      Assignment1and2_DW.is_AOO = Assignment1and_IN_Atrial_Pacing;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
      Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1and2_B.PACE_GND_CTRL = 1.0;
      Assignment1and2_B.ATR_PACE_CTRL = 1.0;
      Assignment1and2_B.ATR_GND_CTRL = 0.0;
      Assignment1and2_B.VENT_PACE_CTRL = 0.0;
      Assignment1and2_B.VENT_GND_CTRL = 0.0;
      Assignment1and2_B.Z_ATR_CTRL = 0.0;
      Assignment1and2_B.Z_VENT_CTRL = 0.0;
    }
  } else {
    /* case IN_Atrial_Pacing: */
    Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 1.0;
    Assignment1and2_B.ATR_GND_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_GND_CTRL = 0.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_b) {
      Assignment1and2_DW.is_AOO = Assignment1and2_IN_AOO_Charge;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      Assign_enter_atomic_AOOR_Charge();
    }
  }
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assignment1and2_AOOR(void)
{
  if (Assignment1and2_B.y_g != 5) {
    Assignment1and2_DW.is_AOOR = Assignment1a_IN_NO_ACTIVE_CHILD;
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  } else if (Assignment1and2_DW.is_AOOR == Assignment1and2_IN_AOOR_Charge) {
    Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.ATR_GND_CTRL = 1.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_GND_CTRL = 0.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    Assignment1and2_B.FRONTEND_CTRL = 0.0;
    if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y -
        Assignment1and2_B.y_b) {
      Assignment1and2_DW.is_AOOR = Assignment1and_IN_Atrial_Pacing;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
      Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1and2_B.PACE_GND_CTRL = 1.0;
      Assignment1and2_B.ATR_PACE_CTRL = 1.0;
      Assignment1and2_B.ATR_GND_CTRL = 0.0;
      Assignment1and2_B.VENT_PACE_CTRL = 0.0;
      Assignment1and2_B.VENT_GND_CTRL = 0.0;
      Assignment1and2_B.Z_ATR_CTRL = 0.0;
      Assignment1and2_B.Z_VENT_CTRL = 0.0;
    }
  } else {
    /* case IN_Atrial_Pacing: */
    Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 1.0;
    Assignment1and2_B.ATR_GND_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_GND_CTRL = 0.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_b) {
      Assignment1and2_DW.is_AOOR = Assignment1and2_IN_AOOR_Charge;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      Assign_enter_atomic_AOOR_Charge();
    }
  }
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assign_enter_atomic_VOOR_Charge(void)
{
  Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
  Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
  Assignment1and2_B.PACE_GND_CTRL = 1.0;
  Assignment1and2_B.ATR_PACE_CTRL = 0.0;
  Assignment1and2_B.ATR_GND_CTRL = 0.0;
  Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  Assignment1and2_B.VENT_GND_CTRL = 1.0;
  Assignment1and2_B.Z_ATR_CTRL = 0.0;
  Assignment1and2_B.Z_VENT_CTRL = 0.0;
  Assignment1and2_B.FRONTEND_CTRL = 0.0;
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assignment1and2_OFF(void)
{
  Assignment1and2_B.ATR_PACE_CTRL = 0.0;
  Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  switch (Assignment1and2_B.y_g) {
   case 3:
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_AAI;
    Assignment1and2_DW.is_AAI = Assignment1and2_IN_AOO_Charge;
    Assign_enter_atomic_AOOR_Charge();
    break;

   case 1:
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_AOO;
    Assignment1and2_DW.is_AOO = Assignment1and2_IN_AOO_Charge;
    Assignment1and2_DW.temporalCounter_i1_g = 0U;
    Assign_enter_atomic_AOOR_Charge();
    break;

   case 4:
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_VVI;
    Assignment1and2_DW.is_VVI = Assignment1and2_IN_VVI_Charge;
    Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
    Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.ATR_GND_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_GND_CTRL = 1.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    break;

   case 2:
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_VOO;
    Assignment1and2_DW.is_VOO = Assignment1and2_IN_VOO_Charge;
    Assignment1and2_DW.temporalCounter_i1_g = 0U;
    Assign_enter_atomic_VOOR_Charge();
    break;

   case 5:
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_AOOR;
    Assignment1and2_DW.is_AOOR = Assignment1and2_IN_AOOR_Charge;
    Assignment1and2_DW.temporalCounter_i1_g = 0U;
    Assign_enter_atomic_AOOR_Charge();
    break;

   case 6:
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_VOOR;
    Assignment1and2_DW.is_VOOR = Assignment1and2_IN_VOOR_Charge;
    Assignment1and2_DW.temporalCounter_i1_g = 0U;
    Assign_enter_atomic_VOOR_Charge();
    break;

   case 7:
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_AAIR;
    Assignment1and2_DW.is_AAIR = Assignment1and2_IN_AOO_Charge;
    Assign_enter_atomic_AOOR_Charge();
    break;

   case 8:
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_VVIR;
    Assignment1and2_DW.is_VVIR = Assignment1and2_IN_VVI_Charge;
    Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
    Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.ATR_GND_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_GND_CTRL = 1.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    break;
  }
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assignment1and2_VOO(void)
{
  if (Assignment1and2_B.y_g != 2) {
    Assignment1and2_DW.is_VOO = Assignment1a_IN_NO_ACTIVE_CHILD;
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  } else if (Assignment1and2_DW.is_VOO == Assignment1and2_IN_VOO_Charge) {
    Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.ATR_GND_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_GND_CTRL = 1.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    Assignment1and2_B.FRONTEND_CTRL = 0.0;
    if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_l0 -
        Assignment1and2_B.y_d) {
      Assignment1and2_DW.is_VOO = Assignmen_IN_Ventricular_Pacing;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
      Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1and2_B.PACE_GND_CTRL = 1.0;
      Assignment1and2_B.ATR_PACE_CTRL = 0.0;
      Assignment1and2_B.ATR_GND_CTRL = 0.0;
      Assignment1and2_B.Z_ATR_CTRL = 0.0;
      Assignment1and2_B.Z_VENT_CTRL = 0.0;
      Assignment1and2_B.VENT_PACE_CTRL = 1.0;
      Assignment1and2_B.VENT_GND_CTRL = 0.0;
    }
  } else {
    /* case IN_Ventricular_Pacing: */
    Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.ATR_GND_CTRL = 0.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 1.0;
    Assignment1and2_B.VENT_GND_CTRL = 0.0;
    if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_d) {
      Assignment1and2_DW.is_VOO = Assignment1and2_IN_VOO_Charge;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      Assign_enter_atomic_VOOR_Charge();
    }
  }
}

/* Function for Chart: '<Root>/Main State Flowchart' */
static void Assignment1and2_VOOR(void)
{
  if (Assignment1and2_B.y_g != 6) {
    Assignment1and2_DW.is_VOOR = Assignment1a_IN_NO_ACTIVE_CHILD;
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  } else if (Assignment1and2_DW.is_VOOR == Assignment1and2_IN_VOOR_Charge) {
    Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.ATR_GND_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_GND_CTRL = 1.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    Assignment1and2_B.FRONTEND_CTRL = 0.0;
    if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y -
        Assignment1and2_B.y_d) {
      Assignment1and2_DW.is_VOOR = Assignmen_IN_Ventricular_Pacing;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
      Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
      Assignment1and2_B.PACE_GND_CTRL = 1.0;
      Assignment1and2_B.ATR_PACE_CTRL = 0.0;
      Assignment1and2_B.ATR_GND_CTRL = 0.0;
      Assignment1and2_B.Z_ATR_CTRL = 0.0;
      Assignment1and2_B.Z_VENT_CTRL = 0.0;
      Assignment1and2_B.VENT_PACE_CTRL = 1.0;
      Assignment1and2_B.VENT_GND_CTRL = 0.0;
    }
  } else {
    /* case IN_Ventricular_Pacing: */
    Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
    Assignment1and2_B.PACE_GND_CTRL = 1.0;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.ATR_GND_CTRL = 0.0;
    Assignment1and2_B.Z_ATR_CTRL = 0.0;
    Assignment1and2_B.Z_VENT_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 1.0;
    Assignment1and2_B.VENT_GND_CTRL = 0.0;
    if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_d) {
      Assignment1and2_DW.is_VOOR = Assignment1and2_IN_VOOR_Charge;
      Assignment1and2_DW.temporalCounter_i1_g = 0U;
      Assign_enter_atomic_VOOR_Charge();
    }
  }
}

static void Assignment_SystemCore_release_n(const
  freedomk64f_SCIRead_Assignmen_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Assignment1_SystemCore_delete_n(const
  freedomk64f_SCIRead_Assignmen_T *obj)
{
  Assignment_SystemCore_release_n(obj);
}

static void matlabCodegenHandle_matlabCod_n(freedomk64f_SCIRead_Assignmen_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignment1_SystemCore_delete_n(obj);
  }
}

static void Assignm_SystemCore_release_nebn(const
  freedomk64f_AnalogInput_Assig_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_AnalogIn_Stop(obj->MW_ANALOGIN_HANDLE);
    MW_AnalogIn_Close(obj->MW_ANALOGIN_HANDLE);
  }
}

static void Assignme_SystemCore_delete_nebn(const
  freedomk64f_AnalogInput_Assig_T *obj)
{
  Assignm_SystemCore_release_nebn(obj);
}

static void matlabCodegenHandle_matlab_nebn(freedomk64f_AnalogInput_Assig_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignme_SystemCore_delete_nebn(obj);
  }
}

static void Assignmen_SystemCore_release_ne(const
  freedomk64f_DigitalRead_Assig_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Assignment_SystemCore_delete_ne(const
  freedomk64f_DigitalRead_Assig_T *obj)
{
  Assignmen_SystemCore_release_ne(obj);
}

static void matlabCodegenHandle_matlabCo_ne(freedomk64f_DigitalRead_Assig_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignment_SystemCore_delete_ne(obj);
  }
}

static void A_SystemCore_rele_a(const freedomk64f_fxos8700_Assignme_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->i2cobj.MW_I2C_HANDLE);
  }
}

static void A_SystemCore_dele_a(const freedomk64f_fxos8700_Assignme_T *obj)
{
  A_SystemCore_rele_a(obj);
}

static void Assignment1an_matlabCodegenHa_a(freedomk64f_fxos8700_Assignme_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    A_SystemCore_dele_a(obj);
  }
}

static void A_SystemCore_rele_lr(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }
}

static void A_SystemCore_dele_lr(b_freedomk64f_I2CMasterWrite__T *obj)
{
  A_SystemCore_rele_lr(obj);
}

static void Assignment1a_matlabCodegenHa_lr(b_freedomk64f_I2CMasterWrite__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    A_SystemCore_dele_lr(obj);
  }
}

static void A_SystemCore_rele_i(dsp_simulink_MovingAverage_As_T *obj)
{
  g_dsp_private_SlidingWindowAv_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void A_SystemCore_dele_i(dsp_simulink_MovingAverage_As_T *obj)
{
  A_SystemCore_rele_i(obj);
}

static void Assignment1an_matlabCodegenHa_i(dsp_simulink_MovingAverage_As_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    A_SystemCore_dele_i(obj);
  }
}

static void As_SystemCore_release_nebna4py5(const
  freedomk64f_DigitalWrite_Assi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void Ass_SystemCore_delete_nebna4py5(const
  freedomk64f_DigitalWrite_Assi_T *obj)
{
  As_SystemCore_release_nebna4py5(obj);
}

static void matlabCodegenHandle_m_nebna4py5(freedomk64f_DigitalWrite_Assi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Ass_SystemCore_delete_nebna4py5(obj);
  }
}

static void Assig_SystemCore_release_nebna4(const
  freedomk64f_PWMOutput_Assignm_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_PWM_Stop(obj->MW_PWM_HANDLE);
    MW_PWM_Close(obj->MW_PWM_HANDLE);
  }
}

static void Assign_SystemCore_delete_nebna4(const
  freedomk64f_PWMOutput_Assignm_T *obj)
{
  Assig_SystemCore_release_nebna4(obj);
}

static void matlabCodegenHandle_matl_nebna4(freedomk64f_PWMOutput_Assignm_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assign_SystemCore_delete_nebna4(obj);
  }
}

static void Assignment1a_SystemCore_setup_n(freedomk64f_SCIRead_Assignmen_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Assignment1and2_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Assignment1and2_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Assignment1and2_B.SCIModuleLoc, false, 10U,
    Assignment1and2_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Assignment1and2_B.StopBitsValue = MW_SCI_STOPBITS_1;
  Assignment1and2_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, Assignment1and2_B.ParityValue,
                        Assignment1and2_B.StopBitsValue);
  obj->isSetupComplete = true;
}

static void Assignment1_SystemCore_setup_ne(freedomk64f_fxos8700_Assignme_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Assignment1and2_B.ModeType = MW_I2C_MASTER;
  Assignment1and2_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(Assignment1and2_B.i2cname,
    Assignment1and2_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  Assignment1and2_B.b_SwappedDataBytes[0] = 43U;
  Assignment1and2_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Assignment1and2_B.b_SwappedDataBytes, 2U, false, false);
  OSA_TimeDelay(500U);
  Assignment1and2_B.status = 42U;
  Assignment1and2_B.status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
    &Assignment1and2_B.status, 1U, true, false);
  if (0 == Assignment1and2_B.status) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &Assignment1and2_B.status,
                      1U, false, true);
    memcpy((void *)&Assignment1and2_B.b_RegisterValue, (void *)
           &Assignment1and2_B.status, (uint32_T)((size_t)1 * sizeof(uint8_T)));
  } else {
    Assignment1and2_B.b_RegisterValue = 0U;
  }

  Assignment1and2_B.b_SwappedDataBytes[0] = 42U;
  Assignment1and2_B.b_SwappedDataBytes[1] = (uint8_T)
    (Assignment1and2_B.b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Assignment1and2_B.b_SwappedDataBytes, 2U, false, false);
  Assignment1and2_B.b_SwappedDataBytes[0] = 14U;
  Assignment1and2_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Assignment1and2_B.b_SwappedDataBytes, 2U, false, false);
  Assignment1and2_B.b_SwappedDataBytes[0] = 91U;
  Assignment1and2_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Assignment1and2_B.b_SwappedDataBytes, 2U, false, false);
  Assignment1and2_B.b_SwappedDataBytes[0] = 42U;
  Assignment1and2_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     Assignment1and2_B.b_SwappedDataBytes, 2U, false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void Assignment1and2_step(void)
{
  int16_T b_output[3];
  uint8_T status;
  uint8_T output_raw[6];
  uint8_T y[2];
  uint8_T b_x[2];
  real_T cumRevIndex;
  real_T csum;
  real_T z;
  real_T rtb_SquareRoot;
  real32_T rtb_Add1;
  real32_T rtb_Min;
  int32_T z_tmp;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Assignment1and2_DW.obj_j.SampleTime !=
      Assignment1and2_P.SerialReceive_SampleTime) {
    Assignment1and2_DW.obj_j.SampleTime =
      Assignment1and2_P.SerialReceive_SampleTime;
  }

  Assignment1and2_B.SerialReceive_o2 = MW_SCI_Receive
    (Assignment1and2_DW.obj_j.MW_SCIHANDLE, Assignment1and2_B.RxDataLocChar, 11U);
  memcpy((void *)&Assignment1and2_B.SerialReceive_o1[0], (void *)
         &Assignment1and2_B.RxDataLocChar[0], (uint32_T)((size_t)11 * sizeof
          (uint8_T)));

  /* End of MATLABSystem: '<Root>/Serial Receive' */

  /* MATLABSystem: '<S1>/AtrSignalIn' */
  if (Assignment1and2_DW.obj_oo.SampleTime !=
      Assignment1and2_P.AtrSignalIn_SampleTime) {
    Assignment1and2_DW.obj_oo.SampleTime =
      Assignment1and2_P.AtrSignalIn_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1and2_DW.obj_oo.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1and2_DW.obj_oo.MW_ANALOGIN_HANDLE,
    &rtb_SquareRoot, 7);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  MATLABSystem: '<S1>/AtrSignalIn'
   */
  Assignment1and2_B.DataTypeConversion = (real32_T)rtb_SquareRoot;

  /* MATLABSystem: '<S1>/VentSignalIn' */
  if (Assignment1and2_DW.obj_ok.SampleTime !=
      Assignment1and2_P.VentSignalIn_SampleTime) {
    Assignment1and2_DW.obj_ok.SampleTime =
      Assignment1and2_P.VentSignalIn_SampleTime;
  }

  MW_AnalogIn_Start(Assignment1and2_DW.obj_ok.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(Assignment1and2_DW.obj_ok.MW_ANALOGIN_HANDLE,
    &rtb_SquareRoot, 7);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  MATLABSystem: '<S1>/VentSignalIn'
   */
  Assignment1and2_B.DataTypeConversion1 = (real32_T)rtb_SquareRoot;

  /* Chart: '<Root>/Serial Communication' */
  switch (Assignment1and2_DW.is_c12_Assignment1and2) {
   case Assignment1and2_IN_ECHO_PARAM:
    Assignment1and2_DW.is_c12_Assignment1and2 = Assignment1and2_IN_STANDBY;
    break;

   case Assignment1and2_IN_INITIAL:
    Assignment1and2_DW.is_c12_Assignment1and2 = Assignment1and2_IN_STANDBY;
    break;

   case Assignment1and2_IN_SET_PARAM:
    Assignment1and2_DW.is_c12_Assignment1and2 = Assignment1and2_IN_STANDBY;
    break;

   default:
    /* case IN_STANDBY: */
    if (Assignment1and2_B.SerialReceive_o2 == 0) {
      if (Assignment1and2_B.SerialReceive_o1[0] == 22) {
        switch (Assignment1and2_B.SerialReceive_o1[1]) {
         case 85:
          Assignment1and2_DW.is_c12_Assignment1and2 =
            Assignment1and2_IN_SET_PARAM;
          memcpy((void *)&Assignment1and2_B.Mode, (void *)
                 &Assignment1and2_B.SerialReceive_o1[2], (uint32_T)((size_t)1 *
                  sizeof(uint8_T)));
          memcpy((void *)&Assignment1and2_B.lower_rate_limit_f, (void *)
                 &Assignment1and2_B.SerialReceive_o1[3], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.upper_rate_limit_b, (void *)
                 &Assignment1and2_B.SerialReceive_o1[7], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.maximum_sensor_rate_p, (void *)
                 &Assignment1and2_B.SerialReceive_o1[11], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.atrial_amplitude_o, (void *)
                 &Assignment1and2_B.SerialReceive_o1[15], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.ventricular_amplitude_g, (void *)
                 &Assignment1and2_B.SerialReceive_o1[19], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.atrial_pulse_width_f, (void *)
                 &Assignment1and2_B.SerialReceive_o1[23], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.ventricular_pulse_width_n, (void *)
                 &Assignment1and2_B.SerialReceive_o1[27], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.atrial_sensitivity_k, (void *)
                 &Assignment1and2_B.SerialReceive_o1[31], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.ventricular_sensitivity_c, (void *)
                 &Assignment1and2_B.SerialReceive_o1[35], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.ARP_o, (void *)
                 &Assignment1and2_B.SerialReceive_o1[39], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.VRP_g, (void *)
                 &Assignment1and2_B.SerialReceive_o1[43], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.PVARP_l, (void *)
                 &Assignment1and2_B.SerialReceive_o1[47], (uint32_T)((size_t)1 *
                  sizeof(uint16_T)));
          memcpy((void *)&Assignment1and2_B.activity_threshold_m, (void *)
                 &Assignment1and2_B.SerialReceive_o1[49], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.reaction_time_k, (void *)
                 &Assignment1and2_B.SerialReceive_o1[53], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.response_factor_c, (void *)
                 &Assignment1and2_B.SerialReceive_o1[57], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          memcpy((void *)&Assignment1and2_B.recovery_time_e, (void *)
                 &Assignment1and2_B.SerialReceive_o1[61], (uint32_T)((size_t)1 *
                  sizeof(real32_T)));
          break;

         case 34:
          Assignment1and2_DW.is_c12_Assignment1and2 =
            Assignment1and2_IN_ECHO_PARAM;
          send_params();
          break;

         default:
          Assignment1and2_DW.is_c12_Assignment1and2 = Assignment1and2_IN_STANDBY;
          break;
        }
      } else {
        Assignment1and2_DW.is_c12_Assignment1and2 = Assignment1and2_IN_STANDBY;
      }
    }
    break;
  }

  /* End of Chart: '<Root>/Serial Communication' */

  /* MATLAB Function: '<S4>/Mode Limiter' */
  Assignment1and2_B.y_g = Assignment1and2_B.Mode;
  if (Assignment1and2_B.Mode > 6) {
    Assignment1and2_B.y_g = 0U;
  } else {
    if (Assignment1and2_B.Mode < 1) {
      Assignment1and2_B.y_g = 0U;
    }
  }

  /* End of MATLAB Function: '<S4>/Mode Limiter' */

  /* MATLAB Function: '<S4>/LRL Limiter' */
  rtb_Add1 = Assignment1and2_B.lower_rate_limit_f;
  if (Assignment1and2_B.lower_rate_limit_f > 175.0F) {
    rtb_Add1 = 350.0F;
  } else {
    if (Assignment1and2_B.lower_rate_limit_f < 30.0F) {
      rtb_Add1 = 60.0F;
    }
  }

  Assignment1and2_B.y_nn = 2.0F * rtb_Add1;

  /* End of MATLAB Function: '<S4>/LRL Limiter' */

  /* MATLAB Function: '<S4>/LRI Function' */
  Assignment1and2_B.y_l0 = 60000.0F / Assignment1and2_B.y_nn;

  /* MATLAB Function: '<S4>/URL Limiter' */
  rtb_Add1 = Assignment1and2_B.upper_rate_limit_b;
  if (Assignment1and2_B.upper_rate_limit_b > 175.0F) {
    rtb_Add1 = 350.0F;
  } else {
    if (Assignment1and2_B.upper_rate_limit_b < 50.0F) {
      rtb_Add1 = 100.0F;
    }
  }

  Assignment1and2_B.y_n = 2.0F * rtb_Add1;

  /* End of MATLAB Function: '<S4>/URL Limiter' */

  /* MATLAB Function: '<S4>/URL Function' */
  Assignment1and2_B.y_i = 60000.0F / Assignment1and2_B.y_n;

  /* MATLAB Function: '<S4>/Atri_Amp Limiter' */
  Assignment1and2_Atri_AmpLimiter(Assignment1and2_B.atrial_amplitude_o,
    &rtb_Add1);

  /* MATLAB Function: '<S4>/Atri_Amp Calculator' */
  Assignment1a_Atri_AmpCalculator(rtb_Add1, &Assignment1and2_B.y_id);

  /* MATLAB Function: '<S4>/Vent_Amp Limiter' */
  Assignment1and2_Atri_AmpLimiter(Assignment1and2_B.ventricular_amplitude_g,
    &rtb_Add1);

  /* MATLAB Function: '<S4>/Vent_Amp Calculator' */
  Assignment1a_Atri_AmpCalculator(rtb_Add1, &Assignment1and2_B.y_l);

  /* MATLAB Function: '<S4>/APW Limiter' */
  Assignment1and2_B.y_b = Assignment1and2_B.atrial_pulse_width_f;
  if (Assignment1and2_B.atrial_pulse_width_f >= 20.0F) {
    Assignment1and2_B.y_b = 20.0F;
  } else {
    if (Assignment1and2_B.atrial_pulse_width_f <= 0.0F) {
      Assignment1and2_B.y_b = 0.0F;
    }
  }

  /* End of MATLAB Function: '<S4>/APW Limiter' */

  /* MATLAB Function: '<S4>/VPW Limiter' */
  Assignment1and2_B.y_d = Assignment1and2_B.ventricular_pulse_width_n;
  if (Assignment1and2_B.ventricular_pulse_width_n >= 20.0F) {
    Assignment1and2_B.y_d = 20.0F;
  } else {
    if (Assignment1and2_B.ventricular_pulse_width_n <= 0.0F) {
      Assignment1and2_B.y_d = 0.0F;
    }
  }

  /* End of MATLAB Function: '<S4>/VPW Limiter' */

  /* MATLAB Function: '<S4>/ARP Limiter' */
  Assignment1and2_ARPLimiter(Assignment1and2_B.ARP_o, &Assignment1and2_B.y_lk);

  /* MATLAB Function: '<S4>/VRP Limiter' */
  Assignment1and2_ARPLimiter(Assignment1and2_B.VRP_g, &Assignment1and2_B.y_c);

  /* MATLABSystem: '<S1>/VENT_CMP_DETECT' */
  if (Assignment1and2_DW.obj_p.SampleTime !=
      Assignment1and2_P.VENT_CMP_DETECT_SampleTime) {
    Assignment1and2_DW.obj_p.SampleTime =
      Assignment1and2_P.VENT_CMP_DETECT_SampleTime;
  }

  Assignment1and2_B.VENT_CMP_DETECT = MW_digitalIO_read
    (Assignment1and2_DW.obj_p.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/VENT_CMP_DETECT' */

  /* MATLABSystem: '<S1>/ATR_CMP_DETECT' */
  if (Assignment1and2_DW.obj_d.SampleTime !=
      Assignment1and2_P.ATR_CMP_DETECT_SampleTime) {
    Assignment1and2_DW.obj_d.SampleTime =
      Assignment1and2_P.ATR_CMP_DETECT_SampleTime;
  }

  Assignment1and2_B.ATR_CMP_DETECT = MW_digitalIO_read
    (Assignment1and2_DW.obj_d.MW_DIGITALIO_HANDLE);

  /* End of MATLABSystem: '<S1>/ATR_CMP_DETECT' */

  /* Gain: '<S5>/Multiply' */
  rtb_Add1 = (real32_T)Assignment1and2_P.Multiply_Gain *
    Assignment1and2_B.response_factor_c;

  /* MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
  if (Assignment1and2_DW.obj_o.SampleTime !=
      Assignment1and2_P.FXOS87006AxesSensor_SampleTime) {
    Assignment1and2_DW.obj_o.SampleTime =
      Assignment1and2_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(Assignment1and2_DW.obj_o.i2cobj.MW_I2C_HANDLE, 29U,
    &status, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(Assignment1and2_DW.obj_o.i2cobj.MW_I2C_HANDLE, 29U,
                      output_raw, 6U, false, true);
    memcpy((void *)&b_output[0], (void *)&output_raw[0], (uint32_T)((size_t)3 *
            sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[0], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[0], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[1], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[1], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
    memcpy((void *)&y[0], (void *)&b_output[2], (uint32_T)((size_t)2 * sizeof
            (uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_output[2], (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
  } else {
    b_output[0] = 0;
    b_output[1] = 0;
    b_output[2] = 0;
  }

  Assignment1and2_B.FXOS87006AxesSensor[0] = (real_T)(int16_T)(b_output[0] >> 2)
    * 2.0 * 0.244 / 1000.0;
  Assignment1and2_B.FXOS87006AxesSensor[1] = (real_T)(int16_T)(b_output[1] >> 2)
    * 2.0 * 0.244 / 1000.0;
  Assignment1and2_B.FXOS87006AxesSensor[2] = (real_T)(int16_T)(b_output[2] >> 2)
    * 2.0 * 0.244 / 1000.0;

  /* End of MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */

  /* Sqrt: '<S5>/Square Root' incorporates:
   *  Math: '<S5>/Magnitude Squared'
   *  Math: '<S5>/Magnitude Squared1'
   *  Math: '<S5>/Magnitude Squared2'
   *  Sum: '<S5>/Add'
   *
   * About '<S5>/Magnitude Squared':
   *  Operator: magnitude^2
   *
   * About '<S5>/Magnitude Squared1':
   *  Operator: magnitude^2
   *
   * About '<S5>/Magnitude Squared2':
   *  Operator: magnitude^2
   */
  rtb_SquareRoot = sqrt((Assignment1and2_B.FXOS87006AxesSensor[0] *
    Assignment1and2_B.FXOS87006AxesSensor[0] +
    Assignment1and2_B.FXOS87006AxesSensor[1] *
    Assignment1and2_B.FXOS87006AxesSensor[1]) +
                        Assignment1and2_B.FXOS87006AxesSensor[2] *
                        Assignment1and2_B.FXOS87006AxesSensor[2]);

  /* MATLABSystem: '<S5>/Moving Average' */
  if (Assignment1and2_DW.obj.TunablePropsChanged) {
    Assignment1and2_DW.obj.TunablePropsChanged = false;
  }

  if (Assignment1and2_DW.obj.pStatistic->isInitialized != 1) {
    Assignment1and2_DW.obj.pStatistic->isSetupComplete = false;
    Assignment1and2_DW.obj.pStatistic->isInitialized = 1;
    Assignment1and2_DW.obj.pStatistic->pCumSum = 0.0;
    Assignment1and2_DW.obj.pStatistic->pCumRevIndex = 1.0;
    Assignment1and2_DW.obj.pStatistic->isSetupComplete = true;
    Assignment1and2_DW.obj.pStatistic->pCumSum = 0.0;
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    Assignment1and2_DW.obj.pStatistic->pCumRevIndex = 1.0;
  }

  cumRevIndex = Assignment1and2_DW.obj.pStatistic->pCumRevIndex;
  csum = Assignment1and2_DW.obj.pStatistic->pCumSum;
  Assignment1and2_B.FXOS87006AxesSensor[0] =
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[0];
  Assignment1and2_B.FXOS87006AxesSensor[1] =
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[1];
  Assignment1and2_B.FXOS87006AxesSensor[2] =
    Assignment1and2_DW.obj.pStatistic->pCumSumRev[2];
  csum += rtb_SquareRoot;
  z_tmp = (int32_T)cumRevIndex - 1;
  z = Assignment1and2_B.FXOS87006AxesSensor[z_tmp] + csum;
  Assignment1and2_B.FXOS87006AxesSensor[z_tmp] = rtb_SquareRoot;
  if (cumRevIndex != 3.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    Assignment1and2_B.FXOS87006AxesSensor[1] +=
      Assignment1and2_B.FXOS87006AxesSensor[2];
    Assignment1and2_B.FXOS87006AxesSensor[0] +=
      Assignment1and2_B.FXOS87006AxesSensor[1];
  }

  Assignment1and2_DW.obj.pStatistic->pCumSum = csum;
  Assignment1and2_DW.obj.pStatistic->pCumSumRev[0] =
    Assignment1and2_B.FXOS87006AxesSensor[0];
  Assignment1and2_DW.obj.pStatistic->pCumSumRev[1] =
    Assignment1and2_B.FXOS87006AxesSensor[1];
  Assignment1and2_DW.obj.pStatistic->pCumSumRev[2] =
    Assignment1and2_B.FXOS87006AxesSensor[2];
  Assignment1and2_DW.obj.pStatistic->pCumRevIndex = cumRevIndex;
  rtb_SquareRoot = z / 4.0;

  /* End of MATLABSystem: '<S5>/Moving Average' */

  /* Sum: '<S5>/Add1' */
  rtb_Min = rtb_Add1 + Assignment1and2_B.y_nn;

  /* MinMax: '<S5>/Min' */
  if ((!(rtb_Min < Assignment1and2_B.maximum_sensor_rate_p)) && (!rtIsNaNF
       (Assignment1and2_B.maximum_sensor_rate_p))) {
    rtb_Min = Assignment1and2_B.maximum_sensor_rate_p;
  }

  /* End of MinMax: '<S5>/Min' */

  /* Chart: '<S5>/Adaptive Rate FSM' */
  if (Assignment1and2_DW.temporalCounter_i1 < MAX_uint32_T) {
    Assignment1and2_DW.temporalCounter_i1++;
  }

  if (Assignment1and2_DW.is_active_c13_Assignment1and2 == 0U) {
    Assignment1and2_DW.is_active_c13_Assignment1and2 = 1U;
    Assignment1and2_DW.is_c13_Assignment1and2 = Assignment1and2_IN_Init;
    Assignment1and2_B.adaptive_rate = Assignment1and2_B.y_nn;
    Assignment1and2_B.red_out = 0.0;
    Assignment1and2_B.green_out = 0.0;
    Assignment1and2_B.blue_out = 1.0;
  } else {
    switch (Assignment1and2_DW.is_c13_Assignment1and2) {
     case Assignment1and2_IN_Decrease:
      if ((Assignment1and2_B.adaptive_rate <= Assignment1and2_B.y_nn) &&
          (rtb_SquareRoot <= Assignment1and2_B.activity_threshold_m)) {
        Assignment1and2_DW.is_c13_Assignment1and2 = Assignment1and2_IN_Init;
        Assignment1and2_B.adaptive_rate = Assignment1and2_B.y_nn;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 1.0;
      } else if ((Assignment1and2_B.adaptive_rate > Assignment1and2_B.y_nn) &&
                 (rtb_SquareRoot <= Assignment1and2_B.activity_threshold_m)) {
        Assignment1and2_DW.is_c13_Assignment1and2 =
          Assignment1and_IN_wait_decrease;
        Assignment1and2_DW.temporalCounter_i1 = 0U;
      } else if (rtb_SquareRoot > Assignment1and2_B.activity_threshold_m) {
        Assignment1and2_DW.is_c13_Assignment1and2 = Assignment1and2_IN_Increase;
        Assignment1and2_B.adaptive_rate += rtb_Add1 / 1000.0F;
        Assignment1and2_B.red_out = 1.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 0.0;
      } else {
        Assignment1and2_B.adaptive_rate -= rtb_Add1 / 1000.0F;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 1.0;
        Assignment1and2_B.blue_out = 0.0;
      }
      break;

     case Assignment1and2_IN_Increase:
      if (Assignment1and2_B.adaptive_rate < rtb_Min) {
        Assignment1and2_DW.is_c13_Assignment1and2 =
          Assignment1and_IN_wait_increase;
        Assignment1and2_DW.temporalCounter_i1 = 0U;
      } else if (Assignment1and2_B.adaptive_rate >= rtb_Min) {
        Assignment1and2_DW.is_c13_Assignment1and2 =
          Assignm_IN_Reached_dessire_rate;
        Assignment1and2_B.adaptive_rate = rtb_Min;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 1.0;
      } else {
        Assignment1and2_B.adaptive_rate += rtb_Add1 / 1000.0F;
        Assignment1and2_B.red_out = 1.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 0.0;
      }
      break;

     case Assignment1and2_IN_Init:
      if (rtb_SquareRoot > Assignment1and2_B.activity_threshold_m) {
        Assignment1and2_DW.is_c13_Assignment1and2 = Assignment1and2_IN_Increase;
        Assignment1and2_B.adaptive_rate += rtb_Add1 / 1000.0F;
        Assignment1and2_B.red_out = 1.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 0.0;
      } else if (rtb_SquareRoot <= Assignment1and2_B.activity_threshold_m) {
        Assignment1and2_DW.is_c13_Assignment1and2 = Assignment1and2_IN_Init;
        Assignment1and2_B.adaptive_rate = Assignment1and2_B.y_nn;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 1.0;
      } else {
        Assignment1and2_B.adaptive_rate = Assignment1and2_B.y_nn;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 1.0;
      }
      break;

     case Assignm_IN_Reached_dessire_rate:
      if (rtb_SquareRoot > Assignment1and2_B.activity_threshold_m) {
        Assignment1and2_DW.is_c13_Assignment1and2 =
          Assignm_IN_Reached_dessire_rate;
        Assignment1and2_B.adaptive_rate = rtb_Min;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 1.0;
      } else if (rtb_SquareRoot <= Assignment1and2_B.activity_threshold_m) {
        Assignment1and2_DW.is_c13_Assignment1and2 = Assignment1and2_IN_Decrease;
        Assignment1and2_B.adaptive_rate -= rtb_Add1 / 1000.0F;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 1.0;
        Assignment1and2_B.blue_out = 0.0;
      } else {
        Assignment1and2_B.adaptive_rate = rtb_Min;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 1.0;
      }
      break;

     case Assignment1and_IN_wait_decrease:
      if (Assignment1and2_DW.temporalCounter_i1 >=
          Assignment1and2_B.recovery_time_e) {
        Assignment1and2_DW.is_c13_Assignment1and2 = Assignment1and2_IN_Decrease;
        Assignment1and2_B.adaptive_rate -= rtb_Add1 / 1000.0F;
        Assignment1and2_B.red_out = 0.0;
        Assignment1and2_B.green_out = 1.0;
        Assignment1and2_B.blue_out = 0.0;
      }
      break;

     default:
      /* case IN_wait_increase: */
      if (Assignment1and2_DW.temporalCounter_i1 >=
          Assignment1and2_B.reaction_time_k) {
        Assignment1and2_DW.is_c13_Assignment1and2 = Assignment1and2_IN_Increase;
        Assignment1and2_B.adaptive_rate += rtb_Add1 / 1000.0F;
        Assignment1and2_B.red_out = 1.0;
        Assignment1and2_B.green_out = 0.0;
        Assignment1and2_B.blue_out = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Adaptive Rate FSM' */

  /* MATLAB Function: '<S5>/interval converter' */
  Assignment1and2_B.y = 60000.0F / Assignment1and2_B.adaptive_rate;

  /* Chart: '<Root>/Main State Flowchart' */
  if (Assignment1and2_DW.temporalCounter_i1_g < MAX_uint32_T) {
    Assignment1and2_DW.temporalCounter_i1_g++;
  }

  if (Assignment1and2_DW.is_active_c3_Assignment1and2 == 0U) {
    Assignment1and2_DW.is_active_c3_Assignment1and2 = 1U;
    Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
    Assignment1and2_B.ATR_PACE_CTRL = 0.0;
    Assignment1and2_B.VENT_PACE_CTRL = 0.0;
  } else {
    switch (Assignment1and2_DW.is_c3_Assignment1and2) {
     case Assignment1and2_IN_AAI:
      Assignment1and2_AAI();
      break;

     case Assignment1and2_IN_AAIR:
      Assignment1and2_AAIR();
      break;

     case Assignment1and2_IN_AOO:
      Assignment1and2_AOO();
      break;

     case Assignment1and2_IN_AOOR:
      Assignment1and2_AOOR();
      break;

     case Assignment1and2_IN_OFF:
      Assignment1and2_OFF();
      break;

     case Assignment1and2_IN_VOO:
      Assignment1and2_VOO();
      break;

     case Assignment1and2_IN_VOOR:
      Assignment1and2_VOOR();
      break;

     case Assignment1and2_IN_VVI:
      if (Assignment1and2_B.y_g != 4) {
        Assignment1and2_DW.is_VVI = Assignment1a_IN_NO_ACTIVE_CHILD;
        Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
        Assignment1and2_B.ATR_PACE_CTRL = 0.0;
        Assignment1and2_B.VENT_PACE_CTRL = 0.0;
      } else {
        switch (Assignment1and2_DW.is_VVI) {
         case Assignment1and2_IN_VVI_Charge:
          Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
          Assignment1and2_B.PACE_GND_CTRL = 1.0;
          Assignment1and2_B.ATR_PACE_CTRL = 0.0;
          Assignment1and2_B.ATR_GND_CTRL = 0.0;
          Assignment1and2_B.VENT_PACE_CTRL = 0.0;
          Assignment1and2_B.VENT_GND_CTRL = 1.0;
          Assignment1and2_B.Z_ATR_CTRL = 0.0;
          Assignment1and2_B.Z_VENT_CTRL = 0.0;
          Assignment1and2_DW.is_VVI = Assignment1and_IN_inhibited_VRP;
          Assignment1and2_DW.temporalCounter_i1_g = 0U;
          break;

         case Assignmen_IN_Ventricular_Pacing:
          Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1and2_B.PACE_GND_CTRL = 1.0;
          Assignment1and2_B.ATR_PACE_CTRL = 0.0;
          Assignment1and2_B.ATR_GND_CTRL = 0.0;
          Assignment1and2_B.Z_ATR_CTRL = 0.0;
          Assignment1and2_B.Z_VENT_CTRL = 0.0;
          Assignment1and2_B.VENT_PACE_CTRL = 1.0;
          Assignment1and2_B.VENT_GND_CTRL = 0.0;
          if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_d)
          {
            Assignment1and2_DW.is_VVI = Assignment1and2_IN_VVI_Charge;
            Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
            Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
            Assignment1and2_B.PACE_GND_CTRL = 1.0;
            Assignment1and2_B.ATR_PACE_CTRL = 0.0;
            Assignment1and2_B.ATR_GND_CTRL = 0.0;
            Assignment1and2_B.VENT_PACE_CTRL = 0.0;
            Assignment1and2_B.VENT_GND_CTRL = 1.0;
            Assignment1and2_B.Z_ATR_CTRL = 0.0;
            Assignment1and2_B.Z_VENT_CTRL = 0.0;
          }
          break;

         case Assignment1and2_IN_delay:
          if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_c -
              Assignment1and2_B.y_d) {
            Assignment1and2_DW.is_VVI = Assignment1and2_IN_sense;
            Assignment1and2_DW.temporalCounter_i1_g = 0U;
            Assignment1and2_B.FRONTEND_CTRL = 1.0;
          }
          break;

         case Assignment1and_IN_inhibited_VRP:
          if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_c -
              Assignment1and2_B.y_d) {
            Assignment1and2_DW.is_VVI = Assignment1and2_IN_sense;
            Assignment1and2_DW.temporalCounter_i1_g = 0U;
            Assignment1and2_B.FRONTEND_CTRL = 1.0;
          }
          break;

         default:
          /* case IN_sense: */
          Assignment1and2_B.FRONTEND_CTRL = 1.0;
          if (Assignment1and2_B.VENT_CMP_DETECT) {
            Assignment1and2_DW.is_VVI = Assignment1and2_IN_delay;
            Assignment1and2_DW.temporalCounter_i1_g = 0U;
          } else {
            if ((Assignment1and2_DW.temporalCounter_i1_g >=
                 Assignment1and2_B.y_l0 - Assignment1and2_B.y_c) &&
                (!Assignment1and2_B.VENT_CMP_DETECT)) {
              Assignment1and2_DW.is_VVI = Assignmen_IN_Ventricular_Pacing;
              Assignment1and2_DW.temporalCounter_i1_g = 0U;
              Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
              Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
              Assignment1and2_B.PACE_GND_CTRL = 1.0;
              Assignment1and2_B.ATR_PACE_CTRL = 0.0;
              Assignment1and2_B.ATR_GND_CTRL = 0.0;
              Assignment1and2_B.Z_ATR_CTRL = 0.0;
              Assignment1and2_B.Z_VENT_CTRL = 0.0;
              Assignment1and2_B.VENT_PACE_CTRL = 1.0;
              Assignment1and2_B.VENT_GND_CTRL = 0.0;
            }
          }
          break;
        }
      }
      break;

     default:
      /* case IN_VVIR: */
      if (Assignment1and2_B.y_g != 8) {
        Assignment1and2_DW.is_VVIR = Assignment1a_IN_NO_ACTIVE_CHILD;
        Assignment1and2_DW.is_c3_Assignment1and2 = Assignment1and2_IN_OFF;
        Assignment1and2_B.ATR_PACE_CTRL = 0.0;
        Assignment1and2_B.VENT_PACE_CTRL = 0.0;
      } else {
        switch (Assignment1and2_DW.is_VVIR) {
         case Assignment1and2_IN_VVI_Charge:
          Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
          Assignment1and2_B.PACE_GND_CTRL = 1.0;
          Assignment1and2_B.ATR_PACE_CTRL = 0.0;
          Assignment1and2_B.ATR_GND_CTRL = 0.0;
          Assignment1and2_B.VENT_PACE_CTRL = 0.0;
          Assignment1and2_B.VENT_GND_CTRL = 1.0;
          Assignment1and2_B.Z_ATR_CTRL = 0.0;
          Assignment1and2_B.Z_VENT_CTRL = 0.0;
          Assignment1and2_DW.is_VVIR = Assignment1and_IN_inhibited_VRP;
          Assignment1and2_DW.temporalCounter_i1_g = 0U;
          break;

         case Assignmen_IN_Ventricular_Pacing:
          Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
          Assignment1and2_B.PACE_GND_CTRL = 1.0;
          Assignment1and2_B.ATR_PACE_CTRL = 0.0;
          Assignment1and2_B.ATR_GND_CTRL = 0.0;
          Assignment1and2_B.Z_ATR_CTRL = 0.0;
          Assignment1and2_B.Z_VENT_CTRL = 0.0;
          Assignment1and2_B.VENT_PACE_CTRL = 1.0;
          Assignment1and2_B.VENT_GND_CTRL = 0.0;
          if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_d)
          {
            Assignment1and2_DW.is_VVIR = Assignment1and2_IN_VVI_Charge;
            Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
            Assignment1and2_B.PACE_CHARGE_CTRL = 1.0;
            Assignment1and2_B.PACE_GND_CTRL = 1.0;
            Assignment1and2_B.ATR_PACE_CTRL = 0.0;
            Assignment1and2_B.ATR_GND_CTRL = 0.0;
            Assignment1and2_B.VENT_PACE_CTRL = 0.0;
            Assignment1and2_B.VENT_GND_CTRL = 1.0;
            Assignment1and2_B.Z_ATR_CTRL = 0.0;
            Assignment1and2_B.Z_VENT_CTRL = 0.0;
          }
          break;

         case Assignment1and2_IN_delay:
          if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_c -
              Assignment1and2_B.y_d) {
            Assignment1and2_DW.is_VVIR = Assignment1and2_IN_sense;
            Assignment1and2_DW.temporalCounter_i1_g = 0U;
            Assignment1and2_B.FRONTEND_CTRL = 1.0;
          }
          break;

         case Assignment1and_IN_inhibited_VRP:
          if (Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y_c -
              Assignment1and2_B.y_d) {
            Assignment1and2_DW.is_VVIR = Assignment1and2_IN_sense;
            Assignment1and2_DW.temporalCounter_i1_g = 0U;
            Assignment1and2_B.FRONTEND_CTRL = 1.0;
          }
          break;

         default:
          /* case IN_sense: */
          Assignment1and2_B.FRONTEND_CTRL = 1.0;
          if (Assignment1and2_B.VENT_CMP_DETECT) {
            Assignment1and2_DW.is_VVIR = Assignment1and2_IN_delay;
            Assignment1and2_DW.temporalCounter_i1_g = 0U;
          } else {
            if ((Assignment1and2_DW.temporalCounter_i1_g >= Assignment1and2_B.y
                 - Assignment1and2_B.y_c) && (!Assignment1and2_B.VENT_CMP_DETECT))
            {
              Assignment1and2_DW.is_VVIR = Assignmen_IN_Ventricular_Pacing;
              Assignment1and2_DW.temporalCounter_i1_g = 0U;
              Assignment1and2_B.PACING_REF_PWM = Assignment1and2_B.y_id;
              Assignment1and2_B.PACE_CHARGE_CTRL = 0.0;
              Assignment1and2_B.PACE_GND_CTRL = 1.0;
              Assignment1and2_B.ATR_PACE_CTRL = 0.0;
              Assignment1and2_B.ATR_GND_CTRL = 0.0;
              Assignment1and2_B.Z_ATR_CTRL = 0.0;
              Assignment1and2_B.Z_VENT_CTRL = 0.0;
              Assignment1and2_B.VENT_PACE_CTRL = 1.0;
              Assignment1and2_B.VENT_GND_CTRL = 0.0;
            }
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Main State Flowchart' */

  /* MATLABSystem: '<S2>/Digital Write' */
  MW_digitalIO_write(Assignment1and2_DW.obj_f.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.PACE_CHARGE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write4' */
  MW_digitalIO_write(Assignment1and2_DW.obj_c.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.VENT_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write3' */
  MW_digitalIO_write(Assignment1and2_DW.obj_e.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.ATR_PACE_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write6' */
  MW_digitalIO_write(Assignment1and2_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.ATR_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write5' */
  MW_digitalIO_write(Assignment1and2_DW.obj_bj.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.VENT_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write7' */
  MW_digitalIO_write(Assignment1and2_DW.obj_pd.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.PACE_GND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write2' */
  MW_digitalIO_write(Assignment1and2_DW.obj_il.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.Z_VENT_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write1' */
  MW_digitalIO_write(Assignment1and2_DW.obj_ey.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.Z_ATR_CTRL != 0.0);

  /* MATLABSystem: '<S2>/Digital Write8' */
  MW_digitalIO_write(Assignment1and2_DW.obj_i4.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.FRONTEND_CTRL != 0.0);

  /* MATLABSystem: '<S2>/PWM Output1' */
  MW_PWM_SetDutyCycle(Assignment1and2_DW.obj_pv.MW_PWM_HANDLE, (real_T)
                      Assignment1and2_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/PWM Output' */
  MW_PWM_SetDutyCycle(Assignment1and2_DW.obj_k.MW_PWM_HANDLE, (real_T)
                      Assignment1and2_B.atrial_sensitivity_k);

  /* MATLABSystem: '<S2>/PWM Output2' */
  MW_PWM_SetDutyCycle(Assignment1and2_DW.obj_a.MW_PWM_HANDLE, (real_T)
                      Assignment1and2_B.ventricular_sensitivity_c);

  /* MATLABSystem: '<S5>/Digital Write1' */
  MW_digitalIO_write(Assignment1and2_DW.obj_i.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.green_out != 0.0);

  /* MATLABSystem: '<S5>/Digital Write2' */
  MW_digitalIO_write(Assignment1and2_DW.obj_h.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.red_out != 0.0);

  /* MATLABSystem: '<S5>/Digital Write3' */
  MW_digitalIO_write(Assignment1and2_DW.obj_b.MW_DIGITALIO_HANDLE,
                     Assignment1and2_B.blue_out != 0.0);
}

/* Model initialize function */
void Assignment1and2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    freedomk64f_AnalogInput_Assig_T *obj;
    freedomk64f_DigitalRead_Assig_T *obj_0;
    freedomk64f_fxos8700_Assignme_T *obj_1;
    freedomk64f_DigitalWrite_Assi_T *obj_2;
    freedomk64f_PWMOutput_Assignm_T *obj_3;

    /* Chart: '<Root>/Serial Communication' */
    Assignment1and2_DW.is_c12_Assignment1and2 = Assignment1and2_IN_INITIAL;
    Assignment1and2_B.Mode = 5U;
    Assignment1and2_B.lower_rate_limit_f = 30.0F;
    Assignment1and2_B.upper_rate_limit_b = 120.0F;
    Assignment1and2_B.maximum_sensor_rate_p = 120.0F;
    Assignment1and2_B.atrial_amplitude_o = 3.5F;
    Assignment1and2_B.ventricular_amplitude_g = 3.5F;
    Assignment1and2_B.atrial_pulse_width_f = 20.0F;
    Assignment1and2_B.ventricular_pulse_width_n = 20.0F;
    Assignment1and2_B.atrial_sensitivity_k = 0.75F;
    Assignment1and2_B.ventricular_sensitivity_c = 2.5F;
    Assignment1and2_B.ARP_o = 250.0F;
    Assignment1and2_B.VRP_g = 320.0F;
    Assignment1and2_B.PVARP_l = 250U;
    Assignment1and2_B.activity_threshold_m = 1.6F;
    Assignment1and2_B.reaction_time_k = 1.0F;
    Assignment1and2_B.response_factor_c = 80.0F;
    Assignment1and2_B.recovery_time_e = 300.0F;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Send Parameters' incorporates:
     *  SubSystem: '<Root>/Send Parameters'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Send Parameters' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Assignment1and2_DW.obj_j.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_j.SampleTime = -1.0;
    Assignment1and2_DW.obj_j.isInitialized = 0;
    Assignment1and2_DW.obj_j.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_mc = true;
    Assignment1and2_DW.obj_j.SampleTime =
      Assignment1and2_P.SerialReceive_SampleTime;
    Assignment1a_SystemCore_setup_n(&Assignment1and2_DW.obj_j);

    /* Start for MATLABSystem: '<S1>/AtrSignalIn' */
    Assignment1and2_DW.obj_oo.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_oo.isInitialized = 0;
    Assignment1and2_DW.obj_oo.SampleTime = -1.0;
    Assignment1and2_DW.obj_oo.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_ap = true;
    Assignment1and2_DW.obj_oo.SampleTime =
      Assignment1and2_P.AtrSignalIn_SampleTime;
    obj = &Assignment1and2_DW.obj_oo;
    Assignment1and2_DW.obj_oo.isSetupComplete = false;
    Assignment1and2_DW.obj_oo.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    Assignment1and2_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1and2_DW.obj_oo.MW_ANALOGIN_HANDLE,
      Assignment1and2_B.trigger_val, 0U);
    Assignment1and2_DW.obj_oo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VentSignalIn' */
    Assignment1and2_DW.obj_ok.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_ok.isInitialized = 0;
    Assignment1and2_DW.obj_ok.SampleTime = -1.0;
    Assignment1and2_DW.obj_ok.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_fv = true;
    Assignment1and2_DW.obj_ok.SampleTime =
      Assignment1and2_P.VentSignalIn_SampleTime;
    obj = &Assignment1and2_DW.obj_ok;
    Assignment1and2_DW.obj_ok.isSetupComplete = false;
    Assignment1and2_DW.obj_ok.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    Assignment1and2_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Assignment1and2_DW.obj_ok.MW_ANALOGIN_HANDLE,
      Assignment1and2_B.trigger_val, 0U);
    Assignment1and2_DW.obj_ok.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_CMP_DETECT' */
    Assignment1and2_DW.obj_p.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_p.isInitialized = 0;
    Assignment1and2_DW.obj_p.SampleTime = -1.0;
    Assignment1and2_DW.obj_p.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_lk = true;
    Assignment1and2_DW.obj_p.SampleTime =
      Assignment1and2_P.VENT_CMP_DETECT_SampleTime;
    obj_0 = &Assignment1and2_DW.obj_p;
    Assignment1and2_DW.obj_p.isSetupComplete = false;
    Assignment1and2_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Assignment1and2_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/ATR_CMP_DETECT' */
    Assignment1and2_DW.obj_d.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_d.isInitialized = 0;
    Assignment1and2_DW.obj_d.SampleTime = -1.0;
    Assignment1and2_DW.obj_d.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_lf = true;
    Assignment1and2_DW.obj_d.SampleTime =
      Assignment1and2_P.ATR_CMP_DETECT_SampleTime;
    obj_0 = &Assignment1and2_DW.obj_d;
    Assignment1and2_DW.obj_d.isSetupComplete = false;
    Assignment1and2_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Assignment1and2_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
    Assignment1and2_DW.obj_o.i2cobj.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_o.matlabCodegenIsDeleted = true;
    obj_1 = &Assignment1and2_DW.obj_o;
    Assignment1and2_DW.obj_o.isInitialized = 0;
    Assignment1and2_DW.obj_o.SampleTime = -1.0;
    obj_1->i2cobj.isInitialized = 0;
    obj_1->i2cobj.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.obj_o.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_d = true;
    Assignment1and2_DW.obj_o.SampleTime =
      Assignment1and2_P.FXOS87006AxesSensor_SampleTime;
    Assignment1_SystemCore_setup_ne(&Assignment1and2_DW.obj_o);

    /* Start for MATLABSystem: '<S5>/Moving Average' */
    Assignment1and2_DW.obj.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj.isInitialized = 0;
    Assignment1and2_DW.obj.NumChannels = -1;
    Assignment1and2_DW.obj.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_d2 = true;
    Assignment1and2_DW.obj.isSetupComplete = false;
    Assignment1and2_DW.obj.isInitialized = 1;
    Assignment1and2_DW.obj.NumChannels = 1;
    Assignment1and2_DW.gobj_2.isInitialized = 0;
    Assignment1and2_DW.obj.pStatistic = &Assignment1and2_DW.gobj_2;
    Assignment1and2_DW.obj.isSetupComplete = true;
    Assignment1and2_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S5>/Moving Average' */
    if (Assignment1and2_DW.obj.pStatistic->isInitialized == 1) {
      Assignment1and2_DW.obj.pStatistic->pCumSum = 0.0;
      Assignment1and2_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
      Assignment1and2_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
      Assignment1and2_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
      Assignment1and2_DW.obj.pStatistic->pCumRevIndex = 1.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S5>/Moving Average' */

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    Assignment1and2_DW.obj_f.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_f.isInitialized = 0;
    Assignment1and2_DW.obj_f.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_p = true;
    obj_2 = &Assignment1and2_DW.obj_f;
    Assignment1and2_DW.obj_f.isSetupComplete = false;
    Assignment1and2_DW.obj_f.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Assignment1and2_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write4' */
    Assignment1and2_DW.obj_c.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_c.isInitialized = 0;
    Assignment1and2_DW.obj_c.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_b = true;
    obj_2 = &Assignment1and2_DW.obj_c;
    Assignment1and2_DW.obj_c.isSetupComplete = false;
    Assignment1and2_DW.obj_c.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Assignment1and2_DW.obj_c.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write3' */
    Assignment1and2_DW.obj_e.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_e.isInitialized = 0;
    Assignment1and2_DW.obj_e.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_l = true;
    obj_2 = &Assignment1and2_DW.obj_e;
    Assignment1and2_DW.obj_e.isSetupComplete = false;
    Assignment1and2_DW.obj_e.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Assignment1and2_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write6' */
    Assignment1and2_DW.obj_n.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_n.isInitialized = 0;
    Assignment1and2_DW.obj_n.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_a = true;
    obj_2 = &Assignment1and2_DW.obj_n;
    Assignment1and2_DW.obj_n.isSetupComplete = false;
    Assignment1and2_DW.obj_n.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Assignment1and2_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write5' */
    Assignment1and2_DW.obj_bj.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_bj.isInitialized = 0;
    Assignment1and2_DW.obj_bj.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_o = true;
    obj_2 = &Assignment1and2_DW.obj_bj;
    Assignment1and2_DW.obj_bj.isSetupComplete = false;
    Assignment1and2_DW.obj_bj.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Assignment1and2_DW.obj_bj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write7' */
    Assignment1and2_DW.obj_pd.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_pd.isInitialized = 0;
    Assignment1and2_DW.obj_pd.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_m = true;
    obj_2 = &Assignment1and2_DW.obj_pd;
    Assignment1and2_DW.obj_pd.isSetupComplete = false;
    Assignment1and2_DW.obj_pd.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Assignment1and2_DW.obj_pd.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write2' */
    Assignment1and2_DW.obj_il.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_il.isInitialized = 0;
    Assignment1and2_DW.obj_il.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_k = true;
    obj_2 = &Assignment1and2_DW.obj_il;
    Assignment1and2_DW.obj_il.isSetupComplete = false;
    Assignment1and2_DW.obj_il.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    Assignment1and2_DW.obj_il.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write1' */
    Assignment1and2_DW.obj_ey.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_ey.isInitialized = 0;
    Assignment1and2_DW.obj_ey.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_cu = true;
    obj_2 = &Assignment1and2_DW.obj_ey;
    Assignment1and2_DW.obj_ey.isSetupComplete = false;
    Assignment1and2_DW.obj_ey.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    Assignment1and2_DW.obj_ey.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write8' */
    Assignment1and2_DW.obj_i4.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_i4.isInitialized = 0;
    Assignment1and2_DW.obj_i4.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_m3 = true;
    obj_2 = &Assignment1and2_DW.obj_i4;
    Assignment1and2_DW.obj_i4.isSetupComplete = false;
    Assignment1and2_DW.obj_i4.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Assignment1and2_DW.obj_i4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output1' */
    Assignment1and2_DW.obj_pv.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_pv.isInitialized = 0;
    Assignment1and2_DW.obj_pv.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_n = true;
    obj_3 = &Assignment1and2_DW.obj_pv;
    Assignment1and2_DW.obj_pv.isSetupComplete = false;
    Assignment1and2_DW.obj_pv.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1and2_DW.obj_pv.MW_PWM_HANDLE);
    Assignment1and2_DW.obj_pv.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output' */
    Assignment1and2_DW.obj_k.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_k.isInitialized = 0;
    Assignment1and2_DW.obj_k.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_f = true;
    obj_3 = &Assignment1and2_DW.obj_k;
    Assignment1and2_DW.obj_k.isSetupComplete = false;
    Assignment1and2_DW.obj_k.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1and2_DW.obj_k.MW_PWM_HANDLE);
    Assignment1and2_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PWM Output2' */
    Assignment1and2_DW.obj_a.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_a.isInitialized = 0;
    Assignment1and2_DW.obj_a.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_h = true;
    obj_3 = &Assignment1and2_DW.obj_a;
    Assignment1and2_DW.obj_a.isSetupComplete = false;
    Assignment1and2_DW.obj_a.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Assignment1and2_DW.obj_a.MW_PWM_HANDLE);
    Assignment1and2_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write1' */
    Assignment1and2_DW.obj_i.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_i.isInitialized = 0;
    Assignment1and2_DW.obj_i.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_c = true;
    obj_2 = &Assignment1and2_DW.obj_i;
    Assignment1and2_DW.obj_i.isSetupComplete = false;
    Assignment1and2_DW.obj_i.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Assignment1and2_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write2' */
    Assignment1and2_DW.obj_h.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_h.isInitialized = 0;
    Assignment1and2_DW.obj_h.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_g = true;
    obj_2 = &Assignment1and2_DW.obj_h;
    Assignment1and2_DW.obj_h.isSetupComplete = false;
    Assignment1and2_DW.obj_h.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Assignment1and2_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write3' */
    Assignment1and2_DW.obj_b.matlabCodegenIsDeleted = true;
    Assignment1and2_DW.obj_b.isInitialized = 0;
    Assignment1and2_DW.obj_b.matlabCodegenIsDeleted = false;
    Assignment1and2_DW.objisempty_g2 = true;
    obj_2 = &Assignment1and2_DW.obj_b;
    Assignment1and2_DW.obj_b.isSetupComplete = false;
    Assignment1and2_DW.obj_b.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Assignment1and2_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void Assignment1and2_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  matlabCodegenHandle_matlabCod_n(&Assignment1and2_DW.obj_j);

  /* Terminate for MATLABSystem: '<S1>/AtrSignalIn' */
  matlabCodegenHandle_matlab_nebn(&Assignment1and2_DW.obj_oo);

  /* Terminate for MATLABSystem: '<S1>/VentSignalIn' */
  matlabCodegenHandle_matlab_nebn(&Assignment1and2_DW.obj_ok);

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Send Parameters' incorporates:
   *  SubSystem: '<Root>/Send Parameters'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Send Parameters' */

  /* Terminate for MATLABSystem: '<S1>/VENT_CMP_DETECT' */
  matlabCodegenHandle_matlabCo_ne(&Assignment1and2_DW.obj_p);

  /* Terminate for MATLABSystem: '<S1>/ATR_CMP_DETECT' */
  matlabCodegenHandle_matlabCo_ne(&Assignment1and2_DW.obj_d);

  /* Terminate for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
  Assignment1an_matlabCodegenHa_a(&Assignment1and2_DW.obj_o);
  Assignment1a_matlabCodegenHa_lr(&Assignment1and2_DW.obj_o.i2cobj);

  /* Terminate for MATLABSystem: '<S5>/Moving Average' */
  Assignment1an_matlabCodegenHa_i(&Assignment1and2_DW.obj);

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_f);

  /* Terminate for MATLABSystem: '<S2>/Digital Write4' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_c);

  /* Terminate for MATLABSystem: '<S2>/Digital Write3' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_e);

  /* Terminate for MATLABSystem: '<S2>/Digital Write6' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_n);

  /* Terminate for MATLABSystem: '<S2>/Digital Write5' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_bj);

  /* Terminate for MATLABSystem: '<S2>/Digital Write7' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_pd);

  /* Terminate for MATLABSystem: '<S2>/Digital Write2' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_il);

  /* Terminate for MATLABSystem: '<S2>/Digital Write1' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_ey);

  /* Terminate for MATLABSystem: '<S2>/Digital Write8' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_i4);

  /* Terminate for MATLABSystem: '<S2>/PWM Output1' */
  matlabCodegenHandle_matl_nebna4(&Assignment1and2_DW.obj_pv);

  /* Terminate for MATLABSystem: '<S2>/PWM Output' */
  matlabCodegenHandle_matl_nebna4(&Assignment1and2_DW.obj_k);

  /* Terminate for MATLABSystem: '<S2>/PWM Output2' */
  matlabCodegenHandle_matl_nebna4(&Assignment1and2_DW.obj_a);

  /* Terminate for MATLABSystem: '<S5>/Digital Write1' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_i);

  /* Terminate for MATLABSystem: '<S5>/Digital Write2' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_h);

  /* Terminate for MATLABSystem: '<S5>/Digital Write3' */
  matlabCodegenHandle_m_nebna4py5(&Assignment1and2_DW.obj_b);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
