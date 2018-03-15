//
// Created by ahodges on 20/02/18.
//

#include <Objects/Box/BoxViewService.h>
#include <Objects/LightBox/LightBoxViewService.h>
#include <Projectile gun/Projectiles/ProjectileViewService.h>
#include "GameController.h"

GameController::GameController(OpenGlUserInput & input, DisplayController & openGLDisplay)
                        :cameraController(input)
                        ,userInput(input)
                        ,projectileController(input,cameraController.cameraData)
                        ,textManager(openGLDisplay.SCR_WIDTH,openGLDisplay.SCR_HEIGHT)
{
    renderSettings.setProjectionMatrix(45.0, openGLDisplay.SCR_WIDTH, openGLDisplay.SCR_HEIGHT);
}


void GameController::update()
{
    cameraController.update();
    projectileController.checkClick();

    updateRenderSettings();

}


glm::mat4 GameController::calcViewMatrix()
{
    return cameraController.cameraData.calcViewMatrix(userInput);
}

void GameController::draw()
{
    projectileController.draw();

    if (debugText)
    {
        textManager.drawDebug(cameraController.cameraData);
    }
}

void GameController::enableDebugText()
{
    debugText = true;
}

void GameController::updateRenderSettings()
{
    auto viewMatrix = calcViewMatrix();
    renderSettings.setViewMatrix(viewMatrix);

    BoxViewService::acquire(renderSettings);
    LightBoxViewService::acquire(renderSettings);
    ProjectileViewService::acquire(renderSettings);
}