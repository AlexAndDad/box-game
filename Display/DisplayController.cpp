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
    auto monitor = glfwGetPrimaryMonitor();
    SCR_WIDTH  = glfwGetVideoMode(monitor)->width;
    SCR_HEIGHT = glfwGetVideoMode(monitor)->height;
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "BoxGame", monitor, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window";
        glfwTerminate();
        std::exit(100);
    }
    else {
        glfwMakeContextCurrent(window);
    }

    glewInit();
    glfwGetCurrentContext();
    glEnable(GL_DEPTH_TEST);
    glfwSwapInterval(1);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


