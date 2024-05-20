#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

#include <Role.h>

class Interactive {
private:
    Role *role;

public:
    void SetRole(Role*);
    Role* GetRole(void);

public:
    // Role Trigger Event
    void TriggeredBy(Role*);
};

#endif