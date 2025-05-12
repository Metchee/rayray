#include "IMaterial.hpp"
#include "vector.hpp" 

class Basic : public IMaterial {
    public:
        Basic(const Vector3 &color, const Vector3 &diffuse, double shine);
    private:
        Vector3 color_;
        Vector3 diffuse_;
        double shine_;
};
