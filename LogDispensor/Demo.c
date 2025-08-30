#include <stdio.h>
#include "Logger.h"

int main(int argc, char const *argv[]) {
    SetPrintLevel(DEBUG);
    SetPrintTime(true);
    SetCreateFile(true);
    SetLogfilePath("Log2.txt");

    Debug("Hello, World");
    Message("Hello, World");
    Warning("Hello, World");
    Error("Hello, World");
    Pass("Hello, World");

    return 0;
}
