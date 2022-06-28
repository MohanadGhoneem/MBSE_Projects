/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: DCMotor_Control.h
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

#ifndef RTW_HEADER_DCMotor_Control_h_
#define RTW_HEADER_DCMotor_Control_h_
#include <math.h>
#include <string.h>
#ifndef DCMotor_Control_COMMON_INCLUDES_
#define DCMotor_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "nesl_rtw.h"
#include "DCMotor_Control_4a109994_1_gateway.h"
#endif                                 /* DCMotor_Control_COMMON_INCLUDES_ */

/* Child system includes */
#include "Controller.h"

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define DCMotor_Control_M              (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  Controller_MdlrefDW Controller_InstanceData;/* '<Root>/Controller' */
  Controller_MdlrefDW Controller1_InstanceData;/* '<Root>/Controller1' */
  NeModelParameters modelParameters;
  real_T STATE_1[3];                   /* '<S14>/STATE_1' */
  real_T INPUT_1_1_1[4];               /* '<S14>/INPUT_1_1_1' */
  real_T INPUT_1_1_1_Discrete[2];      /* '<S14>/INPUT_1_1_1' */
  real_T dv[4];
  real_T OUTPUT_1_1[2];                /* '<S14>/OUTPUT_1_1' */
  real_T dv1[4];
  real_T Controller_k;                 /* '<Root>/Controller' */
  real_T Controller1;                  /* '<Root>/Controller1' */
  real_T STATE_1_Discrete;             /* '<S14>/STATE_1' */
  real_T OUTPUT_1_1_Discrete;          /* '<S14>/OUTPUT_1_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S14>/OUTPUT_1_0' */
  real_T time;
  int_T STATE_1_Modes;                 /* '<S14>/STATE_1' */
  int_T OUTPUT_1_1_Modes;              /* '<S14>/OUTPUT_1_1' */
  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S2>/FromWs' */

  int_T OUTPUT_1_0_Modes;              /* '<S14>/OUTPUT_1_0' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S2>/FromWs' */

  void* STATE_1_Simulator;             /* '<S14>/STATE_1' */
  void* STATE_1_SimData;               /* '<S14>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S14>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S14>/STATE_1' */
  void* STATE_1_TsIndex;               /* '<S14>/STATE_1' */
  void* OUTPUT_1_1_Simulator;          /* '<S14>/OUTPUT_1_1' */
  void* OUTPUT_1_1_SimData;            /* '<S14>/OUTPUT_1_1' */
  void* OUTPUT_1_1_DiagMgr;            /* '<S14>/OUTPUT_1_1' */
  void* OUTPUT_1_1_ZcLogger;           /* '<S14>/OUTPUT_1_1' */
  void* OUTPUT_1_1_TsIndex;            /* '<S14>/OUTPUT_1_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S14>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsIndex;            /* '<S14>/OUTPUT_1_0' */
  boolean_T STATE_1_FirstOutput;       /* '<S14>/STATE_1' */
  boolean_T OUTPUT_1_1_FirstOutput;    /* '<S14>/OUTPUT_1_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S14>/OUTPUT_1_0' */
} DW;

/* Continuous states (default storage) */
typedef struct {
  real_T DCMotor_ControlDC_Motor_Simscap[3];/* '<S14>/STATE_1' */
} X;

/* State derivatives (default storage) */
typedef struct {
  real_T DCMotor_ControlDC_Motor_Simscap[3];/* '<S14>/STATE_1' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T DCMotor_ControlDC_Motor_Simscap[3];/* '<S14>/STATE_1' */
} XDis;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

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
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Continuous states (default storage) */
extern X rtX;

/* Block signals and states (default storage) */
extern DW rtDW;

/* Model entry point functions */
extern void DCMotor_Control_initialize(void);
extern void DCMotor_Control_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Add' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope6' : Unused code path elimination
 * Block '<Root>/Scope7' : Unused code path elimination
 * Block '<Root>/Scope8' : Unused code path elimination
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
 * '<Root>' : 'DCMotor_Control'
 * '<S1>'   : 'DCMotor_Control/DC_Motor_Simscape_Motor'
 * '<S2>'   : 'DCMotor_Control/Signal Builder'
 * '<S3>'   : 'DCMotor_Control/DC_Motor_Simscape_Motor/PS-Simulink Converter'
 * '<S4>'   : 'DCMotor_Control/DC_Motor_Simscape_Motor/PS-Simulink Converter1'
 * '<S5>'   : 'DCMotor_Control/DC_Motor_Simscape_Motor/PS-Simulink Converter2'
 * '<S6>'   : 'DCMotor_Control/DC_Motor_Simscape_Motor/PS-Simulink Converter3'
 * '<S7>'   : 'DCMotor_Control/DC_Motor_Simscape_Motor/Simulink-PS Converter'
 * '<S8>'   : 'DCMotor_Control/DC_Motor_Simscape_Motor/Solver Configuration'
 * '<S9>'   : 'DCMotor_Control/DC_Motor_Simscape_Motor/PS-Simulink Converter/EVAL_KEY'
 * '<S10>'  : 'DCMotor_Control/DC_Motor_Simscape_Motor/PS-Simulink Converter1/EVAL_KEY'
 * '<S11>'  : 'DCMotor_Control/DC_Motor_Simscape_Motor/PS-Simulink Converter2/EVAL_KEY'
 * '<S12>'  : 'DCMotor_Control/DC_Motor_Simscape_Motor/PS-Simulink Converter3/EVAL_KEY'
 * '<S13>'  : 'DCMotor_Control/DC_Motor_Simscape_Motor/Simulink-PS Converter/EVAL_KEY'
 * '<S14>'  : 'DCMotor_Control/DC_Motor_Simscape_Motor/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_DCMotor_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
