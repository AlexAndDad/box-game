#include <cstdlib>
#include <GL/glew.h>
#include <glm/glm.hpp>
#if __has_include(<OpenGL/gl.h>)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include <GLFW/glfw3.h>
#include <iostream>

#include "Display/DisplayController.h"
#include "Input/OpenGlUserInput.h"
#include "Objects/Box/BoxView.h"
#include "Objects/Box/BoxController.h"
#include <string>


int main()
{

    DisplayController openGLDisplay;
    OpenGlUserInput openGLInput(openGLDisplay.window);

    std::string texture = "awesomeface.png";
    BoxController Box(texture);





    while (!glfwWindowShouldClose(openGLDisplay.window))
    {

        glClearColor(0.3f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Box.Draw();

        glfwSwapBuffers(openGLDisplay.window);
        glfwPollEvents();

    }








}