#include "../HeaderPack.h"

class Game {
private:
    std::vector<Role*> movePriority; // Priority of Character Movement
    WorldMap* worldMap;              // Map

private:
    int Move(void);
    int GetKeyboard(void);
    int GiveRandomAttribate(void);

    // ...

public:
    // Initialize Game
    int Init(void);
};