/*
 * Act2_2_e.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Act2_2_e".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 16 17:20:46 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Act2_2_e.h"
#include "Act2_2_e_private.h"
#include "Act2_2_e_dt.h"

/* Block signals (default storage) */
B_Act2_2_e_T Act2_2_e_B;

/* Continuous states */
X_Act2_2_e_T Act2_2_e_X;

/* Block states (default storage) */
DW_Act2_2_e_T Act2_2_e_DW;

/* Real-time model */
static RT_MODEL_Act2_2_e_T Act2_2_e_M_;
RT_MODEL_Act2_2_e_T *const Act2_2_e_M = &Act2_2_e_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Act2_2_e_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Act2_2_e_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (Act2_2_e_M->Timing.TaskCounters.TID[1] == 0) {
    Act2_2_e_M->Timing.RateInteraction.TID1_2 =
      (Act2_2_e_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Act2_2_e_M->Timing.perTaskSampleHits[5] =
      Act2_2_e_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Act2_2_e_M->Timing.TaskCounters.TID[2])++;
  if ((Act2_2_e_M->Timing.TaskCounters.TID[2]) > 499) {/* Sample time: [0.5s, 0.0s] */
    Act2_2_e_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  Act2_2_e_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void Act2_2_e_output0(void)            /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Act2_2_e_M)) {
    /* set solver stop time */
    if (!(Act2_2_e_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Act2_2_e_M->solverInfo,
                            ((Act2_2_e_M->Timing.clockTickH0 + 1) *
        Act2_2_e_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Act2_2_e_M->solverInfo,
                            ((Act2_2_e_M->Timing.clockTick0 + 1) *
        Act2_2_e_M->Timing.stepSize0 + Act2_2_e_M->Timing.clockTickH0 *
        Act2_2_e_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Act2_2_e_M)) {
    Act2_2_e_M->Timing.t[0] = rtsiGetT(&Act2_2_e_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Act2_2_e_M)) {
  }

  /* Integrator: '<Root>/Integrator' */
  Act2_2_e_B.Vo = Act2_2_e_X.Integrator_CSTATE;

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum'
   */
  Act2_2_e_B.Gain = (0.0 - Act2_2_e_B.Vo) * Act2_2_e_P.Gain_Gain;
  if (rtmIsMajorTimeStep(Act2_2_e_M)) {
  }

  /* Gain: '<Root>/Gain1' */
  Act2_2_e_B.Gain1 = Act2_2_e_P.Gain1_Gain * Act2_2_e_B.Gain;

  /* SignalGenerator: '<Root>/Signal Generator' */
  Act2_2_e_B.Vo_e = sin(6.2831853071795862 * Act2_2_e_M->Timing.t[0] *
                        Act2_2_e_P.SignalGenerator_Frequency) *
    Act2_2_e_P.SignalGenerator_Amplitude;
  if (rtmIsMajorTimeStep(Act2_2_e_M)) {
    /* RateTransition generated from: '<Root>/HIL Write Analog' */
    if (Act2_2_e_M->Timing.RateInteraction.TID1_2) {
      Act2_2_e_DW.Vo_Buffer = Act2_2_e_B.Vo_e;
    }

    /* End of RateTransition generated from: '<Root>/HIL Write Analog' */
  }
}

/* Model update function for TID0 */
void Act2_2_e_update0(void)            /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Act2_2_e_M)) {
    rt_ertODEUpdateContinuousStates(&Act2_2_e_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Act2_2_e_M->Timing.clockTick0)) {
    ++Act2_2_e_M->Timing.clockTickH0;
  }

  Act2_2_e_M->Timing.t[0] = rtsiGetSolverStopTime(&Act2_2_e_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Act2_2_e_M->Timing.clockTick1)) {
    ++Act2_2_e_M->Timing.clockTickH1;
  }

  Act2_2_e_M->Timing.t[1] = Act2_2_e_M->Timing.clockTick1 *
    Act2_2_e_M->Timing.stepSize1 + Act2_2_e_M->Timing.clockTickH1 *
    Act2_2_e_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Act2_2_e_derivatives(void)
{
  XDot_Act2_2_e_T *_rtXdot;
  _rtXdot = ((XDot_Act2_2_e_T *) Act2_2_e_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Act2_2_e_B.Gain1;
}

/* Model output function for TID2 */
void Act2_2_e_output2(void)            /* Sample time: [0.5s, 0.0s] */
{
  real_T rtb_Vo;

  /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

  /* S-Function Block: Act2_2_e/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(Act2_2_e_DW.HILInitialize_Card,
      &Act2_2_e_P.HILReadAnalog_channels, 1, &Act2_2_e_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
    }

    Act2_2_e_B.Vo_p = Act2_2_e_DW.HILReadAnalog_Buffer;
  }

  /* RateTransition generated from: '<Root>/HIL Write Analog' */
  rtb_Vo = Act2_2_e_DW.Vo_Buffer;

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: Act2_2_e/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(Act2_2_e_DW.HILInitialize_Card,
      &Act2_2_e_P.HILWriteAnalog_channels, 1, &rtb_Vo);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
    }
  }
}

