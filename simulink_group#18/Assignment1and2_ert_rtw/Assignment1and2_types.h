/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Assignment1and2_types.h
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

#ifndef RTW_HEADER_Assignment1and2_types_h_
#define RTW_HEADER_Assignment1and2_types_h_
#include "rtwtypes.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S6>/Serial Transmit' */
#include "MW_SVD.h"
#ifndef struct_tag_bvK2L41g8z1P0jzpdjsJhE
#define struct_tag_bvK2L41g8z1P0jzpdjsJhE

struct tag_bvK2L41g8z1P0jzpdjsJhE
{
  int32_T __dummy;
};

#endif                                 /*struct_tag_bvK2L41g8z1P0jzpdjsJhE*/

#ifndef typedef_b_freedomk64f_Hardware_Assign_T
#define typedef_b_freedomk64f_Hardware_Assign_T

typedef struct tag_bvK2L41g8z1P0jzpdjsJhE b_freedomk64f_Hardware_Assign_T;

#endif                               /*typedef_b_freedomk64f_Hardware_Assign_T*/

#ifndef struct_tag_WltE1qT51p3S2KRQQd2Zd
#define struct_tag_WltE1qT51p3S2KRQQd2Zd

struct tag_WltE1qT51p3S2KRQQd2Zd
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
};

#endif                                 /*struct_tag_WltE1qT51p3S2KRQQd2Zd*/

#ifndef typedef_freedomk64f_SCIWrite_Assignme_T
#define typedef_freedomk64f_SCIWrite_Assignme_T

typedef struct tag_WltE1qT51p3S2KRQQd2Zd freedomk64f_SCIWrite_Assignme_T;

#endif                               /*typedef_freedomk64f_SCIWrite_Assignme_T*/

#ifndef struct_tag_n6PybfofDJX1nilXyEd0pE
#define struct_tag_n6PybfofDJX1nilXyEd0pE

struct tag_n6PybfofDJX1nilXyEd0pE
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[3];
  real_T pCumRevIndex;
};

#endif                                 /*struct_tag_n6PybfofDJX1nilXyEd0pE*/

#ifndef typedef_g_dsp_private_SlidingWindowAv_T
#define typedef_g_dsp_private_SlidingWindowAv_T

typedef struct tag_n6PybfofDJX1nilXyEd0pE g_dsp_private_SlidingWindowAv_T;

#endif                               /*typedef_g_dsp_private_SlidingWindowAv_T*/

/* Custom Type definition for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
#include "MW_I2C.h"
#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_Assignment1and2_T
#define typedef_cell_wrap_Assignment1and2_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_Assignment1and2_T;

#endif                                 /*typedef_cell_wrap_Assignment1and2_T*/

#ifndef struct_tag_224oznoGXS9H6rLUTJ23kH
#define struct_tag_224oznoGXS9H6rLUTJ23kH

struct tag_224oznoGXS9H6rLUTJ23kH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Assignment1and2_T inputVarSize;
  g_dsp_private_SlidingWindowAv_T *pStatistic;
  int32_T NumChannels;
};

#endif                                 /*struct_tag_224oznoGXS9H6rLUTJ23kH*/

#ifndef typedef_dsp_simulink_MovingAverage_As_T
#define typedef_dsp_simulink_MovingAverage_As_T

typedef struct tag_224oznoGXS9H6rLUTJ23kH dsp_simulink_MovingAverage_As_T;

#endif                               /*typedef_dsp_simulink_MovingAverage_As_T*/

#ifndef struct_tag_79weVYaslRFZRGk3pNTXC
#define struct_tag_79weVYaslRFZRGk3pNTXC

struct tag_79weVYaslRFZRGk3pNTXC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_79weVYaslRFZRGk3pNTXC*/

#ifndef typedef_freedomk64f_SCIRead_Assignmen_T
#define typedef_freedomk64f_SCIRead_Assignmen_T

typedef struct tag_79weVYaslRFZRGk3pNTXC freedomk64f_SCIRead_Assignmen_T;

#endif                               /*typedef_freedomk64f_SCIRead_Assignmen_T*/

#ifndef struct_tag_gY1zYXXyNHJpvdqiHJr34G
#define struct_tag_gY1zYXXyNHJpvdqiHJr34G

