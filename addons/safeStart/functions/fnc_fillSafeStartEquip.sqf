#include "..\script_component.hpp"
#define LASER_RANGE_FINDER ["Rangefinder", "ACE_Vector", "CUP_Vector21Nite", "CUP_Binocular_Vector", "ACE_VectorDay","gm_lp7_oli","gm_lpr1_oli","ACE_Yardage450"]
#define STANDARD_COLOR "#bbbbbb"
#define ATTENTION_COLOR "#ffffff"
#define HIGH_ATTENTION_COLOR "#febf62"
/***************************************************************************
* Author: Lambda.Tiger
*
* Description:
* This function displays gear and setting deviations from "standard."
* Focusing on navigation tools like GPS, night vision / flashlight equipment,
* settings like group markers. This setting does expect to find
*
* Arguments:
* 0: The safeStartEquip display (Display)
*
* Return:
* None
*
* Example:
* [] call potato_safeStart_fnc_fillSafeStartEquip;
******************************************************************************/
params [["_ctrlGroup", controlNull, [controlNull]]];

if (isNull _ctrlGroup) exitWith {};
private _missionTypeEnum = getMissionConfigValue [QEGVAR(missionTesting,missionType), 0];
if (GVAR(showTimer) != 2 || (_missionTypeEnum != 1 && _missionTypeEnum != 2 && !is3DENPreview)) exitWith {
    _ctrlGroup ctrlShow false;
    private _ctrlGroupParent = ctrlParentControlsGroup _ctrlGroup;
    (_ctrlGroupParent controlsGroupCtrl IDC_SAFESTARTEQUIP_BACKGROUND) ctrlShow false;
};
_ctrlGroup ctrlShow true;
private _ctrlGroupParent = ctrlParentControlsGroup _ctrlGroup;
(_ctrlGroupParent controlsGroupCtrl IDC_SAFESTARTEQUIP_BACKGROUND) ctrlShow true;

/// Loadouts for your sides units into hashmap
private _configRoot = missionConfigFile >> "CfgLoadouts" >> (
    switch (side player) do {
        case west: {"potato_w"};
        case east: {"potato_e"};
        case resistance: {"potato_i"};
        case civilian: {"CIV_F"};
        default {"potato_w"};
    }
);
private _unitHash = createHashMap;
private _flashLights = [];
private _nvgs = [];
private _explosives = [];
private _cfgWeapons = configFile >> "CfgWeapons";
{
    private _gearArray = [];
    {
        {
            (_x splitString ":") params ["_item"];
            _gearArray pushBack _item;
        } forEach getArray _x;
    } forEach configProperties [_x];
    _gearArray = _gearArray arrayIntersect _gearArray;
    {
        private _cfgPath = _cfgWeapons >> _x;
        if (!isClass _cfgPath) then {continue};
        if (getText (_cfgPath >> ACEGVAR(explosives,setupObjects)) != "") then {
            _explosives pushBackUnique _x;
            continue;
        };
        if ("NVG" in (getText (_cfgPath >> "simulation"))) then {
            _nvgs pushBackUnique _x;
            continue;
        };
        if (isClass (_cfgPath >> "ItemInfo" >> "FlashLight" >> "Attenuation")) then {
            _flashLights pushBackUnique _x;
        };
    } forEach _gearArray;
    _unitHash set [configName _x, _gearArray];
} forEach configProperties [_configRoot, "isClass _x"];

/// Settings
private _textArr = ["<t align='left' size='0.85'><t font='PuristaBold' size='1'>Mission</t>"];
private _menuXPos = profileNamespace getVariable [QUOTE(TRIPLES(igui,GVAR(grid),x)), SAFESTART_MENU_DEFAULT_X];
if (_menuxPos > 0.5) then {
    _textArr = ["<t align='right' size='0.85'><t font='PuristaBold' size='1'>Mission</t>"];
    private _title = _ctrlGroup controlsGroupCtrl IDC_SAFESTARTEQUIP_TITLE;
    _title ctrlSetStructuredText parseText "<t align='right'>Safe Start Info</t>"
};
private _missionType = ["Other", "Coop", "TvT", "After Hours"]#_missionTypeEnum;

