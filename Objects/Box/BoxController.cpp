//
// Created by ahodges on 20/02/18.
//

#include "BoxController.h"


BoxController::BoxController(std::string texture_)
{

    boxDataptr = new BoxData(std::move(texture_),-0.0,-0.0,-0.0);
    boxViewptr = new BoxView(boxDataptr);
}

void BoxController::Draw()
{
    boxViewptr->Draw();
}