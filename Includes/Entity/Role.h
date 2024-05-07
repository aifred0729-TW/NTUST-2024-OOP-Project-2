#include "../HeaderPack.h"

class Role : public Entity {
private:
    Item      pack;
    Equipment equipment;
    uint8_t   movementPoint;
    uint32_t  step;
    std::pair<uint32_t, uint32_t> position;

public:
    // ...
};