#define COMPONENT massCompat
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_MASSCOMPAT
    #define DEBUG_MODE_FULL
#endif

#include "\z\potato\addons\core\script_macros.hpp"

#define REPEAT(a) a
#define CONCAT(a,b) a####b
#define SCORE_2(a,b) a##_##b
#define SCORE_3(a,b,c) a##_##b##_##c
#define SCORE_4(a,b,c,d) a##_##b##_##c##_##d
#define SCORE_5(a,b,c,d,e) a##_##b##_##c##_##d##_##e

#define AMMO_CLASS(type) SCORE_3(potato,bullet,type)
#define MAGAZINE_CLASS(type) SCORE_2(potato,type)

#define RELOAD_TRACER_REMAINING 4
#define MG_TRACER_EVERY 4

#define CALIBER_SMALL 0.9
#define HIT_SMALL 9
#define HIT_DANGER_SMALL 8
#define HIT_SUPPRESSION_SMALL 12
#define FLYBY_DANGER_SMALL 6
#define FLYBY_SUPPRESSION_SMALL 8
#define AUDIBLE_FIRE_SMALL 100


#define AUDIBLE_FIRE_MEDIUM 150


#define AUDIBLE_FIRE_LARGE 200


#define AUDIBLE_FIRE_SUBSONIC 10



#define AI_AMMO_USAGE_FLAGS_SMALL "64 + 128 + 256"

#define RED_TRACER "\A3\Weapons_f\Data\bullettracer\tracer_red"
#define GREEN_TRACER "\A3\Weapons_f\Data\bullettracer\tracer_green"
#define YELLOW_TRACER "\A3\Weapons_f\Data\bullettracer\tracer_yellow"
#define WHITE_TRACER "\A3\Weapons_f\Data\bullettracer\tracer_white"

// æ to get to top of any listboxes
#define DISPLAY_NAME(ammoDisplayName,bulletCount) QUOTE(CONCAT(æ ,CONCAT(ammoDisplayName,CONCAT(bulletCount,Rnd (No Tracer) [POTATO]))))
#define TRACER_DISPLAY_NAME(ammoDisplayName,bulletCount,colour) QUOTE(CONCAT(æ ,CONCAT(ammoDisplayName,CONCAT(bulletCount,Rnd Tracer (REPEAT(colour)) [POTATO]))))
#define RELOAD_TRACER_DISPLAY_NAME(ammoDisplayName,bulletCount,colour) QUOTE(CONCAT(æ ,CONCAT(ammoDisplayName,CONCAT(bulletCount,Rnd Reload Tracer (REPEAT(colour)) [POTATO]))))

#define CREATE_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,colour,type)\
class MAGAZINE_CLASS(SCORE_5(type,ammoType,CONCAT(bulletCount,rnd),tracer,colour)): MAGAZINE_CLASS(SCORE_3(type,ammoType,CONCAT(bulletCount,rnd))) { \
    displayName = TRACER_DISPLAY_NAME(ammoDisplayName,bulletCount,colour);\
    tracersEvery = 1; \
    ammoTemp = AMMO_CLASS(CONCAT(ammoType,CONCAT(_tracer_,colour))); \
}

#define CREATE_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,colour,type,tracerEvery,lastRoundTracers)\
class MAGAZINE_CLASS(SCORE_5(type,ammoType,CONCAT(bulletCount,rnd),reload_tracer,colour)): MAGAZINE_CLASS(SCORE_3(type,ammoType,CONCAT(bulletCount,rnd))) { \
    displayName = RELOAD_TRACER_DISPLAY_NAME(ammoDisplayName,bulletCount,colour);\
    tracersEvery = tracerEvery; \
    lastRoundsTracer = lastRoundTracers; \
    ammoTemp = AMMO_CLASS(CONCAT(ammoType,CONCAT(_tracer_,colour))); \
}

