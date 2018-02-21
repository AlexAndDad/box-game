//
// Created by ahodges on 20/02/18.
//

#include "BoxViewService.h"
#include "BoxVAO.h"
#include "Resources/resource_path.hpp"

BoxViewService::BoxViewService()
{

    //3) Generate Shader Program
    auto resourcePath = ResourcePath::get() / "Objects" / "Box";
    auto vshaderPath = resourcePath / "VertexShader.glsl";
    auto fshaderPath = resourcePath / "FragmentShader.glsl";
    shaderptr = new Shaders(vshaderPath.c_str(),fshaderPath.c_str());


    BoxVAO vao;
    VAO = vao.VAO;
}

std::unique_ptr<BoxViewService>& BoxViewService::storage()
{
    static std::unique_ptr<BoxViewService> cunt;
    return cunt;
}

BoxViewService& BoxViewService::acquire(RenderSettings const &renderSettings)
{
    auto & self = storage();
    if (!self)
    {
        self.reset(new BoxViewService);
    }

    self->view = renderSettings.viewMatrix;
    self->projection = renderSettings.projectionMatrix;
    return * self;
}

BoxViewService& BoxViewService::acquire()
{
    auto & self = storage();
    assert(self);
    return * self;
}

void BoxViewService::prepare()
{
    glUseProgram(shaderptr->ID);
    shaderptr->setInt("texture1",0);
    glActiveTexture(GL_TEXTURE0);

    shaderptr->setMat4("projection",projection);
    shaderptr->setMat4("view",view);
}




void BoxViewService::setModelMatrix(glm::mat4 model)
{
    shaderptr->setMat4("model",model);
}


void BoxViewService::Draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}