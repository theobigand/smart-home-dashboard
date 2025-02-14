#include <iostream>
#include "mainGui.h"


int main(int argc, char *argv[]) {
    mainGui gui(argc, argv, 1200, 800);
    return gui.run();
}