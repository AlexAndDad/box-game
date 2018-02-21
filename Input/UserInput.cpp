//
// Created by ahodges on 20/02/18.
//

#include "UserInput.h"

bool UserInput::isKeyPressed(GameKey key)
{
    return keys_pressed[key];
}