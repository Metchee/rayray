// include/IObject.hpp
#pragma once
#include <iostream>
#include "IMaterial.hpp"

class IObject {
public:
    virtual ~IObject() = default;
    virtual IMaterial &getMaterial() = 0;
};