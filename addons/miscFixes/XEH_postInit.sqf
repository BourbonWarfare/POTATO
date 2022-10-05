// Temp fix to remove old Ace trenches and SOG spider holes

if (hasInterface) then {
    [typeOf player, 1, ["ACE_SelfActions","ACE_Equipment","ace_trenches_digEnvelopeSmall"]] call ace_interact_menu_fnc_removeActionFromClass;
    [typeOf player, 1, ["ACE_SelfActions","ACE_Equipment","ace_trenches_digEnvelopeBig"]] call ace_interact_menu_fnc_removeActionFromClass;
    [typeOf player, 1, ["ACE_SelfActions","ACE_Equipment","ace_compat_sog_digSpiderhole"]] call ace_interact_menu_fnc_removeActionFromClass;
    [typeOf player, 1, ["ACE_SelfActions","ACE_Equipment","ace_compat_sog_digSpiderholeAngled"]] call ace_interact_menu_fnc_removeActionFromClass;
    [typeOf player, 1, ["ACE_SelfActions","ACE_Equipment","ace_compat_sog_digSpiderholeDual"]] call ace_interact_menu_fnc_removeActionFromClass;
};