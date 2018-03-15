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

#include <Objects/LightBox/LightBoxViewService.h>
#include <iomanip>
#include <map>
#include <wait.h>
#include <Projectile gun/Projectiles/ProjectileViewService.h>


int main(int argc, const char** argv)
{
    ResourcePath::setProgramPath(argv[0]);
    DisplayController openGLDisplay;
    OpenGlUserInput openGLInput(openGLDisplay.window);


    GameController gameController(openGLInput,openGLDisplay);


    // Object generation

    LightBoxController light1({1,0,1});
    std::string temp = "container.jpg";
    std::vector<std::vector<BoxController>> BoxCol;
    std::vector<BoxController> Boxrow;
    for (float x = 0;x<20;x+= 0.2)
    {
        BoxCol.emplace_back();
        for (float z=0;z<20;z+=0.2)
        {


            BoxCol[x].emplace_back(temp,BoxData{x,  (sin(x)*cos(z)) -1 ,z});
        }
    }


    //Text

    gameController.enableDebugText();

    //Draw loop

    while (!glfwWindowShouldClose(openGLDisplay.window)) {


         glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


         gameController.update();


         gameController.draw();
         light1.Draw();
         for (auto & x : BoxCol)
         {
             for (auto & y : x)
             {
                 y.Draw();
             }
         }


        glfwSwapBuffers(openGLDisplay.window);
        glfwPollEvents();

    }


}