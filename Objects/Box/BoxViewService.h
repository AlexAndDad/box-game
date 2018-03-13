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
#include "RenderSettings/RenderSettings.h"
#include <unordered_map>

struct BoxViewService {


    static BoxViewService & acquire(RenderSettings const & renderSettings);
    static BoxViewService & acquire();


    unsigned int acquireTexture(std::string const & texture_);

    void prepare();
    //void setViewMatrix(glm::mat4 const & view);
    void setModelMatrix(glm::mat4 model);
    //void setProjectionMatrix(glm::mat4 projection);
    void Draw();


    unsigned int VAO;
    Shaders * shaderptr;




private:

    static std::unique_ptr<BoxViewService> & storage();
    BoxViewService();
    glm::mat4 view;
    glm::mat4 projection;
    std::unordered_map<std::string,unsigned int> textures;



};

#endif //BOX_GAME_BOXVIEWSERVICE_H
