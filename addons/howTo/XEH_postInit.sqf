#include "script_component.hpp"
if (!hasInterface) exitWith {};

GVAR(howToUse) = createHashMapFromArray [  //IGNORE_PRIVATE_WARNING ["_player", "_units", "_vehicles"];
#include "guides\ace_hunterkiller.inc.sqf"
,
#include "guides\ace_javelin.inc.sqf"
,
#include "guides\ace_manpad_locking.inc.sqf"
,
#include "guides\ace_mclos.inc.sqf"
,
#include "guides\ace_spike.inc.sqf"
,
#include "guides\ace_superDragon.inc.sqf"
,
#include "guides\ace_vector.inc.sqf"
,
#include "guides\launcher_gm_m72.inc.sqf"
,
#include "guides\launcher_m136.inc.sqf"
,
#include "guides\launcher_rpg7-pgo.inc.sqf"
];
GVAR(showAll) = false;
["unit", {
    private _endtime = CBA_missionTime + 60;
    [{
        params ["_args", "_handle"];
        _args params ["_endTime"];
        if (CBA_missionTime > _endTime) exitWith { [_handle] call CBA_fnc_removePerFrameHandler };

        private _player = ace_player;
        private _units = [_player];
        if GVAR(showForGroupMembers) then { _units append (units group _player); };
        _units = _units arrayIntersect _units;

        private _type = toLower (typeOf _player) select [9];
        private _vehicles = createHashMap;
        switch (true) do {
            case (_type in ["vicl", "vicc", "vicd"]): {
                {
                    _vehicles set [typeOf _x, _x];
                } forEach nearestObjects [_player, ["Car", "Tank"], 200];
            };
            case (_type in ["pilot", "helicrew", "cc"]): {
                {
                    _vehicles set [typeOf _x, _x];
                } forEach nearestObjects [_player, ["Air"], 200];
            };
        };

        private _added = _player getVariable [QGVAR(hintsAdded), []];
        {
            if (_x in _added) then { continue };
            _y params ["_condition", "_text"];
            if (GVAR(showAll) || _condition) then {
                _added pushBack _x;
                if (!(_player diarySubjectExists QUOTE(ADDON))) then {
                    _player createDiarySubject [QUOTE(ADDON), "HowTo", QPATHTOEF(core,potato_icon_ca.paa)];
                };
                _player createDiaryRecord [QUOTE(ADDON), [_x, call _text, ""], taskNull, "", false];
            };
        } forEach GVAR(howToUse);
        _player setVariable [QGVAR(hintsAdded), _added];
    }, 5, [_endtime]] call CBA_fnc_addPerFrameHandler;
}, true] call CBA_fnc_addPlayerEventHandler;
