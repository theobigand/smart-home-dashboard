#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>


class MainGui{
protected:
    int argc;
    char** argv;
    int height;
    int width;

public:
    MainGui(int argc, char* argv[], int height, int width);
    int run();
};