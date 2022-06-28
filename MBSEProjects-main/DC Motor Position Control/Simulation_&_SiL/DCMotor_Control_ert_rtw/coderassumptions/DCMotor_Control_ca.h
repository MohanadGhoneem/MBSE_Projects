/*
 * File: DCMotor_Control_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef DCMOTOR_CONTROL_CA_H
#define DCMOTOR_CONTROL_CA_H

/* preprocessor validation checks */
#include "DCMotor_Control_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_DCMotor_Control_HWRes;
extern CA_PWS_TestResults CA_DCMotor_Control_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_DCMotor_Control_ExpHW;
extern CA_HWImpl CA_DCMotor_Control_ActHW;

/* entry point function to run tests */
void DCMotor_Control_caRunTests(void);

#endif                                 /* DCMOTOR_CONTROL_CA_H */
