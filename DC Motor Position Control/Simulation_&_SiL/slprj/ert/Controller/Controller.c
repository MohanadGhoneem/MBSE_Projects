/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Controller.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 2.11
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jun 29 00:39:59 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Controller.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        ((rtmGetSimTimeStep((rtm))) == MINOR_TIME_STEP)
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         (*((rtm)->Timing.simTimeStep))
#endif

#ifndef rtmGetSimTimeStepPointer
#define rtmGetSimTimeStepPointer(rtm)  (rtm)->Timing.simTimeStep
#endif

#ifndef rtmSetSimTimeStepPointer
#define rtmSetSimTimeStepPointer(rtm, val) ((rtm)->Timing.simTimeStep = (val))
#endif

Controller_P ControllerrtP = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S30>/Integral Gain'
   */
  1750.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S33>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S40>/Saturation'
   */
  -5.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S38>/Proportional Gain'
   */
  100.0,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S40>/Saturation'
   */
  5.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S33>/Integrator'
   */
  1.0E-5
};

/* System initialize for referenced model: 'Controller' */
void Controller_Init(Controller_DW_f *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S33>/Integrator' */
  localDW->Integrator_DSTATE = ControllerrtP.PIDController_InitialConditionF;
}

/* Outputs for referenced model: 'Controller' */
void Controller(Controller_RT_MODEL * const ControllerrtM, const real_T
                *rtu_refPos, const real_T *rtu_feedbackPos, real_T
                *rty_controlSignal, Controller_DW_f *localDW)
{
  real_T errorPos;

  /* Sum: '<Root>/Sum' */
  errorPos = *rtu_refPos - *rtu_feedbackPos;
  if (rtmIsMajorTimeStep(ControllerrtM)) {
    /* Gain: '<S30>/Integral Gain' */
    localDW->IntegralGain = ControllerrtP.PIDController_I * errorPos;

    /* RateTransition: '<Root>/Rate Transition' */
    if (rtmIsMajorTimeStep(ControllerrtM)) {
      /* Sum: '<S42>/Sum' incorporates:
       *  DiscreteIntegrator: '<S33>/Integrator'
       *  Gain: '<S38>/Proportional Gain'
       */
      errorPos = ControllerrtP.PIDController_P * errorPos +
        localDW->Integrator_DSTATE;

      /* Saturate: '<S40>/Saturation' */
      if (errorPos > ControllerrtP.PIDController_UpperSaturationLi) {
        *rty_controlSignal = ControllerrtP.PIDController_UpperSaturationLi;
      } else if (errorPos < ControllerrtP.PIDController_LowerSaturationLi) {
        *rty_controlSignal = ControllerrtP.PIDController_LowerSaturationLi;
      } else {
        *rty_controlSignal = errorPos;
      }

      /* End of Saturate: '<S40>/Saturation' */
    }

    /* End of RateTransition: '<Root>/Rate Transition' */
  }
}

/* Update for referenced model: 'Controller' */
void Controller_Update(Controller_RT_MODEL * const ControllerrtM,
  Controller_DW_f *localDW)
{
  if (rtmIsMajorTimeStep(ControllerrtM)) {
    /* Update for DiscreteIntegrator: '<S33>/Integrator' */
    localDW->Integrator_DSTATE += ControllerrtP.Integrator_gainval *
      localDW->IntegralGain;
  }
}

/* Model initialize function */
void Controller_initialize(const char_T **rt_errorStatus, RTWSolverInfo
  *rt_solverInfo, Controller_RT_MODEL *const ControllerrtM, Controller_DW_f
  *localDW)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ControllerrtM, 0,
                sizeof(Controller_RT_MODEL));

  /* initialize error status */
  rtmSetErrorStatusPointer(ControllerrtM, rt_errorStatus);

  /* initialize RTWSolverInfo */
  ControllerrtM->solverInfo = (rt_solverInfo);

  /* Set the Timing fields to the appropriate data in the RTWSolverInfo */
  rtmSetSimTimeStepPointer(ControllerrtM, rtsiGetSimTimeStepPtr
    (ControllerrtM->solverInfo));
  ControllerrtM->Timing.stepSize0 = (rtsiGetStepSize(ControllerrtM->solverInfo));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(Controller_DW_f));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
