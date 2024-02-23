#include "script_component.hpp"

params [["_type", "", [""]]];
if (_type == "") exitWith {};

private _input = uinamespace getvariable ["bis_fnc_3DENEntityMenu_data",[]];
private _entity = _input param [1,objnull];

systemChat format ["Change %1 to %2", _entity, _type];

// itemClass: "potato_e_coy"
private _itemClass = (_entity get3DENAttribute "ItemClass") param [0, ""];
// name: "UNIT_OPF_1PLT_CO"
private _name = (_entity get3DENAttribute "name") param [0, ""];
// description: "OpFor 1 Platoon Commander@OpFor 1st Platoon (Alpha, Bravo, Charlie)"
private _description = (_entity get3DENAttribute "description") param [0, ""];

if (isNull _entity || {!(_entity isKindOf "CaManBase")} || {(_itemClass select [0, 6]) != "potato"} || {"@" in _description}) exitWith {
    ERROR_WITH_TITLE("Bad Unit Selected","Not potato unit or leader?");
};

private _newClass = (_itemClass select [0, 9]) + _type;
private _newDescription = _description;
if ("[" in _newDescription) then { _newDescription = _newDescription select [0, _newDescription find "["]; };
private _newDescription = _newDescription + format ["[%1]", _type];

_entity set3DENAttribute ["description", _newDescription];
[_entity] set3DENObjectType _newClass;

systemChat format ["Set %1 - %2", _newClass, _newDescription];
