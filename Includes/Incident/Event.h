#include "../HeaderPack.h"

class Event {
private:
    // ...

public:
    // Attack Event
    int Attack(Entity*, std::vector<Entity*>);

    // Flee Event
    int Flee(std::vector<Entity*>);

    // Random Event
    int Random(std::vector<Entity*>, std::vector<Entity*>);
};