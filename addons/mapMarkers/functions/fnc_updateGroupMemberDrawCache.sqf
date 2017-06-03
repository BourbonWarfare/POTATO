/*
 * Render element update routine for Group Members.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 */
#include "script_component.hpp"

#define GROUP_MEMBER_MARKER "\A3\ui_f\data\map\markers\military\start_CA.paa"

private _newDrawCache = [];

{
    private _color = switch (assignedTeam _x) do {
        case "RED": {[0.9, 0, 0, 1]};
        case "GREEN": {[0, 0.8, 0, 1]};
        case "BLUE": {[0, 0, 1, 1]};
        case "YELLOW": {[0.9, 0.9, 0, 1]};
        default {[1, 1, 1, 1]};
    };
    _newDrawCache pushBack [getPos _x, GROUP_MEMBER_MARKER, _color, [12, 12], getDir _x, name _x];
    nil
} count (units player);

GVAR(groupMemberDrawCache) = _newDrawCache;
