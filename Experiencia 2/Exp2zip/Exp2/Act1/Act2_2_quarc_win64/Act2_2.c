/*
 * Act2_2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Act2_2".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 16 16:50:56 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Act2_2.h"
#include "Act2_2_private.h"
#include "Act2_2_dt.h"

/* Block signals (default storage) */
B_Act2_2_T Act2_2_B;

/* Continuous states */
X_Act2_2_T Act2_2_X;

/* Block states (default storage) */
DW_Act2_2_T Act2_2_DW;

/* Real-time model */
static RT_MODEL_Act2_2_T Act2_2_M_;
RT_MODEL_Act2_2_T *const Act2_2_M = &Act2_2_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Act2_2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Act2_2_output(void)
{
  if (rtmIsMajorTimeStep(Act2_2_M)) {
    /* set solver stop time */
    if (!(Act2_2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Act2_2_M->solverInfo,
                            ((Act2_2_M->Timing.clockTickH0 + 1) *
        Act2_2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Act2_2_M->solverInfo, ((Act2_2_M->Timing.clockTick0
        + 1) * Act2_2_M->Timing.stepSize0 + Act2_2_M->Timing.clockTickH0 *
        Act2_2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Act2_2_M)) {
    Act2_2_M->Timing.t[0] = rtsiGetT(&Act2_2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Act2_2_M)) {
  }

  /* Integrator: '<Root>/Integrator' */
  Act2_2_B.Vo = Act2_2_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(Act2_2_M)) {
    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: Act2_2/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(Act2_2_DW.HILInitialize_Card,
        &Act2_2_P.HILWriteAnalog_channels, 1, &Act2_2_B.Vo);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

    /* S-Function Block: Act2_2/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(Act2_2_DW.HILInitialize_Card,
        &Act2_2_P.HILReadAnalog_channels, 1, &Act2_2_DW.HILReadAnalog_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_M, _rt_error_message);
      }

      Act2_2_B.HILReadAnalog = Act2_2_DW.HILReadAnalog_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum'
   */
  Act2_2_B.Gain = (Act2_2_B.HILReadAnalog - Act2_2_B.Vo) * Act2_2_P.Gain_Gain;
  if (rtmIsMajorTimeStep(Act2_2_M)) {
  }

  /* Gain: '<Root>/Gain1' */
  Act2_2_B.Gain1 = Act2_2_P.Gain1_Gain * Act2_2_B.Gain;
  if (rtmIsMajorTimeStep(Act2_2_M)) {
  }
}

/* Model update function */
void Act2_2_update(void)
{
  if (rtmIsMajorTimeStep(Act2_2_M)) {
    rt_ertODEUpdateContinuousStates(&Act2_2_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Act2_2_M->Timing.clockTick0)) {
    ++Act2_2_M->Timing.clockTickH0;
  }

  Act2_2_M->Timing.t[0] = rtsiGetSolverStopTime(&Act2_2_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Act2_2_M->Timing.clockTick1)) {
      ++Act2_2_M->Timing.clockTickH1;
    }

    Act2_2_M->Timing.t[1] = Act2_2_M->Timing.clockTick1 *
      Act2_2_M->Timing.stepSize1 + Act2_2_M->Timing.clockTickH1 *
      Act2_2_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Act2_2_derivatives(void)
{
  XDot_Act2_2_T *_rtXdot;
  _rtXdot = ((XDot_Act2_2_T *) Act2_2_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Act2_2_B.Gain1;
}

/* Model initialize function */
void Act2_2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Act2_2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("ni_pci_6221_37_pin", "0", &Act2_2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act2_2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Act2_2_DW.HILInitialize_Card, " ", 2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act2_2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Act2_2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act2_2_M, _rt_error_message);
      return;
    }

    if ((Act2_2_P.HILInitialize_AIPStart && !is_switching) ||
        (Act2_2_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Act2_2_DW.HILInitialize_Card,
        &Act2_2_P.HILInitialize_AIChannels, 1U,
        &Act2_2_P.HILInitialize_AILow, &Act2_2_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_M, _rt_error_message);
        return;
      }
    }

    if ((Act2_2_P.HILInitialize_AOPStart && !is_switching) ||
        (Act2_2_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Act2_2_DW.HILInitialize_Card,
        &Act2_2_P.HILInitialize_AOChannels, 1U,
        &Act2_2_P.HILInitialize_AOLow, &Act2_2_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_M, _rt_error_message);
        return;
      }
    }

    if ((Act2_2_P.HILInitialize_AOStart && !is_switching) ||
        (Act2_2_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Act2_2_DW.HILInitialize_Card,
        &Act2_2_P.HILInitialize_AOChannels, 1U,
        &Act2_2_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Act2_2_X.Integrator_CSTATE = Act2_2_P.Integrator_IC;
}

/* Model terminate function */
void Act2_2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Act2_2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Act2_2_DW.HILInitialize_Card);
    hil_monitor_stop_all(Act2_2_DW.HILInitialize_Card);
    is_switching = false;
    if ((Act2_2_P.HILInitialize_AOTerminate && !is_switching) ||
        (Act2_2_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Act2_2_DW.HILInitialize_Card,
        &Act2_2_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Act2_2_P.HILInitialize_AOFinal);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Act2_2_DW.HILInitialize_Card);
    hil_monitor_delete_all(Act2_2_DW.HILInitialize_Card);
    hil_close(Act2_2_DW.HILInitialize_Card);
    Act2_2_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Act2_2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Act2_2_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Act2_2_initialize();
}

