#include <smart-home-dashboard/gui/mainGui.hpp>

mainGui::mainGui(int argc, char* argv[], int height, int width) {
    // Constructor
    this->argc = argc;
    this->argv = argv;
    this->height = height;
    this->width = width;
}

int mainGui::run() {
    QApplication app(argc, argv);  // Create a QApplication object

    QMainWindow window;
    window.setWindowTitle("Smart Home Dashboard");
    window.resize(height, width);  // Set the window's size
    window.show();  // Show the main GUI window

    QPushButton button("Quit", &window);
    button.setGeometry(height - 75, width - 25, 50, 25);  // Set the button's geometry
    button.show();  // Show the button

    return app.exec();  // Start the event loop
}
