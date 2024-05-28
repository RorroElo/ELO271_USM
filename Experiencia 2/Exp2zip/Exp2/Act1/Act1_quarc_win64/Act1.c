/*
 * Act1.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Act1".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 16 17:23:54 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Act1.h"
#include "Act1_private.h"
#include "Act1_dt.h"

/* Block signals (default storage) */
B_Act1_T Act1_B;

/* Block states (default storage) */
DW_Act1_T Act1_DW;

/* Real-time model */
static RT_MODEL_Act1_T Act1_M_;
RT_MODEL_Act1_T *const Act1_M = &Act1_M_;

/* Model output function */
void Act1_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog_o2;

  /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

  /* S-Function Block: Act1/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(Act1_DW.HILInitialize_Card,
      Act1_P.HILReadAnalog_channels, 2, &Act1_DW.HILReadAnalog_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act1_M, _rt_error_message);
    }

    Act1_B.HILReadAnalog_o1 = Act1_DW.HILReadAnalog_Buffer[0];
    rtb_HILReadAnalog_o2 = Act1_DW.HILReadAnalog_Buffer[1];
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  Act1_B.SignalGenerator = sin(6.2831853071795862 * Act1_M->Timing.t[0] *
    Act1_P.SignalGenerator_Frequency) * Act1_P.SignalGenerator_Amplitude;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Act1/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Act1_DW.HILInitialize_Card,
      &Act1_P.HILWriteAnalog_channels, 1, &Act1_B.SignalGenerator);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act1_M, _rt_error_message);
    }
  }
}

/* Model update function */
void Act1_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Act1_M->Timing.clockTick0)) {
    ++Act1_M->Timing.clockTickH0;
  }

  Act1_M->Timing.t[0] = Act1_M->Timing.clockTick0 * Act1_M->Timing.stepSize0 +
    Act1_M->Timing.clockTickH0 * Act1_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++Act1_M->Timing.clockTick1)) {
      ++Act1_M->Timing.clockTickH1;
    }

    Act1_M->Timing.t[1] = Act1_M->Timing.clockTick1 * Act1_M->Timing.stepSize1 +
      Act1_M->Timing.clockTickH1 * Act1_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void Act1_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Act1/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("ni_pci_6221_37_pin", "0", &Act1_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act1_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_watchdog_clear(Act1_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act1_M, _rt_error_message);
      return;
    }

    if ((Act1_P.HILInitialize_AIPStart && !is_switching) ||
        (Act1_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Act1_DW.HILInitialize_Card,
        &Act1_P.HILInitialize_AIChannels, 1U,
        &Act1_P.HILInitialize_AILow, &Act1_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act1_M, _rt_error_message);
        return;
      }
    }

    if ((Act1_P.HILInitialize_AOPStart && !is_switching) ||
        (Act1_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Act1_DW.HILInitialize_Card,
        &Act1_P.HILInitialize_AOChannels, 1U,
        &Act1_P.HILInitialize_AOLow, &Act1_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act1_M, _rt_error_message);
        return;
      }
    }

    if ((Act1_P.HILInitialize_AOStart && !is_switching) ||
        (Act1_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Act1_DW.HILInitialize_Card,
        &Act1_P.HILInitialize_AOChannels, 1U, &Act1_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act1_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void Act1_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Act1/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Act1_DW.HILInitialize_Card);
    hil_monitor_stop_all(Act1_DW.HILInitialize_Card);
    is_switching = false;
    if ((Act1_P.HILInitialize_AOTerminate && !is_switching) ||
        (Act1_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Act1_DW.HILInitialize_Card,
        &Act1_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Act1_P.HILInitialize_AOFinal);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act1_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Act1_DW.HILInitialize_Card);
    hil_monitor_delete_all(Act1_DW.HILInitialize_Card);
    hil_close(Act1_DW.HILInitialize_Card);
    Act1_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Act1_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Act1_update();
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
  Act1_initialize();
}

void MdlTerminate(void)
{
  Act1_terminate();
}

/* Registration function */
RT_MODEL_Act1_T *Act1(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Act1_M, 0,
                sizeof(RT_MODEL_Act1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Act1_M->solverInfo, &Act1_M->Timing.simTimeStep);
    rtsiSetTPtr(&Act1_M->solverInfo, &rtmGetTPtr(Act1_M));
    rtsiSetStepSizePtr(&Act1_M->solverInfo, &Act1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Act1_M->solverInfo, (&rtmGetErrorStatus(Act1_M)));
    rtsiSetRTModelPtr(&Act1_M->solverInfo, Act1_M);
  }

  rtsiSetSimTimeStep(&Act1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Act1_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Act1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Act1_M points to
       static memory which is guaranteed to be non-NULL" */
    Act1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Act1_M->Timing.sampleTimes = (&Act1_M->Timing.sampleTimesArray[0]);
    Act1_M->Timing.offsetTimes = (&Act1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Act1_M->Timing.sampleTimes[0] = (0.0);
    Act1_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Act1_M->Timing.offsetTimes[0] = (0.0);
    Act1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Act1_M, &Act1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Act1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Act1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Act1_M, 0.1);
  Act1_M->Timing.stepSize0 = 0.001;
  Act1_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Act1_M->Sizes.checksums[0] = (3112671896U);
  Act1_M->Sizes.checksums[1] = (782765089U);
  Act1_M->Sizes.checksums[2] = (3716830634U);
  Act1_M->Sizes.checksums[3] = (2376740177U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Act1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Act1_M->extModeInfo,
      &Act1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Act1_M->extModeInfo, Act1_M->Sizes.checksums);
    rteiSetTPtr(Act1_M->extModeInfo, rtmGetTPtr(Act1_M));
  }

  Act1_M->solverInfoPtr = (&Act1_M->solverInfo);
  Act1_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Act1_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Act1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Act1_M->blockIO = ((void *) &Act1_B);
  (void) memset(((void *) &Act1_B), 0,
                sizeof(B_Act1_T));

  /* parameters */
  Act1_M->defaultParam = ((real_T *)&Act1_P);

  /* states (dwork) */
  Act1_M->dwork = ((void *) &Act1_DW);
  (void) memset((void *)&Act1_DW, 0,
                sizeof(DW_Act1_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Act1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Act1_M->Sizes.numContStates = (0);   /* Number of continuous states */
  Act1_M->Sizes.numY = (0);            /* Number of model outputs */
  Act1_M->Sizes.numU = (0);            /* Number of model inputs */
  Act1_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  Act1_M->Sizes.numSampTimes = (2);    /* Number of sample times */
  Act1_M->Sizes.numBlocks = (8);       /* Number of blocks */
  Act1_M->Sizes.numBlockIO = (2);      /* Number of block outputs */
  Act1_M->Sizes.numBlockPrms = (110);  /* Sum of parameter "widths" */
  return Act1_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
