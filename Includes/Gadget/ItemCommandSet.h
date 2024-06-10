#ifndef ITEMCOMMANDSET_H
#define ITEMCOMMANDSET_H

#include "ItemCommand.h"

class GodsbeardCommand : public ItemCommand {
public:
    void use(Role& role) override;
};

class GoldenRootCommand : public ItemCommand {
public:
    void use(Role& role) override;
};

class TeleportScrollCommand : public ItemCommand {
public:
    void use(Role& role) override;
};

class TentCommand : public ItemCommand {
public:
    void use(Role& role) override;
};

#endif
