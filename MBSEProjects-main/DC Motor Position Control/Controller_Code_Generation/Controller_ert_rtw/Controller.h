/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 2.13
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jun 29 01:02:18 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#include "rtwtypes.h"
#include <string.h>
#ifndef Controller_COMMON_INCLUDES_
#define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

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

#define Controller_M                   (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S33>/Integrator' */
} DW;

/* Parameters (default storage) */
struct P_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S30>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S33>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S40>/Saturation'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S38>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S40>/Saturation'
                               */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S33>/Integrator'
                                        */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  DW *dwork;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P rtP;

/* Model entry point functions */
extern void Controller_initialize(RT_MODEL *const rtM, real_T *rtU_refPos,
  real_T *rtU_feedbackPos, real_T *rtY_controlSignal);
extern void Controller_step(RT_MODEL *const rtM, real_T rtU_refPos, real_T
  rtU_feedbackPos, real_T *rtY_controlSignal);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Rate Transition' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'Controller'
 * '<S1>'   : 'Controller/PID Controller'
 * '<S2>'   : 'Controller/PID Controller/Anti-windup'
 * '<S3>'   : 'Controller/PID Controller/D Gain'
 * '<S4>'   : 'Controller/PID Controller/Filter'
 * '<S5>'   : 'Controller/PID Controller/Filter ICs'
 * '<S6>'   : 'Controller/PID Controller/I Gain'
 * '<S7>'   : 'Controller/PID Controller/Ideal P Gain'
 * '<S8>'   : 'Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'Controller/PID Controller/Integrator'
 * '<S10>'  : 'Controller/PID Controller/Integrator ICs'
 * '<S11>'  : 'Controller/PID Controller/N Copy'
 * '<S12>'  : 'Controller/PID Controller/N Gain'
 * '<S13>'  : 'Controller/PID Controller/P Copy'
 * '<S14>'  : 'Controller/PID Controller/Parallel P Gain'
 * '<S15>'  : 'Controller/PID Controller/Reset Signal'
 * '<S16>'  : 'Controller/PID Controller/Saturation'
 * '<S17>'  : 'Controller/PID Controller/Saturation Fdbk'
 * '<S18>'  : 'Controller/PID Controller/Sum'
 * '<S19>'  : 'Controller/PID Controller/Sum Fdbk'
 * '<S20>'  : 'Controller/PID Controller/Tracking Mode'
 * '<S21>'  : 'Controller/PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'Controller/PID Controller/Tsamp - Integral'
 * '<S23>'  : 'Controller/PID Controller/Tsamp - Ngain'
 * '<S24>'  : 'Controller/PID Controller/postSat Signal'
 * '<S25>'  : 'Controller/PID Controller/preSat Signal'
 * '<S26>'  : 'Controller/PID Controller/Anti-windup/Passthrough'
 * '<S27>'  : 'Controller/PID Controller/D Gain/Disabled'
 * '<S28>'  : 'Controller/PID Controller/Filter/Disabled'
 * '<S29>'  : 'Controller/PID Controller/Filter ICs/Disabled'
 * '<S30>'  : 'Controller/PID Controller/I Gain/Internal Parameters'
 * '<S31>'  : 'Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S32>'  : 'Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'Controller/PID Controller/Integrator/Discrete'
 * '<S34>'  : 'Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S35>'  : 'Controller/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S36>'  : 'Controller/PID Controller/N Gain/Disabled'
 * '<S37>'  : 'Controller/PID Controller/P Copy/Disabled'
 * '<S38>'  : 'Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S39>'  : 'Controller/PID Controller/Reset Signal/Disabled'
 * '<S40>'  : 'Controller/PID Controller/Saturation/Enabled'
 * '<S41>'  : 'Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S42>'  : 'Controller/PID Controller/Sum/Sum_PI'
 * '<S43>'  : 'Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S44>'  : 'Controller/PID Controller/Tracking Mode/Disabled'
 * '<S45>'  : 'Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S46>'  : 'Controller/PID Controller/Tsamp - Integral/Passthrough'
 * '<S47>'  : 'Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S48>'  : 'Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S49>'  : 'Controller/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
