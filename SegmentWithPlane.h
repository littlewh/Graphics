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
    bool SegmentInsertPlane();
private:
    Plane plane;
    Segment segment;
};


#endif //VECTOR_SEGMENTWITHPLANE_H
