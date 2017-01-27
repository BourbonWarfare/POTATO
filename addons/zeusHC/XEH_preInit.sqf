#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (isServer) then {
    missionNameSpace setVariable [QGVAR(aiTransfered), false, true];
};

ADDON = true;

#ifdef DEBUG_MODE_FULL
INFO_1("Checking %1 classnames on zeusHC modules",QGVAR(createVic));
private _configs = configProperties [configFile >> "CfgVehicles", '(isClass _x) && {isText (_x >> QGVAR(createVic))}'];
{
    private _vic = getText (_x >> QGVAR(createVic));
    if ((_vic != "") && {!isClass (configFile >> "CfgVehicles" >> _vic)}) then {
        ERROR_2("Vic [%1] Does Not Exist For Module [%2]", _vic, configName _x);
    };
} forEach _configs;
#endif
