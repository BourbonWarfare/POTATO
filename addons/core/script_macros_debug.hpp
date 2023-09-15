// macro add a dummy cfgPatch and notLoaded entry
#define POTATO_PATCH_NOT_LOADED(NAME,CAUSE) \
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
