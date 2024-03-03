//
// pch.cpp
//

#include "pch.h"

#define STRINGIFY(x) #x

#define EXPAND(x) STRINGIFY(x)

string projectDir;

string getProjectDir() {
    if (!projectDir.empty())
        return projectDir;
    string s = EXPAND(UNITTESTPRJ);
    s.erase(0, 1); // erase the first quote
    s.erase(s.size() - 2); // erase the last quote and the dot
    projectDir = s;
    return projectDir;
}