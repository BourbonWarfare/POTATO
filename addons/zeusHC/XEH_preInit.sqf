#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (isServer) then {
    missionNameSpace setVariable [QGVAR(aiTransfered), false, true];
};

[
    QGVAR(maxAICount),
    "SLIDER",
    ["Maximum AI Count", "Maximum active AI allowed at one time."],
    "POTATO Admin",
    [1, 200, 90, 0],
    1
] call cba_settings_fnc_init;

[
    QGVAR(maxGroupCountPerSide),
    "SLIDER",
    ["Maximum Groups Per Side", "Maximum active groups allowed (per side)."],
    "POTATO Admin",
    [1, 280, 280, 0],
    1
] call cba_settings_fnc_init;

[
    QGVAR(delayBetweenUnitCreation),
    "SLIDER",
    ["Delay Between AI Creation", "Delay between creating AI units from potato tools."],
    "POTATO Admin",
    [0, 10, 0.4, 1],
    1
] call cba_settings_fnc_init;

[
    QGVAR(delayBetweenGroupCreation),
    "SLIDER",
    ["Delay Between AI Group Creation", "Delay between creating AI groups from potato tools."],
    "POTATO Admin",
    [0, 10, 1, 1],
    1
] call cba_settings_fnc_init;

ADDON = true;

#ifdef DEBUG_MODE_FULL
INFO_1("Checking %1 classnames on zeusHC modules",QGVAR(createVic));
private _configs = configProperties [configFile >> "CfgVehicles", '(isClass _x) && {(configName _x) isKindOf QGVAR(base_module)} && {(getNumber (_x >> "scope")) == 2}'];
private _cfgPatchUnits = (getArray (configFile >> "CfgPatches" >> QUOTE(ADDON) >> "units")) apply {toLower _x};
{
    private _vic = getText (_x >> QGVAR(createVic));
    if ((_vic != "") && {!isClass (configFile >> "CfgVehicles" >> _vic)}) then {
        ERROR_2("createVic [%1] Does Not Exist For Module [%2]", _vic, configName _x);
    };
    if (!((toLower configName _x) in _cfgPatchUnits)) then {
        ERROR_1("[%1] Not in CfgPatches units[] array", configName _x);
    };
} forEach _configs;
INFO_1("Checked [%1] configs",count _configs);
#endif