/* Model update function for TID2 */
void Act2_2_e_update2(void)            /* Sample time: [0.5s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Act2_2_e_M->Timing.clockTick2)) {
    ++Act2_2_e_M->Timing.clockTickH2;
  }

  Act2_2_e_M->Timing.t[2] = Act2_2_e_M->Timing.clockTick2 *
    Act2_2_e_M->Timing.stepSize2 + Act2_2_e_M->Timing.clockTickH2 *
    Act2_2_e_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Act2_2_e_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Act2_2_e_output0();
    break;

   case 2 :
    Act2_2_e_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Act2_2_e_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Act2_2_e_update0();
    break;

   case 2 :
    Act2_2_e_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Act2_2_e_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Act2_2_e/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("ni_pci_6221_37_pin", "0", &Act2_2_e_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Act2_2_e_DW.HILInitialize_Card, " ",
      2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Act2_2_e_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
      return;
    }

    if ((Act2_2_e_P.HILInitialize_AIPStart && !is_switching) ||
        (Act2_2_e_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(Act2_2_e_DW.HILInitialize_Card,
        &Act2_2_e_P.HILInitialize_AIChannels, 1U,
        &Act2_2_e_P.HILInitialize_AILow, &Act2_2_e_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
        return;
      }
    }

    if ((Act2_2_e_P.HILInitialize_AOPStart && !is_switching) ||
        (Act2_2_e_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(Act2_2_e_DW.HILInitialize_Card,
        &Act2_2_e_P.HILInitialize_AOChannels, 1U,
        &Act2_2_e_P.HILInitialize_AOLow, &Act2_2_e_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
        return;
      }
    }

    if ((Act2_2_e_P.HILInitialize_AOStart && !is_switching) ||
        (Act2_2_e_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(Act2_2_e_DW.HILInitialize_Card,
        &Act2_2_e_P.HILInitialize_AOChannels, 1U,
        &Act2_2_e_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Act2_2_e_X.Integrator_CSTATE = Act2_2_e_P.Integrator_IC;
}

/* Model terminate function */
void Act2_2_e_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Act2_2_e/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(Act2_2_e_DW.HILInitialize_Card);
    hil_monitor_stop_all(Act2_2_e_DW.HILInitialize_Card);
    is_switching = false;
    if ((Act2_2_e_P.HILInitialize_AOTerminate && !is_switching) ||
        (Act2_2_e_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Act2_2_e_DW.HILInitialize_Card,
        &Act2_2_e_P.HILInitialize_AOChannels, num_final_analog_outputs,
        &Act2_2_e_P.HILInitialize_AOFinal);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Act2_2_e_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Act2_2_e_DW.HILInitialize_Card);
    hil_monitor_delete_all(Act2_2_e_DW.HILInitialize_Card);
    hil_close(Act2_2_e_DW.HILInitialize_Card);
    Act2_2_e_DW.HILInitialize_Card = NULL;
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
  if (tid == 1)
    tid = 0;
  Act2_2_e_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Act2_2_e_update(tid);
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
  Act2_2_e_initialize();
}

void MdlTerminate(void)
{
  Act2_2_e_terminate();
}

