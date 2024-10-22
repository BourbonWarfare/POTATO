class ace_medical_treatment {
    class Medication {
        class Naloxone {
            painReduce = 0;
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
            timeInSystem = 180;
            timeTillMaxEffect = 1;
            maxDose = 0.1;
            onOverDose = QFUNC(Naloxone);
            incompatibleMedication[] = {};
            viscosityChange = 0;
        };
    };
};
