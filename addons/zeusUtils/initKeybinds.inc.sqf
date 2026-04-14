#include "\a3\ui_f\hpp\defineDIKCodes.inc"
["POTATO", QGVAR(keybindInfo), ["(EXP) Zeus ACRE PTT", "(Experimental) Talk on your active radio, changeable by ACE self-interact"], {
    if (side ace_player == sideLogic || !alive ace_payer || !ACRE_IS_SPECTATOR) exitWith {};
    ACRE_IS_SPECTATOR = false;
    [-1] call acre_sys_core_fnc_handleMultiPttKeyPress;
}, {;
    [-1] call acre_sys_core_fnc_handleMultiPttKeyPressUp;
    if ((ace_player getVariable ["acre_sys_core_ts3id", -1]) in ACRE_SPECTATORS_LIST) then {
        ACRE_IS_SPECTATOR = true;
    }
}, [DIK_CAPSLOCK, [false, false, false]]] call CBA_fnc_addKeybind; // Default Caps Lock
