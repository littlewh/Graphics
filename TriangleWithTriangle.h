//
// Created by little_www on 2022/12/5.
//

#ifndef VECTOR_TRIANGLEWITHTRIANGLE_H
#define VECTOR_TRIANGLEWITHTRIANGLE_H

#include "Plane.h"
#include "Segment.h"

class TriangleWithTriangle {
public:
    TriangleWithTriangle(Plane triangle1,Plane triangle2);
    bool IntersectionOfTriangleAndTriangle();//三角面片与平面
    bool DegenerationCheck();
    bool SignalCheck(Plane triangle,Vector pnv,double d);
    bool OverlayCheck(double a,double b,double c,double d);
    Vector GetSegment();//获取线段
private:
    Plane triangle1;
    Plane triangle2;
    Vector segment;
};


#endif //VECTOR_TRIANGLEWITHTRIANGLE_H
