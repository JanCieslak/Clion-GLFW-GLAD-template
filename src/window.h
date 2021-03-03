#pragma once

#include "GLAD/glad.h"
#include "GLFW/glfw3.h"

class Window {
private:
    GLFWwindow* window;
    const char* title;
    int width, height;

public:
    Window(const char* title, int width, int height);

    inline bool shouldClose() const { return glfwWindowShouldClose(window); }
    inline void clear() const { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
    inline void pollEvents() const { glfwPollEvents(); }
    inline void swapBuffers() const { glfwSwapBuffers(window); }
};