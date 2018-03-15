//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_GAMECONTROLLER_H
#define BOX_GAME_GAMECONTROLLER_H
#include "Objects/Camera/CameraController.h"
#include "Input/OpenGlUserInput.h"
#include "Projectile gun/ProjectileController.h"
#include "Text/TextManager.h"
#include "Display/DisplayController.h"
#include "RenderSettings/RenderSettings.h"

struct GameController {

    GameController(OpenGlUserInput & input, DisplayController & openGlDisplay);

    glm::mat4 calcViewMatrix();
    void update();
    void draw();
    void enableDebugText();
    void updateRenderSettings();

    bool debugText = false;


    CameraController cameraController;
    OpenGlUserInput & userInput;
    ProjectileController projectileController;
    TextManager textManager;
    RenderSettings renderSettings;




};


#endif //BOX_GAME_GAMECONTROLLER_H
