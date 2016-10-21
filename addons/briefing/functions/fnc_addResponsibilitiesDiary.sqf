/*
 * Author: AACO
 * Function used to add responsibilities notes to a player's diary
 *
 * Arguments:
 * 0: Unit to add to the notes to <OBJECT>
 * 1: If the unit is a medic or not <BOOL>
 *
 * Examples:
 * [player, true] call potato_briefing_fnc_addResponsibilitiesDiary;
 *
 * Public: Yes
 */

#include "script_component.hpp"

params ["_newPlayer", "_isMedic"];
TRACE_1("params",_this);

private _responsibilitiesDiaryBuilder = [];

if (_isMedic) {
    _responsibilitiesDiaryBuilder pushBack "Role: Medic";
    _responsibilitiesDiaryBuilder pushBack "";
    _responsibilitiesDiaryBuilder pushBack "Responsibilities:";
    _responsibilitiesDiaryBuilder pushBack "  • Ensure the area is secure before treating patients";
    _responsibilitiesDiaryBuilder pushBack "  • Stablize injured teammates, triage if necessary";
    _responsibilitiesDiaryBuilder pushBack "  • Responsibly utilize drugs and fluids to regulate:";
    _responsibilitiesDiaryBuilder pushBack "      Pain";
    _responsibilitiesDiaryBuilder pushBack "      Heart rate";
    _responsibilitiesDiaryBuilder pushBack "      Blood pressure";
    _responsibilitiesDiaryBuilder pushBack "  • Utilize smoke grenades to cover teammates and mark friendly positions";
} else {
    _responsibilitiesDiaryBuilder pushBack "Role: Non-Medical Combatant";
    _responsibilitiesDiaryBuilder pushBack "";
    _responsibilitiesDiaryBuilder pushBack "Responsibilities:";
    _responsibilitiesDiaryBuilder pushBack "  • Secure area for the treatment of casualties";
    _responsibilitiesDiaryBuilder pushBack "  • Transport casualty to cover for treatment";
    _responsibilitiesDiaryBuilder pushBack "  • If possible, stop casuaties bleeding otherwise cover the medic while they treat the casualty";
    _responsibilitiesDiaryBuilder pushBack "  • Communicate if additional supplies are needed";
};

_newPlayer createDiaryRecord ["medical", ["Responsibilities", _responsibilitiesDiaryBuilder joinString "<br/>"]];
