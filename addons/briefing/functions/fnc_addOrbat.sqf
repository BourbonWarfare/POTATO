/*
 * Author: PabstMirror
 * Function used to add the order of battle to player's diary
 *
 * Arguments:
 * 0: Unit to add to the OrBat to <OBJECT>
 *
 * Examples:
 * [player] call potato_briefing_fnc_addOrbat;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);

_this spawn {
    uiSleep 10;

    params ["_unit"];
    TRACE_1("",_unit);
<<<<<<< HEAD

    private _debugMode = false;	//allows for AI to create ORBAT entries for testing

    _diaryHyperlinkedText = "";

    private _bsm_write = {
        params ["_masterList","_playerGroupsID","_playerGroups","_diaryHyperlinkedText"];
        {
            _groupID = _x select 0;
            _color = _x select 1;
            _displayName = _x select 2;
            _code = compile format ['
                if (''%1'' in _playerGroupsID) then {
                    _group = _playerGroups select (_playerGroupsID find ''%1'');
                    private _unitsText = ''<font face=''''PuristaLight'''' color=''''%2'''' size=''''13''''>'';
                    if ((count units _group) > 0) then {
                        {
                            _unitsText = _unitsText + (name _x + '', '');
                        } forEach units _group;
                        _unitsText = [_unitsText,0,-2] call BIS_fnc_trimString;
                        _unitsText = _unitsText + ''</font>'';

                        _diaryHyperlinkedText = _diaryHyperlinkedText + format [''<font face=''''PuristaMedium'''' color=''''#FFFFFF'''' size=''''13''''>%3 </font>''];
                        _diaryHyperlinkedText = _diaryHyperlinkedText + _unitsText;
                        _diaryHyperlinkedText = _diaryHyperlinkedText + format [''<br/>''];
                    };
                };
            ',_groupID,_color,_displayName];
            call _code;
        } forEach _masterList;
        _diaryHyperlinkedText
    };

    private _sideString = switch (playerSide) do {
        case west: {"BluFor "};
        case east: {"Indy "};
        case resistance: {"OpFor "};
    };


    _diaryHyperlinkedText = "";

    private _playerGroupsID = [];
    private _playerGroups = [];

    {
        private _group = _x;
        _playerNum = {isPlayer _x} count (units _group);	//number of players in the group
        if (((_playerNum > 0) || _debugMode) && (side _group == playerSide)) then {	//if more than zero players in group and group is west, add to templist of groups to check
            _playerGroupsID pushBack (groupID _group);
            _playerGroups pushBack _group;
        };
    } forEach allGroups;

    // ===================================================================================
    // COY HQ

    _coyExists = (({_x in _playerGroupsID} count [_sideString + "COY"]) > 0);
    if (_coyExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='18'>Signal Company</font><br/>"];
        _coyMaster = [
            [_sideString + "COY","#AE00AE","CoyHQ"]
        ];
        _diaryHyperlinkedText = [_coyMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // 1 PLATOON HQ

    _1platoonExists = (({_x in _playerGroupsID} count [_sideString + "1PLT"]) > 0);
    if (_1platoonExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='16'>1 Platoon</font><br/>"];
        _1platoonMaster = [
            [_sideString + "1PLT","#AE00AE","1PltHQ"]
        ];
        _diaryHyperlinkedText = [_1platoonMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // 2 PLATOON HQ

    _2platoonExists = (({_x in _playerGroupsID} count [_sideString + "2PLT"]) > 0);
    if (_2platoonExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>2 Platoon</font><br/>"];

        _2platoonMaster = [
            [_sideString + "2PLT","#AE00AE","PltHQ"]
        ];

        _diaryHyperlinkedText = [_2platoonMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // ALPHA SQUAD

    _alphaExists = (({_x in _playerGroupsID} count [_sideString + "ASL",_sideString + "A1",_sideString + "A2",_sideString + "A3"]) > 0);
    if (_alphaExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>Alpha Squad</font><br/>"];

        _alphaMaster = [
            [_sideString + "ASL","#FF0000","ASL"],
            [_sideString + "A1","#FF0000","A1"],
            [_sideString + "A2","#FF0000","A2"],
            [_sideString + "A3","#FF0000","A3"]
        ];

        _diaryHyperlinkedText = [_alphaMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // BRAVO SQUAD

    _bravoExists = (({_x in _playerGroupsID} count [_sideString + "BSL",_sideString + "B1",_sideString + "B2",_sideString + "B3"]) > 0);
    if (_bravoExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>Bravo Squad</font><br/>"];

        _bravoMaster = [
            [_sideString + "BSL","#00B1EC","BSL"],
            [_sideString + "B1","#00B1EC","B1"],
            [_sideString + "B2","#00B1EC","B2"],
            [_sideString + "B3","#00B1EC","B3"]
        ];

        _diaryHyperlinkedText = [_bravoMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // CHARLIE SQUAD

    _charlieExists = (({_x in _playerGroupsID} count [_sideString + "CSL",_sideString + "C1",_sideString + "C2",_sideString + "C3"]) > 0);
    if (_charlieExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>Charlie Squad</font><br/>"];

        _charlieMaster = [
            [_sideString + "CSL","#00FF00","CSL"],
            [_sideString + "C1","#00FF00","C1"],
            [_sideString + "C2","#00FF00","C2"],
            [_sideString + "C3","#00FF00","C3"]
        ];

        _diaryHyperlinkedText = [_charlieMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // DELTA SQUAD

    _deltaExists = (({_x in _playerGroupsID} count [_sideString + "DSL",_sideString + "D1",_sideString + "D2",_sideString + "D3"]) > 0);
    if (_deltaExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>Delta Squad</font><br/>"];

        _deltaMaster = [
            [_sideString + "DSL","#FF0000","DSL"],
            [_sideString + "D1","#FF0000","D1"],
            [_sideString + "D2","#FF0000","D2"],
            [_sideString + "D3","#FF0000","D3"]
        ];

        _diaryHyperlinkedText = [_deltaMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // ECHO SQUAD

    _echoExists = (({_x in _playerGroupsID} count [_sideString + "ESL",_sideString + "E1",_sideString + "E2",_sideString + "E3"]) > 0);
    if (_echoExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>Echo Squad</font><br/>"];

        _echoMaster = [
            [_sideString + "ESL","#00B1EC","ESL"],
            [_sideString + "E1","#00B1EC","E1"],
            [_sideString + "E2","#00B1EC","E2"],
            [_sideString + "E3","#00B1EC","E3"]
        ];

        _diaryHyperlinkedText = [_echoMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // FOXTROT SQUAD

    _foxtrotExists = (({_x in _playerGroupsID} count [_sideString + "FSL",_sideString + "F1",_sideString + "F2",_sideString + "F3"]) > 0);
    if (_foxtrotExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>Foxtrot Squad</font><br/>"];

        _foxtrotMaster = [
            [_sideString + "FSL","#00FF00","FSL"],
            [_sideString + "F1","#00FF00","F1"],
            [_sideString + "F2","#00FF00","F2"],
            [_sideString + "F3","#00FF00","F3"]
        ];

        _diaryHyperlinkedText = [_foxtrotMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // GROUND SUPPORT

    _groundExists = (({_x in _playerGroupsID} count [_sideString + "IFV1",_sideString + "IFV2",_sideString + "IFV3",_sideString + "IFV4",_sideString + "TNK1"]) > 0);
    if (_groundExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>Ground Support</font><br/>"];

        _groundMaster = [
            [_sideString + "IFV1","#FFFFFF","IFV 1"],
            [_sideString + "IFV2","#FFFFFF","IFV 2"],
            [_sideString + "IFV3","#FFFFFF","IFV 3"],
            [_sideString + "IFV4","#FFFFFF","IFV 4"],
            [_sideString + "TNK1","#FFFFFF","Tank 1"]
        ];

        _diaryHyperlinkedText = [_groundMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // AIR SUPPORT

    _airExists = (({_x in _playerGroupsID} count [_sideString + "TH1",_sideString + "TH2",_sideString + "TH3",_sideString + "TH4",_sideString + "AH1"]) > 0);
    if (_airExists) then {
        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font face='PuristaBold' color='#FFFFFF' size='14'>Air Support</font><br/>"];

        _airMaster = [
            [_sideString + "TH1","#FFFFFF","Trans. Helo 1"],
            [_sideString + "TH2","#FFFFFF","Trans. Helo 2"],
            [_sideString + "TH3","#FFFFFF","Trans. Helo 3"],
            [_sideString + "TH4","#FFFFFF","Trans. Helo 4"],
            [_sideString + "AH1","#FFFFFF","Attack Helo 1"]
        ];

        _diaryHyperlinkedText = [_airMaster,_playerGroupsID,_playerGroups,_diaryHyperlinkedText] call _bsm_write;
    };

    // ===================================================================================
    // FINISH

    if (_diaryHyperlinkedText != "") then {
        player createDiaryRecord ["diary", ["ORBAT", _diaryHyperlinkedText]];
    };
=======

    private _diaryBuilder = [];
    _diaryBuilder pushBack "<font size='8'>Only accurate at mission start.</font>";

    {
        if (({isPlayer _x} count (units _x)) > 0) then {
            if (((side _x) getFriend playerSide) >= 0.6) then {
                private _color = switch (side _x) do {
                    case (west): { "#0088EE" }; // use profile colors here
                    case (east): { "#DD0000" };
                    case (resistance): { "#00DD00" };
                    case (civilian): { "#880099" };
                    default { "#FFFFFF" };
                };
                _diaryBuilder pushBack format ["<font color='%1' size='16'>%2</font>", _color, (groupID _x)];
                {
                    private _xIcon = gettext (configfile >> "CfgVehicles" >> typeOf (vehicle _x) >> "icon");
                    private _image = gettext (configfile >> "CfgVehicleIcons" >> _xIcon);
                    _diaryBuilder pushBack format ["<img image='%1' width='16' height='16'/><font size='14'>%2</font>", _image, (name _x)];
                } forEach (units _x);
            };
        };
    } forEach allGroups;

    _unit createDiaryRecord ["diary", ["ORBAT", _diaryBuilder joinString "<br/>"]];
>>>>>>> 41d3ae471fa68c936cf90e057aa94ee5ef0b918c
};
