#include "Equipment.h"

#include <vector>
#include <unordered_set>
#include <algorithm>

Equipment::Equipment() {
    Attribute attribute;
    this->weaponAttribute = attribute;
    this->armorAttribute = attribute;
	this->accessoryAttribute = attribute;
    std::vector<Skill> skills;
    this->weaponSkills = skills;
    this->armorSkills = skills;
	this->accessorySkills = skills;
}

Equipment::Equipment(Attribute attribute, std::vector<Skill> skills)
    : weaponAttribute(attribute), armorAttribute(attribute), accessoryAttribute(attribute),
	  weaponSkills(skills), armorSkills(skills), accessorySkills(skills) {}

Attribute Equipment::GetAdditionalAttribute() const {
    Attribute attribute;
    attribute += weaponAttribute;
    attribute += armorAttribute;
	attribute += accessoryAttribute;
    return attribute;
}

std::vector<Skill> Equipment::GetAdditionalSkills() const {
	struct SkillEqual {
		bool operator()(const Skill& lhs, const Skill& rhs) const {
			return lhs.GetName() == rhs.GetName();
		}
	};

	struct SkillHash {
		std::size_t operator()(const Skill& skill) const {
			return std::hash<std::string>()(skill.GetName());
		}
	};

	std::unordered_set<Skill, SkillHash, SkillEqual> uniqueSkills;
	std::vector<Skill> skills;
	auto addSkills = [&uniqueSkills, &skills](const std::vector<Skill>& newSkills) {
		for (const auto& skill : newSkills) {
			if (uniqueSkills.insert(skill).second) {
				skills.push_back(skill);
			}
		}
		};

	addSkills(weaponSkills);
	addSkills(armorSkills);
	addSkills(accessorySkills);

	return skills;
}

void Equipment::SetWeaponAttribute(const Attribute& weaponAttribute) {
	this->weaponAttribute = weaponAttribute;
}

void Equipment::SetArmorAttribute(const Attribute& armorAttribute) {
	this->armorAttribute = armorAttribute;
}

void Equipment::SetAccessoryAttribute(const Attribute& accessoryAttribute) {
	this->accessoryAttribute = accessoryAttribute;
}

void Equipment::SetWeaponSkills(const std::vector<Skill>& weaponSkills) {
	this->weaponSkills = weaponSkills;
}

void Equipment::SetArmorSkills(const std::vector<Skill>& armorSkills) {
	this->armorSkills = armorSkills;
}

void Equipment::SetAccessorySkills(const std::vector<Skill>& accessorySkills) {
	this->accessorySkills = accessorySkills;
}

Attribute Equipment::GetWeaponAttribute() const {
	return weaponAttribute;
}

Attribute Equipment::GetArmorAttribute() const {
	return armorAttribute;
}

Attribute Equipment::GetAccessoryAttribute() const {
	return accessoryAttribute;
}

std::vector<Skill> Equipment::GetWeaponSkills() const {
	return weaponSkills;
}

std::vector<Skill> Equipment::GetArmorSkills() const {
	return armorSkills;
}

std::vector<Skill> Equipment::GetAccessorySkills() const {
	return accessorySkills;
}