struct tag_gY1zYXXyNHJpvdqiHJr34G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_gY1zYXXyNHJpvdqiHJr34G*/

#ifndef typedef_freedomk64f_DigitalRead_Assig_T
#define typedef_freedomk64f_DigitalRead_Assig_T

typedef struct tag_gY1zYXXyNHJpvdqiHJr34G freedomk64f_DigitalRead_Assig_T;

#endif                               /*typedef_freedomk64f_DigitalRead_Assig_T*/

#ifndef struct_tag_Wwo3lHKnvPcvz2YX38S3zB
#define struct_tag_Wwo3lHKnvPcvz2YX38S3zB

struct tag_Wwo3lHKnvPcvz2YX38S3zB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_Wwo3lHKnvPcvz2YX38S3zB*/

#ifndef typedef_freedomk64f_AnalogInput_Assig_T
#define typedef_freedomk64f_AnalogInput_Assig_T

typedef struct tag_Wwo3lHKnvPcvz2YX38S3zB freedomk64f_AnalogInput_Assig_T;

#endif                               /*typedef_freedomk64f_AnalogInput_Assig_T*/

#ifndef struct_tag_asB9FwAteE1VObOuq1LwyE
#define struct_tag_asB9FwAteE1VObOuq1LwyE

struct tag_asB9FwAteE1VObOuq1LwyE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /*struct_tag_asB9FwAteE1VObOuq1LwyE*/

#ifndef typedef_freedomk64f_PWMOutput_Assignm_T
#define typedef_freedomk64f_PWMOutput_Assignm_T

typedef struct tag_asB9FwAteE1VObOuq1LwyE freedomk64f_PWMOutput_Assignm_T;

#endif                               /*typedef_freedomk64f_PWMOutput_Assignm_T*/

#ifndef struct_tag_62aCTDKRGQaAsT8vVipI2D
#define struct_tag_62aCTDKRGQaAsT8vVipI2D

struct tag_62aCTDKRGQaAsT8vVipI2D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Assign_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /*struct_tag_62aCTDKRGQaAsT8vVipI2D*/

#ifndef typedef_freedomk64f_DigitalWrite_Assi_T
#define typedef_freedomk64f_DigitalWrite_Assi_T

typedef struct tag_62aCTDKRGQaAsT8vVipI2D freedomk64f_DigitalWrite_Assi_T;

#endif                               /*typedef_freedomk64f_DigitalWrite_Assi_T*/

#ifndef struct_tag_dJFZzmsGU3XebjMxPxDlh
#define struct_tag_dJFZzmsGU3XebjMxPxDlh

struct tag_dJFZzmsGU3XebjMxPxDlh
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  b_freedomk64f_Hardware_Assign_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /*struct_tag_dJFZzmsGU3XebjMxPxDlh*/

#ifndef typedef_b_freedomk64f_I2CMasterWrite__T
#define typedef_b_freedomk64f_I2CMasterWrite__T

typedef struct tag_dJFZzmsGU3XebjMxPxDlh b_freedomk64f_I2CMasterWrite__T;

#endif                               /*typedef_b_freedomk64f_I2CMasterWrite__T*/

#ifndef struct_tag_IfyqWdTTOITb2iei5A9qmC
#define struct_tag_IfyqWdTTOITb2iei5A9qmC

struct tag_IfyqWdTTOITb2iei5A9qmC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  b_freedomk64f_I2CMasterWrite__T i2cobj;
};

#endif                                 /*struct_tag_IfyqWdTTOITb2iei5A9qmC*/

#ifndef typedef_freedomk64f_fxos8700_Assignme_T
#define typedef_freedomk64f_fxos8700_Assignme_T

typedef struct tag_IfyqWdTTOITb2iei5A9qmC freedomk64f_fxos8700_Assignme_T;

#endif                               /*typedef_freedomk64f_fxos8700_Assignme_T*/

/* Parameters (default storage) */
typedef struct P_Assignment1and2_T_ P_Assignment1and2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Assignment1and2_T RT_MODEL_Assignment1and2_T;

#endif                                 /* RTW_HEADER_Assignment1and2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
