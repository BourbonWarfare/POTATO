#include "script_component.hpp"

if ((!hasInterface) || {isNull player}) exitWith {};

params ["_profileName", "_diaryEntry"];

if (!(player diarySubjectExists "POTATO")) then {
    player createDiarySubject ["POTATO", "POTATO"];
};
player createDiaryRecord ["POTATO", [format ["Mod Check: %1", _profileName], _diaryEntry]];
