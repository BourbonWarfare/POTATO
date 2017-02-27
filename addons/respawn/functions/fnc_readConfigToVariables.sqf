/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// parse faction info
GVAR(factionsToInfo) = [] call CBA_fnc_createNamespace;
{
    private _infoArray = [];

    _infoArray pushBack (getText (_x >> "displayName"));
    _infoArray pushBack (getText (_x >> "callsignPrefix"));
    _infoArray pushBack (getText (_x >> "factionClassname"));
    _infoArray pushBack (getText (_x >> "factionPrefix"));
    _infoArray pushBack (getArray (_x >> "groups"));

    TRACE_2("Faction info", configName _x, _infoArray);
    GVAR(factionsToInfo) setVariable [configName _x, _infoArray]; // possible to override mission side
} forEach (
    ("true" configClasses (configFile >> "CfgRespawnFactions")) +
    ("true" configClasses (missionConfigFile >> "CfgRespawnFactions"))
);

// parse group info
GVAR(groupsToInfo) = [] call CBA_fnc_createNamespace;
{
    private _infoArray = [];

    _infoArray pushBack (getText (_x >> "displayName"));

    // parse the units in the group
    private _unitsArray = [];
    {
        private _unitArray = [];

        // add config name
        _unitArray pushBack (configName _x);
        _unitArray pushBack (getText (_x >> "displayName"));
        _unitArray pushBack (getText (_x >> "type"));
        _unitArray pushBack (getText (_x >> "rank"));
        _unitArray pushBack (getNumber (_x >> "colorTeam"));
        _unitArray pushBack ((getNumber (_x >> "leader")) == 1);
        _unitArray pushBack ((getNumber (_x >> "medic")) == 1);

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

        // pull marker info
        _configArray pushBack (getText (_config >> "markerText"));
        _configArray pushBack (getArray (_config >> "markerColor"));
        _configArray pushBack (getText (_config >> "markerTexture"));
        _configArray pushBack (getNumber (_config >> "markerSize"));

        // pull radio info
        _configArray pushBack (getNumber (_config >> "srChannel"));
        _configArray pushBack (getNumber (_config >> "mrChannel"));
        _configArray pushBack (getNumber (_config >> "lrChannel"));

        // pull color team info
        private _colorTeamArray = ["MAIN"];
        {
            private _colorTeamProperty = format ["colorTeam%1", _x];
            if (isText (_config >> _colorTeamProperty)) then {
                _colorTeamArray pushBack (getText (_config >> _colorTeamProperty));
            } else {
                _colorTeamArray pushBack "MAIN";
            };
        } forEach [1, 2, 3, 4];
        _configArray pushBack _colorTeamArray;

        _configsArray pushBack _configArray;
    } forEach ("true" configClasses (_x >> "Configurations"));
    _infoArray pushBack _configsArray;


    TRACE_2("Group info", configName _x, _infoArray);
    GVAR(groupsToInfo) setVariable [configName _x, _infoArray]; // possible to override mission side
} forEach (
    ("isClass (_x >> 'Units') && isClass (_x >> 'Configurations')" configClasses (configFile >> "CfgRespawnGroups")) +
    ("isClass (_x >> 'Units') && isClass (_x >> 'Configurations')" configClasses (missionConfigFile >> "CfgRespawnGroups"))
);
