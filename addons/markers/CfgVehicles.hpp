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
    };
};
