//
// Created by little_www on 2022/12/2.
//

#ifndef VECTOR_SEGMENTWITHPLANE_H
#define VECTOR_SEGMENTWITHPLANE_H

#include "Plane.h"
#include "Segment.h"
#include "Vector.h"

class SegmentWithPlane {
public:
    SegmentWithPlane(Plane plane,Segment segment);
    bool SegmentInsertPlane();//线段与平面
    Point GetPoint();
private:
    Plane plane;
    Segment segment;
    Point point;
};


#endif //VECTOR_SEGMENTWITHPLANE_H
