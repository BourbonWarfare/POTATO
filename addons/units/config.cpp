#include "script_component.hpp"

class CfgPatches {
    class ADDON {
    units[] = {
        "potato_w_rifleman","potato_w_rifleman_02","potato_w_rifleman_03","potato_w_rifleman_04","potato_w_sf_rifleman","potato_w_sf_rifleman_02","potato_w_sniper","potato_w_aar","potato_w_sf_aar","potato_w_mmgag","potato_w_hmgag","potato_w_matag","potato_w_hatag","potato_w_msamag","potato_w_mtrag","potato_w_mtrg","potato_w_spotter","potato_w_ar","potato_w_sf_ar","potato_w_mmgg","potato_w_hmgg","potato_w_lat","potato_w_sf_lat","potato_w_matg","potato_w_hatg","potato_w_msamg","potato_w_coy","potato_w_xo","potato_w_uav","potato_w_fac","potato_w_plt","potato_w_sgt","potato_w_sl","potato_w_sf_sl","potato_w_mmgl","potato_w_hmgl","potato_w_matl","potato_w_hatl","potato_w_msaml","potato_w_mtrl","potato_w_stl","potato_w_ftl","potato_w_sf_ftl","potato_w_vicl","potato_w_demol","potato_w_engl","potato_w_cm","potato_w_plm","potato_w_sm","potato_w_sf_sm","potato_w_eng","potato_w_demo","potato_w_mine","potato_w_vicc","potato_w_vicd","potato_w_pilot","potato_w_cc","potato_w_helicrew","potato_w_artl","potato_w_artg","potato_e_rifleman","potato_e_rifleman_02","potato_e_rifleman_03","potato_e_rifleman_04","potato_e_sf_rifleman","potato_e_sf_rifleman_02","potato_e_sniper","potato_e_aar","potato_e_sf_aar","potato_e_mmgag","potato_e_hmgag","potato_e_matag","potato_e_hatag","potato_e_msamag","potato_e_mtrag","potato_e_mtrg","potato_e_spotter","potato_e_ar","potato_e_sf_ar","potato_e_mmgg","potato_e_hmgg","potato_e_lat","potato_e_sf_lat","potato_e_matg","potato_e_hatg","potato_e_msamg","potato_e_coy","potato_e_xo","potato_e_uav","potato_e_fac","potato_e_plt","potato_e_sgt","potato_e_sl","potato_e_sf_sl","potato_e_mmgl","potato_e_hmgl","potato_e_matl","potato_e_hatl","potato_e_msaml","potato_e_mtrl","potato_e_stl","potato_e_ftl","potato_e_sf_ftl","potato_e_vicl","potato_e_demol","potato_e_engl","potato_e_cm","potato_e_plm","potato_e_sm","potato_e_sf_sm","potato_e_eng","potato_e_demo","potato_e_mine","potato_e_vicc","potato_e_vicd","potato_e_pilot","potato_e_cc","potato_e_helicrew","potato_e_artl","potato_e_artg","potato_i_rifleman","potato_i_rifleman_02","potato_i_rifleman_03","potato_i_rifleman_04","potato_i_sf_rifleman","potato_i_sf_rifleman_02","potato_i_sniper","potato_i_aar","potato_i_sf_aar","potato_i_mmgag","potato_i_hmgag","potato_i_matag","potato_i_hatag","potato_i_msamag","potato_i_mtrag","potato_i_mtrg","potato_i_spotter","potato_i_ar","potato_i_sf_ar","potato_i_mmgg","potato_i_hmgg","potato_i_lat","potato_i_sf_lat","potato_i_matg","potato_i_hatg","potato_i_msamg","potato_i_coy","potato_i_xo","potato_i_uav","potato_i_fac","potato_i_plt","potato_i_sgt","potato_i_sl","potato_i_sf_sl","potato_i_mmgl","potato_i_hmgl","potato_i_matl","potato_i_hatl","potato_i_msaml","potato_i_mtrl","potato_i_stl","potato_i_ftl","potato_i_sf_ftl","potato_i_vicl","potato_i_demol","potato_i_engl","potato_i_cm","potato_i_plm","potato_i_sm","potato_i_sf_sm","potato_i_eng","potato_i_demo","potato_i_mine","potato_i_vicc","potato_i_vicd","potato_i_pilot","potato_i_cc","potato_i_helicrew","potato_i_artl","potato_i_artg","potato_e_rifleman","potato_e_rifleman_02","potato_e_rifleman_03","potato_e_rifleman_04","potato_e_sf_rifleman","potato_e_aar","potato_e_sf_aar","potato_e_mmgag","potato_e_hmgag","potato_e_matag","potato_e_hatag","potato_e_msamag","potato_e_mtrag","potato_e_mtrg","potato_e_ar","potato_e_sf_ar","potato_e_mmgg","potato_e_hmgg","potato_e_matg","potato_e_hatg","potato_e_msamg","potato_e_coy","potato_e_fac","potato_e_plt","potato_e_sl","potato_e_sf_sl","potato_e_sf_ftl","potato_e_mmgl","potato_e_hmgl","potato_e_matl","potato_e_hatl","potato_e_msaml","potato_e_mtrl","potato_e_stl","potato_e_vicl","potato_e_engl","potato_e_cm","potato_e_plm","potato_e_sm","potato_e_sf_sm","potato_e_eng","potato_e_demo","potato_e_vicc","potato_e_vicd","potato_e_pilot","potato_e_cc"
        };
        /*units[] = {
            #include "subStrings\usmc.hpp"
            #include "subStrings\msv.hpp"
            #include "subStrings\air.hpp"
            #include "subStrings\bwc_msv.hpp"
        };*/
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "A3_Characters_F" };
        author = "Potato";
        authors[] = {"Alablm", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEditorSubcategories.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgVehicles.hpp"
#include "CfgGroups.hpp"
