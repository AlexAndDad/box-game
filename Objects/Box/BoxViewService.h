//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_BOXVIEWSERVICE_H
#define BOX_GAME_BOXVIEWSERVICE_H
#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderGen/Shaders.h"

struct BoxViewService {

    static BoxViewService & acquire();

    void prepare();
    void setViewMatrix(glm::mat4 view);
    void setModelMatrix(glm::mat4 model);
    void setProjectionMatrix(glm::mat4 projection);
    void Draw();


    unsigned int VAO;
    Shaders * shaderptr;



private:

    BoxViewService();



};

#endif //BOX_GAME_BOXVIEWSERVICE_H
