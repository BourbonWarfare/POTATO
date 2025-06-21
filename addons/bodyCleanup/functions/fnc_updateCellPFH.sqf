#include "script_component.hpp"

/*
 * Author: Bailey
 * Updates cells
 *
 * Arguments:
 * Time since last update <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call potato_bodyCleanup_fnc_updateCellPFH;
 *
 * Public: No
 */
params ["_dt"];

private _inTriangle = {
    params ["_p", "_p1", "_p2", "_p3"];
    _p params ["_px", "_py"];
    _p1 params ["_x1", "_y1"];
    _p2 params ["_x2", "_y2"];
    _p3 params ["_x3", "_y3"];

    private _d1 = (_px - _x2) * (_y1 - _y2) - (_x1 - _x2) * (_py - _y2);
    private _d2 = (_px - _x3) * (_y2 - _y3) - (_x2 - _x3) * (_py - _y3);
    private _d3 = (_px - _x1) * (_y3 - _y1) - (_x3 - _x1) * (_py - _y1);

    private _hasNeg = (_d1 < 0) || (_d2 < 0) || (_d3 < 0);
    private _hasPos = (_d1 > 0) || (_d2 > 0) || (_d3 > 0);
    
    !(_hasNeg && _hasPos)
};

private _viewCones = call FUNC(getPlayerViewCones);
// We will cull as many cells as we can to avoid the O(n*m) complexity
private _cellsToCheck = values GVAR(cells);

// First: Remove cells that lay outside of maximum visible range of any unit
private _meanPosition = [0, 0, 0];
{
    _x params ["_position"];
    _meanPosition = _meanPosition vectorAdd _position;
} forEach _viewCones;
_meanPosition = _meanPosition vectorMultiply (1 / (1 max count _viewCones));

private _maxDistance = 0;
{
    _x params ["_position"];
    _maxDistance = _maxDistance max (_position vectorDistance _meanPosition);
} forEach _viewCones;
_maxDistance = _maxDistance + MAX_CLEANUP_DISTANCE;

// Cull cells that lay outside of bounding circle of all units
_cellsToCheck = _cellsToCheck select {
    _x params ["", "", "", "", "_position"];
    (_position vectorDistance _meanPosition) <= _maxDistance
};

// Determine which cells can be seen
private _visibleCells = [];
{
    _x params ["_origin", "_viewDirection", "_polar", "_fov"];
    _polar params ["", "_azimuth"];

    {
        _x params ["_sideLength", "", "", "_isHidden", "_cellCenter", "_key"];
        // Ignore all cells out of bounds
        if ((_origin vectorDistance _cellCenter) > MAX_CLEANUP_DISTANCE) then {
            continue;
        };

        // If we are within the minimum cleanup distance, then we will update the cell
        if ((_origin vectorDistance _cellCenter) <= MIN_CLEANUP_DISTANCE) then {
            _visibleCells pushBack (_cellsToCheck deleteAt _forEachIndex);
            continue;
        };

        // First: Cull any cells that aren't in the direction we are facing
        private _directionToCell = _origin vectorFromTo _cellCenter;
        private _dot = _viewDirection vectorDotProduct _directionToCell;

        // If dot product < 0, then we are looking away from the cell so we don't consider it
        if (_dot <= 0) then {
            continue;
        };

        private _length = MAX_CLEANUP_DISTANCE / cos _fov;

        // Second: Determine if cell is within bounding box of FOV
        private _left = (_azimuth - _fov);
        private _right = (_azimuth + _fov);

        private _h2 = [sin _left, cos _left, 0] vectorMultiply _length;
        private _h3 = [sin _right, cos _right, 0] vectorMultiply _length;

        private _p1 = _origin;
        private _p2 = _origin vectorAdd _h2;
        private _p3 = _origin vectorAdd _h3;

        private _minX = (_p1 select 0) min (_p2 select 0) min (_p3 select 0);
        private _maxX = (_p1 select 0) max (_p2 select 0) max (_p3 select 0);
        private _minY = (_p1 select 1) min (_p2 select 1) min (_p3 select 1);
        private _maxY = (_p1 select 1) max (_p2 select 1) max (_p3 select 1);

        if !(_minX < (_cellCenter select 0) - _sideLength / 2 && _maxX >= (_cellCenter select 0) + _sideLength / 2 &&
             _minY < (_cellCenter select 1) - _sideLength / 2 && _maxY >= (_cellCenter select 1) + _sideLength / 2) then {
            continue;
        };

        // Third: Determine if cell lays within the triangle
        // We only check if the cell's center is within the FOV. This is for optimisation. We miss a few, but no biggie
        if ([_cellCenter, _p1, _p2, _p3] call _inTriangle) then {
            _visibleCells pushBack (_cellsToCheck deleteAt _forEachIndex);
        };
    } forEachReversed _cellsToCheck;
} forEach _viewCones;

{
    _x params ["", "", "", "_isHidden", "", "_key"];
    _x set [2, CBA_missionTime];
    if (_isHidden) then {
        [_key] call FUNC(uncleanCell);
    };
} forEach _visibleCells;
