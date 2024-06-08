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
public:
    // Buy Item from Shop
    void BuyItem(Role*);
};

#endif