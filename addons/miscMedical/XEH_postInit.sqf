#define DEBUG_MODE_FULL
#include "script_component.hpp"
LOG("Post init start");


if (isServer) then {
    [QGVAR(sLog), {
        params ["_type", "_msg"];
        INFO_2("SLOG - %1: %2",_type,_msg);
    }] call CBA_fnc_addEventHandler;

    #include "serverOnlyFix.sqf"

    // Determine if TVT or COOP
    [{
        private _sideCounts = [west, east, resistance] apply {
            private _side = _x;
            {((side _x) == _side) && {isPlayer _x}} count allUnits;
        };
        private _sortedCounts = +_sideCounts;
        _sortedCounts sort false;
        private _isTVT = (_sortedCounts select 1) > 8;
        TRACE_2("",_isTVT,_sideCounts);
        missionNamespace setVariable [QGVAR(isTVT), _isTVT, true];
        // can override with global exec: potato_miscMedical_isTVT = false;
    }, [], 1] call CBA_fnc_waitAndExecute;
};



// Add ability to examine unconcscious and determine cause of not waking up (should be temporary?)
DFUNC(vitalsStableExamine) = {
    params ["_unit", "_return"];

    private _status = call {
        // based on ace_medical_status_fnc_hasStableVitals
        if (_unit getVariable ["ace_medical_inCardiacArrest", false]) exitWith { "Unstable: Cardiac Arrest" };
        if ((_unit getVariable ["ace_medical_bloodVolume", 6.0 ]) < 5.100 ) exitWith { "Unstable: Low Blood Volume" };

        private _cardiacOutput = [_unit] call ace_medical_status_fnc_getCardiacOutput;
        private _bloodLoss = ([_unit] call ace_medical_status_fnc_getBloodLoss);
        if (_bloodLoss > (0.5  * _cardiacOutput) / 2) exitWith { "Unstable: Bleeding" };

        private _bloodPressure = ([_unit] call ace_medical_status_fnc_getBloodPressure);
        _bloodPressure params ["_bloodPressureL", "_bloodPressureH"];
        if (_bloodPressureL < 50 || {_bloodPressureH < 60}) exitWith { "Unstable: Blood Pressure" };

        private _heartRate = (_unit getVariable ["ace_medical_heartRate", 80]);
        if (_heartRate < 40) exitWith { "Unstable: Heart Rate" };
        "Stable: Should eventually wakeup"
    };

    TRACE_3("vitalsStableExamine",_unit,_return,_status);
    private _name = if (isPlayer _unit) then { name _unit } else { "AI" };
    [QGVAR(sLog), ["_checkUnconc", format ["%1 [VitalsStableExamine: %2] [Checker: %3]", _name, _status, name _return]]] call CBA_fnc_serverEvent;
    ["ace_common_displayTextStructured", [_status, 2, _return], [_return]] call CBA_fnc_targetEvent;
};
DFUNC(checkUnconcStatement) = {
    params ["_target", "_player"];
    TRACE_2("checkUnconcStatement",_target,_player);
    [QGVAR(vitalsStableExamine), [_target, _player], [_target]] call CBA_fnc_targetEvent;
};
DFUNC(checkUnconcCondition) = {
    params ["_target", "_player"];
    (alive _target) && {_target getVariable ["ace_isUnconscious", false]}
};

