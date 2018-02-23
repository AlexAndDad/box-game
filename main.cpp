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
#include <algorithm>
#include <array>

#include "Display/DisplayController.h"
#include "Input/OpenGlUserInput.h"
#include "Objects/Box/BoxView.h"
#include "Objects/Box/BoxController.h"
#include <string>
#include "Game Controller/GameController.h"
#include "RenderSettings/RenderSettings.h"
#include "Objects/Box/BoxViewService.h"
#include "Resources/resource_path.hpp"
#include "Objects/LightBox/LightBoxController.h"
#include <ft2build.h>
#include <Objects/LightBox/LightBoxViewService.h>
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


    LightBoxController light1({1,0,1});

    std::string temp = "container.jpg";

    std::vector<std::vector<BoxController>> BoxCol;
    std::vector<BoxController> Boxrow;

    for (int x = 0;x<20;x++)
    {
        BoxCol.emplace_back();
        for (int y=0;y<20;++y)
        {
            if (x == 0 || x == 19  || y == 0 || y == 19)
            {
                BoxCol[x].emplace_back("awesomeface.png",BoxData{x,-2,y});
            }
            else
                BoxCol[x].emplace_back(temp,BoxData{x,-2,y});
        }
    }






     while (!glfwWindowShouldClose(openGLDisplay.window)) {

         glClearColor(0.3f, 0.3f, 0.6f, 1.0f);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


         gameController.update();
         auto viewMatrix = gameController.calcViewMatrix();
         renderSettings.setViewMatrix(viewMatrix);


         BoxViewService::acquire(renderSettings);

         LightBoxViewService::acquire(renderSettings);

         light1.Draw();

         for (auto & x : BoxCol)
         {
             for (auto & y : x)
             {
                 y.Draw();
             }
         }







        std::cout << glfwGetTime() << std::endl;



        glfwSwapBuffers(openGLDisplay.window);
        glfwPollEvents();

    }


}