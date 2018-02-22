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
    BoxController Box2("container.jpg",BoxData(2,-2,0));
    BoxController Box3("container.jpg",BoxData(3,-2,0));
    BoxController Box4("container.jpg",BoxData(4,-2,0));
    BoxController Box5("container.jpg",BoxData(5,-2,0));
    BoxController Box6("container.jpg",BoxData(6,-2,0));
    BoxController Box7("container.jpg",BoxData(7,-2,0));

    BoxController Box21("container.jpg",BoxData(2,-2,1));
    BoxController Box31("container.jpg",BoxData(3,-2,1));
    BoxController Box41("container.jpg",BoxData(4,-2,1));
    BoxController Box51("container.jpg",BoxData(5,-2,1));
    BoxController Box61("container.jpg",BoxData(6,-2,1));
    BoxController Box71("container.jpg",BoxData(7,-2,1));

    BoxController Box22("container.jpg",BoxData(2,-2,2));
    BoxController Box32("container.jpg",BoxData(3,-2,2));
    BoxController Box42("container.jpg",BoxData(4,-2,2));
    BoxController Box52("container.jpg",BoxData(5,-2,2));
    BoxController Box62("container.jpg",BoxData(6,-2,2));
    BoxController Box72("container.jpg",BoxData(7,-2,2));


     while (!glfwWindowShouldClose(openGLDisplay.window)) {

        glClearColor(0.3f, 0.3f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        gameController.update();
        auto viewMatrix = gameController.calcViewMatrix();
        renderSettings.setViewMatrix(viewMatrix);


        BoxViewService::acquire(renderSettings);


        Box.Draw();
        Box2.Draw();
        Box3.Draw();
        Box4.Draw();
        Box5.Draw();
        Box6.Draw();
        Box7.Draw();

        Box21.Draw();
        Box31.Draw();
        Box41.Draw();
        Box51.Draw();
        Box61.Draw();
        Box71.Draw();

        Box22.Draw();
        Box32.Draw();
        Box42.Draw();
        Box52.Draw();
        Box62.Draw();
        Box72.Draw();











        glfwSwapBuffers(openGLDisplay.window);
        glfwPollEvents();

    }


}