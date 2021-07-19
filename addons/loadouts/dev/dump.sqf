// Dump
// [] spawn compileScript ["\z\potato\addons\loadouts\dev\dump.sqf"] // all
// [configFile >> "potato_loadouts" >> "potato_w" >> "aaf_f2000_digi"] spawn compileScript ["\z\potato\addons\loadouts\dev\dump.sqf"] // specific

#define DEBUG_MODE_FULL
#include "\z\potato\addons\loadouts\script_component.hpp"

disableSerialization;

if (isNil {EGVAR(assignGear,allowMagnifiedOptics)}) then { 
    EGVAR(assignGear,magnifiedOpticCache) = call CBA_fnc_createNamespace;
    EGVAR(assignGear,allowMagnifiedOptics) = false;
};

["showinterface",false] call bis_fnc_3DENInterface; // backspace

private _display = findDisplay 313;
private _textDisplay = _display getVariable ["dumpText", objNull];
if (isNull _textDisplay) then {
    _textDisplay = _display ctrlcreate ["RscStructuredText",-1];
    _textDisplay ctrlSetPosition [safezoneX, safezoneY, 0.2*safezoneW, 0.2*safezoneH];
    _textDisplay ctrlCommit 0;
    _display setVariable ["dumpText", _textDisplay];
};

private _origin = [1511,5000,0];
private _offset = [0.7, 0, 0];
private _dummies = [];
{
    _x params ["_type", "_dir", "_anim"];
    private _pos = _origin vectorAdd (_offset vectorMultiply _forEachIndex);
    private _dummy = create3DENEntity ["Object", _type, _pos];
    removeGoggles _dummy;
    _dummy switchMove _anim;
    _dummy set3DENAttribute ["rotation", [0,0, _dir]];
    _dummies pushBack _dummy;
} forEach [
    ["B_Soldier_F", -15, "AmovPercMstpSoptWbinDnon"], 
    ["B_Soldier_F", -30, "AmovPknlMstpSrasWrflDnon"], 
    ["B_Soldier_F", -75, "AmovPercMstpSrasWlnrDnon"],
    ["B_Soldier_F", 115, "AmovPercMstpSrasWrflDnon"],
    ["B_Soldier_F", 20, "AmovPknlMstpSrasWrflDnon"],
    ["B_Soldier_F", -30, "AmovPercMstpSlowWrflDnon"]
];

get3DENCamera setPos [1512.8,5002.52,1.09691];
get3DENCamera setVectorDirAndUp [[0,-1,-0.1],[0,0,1]];

private _allLoadouts = _this;
if (_allLoadouts isEqualTo []) then {
    _allLoadouts = "true" configClasses (configFile >> "potato_loadouts" >> "potato_w");
};
for "_i" from 3 to 0 step -1 do {
    _textDisplay ctrlSetStructuredText parseText format ["[Count %1] Starting in %2", count _allLoadouts, _i];
    sleep 0.5;
};



private _textOutput = [];

{
    private _loadoutPath = _x;
    private _loadoutName = configName _loadoutPath;
    private _description = getText (_loadoutPath >> "Description");
    if (_description == "") then { _description = "None"; };

    _textDisplay ctrlSetStructuredText parseText format ["<t size='2'>%1</t><br/><t size='1'>%2</t>",_loadoutName,_description];

    {
        private _unitType = _x;
        private _dummy = _dummies select _forEachIndex;
        private _loadoutArray = [_loadoutPath >> _unitType, objNull] call EFUNC(assignGear,getLoadoutFromConfig);
        _dummy setUnitLoadout _loadoutArray;
        // screenshot "x.png"; // super overexposed? - seems unusable
    } forEach ["coy", "sl", "lat", "sm", "ar", "vicl"];
    _textOutput pushBack format ["- ### `%1`", _loadoutName];
    _textOutput pushBack format ["![%1](/docs/loadouts/%2.jpg)%3", _description, _loadoutName, endl];

    sleep 0.01;
} forEach _allLoadouts;

private _output = _textOutput joinString endl;
copyToClipboard _output;

// cleanup
ctrlDelete _textDisplay;
{ deleteVehicle _x; } forEach _dummies;