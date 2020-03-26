#include "script_component.hpp"

TRACE_1("zeusInterfaceOpenedEH",_this);

if (!(missionNamespace getVariable [QGVAR(enabled), false])) exitWith {};

if (isNil QGVAR(init)) then {
    GVAR(state) = 0;
    GVAR(stateSubIndex) = 0;

    GVAR(uniqueID) = 0;
    GVAR(allTargets) = [];
    GVAR(allTargetInfo) = [];
    GVAR(targetGroups) = [];
    
    GVAR(friendlyUnits) = [];
    GVAR(friendlyGroups) = [];
    GVAR(friendlyReports) = [];

    GVAR(addToCurator) = [];
    GVAR(removeFromCurator) = [];

    if (isNull getAssignedCuratorLogic player) then {systemChat "Unknown Curator?";};

    addMissionEventHandler ["EachFrame", {
        BEGIN_COUNTER(reconStateMachine);
        call FUNC(reconStateMachine);
        call FUNC(reconStateMachine);
        call FUNC(reconStateMachine);
        call FUNC(reconStateMachine);
        call FUNC(reconStateMachine);
        END_COUNTER(reconStateMachine);
    }];

    INFO("Initial Setup Done");
    GVAR(init) = true;
};

// Add draw EH for icons:
addMissionEventHandler ["Draw3D", LINKFUNC(drawIcons3d)];

// Note: This one doesn't need to be removed as dispaly is re-created each time zeus is opened
((_this select 0) displayCtrl 50) ctrlAddEventHandler ["draw", LINKFUNC(drawIcons2d)];
