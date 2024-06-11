#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <cstdint>
#include <vector>
#include <set>

#include <EquipmentBase.h>

class Skill;
class Weapon;
class Armor;
class Accessory;
class Attribute;

class Equipment {
private:
    Weapon weapon;
    Armor armor;
    Accessory accessory;

public:
    Equipment();

    void SetWeapon(const Weapon&);
    void SetArmor(const Armor&);
    void SetAccessory(const Accessory&);

    Weapon GetWeapon() const;
    Armor GetArmor() const;
    Accessory GetAccessory() const;

public:
    Attribute GetTotalAttribute() const;
    Skill& GetTotalSkills() ;
};

#endif
