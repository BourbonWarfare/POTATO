class ace_medical_treatment_actions {
    class BasicBandage;
    class ApplyTourniquet: BasicBandage {
        sounds[] = {{"x\POTATO\addons\miscMedical\data\tourniquet.ogg",5,1,50}};
    };
    class Splint: BasicBandage {
        sounds[] = {{"x\POTATO\addons\miscMedical\data\splint.ogg",5,1,50}};
    };
    class Diagnose: BasicBandage {
        sounds[] = {{"x\POTATO\addons\miscMedical\data\diag.ogg",5,1,50}};
    };
};