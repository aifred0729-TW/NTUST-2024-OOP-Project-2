#include "../../Includes/Display/Process.h"

#include <skill.h>
#include <Entity.h>

int Process::HandlePreBattle(std::vector<Entity*>, std::vector<Entity*>) {
    return 0;
}

int Process::HandleMemu(void) {
    return 0;
}

int Process::Handle(std::vector<std::pair<int, int>>*) {
    return 0;
}

int Process::Handle(std::vector<Dice*>) {
    return 0;
}

int Process::Handle(std::vector<Entity*>) {
    return 0;
}

int Process::Handle(Field*) {
    return 0;
}

int Process::Handle(Store*) {
    return 0;
}

int Process::Handle(Interactive*) {
    return 0;
}