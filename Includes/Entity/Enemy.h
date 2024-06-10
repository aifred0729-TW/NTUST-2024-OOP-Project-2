#ifndef ENEMY_H
#define ENEMY_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include <Interactive.h>

class Enemy : public Entity, public Interactive {
private:
    std::pair<uint32_t, uint32_t> position;
public:
    Enemy();
    Enemy(std::string name);
    Enemy(std::string name, int x, int y);

    void SetPosition(const std::pair<uint32_t, uint32_t>&);
    std::pair<uint32_t, uint32_t> GetPosition(void);

};

#endif