//
// Created by ahodges on 20/02/18.
//

#include "GameController.h"

GameController::GameController(OpenGlUserInput const & input)
                        :cameraController(input)
                        ,userInput(input)
{}


void GameController::update()
{
    cameraController.update();
}


glm::mat4 GameController::calcViewMatrix()
{
    return cameraController.cameraData.calcViewMatrix();
}