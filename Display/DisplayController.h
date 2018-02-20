//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_DISPLAYCONTROLLER_H
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define BOX_GAME_DISPLAYCONTROLLER_H



struct DisplayController {

     DisplayController();



    GLFWwindow* window;
    int SCR_WIDTH = 200,SCR_HEIGHT = 200;

};


#endif //BOX_GAME_DISPLAYCONTROLLER_H
