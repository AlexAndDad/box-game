//
// Created by ahodges on 21/02/18.
//

#include "CameraController.h"
#define GLM_ENABLE_EXPERIMENTAL

#include "glm/gtx/rotate_vector.hpp"


CameraController::CameraController(OpenGlUserInput &input)
        : userInput(input) {}


void CameraController::update() {
    //Record time between last and current frame
    float currentTime = glfwGetTime();
    deltaTime = currentTime - lastFrame;
    lastFrame = currentTime;

    //Check inputs and alter magnitude, movement and shit
    cameraData.magnitude = sqrtf(pow(cameraData.velocity.x,2)+pow(cameraData.velocity.z,2));


    auto calMag = [](CameraData const & cameraData) -> float{return sqrtf(pow(cameraData.velocity.x,2)+pow(cameraData.velocity.z,2));};

    if (userInput.isKeyPressed(UserInput::CameraForward))
    {
        cameraData.velocity.x += cameraData.cameraFront.x * 60 * deltaTime;
        cameraData.velocity.z += cameraData.cameraFront.z * 60 * deltaTime;
        cameraData.magnitude = calMag(cameraData);
        if (cameraData.magnitude > cameraData.maxMagnitude)
        {
            float fraction = cameraData.magnitude / cameraData.maxMagnitude;
            cameraData.velocity.x /= fraction;
            cameraData.velocity.z /= fraction;
        }
    }


    if (userInput.isKeyPressed(UserInput::CameraBack))
    {
        cameraData.velocity.x -= cameraData.cameraFront.x * 60 * deltaTime;
        cameraData.velocity.z -= cameraData.cameraFront.z * 60 * deltaTime;
        cameraData.magnitude = calMag(cameraData);
        if (cameraData.magnitude > cameraData.maxMagnitude)
        {
            float fraction = cameraData.magnitude / cameraData.maxMagnitude;
            cameraData.velocity.x /= fraction;
            cameraData.velocity.z /= fraction;
        }
    }



    if (userInput.isKeyPressed(UserInput::CameraRight))
    {
        glm::vec3 top(0.0f,1.0f,0.0f);
        auto right = glm::cross(glm::normalize(cameraData.cameraFront),glm::normalize(top));
        //auto temp = glm::rotate(cameraData.cameraFront,glm::radians(-90.0),glm::vec3(0.0f,1.0f,0.0));
        cameraData.velocity.x += right.x * 60 * deltaTime;
        cameraData.velocity.z += right.z * 60 * deltaTime;
        cameraData.magnitude = calMag(cameraData);
        if (cameraData.magnitude > cameraData.maxMagnitude)
        {
            float fraction = cameraData.magnitude / cameraData.maxMagnitude;
            cameraData.velocity.x /= fraction;
            cameraData.velocity.z /= fraction;
        }
    }

    if (userInput.isKeyPressed(UserInput::CameraLeft))
    {
        glm::vec3 top(0.0f,1.0f,0.0f);
        auto right = glm::cross(glm::normalize(cameraData.cameraFront),glm::normalize(top));
        cameraData.velocity.x -= right.x * 60 * deltaTime;
        cameraData.velocity.z -= right.z * 60 * deltaTime;
        cameraData.magnitude = calMag(cameraData);
        if (cameraData.magnitude > cameraData.maxMagnitude)
        {
            float fraction = cameraData.magnitude / cameraData.maxMagnitude;
            cameraData.velocity.x /= fraction;
            cameraData.velocity.z /= fraction;
        }
    }






    cameraData.cameraPos.x += cameraData.velocity.x * deltaTime;
    cameraData.cameraPos.y += cameraData.velocity.y * deltaTime;
    cameraData.cameraPos.z += cameraData.velocity.z * deltaTime;





}