[QGVAR(vitalsStableExamine), {call FUNC(vitalsStableExamine)}] call CBA_fnc_addEventHandler;
if (hasInterface) then {
    private _action = [QGVAR(checkUncon), "Check why unconcscious","\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa",{call FUNC(checkUnconcStatement)},{call FUNC(checkUnconcCondition)}] call ace_interact_menu_fnc_createAction;
    ["CaManBase", 0, ["ACE_Head"], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

// overpressure from explosions
// helper functions. all from https://www.researchgate.net/publication/309610420_Review_of_Analytical_and_Empirical_Estimations_for_Incident_Blast_Pressure
FUNC(calculateTNTEquivalent) = {
    params ["_explosiveMass", "_type"];
    // _explosiveMass = kg
    
    // Q = kJ/kg
    // Qk / Qtnt
    private _tntEquivalents = [
        "comp-b", 1.148,
        "rdx", 1.185,
        "hmx", 1.256,
        "nitro", 1.481,
        "tnt", 1,
        "blasting-gelatin", 1,
        "dynamite", 0.6,
        "semtex", 1.250,
        "h-6", 1.35,
        "tritonal", 1.07,
        "comp-a3", 1.07,
        "comp-c4", 1.30,
        "explosive-d", 0.92,
        "hbx-1", 1.17,
        "hbx-3", 1.14,
        "minol2", 1.20,
        "anfo", 0.83
    ];
    
    private _equivalent = _tntEquivalents select ((_tntEquivalents find _type) + 1);
    _explosiveMass * _equivalent
};

/*
    Coefficient Table:
        Steel: 1
        Reinforced Concrete: 0.95
        Concrete, rock: 0.85
        Compact sandy clay, clay: 0.7
        Medium compact soil: 0.6
        Water: 0.55
*/

#define GROUND_MATERIAL_STEEL 1
#define GROUND_MATERIAL_REINFORCED_CONCRETE 0.95
#define GROUND_MATERIAL_ROCK 0.85
#define GROUND_MATERIAL_CLAY 0.7
#define GROUND_MATERIAL_COMPACT_SOIL 0.6
#define GROUND_MATERIAL_WATER 0.55
#define GROUND_MATERIAL_SAND 0.55
#define GROUND_MATERIAL_MUD 0.55
#define GROUND_MATERIAL_DEFAULT 0.6

GVAR(baseMaterialTable) = createHashMapFromArray [
    ["GRASSSOUTH",                  GROUND_MATERIAL_COMPACT_SOIL],
    ["GRASSGENERAL",                GROUND_MATERIAL_COMPACT_SOIL],
    ["SANDGENERAL",                 GROUND_MATERIAL_CLAY],
    ["UTGRASS",                     GROUND_MATERIAL_COMPACT_SOIL],
    ["UTCONCRETE",                  GROUND_MATERIAL_ROCK],
    ["Default",                     GROUND_MATERIAL_DEFAULT],
    ["Water",                       GROUND_MATERIAL_WATER],
    ["SurfRoadDirt",                GROUND_MATERIAL_COMPACT_SOIL],
    ["SurfRoadConcrete",            GROUND_MATERIAL_ROCK],
    ["SurfRoadTarmac",              GROUND_MATERIAL_ROCK],
    ["SurfWood",                    GROUND_MATERIAL_DEFAULT],
    ["SurfMetal",                   GROUND_MATERIAL_STEEL],
    ["SurfRoofTin",                 GROUND_MATERIAL_STEEL],
    ["SurfRoofTiles",               GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["SurfIntWood",                 GROUND_MATERIAL_DEFAULT],
    ["SurfIntConcrete",             GROUND_MATERIAL_ROCK],
    ["SurfIntTiles",                GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["SurfIntMetal",                GROUND_MATERIAL_STEEL],
    ["SurfWater",                   GROUND_MATERIAL_WATER],
    ["TEST_SurfNormal",             GROUND_MATERIAL_DEFAULT],
    ["GdtStratisConcrete",          GROUND_MATERIAL_ROCK],
    ["GdtStratisBeach",             GROUND_MATERIAL_COMPACT_SAND],
    ["GdtStratisDirt",              GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtStratisSeabedCluttered",   GROUND_MATERIAL_COMPACT_WATER],
    ["GdtStratisSeabed",            GROUND_MATERIAL_COMPACT_WATER],
    ["GdtStratisDryGrass",          GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtStratisGreenGrass",        GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtStratisRocky",             GROUND_MATERIAL_ROCK],
    ["GdtStratisThistles",          GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtStratisForestPine",        GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtRubble",                   GROUND_MATERIAL_DEFAULT],
    ["GdtForestPine",               GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtConcrete",                 GROUND_MATERIAL_ROCK],
    ["GdtSoil",                     GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtBeach",                    GROUND_MATERIAL_COMPACT_SAND],
    ["GdtRock",                     GROUND_MATERIAL_ROCK],
    ["GdtDead",                     GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtDirt",                     GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtDesert",                   GROUND_MATERIAL_COMPACT_SAND],
    ["GdtGrassGreen",               GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtGrassDry",                 GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtGrassWild",                GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtWeed",                     GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtWildField",                GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtThorn",                    GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtStony",                    GROUND_MATERIAL_ROCK],
    ["GdtStonyThistle",             GROUND_MATERIAL_ROCK],
    ["GdtMud",                      GROUND_MATERIAL_COMPACT_MUD],
    ["GdtMarsh",                    GROUND_MATERIAL_COMPACT_MUD],
    ["GdtSeabed",                   GROUND_MATERIAL_COMPACT_WATER],
    ["concrete",                    GROUND_MATERIAL_ROCK],
    ["concrete_out",                GROUND_MATERIAL_ROCK],
    ["concrete_inside",             GROUND_MATERIAL_ROCK],
    ["dirtrunway",                  GROUND_MATERIAL_COMPACT_SOIL],
    ["road",                        GROUND_MATERIAL_ROCK],
    ["floor",                       GROUND_MATERIAL_DEFAULT],
    ["floor_inside",                GROUND_MATERIAL_DEFAULT],
    ["carpet_inside",               GROUND_MATERIAL_DEFAULT],
    ["carpet",                      GROUND_MATERIAL_COMPACT_SOIL],
    ["mud",                         GROUND_MATERIAL_COMPACT_MUD],
    ["concrete_hall",               GROUND_MATERIAL_ROCK],
    ["stones",                      GROUND_MATERIAL_ROCK],
    ["cardboard",                   GROUND_MATERIAL_DEFAULT],
    ["lino",                        GROUND_MATERIAL_DEFAULT],
    ["steel",                       GROUND_MATERIAL_STEEL],
    ["trash",                       GROUND_MATERIAL_DEFAULT],
    ["parquet",                     GROUND_MATERIAL_DEFAULT],
    ["sand",                        GROUND_MATERIAL_COMPACT_SAND],
    ["metalPlate",                  GROUND_MATERIAL_STEEL],
    ["woodenFloor",                 GROUND_MATERIAL_DEFAULT],
    ["planks",                      GROUND_MATERIAL_DEFAULT],
    ["planks_inside",               GROUND_MATERIAL_DEFAULT],
    ["grid",                        GROUND_MATERIAL_DEFAULT],
    ["rubble",                      GROUND_MATERIAL_DEFAULT],
    ["BuildingRubble",              GROUND_MATERIAL_DEFAULT],
    ["tiling",                      GROUND_MATERIAL_DEFAULT],
    ["wavyMetal",                   GROUND_MATERIAL_STEEL],
    ["GdtVRsurface01",              GROUND_MATERIAL_DEFAULT],
    ["surf_metal",                  GROUND_MATERIAL_STEEL],
    ["surf_roadconcrete",           GROUND_MATERIAL_ROCK],
    ["surf_roaddirt",               GROUND_MATERIAL_CLAY],
    ["surf_roadtarmac",             GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["surf_rooftiles",              GROUND_MATERIAL_CLAY],
    ["surf_rooftin",                GROUND_MATERIAL_STEEL],
    ["surf_wood",                   GROUND_MATERIAL_DEFAULT],
    ["surfint_concrete",            GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["surfint_metal",               GROUND_MATERIAL_STEEL],
    ["surfint_tiles",               GROUND_MATERIAL_STEEL],
    ["surfint_wood",                GROUND_MATERIAL_DEFAULT],
    ["road_exp",                    GROUND_MATERIAL_ROCK],
    ["sand_exp",                    GROUND_MATERIAL_SAND],
    ["SurfRoadDirt_exp",            GROUND_MATERIAL_CLAY],
    ["SurfRoadConcrete_exp",        GROUND_MATERIAL_ROCK],
    ["SurfRoadTarmac_exp",          GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["SurfTrailDirt_exp",           GROUND_MATERIAL_COMPACT_SOIL],
    ["concrete_exp",                GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["concrete_in_exp",             GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["concrete_hall_exp",           GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["floor_exp",                   GROUND_MATERIAL_DEFAULT],
    ["floor_in_exp",                GROUND_MATERIAL_DEFAULT],
    ["stones_exp",                  GROUND_MATERIAL_ROCK],
    ["planks_in_exp",               GROUND_MATERIAL_DEFAULT],
    ["planks_exp",                  GROUND_MATERIAL_DEFAULT],
    ["softwood_in_exp",             GROUND_MATERIAL_CLAY],
    ["steel_exp",                   GROUND_MATERIAL_STEEL],
    ["metalPlate_exp",              GROUND_MATERIAL_STEEL],
    ["metalPlatePressed_exp",       GROUND_MATERIAL_STEEL],
    ["metalPlate_in_exp",           GROUND_MATERIAL_STEEL],
    ["grid_exp",                    GROUND_MATERIAL_DEFAULT],
    ["wavyMetal_exp",               GROUND_MATERIAL_STEEL],
    ["carpet_exp",                  GROUND_MATERIAL_DEFAULT],
    ["carpet_in_exp",               GROUND_MATERIAL_DEFAULT],
    ["mat_in_exp",                  GROUND_MATERIAL_DEFAULT],
    ["mud_exp",                     GROUND_MATERIAL_MUD],
    ["straw_exp",                   GROUND_MATERIAL_DEFAULT],
    ["cardboard_exp",               GROUND_MATERIAL_DEFAULT],
    ["lino_in_exp",                 GROUND_MATERIAL_DEFAULT],
    ["lino_exp",                    GROUND_MATERIAL_DEFAULT],
    ["roof_tiles_exp",              GROUND_MATERIAL_ROCK],
    ["trash_exp",                   GROUND_MATERIAL_WATER],
    ["rubble_exp",                  GROUND_MATERIAL_DEFAULT],
    ["BuildingRubble_exp",          GROUND_MATERIAL_ROCK],
    ["GdtForestMalden",             GROUND_MATERIAL_CLAY],
    ["GdtGrassShort",               GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtGrassTall",                GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtGrassLong",                GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtVolcanoBeach",             GROUND_MATERIAL_SAND],
    ["GdtSeabedExp",                GROUND_MATERIAL_WATER],
    ["GdtRedDirt",                  GROUND_MATERIAL_COMPACT_SOIL], 
    ["GdtAsphalt",                  GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["GdtField",                    GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtForest",                   GROUND_MATERIAL_CLAY],
    ["GdtVolcano",                  GROUND_MATERIAL_ROCK],
    ["GdtCliff",                    GROUND_MATERIAL_ROCK],
    ["SurfRoadDirt_Enoch",          GROUND_MATERIAL_CLAY],
    ["SurfRoadTarmac1_Enoch",       GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["SurfRoadTarmac2_Enoch",       GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["SurfRoadTarmac3_Enoch",       GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["SurfTrailDirt_Enoch",         GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtKLDirt",                   GROUND_MATERIAL_CLAY],
    ["GdtKLGrass1",                 GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtKLGrass2",                 GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtKLForestCon",              GROUND_MATERIAL_CLAY],
    ["GdtKLForestDec",              GROUND_MATERIAL_CLAY],
    ["GdtKlSoil",                   GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtKlTarmac",                 GROUND_MATERIAL_REINFORCED_CONCRETE],
    ["GdtKlWeatheredTarmac",        GROUND_MATERIAL_ROCK],
    ["GdtKLCobblestone",            GROUND_MATERIAL_ROCK],
    ["GdtKlField",                  GROUND_MATERIAL_COMPACT_SOIL],
    ["GdtKlStubble",                GROUND_MATERIAL_COMPACT_SOIL]
];

// hemispherical blasts cause more overpressure than air blast. 2*coeff*weight will account for energy
FUNC(calculateHemisphericalBlastWeight) = {
    params ["_originalWeight", "_positionASL"];

    private _positionAboveGround = ASLtoAGL _positionASL;

    private _objectsBelow = lineIntersectsSurfaces [_positionASL, _positionASL vectorAdd [0, 0, -1]];
    if (_objectsBelow isNotEqualTo []) then {
        (_objectsBelow select 0) params ["_surfacePosition"];
        _positionAboveGround = ASLtoAGL _surfacePosition;
    };
    
    // if we are in the air, continue with normal calculations
    if ((_positionAboveGround#2) > 1) exitWith {
        _originalWeight
    };

    private _surfaceAtPosition = surfaceType _positionASL;
    _surfaceAtPosition = [_surfaceAtPosition, "#"] call CBA_fnc_leftTrim;

    private _coefficient = GVAR(baseMaterialTable) getOrDefault [_surfaceAtPosition, GROUND_MATERIAL_DEFAULT];

    TRACE_5("hemisphere check", _positionAboveGround, _objectsBelow, _surfaceAtPosition, _coefficient, _originalWeight * 2 * _coefficient);
    _originalWeight * 2 * _coefficient
};

FUNC(calculateScaledDistance) = {
    params ["_distanceFromEpicenter", "_explosiveMassTNT"];
    _distanceFromEpicenter / (_explosiveMassTNT ^ (1/3));
};

FUNC(calculatePressure) = {
    // pressure in pascals
    params ["_scaledDistance", ["_ambientPressure", 101325]];

    private _alpha = 808 * (1 + (_scaledDistance / 4.5)^2);
    private _beta = sqrt (1 + (_scaledDistance / 0.048)^2);
    private _gamma = sqrt (1 + (_scaledDistance / 0.32)^2);
    private _delta = sqrt (1 + (_scaledDistance / 1.35)^2);
    
    private _finalPressure = _ambientPressure * _alpha / (_beta * _gamma * _delta);
    _finalPressure
};

FUNC(getChanceOfDeath) = {
    // percent chances calculated from https://www.cdc.gov/niosh/docket/archive/pdfs/niosh-125/125-explosionsandrefugechambers.pdf
    params ["_pressure"];
    private _psi = _pressure / 6895;
    linearConversion [35, 65, _psi, 0, 1, true];
};

DFUNC(generateVisuals) = {
    params ["_position", "_explosiveMass", "_filler"];
    
    private _distances = [0.05, 0.2, 0.4, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 3, 5, 10];

    private _tntEquivalent = [_explosiveMass, _filler] call FUNC(calculateTNTEquivalent);

    private _blastData = [];
    {
        private _scaledDistance = [_x, _tntEquivalent] call FUNC(calculateScaledDistance);
        private _pressure = [_scaledDistance] call FUNC(calculatePressure);
        
        private _chanceOfFatality = [_pressure] call FUNC(getChanceOfDeath);

        _blastData pushBack [_x, _pressure, _chanceOfFatality];
    } forEach _distances;

    [{
        _this params ["_args", "_handle"];
        _args params ["_position", "_blastData", "_stopTime"];
        
        if (_stopTime >= 0 && { CBA_missionTime > _stopTime }) exitWith {
            [_handle] call CBA_fnc_removePerFrameHandler;
        };
        
        private _maxIconsPerRing = 6;
        {
            _x params ["_distance", "_pressureAtPosition", "_chanceOfFatality"];
            private _iconCount = _maxIconsPerRing;
            if (_distance == 0) then {
                _iconCount = 1;
            };
            
            _chanceOfFatality = 0 max (_chanceOfFatality min 1);
            
            private _colour = vectorLinearConversion [0, 1, _chanceOfFatality, [1, 1, 1], [1, 0, 0]];
            _colour pushBack 1;
            
            for "_i" from 0 to (_maxIconsPerRing - 1) do {
                private _angle = _i * 2 * pi / _maxIconsPerRing;
                
                private _iconPosition = _position getPos [_distance, deg _angle];
                
                drawIcon3D [
                    "\a3\ui_f\data\IGUI\Cfg\Cursors\explosive_ca.paa",
                    _colour,
                    _iconPosition,
                    0.2, 0.2, 1,
                    format ["Distance: %1m Pressure: %2Pa Fatality Chance: %3 PsI: %4", _distance, _pressureAtPosition, _chanceOfFatality, _pressureAtPosition / 6895]
                ];
            };
        } forEach _blastData;
    }, 0, [_position, _blastData, CBA_missionTime + 10]] call CBA_fnc_addPerFrameHandler
};

if (isServer) then {
    // add explosion event handler
    [QACEGVAR(frag,frag_eh), {
        params ["_lastPos", "", "_explosive"];
        private _explosiveConfig = configFile >> "CfgAmmo" >> _explosive;

        // ACE_frag defines mass as grams, we do as kilograms
        private _mass = (getNumber (_explosiveConfig >> QACEGVAR(frag,charge))) / 1000;
        private _filler = getText (_explosiveConfig >> QGVAR(explosiveFiller));
        if (_filler isEqualTo "") then {
            _filler = "comp-b";
        };

        if (_mass <= 0) then {
            TRACE_3("no mass",_mass,_filler,_explosive);
            _mass = 1;
        };

        _mass = [_mass, _lastPos] call FUNC(calculateHemisphericalBlastWeight);

        private _objects = (ASLtoAGL _lastPos) nearEntities [["CAManBase"], 50];
        {
            [QGVAR(explosion), [_lastPos, _mass, _filler, _x], _x] call CBA_fnc_targetEvent;
        } forEach _objects;

        TRACE_4("explosion server",_explosive,_mass,_filler,count _objects);

        //[_lastPos, _mass, _filler] call DFUNC(generateVisuals);
    }] call CBA_fnc_addEventHandler;
};

if (hasInterface) then {
    [QGVAR(explosion), {
        params ["_origin", "_mass", "_filler", "_unit"];
        // move up with 5 centimeters for gameplay reasons: makes explosions feel better
        _origin = _origin vectorAdd [0, 0, 0.05];
        // if we can see the unit, that means that there is always going to be a pressure wave
        // if there is a pressure wave, use the closest distance regardless of whether or not it can be seen
        private _canSee = false;
        private _distance = 1e10;
        {
            if !(_canSee) then {
                _canSee = ([] isEqualTo lineIntersectsObjs [_origin, _x, objNull, _unit, false, 16 + 32]) && { !terrainIntersectASL [_origin, _x] };
            };
            _distance = (_x vectorDistance _origin) min _distance;
        } forEach [eyePos _unit, getPosASLVisual _unit, aimPos _unit];

        private _tntEquivalent = [_mass, _filler] call FUNC(calculateTNTEquivalent);

        private _scaledDistance = [_distance, _tntEquivalent] call FUNC(calculateScaledDistance);
        private _pressure = [_scaledDistance] call FUNC(calculatePressure);

        private _chanceOfFatality = [_pressure] call FUNC(getChanceOfDeath);
        TRACE_8("explosion client",_unit,_mass,_filler,_distance,_scaledDistance,_pressure,_chanceOfFatality,_canSee);
        if (_canSee && { _chanceOfFatality >= random 1 }) then {
            [_unit, "Overpressure From Explosive"] call ace_medical_status_fnc_setDead; // this should show correct killer instead of "#scripted"
        };

        //[_origin, _mass, _filler] call DFUNC(generateVisuals);
    }] call CBA_fnc_addEventHandler;

    // Increase lethality when taking sustained critical damage to body/head

    // ToDo: Move this to ace_medical_damage_fnc_determineIfFatal
    // FATAL_SUM_DAMAGE_WEIBULL_L / K values
    [{
        TRACE_1("adding woundRecieved handler",GVAR(isTVT));

        ["ace_medical_woundReceived", {
            params ["_unit", "_damagesArray", "_shooter", "_typeOfDamage"]; // ACE 3.14.2 wound params
            (_damagesArray select 0) params ["_damage", "_bodyPart"]; // biggest damage first
            if (_unit == ACE_player) then {
                TRACE_3("player wound",_bodyPart,_damage,_typeOfDamage);
                if ((_unit getVariable ["ACE_isUnconscious", false]) && {_damage > 0.5}) then {
                    private _bps = _unit getVariable ["ace_medical_bodyPartDamage", [0,0,0,0,0,0]];
                    if (((_bps select 0) + (_bps select 1)) > ([1.75, 3] select GVAR(isTVT))) then {
                        TRACE_1("manually killing", _bps);
                        // _unit setDamage 1;
                        [_unit, "Fatal Damage"] call ace_medical_status_fnc_setDead; // this should show correct killer instead of "#scripted"
                    };
                };
            };
        }] call CBA_fnc_addEventHandler;
    }, [], 5] call CBA_fnc_waitAndExecute;

/* // Medical debug
    // debug for uncon:
    ["ace_unconscious", {
        params ["_unit", "_active"];
        if (_unit == ACE_player) then {
            TRACE_2("uncon event",_unit,_active);
            [QGVAR(sLog), ["uncon event", format ["%1 [Unit:%2] [Active:%3]", profileName, _unit, _active]]] call CBA_fnc_serverEvent;
        };
    }] call CBA_fnc_addEventHandler;

    ["ace_medical_wakeUp", {
        params ["_unit"];
        if (_unit == ACE_player) then {
            private _stable = [_unit] call ace_medical_status_fnc_hasStableVitals;
            TRACE_2("wakeUp event",_unit,_stable);
            [QGVAR(sLog), ["wakeUp event", format ["%1 [Unit:%2] [Stable: %3]", profileName, _unit, _stable]]] call CBA_fnc_serverEvent;
            [{
                params ["_unit"];
                private _targetState = [_unit, ACEGVAR(medical,STATE_MACHINE)] call CBA_statemachine_fnc_getCurrentState;
                private _isUncon = _unit getVariable ["ACE_isUnconscious", -1];
                private _anim = animationState _unit;
                private _weap = currentWeapon _unit;
                private _inputD = missionNamespace getVariable ["ace_common_disableInputPFH", nil];
                if (isNil "_inputD") then {_inputD = "nil"};
                TRACE_6("wakeUp check",_unit,_targetState,_isUncon,_anim,_weap,_inputD);
                [QGVAR(sLog), ["wakeUp check", format ["%1 [State:%2] [isUncon:%3] [Anim:%4] [Weap: %5] [InputD: %6]", profileName, _targetState, _isUncon, _anim, _weap, _inputD]]] call CBA_fnc_serverEvent;
            }, [_unit], 5] call CBA_fnc_waitAndExecute;
        };
    }] call CBA_fnc_addEventHandler;


    GVAR(readyToMsg) = true;
    [{
        private _unit = ace_player;
        if (!alive _unit) exitWith {};
        private _state = [_unit, ace_medical_STATE_MACHINE] call CBA_statemachine_fnc_getCurrentState;
        private _stableVitals = [_unit] call ace_medical_status_fnc_hasStableVitals;
        private _isUncon = _unit getVariable ["ACE_isUnconscious", false];
        private _anim = animationState _unit;
        private _inputD = missionNamespace getVariable ["ace_common_disableInputPFH", -1];
        private _lastWakeUpCheck = _unit getVariable ["ace_medical_lastWakeUpCheck", -1];
        if (_lastWakeUpCheck > 0) then { _lastWakeUpCheck = CBA_missionTime - _lastWakeUpCheck };
        private _lastTimeUpdated = _unit getVariable ["ace_medical_vitals_lastTimeUpdated", -1];
        if (_lastTimeUpdated > 0) then { _lastTimeUpdated = CBA_missionTime - _lastTimeUpdated };

        INFO_8("Status %1 [%2][stable %3][isUncon %4][anim %5][input %6][WakUpC %7][TimeU %8]",_unit,_state,_stableVitals,_isUncon,_anim,_inputD,_lastWakeUpCheck,_lastTimeUpdated);

        // if ((random 1) < 0.1) then {
        // [QGVAR(sLog), ["LOG", format ["%1 [%2][stable %3][isUncon %4][anim %5][input %6][WakUpC %7][TimeU %8]", profileName,_state,_stableVitals,_isUncon,_anim,_inputD,_lastWakeUpCheck,_lastTimeUpdated]]] call CBA_fnc_serverEvent;
        // };

        switch (toLower _state) do {
        case ("default");
        case ("injured"): {
                if (_isUncon || {_inputD > -1}) then {
                    [QGVAR(sLog), ["bugged A", format ["%1 [%2][isUncon %3][anim %4][input %5]", profileName, _state,_isUncon,_anim,_inputD]]] call CBA_fnc_serverEvent;
                    if (GVAR(readyToMsg)) then {
                        ["potato_adminMsg", [format ["[AUTO] bugged A"], profileName]] call CBA_fnc_globalEvent;
                        GVAR(readyToMsg) = false;
                    };
                };
            };
        case ("unconscious"): {
                if ((!_isUncon) || {_inputD == -1}) then {
                    [QGVAR(sLog), ["bugged B", format ["%1 [%2][isUncon %3][anim %4][input %5]", profileName, _state,_isUncon,_anim,_inputD]]] call CBA_fnc_serverEvent;
                    if (GVAR(readyToMsg)) then {
                        ["potato_adminMsg", [format ["[AUTO] bugged B"], profileName]] call CBA_fnc_globalEvent;
                        GVAR(readyToMsg) = false;
                    };
                };
            };
            default { INFO_1("State: %1",_state); };
        };
    }, 30, []] call CBA_fnc_addPerFrameHandler;
     */
};
