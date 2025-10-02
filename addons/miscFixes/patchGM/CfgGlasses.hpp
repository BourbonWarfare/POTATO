#define PROMOTE_SCOPE(classname,parent) class classname: parent {\
    scope = 2;\
}

class CfgGlasses {
    class gm_scrin_helmetcamo_base;
    PROMOTE_SCOPE(gm_headgear_foliage_summer_grass_01,gm_scrin_helmetcamo_base);
    class gm_gasmask_base;
    PROMOTE_SCOPE(gm_gc_army_facewear_schm41m,gm_gasmask_base);
    PROMOTE_SCOPE(gm_ge_facewear_m65,gm_gasmask_base);
    class gm_glasses_base;
    PROMOTE_SCOPE(gm_gc_army_facewear_dustglasses,gm_glasses_base);
    PROMOTE_SCOPE(gm_ge_facewear_dustglasses,gm_glasses_base);
    PROMOTE_SCOPE(gm_ge_facewear_dustglasses_relaxed,gm_glasses_base);
    PROMOTE_SCOPE(gm_ge_facewear_sunglasses,gm_glasses_base);
    PROMOTE_SCOPE(gm_ge_facewear_acidgoggles,gm_glasses_base);
    PROMOTE_SCOPE(gm_ge_facewear_glacierglasses,gm_glasses_base);
    class gm_balaclava_base;
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_blk,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_blu,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_flk,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_frog,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_grn,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_gry,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_m84,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_moro,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_oli,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_pt1,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_pt2,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_pt3,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_red,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_str,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_trp,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_01_wht,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_02_blk,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_02_grn,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_02_oli,gm_balaclava_base);
    PROMOTE_SCOPE(gm_xx_facewear_scarf_02_wht,gm_balaclava_base);
    class gm_ge_facewear_stormhood_base: gm_balaclava_base {};
    PROMOTE_SCOPE(gm_ge_facewear_stormhood_blk,gm_ge_facewear_stormhood_base);
    PROMOTE_SCOPE(gm_ge_facewear_stormhood_brd,gm_ge_facewear_stormhood_base);
    PROMOTE_SCOPE(gm_ge_facewear_stormhood_dustglasses_blk,gm_ge_facewear_stormhood_base);
};
