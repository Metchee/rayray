#include "Scene.hpp"
#include "Objects/include/SphereObj.hpp"

Scene::Scene(int ac, const char *av[])
{
    // TODO: Implement parsing of the config file
}

void Scene::addObject(std::unique_ptr<IObject> obj)
{
    objects_.push_back(std::move(obj));
}

std::unique_ptr<IObject> Scene::createObject(const std::string &type)
{
    if (type == "Sphere")
        return std::make_unique<Sphere>();
    return nullptr;
}
