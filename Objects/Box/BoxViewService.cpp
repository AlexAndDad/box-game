//
// Created by ahodges on 20/02/18.
//

#include "BoxViewService.h"
#include "BoxVAO.h"
#include "Resources/resource_path.hpp"
#include "Textures/TextureGen/TextureGen.h"

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
    auto & self = acquire();


    self.view = renderSettings.viewMatrix;
    self.projection = renderSettings.projectionMatrix;
    return self;
}

BoxViewService& BoxViewService::acquire()
{

    auto & self = storage();
    if (!self)
    {
        self.reset(new BoxViewService);
    }

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



unsigned int BoxViewService::acquireTexture(std::string const &texture_)
{

    auto & result =  textures[texture_];
    if (result == 0)
    {
        TextureGen temp(texture_);
        result = temp.texture;
    }

    return result;






}