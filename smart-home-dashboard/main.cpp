#include <iostream>
#include <smart-home-dashboard/include/gui/MainGui.hpp>


int main(int argc, char *argv[]) {
    MainGui gui(argc, argv, 1200, 800);
    return gui.run();
}