#define CREATE_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,type,tracerEvery,lastRoundTracers) \
class MAGAZINE_CLASS(SCORE_3(type,ammoType,CONCAT(bulletCount,rnd))): baseClass { \
    author = "Brandon (TCVM)"; \
    scope = 2; \
    displayName = DISPLAY_NAME(ammoDisplayName,bulletCount);\
    count = bulletCount; \
    tracersEvery = 0;\
    lastRoundsTracer = 0;\
    ammoTemp = AMMO_CLASS(ammoType); \
}; \
CREATE_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Red,type); \
CREATE_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Green,type); \
CREATE_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Yellow,type); \
CREATE_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,White,type); \
CREATE_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,IR,type); \
CREATE_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Red,type,tracerEvery,lastRoundTracers); \
CREATE_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Green,type,tracerEvery,lastRoundTracers); \
CREATE_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Yellow,type,tracerEvery,lastRoundTracers); \
CREATE_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,White,type,tracerEvery,lastRoundTracers); \
CREATE_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,IR,type,tracerEvery,lastRoundTracers)

#define CREATE_MAGAZINE(ammoType,ammoDisplayName,bulletCount,baseClass) CREATE_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,magazine,0,RELOAD_TRACER_REMAINING)
#define CREATE_BOX(ammoType,ammoDisplayName,bulletCount,baseClass) CREATE_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,box,MG_TRACER_EVERY,RELOAD_TRACER_REMAINING)

#define MAGAZINE_WELL_TYPE(ammoType,bulletCount,type) QUOTE(MAGAZINE_CLASS(SCORE_3(type,ammoType,CONCAT(bulletCount,rnd))))
#define MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,colour,type) QUOTE(MAGAZINE_CLASS(SCORE_5(type,ammoType,CONCAT(bulletCount,rnd),reload_tracer,colour)))
#define MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,colour,type) QUOTE(MAGAZINE_CLASS(SCORE_5(type,ammoType,CONCAT(bulletCount,rnd),tracer,colour)))

#define MAGAZINE_WELL_MAG(ammoType,bulletCount) \
MAGAZINE_WELL_TYPE(ammoType,bulletCount,magazine), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,Red,magazine), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,Green,magazine), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,Yellow,magazine), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,White,magazine), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,IR,magazine), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,Red,magazine), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,Green,magazine), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,Yellow,magazine), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,White,magazine), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,IR,magazine)

#define MAGAZINE_WELL_BOX(ammoType,bulletCount) \
MAGAZINE_WELL_TYPE(ammoType,bulletCount,box), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,Red,box), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,Green,box), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,Yellow,box), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,White,box), \
MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,IR,box), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,Red,box), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,Green,box), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,Yellow,box), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,White,box), \
MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,IR,box)

#define TRACER_CLASSES(baseClass)\
class AMMO_CLASS(SCORE_3(baseClass,tracer,Red)): AMMO_CLASS(baseClass) { \
    model = RED_TRACER; \
    nvgOnly = 0; \
}; \
class AMMO_CLASS(SCORE_3(baseClass,tracer,Green)): AMMO_CLASS(baseClass) { \
    model = GREEN_TRACER; \
    nvgOnly = 0; \
}; \
class AMMO_CLASS(SCORE_3(baseClass,tracer,Yellow)): AMMO_CLASS(baseClass) { \
    model = YELLOW_TRACER; \
    nvgOnly = 0; \
}; \
class AMMO_CLASS(SCORE_3(baseClass,tracer,White)): AMMO_CLASS(baseClass) { \
    model = WHITE_TRACER; \
    nvgOnly = 0; \
}; \
class AMMO_CLASS(SCORE_3(baseClass,tracer,IR)): AMMO_CLASS(baseClass) { \
    nvgOnly = 1; \
}

#define SMALL_AMMO_CONFIG \
dangerRadiusBulletClose = HIT_DANGER_SMALL; \
dangerRadiusHit = FLYBY_DANGER_SMALL; \
suppressionRadiusBulletClose = FLYBY_SUPPRESSION_SMALL; \
suppressionRadiusHit = HIT_SUPPRESSION_SMALL; \
hit = HIT_SMALL; \
audibleFire = AUDIBLE_FIRE_SMALL; \
caliber = CALIBER_SMALL; \
aiAmmoUsageFlags = AI_AMMO_USAGE_FLAGS_SMALL; \
ACE_damageType = "bullet";\
ace_vehicle_damage_incendiary = 0

