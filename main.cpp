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

#include <ft2build.h>
#include FT_FREETYPE_H

int main(int argc, const char** argv)
{
    ResourcePath::setProgramPath(argv[0]);


    // font test
    FT_Library ft;
    if(FT_Init_FreeType(&ft)) {
        std::cerr << "Could not init freetype library\n";
        std::exit(100);
    }

    FT_Face face;
    auto fresource = ResourcePath::get() / "Fonts"  / "A-Bebedera.ttf";

    if(FT_New_Face(ft, fresource.c_str(), 0, &face)) {
        std::cerr << "Could not open font: " << fresource << "\n";
        std::exit(101);
    }


    DisplayController openGLDisplay;
    OpenGlUserInput openGLInput(openGLDisplay.window);

    GameController gameController(openGLInput);

    RenderSettings renderSettings;
    renderSettings.setProjectionMatrix(45.0, openGLDisplay.SCR_WIDTH, openGLDisplay.SCR_HEIGHT);



    BoxController Box("awesomeface.png");
    BoxController Box2("container.jpg",BoxData(0.4,1.0,-2.0));


    while (!glfwWindowShouldClose(openGLDisplay.window)) {

        glClearColor(0.3f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        gameController.update();
        auto viewMatrix = gameController.calcViewMatrix();
        renderSettings.setViewMatrix(viewMatrix);


        BoxViewService::acquire(renderSettings);


        Box.Draw();
        Box2.Draw();

        glfwSwapBuffers(openGLDisplay.window);
        glfwPollEvents();

    }


}