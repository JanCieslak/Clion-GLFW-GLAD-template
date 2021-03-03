#include "window.h"

int main() {
    Window window {"", 800, 600 };

    while (!window.shouldClose()) {
        window.clear();
        window.pollEvents();


        window.swapBuffers();
    }
}
