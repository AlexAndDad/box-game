//
// Created by ahodges on 21/02/18.
//

#ifndef BOX_GAME_CAMERACONTROLLER_H
#define BOX_GAME_CAMERACONTROLLER_H

#include "CameraData.h"
#include "Input/OpenGlUserInput.h"

struct CameraController {


    CameraController(OpenGlUserInput const & input);
    void update();

    CameraData cameraData;
    OpenGlUserInput const &userInput;

    float deltaTime=0.0,lastFrame=0.0;

};


#endif //BOX_GAME_CAMERACONTROLLER_H
