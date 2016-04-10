#include "script_component.hpp"


//gear fix for HLC compat (server only)
//Remove once compats are fixed next week
if (isServer) then {
    DFUNC(hlcFix) = {
        _fixHlcShit = {
            _this spawn {
                params ["_unit"];
                diag_log text format ["fixing hlc on %1", _unit];

                sleep 1; //let f gear assing run

                if (isNull _unit) exitWith {diag_log "null"};
                if (!local _unit) exitWith {diag_log "not local"};

                private _w = primaryWeapon _unit;
                if (_w == "") exitWith {};
                private _muzzles = getArray (configFile >> "CfgWeapons" >> _w >> "muzzles");
                private _badGP = false;

                {
                    if (_x == "GP25Muzzle") then {
                        _badGP = true;
                        private _mags = getArray (configFile >> "CfgWeapons" >> _w >> "GP25_Base" >> "magazines");
                        {
                            if ("rhs_VOG25" == _x) exitWith {_badGP = false;};
                        } forEach _mags;
                    };
                } forEach _muzzles;

                if (_badGP) then {
                    diag_log text format ["Bad RHS GPs"];
                    {
                        _x params ["_rhsMag", "_hlcMag"];
                        while { ({_x == _rhsMag} count (magazines _unit)) > 0 } do {

                            diag_log text format ["Replacing %1 for %2", _rhsMag, _hlcMag];
                            _unit removeMagazine _rhsMag;
                            _unit addMagazine _hlcMag;
                        };
                    } forEach [
                    ["rhs_VOG25", "hlc_VOG25_AK"],
                    ["rhs_VOG25p", "hlc_VOG25_AK"],
                    ["rhs_vg40tb", "hlc_VOG25_AK"],
                    ["rhs_vg40sz", "hlc_VOG25_AK"],
                    ["rhs_vg40op_white", "hlc_GRD_White"],
                    ["rhs_vg40op_green", "hlc_GRD_White"],
                    ["rhs_vg40op_red", "hlc_GRD_White"],
                    ["rhs_GRD40_white", "hlc_GRD_White"],
                    ["rhs_GRD40_green", "hlc_GRD_Green"],
                    ["rhs_GRD40_red", "hlc_GRD_Red"],
                    ["rhs_VG40MD_White", "hlc_GRD_White"],
                    ["rhs_VG40MD_Green", "hlc_GRD_Green"],
                    ["rhs_VG40MD_Red", "hlc_GRD_Red"],
                    ["rhs_GDM40", "hlc_GRD_White"]
                    ];
                };
            };
        };
        diag_log ["calling and adding eh"];
        if (!isNull ace_player) then {
            [ace_player] call _fixHlcShit;
        };
        ["playerChanged", _fixHlcShit] call ace_common_fnc_addEventHandler;
    };

    diag_log "Transmiting func";
    publicVariable QFUNC(hlcFix);

    [] spawn {
        sleep 1;

        diag_log "remoteExec func (with jip)";
        [] remoteExec [QFUNC(hlcFix), 0, true];
    };
};




GVAR(playerStartingSide) = sideUnknown;
GVAR(playerAuth) = false;

if (hasInterface) then {
    ["playerChanged", {
        if (isNull ace_player) exitWith {};
        if (GVAR(playerStartingSide) isEqualTo sideUnknown) then {
            TRACE_1("Setting start playerside",playerSide);
            GVAR(playerStartingSide) = playerSide;
        };
        if ((getPlayerUID player) in AUTHORIZED_USERS) then {
            if (!GVAR(playerAuth)) then {
                GVAR(playerAuth) = true;
                diag_log text format ["[POTATO]: Player UID [%1] in list", getPlayerUID player];
            };
        };
    }] call ace_common_fnc_addEventHandler;
};

["potato_adminMsg", {
    params ["_msg", ["_from", "?"], ["_to", ""]];
    if (hasInterface) then {
        if ((_to == profileName) || {_to == "#ALL"} || {(GVAR(showNotifcations)) && {[] call FUNC(isAuthorized)}}) then {
            systemChat format ["POTATO [%1>%2]: %3", _from, _to, _msg];
        };
    };
    if (isServer) then {
        diag_log text format ["[POTATO] potato_adminMsg EH: %1", _this];
    };
}] call ace_common_fnc_addEventHandler;

["potato_missionHint", {
    //side is 0-dead, 1-dead+alive or actuall side like east/west
    params ["_msg", ["_side", 1, [sideEnemy, 0]], ["_rankMin", 0]];
    TRACE_3("potato_missionHint eh",_msg,_side,_rankMin);
    if (hasInterface) then {
        if ((_side isEqualTo 1) || {(!alive player) && {_side isEqualTo 0}} || {_side isEqualTo GVAR(playerStartingSide)}) then {
            private _playerRank = if (alive player) then {rankId player} else {999};
            if (_playerRank >= _rankMin) then {
                hint _msg;
            };
        };
    };
    if (isServer) then {
        diag_log text format ["[POTATO] potato_missionHint EH: %1", _this];
    };
}] call ace_common_fnc_addEventHandler;
