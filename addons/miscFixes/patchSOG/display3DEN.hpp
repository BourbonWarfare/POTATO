class ctrlControlsGroupNoScrollbars;
class ctrlTree;
class Display3DEN {
    class Controls {
        class PanelRight: ctrlControlsGroupNoScrollbars {
            class Controls {
                class PanelRightCreate: ctrlControlsGroupNoScrollbars {
                    class Controls {
                        class Create: ctrlControlsGroupNoScrollbars {
                            class Controls {
                                // Units
                                class CreateObjectWEST: ctrlTree {
                                    defaultItem[] = {
                                        QUOTE(DOUBLES(PREFIX,W)),
                                        "Fireteam"
                                    };
                                };
                                class CreateObjectEAST: CreateObjectWEST {
                                    defaultItem[] = {
                                        QUOTE(DOUBLES(PREFIX,E)),
                                        "Fireteam"
                                    };
                                };
                                class CreateObjectGUER: CreateObjectWEST {
                                    defaultItem[] = {
                                        QUOTE(DOUBLES(PREFIX,I)),
                                        "Fireteam"
                                    };
                                };
                                class CreateObjectCIV: CreateObjectWEST {
                                    defaultItem[] = {
                                        "CIV_F",
                                        "EdSubcat_Personnel"
                                    };
                                };
                                class CreateObjectEMPTY: CreateObjectWEST {};
                                // Groups
                                class CreateGroupWEST: CreateObjectEMPTY {
                                    defaultItem[] = {
                                        QUOTE(DOUBLES(PREFIX,W)),
                                        "Infantry"
                                    };
                                };
                                class CreateGroupEAST: CreateObjectEMPTY {
                                    defaultItem[] = {
                                        QUOTE(DOUBLES(PREFIX,E)),
                                        "Infantry"
                                    };
                                };
                                class CreateGroupGUER: CreateObjectEMPTY {
                                    defaultItem[] = {
                                        QUOTE(DOUBLES(PREFIX,I)),
                                        "Infantry"
                                    };
                                };
                                class CreateGroupCiv: CreateObjectEMPTY {
                                    defaultItem[] = {};
                                };
                            };
                        };
                    };
                };
            };
        };
    };
};
