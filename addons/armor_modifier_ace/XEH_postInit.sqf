#include "script_component.hpp"

// Call in post init, so that we are sure to overwrite default ACE damage handling and any other mods interfering with ACE medical
["CAManBase", "initPost", {
    params ["_unit"];

    private _ehID = _unit getVariable [QACEGVAR(medical,HandleDamageEHID), -1];

    // If no EH exists, don't add one
    if (_ehID == -1) exitWith {};

    // Replace existing ace medical damage event handler
    _unit removeEventHandler ["HandleDamage", _ehID];

    _ehID = _unit addEventHandler ["HandleDamage", {[_this] call FUNC(handleDamage)}];

    _unit setVariable [QACEGVAR(medical,HandleDamageEHID), _ehID];
}, true, [], true] call CBA_fnc_addClassEventHandler;

[QGVAR(updateUnitArmor), {
    params ["_unit", "_hitPoint", "_armorArray"];
    if (!alive _unit) exitWith {};
    private _newHash = +(_unit getVariable [QGVAR(armorHash), GVAR(defaultArmorHash)]);
    {_newHash set [_x, _armorArray]} forEach (_hitPoint call FUNC(resolveHitPoints));
    _unit setVariable [QGVAR(armorHash), _newHash];
}] call CBA_fnc_addEventHandler;

[QGVAR(updateClassArmor), {
    params ["_class", "_hitPoint", "_armorArray"];
    private _classHashMap = GVAR(classArmorHash) getOrDefaultCall [_class, {
        [_class, "init", {
            params ["_unit"];
            _unit setVariable [QGVAR(armorHash), GVAR(classArmorHash) getOrDefault [(typeOf _unit), DEFAULT_HASH_SETTINGS]];
        }, false] call CBA_fnc_addClassEventHandler;
        +GVAR(defaultArmorHash)
    }, true];
    {_classHashMap set [_x, _armorArray]} forEach (_hitPoint call FUNC(resolveHitPoints));
}] call CBA_fnc_addEventHandler;
