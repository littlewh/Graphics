//
// Created by little_www on 2022/12/2.
//

#include "Plane.h"

Plane::Plane(Point p0, Point p1, Point p2)
{
    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;

    double x1 = p0.x;
    double y1 = p0.y;
    double z1 = p0.z;
    double x2 = p1.x;
    double y2 = p1.y;
    double z2 = p1.z;
    double x3 = p2.x;
    double y3 = p2.y;
    double z3 = p2.z;

    A = (y3 - y1)*(z3 - z1) - (z2 -z1)*(y3 - y1);
    B = (x3 - x1)*(z2 - z1) - (x2 - x1)*(z3 - z1);
    C = (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);
    D = -(A * x1 + B * y1 + C * z1);
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