/* Registration function */
RT_MODEL_Act2_2_e_T *Act2_2_e(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Act2_2_e_M, 0,
                sizeof(RT_MODEL_Act2_2_e_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Act2_2_e_M->solverInfo,
                          &Act2_2_e_M->Timing.simTimeStep);
    rtsiSetTPtr(&Act2_2_e_M->solverInfo, &rtmGetTPtr(Act2_2_e_M));
    rtsiSetStepSizePtr(&Act2_2_e_M->solverInfo, &Act2_2_e_M->Timing.stepSize0);
    rtsiSetdXPtr(&Act2_2_e_M->solverInfo, &Act2_2_e_M->derivs);
    rtsiSetContStatesPtr(&Act2_2_e_M->solverInfo, (real_T **)
                         &Act2_2_e_M->contStates);
    rtsiSetNumContStatesPtr(&Act2_2_e_M->solverInfo,
      &Act2_2_e_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Act2_2_e_M->solverInfo,
      &Act2_2_e_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Act2_2_e_M->solverInfo,
      &Act2_2_e_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Act2_2_e_M->solverInfo,
      &Act2_2_e_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Act2_2_e_M->solverInfo, (&rtmGetErrorStatus
      (Act2_2_e_M)));
    rtsiSetRTModelPtr(&Act2_2_e_M->solverInfo, Act2_2_e_M);
  }

  rtsiSetSimTimeStep(&Act2_2_e_M->solverInfo, MAJOR_TIME_STEP);
  Act2_2_e_M->intgData.f[0] = Act2_2_e_M->odeF[0];
  Act2_2_e_M->contStates = ((real_T *) &Act2_2_e_X);
  rtsiSetSolverData(&Act2_2_e_M->solverInfo, (void *)&Act2_2_e_M->intgData);
  rtsiSetSolverName(&Act2_2_e_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Act2_2_e_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Act2_2_e_M points to
       static memory which is guaranteed to be non-NULL" */
    Act2_2_e_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Act2_2_e_M->Timing.sampleTimes = (&Act2_2_e_M->Timing.sampleTimesArray[0]);
    Act2_2_e_M->Timing.offsetTimes = (&Act2_2_e_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Act2_2_e_M->Timing.sampleTimes[0] = (0.0);
    Act2_2_e_M->Timing.sampleTimes[1] = (0.001);
    Act2_2_e_M->Timing.sampleTimes[2] = (0.5);

    /* task offsets */
    Act2_2_e_M->Timing.offsetTimes[0] = (0.0);
    Act2_2_e_M->Timing.offsetTimes[1] = (0.0);
    Act2_2_e_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Act2_2_e_M, &Act2_2_e_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Act2_2_e_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Act2_2_e_M->Timing.perTaskSampleHitsArray;
    Act2_2_e_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Act2_2_e_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Act2_2_e_M, 30.0);
  Act2_2_e_M->Timing.stepSize0 = 0.001;
  Act2_2_e_M->Timing.stepSize1 = 0.001;
  Act2_2_e_M->Timing.stepSize2 = 0.5;

  /* External mode info */
  Act2_2_e_M->Sizes.checksums[0] = (3353918039U);
  Act2_2_e_M->Sizes.checksums[1] = (1814158822U);
  Act2_2_e_M->Sizes.checksums[2] = (57512171U);
  Act2_2_e_M->Sizes.checksums[3] = (2496762173U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Act2_2_e_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Act2_2_e_M->extModeInfo,
      &Act2_2_e_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Act2_2_e_M->extModeInfo, Act2_2_e_M->Sizes.checksums);
    rteiSetTPtr(Act2_2_e_M->extModeInfo, rtmGetTPtr(Act2_2_e_M));
  }

  Act2_2_e_M->solverInfoPtr = (&Act2_2_e_M->solverInfo);
  Act2_2_e_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Act2_2_e_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Act2_2_e_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Act2_2_e_M->blockIO = ((void *) &Act2_2_e_B);
  (void) memset(((void *) &Act2_2_e_B), 0,
                sizeof(B_Act2_2_e_T));

  /* parameters */
  Act2_2_e_M->defaultParam = ((real_T *)&Act2_2_e_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Act2_2_e_X;
    Act2_2_e_M->contStates = (x);
    (void) memset((void *)&Act2_2_e_X, 0,
                  sizeof(X_Act2_2_e_T));
  }

  /* states (dwork) */
  Act2_2_e_M->dwork = ((void *) &Act2_2_e_DW);
  (void) memset((void *)&Act2_2_e_DW, 0,
                sizeof(DW_Act2_2_e_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Act2_2_e_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Act2_2_e_M->Sizes.numContStates = (1);/* Number of continuous states */
  Act2_2_e_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Act2_2_e_M->Sizes.numY = (0);        /* Number of model outputs */
  Act2_2_e_M->Sizes.numU = (0);        /* Number of model inputs */
  Act2_2_e_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Act2_2_e_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Act2_2_e_M->Sizes.numBlocks = (16);  /* Number of blocks */
  Act2_2_e_M->Sizes.numBlockIO = (5);  /* Number of block outputs */
  Act2_2_e_M->Sizes.numBlockPrms = (110);/* Sum of parameter "widths" */
  return Act2_2_e_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
