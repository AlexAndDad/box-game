//
// Created by rhodges on 21/02/18.
//

#ifndef BOX_GAME_RESOURCE_PATH_HPP
#define BOX_GAME_RESOURCE_PATH_HPP

#include <boost/filesystem.hpp>

struct ResourcePath {

    using Path = boost::filesystem::path;

    static void setProgramPath(Path const& progPath);

    static Path const& get();


private:
    struct StaticData;
    static StaticData& staticData();


};


#endif //BOX_GAME_RESOURCE_PATH_HPP
