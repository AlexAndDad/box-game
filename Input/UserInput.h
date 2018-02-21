//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_USERINPUT_H
#define BOX_GAME_USERINPUT_H
#include <array>

struct UserInput {

    enum GameKey{
        Quit,
        CameraBack,
        CamerForward,

        GameKeySize
    };

    bool isKeyPressed(GameKey key);


protected:
    std::array<bool,GameKeySize> keys_pressed = {};




};



#endif //BOX_GAME_USERINPUT_H
