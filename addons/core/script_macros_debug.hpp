// Dev Ony: Enabling these will skip configs from any potato addons that require external mods
// Allows loading just cba/ace/potato

// Should now be handled automatically by __has_include checks
// EXCEPT when using filePatching: files that exist outside of pbos will still pass for some reason
// Ref https://feedback.bistudio.com/T161113 (so might still need to use these for acre)


// #define POTATO_LEAN_RHS_CUP_HLC "LEAN RHS/CUP/HLC"
// #define POTATO_LEAN_ACRE "LEAN ACRE"


// macro add a dummy cfgPatch and notLoaded entry
#define PATCH_NOT_LOADED(NAME,CAUSE) \
class CfgPatches { \
    class DOUBLES(NAME,notLoaded) { \
        units[] = {}; \
        weapons[] = {}; \
        requiredVersion = REQUIRED_VERSION; \
        requiredAddons[] = {"potato_core"}; \
        version = VERSION; \
    }; \
}; \
class potato_notLoaded { \
    NAME = CAUSE; \
};
