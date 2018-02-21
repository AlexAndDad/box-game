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
#include "Game Controller/GameController.h"
#include "RenderSettings/RenderSettings.h"
#include "Objects/Box/BoxViewService.h"
#include "Resources/resource_path.hpp"


int main(int argc, const char** argv)
{
    ResourcePath::setProgramPath(argv[0]);


    DisplayController openGLDisplay;
    OpenGlUserInput openGLInput(openGLDisplay.window);

    GameController gameController;

    RenderSettings renderSettings;
    renderSettings.setProjectionMatrix(45.0, openGLDisplay.SCR_WIDTH, openGLDisplay.SCR_HEIGHT);


    std::string texture = "awesomeface.png";
    BoxController Box(texture);
    BoxController Box2("container.jpg",BoxData(1.0,1.0,-5.0));


    while (!glfwWindowShouldClose(openGLDisplay.window)) {

        glClearColor(0.3f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        auto viewMatrix = gameController.camera.calcViewMatrix();
        renderSettings.setViewMatrix(viewMatrix);


        BoxViewService::acquire(renderSettings);


        Box.Draw();
        Box2.Draw();

        glfwSwapBuffers(openGLDisplay.window);
        glfwPollEvents();

    }


}