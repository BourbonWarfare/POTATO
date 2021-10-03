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
#define SCORE_6(a,b,c,d,e,f) a##_##b##_##c##_##d##_##e##_##f

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
#define TYPICAL_SPEED_SMALL 920
#define AIR_FRICTION_SMALL -0.0012

#define CALIBER_MEDIUM 1.2
#define HIT_MEDIUM 11
#define HIT_DANGER_MEDIUM 12
#define HIT_SUPPRESSION_MEDIUM 8
#define FLYBY_DANGER_MEDIUM 8
#define FLYBY_SUPPRESSION_MEDIUM 8
#define AUDIBLE_FIRE_MEDIUM 150
#define TYPICAL_SPEED_MEDIUM 730
#define AIR_FRICTION_MEDIUM -0.0016

#define CALIBER_LARGE 4.6
#define HIT_LARGE 20
#define HIT_DANGER_LARGE 14
#define HIT_SUPPRESSION_LARGE 10
#define FLYBY_DANGER_LARGE 4
#define FLYBY_SUPPRESSION_LARGE 2
#define AUDIBLE_FIRE_LARGE 200
#define TYPICAL_SPEED_LARGE 270
#define AIR_FRICTION_LARGE -0.0014

#define AUDIBLE_FIRE_SUBSONIC 10



#define AI_AMMO_USAGE_FLAGS_SMALL "64 + 128 + 256"
#define AI_AMMO_USAGE_FLAGS_MEDIUM "64 + 128 + 256"
#define AI_AMMO_USAGE_FLAGS_LARGE "64 + 128 + 256"

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
    ammo = AMMO_CLASS(CONCAT(ammoType,CONCAT(_tracer_,colour))); \
}

#define CREATE_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,colour,type,tracerEvery,lastRoundTracers)\
class MAGAZINE_CLASS(SCORE_5(type,ammoType,CONCAT(bulletCount,rnd),reload_tracer,colour)): MAGAZINE_CLASS(SCORE_3(type,ammoType,CONCAT(bulletCount,rnd))) { \
    displayName = RELOAD_TRACER_DISPLAY_NAME(ammoDisplayName,bulletCount,colour);\
    tracersEvery = tracerEvery; \
    lastRoundsTracer = lastRoundTracers; \
    ammo = AMMO_CLASS(CONCAT(ammoType,CONCAT(_tracer_,colour))); \
}

#define CREATE_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,type,tracerEvery,lastRoundTracers) \
class MAGAZINE_CLASS(SCORE_3(type,ammoType,CONCAT(bulletCount,rnd))): baseClass { \
    author = "Brandon (TCVM)"; \
    scope = 2; \
    displayName = DISPLAY_NAME(ammoDisplayName,bulletCount);\
    count = bulletCount; \
    tracersEvery = 0;\
    lastRoundsTracer = 0;\
    ammo = AMMO_CLASS(ammoType); \
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

#define CREATE_ALT_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,colour,type,alt)\
class MAGAZINE_CLASS(SCORE_6(type,ammoType,CONCAT(bulletCount,rnd),tracer,colour,alt)): MAGAZINE_CLASS(SCORE_4(type,ammoType,CONCAT(bulletCount,rnd),alt)) { \
    displayName = TRACER_DISPLAY_NAME(ammoDisplayName,bulletCount,colour);\
    tracersEvery = 1; \
    ammo = AMMO_CLASS(CONCAT(ammoType,CONCAT(_tracer_,colour))); \
}

#define CREATE_ALT_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,colour,type,tracerEvery,lastRoundTracers,alt)\
class MAGAZINE_CLASS(SCORE_6(type,ammoType,CONCAT(bulletCount,rnd),reload_tracer,colour,alt)): MAGAZINE_CLASS(SCORE_4(type,ammoType,CONCAT(bulletCount,rnd),alt)) { \
    displayName = RELOAD_TRACER_DISPLAY_NAME(ammoDisplayName,bulletCount,colour);\
    tracersEvery = tracerEvery; \
    lastRoundsTracer = lastRoundTracers; \
    ammo = AMMO_CLASS(CONCAT(ammoType,CONCAT(_tracer_,colour))); \
}

#define CREATE_ALT_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,type,tracerEvery,lastRoundTracers,alt) \
class MAGAZINE_CLASS(SCORE_4(type,ammoType,CONCAT(bulletCount,rnd),alt)): baseClass { \
    author = "Brandon (TCVM)"; \
    scope = 2; \
    displayName = DISPLAY_NAME(ammoDisplayName,bulletCount);\
    count = bulletCount; \
    tracersEvery = 0;\
    lastRoundsTracer = 0;\
    ammo = AMMO_CLASS(ammoType); \
}; \
CREATE_ALT_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Red,type,alt); \
CREATE_ALT_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Green,type,alt); \
CREATE_ALT_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Yellow,type,alt); \
CREATE_ALT_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,White,type,alt); \
CREATE_ALT_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,IR,type,alt); \
CREATE_ALT_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Red,type,tracerEvery,lastRoundTracers,alt); \
CREATE_ALT_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Green,type,tracerEvery,lastRoundTracers,alt); \
CREATE_ALT_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,Yellow,type,tracerEvery,lastRoundTracers,alt); \
CREATE_ALT_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,White,type,tracerEvery,lastRoundTracers,alt); \
CREATE_ALT_RELOAD_TRACER_TYPE(ammoType,ammoDisplayName,bulletCount,IR,type,tracerEvery,lastRoundTracers,alt)

