//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_GAMECONTROLLER_H
#define BOX_GAME_GAMECONTROLLER_H
#include "Objects/Camera/CameraController.h"
#include "Input/OpenGlUserInput.h"
#include "Projectile gun/ProjectileController.h"

struct GameController {

    GameController(OpenGlUserInput & input);

    glm::mat4 calcViewMatrix();
    void update();
    void draw();


    CameraController cameraController;
    OpenGlUserInput & userInput;
    ProjectileController projectileController;




};


#endif //BOX_GAME_GAMECONTROLLER_H
