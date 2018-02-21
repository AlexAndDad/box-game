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

};


#endif //BOX_GAME_BOXDATA_H
