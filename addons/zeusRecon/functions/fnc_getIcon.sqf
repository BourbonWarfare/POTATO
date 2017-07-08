#include "script_component.hpp"

params ["_type"];

if (_type isEqualType objNull) then {
    switch (true) do {
    case (_type isKindOf "Wheeled_APC"): {"\A3\ui_f\data\map\markers\nato\o_mech_inf.paa"};
    case (_type isKindOf "Car"): {"\A3\ui_f\data\map\markers\nato\o_motor_inf.paa"};
    case (_type isKindOf "Tank"): {"\A3\ui_f\data\map\markers\nato\o_armor.paa"};
    case (_type isKindOf "Plane"): {"\A3\ui_f\data\map\markers\nato\o_plane.paa"};
    case (_type isKindOf "Air"): {"\A3\ui_f\data\map\markers\nato\o_air.paa"};
        default {"\A3\ui_f\data\map\markers\nato\o_unknown.paa"};
    };
} else {
    switch (true) do {
    case (_type <= 2): {"\A3\ui_f\data\map\markers\nato\group_0.paa"}; // 1-2 Very Small fireteam
    case (_type <= 5): {"\A3\ui_f\data\map\markers\nato\group_1.paa"}; // 3-5 Fireteam
    case (_type <= 9): {"\A3\ui_f\data\map\markers\nato\group_2.paa"}; // 6-9 Squad
        default {"\A3\ui_f\data\map\markers\nato\group_3.paa"}; // 10+ Large Squad
    };
};
