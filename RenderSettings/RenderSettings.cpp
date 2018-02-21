//
// Created by ahodges on 20/02/18.
//

#include "RenderSettings.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void RenderSettings::setProjectionMatrix(float FOV, float WIDTH,float HEIGHT)
{
    glm::mat4 projection(1.0f);
    projection = glm::perspective(glm::radians(FOV), (WIDTH/HEIGHT), 0.1f, 100.0f);

    projectionMatrix = projection;
}


void RenderSettings::setViewMatrix(glm::mat4 vm)
{
    viewMatrix = vm;
}