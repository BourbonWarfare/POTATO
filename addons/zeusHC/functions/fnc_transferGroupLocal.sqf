#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_group"];

private _groupLeader = leader _group;

// if the group leader is human exit
if (isPlayer _groupLeader) exitWith { TRACE_1("Ignoring group, due to human leader", _group); };

/* probably not needed, leave in comments just in case
private _objectsToSync = [[], []];
{
    private _syncedObjects = synchronizedObjects _x;
    if !(_syncedObjects isEqualTo []) then {
        (_objectsToSync select 0) pushBack _x;
        (_objectsToSync select 1) pushBack _syncedObjects;
    }
    nil
} count (units _group);
*/

// create new group on HC with the old group's side
private _newGroup = createGroup (side _group);
[units _group] joinSilent _newGroup;
_newGroup selectLeader _groupLeader;
_newGroup copyWaypoints _group;
deleteGroup _group;
