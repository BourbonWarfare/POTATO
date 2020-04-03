#include "script_component.hpp"

// PabstMirror - Show reminder when non-crew enters vehicles seats that they might not be trained on
LOG("Adding Crew Training Setting");

[
    QGVAR(crewTraining),
    "CHECKBOX",
    ["Show Crew Training Reminder", "Show reminder about crew training when entering a complex vehicle weapon"],
    ["POTATO UI", "miscFixes"],
    true, // default value
    true, // isGlobal
    {
        params ["_enabled"];
        TRACE_1("crewTraining setting updated",_enabled);

        private _peID = missionNamespace getVariable [QGVAR(crewTraining_peID), -1];
        if (_peID > -1) then { ["turret", _peID] call CBA_fnc_removePlayerEventHandler; };

        if (!_enabled) exitWith {};

        GVAR(crewTraining_peID) = ["turret", {
            params ["_unit", "_turret"];
            TRACE_2("turret EH",_unit,_turret);

            if ((!alive _unit) || {_turret isEqualTo []}) exitWith { TRACE_1("dead or dismounted/cargo seat",_turret); };

            private _unitType = toLower typeOf _unit;
            if ((["pilot", "crew", "msv_cc", "msv_vic"] findIf {_x in _unitType}) > -1) exitWith { TRACE_1("trained",_unitType); };

            private _vehicle = vehicle _unit;
            TRACE_2("non-crew and inside",_vehicle,typeOf _vehicle);
            private _msg = "";

            if (_turret isEqualTo [-1]) then {
                TRACE_1("pilot",_vehicle);
                switch (true) do {
                    case (_vehicle isKindOf "Air"): { _msg = "Are you trained on piloting this aircraft?" };
                    case (_vehicle isKindOf "Tank"): { _msg = "Are you trained on driving this tracked vehicle?" };
                };
            } else {
                private _mags = _vehicle magazinesTurret _turret;
                TRACE_1("gunner",_mags);
                {
                    private _ammoHit = getNumber (configFile >> "CfgAmmo" >> (getText (configFile >> "CfgMagazines" >> _x >> "ammo")) >> "hit");
                    if (_ammoHit > 150) exitWith { // ref vanilla 40mm gmg is 100 hit
                        TRACE_2("big iron",_x,_ammoHit);
                        private _magName = getText (configFile >> "CfgMagazines" >> _x >> "displayName");
                        _msg = format ["Are you trained on this weapon system? [%1]", _magName];
                     }
                } forEach (_mags arrayIntersect _mags);
            };

            if (_msg != "") then { // need delay or msg doesn't show (vehicle switch hasn't fully happened yet)
                [{(_this select 0) vehicleChat (_this select 1);}, [_vehicle, _msg], 1] call CBA_fnc_waitAndExecute;
            };
        }] call CBA_fnc_addPlayerEventHandler;
    }
] call CBA_settings_fnc_init;