#define CREATE_MAGAZINE(ammoType,ammoDisplayName,bulletCount,baseClass) CREATE_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,magazine,0,RELOAD_TRACER_REMAINING)
#define CREATE_BOX(ammoType,ammoDisplayName,bulletCount,baseClass) CREATE_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,box,MG_TRACER_EVERY,RELOAD_TRACER_REMAINING)

#define CREATE_ALT_MAGAZINE(ammoType,ammoDisplayName,bulletCount,baseClass,alt) CREATE_ALT_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,magazine,0,RELOAD_TRACER_REMAINING,alt)
#define CREATE_ALT_BOX(ammoType,ammoDisplayName,bulletCount,baseClass,alt) CREATE_ALT_TYPE(ammoType,ammoDisplayName,bulletCount,baseClass,box,MG_TRACER_EVERY,RELOAD_TRACER_REMAINING,alt)

#define MAGAZINE_WELL_TYPE(ammoType,bulletCount,type) QUOTE(MAGAZINE_CLASS(SCORE_3(type,ammoType,CONCAT(bulletCount,rnd))))
#define MAGAZINE_WELL_RELOAD_TRACER_TYPE(ammoType,bulletCount,colour,type) QUOTE(MAGAZINE_CLASS(SCORE_5(type,ammoType,CONCAT(bulletCount,rnd),reload_tracer,colour)))
#define MAGAZINE_WELL_TRACER_TYPE(ammoType,bulletCount,colour,type) QUOTE(MAGAZINE_CLASS(SCORE_5(type,ammoType,CONCAT(bulletCount,rnd),tracer,colour)))

#define MAGAZINE_WELL_ALT_TYPE(ammoType,bulletCount,type,alt) QUOTE(MAGAZINE_CLASS(SCORE_4(type,ammoType,CONCAT(bulletCount,rnd),alt)))
#define MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,colour,type,alt) QUOTE(MAGAZINE_CLASS(SCORE_6(type,ammoType,CONCAT(bulletCount,rnd),reload_tracer,colour,alt)))
#define MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,colour,type,alt) QUOTE(MAGAZINE_CLASS(SCORE_6(type,ammoType,CONCAT(bulletCount,rnd),tracer,colour,alt)))

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

#define MAGAZINE_WELL_ALT_MAG(ammoType,bulletCount,alt) \
MAGAZINE_WELL_ALT_TYPE(ammoType,bulletCount,magazine,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,Red,magazine,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,Green,magazine,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,Yellow,magazine,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,White,magazine,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,IR,magazine,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,Red,magazine,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,Green,magazine,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,Yellow,magazine,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,White,magazine,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,IR,magazine,alt)

#define MAGAZINE_WELL_ALT_BOX(ammoType,bulletCount,alt) \
MAGAZINE_WELL_ALT_TYPE(ammoType,bulletCount,box,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,Red,box,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,Green,box,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,Yellow,box,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,White,box,alt), \
MAGAZINE_WELL_TRACER_ALT_TYPE(ammoType,bulletCount,IR,box,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,Red,box,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,Green,box,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,Yellow,box,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,White,box,alt), \
MAGAZINE_WELL_RELOAD_TRACER_ALT_TYPE(ammoType,bulletCount,IR,box,alt)

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

