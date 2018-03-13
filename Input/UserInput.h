//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_USERINPUT_H
#define BOX_GAME_USERINPUT_H
#include <array>
#include <boost/noncopyable.hpp>

struct UserInput :boost::noncopyable {

    enum GameKey{
        Quit,
        CameraBack,
        CameraForward,
        CameraLeft,
        CameraRight,

        GameKeySize
    };

    bool isKeyPressed(GameKey key) const;

    bool firstMouse;
    float lastX =  800.0f / 2.0;
    float lastY =  600.0 / 2.0;
    float currentX = 0.0;
    float currentY = 0.0;

    bool leftMouseClicked = false;


protected:
    std::array<bool,GameKeySize> keys_pressed = {};




};



#endif //BOX_GAME_USERINPUT_H
