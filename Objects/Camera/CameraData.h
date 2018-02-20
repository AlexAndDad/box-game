//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_CAMERACONTROLLER_H
#define BOX_GAME_CAMERACONTROLLER_H
#include <glm/glm.hpp>

struct CameraData {

    CameraData();

    glm::mat4 calcViewMatrix() const;


    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::vec3 cameraPos;
    glm::vec3 cameraTarget;

};


#endif //BOX_GAME_CAMERACONTROLLER_H
