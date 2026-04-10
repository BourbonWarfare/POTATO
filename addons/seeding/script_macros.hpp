#define MISSION_PREFIX seed
#define PREFIX bw

// Basic
#define GLUE(var1,var2)         var1##var2
#define GLUETRI(var1,var2,var3) GLUE(var1,GLUE(var2,var3))
#define DOUBLES(var1,var2)      var1##_##var2
#define TRIPLES(var1,var2,var3) var1##_##var2##_##var3
#define QUOTE(var1)             #var1
#define QQUOTE(var1)            QUOTE(QUOTE(var1))
#define ARR_2(var1,var2)        var1,var2

// Redefine mission prefix
#define MISSION_GVAR_PREFIX DOUBLES(PREFIX,MISSION_PREFIX)

// Variable functions
#define GVAR(var1)   DOUBLES(MISSION_GVAR_PREFIX,var1)
#define QGVAR(var1)  QUOTE(DOUBLES(MISSION_GVAR_PREFIX,var1))
#define DGVAR(var1)  DOUBLES(MISSION_PREFIX,var1)
#define QDGVAR(var1) QUOTE(DOUBLES(MISSION_PREFIX,var1))
#define FUNC(var1)   TRIPLES(PREFIX,fnc,var1)
#define QFUNC(var1)  QUOTE(FUNC(var1))

// ACE Functions & Variables
#define ACEGVAR(addon,var) TRIPLES(ace,addon,var)
#define QACEGVAR(addon,var) QUOTE(ACEGVAR(addon,var))
#define ACEFUNC(addon,func) TRIPLES(DOUBLES(ace,addon),fnc,func)
#define QACEFUNC(addon,func) QUOTE(ACEFUNC(addon,func))

// Potato variables
#define PGVAR(var1,var2) TRIPLES(potato,var1,var2)
#define QPGVAR(var1,var2) QUOTE(PGVAR(var1,var2))
#define PFUNC(var1,var2) TRIPLES(DOUBLES(potato,var1),fnc,var2)
#define QPFUNC(var1,var2) QUOTE(PFUNC(var1,var2))
#define QPPATHTOF(addon,path) QUOTE(GLUE(GLUETRI(\z\potato\addons\,addon,\),path))
