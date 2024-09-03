diag_log text format ["------- Voices -----"];
ignore = ["default", "usmc", "vr_f", "head_"];
x = "getNumber (_x >> 'scope') == 2" configClasses (configFile >> "CfgVoice");
z = [];
{
    z append getArray (_x >> "identityTypes")
} forEach x;
z = z arrayIntersect z;
z = z select {private _name = _x; (ignore findIf {_x in toLower _name}) == -1 };
{
    key = _x;
    match = [];
    {
        if (((getArray (_x >> "identityTypes")) findIf {_x == key}) != -1) then { 
            match pushBack configName _x
        };
    } forEach x;

    if (match isEqualTo []) then {continue};

    private _first = configFile >> "CfgVoice" >> (match # 0);

    diag_log text format ["class %1 {", key];
    diag_log text format ["  name = ""%1"";", getText (_first >> "displayName")];
    diag_log text format ["  value = ""%1"";", key];
    diag_log text format ["  picture = ""%1"";", getText (_first >> "icon")];
    matchStr = str match;
    matchStr = matchStr select [1, (count matchStr) - 2];
    diag_log text format ["  data[] = {%1};", matchStr];
    diag_log text format ["};"];
} forEach z;
diag_log text format ["------------"];


diag_log text format ["------- Faces -----"];
ignore = ["_sick"];
x = "true" configClasses (configFile >> "CfgFaces" >> "Man_A3");
z = [];
{
    z append getArray (_x >> "identityTypes")
} forEach x;
z = z arrayIntersect z;
z = z select {private _name = _x; (ignore findIf {_x in toLower _name}) == -1 };
{
    key = _x;
    match = [];
    {
        if (((getArray (_x >> "identityTypes")) findIf {_x == key}) != -1) then { 
            match pushBack configName _x
        };
    } forEach x;

    if ((count match) < 3) then {continue};

    private _first = configFile >> "CfgFaces" >> "Man_A3" >> (match # 0);

    diag_log text format ["class %1 { // %2", key, match];
    diag_log text format ["  name = ""%1"";", getText (_first >> "displayName")];
    diag_log text format ["  value = ""%1"";", key];
    matchStr = str match;
    matchStr = matchStr select [1, (count matchStr) - 2];
    diag_log text format ["  data[] = {%1};", matchStr];
    diag_log text format ["};"];
} forEach z;
diag_log text format ["------------"];
