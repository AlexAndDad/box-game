//
// Created by ahodges on 20/02/18.
//

#include "BoxController.h"


BoxController::BoxController(std::string texture_)
                    :boxData(-0.0,-0.0,-0.0)
                    ,boxView(std::move(texture_))
{}

void BoxController::Draw()
{
    boxView.Draw(boxData);
}