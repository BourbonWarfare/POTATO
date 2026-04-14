#include "\a3\ui_f\hpp\defineDIKCodes.inc"
[["Potato", "Zeus"], QGVAR(zeusSpectatePTT), ["(EXP) Zeus ACRE PTT", "(Experimental) Talk on your active ACRE radio. Changeable using ACE interact in Zeus or ACE Self-Interact normally."], {
    if (side ace_player == sideLogic || !alive ace_player || isNil "ACRE_IS_SPECTATOR" || {!ACRE_IS_SPECTATOR}) exitWith {};
    ACRE_IS_SPECTATOR = false;
    [-1] call acre_sys_core_fnc_handleMultiPttKeyPress;
}, {
    [-1] call acre_sys_core_fnc_handleMultiPttKeyPressUp;
    if (acre_sys_core_ts3id in ACRE_SPECTATORS_LIST) then {
        ACRE_IS_SPECTATOR = true;
    }
}, [DIK_CAPSLOCK, [false, false, false]]] call CBA_fnc_addKeybind; // Default Caps Lock
