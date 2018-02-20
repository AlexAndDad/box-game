//
// Created by ahodges on 20/02/18.
//

#include "BoxView.h"
#include "BoxViewService.h"


BoxView::BoxView(std::string texture_)
                :service(BoxViewService::acquire())
{

    // 1) Generate Texture
    TextureGen temp(texture_);
    texture = temp.texture;

}



void BoxView::Draw(BoxData const & boxData, glm::mat4 const & viewMatrix) {

    service.prepare();
    glBindTexture(GL_TEXTURE_2D, texture);

    service.setViewMatrix(viewMatrix);
    service.setModelMatrix(getModelMatrix(boxData));
    service.setProjectionMatrix(getProjectionMatrix(boxData));

    service.Draw();

}




glm::mat4 BoxView::getModelMatrix(BoxData const &boxData)
{
    glm::mat4 model(1.0f);
    model = glm::translate(model,glm::vec3(boxData.coordX,boxData.coordY,boxData.coordZ));
    float angle = 20.0f * 1 + 5;
    model = glm::rotate(model, (float) glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

    return model;
}

glm::mat4 BoxView::getProjectionMatrix(BoxData const &)
{
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(45.0f), ((float) 1920 / (float) 1080), 0.1f, 100.0f);

    return projection;
}