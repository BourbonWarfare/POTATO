// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp

#define MAINPREFIX z
#define PREFIX potato

#include "script_version.hpp"

#define VERSION MAJOR.MINOR.PATCHLVL.BUILD
#define VERSION_AR MAJOR,MINOR,PATCHLVL,BUILD


// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 1.94

// Warn if starting **NEW** mission on a BWMF version older than this
#define EXPECTED_BWMF "2020/20/16"
// it's 20 just to match mistake in actual
