/*
 * Author: Brandon (TCVM)
 * Ensures that the burst value of a weapons firemode is properly defined and log it if it breaks the test
 * I.E if a firemode has a burst = "3 + random 3" and it is shown to the player, this will log to rpt
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_aiCfgFixes_fnc_ensurePlayerBurst;
 *
 * Public: Yes
 */
#include "script_component.hpp"

private _fine = true;
{
    private _firemodes = getArray(_x >> "modes");
    {
        if (count (getText(_x >> "burst")) > 0 && getNumber(_x >> "showToPlayer") >= 1) then {
            private _errorStr = "Fire Mode: " + configName(_x) + " -- Config: " + str(_x);
            systemChat _errorStr;
            diag_log _errorStr;
            _fine = false;
        };
    } forEach configProperties[_x, "configName(_x) in _firemodes", false];

} forEach configProperties[configFile >> "CfgWeapons", "isClass(_x) && { !isNull(_x >> 'modes') }"];
diag_log "done test";
_fine

