#ifndef ITEMCOMMAND_H
#define ITEMCOMMAND_H

#include <vector>

class Role;

class ItemCommand {
public:
    virtual ~ItemCommand() = default;
    virtual void use(Role& role) {};
};

#endif
