/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Controller_data.c
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

/* Block parameters (default storage) */
P rtP = {
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

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
