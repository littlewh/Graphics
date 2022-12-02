//
// Created by little_www on 2022/12/2.
//

#ifndef VECTOR_PLANE_H
#define VECTOR_PLANE_H

#include "Point.h"
#include "Vector.h"


class Plane {
    friend class SegmentWithPlane;
public:
    Plane(Point p0,Point p1,Point p2);

    Plane();

    Vector normal_vector_unit();
private:
    Point p0;
    Point p1;
    Point p2;
};


#endif //VECTOR_PLANE_H
