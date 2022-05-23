#include "script_component.hpp"

if (isServer) then {
    // Setting to sync to ace_fortify        
    ["potato_safeStartOn", {
        if (!GVAR(syncFortify)) exitWith {};
        missionNamespace setVariable [QACEGVAR(fortify,fortifyAllowed), true, true];
    }] call CBA_fnc_addEventHandler;
    ["potato_safeStartOff", {
        if (!GVAR(syncFortify)) exitWith {};
        missionNamespace setVariable [QACEGVAR(fortify,fortifyAllowed), false, true];
    }] call CBA_fnc_addEventHandler;

    [
        {time > 0},
        { [GVAR(enabled)] call FUNC(toggleSafeStart); }
    ] call CBA_fnc_waitUntilAndExecute;
	
	if (getMissionConfigValue "potato_missionTesting_forceSS") then {
		if (parseNumber (GetMissionConfigValue "potato_missionTesting_SSTimeGiven") isEqualTo 0) exitWith {"[CMF] WARNING: THIS MISSION IS LIVE IMMEDIATELY" remoteExec ["systemChat", 0]; [true] spawn JST_fnc_ReadyUp;};
		
		[format ["[CMF] Safe start time is enforced: %1 minutes",GetMissionConfigValue "potato_missionTesting_SSTimeGiven"]] remoteExec ["systemChat", 0];
		
		[
			{CBA_missionTime >= ((parseNumber (GetMissionConfigValue "potato_missionTesting_SSTimeGiven") * 60) / 2)},
			{ 
				"[CMF] Half of safe start time remains" remoteExec ["systemChat", 0];	
			},
			[],
			((parseNumber (GetMissionConfigValue "potato_missionTesting_SSTimeGiven") * 60) / 2),
			{true}
		] call CBA_fnc_waitUntilAndExecute; 
		
		[
			{CBA_missionTime >= (parseNumber (GetMissionConfigValue "potato_missionTesting_SSTimeGiven") * 60)},
			{ 
				"[CMF] Safe start time has expired" remoteExec ["systemChat", 0];
				[true] spawn JST_fnc_ReadyUp;
			},
			[],
			(parseNumber (GetMissionConfigValue "potato_missionTesting_SSTimeGiven") * 60),
			{true}
		] call CBA_fnc_waitUntilAndExecute;
	};
};

if (didJip) then {
    [
        {time > 1},
        {
            if (missionNamespace getVariable [QGVAR(startTime_PV), -1] == -1) then {
                ["potato_safeStartOff"] call CBA_fnc_localEvent;
            } else {
                ["potato_safeStartOn"] call CBA_fnc_localEvent;
            };
        }
    ] call CBA_fnc_waitUntilAndExecute;
};
