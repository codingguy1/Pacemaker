/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.c
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

#include "test.h"
#include "test_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define test_IN_ECHO_PARAM             ((uint8_T)1U)
#define test_IN_INITIAL                ((uint8_T)2U)
#define test_IN_SET_PARAM              ((uint8_T)3U)
#define test_IN_STANDBY                ((uint8_T)4U)

/* Named constants for Chart: '<Root>/Chart1' */
#define test_IN_BLUE_ON                ((uint8_T)1U)
#define test_IN_GREEN_ON               ((uint8_T)2U)
#define test_IN_OFF                    ((uint8_T)3U)
#define test_IN_RED_ON                 ((uint8_T)4U)

/* Block signals (default storage) */
B_test_T test_B;

/* Block states (default storage) */
DW_test_T test_DW;

/* Real-time model */
RT_MODEL_test_T test_M_;
RT_MODEL_test_T *const test_M = &test_M_;

/* Forward declaration for local functions */
static void test_SystemCore_release_j(const freedomk64f_SCIRead_test_T *obj);
static void test_SystemCore_delete_j(const freedomk64f_SCIRead_test_T *obj);
static void matlabCodegenHandle_matlabCod_j(freedomk64f_SCIRead_test_T *obj);
static void test_SystemCore_release_jp(const freedomk64f_DigitalWrite_test_T
  *obj);
static void test_SystemCore_delete_jp(const freedomk64f_DigitalWrite_test_T *obj);
static void matlabCodegenHandle_matlabCo_jp(freedomk64f_DigitalWrite_test_T *obj);
static void test_SystemCore_setup_j(freedomk64f_SCIRead_test_T *obj);
static void test_SystemCore_release_j(const freedomk64f_SCIRead_test_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void test_SystemCore_delete_j(const freedomk64f_SCIRead_test_T *obj)
{
  test_SystemCore_release_j(obj);
}

static void matlabCodegenHandle_matlabCod_j(freedomk64f_SCIRead_test_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    test_SystemCore_delete_j(obj);
  }
}

static void test_SystemCore_release_jp(const freedomk64f_DigitalWrite_test_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_digitalIO_close(obj->MW_DIGITALIO_HANDLE);
  }
}

static void test_SystemCore_delete_jp(const freedomk64f_DigitalWrite_test_T *obj)
{
  test_SystemCore_release_jp(obj);
}

static void matlabCodegenHandle_matlabCo_jp(freedomk64f_DigitalWrite_test_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    test_SystemCore_delete_jp(obj);
  }
}

