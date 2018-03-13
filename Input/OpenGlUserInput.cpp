//
// Created by ahodges on 20/02/18.
//

#include "OpenGlUserInput.h"


OpenGlUserInput::OpenGlUserInput(GLFWwindow *window_)
{
    window = window_;
    glfwSetWindowUserPointer(window, this);

    glfwSetKeyCallback(window, &OpenGlUserInput::getInput);
    glfwSetCursorPosCallback(window,&OpenGlUserInput::getMouse);
    glfwSetMouseButtonCallback(window,&OpenGlUserInput::getMouseClick);
}

void OpenGlUserInput::getMouse(GLFWwindow *window, double xpos, double ypos)
{
    auto pv = glfwGetWindowUserPointer(window);
    auto self = reinterpret_cast<OpenGlUserInput*>(pv);
    if (self->firstMouse)
    {
        self->lastX = xpos;
        self->lastY = ypos;
        self->firstMouse = false;
    }

    self->lastX = self->currentX;
    self->lastY = self->currentY;
    self->currentX = xpos;
    self->currentY = ypos;
}



void OpenGlUserInput::getInput(GLFWwindow* window,int key, int scancode , int action, int mods) {
    auto pv = glfwGetWindowUserPointer(window);
    auto self = reinterpret_cast<OpenGlUserInput*>(pv);

    auto pressed=[](int action)
    {
        return action == GLFW_PRESS || action == GLFW_REPEAT;
    };

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (key == GLFW_KEY_S)
    {
        self->keys_pressed[CameraBack] = pressed(action);
    }
    if (key == GLFW_KEY_W)
    {
        self->keys_pressed[CameraForward] = pressed(action);
    }
    if (key == GLFW_KEY_A)
    {
        self->keys_pressed[CameraLeft] = pressed(action);
    }
    if (key == GLFW_KEY_D)
    {
        self->keys_pressed[CameraRight] = pressed(action);
    }

}

void OpenGlUserInput::getMouseClick(GLFWwindow *window, int button, int action, int mods)
{
    auto pv = glfwGetWindowUserPointer(window);
    auto self = reinterpret_cast<OpenGlUserInput*>(pv);

    if (action != GLFW_PRESS)
    {
        self->leftMouseClicked = false;
    }
    else if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_LEFT)
    {
        self->leftMouseClicked = true;
    }
}