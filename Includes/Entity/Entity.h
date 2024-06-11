#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

#include <Equipment.h>
#include <EquipmentTable.h>
#include <SkillTable.h>
#include <Dice.h>

class Attribute;
class Active;
class Skill;

class Entity {
protected:
    std::string        name;            // Role Name
    Attribute          attribute;       // Attribute
    Attribute          totalAttribute;  // Total Attribute
    Skill              skill;           // Skill
    Skill              totalSkill;      // Total Skill
    int16_t            lastDamage;      // Last Damage
    Equipment          equipment;	    // Equipment
    Dice               dice;            // Dice
    uint8_t            status;          // Role Status
    uint8_t            eventID;         // Current Event
    bool               faction;         // 0:ROLE 1:ENEMY

public:
    Entity();
    Entity(std::string name);
    Entity(std::string name, bool faction);

    void SetName(const std::string& name) { this->name = name; }
    void SetAttribute(const Attribute& attribute) { this->attribute = attribute; this->totalAttribute = attribute; }
    void SetSkill(const Skill& skill) { this->skill = skill; this->totalSkill = skill; }
    void SetEquipment(const Equipment& equipment) { this->equipment = equipment; }
    void SetDice(const Dice& dice) { this->dice = dice; }
    void SetStatus(const uint8_t status) { this->status = status; }
    void SetEventID(const uint8_t eventID) { this->eventID = eventID; }
    void SetlastDamage(const int16_t lastDamage) { this->lastDamage = lastDamage; }
    void SetFaction(const bool faction) { this->faction = faction; }

    std::string         GetName(void) { return name; }
    Attribute&          GetAttribute(void) { return attribute; }
    Skill&              GetSkill(void) { return skill; }
    Equipment           GetEquipment(void) { return equipment; }
    Dice&               GetDice(void) { return dice; }
    uint8_t             GetStatus(void) { return status; }
    uint8_t             GetEventID(void) { return eventID; }
    int16_t             GetlastDamage(void) { return lastDamage; }
    bool                GetFaction(void) { return faction; }

    Attribute&          GetTotalAttribute(void) { return totalAttribute; }
    Skill&              GetTotalSkill(void) { return totalSkill; }

    void                renewPlayer(void);
    void                decreaseTick(void);


public:
    // Find the Enemy in Range
    bool isInRange(std::vector<Entity*>);
    // 直接強制用set套上裝備，沒有在跟你把裝備拿下來的
    void equipForce(std::string equipmentName);
    void unEquipForce(std::string equipmentName);
    // Skill 實做
    void useActive(std::string skillName, std::vector<Entity*> targets);
    void usePassive(std::string skillName, std::vector<Entity*> targets);
    void useBuff(std::string skillName);
    void addBuff(std::string skillName, uint8_t round);
    void removeBuff(std::string skillName);
    bool findAvailablePassive(std::string skillName);
    bool findAvailableBuff(std::string skillName);
    // 計算經過一切計算後受到的傷害(直接傳原始傷害進來就好)
    void takeDamage(int16_t damage, char attackType);
    void takeTrueDamage(int16_t damage);
    // 顯示玩家資訊
    void displayTotalSkill(void);
    void clearBuff(void);
    void clearTick(void);
    // 直接受到的治療數值
    void heal(int16_t heal);
};

#endif