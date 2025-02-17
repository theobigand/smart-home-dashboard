#include <iostream>
#include <smart-home-dashboard/gui/mainGui.hpp>


int main(int argc, char *argv[]) {
    mainGui gui(argc, argv, 1200, 800);
    return gui.run();
}