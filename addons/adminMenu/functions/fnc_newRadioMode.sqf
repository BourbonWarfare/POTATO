#include "script_component.hpp"
/*
* Author: Lambda.Tiger
* This handles the radio change event, specifically
*
* Arguments:
* 0: New mode to be set to
*
* Return Value:
* None
*
* Examples:
* [] call potato_adminMenu_fnc_newRadioMode;
*
* Public: No
*/
params [["_radioValue", -1, [-1]]];

if (isNil QEFUNC(radios,arcadeSim)) then {
    EFUNC(radios,arcadeSim) = compileFinal {
        params ["_f", "_mW", "_receiverClass", "_transmitterClass"];
        private _realRadioRx = configName (inheritsFrom (configFile >> "CfgWeapons" >> _receiverClass));
        private _sinadRating = getNumber (configFile >> "CfgAcreComponents" >> _realRadioRx >> "sinadRating");

        private _txPos = [_receiverClass] call acre_sys_radio_fnc_getRadioPos;
        private _rxPos = [_transmitterClass] call acre_sys_radio_fnc_getRadioPos;
        private _distance = _txPos distance _rxPos;

        private _Lfs = 20 * (log(_f) + log(_distance));
        private _Lm = 1.95 + random 1;
        private _Lb = _Lfs - _Lm  + 10 * log _mW;
        private _bottom = _sinadRating - 0.075 / 2 * abs _sinadRating;
        private _Snd = 2 * abs ((_bottom - (_Lb max _bottom))/_sinadRating);
        [1 min (0 max _Snd), _Lb]
    };
};

switch (_radioValue) do {
    case POTATO_RADIO_RESET_TO_DEFAULT: {
        private _simFunc = missionNamespace getVariable [QEGVAR(radios,defaultSim), {}];
        [_simFunc] call acre_api_fnc_setCustomSignalFunc;
    };
    case POTATO_RADIO_ACRE_ONLY_343: {
        [{
            params ["_f", "_mW", "_receiverClass", "_transmitterClass"];
            if ("ACRE_PRC343" == _receiverClass select [0,11]) then {
                _this call acre_sys_signal_fnc_getSignalCore
            } else {
                _this call EFUNC(radios,arcadeSim)
            };
        }] call acre_api_fnc_setCustomSignalFunc;
    };
    case POTATO_RADIO_INGAME_ONLY_343: {
        [{
            params ["_f", "_mW", "_receiverClass", "_transmitterClass"];
            if ("ACRE_PRC343" == _receiverClass select [0,11]) then {
                _this call EFUNC(radios,arcadeSim)
            } else {
                [1, 1]
            };
        }] call acre_api_fnc_setCustomSignalFunc;
    };
    case POTATO_RADIO_END_RADIO_SIM: {
        [{[1,1]}] call acre_api_fnc_setCustomSignalFunc;
    };
};
