class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_TeamManagement {
                class ACE_BecomeLeader {
                    condition = QUOTE(_this call FUNC(becomeGroupLeader_condition));
                    statement = QUOTE(_this call FUNC(becomeGroupLeader_statement));
                };
                class ACE_LeaveGroup {
                    statement = QUOTE(_this call FUNC(leaveGroup_statement));
                };
            };
        };
        class ACE_Actions {
            class ACE_MainActions {
                class ACE_JoinGroup {
                    statement = QUOTE(_this call FUNC(joinGroup_statement));
                };
            };
        };
    };
};
