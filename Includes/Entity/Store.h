#ifndef STORE_H
#define STORE_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include <Interactive.h>

class Store : public Interactive {
private:
    std::string name;
    std::pair<int, int> position;
public:
    Store(std::string name, std::pair<int, int> position);
    Store(std::string name, int x, int y);
public:

    std::string GetName(void) const;
    std::pair<int, int> GetPosition(void) const;

    // Buy Item from Shop
    void SellItemTo(Role*);
    void SellItemTo();
};

#endif