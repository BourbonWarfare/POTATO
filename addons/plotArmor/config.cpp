#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		author = "SagJangi";
        authorUrl = "https://steamcommunity.com/sharedfiles/filedetails/?id=2075156290";
		units[] = {};
		weapons[] = {"PLOT_ARMOR_V_Pockets_F","PLOT_ARMOR_V_BandollierB","PLOT_ARMOR_V_TacChestrig_grn_F","PLOT_ARMOR_V_Chestrig","PLOT_ARMOR_V_HarnessO_brn","PLOT_ARMOR_V_HarnessOGL_brn","PLOT_ARMOR_H_No_Hat","PLOT_ARMOR_H_Cap_oli","PLOT_ARMOR_H_Cap_tan","PLOT_ARMOR_H_Cap_grn","PLOT_ARMOR_H_Bandanna_cbr","PLOT_ARMOR_H_Bandanna_khk","PLOT_ARMOR_H_Bandanna_sand","PLOT_ARMOR_H_Booniehat_khk","PLOT_ARMOR_H_Booniehat_oli","PLOT_ARMOR_H_Booniehat_tan","PLOT_ARMOR_H_Shemag_olive","PLOT_ARMOR_H_ShemagOpen_khk","PLOT_ARMOR_H_ShemagOpen_tan","PLOT_ARMOR_H_3holeBalaclava"};
        requiredAddons[] = {"potato_core"};
        VERSION_CONFIG;
	};
};

