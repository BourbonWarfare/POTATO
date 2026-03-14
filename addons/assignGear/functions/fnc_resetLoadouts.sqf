#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Reloads every units gear in
 *
 * Arguments: None
 *
 * Return Value: None
 *
 * Example:
 * call compileScript ["\z\potato\addons\assigngear\functions\fnc_resetLoadouts.sqf"]
 *
 * Public: No
 */
if (!is3DEN) exitWith {};
// Reload mission config
EGVAR(missionMaking,skipSaveTest) = true;
do3DENAction "MissionSave";
EGVAR(missionMaking,skipSaveTest) = false;

// Reinit reassign gear and reapply loadouts
GVAR(loadoutCache) = createHashMap;
GVAR(classnameCache) = createHashMap;
GVAR(magnifiedOpticCache) = createHashMap;

GVAR(allowMagnifiedOptics) = [missionConfigFile >> "CfgLoadouts" >> "allowMagnifiedOptics"] call CFUNC(getBool);
GVAR(allowChangeableOptics) = [missionConfigFile >> "CfgLoadouts" >> "allowChangeableOptics"] call CFUNC(getBool);
GVAR(useFallback) = [missionConfigFile >> "CfgLoadouts" >> "useFallback"] call CFUNC(getBool);
GVAR(maxRandomization) = [missionConfigFile >> "CfgLoadouts" >> "maxRandomization", 5] call CFUNC(getNumber);
GVAR(setVehicleLoadouts) = [missionConfigFile >> "CfgLoadouts" >> "setVehicleLoadouts", 1] call CFUNC(getNumber);
GVAR(setSupplyBoxLoadouts) = [missionConfigFile >> "CfgLoadouts" >> "setSupplyBoxLoadouts", 1] call CFUNC(getNumber);
GVAR(alwaysAddToolkits) = [missionConfigFile >> "CfgLoadouts" >> "alwaysAddToolkits", true] call CFUNC(getBool);
GVAR(alwaysAddLandRopes) = [missionConfigFile >> "CfgLoadouts" >> "alwaysAddLandRopes", true] call CFUNC(getBool);
GVAR(prefixes) = [missionConfigFile >> "CfgLoadouts" >> "prefixes"] call CFUNC(getArray);
GVAR(resupplyBoxMarkerIndex) = 0;

{
    if (_x isKindOf "CAManBase") then {
        [_x] call FUNC(assignGearMan);
    };
} forEach (all3DENEntities select 0);

// force run loadout checks
systemChat "Reloaded mission config, finished reassigning loadouts, running tests.";
do3DENAction "MissionSave";
