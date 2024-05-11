#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include "Role.h"

class Interactive {
private:
    Role* role;

public:
    // Role Trigger Event
    void TriggeredBy(Role*);
};