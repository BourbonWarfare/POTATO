/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[
    format [
        "%1,%2,%3,%4,%5,%6,%7,%8",
        GVAR(addCommonChannelWestMR),
        GVAR(addCommonChannelWestLR),
        GVAR(addCommonChannelEastMR),
        GVAR(addCommonChannelEastLR),
        GVAR(addCommonChannelIndyMR),
        GVAR(addCommonChannelIndyLR),
        GVAR(addCommonChannelCivMR),
        GVAR(addCommonChannelCivLR)
    ],
    GVAR(westDefaultLanguages) joinString ",",
    GVAR(eastDefaultLanguages) joinString ",",
    GVAR(indyDefaultLanguages) joinString ",",
    GVAR(civDefaultLanguages) joinString ",",
    GVAR(westSRChannelNames) joinString ",",
    GVAR(westMRChannelNames) joinString ",",
    GVAR(westLRChannelNames) joinString ",",
    GVAR(eastSRChannelNames) joinString ",",
    GVAR(eastMRChannelNames) joinString ",",
    GVAR(eastLRChannelNames) joinString ",",
    GVAR(indySRChannelNames) joinString ",",
    GVAR(indyMRChannelNames) joinString ",",
    GVAR(indyLRChannelNames) joinString ",",
    GVAR(civSRChannelNames) joinString ",",
    GVAR(civMRChannelNames) joinString ",",
    GVAR(civLRChannelNames) joinString ","
]
