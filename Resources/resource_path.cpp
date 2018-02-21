//
// Created by rhodges on 21/02/18.
//

#include "resource_path.hpp"


struct ResourcePath::StaticData
{
    Path programPath_;
    Path resourceBase_;
};

void ResourcePath::setProgramPath(Path const &progPath)
{
    auto& statics = staticData();
    statics.programPath_ = progPath;
    statics.resourceBase_ = progPath.parent_path() / "Resources";
}

ResourcePath::Path const& ResourcePath::get()
{
    return staticData().resourceBase_;
}

ResourcePath::StaticData & ResourcePath::staticData()
{
    static StaticData statics;
    return statics;
}