void MdlTerminate(void)
{
  Act2_2_terminate();
}

/* Registration function */
RT_MODEL_Act2_2_T *Act2_2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Act2_2_M, 0,
                sizeof(RT_MODEL_Act2_2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Act2_2_M->solverInfo, &Act2_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Act2_2_M->solverInfo, &rtmGetTPtr(Act2_2_M));
    rtsiSetStepSizePtr(&Act2_2_M->solverInfo, &Act2_2_M->Timing.stepSize0);
    rtsiSetdXPtr(&Act2_2_M->solverInfo, &Act2_2_M->derivs);
    rtsiSetContStatesPtr(&Act2_2_M->solverInfo, (real_T **)
                         &Act2_2_M->contStates);
    rtsiSetNumContStatesPtr(&Act2_2_M->solverInfo,
      &Act2_2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Act2_2_M->solverInfo,
      &Act2_2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Act2_2_M->solverInfo,
      &Act2_2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Act2_2_M->solverInfo,
      &Act2_2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Act2_2_M->solverInfo, (&rtmGetErrorStatus(Act2_2_M)));
    rtsiSetRTModelPtr(&Act2_2_M->solverInfo, Act2_2_M);
  }

  rtsiSetSimTimeStep(&Act2_2_M->solverInfo, MAJOR_TIME_STEP);
  Act2_2_M->intgData.f[0] = Act2_2_M->odeF[0];
  Act2_2_M->contStates = ((real_T *) &Act2_2_X);
  rtsiSetSolverData(&Act2_2_M->solverInfo, (void *)&Act2_2_M->intgData);
  rtsiSetSolverName(&Act2_2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Act2_2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Act2_2_M points to
       static memory which is guaranteed to be non-NULL" */
    Act2_2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Act2_2_M->Timing.sampleTimes = (&Act2_2_M->Timing.sampleTimesArray[0]);
    Act2_2_M->Timing.offsetTimes = (&Act2_2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Act2_2_M->Timing.sampleTimes[0] = (0.0);
    Act2_2_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Act2_2_M->Timing.offsetTimes[0] = (0.0);
    Act2_2_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Act2_2_M, &Act2_2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Act2_2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Act2_2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Act2_2_M, 30.0);
  Act2_2_M->Timing.stepSize0 = 0.001;
  Act2_2_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Act2_2_M->Sizes.checksums[0] = (735078103U);
  Act2_2_M->Sizes.checksums[1] = (917341586U);
  Act2_2_M->Sizes.checksums[2] = (2262710308U);
  Act2_2_M->Sizes.checksums[3] = (224752327U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Act2_2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Act2_2_M->extModeInfo,
      &Act2_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Act2_2_M->extModeInfo, Act2_2_M->Sizes.checksums);
    rteiSetTPtr(Act2_2_M->extModeInfo, rtmGetTPtr(Act2_2_M));
  }

  Act2_2_M->solverInfoPtr = (&Act2_2_M->solverInfo);
  Act2_2_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Act2_2_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Act2_2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Act2_2_M->blockIO = ((void *) &Act2_2_B);
  (void) memset(((void *) &Act2_2_B), 0,
                sizeof(B_Act2_2_T));

  /* parameters */
  Act2_2_M->defaultParam = ((real_T *)&Act2_2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Act2_2_X;
    Act2_2_M->contStates = (x);
    (void) memset((void *)&Act2_2_X, 0,
                  sizeof(X_Act2_2_T));
  }

  /* states (dwork) */
  Act2_2_M->dwork = ((void *) &Act2_2_DW);
  (void) memset((void *)&Act2_2_DW, 0,
                sizeof(DW_Act2_2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Act2_2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Act2_2_M->Sizes.numContStates = (1); /* Number of continuous states */
  Act2_2_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Act2_2_M->Sizes.numY = (0);          /* Number of model outputs */
  Act2_2_M->Sizes.numU = (0);          /* Number of model inputs */
  Act2_2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Act2_2_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  Act2_2_M->Sizes.numBlocks = (14);    /* Number of blocks */
  Act2_2_M->Sizes.numBlockIO = (4);    /* Number of block outputs */
  Act2_2_M->Sizes.numBlockPrms = (102);/* Sum of parameter "widths" */
  return Act2_2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
