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
    double lastX =  800.0f / 2.0;
    double lastY =  600.0 / 2.0;
    double currentX = 0.0;
    double currentY = 0.0;

    bool leftMouseClicked = false;


protected:
    std::array<bool,GameKeySize> keys_pressed = {};




};



#endif //BOX_GAME_USERINPUT_H
