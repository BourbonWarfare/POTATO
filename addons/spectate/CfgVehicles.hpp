class CfgVehicles {
    class VirtualMan_F;

    // add spectate group holder
    class GVAR(holder): VirtualMan_F {
        author = "POTATO";
        scope = 1;
        scopeArsenal = 0;
        scopeCurator = 0;

        icon = "iconManDead";

        weapons[] = {}; // empty weapons array

        delete ACE_Actions;
        delete ACE_SelfActions;
    };

    // add spectator
    class GVAR(spectator): GVAR(holder) {
        author = "POTATO";
    };

    // add playable spectator
    class GVAR(playableSpectator): GVAR(spectator) {
        author = "POTATO";
        displayName = "POTATO Spectator";
        displayNameShort = "Spectator";
        icon = "iconPotatoSpectate";
        scope = 2;
    };
};
