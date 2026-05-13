// Based on "A3\3den\UI\attributes\AmmoBox.sqf"
// Gathers current box info and exports it to text
private _attributeInvent = uinamespace getvariable ["RscAttributeInventory_cargo", [[],[]]];
private _itemHash = (_attributeInvent#0) createHashMapFromArray (_attributeInvent#1);
private _weapons = [];
private _magazines = [];
private _items = [];
private _backpacks = [];
private _cfgWeps = configfile >> "CfgWeapons";
private _cfgMags = configFile >> "CfgMagazines";
private _cfgVics = configFile >> "CfgVehicles";
private _cfgGlass = configFile >> "CfgGlasses";
{
    if (_y <= 0) then {continue};
    private _class = _x;
    private _format = if (_y > 1) then {
        format ["%1:%2",_x,_y];
    } else {
        _x
    };
    switch (true) do {
        case (getnumber (_cfgWeps >> _class >> "type") in [4096, 131072]): {
            _items pushback _format;
        };
        case (isclass (_cfgWeps >> _class)): {
            _weapons pushback _format;
        };
        case (isclass (_cfgMags >> _class)): {
            _magazines pushback _format;
        };
        case (isclass (_cfgVics >> _class)): {
            _backpacks pushback _format;
        };
        case (isclass (_cfgGlass >> _class)): {
            _items pushback _format;
        };
        default {-1};
    };
} forEach _itemHash;


// Create the output text lines
private _lines = [
    "class <boxClassname> {",
    "  boxCustomName = ""Resupply Box"";"
];
if (_weapons isNotEqualTo []) then {
    _lines pushBack "  class TransportWeapons[] = {";
    {
        _lines pushBack format ["    %1,", str _x];
    } forEach _weapons;
    _lines pushBack "  };";
};
if (_magazines isNotEqualTo []) then {
    _lines pushBack "  class TransportMagazines[] = {";
    {
        _lines pushBack format ["    %1,", str _x];
    } forEach _magazines;
    _lines pushBack "  };";
};
if (_items isNotEqualTo []) then {
    _lines pushBack "  class TransportItems[] = {";
    {
        _lines pushBack format ["    %1,", str _x];
    } forEach _items;
    _lines pushBack "  };";
};
if (_backpacks isNotEqualTo []) then {
    _lines pushBack "  class TransportBackpacks[] = {";
    {
        _lines pushBack format ["    %1,", str _x];
    } forEach _backpacks;
    _lines pushBack "  };";
};
_lines pushBack "};";
// Use ace extensions to put it in the clipboard
{
    "ace" callExtension ["clipboard:append", [_x + endl]];
} forEach _lines;
"ace" callExtension ["clipboard:complete", []];
