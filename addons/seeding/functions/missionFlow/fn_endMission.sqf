#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion will check if the mission is started on the same day as a
* session, and then if it is, add a CBA waitAndExecute call to end the
* mission at the desired time.
*
* Arguments:
* none
*
* Return:
* none
*
* Example:
* [] call bw_fnc_endMission; // end 15 minutes before session time
*//***************************************************************************/

if (isServer) then {
    [west, "Mission ended", "Seed"] call ocap_fnc_exportData;
    private _debugMsg = format ["Saving OCAP recording with winning side %1 and mission type %2", west, "Seed"];
    ["potato_adminMsg", [_debugMsg, profileName, "#ALL"]] call CBA_fnc_globalEvent;
};

["", true, 1] call BIS_fnc_endMission;
