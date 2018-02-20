//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_TEXTUREGEN_H
#define BOX_GAME_TEXTUREGEN_H
#include <string>
#include "stb/stb_image.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

struct TextureGen {

    TextureGen(std::string texturePath);






    unsigned int texture;

};


#endif //BOX_GAME_TEXTUREGEN_H
