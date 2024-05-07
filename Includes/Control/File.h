#include "../HeaderPack.h"

class File
{
private:
    std::fstream FileStream;

public:
    // Load Map from File
    void LoadWorldMap(WorldMap&);

    // Load Role from File
    void LoadRole(Role&);

    // Load Enemy from File
    void LoadEnemy(Enemy&);

    // ...
};