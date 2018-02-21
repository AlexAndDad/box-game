//
// Created by ahodges on 20/02/18.
//

#include "OpenGlUserInput.h"


OpenGlUserInput::OpenGlUserInput(GLFWwindow *window_)
{
    window = window_;
    glfwSetWindowUserPointer(window, this);

    glfwSetKeyCallback(window, &OpenGlUserInput::getInput);
}



void OpenGlUserInput::getInput(GLFWwindow* window,int key, int scancode , int action, int mods) {
    auto pv = glfwGetWindowUserPointer(window);
    auto self = reinterpret_cast<OpenGlUserInput*>(pv);

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (key == GLFW_KEY_S)
    {
        self->keys_pressed[CameraBack] = action == GLFW_PRESS ? true:false;
    }
}
