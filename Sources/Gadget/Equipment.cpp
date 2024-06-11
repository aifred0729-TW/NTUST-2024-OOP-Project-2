#include <vector>
#include <unordered_set>
#include <algorithm>

#include <Equipment.h>
#include <EquipmentBase.h>
#include <EquipmentTable.h>
#include <Attribute.h>
#include <Skill.h>

Equipment::Equipment() {
	armor = Armor();
	accessory = Accessory();
	weapon = Weapon();
}

Attribute Equipment::GetTotalAttribute() const {
	Attribute attribute;
	attribute += weapon.GetAttribute();
	attribute += armor.GetAttribute();
	attribute += accessory.GetAttribute();
	return attribute;
}

Skill& Equipment::GetTotalSkills() {
	Skill skill;
	skill += weapon.GetSkill();
	skill += armor.GetSkill();
	skill += accessory.GetSkill();
	return skill;
}

void Equipment::SetWeapon(const Weapon& weapon) {
	this->weapon = weapon;
}

void Equipment::SetArmor(const Armor& armor) {
	this->armor = armor;
}

void Equipment::SetAccessory(const Accessory& accessory) {
	this->accessory = accessory;
}

Weapon Equipment::GetWeapon() const {
	return weapon;
}

Armor Equipment::GetArmor() const {
	return armor;
}

Accessory Equipment::GetAccessory() const {
	return accessory;
}