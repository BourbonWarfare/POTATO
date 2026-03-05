#define REPLACE_DAMAGE_CLASSES class Laceration {\
    weighting[] = {{20,10},{4,1},{0.3,1},{0,0}};\
}

class ACE_Medical_Injuries {
    class damageTypes {
        class bullet {
            delete Contusion;
            REPLACE_DAMAGE_CLASSES;
        };
        class grenade {
            delete Contusion;
            REPLACE_DAMAGE_CLASSES;
        };
        class explosive {
            delete Contusion;
            REPLACE_DAMAGE_CLASSES;
        };
        class shell {
            delete Contusion;
            REPLACE_DAMAGE_CLASSES;
        };
        class vehiclecrash {
            delete Abrasion;
            REPLACE_DAMAGE_CLASSES;
            delete Contusion;
        };
        class collision {
            delete Abrasion;
            delete Contusion;
            REPLACE_DAMAGE_CLASSES;
        };
        class falling {
            delete Abrasion;
            delete Contusion;
            REPLACE_DAMAGE_CLASSES;
        };
        class backblast {
            delete Contusion;
            REPLACE_DAMAGE_CLASSES;
        };
        class punch {
            delete Contusion;
            REPLACE_DAMAGE_CLASSES;
        };
        class ropeburn {
            delete Abrasion;
            REPLACE_DAMAGE_CLASSES;
        };
        class burn {
            delete ThermalBurn;
            REPLACE_DAMAGE_CLASSES;
        };
        class unknown {
            delete Abrasion;
            REPLACE_DAMAGE_CLASSES;
        };
    };
};
