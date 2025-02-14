#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>


class mainGui{
private:
    int argc;
    char** argv;
    int height;
    int width;

public:
    mainGui(int argc, char* argv[], int height, int width);
    int run();
};