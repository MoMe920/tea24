#include "version/version.h"

const char* projectName() {
    return "tea24";
}

int major() {
    return 0;
}

int minor() {
    return 0;
}

int patch() {
    return 1;
}

std::string fullVersion() {
    return std::string(projectName()) + "-" + 
           std::to_string(major()) + "." + 
           std::to_string(minor()) + "." + 
           std::to_string(patch());
}