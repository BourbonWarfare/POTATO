#define DEBUG_MODE_FULL
#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function attempts to find and group elements into categories of
 * company, platoons, weapons assets, armored assets, and air assets
 *
 * Arguments:
 * 0: The ORBAT hashmap to attempt to sort <HASHMAP>
 * 1: The array the diary entry for the orbat is built from <ARRAY>
 *
 * Examples:
 * [_orbatHash, []] call potato_briefing_fnc_addOrbat;
 *
 * Public: No
 */
params [
    ["_orbatToSort", createHashMap, [createHashMap]],
    ["_diaryBuilderArray", [], [[]]]
];

if (_orbatToSort isEqualTo createHashMap)  exitWith {};

/// Find all leaderships and keys
private _orbatAbrev = createHashMap;
private _leadKey = "";
{
    private _groupID = toLowerANSI _x;
    _y params ["_roleDescript", "", "_used"];
    if (_used) then {continue};
    if ("coy" in _groupID || {"coy" in _roleDescript}) exitWith {
        TRACE_2("Found coy",_groupID,_roleDescript);
        _leadKey = _x;
        _y set [2, true];
    };
} forEach _orbatToSort;
private _subKeys = [];
_orbatAbrev set ["coy", [_leadKey, _subKeys]];
if (_leadKey != "") then {
    {
        private _groupID = toLowerANSI _x;
        _y params ["_roleDescript", "", "_used"];
        if (_used) then {continue};
        if ("logi" in _groupID || {"logi" in toLowerANSI _roleDescript}) then {
            _subKeys pushBack _x;
            _y set [2, true];
        };
    } forEach _orbatToSort;
};

/// Weapons
_leadKey = "";
{
    private _groupID = toLowerANSI _x;
    _y params ["_roleDescript", "", "_used"];
    if (_used) then {continue};
    if ("wsl" in _groupID || {"weapon" in _roleDescript}) exitWith {
        _leadKey = _x;
        _y set [2, true];
    };
} forEach _orbatToSort;
_subKeys = [];
_orbatAbrev set ["wsl", [_leadKey, _subKeys]];
{
    private _groupID =  _x;
    _y params ["", "", "_used"];
    if (_used) then {continue};
    private _argArray = _y;
    private _lowerGroupID = toLowerANSI _groupID;
    {
        if (_x in _lowerGroupID) exitWith {
            TRACE_3("Found weapons team",_x,_lowerGroupID,_groupID);
            _subKeys pushBack _groupID;
            _argArray set [2, true];
        };
    } forEach ["mtr", "hmg", "mmg", "mat", "hat", "sniper", "st", "sam", "demo", "arty"];
} forEach _orbatToSort;

/// Armor / SV
_subKeys = [];
_orbatAbrev set ["ARMOR_NOLEAD", ["", _subKeys]];
{
    private _groupID = _x;
    _y params ["", "", "_used"];
    if (_used) then {continue};
    private _argArray = _y;
    private _lowerGroupID = toLowerANSI _groupID;
    {
        if (_x in _lowerGroupID) exitWith {
            TRACE_3("Found ground vehicle",_x,_lowerGroupID,_groupID);
            _subKeys pushBack _groupID;
            _argArray set [2, true];
        };
    } forEach ["ifv", "tank", "support", "sv", "tnk", "apc", "truck", "technical", "gun"];
} forEach _orbatToSort;

/// Air (AH/TH)
_subKeys = [];
_orbatAbrev set ["AIR_NOLEAD", ["", _subKeys]];
{
    private _groupID = _x;
    _y params ["_roleDescript", "", "_used"];
    if (_used) then {continue};
    private _argArray = _y;
    private _lowerGroupDesc = toLowerANSI _roleDescript;
    private _lowGroupID = toLowerANSI _groupID;
    {
        if (_x in _lowerGroupDesc || _x in _lowGroupID) exitWith {
            TRACE_5("Found air group",_x,_lowGroupID,_lowerGroupDesc,_groupID,_roleDescript);
            _subKeys pushBack _groupID;
            _argArray set [2, true];
        };
    } forEach ["helo", "heli", "fixed", "plane", "ah"];
} forEach _orbatToSort;

//// Zeus
_subKeys = [];
_orbatAbrev set ["ZEUS", ["", _subKeys]];
{
    private _groupID = _x;
    _y params ["_roleDescript", "", "_used"];
    if (_used) then {continue};
    private _argArray = _y;
    private _lowerGroupDesc = toLowerANSI _roleDescript;
    private _lowGroupID = toLowerANSI _x;
    {
        if (_x in _lowerGroupDesc || _x in _lowGroupID) exitWith {
            TRACE_5("Zeus",_x,_lowGroupID,_lowerGroupDesc,_groupID,_roleDescript);
            _subKeys pushBack _groupID;
            _argArray set [2, true];
        };
    } forEach ["zeus", "zane"];
} forEach _orbatToSort;

