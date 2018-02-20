//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_BOXDATA_H
#define BOX_GAME_BOXDATA_H
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct BoxData {

    BoxData(float x=0,float y=0, float z=0);

    float coordX,coordY,coordZ;


    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::vec3 cameraPos;
    glm::vec3 cameraTarget;

};


#endif //BOX_GAME_BOXDATA_H
