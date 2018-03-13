//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_OPENGLUSERINPUT_H
#define BOX_GAME_OPENGLUSERINPUT_H
#include "UserInput.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct OpenGlUserInput:UserInput {

    OpenGlUserInput(GLFWwindow * window_);


    static void getInput(GLFWwindow* window,int key, int scancode, int action, int mods);
    static void getMouse(GLFWwindow* window,double xpos, double ypos);
    static void getMouseClick(GLFWwindow* window, int button, int action, int mods);

    GLFWwindow * window;

    struct State{

    };

    State myState;
};


#endif //BOX_GAME_OPENGLUSERINPUT_H
