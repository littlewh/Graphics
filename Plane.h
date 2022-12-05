//
// Created by little_www on 2022/12/2.
//

#ifndef VECTOR_PLANE_H
#define VECTOR_PLANE_H

#include "Point.h"
#include "Vector.h"


class Plane {
    friend class SegmentWithPlane;
    friend class TriangleWithPlane;
    friend class TriangleWithTriangle;
    friend class PlaneWithPlane;
public:
    Plane(Point p0,Point p1,Point p2);

    Plane();

    Vector normal_vector_unit();
private:
    Point p0;
    Point p1;
    Point p2;
    double A;
    double B;
    double C;
    double D;
};


#endif //VECTOR_PLANE_H
