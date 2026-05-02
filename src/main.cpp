// main.cpp
// Entry point. Stroustrup, *The C++ Programming Language*, Ch. 15 §15.4:
// main() must be a global function — no namespace.

// In iteration 1, all our work happens in the Vault and Credential classes,
// which are exercised by the test suite (see tests/). This main() exists
// only so CMake has something to build for the main executable.
//
// Later iterations will replace this with the Qt application bootstrap:
//   QApplication app(argc, argv);
//   MainWindow window;
//   window.show();
//   return app.exec();
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hello from the project template.\n";
    return 0;
}