static void test_SystemCore_setup_j(freedomk64f_SCIRead_test_T *obj)
{
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  test_B.TxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, 10U, test_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void test_step(void)
{
  uint8_T RxData[11];
  uint8_T RxDataLocChar[11];
  uint8_T status;
  boolean_T rtb_blue_out;
  boolean_T rtb_green_out;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (test_DW.obj.SampleTime != test_P.SerialReceive_SampleTime) {
    test_DW.obj.SampleTime = test_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(test_DW.obj.MW_SCIHANDLE, RxDataLocChar, 11U);
  memcpy((void *)&RxData[0], (void *)&RxDataLocChar[0], (uint32_T)((size_t)11 *
          sizeof(uint8_T)));

  /* Chart: '<Root>/Chart' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  switch (test_DW.is_c3_test) {
   case test_IN_ECHO_PARAM:
    test_DW.is_c3_test = test_IN_STANDBY;
    break;

   case test_IN_INITIAL:
    test_DW.is_c3_test = test_IN_STANDBY;
    break;

   case test_IN_SET_PARAM:
    test_DW.is_c3_test = test_IN_STANDBY;
    break;

   default:
    /* case IN_STANDBY: */
    if (status == 0) {
      if (RxData[0] == 22) {
        switch (RxData[1]) {
         case 85:
          test_DW.is_c3_test = test_IN_SET_PARAM;
          test_B.red_enable = RxData[2];
          test_B.green_enable = RxData[3];
          test_B.blue_enable = RxData[4];
          memcpy((void *)&test_B.off_time_l, (void *)&RxData[5], (uint32_T)
                 ((size_t)1 * sizeof(real32_T)));
          memcpy((void *)&test_B.switch_time_i, (void *)&RxData[9], (uint32_T)
                 ((size_t)1 * sizeof(uint16_T)));
          break;

         case 34:
          test_DW.is_c3_test = test_IN_ECHO_PARAM;
          send_params();
          break;

         default:
          test_DW.is_c3_test = test_IN_STANDBY;
          break;
        }
      } else {
        test_DW.is_c3_test = test_IN_STANDBY;
      }
    }
    break;
  }

  /* End of Chart: '<Root>/Chart' */

  /* Chart: '<Root>/Chart1' */
  if (test_DW.temporalCounter_i1 < MAX_uint32_T) {
    test_DW.temporalCounter_i1++;
  }

  if (test_DW.is_active_c1_test == 0U) {
    test_DW.is_active_c1_test = 1U;
    test_DW.is_c1_test = test_IN_OFF;
    test_DW.temporalCounter_i1 = 0U;
    rtb_green_out = false;
    rtb_blue_out = false;
  } else {
    switch (test_DW.is_c1_test) {
     case test_IN_BLUE_ON:
      rtb_green_out = false;
      rtb_blue_out = true;
      if (test_DW.temporalCounter_i1 >= test_B.switch_time_i) {
        test_DW.is_c1_test = test_IN_OFF;
        test_DW.temporalCounter_i1 = 0U;
        rtb_blue_out = false;
      }
      break;

     case test_IN_GREEN_ON:
      if (test_B.blue_enable == 1) {
        test_DW.is_c1_test = test_IN_BLUE_ON;
        test_DW.temporalCounter_i1 = 0U;
        rtb_green_out = false;
        rtb_blue_out = true;
      } else {
        test_DW.is_c1_test = test_IN_OFF;
        test_DW.temporalCounter_i1 = 0U;
        rtb_green_out = false;
        rtb_blue_out = false;
      }
      break;

     case test_IN_OFF:
      rtb_green_out = false;
      rtb_blue_out = false;
      if (test_DW.temporalCounter_i1 >= test_B.off_time_l * 1000.0F) {
        if (test_B.red_enable == 1) {
          test_DW.is_c1_test = test_IN_RED_ON;
          test_DW.temporalCounter_i1 = 0U;
        } else if (test_B.green_enable == 1) {
          test_DW.is_c1_test = test_IN_GREEN_ON;
          rtb_green_out = true;
        } else if (test_B.blue_enable == 1) {
          test_DW.is_c1_test = test_IN_BLUE_ON;
          test_DW.temporalCounter_i1 = 0U;
          rtb_blue_out = true;
        } else {
          test_DW.is_c1_test = test_IN_OFF;
          test_DW.temporalCounter_i1 = 0U;
        }
      }
      break;

     default:
      /* case IN_RED_ON: */
      rtb_green_out = false;
      rtb_blue_out = false;
      if (test_DW.temporalCounter_i1 >= test_B.switch_time_i) {
        if (test_B.green_enable == 1) {
          test_DW.is_c1_test = test_IN_GREEN_ON;
          rtb_green_out = true;
        } else if (test_B.blue_enable == 1) {
          test_DW.is_c1_test = test_IN_BLUE_ON;
          test_DW.temporalCounter_i1 = 0U;
          rtb_blue_out = true;
        } else {
          test_DW.is_c1_test = test_IN_OFF;
          test_DW.temporalCounter_i1 = 0U;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(test_DW.obj_lh.MW_DIGITALIO_HANDLE, rtb_green_out);

  /* MATLABSystem: '<S4>/Digital Write2' */
  MW_digitalIO_write(test_DW.obj_m.MW_DIGITALIO_HANDLE, rtb_blue_out);
}

/* Model initialize function */
void test_initialize(void)
{
  {
    freedomk64f_DigitalWrite_test_T *obj;

    /* Chart: '<Root>/Chart' */
    test_DW.is_c3_test = test_IN_INITIAL;
    test_B.red_enable = 1U;
    test_B.green_enable = 1U;
    test_B.blue_enable = 1U;
    test_B.off_time_l = 0.5F;
    test_B.switch_time_i = 200U;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    test_DW.obj.isInitialized = 0;
    test_DW.obj.matlabCodegenIsDeleted = false;
    test_DW.obj.SampleTime = test_P.SerialReceive_SampleTime;
    test_SystemCore_setup_j(&test_DW.obj);

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    test_DW.obj_lh.matlabCodegenIsDeleted = true;
    test_DW.obj_lh.isInitialized = 0;
    test_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj = &test_DW.obj_lh;
    test_DW.obj_lh.isSetupComplete = false;
    test_DW.obj_lh.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    test_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write2' */
    test_DW.obj_m.matlabCodegenIsDeleted = true;
    test_DW.obj_m.isInitialized = 0;
    test_DW.obj_m.matlabCodegenIsDeleted = false;
    obj = &test_DW.obj_m;
    test_DW.obj_m.isSetupComplete = false;
    test_DW.obj_m.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    test_DW.obj_m.isSetupComplete = true;
  }
}

/* Model terminate function */
void test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  matlabCodegenHandle_matlabCod_j(&test_DW.obj);

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  matlabCodegenHandle_matlabCo_jp(&test_DW.obj_lh);

  /* Terminate for MATLABSystem: '<S4>/Digital Write2' */
  matlabCodegenHandle_matlabCo_jp(&test_DW.obj_m);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
