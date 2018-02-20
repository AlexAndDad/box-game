//
// Created by ahodges on 20/02/18.
//

#include "DisplayController.h"


DisplayController::DisplayController()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
    SCR_WIDTH  = glfwGetVideoMode(glfwGetPrimaryMonitor())->width;
    SCR_HEIGHT = glfwGetVideoMode(glfwGetPrimaryMonitor())->height;
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "BoxGame", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window";
        glfwTerminate();
    }
    else {
        glfwMakeContextCurrent(window);
    }

    glewInit();
    glfwGetCurrentContext();
    glEnable(GL_DEPTH_TEST);
}


