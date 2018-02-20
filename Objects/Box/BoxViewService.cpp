//
// Created by ahodges on 20/02/18.
//

#include "BoxViewService.h"
#include "BoxVAO.h"

BoxViewService::BoxViewService()
{
    shaderptr = new Shaders("/home/ahodges/alex_dad/Box Game/Objects/Box/VertexShader.glsl","/home/ahodges/alex_dad/Box Game/Objects/Box/FragmentShader.glsl");

    BoxVAO vao;
    VAO = vao.VAO;
}

BoxViewService& BoxViewService::acquire()
{
    static BoxViewService theOne;
    return theOne;
}

void BoxViewService::prepare()
{
    glUseProgram(shaderptr->ID);
    shaderptr->setInt("texture1",0);
    glActiveTexture(GL_TEXTURE0);
}


void BoxViewService::setViewMatrix(glm::mat4 view)
{
    shaderptr->setMat4("view",view);
}

void BoxViewService::setModelMatrix(glm::mat4 model)
{
    shaderptr->setMat4("model",model);
}

void BoxViewService::setProjectionMatrix(glm::mat4 projection)
{
    shaderptr->setMat4("projection",projection);
}
void BoxViewService::Draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}