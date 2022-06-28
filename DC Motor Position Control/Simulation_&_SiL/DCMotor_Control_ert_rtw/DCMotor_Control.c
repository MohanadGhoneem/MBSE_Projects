/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: DCMotor_Control.c
 *
 * Code generated for Simulink model 'DCMotor_Control'.
 *
 * Model version                  : 2.21
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Jun 29 00:50:41 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "DCMotor_Control.h"

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

/* Used by FromWorkspace Block: '<S2>/FromWs' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* Continuous states */
X rtX;

/* Block signals and states (default storage) */
DW rtDW;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* private model entry point functions */
extern void DCMotor_Control_derivatives(void);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  DCMotor_Control_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  DCMotor_Control_step();
  DCMotor_Control_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  DCMotor_Control_step();
  DCMotor_Control_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void DCMotor_Control_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs;
  if (rtmIsMajorTimeStep(rtM)) {
    /* set solver stop time */
    if (!(rtM->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&rtM->solverInfo, ((rtM->Timing.clockTickH0 + 1) *
        rtM->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&rtM->solverInfo, ((rtM->Timing.clockTick0 + 1) *
        rtM->Timing.stepSize0 + rtM->Timing.clockTickH0 * rtM->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(rtM)) {
    rtM->Timing.t[0] = rtsiGetT(&rtM->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    int32_T tmp_2;
    int_T tmp_1[2];
    boolean_T tmp;
    boolean_T tmp_0;

    /* SimscapeExecutionBlock: '<S14>/STATE_1' */
    if (rtDW.STATE_1_FirstOutput) {
      simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
      rtDW.time = rtM->Timing.t[0];
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &rtDW.time;
      simulationData->mData->mContStates.mN = 3;
      simulationData->mData->mContStates.mX =
        &rtX.DCMotor_ControlDC_Motor_Simscap[0];
      simulationData->mData->mDiscStates.mN = 0;
      simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
      simulationData->mData->mModeVector.mN = 0;
      simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes;
      tmp = false;
      simulationData->mData->mFoundZcEvents = tmp;
      tmp = rtmIsMajorTimeStep(rtM);
      simulationData->mData->mIsMajorTimeStep = tmp;
      tmp_0 = false;
      simulationData->mData->mIsSolverAssertCheck = tmp_0;
      simulationData->mData->mIsSolverCheckingCIC = false;
      tmp_0 = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
      simulationData->mData->mIsComputingJacobian = tmp_0;
      simulationData->mData->mIsEvaluatingF0 = false;
      simulationData->mData->mIsSolverRequestingReset = false;
      simulationData->mData->mIsOkayToUpdateMode = tmp;
      tmp_1[0] = 0;
      rtDW.dv[0] = rtDW.INPUT_1_1_1[0];
      rtDW.dv[1] = rtDW.INPUT_1_1_1[1];
      rtDW.dv[2] = rtDW.INPUT_1_1_1[2];
      rtDW.dv[3] = rtDW.INPUT_1_1_1[3];
      tmp_1[1] = 4;
      simulationData->mData->mInputValues.mN = 4;
      simulationData->mData->mInputValues.mX = &rtDW.dv[0];
      simulationData->mData->mInputOffsets.mN = 2;
      simulationData->mData->mInputOffsets.mX = &tmp_1[0];
      simulationData->mData->mOutputs.mN = 3;
      simulationData->mData->mOutputs.mX = &rtDW.STATE_1[0];
      simulationData->mData->mSampleHits.mN = 0;
      simulationData->mData->mSampleHits.mX = NULL;
      simulationData->mData->mIsFundamentalSampleHit = false;
      simulationData->mData->mTolerances.mN = 0;
      simulationData->mData->mTolerances.mX = NULL;
      simulationData->mData->mCstateHasChanged = false;
      diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
      diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
      tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
        NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
      if (tmp_2 != 0) {
        tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
        if (tmp) {
          msg = rtw_diagnostics_msg(diagnosticTree);
          rtmSetErrorStatus(rtM, msg);
        }
      }

      rtDW.STATE_1_FirstOutput = false;
    } else {
      rtDW.STATE_1[0] = rtX.DCMotor_ControlDC_Motor_Simscap[0];
      rtDW.STATE_1[1] = rtX.DCMotor_ControlDC_Motor_Simscap[1];
      rtDW.STATE_1[2] = rtX.DCMotor_ControlDC_Motor_Simscap[2];
    }

    /* End of SimscapeExecutionBlock: '<S14>/STATE_1' */

    /* SimscapeExecutionBlock: '<S14>/OUTPUT_1_1' */
    rtDW.OUTPUT_1_1[0] = 0.0;
    rtDW.OUTPUT_1_1[1] = 0.0;
    rtDW.OUTPUT_1_1[1] += 0.004 * rtDW.STATE_1[1];
    rtDW.OUTPUT_1_1[0] += rtDW.STATE_1[2];

    /* FromWorkspace: '<S2>/FromWs' */
    {
      real_T *pDataValues = (real_T *) rtDW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *) rtDW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex = rtDW.FromWs_IWORK.PrevIndex;
      real_T t = rtM->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[57]) {
        currTimeIndex = 56;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      rtDW.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_FromWs = pDataValues[currTimeIndex];
          } else {
            rtb_FromWs = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex = currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_FromWs = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 58;
        }
      }
    }

    /* ModelReference: '<Root>/Controller' */
    Controller(&(rtDW.Controller_InstanceData.rtm), &rtb_FromWs,
               &rtDW.OUTPUT_1_1[0], &rtDW.Controller_k,
               &(rtDW.Controller_InstanceData.rtdw));

    /* ModelReference: '<Root>/Controller1' */
    Controller(&(rtDW.Controller1_InstanceData.rtm), &rtb_FromWs,
               &rtDW.OUTPUT_1_1[0], &rtDW.Controller1,
               &(rtDW.Controller1_InstanceData.rtdw));

    /* SimscapeInputBlock: '<S14>/INPUT_1_1_1' */
    rtDW.INPUT_1_1_1[0] = rtDW.Controller_k;
    rtDW.INPUT_1_1_1[1] = 0.0;
    rtDW.INPUT_1_1_1[2] = 0.0;
    if (rtmIsMajorTimeStep(rtM)) {
      rtDW.INPUT_1_1_1_Discrete[0] = !(rtDW.INPUT_1_1_1[0] ==
        rtDW.INPUT_1_1_1_Discrete[1]);
      rtDW.INPUT_1_1_1_Discrete[1] = rtDW.INPUT_1_1_1[0];
    }

    rtDW.INPUT_1_1_1[0] = rtDW.INPUT_1_1_1_Discrete[1];
    rtDW.INPUT_1_1_1[3] = rtDW.INPUT_1_1_1_Discrete[0];

    /* End of SimscapeInputBlock: '<S14>/INPUT_1_1_1' */
  }

  if (rtmIsMajorTimeStep(rtM)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T time;
    int32_T tmp_2;
    int_T tmp_1[2];
    boolean_T tmp;
    boolean_T tmp_0;

    /* Update for SimscapeExecutionBlock: '<S14>/STATE_1' */
    simulationData = (NeslSimulationData *)rtDW.STATE_1_SimData;
    time = rtM->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 3;
    simulationData->mData->mContStates.mX =
      &rtX.DCMotor_ControlDC_Motor_Simscap[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &rtDW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &rtDW.STATE_1_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    tmp = rtmIsMajorTimeStep(rtM);
    simulationData->mData->mIsMajorTimeStep = tmp;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&rtM->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsOkayToUpdateMode = tmp;
    tmp_1[0] = 0;
    rtDW.dv1[0] = rtDW.INPUT_1_1_1[0];
    rtDW.dv1[1] = rtDW.INPUT_1_1_1[1];
    rtDW.dv1[2] = rtDW.INPUT_1_1_1[2];
    rtDW.dv1[3] = rtDW.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    simulationData->mData->mInputValues.mN = 4;
    simulationData->mData->mInputValues.mX = &rtDW.dv1[0];
    simulationData->mData->mInputOffsets.mN = 2;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)rtDW.STATE_1_Simulator,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S14>/STATE_1' */

    /* Update for ModelReference: '<Root>/Controller' */
    Controller_Update(&(rtDW.Controller_InstanceData.rtm),
                      &(rtDW.Controller_InstanceData.rtdw));

    /* Update for ModelReference: '<Root>/Controller1' */
    Controller_Update(&(rtDW.Controller1_InstanceData.rtm),
                      &(rtDW.Controller1_InstanceData.rtdw));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(rtM)) {
    rt_ertODEUpdateContinuousStates(&rtM->solverInfo);

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

    rtM->Timing.t[0] = rtsiGetSolverStopTime(&rtM->solverInfo);

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
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void DCMotor_Control_derivatives(void)
{
  XDot *_rtXdot;
  _rtXdot = ((XDot *) rtM->derivs);

  /* Derivatives for SimscapeExecutionBlock: '<S14>/STATE_1' */
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[0] = 0.0;
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[1] = 0.0;
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[2] = 0.0;
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[0] += -199191.464056792 *
    rtX.DCMotor_ControlDC_Motor_Simscap[0];
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[1] += 1.1860623188219483E+8 *
    rtX.DCMotor_ControlDC_Motor_Simscap[0];
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[0] += -28.2610464664868 *
    rtX.DCMotor_ControlDC_Motor_Simscap[1];
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[1] += -2991.464393393057 *
    rtX.DCMotor_ControlDC_Motor_Simscap[1];
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[2] += 0.004 *
    rtX.DCMotor_ControlDC_Motor_Simscap[1];
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[0] += 83354.171677110935 *
    rtDW.INPUT_1_1_1[0];
  _rtXdot->DCMotor_ControlDC_Motor_Simscap[1] += 0.11860623188219484 *
    rtDW.INPUT_1_1_1[0];
}

/* Model initialize function */
void DCMotor_Control_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetdXPtr(&rtM->solverInfo, &rtM->derivs);
    rtsiSetContStatesPtr(&rtM->solverInfo, (real_T **) &rtM->contStates);
    rtsiSetNumContStatesPtr(&rtM->solverInfo, &rtM->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&rtM->solverInfo,
      &rtM->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&rtM->solverInfo,
      &rtM->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&rtM->solverInfo,
      &rtM->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, (&rtmGetErrorStatus(rtM)));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtM->intgData.y = rtM->odeY;
  rtM->intgData.f[0] = rtM->odeF[0];
  rtM->intgData.f[1] = rtM->odeF[1];
  rtM->intgData.f[2] = rtM->odeF[2];
  rtM->contStates = ((X *) &rtX);
  rtsiSetSolverData(&rtM->solverInfo, (void *)&rtM->intgData);
  rtsiSetSolverName(&rtM->solverInfo,"ode3");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 1.0E-5;

  /* Model Initialize function for ModelReference Block: '<Root>/Controller' */
  Controller_initialize(rtmGetErrorStatusPointer(rtM), &(rtM->solverInfo),
                        &(rtDW.Controller_InstanceData.rtm),
                        &(rtDW.Controller_InstanceData.rtdw));

  /* Model Initialize function for ModelReference Block: '<Root>/Controller1' */
  Controller_initialize(rtmGetErrorStatusPointer(rtM), &(rtM->solverInfo),
                        &(rtDW.Controller1_InstanceData.rtm),
                        &(rtDW.Controller1_InstanceData.rtdw));

  {
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp_0;

    /* Start for SimscapeExecutionBlock: '<S14>/STATE_1' */
    tmp = nesl_lease_simulator(
      "DCMotor_Control/DC_Motor_Simscape_Motor/Solver Configuration_1", 0, 0);
    rtDW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(rtDW.STATE_1_Simulator);
    if (tmp_0) {
      DCMotor_Control_4a109994_1_gateway();
      tmp = nesl_lease_simulator(
        "DCMotor_Control/DC_Motor_Simscape_Motor/Solver Configuration_1", 0, 0);
      rtDW.STATE_1_Simulator = (void *)tmp;
    }

    tmp_1 = nesl_create_simulation_data();
    rtDW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    rtDW.STATE_1_DiagMgr = (void *)diagnosticManager;
    rtDW.modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    rtDW.modelParameters.mSolverTolerance = 0.001;
    rtDW.modelParameters.mVariableStepSolver = false;
    rtDW.modelParameters.mIsUsingODEN = false;
    rtDW.modelParameters.mFixedStepSize = 1.0E-5;
    rtDW.modelParameters.mStartTime = 0.0;
    rtDW.modelParameters.mLoadInitialState = false;
    rtDW.modelParameters.mUseSimState = false;
    rtDW.modelParameters.mLinTrimCompile = false;
    rtDW.modelParameters.mLoggingMode = SSC_LOGGING_NONE;
    rtDW.modelParameters.mRTWModifiedTimeStamp = 5.78363684E+8;
    rtDW.modelParameters.mZcDisabled = false;
    tmp_2 = 0.001;
    rtDW.modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 1.0E-5;
    rtDW.modelParameters.mFixedStepSize = tmp_2;
    tmp_0 = false;
    rtDW.modelParameters.mVariableStepSolver = tmp_0;
    tmp_0 = false;
    rtDW.modelParameters.mIsUsingODEN = tmp_0;
    rtDW.modelParameters.mLoadInitialState = false;
    rtDW.modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)rtDW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)rtDW.STATE_1_Simulator,
      &rtDW.modelParameters, diagnosticManager);
    if (tmp_3 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(rtM));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(rtM, msg);
      }
    }

    rtDW.STATE_1_FirstOutput = true;

    /* End of Start for SimscapeExecutionBlock: '<S14>/STATE_1' */

    /* Start for FromWorkspace: '<S2>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 4.0,
        4.0, 5.0, 5.0, 6.0, 6.0, 7.0, 7.0, 8.0, 8.0, 9.0, 9.0, 10.0, 10.0, 11.0,
        11.0, 12.0, 12.0, 13.0, 13.0, 14.0, 14.0, 15.0, 15.0, 16.0, 16.0, 17.0,
        17.0, 18.0, 18.0, 19.0, 19.0, 20.0, 20.0, 21.0, 21.0, 22.0, 22.0, 23.0,
        23.0, 24.0, 24.0, 25.0, 25.0, 26.0, 26.0, 27.0, 27.0, 28.0, 28.0, 30.0 }
      ;

      static real_T pDataValues0[] = { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 2.0,
        2.0, 2.0, 2.0, 3.0, 3.0, 3.0, 3.0, 4.0, 4.0, 4.0, 4.0, 5.0, 5.0, 5.0,
        5.0, 6.0, 6.0, 6.0, 6.0, 7.0, 7.0, 7.0, 7.0, 6.0, 6.0, 6.0, 6.0, 5.0,
        5.0, 5.0, 5.0, 4.0, 4.0, 4.0, 4.0, 3.0, 3.0, 3.0, 3.0, 2.0, 2.0, 2.0,
        2.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0 } ;

      rtDW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
      rtDW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
      rtDW.FromWs_IWORK.PrevIndex = 0;
    }

    /* SystemInitialize for ModelReference: '<Root>/Controller' */
    Controller_Init(&(rtDW.Controller_InstanceData.rtdw));

    /* SystemInitialize for ModelReference: '<Root>/Controller1' */
    Controller_Init(&(rtDW.Controller1_InstanceData.rtdw));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
