#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <cstdint>
#include <ConstData.h>

// itemTable[COIN]();
// Used COIN¡Acorresponding to ApplyCoin function
// #include <vector>

class Role;

class Item {
private:
    static std::vector<std::pair<int, int>> items;          // ItemID / Counts (need initialize)
    static void (* const itemTable[ITEM_TOTAL_SIZE])(void); // ItemTable (need initialize¡Ffunction of ApplyXXX)

private:
    static void ApplyCoin(void);           // Use Coin
    static void ApplyGodsBeard(void);      // Use GodsBeard
    static void ApplyTent(void);           // Use Tent
    static void ApplyTeleportScroll(void); // Use Teleport Scroll
    static void ApplyGoldenRoot(void);     // Use Golden Root
    static void ApplyXXX111(void);         // Use Custom Item 1
    static void ApplyXXX222(void);         // Use Custom Item 2
    static void ApplyXXX333(void);         // Use Custom Item 3

    // ...

private:
    // Log who will use backpack
    std::vector<Role*> packUsers;

public:
    // Use Item to XXX Role
    void ApplyItemTo(uint8_t, std::vector<Role*>);
};

#endif