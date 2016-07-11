/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[
    [GVAR(westSRChannelNames),GVAR(westMRChannelNames),GVAR(westLRChannelNames),GVAR(westDefaultLanguage),GVAR(addCommonChannelWestMR),GVAR(addCommonChannelWestLR)], // west
    [GVAR(eastSRChannelNames),GVAR(eastMRChannelNames),GVAR(eastLRChannelNames),GVAR(eastDefaultLanguage),GVAR(addCommonChannelEastMR),GVAR(addCommonChannelEastLR)], // east
    [GVAR(indySRChannelNames),GVAR(indyMRChannelNames),GVAR(indyLRChannelNames),GVAR(indyDefaultLanguage),GVAR(addCommonChannelIndyMR),GVAR(addCommonChannelIndyLR)], // indy
    [GVAR(civSRChannelNames),GVAR(civMRChannelNames),GVAR(civLRChannelNames),GVAR(civDefaultLanguage),GVAR(addCommonChannelCivMR),GVAR(addCommonChannelCivLR)] // civ
]
