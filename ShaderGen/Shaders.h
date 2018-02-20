//
// Created by ahodges on 20/02/18.
//

#ifndef BOX_GAME_SHADERS_H
#define BOX_GAME_SHADERS_H
#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/filesystem.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Shaders {

    //Program ID:
    unsigned int ID;



    //Constructor reads and builds shader
    Shaders(std::string const& vertexPath, std::string const& fragmentPath);

    void changeTexture(std::string const& vertexPath, std::string const& fragmentPath);

    //use/activate shader
    void use();
    //utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w) const;
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;


};


#endif //BOX_GAME_SHADERS_H
