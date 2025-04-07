#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Very basic orbat for leadership (what is char limit?)
 *
 * Arguments:
 * None
 *
 * Returns: ORBAT <STRING>
 *
 * Public: No
 */

private _groups = allGroups select {
    isPlayer leader _x
} apply {
    [str side _x, -rankId leader _x, groupId _x, _x]
};
_groups sort true;
_groups = _groups apply {
    _x params ["", "", "_groupID", "_group"];
    format ["%1: %2 (%3)", _groupID, name leader _group, count units _group]
};
_groups joinString endl;
