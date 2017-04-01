#include "script_component.hpp"

if (GVAR(enabled) && hasInterface) then {
    // setup babel
    GVAR(availableLanguages) = [];
    {
        GVAR(availableLanguages) pushBack (_x select 0);
    } forEach EGVAR(radios,availableLanguages);

    GVAR(classEHInstalled) = false;

    GVAR(boundingBoxCache) = call CBA_fnc_createNamespace;
    GVAR(vehicleIconCache) = call CBA_fnc_createNamespace;
    GVAR(groupIconCache) = call CBA_fnc_createNamespace;

    // populate group icon cache
    {
        _x params ["_key", "_value"];
        GVAR(groupIconCache) setVariable [_key, _value];
    } forEach [
        [QPATHTOEF(markers,data\armor.paa), QPATHTOF(data\armor.paa)],
        [QPATHTOEF(markers,data\artillery.paa), QPATHTOF(data\artillery.paa)],
        [QPATHTOEF(markers,data\attack_fixed_wing.paa), QPATHTOF(data\attack_fixed_wing.paa)],
        [QPATHTOEF(markers,data\attack_helicopter.paa), QPATHTOF(data\attack_helicopter.paa)],
        [QPATHTOEF(markers,data\engineer.paa), QPATHTOF(data\engineer.paa)],
        [QPATHTOEF(markers,data\fixed_wing.paa), QPATHTOF(data\fixed_wing.paa)],
        [QPATHTOEF(markers,data\helicopter.paa), QPATHTOF(data\helicopter.paa)],
        [QPATHTOEF(markers,data\hq.paa), QPATHTOF(data\hq.paa)],
        [QPATHTOEF(markers,data\infantry.paa), QPATHTOF(data\infantry.paa)],
        [QPATHTOEF(markers,data\maintenance.paa), QPATHTOF(data\maintenance.paa)],
        [QPATHTOEF(markers,data\mat.paa), QPATHTOF(data\mat.paa)],
        [QPATHTOEF(markers,data\mechanized_infantry.paa), QPATHTOF(data\mechanized_infantry.paa)],
        [QPATHTOEF(markers,data\medical.paa), QPATHTOF(data\medical.paa)],
        [QPATHTOEF(markers,data\mmg.paa), QPATHTOF(data\mmg.paa)],
        [QPATHTOEF(markers,data\mortar.paa), QPATHTOF(data\mortar.paa)],
        [QPATHTOEF(markers,data\motorized_infantry.paa), QPATHTOF(data\motorized_infantry.paa)],
        [QPATHTOEF(markers,data\msam.paa), QPATHTOF(data\msam.paa)],
        [QPATHTOEF(markers,data\recon.paa), QPATHTOF(data\recon.paa)],
        [QPATHTOEF(markers,data\support.paa), QPATHTOF(data\support.paa)],
        [QPATHTOEF(markers,data\unknown.paa), QPATHTOF(data\unknown.paa)]
    ];

    // register respawn EH
    [QEGVAR(respawn,respawnStateChanged), {
        params [["_open", false, [false]]];
        GVAR(respawnOpen) = _open;

        if (GVAR(running)) then {
            [_open] call FUNC(setRespawn);
        };
    }] call CBA_fnc_addEventHandler;
};
