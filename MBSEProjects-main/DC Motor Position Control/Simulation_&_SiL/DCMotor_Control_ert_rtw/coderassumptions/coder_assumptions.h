/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "DCMotor_Control_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_DCMotor_Control_ExpHW
#define CA_Actual_HWImpl               CA_DCMotor_Control_ActHW
#define CA_HWImpl_Results              CA_DCMotor_Control_HWRes
#define CA_PortableWordSizes_Results   CA_DCMotor_Control_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   DCMotor_Control_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
