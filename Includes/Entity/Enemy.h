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
public:
	Enemy();
	Enemy(std::string name);
};

#endif