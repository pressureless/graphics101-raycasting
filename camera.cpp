#include "camera.h"

#include "debugging.h"

#include <cmath> // fabs()
#include <algorithm> // std::max()

namespace graphics101 {

ray3 CameraPerspective::getRay( const vec2& uv ) const {
    
    // Your code goes here.

    // Create a ray3( ray origin point, ray direction ).
    // Since you will be testing for intersections along the ray,
    // you may want to start the ray on the film plane so that objects
    // between the eye() and the film plane aren't drawn.
    
    return ray3( vec3( 0,0,0 ), vec3( 0,0,1 ) );
}

ray3 CameraOrthographic::getRay( const vec2& uv ) const {

    // Your code goes here.

    // Create a ray3( ray origin point, ray direction ).

    return ray3( vec3( 0,0,0 ), vec3( 0,0,1 ) );
}

void Camera::imageDimensionsWithLongEdge( int long_edge_pixels, int& width_out, int& height_out ) const {
    assert( long_edge_pixels > 0 );
    
    const real w = fabs( film_right - film_left );
    const real h = fabs( film_bottom - film_top );
    
    if( w > h ) {
        width_out = long_edge_pixels;
        height_out = std::max( 1L, lround( long_edge_pixels * h / w ) );
    } else {
        height_out = long_edge_pixels;
        width_out = std::max( 1L, lround( long_edge_pixels * w / h ) );
    }
}

}
