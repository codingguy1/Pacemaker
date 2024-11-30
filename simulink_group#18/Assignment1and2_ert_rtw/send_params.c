/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params.c
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

#include "send_params.h"

/* Include model header file for global data */
#include "Assignment1and2.h"
#include "Assignment1and2_private.h"

/* Forward declaration for local functions */
static void Assignment1and_SystemCore_setup(freedomk64f_SCIWrite_Assignme_T *obj);
static void Assignment1a_SystemCore_release(const
  freedomk64f_SCIWrite_Assignme_T *obj);
static void Assignment1an_SystemCore_delete(const
  freedomk64f_SCIWrite_Assignme_T *obj);
static void matlabCodegenHandle_matlabCodeg(freedomk64f_SCIWrite_Assignme_T *obj);
static void Assignment1and_SystemCore_setup(freedomk64f_SCIWrite_Assignme_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

static void Assignment1a_SystemCore_release(const
  freedomk64f_SCIWrite_Assignme_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Assignment1an_SystemCore_delete(const
  freedomk64f_SCIWrite_Assignme_T *obj)
{
  Assignment1a_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(freedomk64f_SCIWrite_Assignme_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Assignment1an_SystemCore_delete(obj);
  }
}

/* System initialize for Simulink Function: '<Root>/Send Parameters' */
void send_params_Init(void)
{
  /* Start for MATLABSystem: '<S6>/Serial Transmit' */
  Assignment1and2_DW.obj_m.isInitialized = 0;
  Assignment1and2_DW.obj_m.matlabCodegenIsDeleted = false;
  Assignment1and_SystemCore_setup(&Assignment1and2_DW.obj_m);
}

/* Output and update for Simulink Function: '<Root>/Send Parameters' */
void send_params(void)
{
  uint8_T status;

  /* SignalConversion generated from: '<S6>/LRL' */
  Assignment1and2_B.lower_rate_limit = Assignment1and2_B.lower_rate_limit_f;

  /* SignalConversion generated from: '<S6>/URL' */
  Assignment1and2_B.upper_rate_limit = Assignment1and2_B.upper_rate_limit_b;

  /* SignalConversion generated from: '<S6>/MaxSensorRate' */
  Assignment1and2_B.maximum_sensor_rate =
    Assignment1and2_B.maximum_sensor_rate_p;

  /* SignalConversion generated from: '<S6>/AtrialAmp' */
  Assignment1and2_B.atrial_amplitude = Assignment1and2_B.atrial_amplitude_o;

  /* SignalConversion generated from: '<S6>/VentricularAmp' */
  Assignment1and2_B.ventricular_amplitude =
    Assignment1and2_B.ventricular_amplitude_g;

  /* SignalConversion generated from: '<S6>/AtrialPulseWidth' */
  Assignment1and2_B.atrial_pulse_width = Assignment1and2_B.atrial_pulse_width_f;

  /* SignalConversion generated from: '<S6>/VentricularPulseWidth' */
  Assignment1and2_B.ventricular_pulse_width =
    Assignment1and2_B.ventricular_pulse_width_n;

  /* SignalConversion generated from: '<S6>/AtrialSensitivity' */
  Assignment1and2_B.atrial_sensitivity = Assignment1and2_B.atrial_sensitivity_k;

  /* SignalConversion generated from: '<S6>/VentricularSensitivity' */
  Assignment1and2_B.ventricular_sensitivity =
    Assignment1and2_B.ventricular_sensitivity_c;

  /* SignalConversion generated from: '<S6>/ARP' */
  Assignment1and2_B.ARP = Assignment1and2_B.ARP_o;

  /* SignalConversion generated from: '<S6>/VRP' */
  Assignment1and2_B.VRP = Assignment1and2_B.VRP_g;

  /* SignalConversion generated from: '<S6>/PVARP' */
  Assignment1and2_B.PVARP = Assignment1and2_B.PVARP_l;

  /* SignalConversion generated from: '<S6>/ActivityThreshold' */
  Assignment1and2_B.activity_threshold = Assignment1and2_B.activity_threshold_m;

  /* SignalConversion generated from: '<S6>/ReactionTime' */
  Assignment1and2_B.reaction_time = Assignment1and2_B.reaction_time_k;

  /* SignalConversion generated from: '<S6>/ResponseFactor' */
  Assignment1and2_B.response_factor = Assignment1and2_B.response_factor_c;

  /* SignalConversion generated from: '<S6>/RecoveryTime' */
  Assignment1and2_B.recovery_time = Assignment1and2_B.recovery_time_e;

  /* SignalConversion generated from: '<S6>/Atrial_Signal' */
  Assignment1and2_B.TmpLatchAtAtrial_SignalOutport1 =
    Assignment1and2_B.DataTypeConversion;

  /* SignalConversion generated from: '<S6>/Vent_Signal' */
  Assignment1and2_B.TmpLatchAtVent_SignalOutport1 =
    Assignment1and2_B.DataTypeConversion1;

  /* S-Function (any2byte): '<S6>/Byte Pack15' */

  /* Pack: <S6>/Byte Pack15 */
  (void) memcpy(&Assignment1and2_B.BytePack15[0],
                &Assignment1and2_B.lower_rate_limit,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack16' */

  /* Pack: <S6>/Byte Pack16 */
  (void) memcpy(&Assignment1and2_B.BytePack16[0],
                &Assignment1and2_B.upper_rate_limit,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack17' */

  /* Pack: <S6>/Byte Pack17 */
  (void) memcpy(&Assignment1and2_B.BytePack17[0],
                &Assignment1and2_B.maximum_sensor_rate,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack1' */

  /* Pack: <S6>/Byte Pack1 */
  (void) memcpy(&Assignment1and2_B.BytePack1[0],
                &Assignment1and2_B.atrial_amplitude,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack4' */

  /* Pack: <S6>/Byte Pack4 */
  (void) memcpy(&Assignment1and2_B.BytePack4[0],
                &Assignment1and2_B.ventricular_amplitude,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack8' */

  /* Pack: <S6>/Byte Pack8 */
  (void) memcpy(&Assignment1and2_B.BytePack8[0],
                &Assignment1and2_B.atrial_pulse_width,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack10' */

  /* Pack: <S6>/Byte Pack10 */
  (void) memcpy(&Assignment1and2_B.BytePack10[0],
                &Assignment1and2_B.ventricular_pulse_width,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack3' */

  /* Pack: <S6>/Byte Pack3 */
  (void) memcpy(&Assignment1and2_B.BytePack3[0],
                &Assignment1and2_B.atrial_sensitivity,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack9' */

  /* Pack: <S6>/Byte Pack9 */
  (void) memcpy(&Assignment1and2_B.BytePack9[0],
                &Assignment1and2_B.ventricular_sensitivity,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack5' */

  /* Pack: <S6>/Byte Pack5 */
  (void) memcpy(&Assignment1and2_B.BytePack5[0], &Assignment1and2_B.ARP,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack' */

  /* Pack: <S6>/Byte Pack */
  (void) memcpy(&Assignment1and2_B.BytePack[0], &Assignment1and2_B.VRP,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack6' */

  /* Pack: <S6>/Byte Pack6 */
  (void) memcpy(&Assignment1and2_B.BytePack6[0], &Assignment1and2_B.PVARP,
                2);

  /* S-Function (any2byte): '<S6>/Byte Pack2' */

  /* Pack: <S6>/Byte Pack2 */
  (void) memcpy(&Assignment1and2_B.BytePack2[0],
                &Assignment1and2_B.activity_threshold,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack11' */

  /* Pack: <S6>/Byte Pack11 */
  (void) memcpy(&Assignment1and2_B.BytePack11[0],
                &Assignment1and2_B.reaction_time,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack12' */

  /* Pack: <S6>/Byte Pack12 */
  (void) memcpy(&Assignment1and2_B.BytePack12[0],
                &Assignment1and2_B.response_factor,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack7' */

  /* Pack: <S6>/Byte Pack7 */
  (void) memcpy(&Assignment1and2_B.BytePack7[0],
                &Assignment1and2_B.recovery_time,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack13' */

  /* Pack: <S6>/Byte Pack13 */
  (void) memcpy(&Assignment1and2_B.BytePack13[0],
                &Assignment1and2_B.TmpLatchAtAtrial_SignalOutport1,
                4);

  /* S-Function (any2byte): '<S6>/Byte Pack14' */

  /* Pack: <S6>/Byte Pack14 */
  (void) memcpy(&Assignment1and2_B.BytePack14[0],
                &Assignment1and2_B.TmpLatchAtVent_SignalOutport1,
                4);

  /* SignalConversion generated from: '<S6>/Serial Transmit' incorporates:
   *  SignalConversion generated from: '<S6>/Mode'
   */
  Assignment1and2_B.TmpSignalConversionAtSerial[0] = Assignment1and2_B.Mode;
  Assignment1and2_B.TmpSignalConversionAtSerial[1] =
    Assignment1and2_B.BytePack15[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[5] =
    Assignment1and2_B.BytePack16[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[9] =
    Assignment1and2_B.BytePack17[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[13] =
    Assignment1and2_B.BytePack1[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[17] =
    Assignment1and2_B.BytePack4[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[21] =
    Assignment1and2_B.BytePack8[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[25] =
    Assignment1and2_B.BytePack10[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[29] =
    Assignment1and2_B.BytePack3[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[33] =
    Assignment1and2_B.BytePack9[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[37] =
    Assignment1and2_B.BytePack5[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[41] =
    Assignment1and2_B.BytePack[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[2] =
    Assignment1and2_B.BytePack15[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[6] =
    Assignment1and2_B.BytePack16[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[10] =
    Assignment1and2_B.BytePack17[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[14] =
    Assignment1and2_B.BytePack1[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[18] =
    Assignment1and2_B.BytePack4[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[22] =
    Assignment1and2_B.BytePack8[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[26] =
    Assignment1and2_B.BytePack10[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[30] =
    Assignment1and2_B.BytePack3[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[34] =
    Assignment1and2_B.BytePack9[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[38] =
    Assignment1and2_B.BytePack5[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[42] =
    Assignment1and2_B.BytePack[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[3] =
    Assignment1and2_B.BytePack15[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[7] =
    Assignment1and2_B.BytePack16[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[11] =
    Assignment1and2_B.BytePack17[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[15] =
    Assignment1and2_B.BytePack1[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[19] =
    Assignment1and2_B.BytePack4[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[23] =
    Assignment1and2_B.BytePack8[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[27] =
    Assignment1and2_B.BytePack10[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[31] =
    Assignment1and2_B.BytePack3[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[35] =
    Assignment1and2_B.BytePack9[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[39] =
    Assignment1and2_B.BytePack5[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[43] =
    Assignment1and2_B.BytePack[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[4] =
    Assignment1and2_B.BytePack15[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[8] =
    Assignment1and2_B.BytePack16[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[12] =
    Assignment1and2_B.BytePack17[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[16] =
    Assignment1and2_B.BytePack1[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[20] =
    Assignment1and2_B.BytePack4[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[24] =
    Assignment1and2_B.BytePack8[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[28] =
    Assignment1and2_B.BytePack10[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[32] =
    Assignment1and2_B.BytePack3[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[36] =
    Assignment1and2_B.BytePack9[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[40] =
    Assignment1and2_B.BytePack5[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[44] =
    Assignment1and2_B.BytePack[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[45] =
    Assignment1and2_B.BytePack6[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[46] =
    Assignment1and2_B.BytePack6[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[47] =
    Assignment1and2_B.BytePack2[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[51] =
    Assignment1and2_B.BytePack11[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[55] =
    Assignment1and2_B.BytePack12[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[59] =
    Assignment1and2_B.BytePack7[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[63] =
    Assignment1and2_B.BytePack13[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[67] =
    Assignment1and2_B.BytePack14[0];
  Assignment1and2_B.TmpSignalConversionAtSerial[48] =
    Assignment1and2_B.BytePack2[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[52] =
    Assignment1and2_B.BytePack11[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[56] =
    Assignment1and2_B.BytePack12[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[60] =
    Assignment1and2_B.BytePack7[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[64] =
    Assignment1and2_B.BytePack13[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[68] =
    Assignment1and2_B.BytePack14[1];
  Assignment1and2_B.TmpSignalConversionAtSerial[49] =
    Assignment1and2_B.BytePack2[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[53] =
    Assignment1and2_B.BytePack11[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[57] =
    Assignment1and2_B.BytePack12[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[61] =
    Assignment1and2_B.BytePack7[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[65] =
    Assignment1and2_B.BytePack13[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[69] =
    Assignment1and2_B.BytePack14[2];
  Assignment1and2_B.TmpSignalConversionAtSerial[50] =
    Assignment1and2_B.BytePack2[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[54] =
    Assignment1and2_B.BytePack11[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[58] =
    Assignment1and2_B.BytePack12[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[62] =
    Assignment1and2_B.BytePack7[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[66] =
    Assignment1and2_B.BytePack13[3];
  Assignment1and2_B.TmpSignalConversionAtSerial[70] =
    Assignment1and2_B.BytePack14[3];

  /* MATLABSystem: '<S6>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&Assignment1and2_B.TxDataLocChar[0], (void *)
           &Assignment1and2_B.TmpSignalConversionAtSerial[0], (uint32_T)((size_t)
            71 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(Assignment1and2_DW.obj_m.MW_SCIHANDLE,
      Assignment1and2_B.TxDataLocChar, 71U);
  }

  /* End of MATLABSystem: '<S6>/Serial Transmit' */
}

/* Termination for Simulink Function: '<Root>/Send Parameters' */
void send_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S6>/Serial Transmit' */
  matlabCodegenHandle_matlabCodeg(&Assignment1and2_DW.obj_m);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
