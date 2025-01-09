#include "..\script_component.hpp"

if !(hasInterface) exitWith {};
// Modified from ace_grenades_fnc_addChangeFuseItemContextMenuOptions by Cyruz
{
    _x params ["_concusion", "_frag"];
    [
        _concusion, "CONTAINER", "Attach frag jacket", [],
        "\a3\ui_f\data\igui\cfg\simpletasks\types\destroy_ca.paa",
        [{true}, {
            params ["", "", "_item", "", "_grenadeType"];
            _item == _grenadeType#0
        }], {
            params ["_unit", "", "", "_slot", "_grenadeType"];

            private _container = switch (_slot) do {
                case "UNIFORM_CONTAINER": {"uniform"};
                case "VEST_CONTAINER": {"vest"};
                case "BACKPACK_CONTAINER": {"backpack"};
                default {""};
            };

            if (_container != "") then {
                [_unit, _grenadeType#1, _container] call ACEFUNC(common,addToInventory);
            };

            false
        }, true, [_concusion, _frag]
    ] call CBA_fnc_addItemContextMenuOption;

    [
        _frag, "CONTAINER", "Remove frag jacket", [],
        "\a3\ui_f\data\igui\cfg\simpletasks\types\destroy_ca.paa",
        [{true}, {
            params ["", "", "_item", "", "_grenadeType"];
            _item == _grenadeType#1
        }],
        {
            params ["_unit", "", "", "_slot", "_grenadeType"];

            private _container = switch (_slot) do {
                case "UNIFORM_CONTAINER": {"uniform"};
                case "VEST_CONTAINER": {"vest"};
                case "BACKPACK_CONTAINER": {"backpack"};
                default {""};
            };

            if (_container != "") then {
                [_unit, _grenadeType#0, _container] call ACEFUNC(common,addToInventory);
            };

            false
        }, true, [_concusion, _frag]
    ] call CBA_fnc_addItemContextMenuOption;
} forEach [
    ["gm_handgrenade_conc_dm51a1", "gm_handgrenade_frag_dm51a1"],
    ["gm_handgrenade_conc_dm51", "gm_handgrenade_frag_dm51"],
    ["gm_handgrenade_pracconc_dm58", "gm_handgrenade_pracfrag_dm58"]
];
