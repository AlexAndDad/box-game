//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_RENDERSETTINGS_H
#define BOX_GAME_RENDERSETTINGS_H

#include <glm/glm.hpp>

struct RenderSettings {

    void setViewMatrix(glm::mat4 vm);
    void setProjectionMatrix(float FOV, float WIDTH,float HEIGHT);

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

};


#endif //BOX_GAME_RENDERSETTINGS_H