_textArr pushBack format ["Mission Type: %1", _missionType];
//// Timings
private _safeStartLength = getMissionConfigValue [QEGVAR(missionTesting,SSTimeGiven), 0];
private _missionLength = getMissionConfigValue [QEGVAR(missionTesting,missionTimeLength), 0];
private _safeStartInBounds = true;
private _missionLengthInBounds = true;
switch (_missionTypeEnum) do {
    case 1: { // Coop
        _safeStartInBounds = _safeStartLength == 15;
        _missionLengthInBounds = _missionLength >= 60 && _missionLength <= 75;
    };
    case 2: { // TvT
        _safeStartInBounds = _safeStartLength == 10;
        _missionLengthInBounds = _missionLength >= 30 && _missionLength <= 40;
    };
};
// Safe start length
if (_safeStartInBounds) then {
    _textArr pushBack format [
        QUOTE(<t color=QUOTE(STANDARD_COLOR)>Safe Start Length: %1</t>),
        [60 * _safeStartLength, "M:SS"] call CBA_fnc_formatElapsedTime
    ];
} else {
    _textArr pushBack format [
        QUOTE(<t color=QUOTE(ATTENTION_COLOR)>Safe Start Length: %1</t>),
        [60 * _safeStartLength, "M:SS"] call CBA_fnc_formatElapsedTime
    ];
};
// Safe Start auto ends
if (EGVAR(safeStart,safeStartForceEnd)) then {
    _textArr pushBack QUOTE(<t color=QUOTE(ATTENTION_COLOR)>Safe Start Hard Limit: Yes</t>);
} else {
    _textArr pushBack QUOTE(<t color=QUOTE(STANDARD_COLOR)>Safe Start Hard Limit: No</t>);
};
// Mission Length
if (_missionLengthInBounds) then {
    _textArr pushBack format [
        QUOTE(<t color=QUOTE(STANDARD_COLOR)>Mission Length: %1</t>),
        [60 * _missionLength] call CBA_fnc_formatElapsedTime
    ];
} else {
    _textArr pushBack format [
        QUOTE(<t color=QUOTE(ATTENTION_COLOR)>Mission Length: %1</t>),
        [60 * _missionLength] call CBA_fnc_formatElapsedTime
    ];
};

//// Markers
_textArr pushBack "<t font='PuristaBold' size='1'>Markers</t>";
// Group & Unit markers
if (EGVAR(markers,groupAndUnitEnabled)) then {
    _textArr pushBack QUOTE(<t color=QUOTE(STANDARD_COLOR)>Blue Force Tracker: On</t>);
} else {
    _textArr pushBack QUOTE(<t color=QUOTE(ATTENTION_COLOR)>Blue Force Tracker: Off</t>);
};
// inter group markers
if (EGVAR(markers,intraFireteamEnabled)) then {
    if (EGVAR(markers,intraFireteam_playerOnly)) then {
        _textArr pushBack QUOTE(<t color=QUOTE(ATTENTION_COLOR)>Unit Map Markers: Player Only</t>);
    } else {
        _textArr pushBack QUOTE(<t color=QUOTE(STANDARD_COLOR)>Unit Map Markers: On</t>);
    };
} else {
    _textArr pushBack QUOTE(<t color=QUOTE(ATTENTION_COLOR)>Unit Map Markers: Off</t>);
};

