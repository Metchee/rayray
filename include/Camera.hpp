// include/Camera.hpp

#pragma once
#include "vector.hpp"
#include "Ray.hpp"

class Camera {
public:
    Camera(int width, int height, const Vector3& position, const Vector3& rotation, double fov)
        : width_(width), height_(height), position_(position), rotation_(rotation), fov_(fov) {}
    
    Ray getRay(int x, int y) const {
        // Calculate the aspect ratio
        double aspect_ratio = double(width_) / height_;
        
        // Convert FOV from degrees to radians
        double fov_rad = fov_ * M_PI / 180.0;
        
        // Calculate viewport dimensions
        double viewport_height = 2.0 * tan(fov_rad / 2.0);
        double viewport_width = aspect_ratio * viewport_height;
        
        // Calculate viewport vectors
        Vector3 viewport_u(viewport_width, 0, 0);
        Vector3 viewport_v(0, viewport_height, 0);
        
        // Calculate pixel deltas
        double pixel_delta_u = viewport_width / width_;
        double pixel_delta_v = viewport_height / height_;
        
        // Calculate viewport upper left
        Vector3 viewport_upper_left = position_ - Vector3(0, 0, 1) - viewport_u/2 - viewport_v/2;
        
        // Calculate pixel position
        double u = double(x) / width_;
        double v = double(y) / height_;
        Vector3 pixel_center = viewport_upper_left + u * viewport_u + v * viewport_v;
        
        // Apply camera rotation (simplified version)
        // In a full implementation, you would use a rotation matrix
        
        // Create and return ray
        return Ray(position_, unit_vector(pixel_center - position_));
    }
    
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    
private:
    int width_;
    int height_;
    Vector3 position_;
    Vector3 rotation_;
    double fov_;
};