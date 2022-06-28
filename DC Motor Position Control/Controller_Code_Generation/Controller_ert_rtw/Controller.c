/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Controller.c
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

#include "Controller.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

/* Model step function */
void Controller_step(RT_MODEL *const rtM, real_T rtU_refPos, real_T
                     rtU_feedbackPos, real_T *rtY_controlSignal)
{
  DW *rtDW = rtM->dwork;

  /* local block i/o variables */
  real_T rtb_IntegralGain;
  real_T errorPos;
  real_T u0;

  /* Sum: '<Root>/Sum' incorporates:
   *  Inport: '<Root>/feedbackPos'
   *  Inport: '<Root>/refPos'
   */
  errorPos = rtU_refPos - rtU_feedbackPos;

  /* Sum: '<S42>/Sum' incorporates:
   *  DiscreteIntegrator: '<S33>/Integrator'
   *  Gain: '<S38>/Proportional Gain'
   */
  u0 = rtP.PIDController_P * errorPos + rtDW->Integrator_DSTATE;

  /* Saturate: '<S40>/Saturation' */
  if (u0 > rtP.PIDController_UpperSaturationLi) {
    /* Outport: '<Root>/controlSignal' */
    *rtY_controlSignal = rtP.PIDController_UpperSaturationLi;
  } else if (u0 < rtP.PIDController_LowerSaturationLi) {
    /* Outport: '<Root>/controlSignal' */
    *rtY_controlSignal = rtP.PIDController_LowerSaturationLi;
  } else {
    /* Outport: '<Root>/controlSignal' */
    *rtY_controlSignal = u0;
  }

  /* End of Saturate: '<S40>/Saturation' */

  /* Gain: '<S30>/Integral Gain' */
  rtb_IntegralGain = rtP.PIDController_I * errorPos;

  /* Update for DiscreteIntegrator: '<S33>/Integrator' */
  rtDW->Integrator_DSTATE += rtP.Integrator_gainval * rtb_IntegralGain;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++rtM->Timing.clockTick0)) {
    ++rtM->Timing.clockTickH0;
  }

  rtM->Timing.t[0] = rtM->Timing.clockTick0 * rtM->Timing.stepSize0 +
    rtM->Timing.clockTickH0 * rtM->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [1.0E-5s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    rtM->Timing.clockTick1++;
    if (!rtM->Timing.clockTick1) {
      rtM->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void Controller_initialize(RT_MODEL *const rtM, real_T *rtU_refPos, real_T
  *rtU_feedbackPos, real_T *rtY_controlSignal)
{
  DW *rtDW = rtM->dwork;

  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 1.0E-5;

  /* states (dwork) */
  (void) memset((void *)rtDW, 0,
                sizeof(DW));

  /* external inputs */
  *rtU_refPos = 0.0;
  *rtU_feedbackPos = 0.0;

  /* external outputs */
  *rtY_controlSignal = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Integrator' */
  rtDW->Integrator_DSTATE = rtP.PIDController_InitialConditionF;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