//// Gear
_textArr pushBack "<t font='PuristaBold' size='1'>Equipment</t>";
// Radios
private _itemBoolArray = [
    "ACRE_PRC343" in (_unitHash getOrDefault ["rifleman", []]),
    "ACRE_PRC343" in (_unitHash getOrDefault ["flt", []]),
    "ACRE_PRC148" in (_unitHash getOrDefault ["sl", []]),
    "ACRE_PRC148" in (_unitHash getOrDefault ["plt", []]),
    "ACRE_PRC148" in (_unitHash getOrDefault ["sm", []])
];
private _subString = switch (true) do {
    case (_itemBoolArray#0 && _itemBoolArray#2): {"Full"};
    case (_itemBoolArray#1 && _itemBoolArray#2): {"FTL+"};
    case (_itemBoolArray#2): {"SL+"};
    default {"None"};
};
_textArr pushBack format ["<t color=""%1"">Radios: " + _subString +"</t>", [ATTENTION_COLOR, STANDARD_COLOR] select (_subString == "full")];
_textArr pushBack format ["<t color=""%1"">Medical Net: " + (["None", "Yes"] select (_itemBoolArray#4)) +"</t>", [ATTENTION_COLOR, STANDARD_COLOR] select (_itemBoolArray#4)];

// GPS, MicroDAGR
_itemBoolArray = [
    "ACE_microDAGR" in (_unitHash getOrDefault ["sl", []]),
    "ACE_microDAGR" in (_unitHash getOrDefault ["plt", []]),
    "ACE_microDAGR" in (_unitHash getOrDefault ["artl", []]),
    "ItemGPS" in (_unitHash getOrDefault ["ftl", []]),
    "ItemGPS" in (_unitHash getOrDefault ["sl", []]),
    "ItemGPS" in (_unitHash getOrDefault ["plt", []]),
    "ACE_microDAGR" in (_unitHash getOrDefault ["ftl", []])
];
_subString = switch (true) do {
    case (_itemBoolArray#0 && _itemBoolArray#1 && _itemBoolArray#6): {"FTL+"};
    case (_itemBoolArray#0 && _itemBoolArray#1 && _itemBoolArray#2): {"SL+ + Arty"};
    case (_itemBoolArray#0 && _itemBoolArray#1): {"SL+"};
    case (_itemBoolArray#1): {"PLT+"};
    default {"None"};
};
_textArr pushBack format ["<t color=""%1"">MicroDAGR: " + _subString +"</t>", [ATTENTION_COLOR, STANDARD_COLOR] select (_subString == "SL+" || _subString == "FTL+")];
_subString = switch (true) do {
    case (_itemBoolArray#3 && _itemBoolArray#4 && _itemBoolArray#5): {"FTL+"};
    case (_itemBoolArray#4 && _itemBoolArray#5): {"SL+"};
    case (_itemBoolArray#5): {"PLT+"};
    default {"None"};
};
_textArr pushBack format ["<t color=""%1"">GPS: " + _subString +"</t>", [ATTENTION_COLOR, STANDARD_COLOR] select (_subString == "FTL+")];

// Laser Range Finders
_itemBoolArray = [
    (LASER_RANGE_FINDER arrayIntersect (_unitHash getOrDefault ["sl", []])) isNotEqualTo [],
    (LASER_RANGE_FINDER arrayIntersect (_unitHash getOrDefault ["plt", []])) isNotEqualTo []
];
_subString = switch (true) do {
    case (_itemBoolArray#0 && _itemBoolArray#1): {"SL+"};
    case (_itemBoolArray#1): {"PLT+"};
    default {"None"};
};
_textArr pushBack format ["<t color=""%1"">Laser Rangefinder: " + _subString +"</t>", [ATTENTION_COLOR, STANDARD_COLOR] select (_subString == "SL+")];

// Shovels
if ("ACE_EntrenchingTool" in (_unitHash getOrDefault ["rifleman", []])) then {
    _textArr pushBack QUOTE(<t color=QUOTE(STANDARD_COLOR)>Entrenching Tool: Yes</t>);
} else {
    _textArr pushBack QUOTE(<t color=QUOTE(ATTENTION_COLOR)>Entrenching Tool: None</t>);
};

// Explosives
_itemBoolArray = [
    (_explosives arrayIntersect (_unitHash getOrDefault ["rifleman", []])) isNotEqualTo [],
    (_explosives arrayIntersect (_unitHash getOrDefault ["lat", []])) isNotEqualTo [],
    (_explosives arrayIntersect (_unitHash getOrDefault ["ftl", []])) isNotEqualTo [],
    (_explosives arrayIntersect (_unitHash getOrDefault ["sl", []])) isNotEqualTo []
];
_subString = switch (true) do {
    case (_itemBoolArray#2 && _itemBoolArray#2): {"FTL+"};
    case (_itemBoolArray#2): {"FTL"};
    case (_itemBoolArray#3): {"SL+"};
    default {""};
};
if (_itemBoolArray#1) then {
    if (_subString == "") then {
        _subString = _subString + "RAT";
    } else {
        _subString = _subString + ", RAT";
    };
};
if (_itemBoolArray#0) then {
    if (_subString == "") then {
        _subString = _subString + "Rifle";
    } else {
        _subString = _subString + ", Rifle";
    };
};
if (_subString == "") then {_subString = "None"};
_textArr pushBack format ["<t color=""%1"">Demo: " + _subString +"</t>", [ATTENTION_COLOR, STANDARD_COLOR] select (_subString == "None")];

// Night utilities (NVG & flashlight)
_itemBoolArray = [
    (_nvgs arrayIntersect (_unitHash getOrDefault ["rifleman", []])) isNotEqualTo [],
    (_nvgs arrayIntersect (_unitHash getOrDefault ["ftl", []])) isNotEqualTo [],
    (_nvgs arrayIntersect (_unitHash getOrDefault ["sl", []])) isNotEqualTo [],
    (_nvgs arrayIntersect (_unitHash getOrDefault ["plt", []])) isNotEqualTo []
];
_subString = switch (true) do {
    case (_itemBoolArray#0): {"All"};
    case (_itemBoolArray#1): {"FTL+"};
    case (_itemBoolArray#2): {"SL+"};
    case (_itemBoolArray#3): {"PLT+"};
    default {"None"};
};
_textArr pushBack format ["<t color=""%1"">Night Vision: " + _subString +"</t>", [ATTENTION_COLOR, STANDARD_COLOR] select (_subString == "None")];
_textArr pushBack format ["<t color=""%1"">Flashlights: " + (["Yes</t>", "None</t>"] select (_flashLights isEqualTo [])) +"</t>", [ATTENTION_COLOR, STANDARD_COLOR] select (_flashLights isEqualTo [])];

private _control = _ctrlGroup controlsGroupCtrl IDC_SAFESTARTEQUIP_TEXT;
_control ctrlSetStructuredText parseText (_textArr joinString "<br/>");
