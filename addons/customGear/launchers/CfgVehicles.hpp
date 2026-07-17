class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class GVAR(carlG_AB_laser) {
                    displayName = "Toggle HE Airburst";
                    condition = QUOTE(call FUNC(carlGAB_Cond));
                    statement = QUOTE(call FUNC(carlGAB_Toggle));
                    showDisabled = 0;
                    exceptions[] = {"notOnMap", "isNotUnconscious", "isNotSwimming"};
                    class GVAR(carlG_IncLaserOffset) {
                        displayName = "Increase Offset (5m)";
                        condition = QUOTE(_player getVariable [ARR_2(QQGVAR(abCGRnd),false)]);
                        statement = QUOTE([true] call FUNC(carlGAB_OffDelta));
                    };
                    class GVAR(carlG_resetLaserOffset) {
                        displayName = "Reset Offset (5m)";
                        condition = QUOTE(_player getVariable [ARR_2(QQGVAR(abCGRnd),false)]);
                        statement = QUOTE(_player setVariable [ARR_2(QQGVAR(abOffset),5)]; [ARR_4('Offset to laser set to 5m',true,5,2)] call ACEFUNC(common,displayText););
                    };
                    class GVAR(carlG_DecLaserOffset) {
                        displayName = "Decrease Offset (5m)";
                        condition = QUOTE(_player getVariable [ARR_2(QQGVAR(abCGRnd),false)]);
                        statement = QUOTE([false] call FUNC(carlGAB_OffDelta));
                    };
                };
            };
        };
    };
};
