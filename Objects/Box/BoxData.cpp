//
// Created by ahodges on 20/02/18.
//

#include "BoxData.h"


BoxData::BoxData(float x, float y, float z) {
    coordX = x;
    coordY = y;
    coordZ = z;


    cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
}