//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_BOXCONTROLLER_H
#define BOX_GAME_BOXCONTROLLER_H

#include "BoxData.h"
#include "BoxView.h"
#include <string>

struct BoxController {

    BoxController(std::string texture_);

    void Draw();

    BoxData * boxDataptr;
    BoxView * boxViewptr;

};


#endif //BOX_GAME_BOXCONTROLLER_H
