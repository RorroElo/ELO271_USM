    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (Act2_2_e_P)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Act2_2_e_P.HILReadAnalog_channels
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_P.HILWriteAnalog_channels
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% Act2_2_e_P.HILInitialize_OOTerminate
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_P.HILInitialize_OOExit
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% Act2_2_e_P.HILInitialize_OOStart
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

                    ;% Act2_2_e_P.HILInitialize_OOEnter
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% Act2_2_e_P.HILInitialize_AOFinal
                    section.data(5).logicalSrcIdx = 6;
                    section.data(5).dtTransOffset = 4;

                    ;% Act2_2_e_P.HILInitialize_POFinal
                    section.data(6).logicalSrcIdx = 7;
                    section.data(6).dtTransOffset = 5;

                    ;% Act2_2_e_P.HILInitialize_AIHigh
                    section.data(7).logicalSrcIdx = 8;
                    section.data(7).dtTransOffset = 6;

                    ;% Act2_2_e_P.HILInitialize_AILow
                    section.data(8).logicalSrcIdx = 9;
                    section.data(8).dtTransOffset = 7;

                    ;% Act2_2_e_P.HILInitialize_AOHigh
                    section.data(9).logicalSrcIdx = 10;
                    section.data(9).dtTransOffset = 8;

                    ;% Act2_2_e_P.HILInitialize_AOLow
                    section.data(10).logicalSrcIdx = 11;
                    section.data(10).dtTransOffset = 9;

                    ;% Act2_2_e_P.HILInitialize_AOInitial
                    section.data(11).logicalSrcIdx = 12;
                    section.data(11).dtTransOffset = 10;

                    ;% Act2_2_e_P.HILInitialize_POFrequency
                    section.data(12).logicalSrcIdx = 13;
                    section.data(12).dtTransOffset = 11;

                    ;% Act2_2_e_P.HILInitialize_POInitial
                    section.data(13).logicalSrcIdx = 14;
                    section.data(13).dtTransOffset = 12;

                    ;% Act2_2_e_P.Integrator_IC
                    section.data(14).logicalSrcIdx = 15;
                    section.data(14).dtTransOffset = 13;

                    ;% Act2_2_e_P.Gain_Gain
                    section.data(15).logicalSrcIdx = 16;
                    section.data(15).dtTransOffset = 14;

                    ;% Act2_2_e_P.Gain1_Gain
                    section.data(16).logicalSrcIdx = 17;
                    section.data(16).dtTransOffset = 15;

                    ;% Act2_2_e_P.SignalGenerator_Amplitude
                    section.data(17).logicalSrcIdx = 18;
                    section.data(17).dtTransOffset = 16;

                    ;% Act2_2_e_P.SignalGenerator_Frequency
                    section.data(18).logicalSrcIdx = 19;
                    section.data(18).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Act2_2_e_P.HILInitialize_EIInitial
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_P.HILInitialize_POModes
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% Act2_2_e_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 23;
                    section.data(2).dtTransOffset = 1;

                    ;% Act2_2_e_P.HILInitialize_EIQuadrature
                    section.data(3).logicalSrcIdx = 24;
                    section.data(3).dtTransOffset = 2;

                    ;% Act2_2_e_P.ToHostFile1_Decimation
                    section.data(4).logicalSrcIdx = 25;
                    section.data(4).dtTransOffset = 3;

                    ;% Act2_2_e_P.ToHostFile1_BitRate
                    section.data(5).logicalSrcIdx = 26;
                    section.data(5).dtTransOffset = 4;

                    ;% Act2_2_e_P.ToHostFile_Decimation
                    section.data(6).logicalSrcIdx = 27;
                    section.data(6).dtTransOffset = 5;

                    ;% Act2_2_e_P.ToHostFile_BitRate
                    section.data(7).logicalSrcIdx = 28;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 37;
            section.data(37)  = dumData; %prealloc

                    ;% Act2_2_e_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 30;
                    section.data(2).dtTransOffset = 1;

                    ;% Act2_2_e_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 31;
                    section.data(3).dtTransOffset = 2;

                    ;% Act2_2_e_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 32;
                    section.data(4).dtTransOffset = 3;

                    ;% Act2_2_e_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 33;
                    section.data(5).dtTransOffset = 4;

                    ;% Act2_2_e_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 34;
                    section.data(6).dtTransOffset = 5;

                    ;% Act2_2_e_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 35;
                    section.data(7).dtTransOffset = 6;

                    ;% Act2_2_e_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 36;
                    section.data(8).dtTransOffset = 7;

                    ;% Act2_2_e_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 37;
                    section.data(9).dtTransOffset = 8;

                    ;% Act2_2_e_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 38;
                    section.data(10).dtTransOffset = 9;

                    ;% Act2_2_e_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 39;
                    section.data(11).dtTransOffset = 10;

                    ;% Act2_2_e_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 40;
                    section.data(12).dtTransOffset = 11;

                    ;% Act2_2_e_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 41;
                    section.data(13).dtTransOffset = 12;

                    ;% Act2_2_e_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 42;
                    section.data(14).dtTransOffset = 13;

                    ;% Act2_2_e_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 43;
                    section.data(15).dtTransOffset = 14;

                    ;% Act2_2_e_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 44;
                    section.data(16).dtTransOffset = 15;

                    ;% Act2_2_e_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 45;
                    section.data(17).dtTransOffset = 16;

                    ;% Act2_2_e_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 46;
                    section.data(18).dtTransOffset = 17;

                    ;% Act2_2_e_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 47;
                    section.data(19).dtTransOffset = 18;

                    ;% Act2_2_e_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 48;
                    section.data(20).dtTransOffset = 19;

                    ;% Act2_2_e_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 49;
                    section.data(21).dtTransOffset = 20;

                    ;% Act2_2_e_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 50;
                    section.data(22).dtTransOffset = 21;

                    ;% Act2_2_e_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 51;
                    section.data(23).dtTransOffset = 22;

                    ;% Act2_2_e_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 52;
                    section.data(24).dtTransOffset = 23;

                    ;% Act2_2_e_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 53;
                    section.data(25).dtTransOffset = 24;

                    ;% Act2_2_e_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 54;
                    section.data(26).dtTransOffset = 25;

                    ;% Act2_2_e_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 55;
                    section.data(27).dtTransOffset = 26;

                    ;% Act2_2_e_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 56;
                    section.data(28).dtTransOffset = 27;

                    ;% Act2_2_e_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 57;
                    section.data(29).dtTransOffset = 28;

                    ;% Act2_2_e_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 58;
                    section.data(30).dtTransOffset = 29;

                    ;% Act2_2_e_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 59;
                    section.data(31).dtTransOffset = 30;

                    ;% Act2_2_e_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 60;
                    section.data(32).dtTransOffset = 31;

                    ;% Act2_2_e_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 61;
                    section.data(33).dtTransOffset = 32;

                    ;% Act2_2_e_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 62;
                    section.data(34).dtTransOffset = 33;

                    ;% Act2_2_e_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 63;
                    section.data(35).dtTransOffset = 34;

                    ;% Act2_2_e_P.HILReadAnalog_Active
                    section.data(36).logicalSrcIdx = 64;
                    section.data(36).dtTransOffset = 35;

                    ;% Act2_2_e_P.HILWriteAnalog_Active
                    section.data(37).logicalSrcIdx = 65;
                    section.data(37).dtTransOffset = 36;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% Act2_2_e_P.ToHostFile1_file_name
                    section.data(1).logicalSrcIdx = 66;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_P.ToHostFile1_VarName
                    section.data(2).logicalSrcIdx = 67;
                    section.data(2).dtTransOffset = 15;

                    ;% Act2_2_e_P.ToHostFile1_FileFormat
                    section.data(3).logicalSrcIdx = 68;
                    section.data(3).dtTransOffset = 20;

                    ;% Act2_2_e_P.ToHostFile_file_name
                    section.data(4).logicalSrcIdx = 69;
                    section.data(4).dtTransOffset = 21;

                    ;% Act2_2_e_P.ToHostFile_VarName
                    section.data(5).logicalSrcIdx = 70;
                    section.data(5).dtTransOffset = 38;

                    ;% Act2_2_e_P.ToHostFile_FileFormat
                    section.data(6).logicalSrcIdx = 71;
                    section.data(6).dtTransOffset = 43;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (Act2_2_e_B)
        ;%
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% Act2_2_e_B.Vo
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_B.Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Act2_2_e_B.Gain1
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% Act2_2_e_B.Vo_e
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% Act2_2_e_B.Vo_p
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 5;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (Act2_2_e_DW)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% Act2_2_e_DW.HILInitialize_AOVoltages
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_DW.Vo_Buffer
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% Act2_2_e_DW.HILReadAnalog_Buffer
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% Act2_2_e_DW.ToHostFile1_PointsWritten
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_DW.ToHostFile_PointsWritten
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% Act2_2_e_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% Act2_2_e_DW.Scope2_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_DW.Scope3_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% Act2_2_e_DW.Scope1_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

                    ;% Act2_2_e_DW.ToHostFile1_PWORK
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 3;

                    ;% Act2_2_e_DW.Scope4_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 5;

                    ;% Act2_2_e_DW.HILReadAnalog_PWORK
                    section.data(6).logicalSrcIdx = 11;
                    section.data(6).dtTransOffset = 6;

                    ;% Act2_2_e_DW.Scope_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 12;
                    section.data(7).dtTransOffset = 7;

                    ;% Act2_2_e_DW.ToHostFile_PWORK
                    section.data(8).logicalSrcIdx = 13;
                    section.data(8).dtTransOffset = 8;

                    ;% Act2_2_e_DW.HILWriteAnalog_PWORK
                    section.data(9).logicalSrcIdx = 14;
                    section.data(9).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% Act2_2_e_DW.ToHostFile1_SamplesCount
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% Act2_2_e_DW.ToHostFile1_ArrayNameLength
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% Act2_2_e_DW.ToHostFile_SamplesCount
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

                    ;% Act2_2_e_DW.ToHostFile_ArrayNameLength
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3353918039;
    targMap.checksum1 = 1814158822;
    targMap.checksum2 = 57512171;
    targMap.checksum3 = 2496762173;

