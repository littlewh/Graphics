//
// Created by little_www on 2022/12/2.
//

#include "Segment.h"

Segment::Segment(Point p0, Point p1)
{
    this->p0 = p0;
    this->p1 = p1;
}

Vector Segment::direction_vector()
{
    Vector v1(p0,p1);

    return v1;
}

Segment::Segment() {

}

void Segment::output() {
    p0.output();
    p1.output();
}