//// plt1-3
_subKeys = [];
{
    private _leadStr = _x;
    _leadKey = "";
    // find leader
    {
        private _groupID = toLowerANSI _x;
        _y params ["_roleDescript", "", "_used"];
        if (_used) then {continue};
        if (_leadStr in _groupID || {_leadStr in toLowerANSI _roleDescript}) exitWith {
            _leadKey = _x;
            _y set [2, true];
        };
    } forEach _orbatToSort;
    if (_leadKey == "") then {
        _orbatAbrev set [_leadStr, ["", []]];
        continue;
    };
    private _roleDescript = (_orbatToSort get _leadKey)#0;
    _roleDescript = (toLowerANSI _roleDescript) splitString "@";
    _roleDescript = _roleDescript#(count _roleDescript - 1);
    private _idx = _roleDescript find "(";
    private _keysToFind = if (_idx < 0) then {
        switch (true) do {
            case ("1" in _leadStr): {["alpha", "bravo", "charlie"]};
            case ("3" in _leadStr): {["delta", "echo", "foxtrot"]};
            case ("2" in _leadStr): {["golf", "hotel", "india"]};
            default {["alpha", "bravo", "charlie"]};
        }
    } else {
        _roleDescript = _roleDescript select [_idx];
        _roleDescript splitString "( ,)"
    };

    // find assets below leader
    _subKeys = [];
    _orbatAbrev set [_x, [_leadKey, _subKeys]];
    {
        private _groupID = _x;
        _y params ["_roleDescript", "", "_used"];
        if (_used) then {continue};
        private _argArray = _y;
        _roleDescript = toLowerANSI _roleDescript;
        private _firstChar = (toLowerANSI _groupID) select [0, 1];
        {
            if (_firstChar == (_x select [0, 1]) && {
                _x in _roleDescript
            }) exitWith {
                TRACE_4("Zeus",_x,_firstChar,_groupID,_roleDescript);
                _subKeys pushBack _groupID;
                _argArray set [2, true];
            };
        } forEach _keysToFind;
    } forEach _orbatToSort;
} forEach ["1pl", "2pl", "3pl"];


// Check for fireteams/squads and pile them into the last platoon if they aren't with anyone
if (_subKeys isNotEqualTo []) then {
    {
        private _groupID = _x;
        _y params ["_roleDescript", "", "_used"];
        if (_used) then {continue};
        private _argArray = _y;
        _roleDescript = toLowerANSI _roleDescript;
        private _firstChar = (toLowerANSI _groupID) select [0, 1];
        {
            if (_firstChar == (_x select [0, 1]) && {
                _x in _roleDescript
            }) exitWith {
                _subKeys pushBack _groupID;
                _argArray set [2, true];
            };
        } forEach ["alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india"];
    } forEach _orbatToSort;
} else {
    if (_leadKey == "") then {
        {
            private _groupID = _x;
            _y params ["_roleDescript", "", "_used"];
            if (_used) then {continue};
            _roleDescript = toLowerANSI _roleDescript;
            private _firstChar = (toLowerANSI _groupID) select [0, 1];
            {
                if (_firstChar == (_x select [0, 1]) && {
                    _x in _roleDescript
                }) exitWith {
                    private _platoon = switch (_x) do {
                        case "delta";
                        case "echo";
                        case "foxtrot": {"2pl"};
                        case "golf";
                        case "hotel";
                        case "india": {"3pl"};
                        default {"1pl"};
                    };
                    _orbatAbrev set [_platoon, ["", _subKeys]];
                    _leadKey = _groupID;
                };
            } forEach ["alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india"];
            if (_leadKey != "") exitWith {};
        } forEach _orbatToSort;
    };

    {
        private _groupID = _x;
        _y params ["_roleDescript", "", "_used"];
        if (_used) then {continue};
        private _argArray = _y;
        _roleDescript = toLowerANSI _roleDescript;
        private _firstChar = (toLowerANSI _groupID) select [0, 1];
        {
            if (_firstChar == (_x select [0, 1]) && {
                _x in _roleDescript
            }) exitWith {
                _subKeys pushBack _groupID;
                _argArray set [2, true];
            };
        } forEach ["alpha", "bravo", "charlie", "delta", "echo", "foxtrot", "golf", "hotel", "india"];
    } forEach _orbatToSort;
};

