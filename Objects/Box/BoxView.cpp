//
// Created by ahodges on 20/02/18.
//

#include "BoxView.h"

#include "BoxViewService.h"

//#include "Resources/resource_path.hpp"


BoxView::BoxView(std::string texture_)
{

    auto & service = BoxViewService::acquire();

    texture = service.acquireTexture(texture_);


}

BoxViewService& BoxView::getService()
{
    auto & service = BoxViewService::acquire();

    service.prepare();
    return service;



}

void BoxView::Draw(BoxData const & boxData) {

    auto & service = getService();

    glBindTexture(GL_TEXTURE_2D, texture);


    service.setModelMatrix(getModelMatrix(boxData));


    service.Draw();

}




glm::mat4 BoxView::getModelMatrix(BoxData const &boxData)
{
    glm::mat4 model(1.0f);
    model = glm::translate(model,glm::vec3(boxData.coordX,boxData.coordY,boxData.coordZ));
    float angle = 20.0f * 1 + 5;
    //model = glm::rotate(model, (float) glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
    model = glm::scale(model,glm::vec3(0.2,0.2,0.2));
    return model;
}

