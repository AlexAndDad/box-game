//
// Created by ahodges on 20/02/18.
//

#include "GameController.h"

GameController::GameController(OpenGlUserInput & input)
                        :cameraController(input)
                        ,userInput(input)
                        ,projectileController(input,cameraController.cameraData)
{}


void GameController::update()
{
    cameraController.update();
    projectileController.checkClick();

}


glm::mat4 GameController::calcViewMatrix()
{
    return cameraController.cameraData.calcViewMatrix(userInput);
}

void GameController::draw()
{
    projectileController.draw();
}