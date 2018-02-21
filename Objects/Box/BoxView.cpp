//
// Created by ahodges on 20/02/18.
//

#include "BoxView.h"
#include "Resources/resource_path.hpp"

BoxView::BoxView(BoxData * boxData_)
{

    boxData = boxData_;
    // 1) Generate Texture
    TextureGen temp(boxData->texture);
    texture = temp.texture;

    // 2) Generate VAO
    BoxVAO vao;
    VAO = vao.VAO;


    // 3) Generate Shader Program
    auto resourcePath = ResourcePath::get() / "Objects" / "Box";
    auto vshaderPath = resourcePath / "VertexShader.glsl";
    auto fshaderPath = resourcePath / "FragmentShader.glsl";
    shaderptr = new Shaders(vshaderPath.c_str(),fshaderPath.c_str());
}



void BoxView::Draw() {
    glUseProgram(shaderptr->ID);
    glUniform1i(glGetUniformLocation(shaderptr->ID, "texture1"), 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);




    glm::vec3 cameraDirection = glm::normalize(boxData->cameraPos - boxData->cameraTarget);
    glm::vec3 cameraRight = glm::normalize(glm::cross(boxData->cameraUp, cameraDirection));
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);


    glm::mat4 view(1.0f);
    view = glm::lookAt(boxData->cameraPos, boxData->cameraPos + boxData->cameraFront, cameraUp);

    glm::mat4 model(1.0f);
    model = glm::translate(model,glm::vec3(boxData->coordX,boxData->coordY,boxData->coordZ));
    float angle = 20.0f * 1 + 5;
    model = glm::rotate(model, (float) glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(45.0f), ((float) 1920 / (float) 1080), 0.1f, 100.0f);



    shaderptr->setMat4("view",view);
    shaderptr->setMat4("projection",projection);
    shaderptr->setMat4("model",model);


    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);

}
