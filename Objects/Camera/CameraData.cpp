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
        ,cameraRight(glm::vec3(0.0f,0.0f,0.0f))


{
    cameraSpeed = 3;
    maxMagnitude = 10;

}


glm::mat4 CameraData::calcViewMatrix(OpenGlUserInput & input)
{
    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    cameraRight = glm::normalize(glm::cross(cameraUp, cameraDirection));
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);

    float xoffset = input.currentX - input.lastX;
    float yoffset = input.lastY - input.currentY;

    input.lastX= input.currentX;
    input.lastY= input.currentY;

    float sensitivity = 1.5f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;



    glm::vec3 front(1.0);
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);

    glm::mat4 view(1.0f);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    return view;
}

