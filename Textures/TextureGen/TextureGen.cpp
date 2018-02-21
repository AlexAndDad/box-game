//
// Created by ahodges on 20/02/18.
//

#include "TextureGen.h"
#include "Resources/resource_path.hpp"

TextureGen::TextureGen(std::string texturePath)
{
    //1) generate texture
    stbi_set_flip_vertically_on_load(true);

    //Generate texture ID
    glGenTextures(1, &texture);
    //Bind texture
    glBindTexture(GL_TEXTURE_2D, texture);
    //Load texture from file
    int width, height, nrChannels;

    auto filePath = ResourcePath::get() / "Textures" / texturePath;

    unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        //Generate texture using previously loaded data
        if (nrChannels == 3)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        }
        else
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        }

        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    //Free image data memory
    stbi_image_free(data);
}
