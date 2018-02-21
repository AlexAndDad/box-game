//
// Created by ahodges on 20/02/18.
//

#include "UserInput.h"

bool UserInput::isKeyPressed(GameKey key) const
{
    return keys_pressed[key];
}