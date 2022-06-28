/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'DCMotor_Control/DC_Motor_Simscape_Motor/Solver Configuration'.
 */

#include "ne_ds.h"
#include "DCMotor_Control_4a109994_1_ds_sys_struct.h"
#include "DCMotor_Control_4a109994_1_ds_log.h"
#include "DCMotor_Control_4a109994_1_ds.h"
#include "DCMotor_Control_4a109994_1_ds_externals.h"
#include "DCMotor_Control_4a109994_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T DCMotor_Control_4a109994_1_ds_log(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t3, NeDsMethodOutput *t4)
{
  PmRealVector out;
  real_T DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T t1;
  U_idx_0 = t3->mU.mX[0];
  X_idx_0 = t3->mX.mX[0];
  X_idx_1 = t3->mX.mX[1];
  X_idx_2 = t3->mX.mX[2];
  out = t4->mLOG;
  DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i = (X_idx_0 *
    -0.9999999976103 + X_idx_1 * 3.390477744584422E-13) + U_idx_0 *
    -9.999999976103E-10;
  t1 = X_idx_1 * 0.004;
  out.mX[0] = DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i;
  out.mX[1] = U_idx_0;
  out.mX[2] = U_idx_0;
  out.mX[3] = U_idx_0;
  out.mX[4] = -DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i;
  out.mX[5] = -DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i;
  out.mX[6] = U_idx_0;
  out.mX[7] = U_idx_0;
  out.mX[8] = -DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i;
  out.mX[9] = X_idx_1;
  out.mX[10] = -DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i;
  out.mX[11] = X_idx_0;
  out.mX[12] = U_idx_0;
  out.mX[13] = DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i *
    DC_Motor_Simscape_Motor_Controlled_Voltage_Source_i * 0.0023897 * 1000.0;
  out.mX[14] = U_idx_0;
  out.mX[15] = X_idx_1 * 9.5492965855137211;
  out.mX[16] = X_idx_1 * 0.004;
  out.mX[17] = X_idx_1;
  out.mX[18] = X_idx_2;
  out.mX[19] = X_idx_1 * 0.004;
  out.mX[20] = t1;
  out.mX[21] = X_idx_2 * 57.295779513082323;
  out.mX[22] = X_idx_2;
  out.mX[23] = t1;
  out.mX[24] = U_idx_0;
  out.mX[25] = U_idx_0;
  out.mX[26] = U_idx_0;
  out.mX[27] = U_idx_0;
  (void)sys;
  (void)t4;
  return 0;
}
