#include "script_component.hpp"

params ["", "_sel"];
TRACE_1("tabchange",_sel);

disableSerialization;

private _fnc_setListOfPlayers = {
    params [
        ["_listCtrl", controlNull, [controlNull]],
        ["_nameCode", {[[_this] call ACEFUNC(common,getName), 0]}, [{}]],
        ["_condition", {true}, [{}]]
    ];

    lbClear _listCtrl;

    private _playerList = ((entities [["CAManBase"], ["HeadlessClient_F"], true, true]) select { isPlayer _x });

    {
        if (_x call _condition) then {
            private _unit = _x;
            (_unit call _nameCode) params [
                ["_name", "", [""]],
                ["_weight", 0, [0]],
                ["_rightName", "", [""]]
            ];

            private _recentMessages = [];
            {
                _x params ["_time", "_message", "_from"];
                if ((_from == [_unit] call ACEFUNC(common,getName)) && {(time - _time) < 300}) then {
                    _recentMessages pushBack _message;
                };
            } forEach (missionNamespace getVariable [QEGVAR(adminComs,logs), []]);

             private _index = _listCtrl lbAdd _name;
             _listCtrl lbSetValue [_index, _weight];
             _listCtrl lbSetData [_index, [_unit] call BIS_fnc_objectVar];
             _listCtrl lbSetColor [_index, [[1,0,0,1], [1,1,1,1]] select (_recentMessages isEqualTo [])];
             _listCtrl lbSetTooltip [_index, _recentMessages joinString "\n"];
             if (_rightName != "") then {
                _listCtrl lbSetTextRight [_index, _rightName];
             };

             TRACE_6("Item added to list",_listCtrl,_unit,_name,_weight,[_unit] call BIS_fnc_objectVar,_recentMessages);
        };
    } forEach _playerList;

    lbSortByValue _listCtrl;
    _listCtrl lbSetCurSel 0;
};

{
    _x ctrlShow (_forEachIndex == _sel);
} forEach UI_TABS_CONTROLS;

