//
// Created by ahodges on 20/02/18.
//
#pragma once

#include <glm/glm.hpp>
#include "Input/OpenGlUserInput.h"

struct CameraData {

    CameraData();

    glm::mat4 calcViewMatrix(OpenGlUserInput &);

    glm::vec3 velocity;
    glm::vec3 velocityLimit;

    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::vec3 cameraPos;
    glm::vec3 cameraTarget;

    float cameraSpeed;

    float yaw   = -45.0f;
    float pitch =  0.0f;

};



