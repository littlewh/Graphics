//
// Created by little_www on 2022/12/2.
//

#include "Plane.h"

Plane::Plane(Point p0, Point p1, Point p2)
{
    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;
}

Vector Plane::normal_vector_unit()
{
    Vector v1(p0,p1);
    Vector v2(p0,p2);

    Vector v3 = v1.cross(v2);
    v3 = v3/v3.length();

    return v3;
}

Plane::Plane() {

}
