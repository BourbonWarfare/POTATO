#include "script_component.hpp"

// true
visibleMap
&& {missionNamespace getVariable [QEGVAR(safeStart,safeStartEnabled), true]}
&& {[ACE_player, objNull, ["isNotInside", "notOnMap"]] call ACEFUNC(common,canInteractWith)}
&& {
    private _rank = rankId ACE_player;
    private _units = units side group ACE_player;
    (_units findIf {rankId _x > _rank}) == -1 // no higher rank in group
}
