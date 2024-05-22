#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <cstdint>
#include <vector>
#include <set>
#include "Attribute.h"
#include "Skill.h"

class Equipment {
private:
    Attribute weaponAttribute;
    Attribute armorAttribute;
    Attribute accessoryAttribute;
    std::vector<Skill> weaponSkills;
    std::vector<Skill> armorSkills;
    std::vector<Skill> accessorySkills;

public:
    Equipment();  // Default constructor
    Equipment(Attribute, std::vector<Skill>);

    void SetWeaponAttribute(const Attribute&);
    void SetArmorAttribute(const Attribute&);
    void SetWeaponSkills(const std::vector<Skill>&);
    void SetArmorSkills(const std::vector<Skill>&);
    void SetAccessoryAttribute(const Attribute&);
    void SetAccessorySkills(const std::vector<Skill>&);

    Attribute GetWeaponAttribute() const;
    Attribute GetArmorAttribute() const;
    Attribute GetAccessoryAttribute() const;
    std::vector<Skill> GetWeaponSkills() const;
    std::vector<Skill> GetArmorSkills() const;
    std::vector<Skill> GetAccessorySkills() const;

public:
    Attribute GetAdditionalAttribute() const;
    std::vector<Skill> GetAdditionalSkills() const;
};

#endif
