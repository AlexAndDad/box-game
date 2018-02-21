//
// Created by ahodges on 21/02/18.
//

#include "CameraController.h"


CameraController::CameraController(const OpenGlUserInput &input)
        : userInput(input) {}


void CameraController::update() {
    //Record time between last and current frame
    float currentTime = glfwGetTime();
    deltaTime = currentTime - lastFrame;
    lastFrame = currentTime;

    //Check inputs and alter velocity accordingly && Check velocity is within bounds
    if (userInput.isKeyPressed(UserInput::CameraForward)) {
        if (cameraData.velocity.z > -(cameraData.velocityLimit.z)) {
            cameraData.velocity.z -= cameraData.cameraSpeed * deltaTime;
            if (cameraData.velocity.z < -(cameraData.velocityLimit.z)) {
                cameraData.velocity.z = -(cameraData.velocityLimit.z);
            }
        }
    }
    if (userInput.isKeyPressed(UserInput::CameraBack)) {
        if (cameraData.velocity.z < cameraData.velocityLimit.z) {
            cameraData.velocity.z += cameraData.cameraSpeed * deltaTime;
            if (cameraData.velocity.z > cameraData.velocityLimit.z) {
                cameraData.velocity.z = cameraData.velocityLimit.z;
            }
        }
    }

    if (userInput.isKeyPressed(UserInput::CameraLeft)) {
        if (cameraData.velocity.x > -(cameraData.velocityLimit.x)) {
            cameraData.velocity.x -= cameraData.cameraSpeed * deltaTime;
            if (cameraData.velocity.x < -(cameraData.velocityLimit.x)) {
                cameraData.velocity.x = -(cameraData.velocityLimit.x);
            }
        }
    }


    if (userInput.isKeyPressed(UserInput::CameraRight)) {
        if (cameraData.velocity.x < cameraData.velocityLimit.x) {
            cameraData.velocity.x += cameraData.cameraSpeed * deltaTime;
            if (cameraData.velocity.x > cameraData.velocityLimit.x) {
                cameraData.velocity.x = cameraData.velocityLimit.x;
            }
        }
    }


    cameraData.cameraPos.x += cameraData.velocity.x * deltaTime;
    cameraData.cameraPos.y += cameraData.velocity.y * deltaTime;
    cameraData.cameraPos.z += cameraData.velocity.z * deltaTime;
}
