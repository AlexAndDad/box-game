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
#include <iomanip>
#include <map>
#include <wait.h>
#include <Projectile gun/Projectiles/ProjectileViewService.h>
#include FT_FREETYPE_H






int main(int argc, const char** argv)
{
    ResourcePath::setProgramPath(argv[0]);





    DisplayController openGLDisplay;
    OpenGlUserInput openGLInput(openGLDisplay.window);

    GameController gameController(openGLInput);

    RenderSettings renderSettings;
    renderSettings.setProjectionMatrix(45.0, openGLDisplay.SCR_WIDTH, openGLDisplay.SCR_HEIGHT);

    glm::mat4 projection = glm::ortho(0.0f,openGLDisplay.SCR_WIDTH,0.0f,openGLDisplay.SCR_HEIGHT);

    LightBoxController light1({1,0,1});

    std::string temp = "container.jpg";

    std::vector<std::vector<BoxController>> BoxCol;
    std::vector<BoxController> Boxrow;



    for (float x = 0;x<15;x+= 0.1)
    {
        BoxCol.emplace_back();
        for (float y=0;y<15;y+=0.1)
        {


            BoxCol[x].emplace_back(temp,BoxData{x,  (sin(x)*cos(y)) -1 ,y});
        }
    }


    //Text Rendering

    FT_Library ft;
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

    FT_Face face;
    if (FT_New_Face(ft, "/home/ahodges/alex_dad/Box Game/Fonts/FreeSans.ttf", 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

    //Font size we want to extract from face
    FT_Set_Pixel_Sizes(face, 0,48);


    //Load glyph 'X'
    if (FT_Load_Char(face,'X',FT_LOAD_RENDER))
        std::cout << "ERROR::FREETYPE: Failed to load Glyph" << std::endl;

    struct Character {
        GLuint      TextureID;
        glm::ivec2  Size;
        glm::ivec2  Bearing;
        GLuint      Advance;
    };

    std::map<GLchar, Character> Characters;

    glPixelStorei(GL_UNPACK_ALIGNMENT,1);

    for (GLubyte c =0; c < 128; c++)
    {
        //Load character glyph
        if (FT_Load_Char(face,c,FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYPE: FAILED TO LOAD GLYPH" << std::endl;
            continue;
        }

        //Generate texture
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D,texture);
        glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
        );
        //Set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //Store character for later use
        Character character = {
                texture,
                glm::ivec2(face->glyph->bitmap.width,face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left,face->glyph->bitmap_top),
                face->glyph->advance.x
        };
        Characters.insert(std::pair<GLchar,Character>(c,character));
    }

    FT_Done_Face(face);
    FT_Done_FreeType(ft);




    GLuint VAO, VBO;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(GLfloat)*6*4,NULL,GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,4,GL_FLOAT,GL_FALSE,4* sizeof(GLfloat), 0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    Shaders shader("/home/ahodges/alex_dad/Box Game/Text/TextVertexShader.glsl","/home/ahodges/alex_dad/Box Game/Text/TextFragmentShader.glsl");

    auto RenderText = [&](std::string text, glm::vec3 color,GLfloat x, GLfloat y, GLfloat scale)->void
    {
        //Activate render state
        glUseProgram(shader.ID);
        shader.setVec3("textColor",color.x,color.y,color.z);
        shader.setMat4("projection",projection);
        glActiveTexture(GL_TEXTURE0);
        glBindVertexArray(VAO);

        //Iterate through characters
        std::string::const_iterator c;
        for (c = text.begin(); c!=text.end();c++)
        {
            Character ch = Characters[*c];

            GLfloat xpos = x + ch.Bearing.x * scale;
            GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

            GLfloat w = ch.Size.x * scale;
            GLfloat h = ch.Size.y * scale;

            //Update VBO for eah character
            GLfloat vertices[6][4] = {
                    { xpos,     ypos + h,   0.0, 0.0 },
                    { xpos,     ypos,       0.0, 1.0 },
                    { xpos + w, ypos,       1.0, 1.0 },

                    { xpos,     ypos + h,   0.0, 0.0 },
                    { xpos + w, ypos,       1.0, 1.0 },
                    { xpos + w, ypos + h,   1.0, 0.0 }
            };
            //Render glyph texture over quad
            glBindTexture(GL_TEXTURE_2D, ch.TextureID);
            //Update VBO memory
            glBindBuffer(GL_ARRAY_BUFFER,VBO);
            glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(vertices),vertices);
            glBindBuffer(GL_ARRAY_BUFFER,0);
            //Render quad
            glDrawArrays(GL_TRIANGLES,0,6);
            //Advance cursor
            x += (ch.Advance >> 6) * scale;
        }
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D,0);
    };

    //FPS
    double currentTime = 0;
    double lasttime    = 0;

    int frameCount = 0;
    int frameRate = 0;
    std::string fps_str;



    //Draw loop
    while (!glfwWindowShouldClose(openGLDisplay.window)) {
         frameCount++;
         glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


         gameController.update();
         auto viewMatrix = gameController.calcViewMatrix();
         renderSettings.setViewMatrix(viewMatrix);


         BoxViewService::acquire(renderSettings);

         LightBoxViewService::acquire(renderSettings);

        ProjectileViewService::acquire(renderSettings);

        gameController.draw();

         light1.Draw();

         for (auto & x : BoxCol)
         {
             for (auto & y : x)
             {
                 y.Draw();
             }
         }

        //FPS
        currentTime = glfwGetTime();


        if (currentTime > lasttime + 1) {

            lasttime = currentTime;
            frameRate = frameCount;
            frameCount = 0;
            fps_str = std::to_string(frameRate);
        }



        std::string x,y,z,vx,vy,vz;
        x = std::to_string(gameController.cameraController.cameraData.cameraPos.x);
        y = std::to_string(gameController.cameraController.cameraData.cameraPos.y);
        z = std::to_string(gameController.cameraController.cameraData.cameraPos.z);

        vx = std::to_string(gameController.cameraController.cameraData.velocity.x);
        vy = std::to_string(gameController.cameraController.cameraData.velocity.y);
        vz = std::to_string(gameController.cameraController.cameraData.velocity.z);

        RenderText("Camera Position: ",glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-20,0.5);
        RenderText(("X: "+x),glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-40,0.5);
        RenderText(("Y: "+y),glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-60,0.5);
        RenderText(("Z: "+z),glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-80,0.5);

        RenderText("Camera velocity: ",glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-120,0.5);
        RenderText(("X: "+vx),glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-140,0.5);
        RenderText(("Y: "+vy),glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-160,0.5);
        RenderText(("Z: "+vz),glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-180,0.5);

        RenderText(("FPS: "+fps_str),glm::vec3(1,1,1),openGLDisplay.SCR_WIDTH-200,openGLDisplay.SCR_HEIGHT-220,0.5);


        glfwSwapBuffers(openGLDisplay.window);
        glfwPollEvents();

    }


}