#define TYPICAL_CONFIG \
airLock = 1; \
indirectHit = 0; \
indirectHitRange = 0; \
cost = 1; \
waterFriction = -0.3; \
tracerScale = 1; \
tracerStartTime = 0.05; \
tracerEndTime = 1

#define SMALL_AMMO_CONFIG \
TYPICAL_CONFIG; \
dangerRadiusBulletClose = HIT_DANGER_SMALL; \
dangerRadiusHit = FLYBY_DANGER_SMALL; \
suppressionRadiusBulletClose = FLYBY_SUPPRESSION_SMALL; \
suppressionRadiusHit = HIT_SUPPRESSION_SMALL; \
hit = HIT_SMALL; \
audibleFire = AUDIBLE_FIRE_SMALL; \
caliber = CALIBER_SMALL; \
aiAmmoUsageFlags = AI_AMMO_USAGE_FLAGS_SMALL; \
ACE_damageType = "bullet";\
ace_vehicle_damage_incendiary = 0;\
typicalSpeed = TYPICAL_SPEED_SMALL;\
airFriction = AIR_FRICTION_SMALL;\
class CamShakeExplode {\
    power = 2.24;\
    duration = 0.4;\
    frequency = 20;\
    distance = 6.7;\
};\
class CamShakeHit {\
    power = 5;\
    duration = 0.2;\
    frequency = 20;\
    distance = 1;\
}

#define MEDIUM_AMMO_CONFIG \
TYPICAL_CONFIG; \
dangerRadiusBulletClose = HIT_DANGER_MEDIUM; \
dangerRadiusHit = FLYBY_DANGER_MEDIUM; \
suppressionRadiusBulletClose = FLYBY_SUPPRESSION_MEDIUM; \
suppressionRadiusHit = HIT_SUPPRESSION_MEDIUM; \
hit = HIT_MEDIUM; \
audibleFire = AUDIBLE_FIRE_MEDIUM; \
caliber = CALIBER_MEDIUM; \
aiAmmoUsageFlags = AI_AMMO_USAGE_FLAGS_MEDIUM; \
ACE_damageType = "bullet";\
ace_vehicle_damage_incendiary = 0;\
typicalSpeed = TYPICAL_SPEED_MEDIUM;\
airFriction = AIR_FRICTION_MEDIUM;\
class CamShakeExplode {\
    power = 2.24;\
    duration = 0.4;\
    frequency = 20;\
    distance = 6.7;\
};\
class CamShakeHit {\
    power = 5;\
    duration = 0.2;\
    frequency = 20;\
    distance = 1;\
}

#define LARGE_AMMO_CONFIG \
TYPICAL_CONFIG; \
dangerRadiusBulletClose = HIT_DANGER_LARGE; \
dangerRadiusHit = FLYBY_DANGER_LARGE; \
suppressionRadiusBulletClose = FLYBY_SUPPRESSION_LARGE; \
suppressionRadiusHit = HIT_SUPPRESSION_LARGE; \
hit = HIT_LARGE; \
audibleFire = AUDIBLE_FIRE_LARGE; \
caliber = CALIBER_LARGE; \
aiAmmoUsageFlags = AI_AMMO_USAGE_FLAGS_LARGE; \
ACE_damageType = "bullet";\
ace_vehicle_damage_incendiary = 0;\
typicalSpeed = TYPICAL_SPEED_LARGE;\
airFriction = AIR_FRICTION_LARGE;\
class CamShakeExplode {\
    power = 2.24;\
    duration = 0.4;\
    frequency = 20;\
    distance = 6.7;\
};\
class CamShakeHit {\
    power = 15;\
    duration = 0.4;\
    frequency = 20;\
    distance = 1;\
}

#define CREATE_SMALL_AMMO(type)\
class AMMO_CLASS(type): BulletBase {\
    SMALL_AMMO_CONFIG;\
};\
TRACER_CLASSES(type)

#define CREATE_MEDIUM_AMMO(type)\
class AMMO_CLASS(type): BulletBase {\
    MEDIUM_AMMO_CONFIG;\
};\
TRACER_CLASSES(type)

#define CREATE_LARGE_AMMO(type)\
class AMMO_CLASS(type): BulletBase {\
    LARGE_AMMO_CONFIG;\
};\
TRACER_CLASSES(type)

