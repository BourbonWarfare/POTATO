#define SCORE_2(a,b) a##_##b
#define ACE_MISSILE(missile) class ace_missileguidance: ACEGVAR(missileguidance,SCORE_2(type,missile)) { enabled = 1; }