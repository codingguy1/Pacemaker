/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Peacemaker_types.h
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

#ifndef RTW_HEADER_Peacemaker_types_h_
#define RTW_HEADER_Peacemaker_types_h_
#include "rtwtypes.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S3>/Digital Write' */
#include "MW_SVD.h"
#ifndef struct_tag_bvK2L41g8z1P0jzpdjsJhE
#define struct_tag_bvK2L41g8z1P0jzpdjsJhE

struct tag_bvK2L41g8z1P0jzpdjsJhE
{
  int32_T __dummy;
};

#endif                                 /*struct_tag_bvK2L41g8z1P0jzpdjsJhE*/

#ifndef typedef_b_freedomk64f_Hardware_Peacem_T
#define typedef_b_freedomk64f_Hardware_Peacem_T

typedef struct tag_bvK2L41g8z1P0jzpdjsJhE b_freedomk64f_Hardware_Peacem_T;

#endif                               /*typedef_b_freedomk64f_Hardware_Peacem_T*/

#ifndef struct_tag_gY1zYXXyNHJpvdqiHJr34G
#define struct_tag_gY1zYXXyNHJpvdqiHJr34G

struct tag_gY1zYXXyNHJpvdqiHJr34G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Peacem_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /*struct_tag_gY1zYXXyNHJpvdqiHJr34G*/

#ifndef typedef_freedomk64f_DigitalRead_Peace_T
#define typedef_freedomk64f_DigitalRead_Peace_T

typedef struct tag_gY1zYXXyNHJpvdqiHJr34G freedomk64f_DigitalRead_Peace_T;

#endif                               /*typedef_freedomk64f_DigitalRead_Peace_T*/

#ifndef struct_tag_62aCTDKRGQaAsT8vVipI2D
#define struct_tag_62aCTDKRGQaAsT8vVipI2D

struct tag_62aCTDKRGQaAsT8vVipI2D
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Peacem_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /*struct_tag_62aCTDKRGQaAsT8vVipI2D*/

#ifndef typedef_freedomk64f_DigitalWrite_Peac_T
#define typedef_freedomk64f_DigitalWrite_Peac_T

typedef struct tag_62aCTDKRGQaAsT8vVipI2D freedomk64f_DigitalWrite_Peac_T;

#endif                               /*typedef_freedomk64f_DigitalWrite_Peac_T*/

#ifndef struct_tag_asB9FwAteE1VObOuq1LwyE
#define struct_tag_asB9FwAteE1VObOuq1LwyE

struct tag_asB9FwAteE1VObOuq1LwyE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_Peacem_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /*struct_tag_asB9FwAteE1VObOuq1LwyE*/

#ifndef typedef_freedomk64f_PWMOutput_Peacema_T
#define typedef_freedomk64f_PWMOutput_Peacema_T

typedef struct tag_asB9FwAteE1VObOuq1LwyE freedomk64f_PWMOutput_Peacema_T;

#endif                               /*typedef_freedomk64f_PWMOutput_Peacema_T*/

/* Parameters (default storage) */
typedef struct P_Peacemaker_T_ P_Peacemaker_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Peacemaker_T RT_MODEL_Peacemaker_T;

#endif                                 /* RTW_HEADER_Peacemaker_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
