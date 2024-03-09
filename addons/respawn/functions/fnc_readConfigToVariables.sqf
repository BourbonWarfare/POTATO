/*
 * Author: AACO
 * Reads the respawn configurations and loads them into cache variables.
 * Should only be called once on server init/admin UI load
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_readConfigToVariables;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// parse faction info
GVAR(factionsToInfo) = [] call CBA_fnc_createNamespace;
{
    private _infoArray = [];

    _infoArray pushBack ([_x >> "displayName"] call CFUNC(getText));
    _infoArray pushBack ([_x >> "callsignPrefix"] call CFUNC(getText));
    _infoArray pushBack ([_x >> "factionClassname"] call CFUNC(getText));
    _infoArray pushBack ([_x >> "factionPrefix"] call CFUNC(getText));
    _infoArray pushBack ([_x >> "groups"] call CFUNC(getArray));

    TRACE_2("Faction info",configName _x,_infoArray);
    GVAR(factionsToInfo) setVariable [configName _x, _infoArray]; // possible to override mission side
} forEach (
    ("true" configClasses (configFile >> "CfgRespawnFactions")) +
    ("true" configClasses (missionConfigFile >> "CfgRespawnFactions"))
);

// parse group info
GVAR(groupsToInfo) = [] call CBA_fnc_createNamespace;
{
    private _infoArray = [];

    _infoArray pushBack ([_x >> "displayName"] call CFUNC(getText));

    // parse the units in the group
    private _unitsArray = [];
    {
        private _unitArray = [];

        // add top level info
        _unitArray pushBack (configName _x);
        _unitArray pushBack ([_x >> "displayName", "Rifleman"] call CFUNC(getText));
        _unitArray pushBack ([_x >> "type", "rifleman"] call CFUNC(getText));
        _unitArray pushBack ([_x >> "rank", "private"] call CFUNC(getText));
        _unitArray pushBack ([_x >> "colorTeam"] call CFUNC(getNumber));
        _unitArray pushBack ([_x >> "leader"] call CFUNC(getBool));

        // pull marker info
        _unitArray pushBack ([_x >> "markerText"] call CFUNC(getText));
        _unitArray pushBack ([_x >> "markerColor", [0,0,0,0]] call CFUNC(getArray));
        _unitArray pushBack ([_x >> "markerTexture"] call CFUNC(getText));
        _unitArray pushBack ([_x >> "markerSize", 16] call CFUNC(getNumber));

        _unitsArray pushBack _unitArray;
    } forEach ("true" configClasses (_x >> "Units"));
    _infoArray pushBack _unitsArray;


    // parse the group configurations
    private _configsArray = [];
    {
        private _config = _x;
        private _configArray = [];

        // add config name
        _configArray pushBack (configName _config);

        // add display name
        _configArray pushBack ([_x >> "displayName"] call CFUNC(getText));

        // pull marker info
        _configArray pushBack ([_x >> "markerPrefix"] call CFUNC(getText));
        _configArray pushBack ([_x >> "markerText"] call CFUNC(getText));
        _configArray pushBack ([_x >> "markerColor", [0,0,0,0]] call CFUNC(getArray));
        _configArray pushBack ([_x >> "markerTexture"] call CFUNC(getText));
        _configArray pushBack ([_x >> "markerSize", 24] call CFUNC(getNumber));

        // pull radio info
        _configArray pushBack ([_x >> "srChannel"] call CFUNC(getNumber));
        _configArray pushBack ([_x >> "mrChannel"] call CFUNC(getNumber));
        _configArray pushBack ([_x >> "lrChannel"] call CFUNC(getNumber));

        // pull color team info
        private _colorTeamArray = ["MAIN"];
        {
            _colorTeamArray pushBack ([_config >> (format ["colorTeam%1", _x]), "MAIN"] call CFUNC(getText));
        } forEach [1, 2, 3, 4];
        _configArray pushBack _colorTeamArray;

        _configsArray pushBack _configArray;
    } forEach ("true" configClasses (_x >> "Configurations"));
    _infoArray pushBack _configsArray;


    TRACE_2("Group info",configName _x,_infoArray);
    GVAR(groupsToInfo) setVariable [configName _x, _infoArray]; // possible to override mission side
} forEach (
    ("isClass (_x >> 'Units') && isClass (_x >> 'Configurations')" configClasses (configFile >> "CfgRespawnGroups")) +
    ("isClass (_x >> 'Units') && isClass (_x >> 'Configurations')" configClasses (missionConfigFile >> "CfgRespawnGroups"))
);