class CfgWeapons {
	class V_BandollierB_khk;
	class V_BandollierB_blk: V_BandollierB_khk { 
		class ItemInfo;
	};
	class PLOT_ARMOR_V_Pockets_F: V_BandollierB_blk {
		author = "SagJangi";
		displayName = "PLOT ARMOR Pockets (Invisible Prop)";
		class ItemInfo: ItemInfo {
			uniformModel = "";
		};
	};
	class Vest_Camo_Base;
	class V_PlateCarrier1_blk: Vest_Camo_Base { 
		class ItemInfo;
	};
	class PLOT_ARMOR_V_BandollierB: V_PlateCarrier1_blk {
		author = "SagJangi";
		_generalMacro = "V_BandollierB_rgr";
		displayName = "PLOT ARMOR Slash Bandollier";
		picture = "\A3\Characters_F_Beta\Data\ui\icon_V_Bandolier_oli_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F\BLUFOR\Data\vests_rgr_co.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier.p3d";
		};
	};
	class PLOT_ARMOR_V_TacChestrig_grn_F: V_PlateCarrier1_blk {
		author = "SagJangi";
		_generalMacro = "V_TacChestrig_grn_F";
		displayName = "PLOT ARMOR Tactical Chest Rig";
		picture = "\A3\Characters_F_Exp\Data\UI\icon_V_TacChestrig_grn_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\Common\Data\equip_TacChestrig_grn_co.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F_Exp\Common\equip_TacChestrig.p3d";
		};
	};
	class PLOT_ARMOR_V_Chestrig: V_PlateCarrier1_blk {
		author = "SagJangi";
		_generalMacro = "V_Chestrig_rgr";
		displayName = "PLOT ARMOR Chest Rig";
		picture = "\A3\characters_f\Data\UI\icon_V_Chestrig_rgr_CA.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\equip_chestrig_rgr_co.paa","\A3\Characters_f\BLUFOR\data\armor1_co.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F\Common\equip_chestrig.p3d";
		};
	};
	class PLOT_ARMOR_V_HarnessO_brn: V_PlateCarrier1_blk {
		author = "SagJangi";
		_generalMacro = "V_HarnessO_brn";
		displayName = "PLOT ARMOR LBV Harness";
		picture = "\A3\characters_f\Data\UI\icon_V_HarnessO_brn_CA.paa";
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F\OPFOR\equip_o_vest01";
		};
	};
	class PLOT_ARMOR_V_HarnessOGL_brn: V_PlateCarrier1_blk {
		author = "SagJangi";
		_generalMacro = "V_HarnessOGL_brn";
		displayName = "PLOT ARMOR LBV Grenadier Harness";
		picture = "\A3\characters_f\Data\UI\icon_V_HarnessOGL_brn_CA.paa";
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F\OPFOR\equip_o_vest_gl";
		};
	};
	class H_HelmetB;
	class H_HelmetIA: H_HelmetB {
		class ItemInfo;
	};
	class PLOT_ARMOR_H_No_Hat: H_HelmetIA {
		author = "SagJangi";
		_generalMacro = "H_Cap_oli";
		displayName = "PLOT ARMOR No Hat (Invisable Prop)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_Cap_oli_ca.paa";
		class ItemInfo: ItemInfo {
			uniformModel = "";
		};
	};
	class PLOT_ARMOR_H_Cap_oli: H_HelmetIA {
		author = "SagJangi";
		_generalMacro = "H_Cap_oli";
		displayName = "PLOT ARMOR Cap (Olive)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_Cap_oli_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\capb_olive_co.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F\common\capb.p3d";
		};
	};
	class PLOT_ARMOR_H_Cap_tan: PLOT_ARMOR_H_Cap_oli {
		author = "SagJangi";
		_generalMacro = "H_Cap_tan";
		displayName = "PLOT ARMOR Cap (Tan)";
		picture = "\A3\characters_f\Data\UI\icon_H_Cap_tan_CA.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\capb_tan_co.paa"};
	};
	class PLOT_ARMOR_H_Cap_grn: PLOT_ARMOR_H_Cap_oli {
		author = "SagJangi";
		_generalMacro = "H_Cap_grn";
		displayName = "PLOT ARMOR Cap (Green)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_Cap_grn_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\capb_green_co.paa"};
	};
	class PLOT_ARMOR_H_Bandanna_cbr: H_HelmetIA {
		author = "SagJangi";
		_generalMacro = "H_Bandanna_cbr";
		displayName = "PLOT ARMOR Bandana (Coyote)";
		picture = "\A3\characters_f\Data\UI\icon_H_Bandanna_cbr_CA.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\h_bandana_cbr_co.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F\Civil\headgear_c_bandana1.p3d";
		};
	};
	class PLOT_ARMOR_H_Bandanna_khk: PLOT_ARMOR_H_Bandanna_cbr {
		author = "SagJangi";
		_generalMacro = "H_Bandanna_khk";
		displayName = "PLOT ARMOR Bandana (Khaki)";
		picture = "\A3\characters_f\Data\UI\icon_H_Bandanna_khk_CA.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\h_bandana_khk_co.paa"};
	};
	class PLOT_ARMOR_H_Bandanna_sand: PLOT_ARMOR_H_Bandanna_cbr	{
		author = "SagJangi";
		_generalMacro = "H_Bandanna_sand";
		displayName = "PLOT ARMOR Bandana (Sand)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_Bandanna_sand_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\h_bandana_sand_co.paa"};
	};
	class PLOT_ARMOR_H_Booniehat_khk: H_HelmetIA {
		author = "SagJangi";
		_generalMacro = "H_Booniehat_khk";
		displayName = "PLOT ARMOR Boonie Hat (Khaki)";
		picture = "\A3\characters_f\Data\UI\icon_H_booniehat_desert_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\booniehat_khk_co.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F\Common\booniehat";
		};
	};
	class PLOT_ARMOR_H_Booniehat_oli: PLOT_ARMOR_H_Booniehat_khk {
		author = "SagJangi";
		_generalMacro = "H_Booniehat_oli";
		displayName = "PLOT ARMOR Boonie Hat (Olive)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_Booniehat_oli_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\booniehat_grn_co.paa"};
	};
	class PLOT_ARMOR_H_Booniehat_tan: PLOT_ARMOR_H_Booniehat_khk {
		author = "SagJangi";
		_generalMacro = "H_Booniehat_tan";
		displayName = "PLOT ARMOR Boonie Hat (Tan)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_Booniehat_tan_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\booniehat_tan_co.paa"};
	};
	class PLOT_ARMOR_H_Shemag_olive: H_HelmetIA {
		author = "SagJangi";
		_generalMacro = "H_Shemag_olive";
		displayName = "PLOT ARMOR Shemag (Olive)";
		picture = "\A3\characters_F_Gamma\Guerrilla\Data\ui\icon_H_Shemag_olive_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\characters_F_Gamma\Guerrilla\Data\h_shemag_olive_co.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F_gamma\Guerrilla\headgear_shemagmask";
		};
	};
	class PLOT_ARMOR_H_ShemagOpen_khk: PLOT_ARMOR_H_Shemag_olive {
		author = "SagJangi";
		_generalMacro = "H_ShemagOpen_khk";
		displayName = "PLOT ARMOR Shemag (White)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_ShemagOpen_khk_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\h_shemag_basic_co.paa"};
	};
	class PLOT_ARMOR_H_ShemagOpen_tan: PLOT_ARMOR_H_Shemag_olive {
		author = "SagJangi";
		_generalMacro = "H_ShemagOpen_Tan";
		displayName = "PLOT ARMOR Shemag (Tan)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_ShemagOpen_khk_ca.paa";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Bootcamp\Civil\Data\h_shemag_brn_co.paa"};
	};
    class PLOT_ARMOR_H_3holeBalaclava: H_HelmetIA {
        author = "Chesheire";
		displayName = "PLOT ARMOR 3-hole Balaclava (Black)";
		picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_G_Balaclava_clean_ca.paa";
        hiddenSelections[] = {"camo"};
        hiddenSelectionsTextures[] = {"\a3\characters_f_bootcamp\guerrilla\data\headgear_balaclava_blk_co.paa"};
		class ItemInfo: ItemInfo {
			uniformModel = "\A3\Characters_F_Bootcamp\Guerrilla\g_balaclava_clean.p3d";
		};
    };
};
