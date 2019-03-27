#define CONST_TIME 0.03
#define IS_EXPLOSIVE_AMMO(ammo) (getNumber (ammo call CBA_fnc_getObjectConfig >> "explosive") > 0.5)
#define ENGINE_HITPOINTS [["hitengine"], "engine"]
#define HULL_HITPOINTS [["hithull"], "hull"]
#define TURRET_HITPOINTS [["hitgun", "hitturret"], "turret"]
#define TRACK_HITPOINTS [["hitltrack", "hitrtrack"], "track"]
#define WHEEL_HITPOINTS [["hitlbwheel", "hitlmwheel", "hitlfwheel", "hitlf2wheel", "hitrbwheel", "hitrlwheel", "hitrfwheel", "hitrf2wheel"], "wheel"]
