//
// Created by little_www on 2022/12/2.
//

#ifndef VECTOR_TRIANGLEWITHPLANE_H
#define VECTOR_TRIANGLEWITHPLANE_H


#include "Plane.h"
#include "Segment.h"

class TriangleWithPlane {
public:
    TriangleWithPlane(Plane plane,Plane triangle);
    bool IntersectionDfTriangleAndPlane();//三角面片与平面
    Segment GetSegment();//获取线段
private:
    Plane plane;
    Plane triangle;
    Segment segment;
};


#endif //VECTOR_TRIANGLEWITHPLANE_H
