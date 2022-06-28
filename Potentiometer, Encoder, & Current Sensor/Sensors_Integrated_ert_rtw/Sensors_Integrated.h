/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Sensors_Integrated.h
 *
 * Code generated for Simulink model 'Sensors_Integrated'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Jun 28 23:26:12 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Sensors_Integrated_h_
#define RTW_HEADER_Sensors_Integrated_h_
#include <math.h>
#include <string.h>
#ifndef Sensors_Integrated_COMMON_INCLUDES_
#define Sensors_Integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Sensors_Integrated_COMMON_INCLUDES_ */

#include "Sensors_Integrated_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T UnitDelay;                    /* '<S6>/Unit Delay' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S6>/Unit Delay' */
  boolean_T Relay_Mode;                /* '<Root>/Relay' */
  boolean_T Relay1_Mode;               /* '<Root>/Relay1' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S3>/Triggered Subsystem' */
} PrevZCX;

/* Parameters (default storage) */
struct P_ {
  real_T Pulsecount_Y0;                /* Expression: 0
                                        * Referenced by: '<S6>/Pulse count'
                                        */
  real_T Pulsefrequency_Y0;            /* Computed Parameter: Pulsefrequency_Y0
                                        * Referenced by: '<S6>/Pulse frequency'
                                        */
  real_T Direction_Y0;                 /* Expression: 0
                                        * Referenced by: '<S6>/Direction'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S6>/Unit Delay'
                                        */
  real_T Constant_Value;               /* Expression: 0.5
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/15
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<Root>/Constant'
                                        */
  boolean_T Relay_OnVal;               /* Computed Parameter: Relay_OnVal
                                        * Referenced by: '<Root>/Relay'
                                        */
  boolean_T Relay_OffVal;              /* Computed Parameter: Relay_OffVal
                                        * Referenced by: '<Root>/Relay'
                                        */
  boolean_T Relay_YOn;                 /* Computed Parameter: Relay_YOn
                                        * Referenced by: '<Root>/Relay'
                                        */
  boolean_T Relay_YOff;                /* Computed Parameter: Relay_YOff
                                        * Referenced by: '<Root>/Relay'
                                        */
  boolean_T Relay1_OnVal;              /* Computed Parameter: Relay1_OnVal
                                        * Referenced by: '<Root>/Relay1'
                                        */
  boolean_T Relay1_OffVal;             /* Computed Parameter: Relay1_OffVal
                                        * Referenced by: '<Root>/Relay1'
                                        */
  boolean_T Relay1_YOn;                /* Computed Parameter: Relay1_YOn
                                        * Referenced by: '<Root>/Relay1'
                                        */
  boolean_T Relay1_YOff;               /* Computed Parameter: Relay1_YOff
                                        * Referenced by: '<Root>/Relay1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  B *blockIO;
  PrevZCX *prevZCSigState;
  DW *dwork;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P rtP;

/* Model entry point functions */
extern void Sensors_Integrated_initialize(RT_MODEL *const rtM, uint8_T *rtU_A,
  uint8_T *rtU_B_j, uint8_T *rtU_potAnalog_in, uint8_T *rtU_currAnalog_in,
  uint8_T *rtY_currFlag, uint8_T *rtY_dirFlag);
extern void Sensors_Integrated_step(RT_MODEL *const rtM, uint8_T rtU_A, uint8_T
  rtU_B_j, uint8_T rtU_potAnalog_in, uint8_T rtU_currAnalog_in, uint8_T
  *rtY_currFlag, uint8_T *rtY_dirFlag);
extern void Sensors_Integrated_terminate(RT_MODEL *const rtM);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Display1' : Unused code path elimination
 * Block '<S1>/Display2' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<S2>/Display1' : Unused code path elimination
 * Block '<S2>/Display2' : Unused code path elimination
 * Block '<S3>/Clock' : Unused code path elimination
 * Block '<S3>/Data Type Conversion3' : Unused code path elimination
 * Block '<S3>/Data Type Conversion4' : Unused code path elimination
 * Block '<S6>/Math Function' : Unused code path elimination
 * Block '<S6>/Sum' : Unused code path elimination
 * Block '<S6>/Unit Delay1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'Sensors_Integrated'
 * '<S1>'   : 'Sensors_Integrated/Current_Sensor'
 * '<S2>'   : 'Sensors_Integrated/Potentiometer'
 * '<S3>'   : 'Sensors_Integrated/Pulse_Decode'
 * '<S4>'   : 'Sensors_Integrated/Current_Sensor/MATLAB Function'
 * '<S5>'   : 'Sensors_Integrated/Potentiometer/MATLAB Function'
 * '<S6>'   : 'Sensors_Integrated/Pulse_Decode/Triggered Subsystem'
 */
#endif                                 /* RTW_HEADER_Sensors_Integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
