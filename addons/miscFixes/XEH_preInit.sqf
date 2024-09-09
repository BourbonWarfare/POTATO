#include "script_component.hpp"

// fix Error in expression <layer getVariable "concentrationParam") <= 0.15};
if (fileExists "WebKnight_StarWars_Mechanic\bootstrap\XEH_postInit.sqf") then {
    INFO("trying to fix webknight melee popup");
    ["unit", {
        if (isNil {player getVariable "concentrationParam"}) then {
            INFO("fixing webknight melee popup");
            player setVariable ["concentrationParam", 0.5];
        };
    }, true] call CBA_fnc_addPlayerEventHandler;
};


if (["WBK_ZombieCreatures"] call ACEFUNC(common,isModLoaded)) then {
    private _wbkZombiesBase = ["Zombie_Special_OPFOR_Leaper_1","Zombie_Special_OPFOR_Screamer","Zombie_Special_OPFOR_Boomer","Zombie_O_Crawler_CSAT","Zombie_O_Walker_CSAT","Zombie_O_Shambler_CSAT","Zombie_O_RunnerCalm_CSAT","Zombie_O_RunnerAngry_CSAT","Zombie_O_Shooter_CSAT"];
    {
        [_x, "init", {
            params ["_unit"];
            TRACE_1("disabling lambs on zombie creturd",_unit);
            _unit setVariable ["lambs_danger_disableAI", true];
        }] call CBA_fnc_addClassEventHandler;
    } forEach _wbkZombiesBase;
};

//add EH to fix weapon lowering while walking fix
addUserActionEventHandler ["toggleRaiseWeapon","Activate",{ 
	private _lAnim = animationState ace_player;
	if ("stp" in _lAnim || "non" in _lAnim) exitWith {};
	_lAnim = _lAnim splitString "";
	private _state = [_lAnim #13,_lAnim #14,_lAnim #15] joinString "";
	switch(_state)do{
		case "ras": {
			_lAnim set [13,"l"];
			_lAnim set [14,"o"];
			_lAnim set [15,"w"];
		};
		case "low": {
			_lAnim set [13,"r"];
			_lAnim set [14,"a"];
			_lAnim set [15,"s"];
		};
	};
	private _nAnim = _lAnim joinString "";
    [{
        params ["_nAnim"];
        if (!alive ace_player) exitWith {};
        private _f = inputAction "MoveForward";
        private _b = inputAction "MoveBack";
        private _l = inputAction "TurnLeft";
        private _r = inputAction "TurnRight";
        private _tot = _f + _b + _l + _r;
        if (_tot == 0) then {
            private _tAnim = _nAnim splitString "_";
            _nAnim = _tAnim #0 splitString "";
            _nAnim set [9,"s"];
            _nAnim set [10,"t"];
            _nAnim set [11,"p"];
            _nAnim set [21,"n"];
            _nAnim set [22,"o"];
            _nAnim set [23,"n"];
            _nAnim = _nAnim joinString "";
            INFO_2("weapon lowering stopping %1->%2",animationState ace_player,_nAnim); // temp debug logging for problems
            [ace_player, _nAnim, 1] call ace_common_fnc_doAnimation;
        };
    }, [_nAnim], 0.5] call CBA_fnc_waitAndExecute;
}];
