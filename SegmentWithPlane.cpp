//
// Created by little_www on 2022/12/2.
//

#include "SegmentWithPlane.h"
#include <cmath>

#define epsilon 1e-16;

SegmentWithPlane::SegmentWithPlane(Plane plane, Segment segment)
{
    this->plane = plane;
    this->segment = segment;
}

bool SegmentWithPlane::SegmentInsertPlane()
{
    double t = 0; // 线段要求 0 <= t <= 1，射线要求 0 <= t
    double denominator = segment.direction_vector().dot(plane.normal_vector_unit());
    Vector pVector (segment.p0,plane.p0);

    double ep = epsilon;
    if(fabs(denominator) < ep){//平行
        if(fabs(pVector.dot(plane.normal_vector_unit())) < ep){
            t = 0;
            return true;
        }
        else {
            return false;
        }
    }

    t = (plane.normal_vector_unit().dot(pVector)) / denominator;

    if(t >= 0 && t <= 1){
        double x = segment.p0.x + segment.direction_vector().x*t;
        double y = segment.p0.y + segment.direction_vector().y*t;
        double z = segment.p0.z + segment.direction_vector().z*t;

        Point p(x,y,z);
        p.output();
        return true;
    }
    else {
        return  false;
    }
}



/*
 *  3.14159265358979311599796346854418516159057617187500
 *  3.14159265358979323846264338327950288419716939937510
 */