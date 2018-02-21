//
// Created by ahodges on 20/02/18.
//

#include "CameraData.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

CameraData::CameraData()
        :cameraPos (glm::vec3(0.0f, 0.0f, 3.0f))
        ,cameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
        ,cameraUp(glm::vec3(0.0f, 1.0f, 0.0f))
        ,cameraTarget(glm::vec3(0.0f, 0.0f, 0.0f))
        ,velocity(glm::vec3(0.0f,0.0f,0.0f))
        ,velocityLimit(glm::vec3(6.0f,6.0f,6.0f))

{
    cameraSpeed = 0.5;
}


glm::mat4 CameraData::calcViewMatrix() const
{
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    glm::vec3 cameraRight = glm::normalize(glm::cross(cameraUp, cameraDirection));
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);


    glm::mat4 view(1.0f);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    return view;
}

