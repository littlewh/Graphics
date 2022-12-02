//
// Created by little_www on 2022/12/2.
//

#ifndef VECTOR_SEGMENT_H
#define VECTOR_SEGMENT_H

#include "Point.h"
#include "Vector.h"

class Segment {
    friend class SegmentWithPlane;
public:
    Segment(Point p0,Point p1);

    Segment();

    Vector direction_vector();
private:
    Point p0;
    Point p1;
};


#endif //VECTOR_SEGMENT_H
