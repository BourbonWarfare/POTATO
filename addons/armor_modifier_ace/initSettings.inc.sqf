//#pragma hemtt suppress command_case file
#define HITPOINT_SETTINGS_FUNCTION(HITPOINT,SIDE_CMD) {\
    private _newSettings = parseSimpleArray _this;\
    private _parsedSettings = [];\
    \
    {\
        if (_x isEqualType 0) then {\
            _parsedSettings pushBack (_x max (MINIMUM_SETTINGS select _forEachIndex));\
        } else {\
            _parsedSettings pushBack (DEFAULT_SETTINGS select _forEachIndex);\
        };\
    } forEach _newSettings;\
    \
    if (_parsedSettings isNotEqualTo _newSettings) then {\
        [ARR_2("A setting was set too low or otherwise incorrectly, reverting to default setting.",3)] call ace_common_fnc_displayTextStructured;\
    };\
    \
    private _hitPointHashMap = GVAR(armorValueHash) getOrDefault [SIDE_CMD, createHashMap, true];\
    switch (QUOTE(HITPOINT)) do {\
        case QUOTE(torso): {\
            _hitPointHashMap set ["hitabdomen", _parsedSettings];\
            _hitPointHashMap set ["hitdiaphragm", _parsedSettings];\
            _hitPointHashMap set ["hitchest", _parsedSettings];\
        };\
        case QUOTE(arms): {\
            _hitPointHashMap set ["hitleftarm", _parsedSettings];\
            _hitPointHashMap set ["hitrightarm", _parsedSettings];\
        };\
        case QUOTE(legs): {\
            _hitPointHashMap set ["hitleftleg", _parsedSettings];\
            _hitPointHashMap set ["hitrightleg", _parsedSettings];\
        };\
        default {\
            _hitPointHashMap set [FORMAT_1("hit%1",QUOTE(HITPOINT)), _parsedSettings];\
        };\
    };\
}

#define HITPOINT_SETTINGS_SIDE(TYPE,SIDE_CMD,HITPOINT,TEXT,DEFAULT_ARRAY)\
[\
    QGVAR(DOUBLES(TYPE,HITPOINT)),\
    "EDITBOX",\
    [TEXT, "Allows the tuning the effectiveness of groups of armor hitpoints.\n[hitpoint multiplier, minimum armor, maximum armor]\nIf minimum or maximum armor value is below 1, they don't take effect."],\
    [COMPONENT_NAME, FORMAT_1("Armor modifiers - %1",QUOTE(TYPE))],\
    QUOTE(DEFAULT_ARRAY),\
    true,\
    HITPOINT_SETTINGS_FUNCTION(HITPOINT,SIDE_CMD)\
] call CBA_fnc_addSetting

#define HITPOINT_CHECK_SETTING_SIDE(OBJECT,SIDE_CMD) HITPOINT_SETTINGS_SIDE(OBJECT,SIDE_CMD,head,FORMAT_1("%1 hitpoint damage reduction - head",QUOTE(OBJECT)),ARR_3([1,0,0]));\
HITPOINT_SETTINGS_SIDE(OBJECT,SIDE_CMD,face,FORMAT_1("%1 hitpoint damage reduction - face",QUOTE(OBJECT)),ARR_3([1,0,0]));\
HITPOINT_SETTINGS_SIDE(OBJECT,SIDE_CMD,neck,FORMAT_1("%1 hitpoint damage reduction - neck",QUOTE(OBJECT)),ARR_3([1,0,0]));\
HITPOINT_SETTINGS_SIDE(OBJECT,SIDE_CMD,torso,FORMAT_1("%1 hitpoint damage reduction - torso",QUOTE(OBJECT)),ARR_3([1,0,0]));\
HITPOINT_SETTINGS_SIDE(OBJECT,SIDE_CMD,pelvis,FORMAT_1("%1 hitpoint damage reduction - pelvis",QUOTE(OBJECT)),ARR_3([1,0,0]));\
HITPOINT_SETTINGS_SIDE(OBJECT,SIDE_CMD,arms,FORMAT_1("%1 hitpoint damage reduction - arms",QUOTE(OBJECT)),ARR_3([1,0,0]));\
HITPOINT_SETTINGS_SIDE(OBJECT,SIDE_CMD,legs,FORMAT_1("%1 hitpoint damage reduction - legs",QUOTE(OBJECT)),ARR_3([1,0,0]))

HITPOINT_CHECK_SETTING_SIDE(BluFor,blufor);
HITPOINT_CHECK_SETTING_SIDE(OpFor,opfor);
HITPOINT_CHECK_SETTING_SIDE(Independent,independent);
HITPOINT_CHECK_SETTING_SIDE(Civilian,civilian);
