#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
*
*
* Arguments:
* _vest - The classname of the vest to check diaphragm hitpoint for(STRING)
*
* Return:
* The diaphragm hitpoint armor
*
* Example:
* [vest ace_player] call potato_missionTesting_fnc_getVestArmor;
*//***************************************************************************/
params ["_vest"];

if (isNil QGVAR(vestArmor)) then {
    GVAR(vestArmor) = createHashMap;
};

GVAR(vestArmor) getOrDefaultCall [_vest, {
    private _classes = configProperties [
        configFile >> "CfgWeapons" >> _vest >> "ItemInfo" >> "HitpointsProtectionInfo",
        "getText (_x >> ""hitpointName"") == ""HitDiaphragm""",
        true
    ];
    if (_classes isEqualTo []) then {
        0
    } else {
        getNumber ((_classes#0) >> "armor")
    }
}, true]
