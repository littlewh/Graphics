//
// Created by little_www on 2022/12/5.
//

#ifndef VECTOR_PLANEWITHPLANE_H
#define VECTOR_PLANEWITHPLANE_H

#include "Plane.h"
#include "Segment.h"

class PlaneWithPlane {
public:
    PlaneWithPlane(Plane plane1,Plane plane2);
    bool IntersectionOfPlaneAndPlane();//三角面片与平面
    Vector GetSegment();//获取线段
private:
    Plane plane1;
    Plane plane2;
    Vector segment;
};


#endif //VECTOR_PLANEWITHPLANE_H
