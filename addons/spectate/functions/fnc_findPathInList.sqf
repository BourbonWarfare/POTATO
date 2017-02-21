/*
 * Author: AACO
 * Function used to find a tree path of a unit
 *
 * Arguments:
 * 0: data value to lookup <STRING>
 * 1: IDC of the control to look through <NUMBER>
 *
 * Return Value:
 * Path of unit <ARRAY>
 *
 * Examples:
 * ["playerName", 6547] call potato_spectate_fnc_findPathInList;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

scopeName QGVAR(findPathInList);

params [["_data", "", [""]], "_listIdc"];

// Make sure data is not empty
if (_data != "") then {
    for "_sideIndex" from 0 to ((tvCount [_listIdc, []]) - 1) do {
        if (tvData [_listIdc, [_sideIndex]] == _data) then {
            [_sideIndex] breakOut QGVAR(findPathInList);
        };
        for "_groupIndex" from 0 to ((tvCount [_listIdc, [_sideIndex]]) - 1) do {
            if (tvData [_listIdc, [_sideIndex, _groupIndex]] == _data) then {
                [_sideIndex, _groupIndex] breakOut QGVAR(findPathInList);
            };
            for "_unitIndex" from 0 to ((tvCount [_listIdc, [_sideIndex, _groupIndex]]) - 1) do {
                if (tvData [_listIdc, [_sideIndex, _groupIndex, _unitIndex]] == _data) then {
                    [_sideIndex, _groupIndex, _unitIndex] breakOut QGVAR(findPathInList);
                };
            };
        };
    };
};

[-1] // return empty path if not found (worst case)