//// Logi
private _orbatArr = _orbatAbrev getOrDefault ["coy", ["", []]];
_leadKey = _orbatArr#0;
_subKeys = _orbatArr#1;
{
    if (_leadKey != "") exitWith {};
    _orbatArr = _orbatAbrev getOrDefault [_x, ["", []]];
    _leadKey = _orbatArr#0;
    _subKeys = _orbatArr#1;
} forEach ["1pl", "2pl", "3pl"];
if (_leadKey != "") then {
    {
        private _groupID = _x;
        _y params ["_roleDescript", "", "_used"];
        if (_used) then {continue};
        private _argArray = _y;
        private _lowerGroupID = toLowerANSI _groupID;
        private _lowerGroupDesc = toLowerANSI _roleDescript;
        {
            if (_x in _lowerGroupDesc || _x in _lowerGroupID) exitWith {
                _subKeys pushBack (" | " + _groupID);
                _argArray set [2, true];
            };
        } forEach ["logi", "eng"];
    } forEach _orbatToSort;
};

//// Other
_subKeys = [];
_orbatAbrev set ["OTH_NOLEAD", ["", _subKeys]];
{
    _y params ["", "", "_used"];
    if (_used) then {continue};
    _subKeys pushBack _x;
} forEach _orbatToSort;

private _fnc_enumAlpha = {
    params ["_str", ""];
    switch ((toLowerANSI _str) select [0,1]) do {
        case " ": {-10};
        case "a": {00};
        case "b": {10};
        case "c": {20};
        case "d": {30};
        case "e": {40};
        case "f": {50};
        case "g": {60};
        case "h": {70};
        case "i": {80};
        case "j": {90};
        case "k": {100};
        case "l": {120};
        case "m": {130};
        case "n": {120};
        case "o": {150};
        case "p": {160};
        case "q": {170};
        case "r": {180};
        case "s": {190};
        case "t": {200};
        case "u": {210};
        case "v": {220};
        case "w": {230};
        case "x": {240};
        case "y": {250};
        case "z": {260};
        default {300};
    };
};

// We output them in the following order
{
    _x params ["_key", "_str"];
    private _args = _orbatAbrev getOrDefault [_key, ["", []]];
    _args params ["_lead", "_groups"];
    if (_lead == "" && _groups isEqualTo []) then {continue};
    _diaryBuilderArray pushBack _str;
    private _addedPlt = false;
    if (_lead != "") then {
        _addedPlt = true;
        private _args = _orbatToSort get _lead;
        _diaryBuilderArray pushBack (_args#1);
    };
    if (_groups isNotEqualTo []) then {
        if ("pl" in _key) then {
            _groups = _groups apply {
                [([_x] call _fnc_enumAlpha), parseNumber (_x select [1]), _x]
            };
            _groups sort true;
            _groups = _groups apply {_x#2};
            _args set [1, _groups];
        } else {
            _groups sort true;
        };
        {
            if (_x select [0, 3] == " | ") then {_x = _x select [3]};
            private _args = _orbatToSort get _x;
            if (_addedPlt && ("sl" in toLowerANSI _x || { // nasty regex isn't it?
                (_x regexMatch ".*alpha.*|.*bravo.*|.*charlie.*|.*delta.*|.*echo.*|.*foxtrot.*|.*golf.*|.*hotel.*|.*india.*/gi")
            })) then {
                _diaryBuilderArray pushBack ("<font size='4'><br/></font>" + (_args#1));
            } else {
                _addedPlt = true;
                _diaryBuilderArray pushBack (_args#1);
            };
        } forEach _groups;
    };
} forEach [
    ["coy", "<font face='PuristaBold' size='12'>Company Element</font>"],
    ["1pl", "<br/><font face='PuristaBold' size='12'>1st Platoon</font>"],
    ["wsl", "<br/><font face='PuristaBold' size='12'>Weapons Teams</font>"],
    ["2pl", "<br/><font face='PuristaBold' size='12'>2nd Platoon</font>"],
    ["3pl", "<br/><font face='PuristaBold' size='12'>3rd Platoon</font>"],
    ["ARMOR_NOLEAD", "<br/><font face='PuristaBold' size='12'>Armor Assets</font>"],
    ["AIR_NOLEAD", "<br/><font face='PuristaBold' size='12'>Air Assets</font>"],
    ["OTH_NOLEAD", ""],
    ["ZEUS", "<br/><font face='PuristaBold' size='12'>High Command</font>"]
];
