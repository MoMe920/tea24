#include <fmt/core.h>
#include "version/version.h"

int main() {
    // Versionsinfos über die Bibliothek abrufen und mit {fmt} ausgeben
    fmt::print("Project: {}\n", projectName());
    fmt::print("Version: {}.{}.{}\n", major(), minor(), patch());
    fmt::print("Full: {}\n", fullVersion());

    return 0;
}