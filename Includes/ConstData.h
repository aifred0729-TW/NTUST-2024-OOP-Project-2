#ifndef CONST_DATA_H
#define CONST_DATA_H

#include "HeaderPack.h"

#define BANNER = \
R"(
      ___           ___           ___                    ___           ___           ___                    ___                       ___           ___                        
     /\  \         /\  \         /\  \                  /\  \         /\__\         /\  \                  /\__\          ___        /\__\         /\  \                       
    /::\  \       /::\  \       /::\  \                 \:\  \       /:/  /        /::\  \                /:/  /         /\  \      /::|  |       /::\  \                      
   /:/\:\  \     /:/\:\  \     /:/\:\  \                 \:\  \     /:/__/        /:/\:\  \              /:/__/          \:\  \    /:|:|  |      /:/\:\  \                     
  /::\~\:\  \   /:/  \:\  \   /::\~\:\  \                /::\  \   /::\  \ ___   /::\~\:\  \            /::\__\____      /::\__\  /:/|:|  |__   /:/  \:\  \                    
 /:/\:\ \:\__\ /:/__/ \:\__\ /:/\:\ \:\__\              /:/\:\__\ /:/\:\  /\__\ /:/\:\ \:\__\          /:/\:::::\__\  __/:/\/__/ /:/ |:| /\__\ /:/__/_\:\__\                   
 \/__\:\ \/__/ \:\  \ /:/  / \/_|::\/:/  /             /:/  \/__/ \/__\:\/:/  / \:\~\:\ \/__/          \/_|:|~~|~    /\/:/  /    \/__|:|/:/  / \:\  /\ \/__/                   
      \:\__\    \:\  /:/  /     |:|::/  /             /:/  /           \::/  /   \:\ \:\__\               |:|  |     \::/__/         |:/:/  /   \:\ \:\__\                     
       \/__/     \:\/:/  /      |:|\/__/              \/__/            /:/  /     \:\ \/__/               |:|  |      \:\__\         |::/  /     \:\/:/  /                     
                  \::/  /       |:|  |                                /:/  /       \:\__\                 |:|  |       \/__/         /:/  /       \::/  /                      
                   \/__/         \|__|                                \/__/         \/__/                  \|__|                     \/__/         \/__/                       
      ___           ___           ___           ___           ___                    ___           ___           ___           ___                       ___           ___     
     /\__\         /\  \         /\__\         /\  \         /\  \                  /\__\         /\  \         /\  \         /\  \          ___        /\  \         /\__\    
    /::|  |        \:\  \       /:/  /        /::\  \        \:\  \                /:/  /        /::\  \       /::\  \       /::\  \        /\  \      /::\  \       /::|  |   
   /:|:|  |         \:\  \     /:/  /        /:/\ \  \        \:\  \              /:/  /        /:/\:\  \     /:/\:\  \     /:/\ \  \       \:\  \    /:/\:\  \     /:|:|  |   
  /:/|:|  |__       /::\  \   /:/  /  ___   _\:\~\ \  \       /::\  \            /:/__/  ___   /::\~\:\  \   /::\~\:\  \   _\:\~\ \  \      /::\__\  /:/  \:\  \   /:/|:|  |__ 
 /:/ |:| /\__\     /:/\:\__\ /:/__/  /\__\ /\ \:\ \ \__\     /:/\:\__\           |:|  | /\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /\ \:\ \ \__\  __/:/\/__/ /:/__/ \:\__\ /:/ |:| /\__\
 \/__|:|/:/  /    /:/  \/__/ \:\  \ /:/  / \:\ \:\ \/__/    /:/  \/__/           |:|  |/:/  / \:\~\:\ \/__/ \/_|::\/:/  / \:\ \:\ \/__/ /\/:/  /    \:\  \ /:/  / \/__|:|/:/  /
     |:/:/  /    /:/  /       \:\  /:/  /   \:\ \:\__\     /:/  /                |:|__/:/  /   \:\ \:\__\      |:|::/  /   \:\ \:\__\   \::/__/      \:\  /:/  /      |:/:/  / 
     |::/  /     \/__/         \:\/:/  /     \:\/:/  /     \/__/                  \::::/__/     \:\ \/__/      |:|\/__/     \:\/:/  /    \:\__\       \:\/:/  /       |::/  /  
     /:/  /                     \::/  /       \::/  /                              ~~~~          \:\__\        |:|  |        \::/  /      \/__/        \::/  /        /:/  /   
     \/__/                       \/__/         \/__/                                              \/__/         \|__|         \/__/                     \/__/         \/__/    
)"

enum MODE {
	ROLE,
	ENEMY,
};

enum SKILL_TYPE {
	ATTACK,       // Attack
	FLEE,         // Flee
	PROVOKE,      // Provoke
	SHOCKBLAST,   // Shock Blast
	HEAL,         // Healing
	SPEEDUP,   	  // Speed Up
	RUN,	      // Use Physical Power to Roll Dice
	HAMMERSPLASH, // Hammer Splash
	DESTORY,      // Destory
	FORTIFY,      // Foritfy
	SKILL111,     // Custom Skill 1
	SKILL222,     // Custom Skill 2
	SKILL333,     // Custom Skill 3
	SKILL_TOTAL_SIZE
};

enum WEAPON_TYPE {
	HAND,
	WOODEN_SWORD,
	HAMMER,
	GIANT_HAMMER,
	MAGIC_WAND,
	RITUAL_SWORD
};  // Weapon Type

enum ARMOR_TYPE {
	WOODEN_SHIELD,
	PLATE_ARMOR,
	LEATHER_ARMOR,
	ROBE,
	LAUREL_WREATH
};  // Armor Type

enum ACCESSORY_TYPE
{
	HOLY_GRAIL,
	SHOES,
	BRACELET,
};  // Accessory Type

enum ITEM_TYPE
{
	COIN,
	GOD_BEARD,
	GOLDGEN_ROOT,
	TELEPORT_SCROLL,
	TENT,
	XXX111, // Custom Item 1
	XXX222, // Custom Item 2
	XXX333, // Custom Item 3
	ITEM_TOTAL_SIZE
};  // Item Type

enum STATUS_TYPE
{
	DEAD = 0x1,
	POISONED = 0x2,
	BLEED = 0x4,
	DIZZINESS = 0x8,
	ANGRY = 0x10,
	RETREAT = 0x20,
};  // Status Type

#endif