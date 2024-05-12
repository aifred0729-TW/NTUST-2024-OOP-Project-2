#ifndef EVENT_H
#define EVENT_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include <Entity.h>

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

#endif