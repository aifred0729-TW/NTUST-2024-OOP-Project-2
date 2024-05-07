#include "../HeaderPack.h"

class UI {
private:
    std::stack<std::vector<std::vector<char>>> prevPicture;
    WorldMap* worldMapPoac;
    Field* fieldPointer;

public:
    // Prepare Battle
    int PreBattle(std::vector<Entity*>, std::vector<Entity*>);

    // Display Menu
    int ShowMenu(void);

    // Display Backpack
    int Display(std::vector<std::pair<int, int>>*);

    // Display Dice
    int Display(std::vector<Dice*>);

    // Display Information of Roles
    int Display(std::vector<Entity*>);

    // Display Battle Status
    int Display(Field*);

    // Display Shops
    int Display(Store*);

    // Display Interactive Objects
    int Display(Interactive*);

    // Relocation Map to Roles¡Aand Make it the Center Point Shows Part of Map
    int ReLocation(Entity*);

    // ...
};