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


protected:
    std::array<bool,GameKeySize> keys_pressed = {};




};



#endif //BOX_GAME_USERINPUT_H
