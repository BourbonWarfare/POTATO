#include "script_component.hpp"

#define ICON_MARKER_SIZE 1.1
#define ICON_FIRETEAM_SIZE 1.6
#define ICON_REPORT_SIZE 0.56

if (isNull (findDisplay 312)) exitWith {
    TRACE_1("removing Draw3D EH",_this);
    removeMissionEventHandler ["Draw3d", _thisEventHandler];
};

{
    _x params ["_isInfantry", "_grpPositionAverage", "", "_spotTimeString", "", "_icon"];

    if (_isInfantry) then {
        drawIcon3D ["\A3\ui_f\data\map\markers\nato\o_inf.paa", [1,0.4,0.1,1], _grpPositionAverage, ICON_MARKER_SIZE, ICON_MARKER_SIZE, 0, ""];
        drawIcon3D [_icon, [1,1,1,0.75], _grpPositionAverage, ICON_FIRETEAM_SIZE, ICON_FIRETEAM_SIZE, 0, ""];
    } else {
        drawIcon3D [_icon, [1,0.4,0.1,0.75], _grpPositionAverage, ICON_MARKER_SIZE, ICON_MARKER_SIZE, 0, ""];
    };

    drawIcon3D ["", [1,1,1,1], _grpPositionAverage, 1.25, 1.25, 0, _spotTimeString, 1, 0.02, "TahomaB", "center"];

} forEach GVAR(targetGroups);

{
    _x params ["_xGroup", "", "", "_xIcon", "_xIconColor"];
    private _leader = leader _xGroup;
    if (!isNull _leader) then {
        private _distance = (positionCameraToWorld [0,0,0]) distance _leader;
        private _drawPosAGL = (_leader modelToWorldVisual (_leader selectionPosition "pelvis")) vectorAdd [0,0,linearConversion [200, 360, _distance, 5.3, 20, true]];
        drawIcon3D [_xIcon, _xIconColor, _drawPosAGL, ICON_REPORT_SIZE, ICON_REPORT_SIZE, 0, "", 1];
    };
} forEach GVAR(friendlyReports);
