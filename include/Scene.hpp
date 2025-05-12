#pragma once
#include <iostream>
#include "IObject.hpp"
#include <libconfig.h++>

class Scene {
    public:
        Scene(int ac, const char *av[]) {
            // TODO: Implement parsing of the config file
        }
        void addObject(std::unique_ptr<IObject> obj);
        std::unique_ptr<IObject> createObject(const std::string &type);
    private:
        std::vector<std::unique_ptr<IObject>> objects_;
};