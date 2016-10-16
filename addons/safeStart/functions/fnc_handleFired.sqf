#include "script_component.hpp"

params ["_unit", "", "", "", "", "", "_bullet"];

if (local _unit) then {
    deleteVehicle _bullet;

    if (missionNamespace getVariable ["PABST_ADMIN_SAFESTART_public_shotWarning", true]) then {
        _masterAdminList = [] call potato_common_fnc_authorizedUsers;
        _masterUnitList = [];

        {
            if ((getPlayerUID _x) in _masterAdminList) then {
                _masterUnitList pushBack _x;
            };
        } forEach allPlayers;

        _toolText = format["%1 has fired/thrown a weapon.", name _unit];

        _toolText remoteExec ["hint", _masterUnitList];
        _toolText remoteExec ["systemChat", _masterUnitList];
    };
};