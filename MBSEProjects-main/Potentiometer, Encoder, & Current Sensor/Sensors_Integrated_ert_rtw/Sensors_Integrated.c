/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Sensors_Integrated.c
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

#include "Sensors_Integrated.h"
#include "Sensors_Integrated_private.h"

/* Forward declaration for local functions */
static real_T xnrm2(int32_T n, const real_T x[32], int32_T ix0);
static void qrpf(real_T A[32], int32_T ia0, int32_T m, int32_T n, real_T tau[2],
                 int32_T jpvt[2]);
static void polyfit(const real_T x[16], const real_T y[16], real_T p[2]);

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static real_T xnrm2(int32_T n, const real_T x[32], int32_T ix0)
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void qrpf(real_T A[32], int32_T ia0, int32_T m, int32_T n, real_T tau[2],
                 int32_T jpvt[2])
{
  real_T vn1[2];
  real_T vn2[2];
  real_T work[2];
  real_T s;
  real_T smax;
  int32_T b_j;
  int32_T c_ix;
  int32_T c_j;
  int32_T d;
  int32_T exitg1;
  int32_T ia;
  int32_T ii;
  int32_T ii_tmp;
  int32_T ix;
  int32_T iy;
  int32_T minmn;
  int32_T mmi;
  int32_T nmi;
  int32_T pvt;
  boolean_T exitg2;
  if (m <= n) {
    minmn = m;
  } else {
    minmn = n;
  }

  work[0] = 0.0;
  vn1[0] = 0.0;
  vn2[0] = 0.0;
  work[1] = 0.0;
  vn1[1] = 0.0;
  vn2[1] = 0.0;
  for (b_j = 0; b_j < n; b_j++) {
    vn1[b_j] = xnrm2(m, A, (b_j << 4) + ia0);
    vn2[b_j] = vn1[b_j];
  }

  for (b_j = 0; b_j < minmn; b_j++) {
    c_j = b_j + 1;
    ii_tmp = (b_j << 4) + ia0;
    ii = (ii_tmp + b_j) - 1;
    nmi = n - b_j;
    mmi = m - b_j;
    if (nmi < 1) {
      pvt = -1;
    } else {
      pvt = 0;
      if (nmi > 1) {
        ix = b_j;
        smax = fabs(vn1[b_j]);
        for (iy = 2; iy <= nmi; iy++) {
          ix++;
          s = fabs(vn1[ix]);
          if (s > smax) {
            pvt = iy - 1;
            smax = s;
          }
        }
      }
    }

    pvt += b_j;
    if (pvt + 1 != b_j + 1) {
      ix = ((pvt << 4) + ia0) - 1;
      iy = ii_tmp - 1;
      for (ii_tmp = 0; ii_tmp < m; ii_tmp++) {
        smax = A[ix];
        A[ix] = A[iy];
        A[iy] = smax;
        ix++;
        iy++;
      }

      ix = jpvt[pvt];
      jpvt[pvt] = jpvt[b_j];
      jpvt[b_j] = ix;
      vn1[pvt] = vn1[b_j];
      vn2[pvt] = vn2[b_j];
    }

    if (b_j + 1 < m) {
      s = A[ii];
      tau[b_j] = 0.0;
      if (mmi > 0) {
        smax = xnrm2(mmi - 1, A, ii + 2);
        if (smax != 0.0) {
          smax = rt_hypotd_snf(A[ii], smax);
          if (A[ii] >= 0.0) {
            smax = -smax;
          }

          if (fabs(smax) < 1.0020841800044864E-292) {
            pvt = -1;
            ix = ii + mmi;
            do {
              pvt++;
              for (iy = ii + 1; iy < ix; iy++) {
                A[iy] *= 9.9792015476736E+291;
              }

              smax *= 9.9792015476736E+291;
              s *= 9.9792015476736E+291;
            } while (!(fabs(smax) >= 1.0020841800044864E-292));

            smax = rt_hypotd_snf(s, xnrm2(mmi - 1, A, ii + 2));
            if (s >= 0.0) {
              smax = -smax;
            }

            tau[b_j] = (smax - s) / smax;
            s = 1.0 / (s - smax);
            for (iy = ii + 1; iy < ix; iy++) {
              A[iy] *= s;
            }

            for (ix = 0; ix <= pvt; ix++) {
              smax *= 1.0020841800044864E-292;
            }

            s = smax;
          } else {
            tau[b_j] = (smax - A[ii]) / smax;
            s = 1.0 / (A[ii] - smax);
            pvt = ii + mmi;
            for (ix = ii + 1; ix < pvt; ix++) {
              A[ix] *= s;
            }

            s = smax;
          }
        }
      }

      A[ii] = s;
    } else {
      tau[b_j] = 0.0;
    }

    if (b_j + 1 < n) {
      smax = A[ii];
      A[ii] = 1.0;
      if (tau[b_j] != 0.0) {
        pvt = mmi - 1;
        ix = (ii + mmi) - 1;
        while ((pvt + 1 > 0) && (A[ix] == 0.0)) {
          pvt--;
          ix--;
        }

        nmi -= 2;
        exitg2 = false;
        while ((!exitg2) && (nmi + 1 > 0)) {
          ix = ((nmi << 4) + ii) + 17;
          iy = ix;
          do {
            exitg1 = 0;
            if (iy <= ix + pvt) {
              if (A[iy - 1] != 0.0) {
                exitg1 = 1;
              } else {
                iy++;
              }
            } else {
              nmi--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        pvt = -1;
        nmi = -1;
      }

      if (pvt + 1 > 0) {
        if (nmi + 1 != 0) {
          for (ix = 0; ix <= nmi; ix++) {
            work[ix] = 0.0;
          }

          ix = 0;
          iy = ((nmi << 4) + ii) + 17;
          for (ii_tmp = ii + 17; ii_tmp <= iy; ii_tmp += 16) {
            c_ix = ii;
            s = 0.0;
            d = ii_tmp + pvt;
            for (ia = ii_tmp; ia <= d; ia++) {
              s += A[ia - 1] * A[c_ix];
              c_ix++;
            }

            work[ix] += s;
            ix++;
          }
        }

        if (!(-tau[b_j] == 0.0)) {
          ix = ii + 16;
          iy = 0;
          for (ii_tmp = 0; ii_tmp <= nmi; ii_tmp++) {
            if (work[iy] != 0.0) {
              s = work[iy] * -tau[b_j];
              c_ix = ii;
              d = ix;
              ia = pvt + ix;
              while (d + 1 <= ia + 1) {
                A[d] += A[c_ix] * s;
                c_ix++;
                d++;
              }
            }

            iy++;
            ix += 16;
          }
        }
      }

      A[ii] = smax;
    }

    while (c_j + 1 <= n) {
      ii = (ia0 + b_j) + (c_j << 4);
      if (vn1[c_j] != 0.0) {
        smax = fabs(A[ii - 1]) / vn1[c_j];
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        s = vn1[c_j] / vn2[c_j];
        s = s * s * smax;
        if (s <= 1.4901161193847656E-8) {
          if (b_j + 1 < m) {
            vn1[c_j] = xnrm2(mmi - 1, A, ii + 1);
            vn2[c_j] = vn1[c_j];
          } else {
            vn1[c_j] = 0.0;
            vn2[c_j] = 0.0;
          }
        } else {
          vn1[c_j] *= sqrt(smax);
        }
      }

      c_j++;
    }
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void polyfit(const real_T x[16], const real_T y[16], real_T p[2])
{
  real_T V[32];
  real_T B_0[16];
  real_T tau[2];
  real_T wj;
  int32_T jpvt[2];
  int32_T assumedRank;
  int32_T d_i;
  int32_T p_tmp;
  for (assumedRank = 0; assumedRank < 16; assumedRank++) {
    V[assumedRank + 16] = 1.0;
    V[assumedRank] = x[assumedRank];
    B_0[assumedRank] = y[assumedRank];
  }

  jpvt[0] = 1;
  tau[0] = 0.0;
  jpvt[1] = 2;
  tau[1] = 0.0;
  qrpf(V, 1, 16, 2, tau, jpvt);
  assumedRank = -1;
  if (V[0] != 0.0) {
    assumedRank = 0;
  }

  if (V[17] != 0.0) {
    assumedRank++;
  }

  p[0] = 0.0;
  if (tau[0] != 0.0) {
    wj = B_0[0];
    for (d_i = 1; d_i + 1 < 17; d_i++) {
      wj += V[d_i] * B_0[d_i];
    }

    wj *= tau[0];
    if (wj != 0.0) {
      B_0[0] -= wj;
      for (d_i = 1; d_i + 1 < 17; d_i++) {
        B_0[d_i] -= V[d_i] * wj;
      }
    }
  }

  p[1] = 0.0;
  if (tau[1] != 0.0) {
    wj = B_0[1];
    for (d_i = 2; d_i + 1 < 17; d_i++) {
      wj += V[d_i + 16] * B_0[d_i];
    }

    wj *= tau[1];
    if (wj != 0.0) {
      B_0[1] -= wj;
      for (d_i = 2; d_i + 1 < 17; d_i++) {
        B_0[d_i] -= V[d_i + 16] * wj;
      }
    }
  }

  for (d_i = 0; d_i <= assumedRank; d_i++) {
    p[jpvt[d_i] - 1] = B_0[d_i];
  }

  while (assumedRank + 1 > 0) {
    p_tmp = assumedRank << 4;
    p[jpvt[assumedRank] - 1] /= V[p_tmp + assumedRank];
    for (d_i = 0; d_i < assumedRank; d_i++) {
      p[jpvt[d_i] - 1] -= V[p_tmp + d_i] * p[jpvt[assumedRank] - 1];
    }

    assumedRank--;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Sensors_Integrated_step(RT_MODEL *const rtM, uint8_T rtU_A, uint8_T rtU_B_j,
  uint8_T rtU_potAnalog_in, uint8_T rtU_currAnalog_in, uint8_T *rtY_currFlag,
  uint8_T *rtY_dirFlag)
{
  B *rtB = rtM->blockIO;
  DW *rtDW = rtM->dwork;
  PrevZCX *rtPrevZCX = rtM->prevZCSigState;
  real_T tmp[16];
  real_T tmp_0[16];
  real_T p[2];
  real_T tmp_1;
  real_T u;
  int32_T i;
  uint8_T tmp_2;
  boolean_T rtb_Relay1;
  ZCEventType zcEvent;

  /* Outputs for Atomic SubSystem: '<Root>/Current_Sensor' */
  /* MATLAB Function: '<S1>/MATLAB Function' */
  for (i = 0; i < 16; i++) {
    tmp[i] = 17.0 * (real_T)i;
    tmp_0[i] = 10.0 * (real_T)i;
  }

  polyfit(tmp, tmp_0, p);
  u = rt_roundd_snf(p[1]);
  if (u < 256.0) {
    if (u >= 0.0) {
      tmp_2 = (uint8_T)u;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/currAnalog_in'
   *  MATLAB Function: '<S1>/MATLAB Function'
   *  Product: '<S1>/Divide'
   *  Sum: '<S1>/Add'
   */
  u = floor((real_T)rtU_currAnalog_in * p[0] + (real_T)tmp_2);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 65536.0);
  }

  /* RelationalOperator: '<Root>/Relational Operator' incorporates:
   *  Constant: '<Root>/Constant'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  rtb_Relay1 = ((u < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u : (int32_T)
                 (uint16_T)u) >= rtP.Constant_Value_f);

  /* End of Outputs for SubSystem: '<Root>/Current_Sensor' */

  /* Relay: '<Root>/Relay' */
  rtDW->Relay_Mode = (((int32_T)rtb_Relay1 >= (int32_T)rtP.Relay_OnVal) ||
                      (((int32_T)rtb_Relay1 > (int32_T)rtP.Relay_OffVal) &&
                       rtDW->Relay_Mode));
  if (rtDW->Relay_Mode) {
    /* Outport: '<Root>/currFlag' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    *rtY_currFlag = rtP.Relay_YOn;
  } else {
    /* Outport: '<Root>/currFlag' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    *rtY_currFlag = rtP.Relay_YOff;
  }

  /* End of Relay: '<Root>/Relay' */

  /* Outputs for Atomic SubSystem: '<Root>/Pulse_Decode' */
  /* Outputs for Triggered SubSystem: '<S3>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/A'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &rtPrevZCX->TriggeredSubsystem_Trig_ZCE,
                     ((real_T)rtU_A));
  if (zcEvent != NO_ZCEVENT) {
    /* UnitDelay: '<S6>/Unit Delay' */
    rtB->UnitDelay = rtDW->UnitDelay_DSTATE;

    /* Sum: '<S3>/Sum1' incorporates:
     *  Constant: '<S3>/Constant'
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     *  Inport: '<Root>/B'
     */
    u = rtP.Constant_Value - (real_T)rtU_B_j;

    /* Signum: '<S3>/Sign' */
    if (u < 0.0) {
      u = -1.0;
    } else if (u > 0.0) {
      u = 1.0;
    } else if (u == 0.0) {
      u = 0.0;
    } else {
      u = (rtNaN);
    }

    /* End of Signum: '<S3>/Sign' */

    /* Update for UnitDelay: '<S6>/Unit Delay' incorporates:
     *  Sum: '<S6>/Sum1'
     */
    rtDW->UnitDelay_DSTATE = u + rtB->UnitDelay;
  }

  /* End of Outputs for SubSystem: '<S3>/Triggered Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Pulse_Decode' */

  /* Outputs for Atomic SubSystem: '<Root>/Potentiometer' */
  /* MATLAB Function: '<S2>/MATLAB Function' */
  for (i = 0; i < 16; i++) {
    tmp[i] = 17.0 * (real_T)i;
    tmp_0[i] = 24.0 * (real_T)i;
  }

  polyfit(tmp, tmp_0, p);

  /* End of Outputs for SubSystem: '<Root>/Potentiometer' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Gain: '<Root>/Gain'
   */
  u = floor(rtP.Gain_Gain * rtB->UnitDelay);
  if (rtIsNaN(u) || rtIsInf(u)) {
    u = 0.0;
  } else {
    u = fmod(u, 65536.0);
  }

  /* Outputs for Atomic SubSystem: '<Root>/Potentiometer' */
  /* MATLAB Function: '<S2>/MATLAB Function' */
  tmp_1 = rt_roundd_snf(p[1]);
  if (tmp_1 < 256.0) {
    if (tmp_1 >= 0.0) {
      tmp_2 = (uint8_T)tmp_1;
    } else {
      tmp_2 = 0U;
    }
  } else {
    tmp_2 = MAX_uint8_T;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/potAnalog_in'
   *  MATLAB Function: '<S2>/MATLAB Function'
   *  Product: '<S2>/Divide'
   *  Sum: '<S2>/Add'
   */
  tmp_1 = floor((real_T)rtU_potAnalog_in * p[0] + (real_T)tmp_2);
  if (rtIsNaN(tmp_1) || rtIsInf(tmp_1)) {
    tmp_1 = 0.0;
  } else {
    tmp_1 = fmod(tmp_1, 65536.0);
  }

  /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  rtb_Relay1 = ((u < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-u : (int32_T)
                 (uint16_T)u) == (tmp_1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp_1 : (int32_T)(uint16_T)tmp_1));

  /* End of Outputs for SubSystem: '<Root>/Potentiometer' */

  /* Relay: '<Root>/Relay1' */
  rtDW->Relay1_Mode = (((int32_T)rtb_Relay1 >= (int32_T)rtP.Relay1_OnVal) ||
                       (((int32_T)rtb_Relay1 > (int32_T)rtP.Relay1_OffVal) &&
                        rtDW->Relay1_Mode));
  if (rtDW->Relay1_Mode) {
    /* Outport: '<Root>/dirFlag' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    *rtY_dirFlag = rtP.Relay1_YOn;
  } else {
    /* Outport: '<Root>/dirFlag' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    *rtY_dirFlag = rtP.Relay1_YOff;
  }

  /* End of Relay: '<Root>/Relay1' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[0] =
    ((time_T)(++rtM->Timing.clockTick0)) * rtM->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Sensors_Integrated_initialize(RT_MODEL *const rtM, uint8_T *rtU_A, uint8_T *
  rtU_B_j, uint8_T *rtU_potAnalog_in, uint8_T *rtU_currAnalog_in, uint8_T
  *rtY_currFlag, uint8_T *rtY_dirFlag)
{
  B *rtB = rtM->blockIO;
  DW *rtDW = rtM->dwork;
  PrevZCX *rtPrevZCX = rtM->prevZCSigState;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

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
  rtM->Timing.stepSize0 = 0.2;

  /* block I/O */
  (void) memset(((void *) rtB), 0,
                sizeof(B));

  /* states (dwork) */
  (void) memset((void *)rtDW, 0,
                sizeof(DW));

  /* external inputs */
  *rtU_A = 0U;
  *rtU_B_j = 0U;
  *rtU_potAnalog_in = 0U;
  *rtU_currAnalog_in = 0U;

  /* external outputs */
  *rtY_currFlag = 0U;
  *rtY_dirFlag = 0U;
  rtPrevZCX->TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Pulse_Decode' */
  /* SystemInitialize for Triggered SubSystem: '<S3>/Triggered Subsystem' */
  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
  rtDW->UnitDelay_DSTATE = rtP.UnitDelay_InitialCondition;

  /* SystemInitialize for UnitDelay: '<S6>/Unit Delay' incorporates:
   *  Outport: '<S6>/Pulse count'
   */
  rtB->UnitDelay = rtP.Pulsecount_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Triggered Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Pulse_Decode' */
}

/* Model terminate function */
void Sensors_Integrated_terminate(RT_MODEL *const rtM)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(rtM);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
