//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_GAMECONTROLLER_H
#define BOX_GAME_GAMECONTROLLER_H
#include "Objects/Camera/CameraController.h"
#include "Input/OpenGlUserInput.h"

struct GameController {

    GameController(OpenGlUserInput & input);

    glm::mat4 calcViewMatrix();
    void update();


    CameraController cameraController;
    OpenGlUserInput & userInput;




};


#endif //BOX_GAME_GAMECONTROLLER_H
