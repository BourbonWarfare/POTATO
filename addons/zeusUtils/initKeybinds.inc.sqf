#include "\a3\ui_f\hpp\defineDIKCodes.inc"
[["Potato", "Zeus"], QGVAR(zeusSpectatePTT), ["(EXP) Zeus ACRE PTT", "(Experimental) Talk on your active ACRE radio. Changeable using ACE interact in Zeus or ACE Self-Interact normally."], {
    if (side ace_player == sideLogic || !alive ace_player || isNil "ACRE_IS_SPECTATOR" || {!ACRE_IS_SPECTATOR}) exitWith {};
    GVAR(wasSpec) = ACRE_IS_SPECTATOR;
    [false] call acre_api_fnc_setSpectator;
    [-1] call acre_sys_core_fnc_handleMultiPttKeyPress;
}, {
    if (isNil QGVAR(wasSpec)) exitWith {};
    [-1] call acre_sys_core_fnc_handleMultiPttKeyPressUp;
    if (GVAR(wasSpec)) then {
        GVAR(wasSpec) = false;
        [true] call acre_api_fnc_setSpectator;
    };
    GVAR(wasSpec) = nil;
}, [DIK_CAPSLOCK, [false, false, false]]] call CBA_fnc_addKeybind; // Default Caps Lock
