/*
 * Author: BadWolf
 * Function called to populate the side arrays for each side. Will the default display the infromation for west.
 *
 * Arguments:
 * 0: side <INTERGER>
 *
 * Examples:
 * [0] call potato_missionTesting_fnc_weaponsReport;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params["_menu","_tabArray"];
private _activeTab = _tabArray select _menu;
TRACE_1("Menu Selected ",_activeTab);
if (isNull MENU_DISPLAY) then {
    createDialog QGVAR(onePanelMenu);
    GVAR(groupHeight) = 0;
    GVAR(yStartCoord) = 0;
    GVAR(idcIndex) = 0;
    //Main Frame. This should be moved to a Class system so that I can have multiple types of main frames and customize from there.
    private _ctrlBackground = MENU_DISPLAY ctrlCreate ["RscBackgroundGUI",-1];
    _ctrlBackground ctrlSetPosition [0,0,1,1];
    _ctrlBackground ctrlCommit 0;
    private _leftFrame = MENU_DISPLAY ctrlCreate ["RscFrame",-1];
    _leftFrame ctrlSetPosition [0,0,1,1];
    _leftFrame ctrlCommit 0;
    private _leftGroup = MENU_DISPLAY ctrlCreate ["RscControlsGroup",9991];
    _leftGroup ctrlSetPosition [0,0,1,1];
    _leftGroup ctrlCommit 0;
    private _menuOK = MENU_DISPLAY ctrlCreate ["RscButtonMenuOK",9990];
    _menuOK ctrlSetPosition [0.75,1,0.12,0.1];
    UITOOLTIP(_menuOK,"9990");
    _menuOK ctrlCommit 0;
    private _menuCancel = MENU_DISPLAY ctrlCreate ["RscButtonMenuCancel",-1];
    _menuCancel ctrlSetText "Close";
    _menuCancel ctrlSetPosition [0.88,1,0.12,0.1];
    _menuCancel buttonSetAction "closeDialog 2;";
    _menuCancel ctrlCommit 0;
    {
        private _idc = _forEachIndex + 3000;
        private _ctrl = MENU_DISPLAY ctrlCreate ["RscButtonMenu",_idc];
        Private _yStartPos = 0;
        Private _yCoord = nil;
        private _tabName = _x;
        if(_forEachIndex == 0) then {
            _yCoord = _yStartPos;
        } else {
            _yCoord = _yStartPos + (_forEachIndex * 0.11);
        };
        _ctrl ctrlSetPosition [-0.15,_yCoord,0.15,0.1];
        _ctrl ctrlSetText _tabName;
        _ctrl ctrlCommit 0;
    } forEach _tabArray;
} else {
    // Clean up of previous controls.
    if (isNull MENU_DISPLAY) exitWith { systemChat "bad display"; };
    private _ctrls = [];
    for "_i" from 1000 to 2000 do {
        with uiNamespace do {
            private _ctrl = MENU_DISPLAY displayCtrl _i;
            if (!isNull _ctrl) then {
                _ctrls pushBack _i;
            };
        };
    };
    {
        private _ctrl = MENU_DISPLAY displayCtrl _x;
        _ctrl ctrlRemoveAllEventHandlers "LBSelChanged";
        _ctrl ctrlRemoveAllEventHandlers "CheckedChanged";
        _ctrl ctrlRemoveAllEventHandlers "SliderPosChanged";
        ctrlDelete _ctrl;
    } forEach _ctrls;
};
