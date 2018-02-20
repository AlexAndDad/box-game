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



void BoxView::Draw(BoxData const & boxData) {

    service.prepare();
    glBindTexture(GL_TEXTURE_2D, texture);

    service.setViewMatrix(getViewMatrix(boxData));
    service.setModelMatrix(getModelMatrix(boxData));
    service.setProjectionMatrix(getProjectionMatrix(boxData));

    service.Draw();

}


glm::mat4 BoxView::getViewMatrix(BoxData const & boxData)
{
    glm::vec3 cameraDirection = glm::normalize(boxData.cameraPos - boxData.cameraTarget);
    glm::vec3 cameraRight = glm::normalize(glm::cross(boxData.cameraUp, cameraDirection));
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);


    glm::mat4 view(1.0f);
    view = glm::lookAt(boxData.cameraPos, boxData.cameraPos + boxData.cameraFront, cameraUp);

    return view;
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