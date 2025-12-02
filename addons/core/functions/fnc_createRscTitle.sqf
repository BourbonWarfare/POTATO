/*
 * Author: AACO
 * Function used to show rsc titles to clients
 *
 * Note makes some assumptions:
 * 1: Provided display class maps to a unique Rsctitle
 * 2: Provided display class is a unique layer
 * 3: Provided RscTitle stored itself into the uiNamespace
 *
 * Arguments:
 * 0: Classname of RscTitle <STRING>
 * 1: Display the title over the map? <BOOL> (default: false)
 *
 * Examples:
 * ["someRSCTitleClass", true] call potato_core_fnc_createRscTitle;
 * ["someOtherRSCTitleClass", false] call potato_core_fnc_createRscTitle;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_displayClass", "", [""]], ["_showOnMap", false, [false]]];

if (isNull (uiNamespace getVariable [_displayClass, displayNull])) then {
    TRACE_2("Creating RscTitle",_displayClass,_showOnMap);
    (_displayClass cutFadeOut 0) cutRsc [_displayClass, "PLAIN", 1, _showOnMap];
};
