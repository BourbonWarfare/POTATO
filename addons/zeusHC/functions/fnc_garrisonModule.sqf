#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];

if (local _logic) then {
    GVAR(garrisonLocation) = getPosATL _logic;

    if (isServer && !isNull (_logic getVariable [QGVAR(garrisonChance), objNull])) then {
        private _radius = abs(_logic getVariable QGVAR(garrisonRadius));
        private _min = (_logic getVariable QGVAR(garrisonMin)) min (_logic getVariable QGVAR(garrisonMax));
        private _max = (_logic getVariable QGVAR(garrisonMin)) max (_logic getVariable QGVAR(garrisonMax));

        [
            _logic getVariable QGVAR(garrisonFaction),
            _logic getVariable QGVAR(garrisonChance),
            _radius,
            _min,
            _max,
        ] call FUNC(garrisonSpawn);
    } else {
        createDialog QGVAR(garrison_dialog);
    };
};

deleteVehicle _logic;
