#ifndef TENT_H
#define TENT_H

#include <vector>
#include <windows.h>

#include <Interactive.h>

class Role;

class Tent : public Interactive {
private:
    std::string name;
    std::pair<uint32_t, uint32_t> position;
    int duration;
public:
    Tent(std::string name, std::pair<uint32_t, uint32_t> position);
    Tent(std::string name, uint32_t x, uint32_t y);
    Tent(std::string name, uint32_t x, uint32_t y, int duration);
public:

    std::string GetName(void) const;
    std::pair<uint32_t, uint32_t> GetPosition(void) const;
    int GetDuration() { return duration; }

    void SetTent(Role*);
    void Recover(Role*);
    bool timePass();
};

#endif 