#include "Control/WorldMap.h"
#include <Process.h>
#include <string>

int main() {
    WorldMap w("W-1.txt");
    w.SetFog(21, 50);

    return 0;
}
