#include "EquipmentTable.h"

std::map<std::string, Equipment> EquipmentTable::weaponMap;
std::map<std::string, Equipment> EquipmentTable::armorMap;
std::map<std::string, Equipment> EquipmentTable::accessoryMap;

void EquipmentTable::Initialize() {
    EquipmentTable::WeaponTableInitialize();
    EquipmentTable::ArmorTableInitialize();
    EquipmentTable::AccessoryTableInitialize();
}

void EquipmentTable::WeaponTableInitialize() {
    Skill speedUpSkill("SpeedUp", SkillType::ACTIVE);
    Skill HammerSplashSkill("HammerSplash", SkillType::ACTIVE);
    Skill ProvokeSkill("Provoke", SkillType::ACTIVE);
    Skill ShokeBlastSkill("ShokeBlast", SkillType::ACTIVE);
    Skill HealSkill("Heal", SkillType::ACTIVE);

    Attribute bareHandAttribute;
    std::vector<Skill> bareHandSkills;

    Attribute woodenSwordAttribute;
    woodenSwordAttribute.SetPA(5);
    woodenSwordAttribute.SetACC(10);
    std::vector<Skill> woodenSwordSkills;
    woodenSwordSkills.push_back(speedUpSkill);

    Attribute hammerAttribute;
    hammerAttribute.SetPA(15);
    hammerAttribute.SetACC(-15);
    std::vector<Skill> hammerSkills;    
    hammerSkills.push_back(HammerSplashSkill);
    hammerSkills.push_back(ProvokeSkill);

    Attribute giantHammerAttribute;
    giantHammerAttribute.SetPA(20);
    giantHammerAttribute.SetACC(-15);
    std::vector<Skill> giantHammerSkills;
    giantHammerSkills.push_back(HammerSplashSkill);


    Attribute magicWandAttribute;
    magicWandAttribute.SetMA(10);
    std::vector<Skill> magicWandSkills;
    magicWandSkills.push_back(ShokeBlastSkill);
    magicWandSkills.push_back(HealSkill);

    Attribute ritualSwordAttribute;
    ritualSwordAttribute.SetMA(15);
    std::vector<Skill> ritualSwordSkills;
    ritualSwordSkills.push_back(ShokeBlastSkill);


    Equipment bareHand(bareHandAttribute, bareHandSkills);
    Equipment woodenSword(woodenSwordAttribute, woodenSwordSkills);
    Equipment hammer(hammerAttribute, hammerSkills);
    Equipment giantHammer(giantHammerAttribute, giantHammerSkills);
    Equipment magicWand(magicWandAttribute, magicWandSkills);
    Equipment ritualSword(ritualSwordAttribute, ritualSwordSkills);

    weaponMap["WoodenSword"] = woodenSword;
    weaponMap["BareHand"] = bareHand;
    weaponMap["Hammer"] = hammer;
    weaponMap["GiantHammer"] = giantHammer;
    weaponMap["MagicWand"] = magicWand;
    weaponMap["RitualSword"] = ritualSword;
}

void EquipmentTable::ArmorTableInitialize() {
    Skill ProvokeSkill("Provoke", SkillType::ACTIVE);
    Skill FortitySkill("Fortity", SkillType::ACTIVE);
    Skill LaurelPassiveSkill("LaurelPassive", SkillType::PASSIVE);

	Attribute bareBodyAttribute;
	std::vector<Skill> bareBodySkills;

    Attribute woodenShieldAttribute;
    woodenShieldAttribute.SetPD(10);
    std::vector<Skill> woodenShieldSkills;
    woodenShieldSkills.push_back(ProvokeSkill);

    Attribute plateArmorAttribute;
    plateArmorAttribute.SetPD(20);
    plateArmorAttribute.SetSPD(-10);
    std::vector<Skill> plateArmorSkills;
    plateArmorSkills.push_back(FortitySkill);

    Attribute leatherArmorAttribute;
    leatherArmorAttribute.SetPD(5);
    std::vector<Skill> leatherArmorSkills;
    leatherArmorSkills.push_back(FortitySkill);

    Attribute robeAttribute;
    robeAttribute.SetMD(10);
    std::vector<Skill> robeSkills;

    Attribute laurelWreathAttribute;
    std::vector<Skill> laurelWreathSkills;
    laurelWreathSkills.push_back(LaurelPassiveSkill);

    Equipment bareBody(bareBodyAttribute, bareBodySkills);
    Equipment woodenShield(woodenShieldAttribute, woodenShieldSkills);
    Equipment plateArmor(plateArmorAttribute, plateArmorSkills);
    Equipment leatherArmor(leatherArmorAttribute, leatherArmorSkills);
    Equipment robe(robeAttribute, robeSkills);
    Equipment laurelWreath(laurelWreathAttribute, laurelWreathSkills);

    armorMap["BareBody"] = bareBody;
    armorMap["WoodenShield"] = woodenShield;
    armorMap["PlateArmor"] = plateArmor;
    armorMap["LeatherArmor"] = leatherArmor;
    armorMap["Robe"] = robe;
    armorMap["LaurelWreath"] = laurelWreath;
}

void EquipmentTable::AccessoryTableInitialize() {
    Skill HealSkill("Heal", SkillType::ACTIVE);
    Skill RunSkill("Run", SkillType::ACTIVE);

    Attribute bareAccessoryAttribute;
    std::vector<Skill> bareAccessorySkills;

    Attribute holyGrailAttribute;
    holyGrailAttribute.SetMD(30);
    std::vector<Skill> holyGrailSkills;
    holyGrailSkills.push_back(HealSkill);

    Attribute shoesAttribute;
    shoesAttribute.SetSPD(5);
    std::vector<Skill> shoesSkills;
    shoesSkills.push_back(RunSkill);

    Attribute braceletAttribute;
    braceletAttribute.SetMaxFocus(1);
    std::vector<Skill> braceletSkills;

    Equipment bareAccessory(bareAccessoryAttribute, bareAccessorySkills);
    Equipment holyGrail(holyGrailAttribute, holyGrailSkills);
    Equipment shoes(shoesAttribute, shoesSkills);
    Equipment bracelet(braceletAttribute, braceletSkills);

    accessoryMap["BareAccessory"] = bareAccessory;
    accessoryMap["HolyGrail"] = holyGrail;
    accessoryMap["Shoes"] = shoes;
    accessoryMap["Bracelet"] = bracelet;
}