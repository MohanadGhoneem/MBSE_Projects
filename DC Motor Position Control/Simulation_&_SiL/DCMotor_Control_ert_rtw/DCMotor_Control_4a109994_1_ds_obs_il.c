/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'DCMotor_Control/DC_Motor_Simscape_Motor/Solver Configuration'.
 */

#include "ne_ds.h"
#include "DCMotor_Control_4a109994_1_ds_sys_struct.h"
#include "DCMotor_Control_4a109994_1_ds_obs_il.h"
#include "DCMotor_Control_4a109994_1_ds.h"
#include "DCMotor_Control_4a109994_1_ds_externals.h"
#include "DCMotor_Control_4a109994_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T DCMotor_Control_4a109994_1_ds_obs_il(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmBoolVector out;
  (void)t1;
  out = t2->mOBS_IL;
  out.mX[0] = false;
  out.mX[1] = true;
  out.mX[2] = false;
  out.mX[3] = false;
  out.mX[4] = false;
  out.mX[5] = false;
  out.mX[6] = false;
  out.mX[7] = false;
  out.mX[8] = false;
  out.mX[9] = false;
  out.mX[10] = true;
  out.mX[11] = true;
  out.mX[12] = true;
  out.mX[13] = true;
  out.mX[14] = true;
  out.mX[15] = true;
  out.mX[16] = true;
  out.mX[17] = false;
  out.mX[18] = true;
  out.mX[19] = true;
  out.mX[20] = false;
  out.mX[21] = false;
  out.mX[22] = true;
  out.mX[23] = false;
  out.mX[24] = true;
  out.mX[25] = true;
  out.mX[26] = true;
  out.mX[27] = true;
  out.mX[28] = true;
  out.mX[29] = true;
  out.mX[30] = true;
  out.mX[31] = true;
  out.mX[32] = true;
  out.mX[33] = true;
  out.mX[34] = true;
  out.mX[35] = true;
  out.mX[36] = true;
  out.mX[37] = true;
  out.mX[38] = true;
  out.mX[39] = true;
  out.mX[40] = true;
  out.mX[41] = true;
  out.mX[42] = false;
  out.mX[43] = false;
  out.mX[44] = true;
  out.mX[45] = false;
  out.mX[46] = false;
  (void)sys;
  (void)t2;
  return 0;
}
