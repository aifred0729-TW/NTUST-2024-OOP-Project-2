#include "EquipmentTable.h"
#include "SkillTable.h"

std::map<std::string, Weapon> EquipmentTable::weaponMap;
std::map<std::string, Armor> EquipmentTable::armorMap;
std::map<std::string, Accessory> EquipmentTable::accessoryMap;

void EquipmentTable::Initialize() {
	EquipmentTable::WeaponTableInitialize();
	EquipmentTable::ArmorTableInitialize();
	EquipmentTable::AccessoryTableInitialize();
}

void EquipmentTable::WeaponTableInitialize() {
	Active SpeedUp = SkillTable::activeMap.find("SpeedUp")->second;
	Passive HammerSplash = SkillTable::passiveMap.find("HammerSplash")->second;
	Active Provoke = SkillTable::activeMap.find("Provoke")->second;
	Active ShockBlast = SkillTable::activeMap.find("ShockBlast")->second;
	Active Heal = SkillTable::activeMap.find("Heal")->second;

	Attribute bareHandAttribute;
	Skill bareHandSkill;

	Attribute woodenSwordAttribute;
	woodenSwordAttribute.SetPA(5);
	woodenSwordAttribute.SetACC(10);
	Skill woodenSwordSkill;
	woodenSwordSkill.pushActive(SpeedUp);

	Attribute hammerAttribute;
	hammerAttribute.SetPA(15);
	hammerAttribute.SetACC(-15);
	Skill hammerSkill;
	hammerSkill.pushPassive(HammerSplash);
	hammerSkill.pushActive(Provoke);

	Attribute giantHammerAttribute;
	giantHammerAttribute.SetPA(20);
	giantHammerAttribute.SetACC(-15);
	Skill giantHammerSkill;
	giantHammerSkill.pushPassive(HammerSplash);


	Attribute magicWandAttribute;
	magicWandAttribute.SetMA(10);
	Skill magicWandSkill;
	magicWandSkill.pushActive(ShockBlast);
	magicWandSkill.pushActive(Heal);

	Attribute ritualSwordAttribute;
	ritualSwordAttribute.SetMA(15);
	Skill ritualSwordSkill;
	ritualSwordSkill.pushActive(ShockBlast);

	weaponMap["BareHand"] = Weapon("BareHand", bareHandAttribute, bareHandSkill, 1, 'P');
	weaponMap["WoodenSword"] = Weapon("WoodenSword", woodenSwordAttribute, woodenSwordSkill, 3, 'P');
	weaponMap["Hammer"] = Weapon("Hammer", hammerAttribute, hammerSkill, 4, 'P');
	weaponMap["GiantHammer"] = Weapon("GiantHammer", giantHammerAttribute, giantHammerSkill, 5, 'P');
	weaponMap["MagicWand"] = Weapon("MagicWand", magicWandAttribute, magicWandSkill, 3, 'M');
	weaponMap["RitualSword"] = Weapon("RitualSword", ritualSwordAttribute, ritualSwordSkill, 1, 'M');
}

void EquipmentTable::ArmorTableInitialize() {
	Active Provoke = SkillTable::activeMap.find("Provoke")->second;
	Passive Fortify = SkillTable::passiveMap.find("Fortify")->second;
	Buff LaurelBuff = SkillTable::buffMap.find("LaurelBuff")->second;

	Attribute bareBodyAttribute;
	Skill bareBodySkill;

	Attribute woodenShieldAttribute;
	woodenShieldAttribute.SetPD(10);
	Skill woodenShieldSkill;
	woodenShieldSkill.pushActive(Provoke);

	Attribute plateArmorAttribute;
	plateArmorAttribute.SetPD(20);
	plateArmorAttribute.SetSPD(-10);
	Skill plateArmorSkill;
	plateArmorSkill.pushPassive(Fortify);

	Attribute leatherArmorAttribute;
	leatherArmorAttribute.SetPD(5);
	Skill leatherArmorSkill;
	leatherArmorSkill.pushPassive(Fortify);

	Attribute robeAttribute;
	robeAttribute.SetMD(10);
	Skill robeSkill;

	Attribute laurelWreathAttribute;
	Skill laurelWreathSkill;
	laurelWreathSkill.pushBuff(LaurelBuff);

	armorMap["BareBody"] = Armor("BareBody", bareBodyAttribute, bareBodySkill);
	armorMap["WoodenShield"] = Armor("WoodenShield", woodenShieldAttribute, woodenShieldSkill);
	armorMap["PlateArmor"] = Armor("PlateArmor", plateArmorAttribute, plateArmorSkill);
	armorMap["LeatherArmor"] = Armor("LeatherArmor", leatherArmorAttribute, leatherArmorSkill);
	armorMap["Robe"] = Armor("Robe", robeAttribute, robeSkill);
	armorMap["LaurelWreath"] = Armor("LaurelWreath", laurelWreathAttribute, laurelWreathSkill);
}

void EquipmentTable::AccessoryTableInitialize() {
	Active Heal = SkillTable::activeMap.find("Heal")->second;
	Passive Run = SkillTable::passiveMap.find("Run")->second;

	Attribute bareAccessoryAttribute;
	Skill bareAccessorySkill;

	Attribute holyGrailAttribute;
	holyGrailAttribute.SetMD(30);
	Skill holyGrailSkill;
	holyGrailSkill.pushActive(Heal);

	Attribute shoesAttribute;
	shoesAttribute.SetSPD(5);
	Skill shoesSkill;
	shoesSkill.pushPassive(Run);

	Attribute braceletAttribute;
	braceletAttribute.SetMaxFocus(1);
	Skill braceletSkill;

	accessoryMap["BareAccessory"] = Accessory("BareAccessory", bareAccessoryAttribute, bareAccessorySkill);
	accessoryMap["HolyGrail"] = Accessory("HolyGrail", holyGrailAttribute, holyGrailSkill);
	accessoryMap["Shoes"] = Accessory("Shoes", shoesAttribute, shoesSkill);
	accessoryMap["Bracelet"] = Accessory("Bracelet", braceletAttribute, braceletSkill);
}