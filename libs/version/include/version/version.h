#ifndef VERSION_H
#define VERSION_H

#include <string> // Notwendig, da std::string in den Funktionsdeklarationen verwendet wird

const char* projectName();
int major();
int minor();
int patch();
std::string fullVersion();

#endif // VERSION_H