switch (_sel) do {
case (0): {
        TRACE_1("showing zeus tab",_sel);
        [
            UI_TAB_ZEUS_PLAYERS,
            {
                private _isNotZeus = isNull (getAssignedCuratorLogic _this);
                [
                    format [
                        "%1%2",
                        [_this] call ACEFUNC(common,getName),
                        [" [ZEUS]", ""] select _isNotZeus
                    ],
                    [0, 1] select _isNotZeus
                ]
            }
        ] call _fnc_setListOfPlayers;
    };
case (1): {
        TRACE_1("showing supplies tab",_sel);
        lbClear UI_TAB_SUPPLIES_TYPE;
        GVAR(supplyClassNames) = [];
        {
            private _className = configName _x;
            if (isClass (configFile >> "CfgVehicles" >> _className)) then {
                TRACE_2("veh exists in modset",_x,_className);
                GVAR(supplyClassNames) pushBack _className;
                private _description = if (isText (_x >> "displayName")) then {
                    getText (_x >> "displayName"); //use custom name
                } else {
                    getText (configFile >> "CfgVehicles" >> _className >> "displayName"); // use veh name
                };
                private _index = UI_TAB_SUPPLIES_TYPE lbAdd format ["%1", _description];
                UI_TAB_SUPPLIES_TYPE lbSetTooltip [_index, _className];
            } else {
                TRACE_2("veh missing from modset",_x,_className);
            };
        } forEach (configProperties [configFile >> QGVAR(supplies)]);
        UI_TAB_SUPPLIES_TYPE lbSetCurSel 0;

        lbClear UI_TAB_SUPPLIES_GROUP;
        GVAR(groupsArray) = [];
        {
            if ( ({(isPlayer _x)&&{alive _x}} count (units _x)) > 0) then {
                GVAR(groupsArray) pushBack _x;
                private _grpMembers = "";
                {_grpMembers = _grpMembers + format ["%1, ", (name _x)];} forEach (units _x);
                private _txt = format ["%1 [%2]", _x, _grpMembers];
                private _index = UI_TAB_SUPPLIES_GROUP lbAdd _txt;
                UI_TAB_SUPPLIES_GROUP lbSetTooltip [_index, _grpMembers];
            };
        } forEach allGroups;
        UI_TAB_SUPPLIES_GROUP lbSetCurSel 0;
    };
case (2): {
        TRACE_2("showing end mission tab",_sel,GVAR(openEndMission));
        if (GVAR(openEndMission)) then {
            UI_TAB_END_TEXT ctrlShow true;
            UI_TAB_END_UNLOCK ctrlShow false;
            private _txt = format ["Players Alive: %1<br/>", ({(alive _x)&&{isPlayer _x}} count allUnits)];
            _txt = _txt + format ["<br/><t color='#9999FF'>West Alive: %1 [Players: %2]</t>", ({(alive _x)&&{side _x == west}} count allUnits), ({(alive _x)&&(side _x == west)&&(isPlayer _x)} count allUnits)];
            _txt = _txt + format ["<br/><t color='#FF9999'>East Alive: %1 [Players: %2]</t>", ({(alive _x)&&{side _x == east}} count allUnits), ({(alive _x)&&(side _x == east)&&(isPlayer _x)} count allUnits)];
            _txt = _txt + format ["<br/><t color='#99FF99'>Indp Alive: %1 [Players: %2]</t>", ({(alive _x)&&{side _x == resistance}} count allUnits), ({(alive _x)&&(side _x == resistance)&&(isPlayer _x)} count allUnits)];
            _txt = _txt + format ["<br/><t color='#FF99FF'>Civ  Alive: %1 [Players: %2]</t>", ({(alive _x)&&{side _x == civilian}} count allUnits), ({(alive _x)&&(side _x == civilian)&&(isPlayer _x)} count allUnits)];
            UI_TAB_END_TEXT ctrlSetStructuredText parseText _txt;
        } else {
            UI_TAB_END_TEXT ctrlShow false;
            UI_TAB_END_UNLOCK ctrlShow true;
        };
    };
case (3): {
        TRACE_1("showing teleport tab",_sel);
        [
            UI_TAB_TELEPORT_PERSON,
            nil, // default to ace name
            {alive _this}
        ] call _fnc_setListOfPlayers;

        lbClear UI_TAB_TELEPORT_GROUP;
        GVAR(groupsArray) = [];
        {
            if ( ({(isPlayer _x)&&(alive _x)} count (units _x)) != 0) then {
                GVAR(groupsArray) pushBack _x;
                private _grpMembers = "";
                {_grpMembers = _grpMembers + format ["%1, ", (name _x)];} forEach (units _x);
                private _txt = format ["%1 [%2]", _x, _grpMembers];
                private _index = UI_TAB_TELEPORT_GROUP lbAdd _txt;
                UI_TAB_TELEPORT_GROUP lbSetTooltip [_index, _grpMembers];
            };
        } forEach allGroups;
        UI_TAB_TELEPORT_GROUP lbSetCurSel 0;
    };
case (6): {
        TRACE_1("showing mission hint tab",_sel);
        lbClear UI_TAB_MISSIONHINT_SIDE;
        lbClear UI_TAB_MISSIONHINT_RANK;
        {
            private _sideText = if (_x isEqualType 0) then {
                ["Dead", "All Players"] select _x;
            } else {
                str _x;
            };
            UI_TAB_MISSIONHINT_SIDE lbAdd _sideText;
        } forEach MISSION_HINT_SIDES;
        UI_TAB_MISSIONHINT_SIDE lbSetCurSel 0;
        {
            private _rankText = switch (_x) do {
                case (0): {"Private or higher"};
                case (1): {"Corporal or higher"};
                case (2): {"Sergeant or higher"};
                case (3): {"Lieutenant or higher"};
                default {"All Ranks"};
            };
            UI_TAB_MISSIONHINT_RANK lbAdd _rankText;
        } forEach MISSION_HINT_RANKS;
        UI_TAB_MISSIONHINT_RANK lbSetCurSel 0;
    };
case (7): {
        TRACE_1("showing fix unit tab",_sel);

        private _loadouts = [
            ["", "Default Gear"],
            ["sl", ""],
            ["ar", ""],
            ["aar", "Assistant to the Automatic Rifleman"],
            ["lat", ""],
            ["rifleman", ""],
            ["ftl", ""],
            ["coy", "CO and DC"],
            ["uav", ""],
            ["sm", "Squad Medic"],
            ["mmgg", "MMG Gunner"],
            ["mmgag", "MMG Spotter/Ammo Bearer"],
            ["mmgl", "MMG Lead"],
            ["matg", "MAT Gunner"],
            ["matag", "MAT Spotter/Ammo Bearer"],
            ["matl", "MAT Lead"],
            ["msamg", "SAM Gunner"],
            ["msamag", "SAM Spotter/Ammo Bearer"],
            ["mtrg", "Mortar Gunner"],
            ["mtrag", "Assistant Mortar"],
            ["sniper", ""],
            ["pilot", "rifleman"],
            ["vicc", "Crew"],
            ["vicd", "Repair Specialist"],
            ["vicl", "Vehicle Commander"],
            ["demo", "Explosive Specialist"],
            ["mine", "Mine Specialist"],
            ["demol", "Demolitions Leader"],
            ["eng", "Logistics Engineer"],
            ["fac", ""],
            ["rifleman_02", ""],
            ["artl", "Artillery Leader"],
            ["artg", "Artillery Gunner"]
        ];
        private _listGear = UI_TAB_FIX_UNIT_GEAR;
        lbClear _listGear;
        {
            _x params ["_loadout", "_description"];
            _description = if (_description == "") then { _loadout } else { format ["%1 (%2)", _loadout, _description] };
            private _index = _listGear lbAdd _description;
            _listGear lbSetData [_index, _loadout];
        } forEach _loadouts;
        _listGear lbSetCurSel 0;

        //IGNORE_PRIVATE_WARNING ["_x"];
        [
            UI_TAB_FIX_UNIT_LIST,
            {
                if (alive _this) then {
                    if (_this isKindOf QEGVAR(spectate,spectator)) then {
                        [name _this, 3, "(SPECTATOR)"]
                    } else {
                        if (uniform _x == "") then {
                            [name _this, 0, "(NAKED)"]
                        } else {
                            [name _this, 1]
                        }
                    }
                } else {
                    [[_this] call ACEFUNC(common,getName), 2, "(DEAD)"]
                }
            }
        ] call _fnc_setListOfPlayers;
    };
case UI_TABS_INDEX_MARKERS: {
        TRACE_1("showing markers tab",_sel);
        private _display = uiNamespace getVariable QGVAR(adminMenuDialog);

        private _help  = _display displayCtrl (POTATO_MARKER_HELP_IDC + 0);
        _help ctrlSetTooltip "There are two types of markers in BW
- Group markers - markers attached to a group leader and transferred when someone does the ""become leader"" action
- Unit markers - markers attached to specific unit that stay with them (i.e., Medic, FAC, etc)

Basics of the Menu
First list - Players:
- [LEFT] Names of all player names sorted in order: Has marker, no marker, dead, spectators
- [RIGHT] Marker side and text if they have a marker
Second list - Markers:
- [LEFT] Marker side and text
- [RIGHT] Whether the marker is attached to, followed by the marker icon. The text means either:
- ""AI"" for AI
- ""NA"" For not attached
- "" "" For attached to a player
When you're hovering over a marker in the marker list it will give you context of who the marker is currently attached to (unit), although the marker may be either a group or unit marker
";
        _help  = _display displayCtrl (POTATO_MARKER_HELP_IDC + 1);
        _help ctrlSetTooltip "The buttons on the righthand side give context on hover but from top to bottom
- Attach Marker to Unit - Attached the selected marker to the selected unit (converts marker to unit marker) - Mainly used for medics or FACs who crash and have to reJIP
- Attach Marker to Unit Group - Attach the selected marker to the selected unit's group (converts to a group marker) - For times when all group members mistakenly leave their group
- Detach Marker - Assigns the marker to no group/unit
- Delete Marker - Deletes marker
- Create Marker - Opens the creates new marker dialog
- Edit Marker - Opens the edit marker dialog (can edit
- Reload Unit Local Markers - Forces the selected unit to read any local markers they have
- Reload All Client Markers - Reloads everyone's markers from their local caches
- Reinit Server AI Markers - Sometimes unit markers don't appear on AI on the server during testing, this button just forces the server to reinitialize them.
";
        _help  = _display displayCtrl (POTATO_MARKER_HELP_IDC + 2);
        _help ctrlSetTooltip "How to Solve Common Problems
A player doesn't have a marker and should
- Check if the marker exists, if it doesn't make sure the MM intends for it to exist
- If it exists either attach it to them or their squad (depending if it's a unit or group marker)
- If it doesn't exist and the MM intended for it to be there, add it using the ""Create Marker"" dialog
- You can select whether the marker is attached to a unit or group in the dialog
A marker is no longer attached to a group because everyone left that group and joined a new one
- Check that group already has a marker, if so they will need to choose one or the other
- If they want the one not currently setup as their group marker, detach or delete the old group marker attach that marker to their group
- If they want the new one, you don't have to do anything
- If they don't have a marker, just attach the marker using the ""attach to group""";
        _help  = _display displayCtrl (POTATO_MARKER_HELP_IDC + 3);
        _help ctrlSetTooltip "A squad's SL died and an FTL would like to take over with the SL marker
- The FTL should join on the medic if alive and take command of the group
- If no one is left in that group, the FTL should leave their fireteam using the ""leave group"" interact and then the marker can be given to their new group
Someone can't see any markers
- Select the unit and click ""Reload Unit Local Markers""
- If that doesn't work after 20-30 seconds, run ""Reload All Client Markers""
";

        // Setup marker list
        private _markerList = _display displayCtrl IDC_LISTBOX_MARKERS_MARKERS;
        lbClear _markerList;
        {
            _y params ["_object", "_text", "_icon", "_color", "", "", "_side"];
            private _sideText = switch (_side) do {
                case west: {"BluFor"};
                case east: {"OpFor"};
                case resistance: {"IndFor"};
                case civilian: {"Civ"};
                default {"None "};
            };
            private _entry = _markerList lbAdd format ["%1 %2", _sideText, _text];
            _markerList lbSetPictureRight [_entry, _icon];
            _markerList lbSetPictureRightColor [_entry, _color];
            _markerList lbSetPictureRightColorSelected [_entry, _color];
            if !(isPlayer _object) then {
                if (isNull _object) then {
                    _markerList lbSetTextRight [_entry, "NA"];
                    _markerList lbSetTooltip [_entry, "Marker not attached"];
                } else {
                    _markerList lbSetTextRight [_entry, "AI"];
                    _markerList lbSetTooltip [_entry, "Marker attached to AI"];
                };
            } else {
                _markerList lbSetTooltip [_entry,
                    format ["Marker attached to %1",
                     [_object, false, true] call ace_common_fnc_getName]
                ];
            };
            _markerList lbSetData [_entry, _x];
        } forEach EGVAR(markers,markerHash);
        lbSort _markerList;
        _markerList lbSetCurSel 0;

        // Setup player list
        [
            _display displayCtrl IDC_LISTBOX_MARKERS_PLAYERS,
            {
                private _markerArr = EGVAR(markers,markerHash) getOrDefault [str side _this + str _this, []];
                if (_markerArr isEqualTo []) then {
                    _markerArr = EGVAR(markers,markerHash) getOrDefault [str side _this + groupId group _this, [objNull, ""]];
                };
                private _markerText = ["", _markerArr#1] select (_markerArr#0 == _this);
                private _side = if (count _markerArr >= 7) then {
                    [side _this, _markerArr#6] select (_markerArr#6 isEqualType grpNull)
                } else {
                    side _this
                };
                _side = switch (_side) do {
                    case west: {"BluFor "};
                    case east: {"OpFor "};
                    case resistance: {"IndFor "};
                    case civilian: {"Civ "};
                    default {"ERR "};
                };
                if (alive _this) then {
                    if (_this isKindOf QEGVAR(spectate,spectator)) then {
                        [format ["%1 (SPECTATOR)", name _this], 10]
                    } else {
                        if ([_this] call EFUNC(markers,hasMarkerAttached)) then {
                            [format ["%1", name _this], 0, _side + _markerText]
                        } else {
                            [format ["%1", name _this], 5]
                        }
                    }
                } else {
                    if ([_this] call EFUNC(markers,hasMarkerAttached)) then {
                        [format ["%1 (DEAD)", [_this] call ACEFUNC(common,getName)], 1, _side + _markerText]
                    } else {
                        [format ["%1 (DEAD)", [_this] call ACEFUNC(common,getName)], 5]
                    }
                }
            }
        ] call _fnc_setListOfPlayers;
    };
};
