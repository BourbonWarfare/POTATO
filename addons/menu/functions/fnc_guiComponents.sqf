/*
 * Author: BadWolf
 * Function called when creating a menu using BadWolf's menu system.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_menu_fnc_guiComponents;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params["_array","_xStartPos","_yStartPos","_index","_hozVert","_group"];

private _ctrlSwitch = {
	params["_ctrlType","_ctrlCreate","_ctrltext","_ctrlfunction","_idc","_eh"];
	switch _ctrlType do {
		case "RscButton": {
            _ctrlCreate ctrlSetText _ctrltext;
            _ctrlCreate buttonSetAction _ctrlfunction;
            if(count _eh > 0) then {
                _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscText": {
            _ctrlCreate ctrlSetText _ctrltext;
            if (count _ctrlfunction == 4) then {
                _ctrlCreate ctrlSetTextColor _ctrlfunction;
            };
            if(count _eh > 0) then {
                _ctrlCreate ctrlAddEventHandler _eh;
            };
        };
		case "RscStructuredText": {
            _ctrlCreate ctrlSetStructuredText parseText _ctrltext;
            _ctrlCreate ctrlSetBackgroundColor [1, 1, 1, 0.25];
            if(count _eh > 0) then {
                _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscListBox": {
            lbCLear _ctrlCreate;
            {
            _ctrlCreate lbAdd _x;
            } forEach _ctrltext;
            _ctrlCreate lbSetCurSel 0;
            if(count _eh > 0) then {
                _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscPictureKeepAspect": {
            if(count _eh > 0) then {
                _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscCombo": {
            lbCLear _ctrlCreate;
            {
                _ctrlCreate lbAdd _x;
            } forEach _ctrltext;
            _ctrlCreate lbSetCurSel 0;
            if(count _eh > 0) then {
                _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscEdit": {
            _ctrlCreate ctrlSetText _ctrltext;
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscCheckBox": {
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscSlider": {
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscFrame": {
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscXListBox": {
            lbCLear _ctrlCreate;
            {
            _ctrlCreate lbAdd _x;
            } forEach _ctrltext;
            _ctrlCreate lbSetCurSel 0;
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscListBoxMulti": {
            lbCLear _ctrlCreate;
            {
            _ctrlCreate lbAdd _x;
            } forEach _ctrltext;
            _ctrlCreate lbSetCurSel 0;
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscHTML": {
            _ctrlCreate htmlLoad _ctrltext;
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscLine": {
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscEditMulti": {
            _ctrlCreate ctrlSetText _ctrltext;
            _ctrlCreate ctrlSetBackgroundColor [1, 1, 1, 0.25];
            _ctrlCreate ctrlSetTextColor TEXT_BLUE;
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
		case "RscControlsGroup": {
            if(count _eh > 0) then {
            _ctrlCreate ctrlAddEventHandler _eh;
            };
		};
	};
};

TRACE_1("Start of Loop",GVAR(groupHeight));

private _yCoord = nil;
private _groupHeight = 0;
if (!isNil "_yStartPos") then {
_yCoord = _yStartPos;
GVAR(groupHeight) = 0;
GVAR(yStartCoord) = _yStartPos;
} else {
    _yCoord = GVAR(yStartCoord) + GVAR(groupHeight);
};
if(!isNil "_index") then {
    GVAR(idcIndex) = _index;
} else {
    GVAR(idcIndex) = GVAR(idcIndex) + 1;
};
TRACE_1("",_yCoord);
private _xCoord = _xStartPos;
{
    _ctrlName = _x select 0;
    _ctrlType = _x select 1;
    _ctrlWidth = _x select 2;
    _ctrlHeight = _x select 3;
    _ctrltext = _x select 4;
    _ctrlfunction = _x select 5;
    _eh = _x select 6;
    _ctrlGroup = 0;
    TRACE_1("Creating Ctrl",_ctrlName);
    if(_ctrlType == "RscControlsGroup") then {
        _idc = 9990 + _ctrlfunction;
    } else {
        _idc = _forEachIndex + (10 * GVAR(idcIndex)) + 1000;
    };
    if(_hozVert == 1) then {
        _xCoord;
        _xCoord = _xStartPos;
    };
    if(_group > 0) then {
    _ctrlGroup = MENU_DISPLAY displayCtrl (9990 + _group);
    };
        private _ctrlCreate = MENU_DISPLAY ctrlCreate [_ctrlType,_idc,_ctrlGroup];
        _ctrlCreate ctrlSetPosition [_xCoord,_yCoord,_ctrlWidth,_ctrlHeight];
        [_ctrlType,_ctrlCreate,_ctrltext,_ctrlfunction,_idc,_eh] call _ctrlSwitch;
        _ctrlPosition = ctrlPosition _ctrlCreate;
        _stridc = str _idc + " at Position " + str _ctrlPosition;
        UITOOLTIP(_ctrlCreate,_stridc);
        _ctrlCreate ctrlCommit 0;
        if (_ctrlType == "RscStructuredText") then {
            if (!(_ctrltext == "")) then {
            _ctrlHeight =  ctrlTextHeight _ctrlCreate;
            _ctrlCreate ctrlSetPosition [_xCoord,_yCoord,_ctrlWidth,_ctrlHeight + 0.01];
            _ctrlCreate ctrlCommit 0;
            };
        };
    if(_hozVert == 1) then {
        _yCoord = _yCoord + _ctrlHeight + 0.01;
        _groupHeight = _groupHeight + _ctrlHeight + 0.01;
    } else {
        _xCoord = _xCoord + _ctrlWidth + 0.01;
        if(_groupHeight<_ctrlHeight) then {
            _groupHeight = _ctrlHeight + 0.01;
        };
    };
    TRACE_1("",_groupHeight);
} forEach _array;
GVAR(groupHeight) = GVAR(groupHeight) + _groupHeight;
TRACE_1("End of Loop",GVAR(groupHeight));
TRACE_1("",GVAR(idcIndex));
