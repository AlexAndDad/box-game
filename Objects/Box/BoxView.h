//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_BOXVIEW_H
#define BOX_GAME_BOXVIEW_H
#include "stb/stb_image.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "BoxData.h"
#include "Textures/TextureGen/TextureGen.h"
#include "BoxVAO.h"
#include "ShaderGen/Shaders.h"

struct BoxView {
    BoxView(BoxData * boxData_);

    void Draw();
    BoxData * boxData;

    std::string texture_current;
    unsigned int texture,VAO;
    Shaders * shaderptr;

};


#endif //BOX_GAME_BOXVIEW_H
