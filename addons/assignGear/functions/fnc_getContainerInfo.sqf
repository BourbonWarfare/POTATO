/*
 * Author: AACO
 * Gets container information from an array of classnames
 *
 * Arguments:
 * 0: Array of containers to select <ARRAY>
 * 1: The array containing all the containers and their available space <ARRAY>
 * 2: Does the container class needed to be looked up in CfgWeapons (optional, default: true) <BOOL>
 *
 * Return Value:
 * NONE
 *
 * Example:
 * [_configUniform, _containersArray] call potato_assignGear_fnc_getContainerInfo;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_containers", [], [[]]],
    ["_allContainersArray", [], [[]]],
    ["_lookupContainer", true, [true]]
];

if (_containers isEqualTo []) then {
    TRACE_1("No classnames provided for container",_containers);
    _allContainersArray pushBack [0];
} else {
    private _container = selectRandom _containers;
    private _containerClass = if (_lookupContainer) then {
        getText (configFile >> "CfgWeapons" >> _container >> "ItemInfo" >> "containerClass")
    } else {
        _container
    };
    private _containerSpace = getNumber (configFile >> "CfgVehicles" >> _containerClass >> "maximumLoad");
    TRACE_3("container info: ",_container,_containerClass,_containerSpace);

    _allContainersArray pushBack [_containerSpace, [_container, []]];
};
