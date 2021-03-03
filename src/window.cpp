#include "window.h"

#include <iostream>

void centerWindow(GLFWwindow *window, GLFWmonitor *monitor) {
    if (!monitor) {
        return;
    }

    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    if (!mode) {
        return;
    }

    int monitorX, monitorY;
    glfwGetMonitorPos(monitor, &monitorX, &monitorY);

    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    glfwSetWindowPos(window,
                     monitorX + (mode->width - windowWidth) / 2,
                     monitorY + (mode->height - windowHeight) / 2);
}

Window::Window(const char *title, int width, int height)
: title(title), width(width), height(height) {
    if (glfwInit() != GLFW_TRUE) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (!window) {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    centerWindow(window, glfwGetPrimaryMonitor());

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(-1);
    }
}
