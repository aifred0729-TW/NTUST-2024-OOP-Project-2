#ifndef FILE_H
#define FILE_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <windows.h>

class Role;
class Enemy;

class File {
private:
    std::fstream FileStream;

public:
    //File(std::string);
    // 
    //std::fstream GetFileStream(void);
    //void SetFileStream(const std::fstream&);

public:
    // Load Role from File
    void LoadRole(Role&);

    // Load Enemy from File
    void LoadEnemy(Enemy&);
};

#endif