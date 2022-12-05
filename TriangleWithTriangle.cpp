//
// Created by little_www on 2022/12/5.
//

#include "TriangleWithTriangle.h"
#include "PlaneWithPlane.h"
#include <cmath>
#include <algorithm>

#define epsilon 1e-16;


TriangleWithTriangle::TriangleWithTriangle(Plane triangle1,Plane triangle2){
    this->triangle1 = triangle1;
    this->triangle2 = triangle2;
    this->segment = {};
}

bool TriangleWithTriangle::DegenerationCheck() {
    Vector tpv1(triangle1.p0,triangle1.p1);
    Vector tpv2(triangle1.p0,triangle1.p2);
    Vector tpv3(triangle1.p1,triangle1.p2);
    if(tpv1.dot(tpv2) == 0 || tpv1.dot(tpv3) == 0 || tpv2.dot(tpv3) == 0){
        return false;
    }

    Vector tpv4(triangle2.p0,triangle2.p1);
    Vector tpv5(triangle2.p0,triangle2.p2);
    Vector tpv6(triangle2.p1,triangle2.p2);
    if(tpv4.dot(tpv5) == 0 || tpv4.dot(tpv6) == 0 || tpv5.dot(tpv6) == 0){
        return false;
    }

    return true;
}

bool TriangleWithTriangle::SignalCheck(Plane triangle,Vector pnv,double d) {
    double ep = epsilon;

    Point point(0,0,0);
    Vector tpv1(point,triangle.p0);
    Vector tpv2(point,triangle.p1);
    Vector tpv3(point,triangle.p2);
    double dot1 = pnv.dot(tpv1) + d;
    double dot2 = pnv.dot(tpv2) + d;
    double dot3 = pnv.dot(tpv3) + d;

    if(fabs(dot1) < ep){
        dot1 = 0.0;
    }
    if(fabs(dot2) < ep){
        dot2 = 0.0;
    }
    if(fabs(dot3) < ep){
        dot3 = 0.0;
    }

    if(dot1 * dot2 > 0 && dot1 * dot3 > 0){
        return false;
    }
    else if(dot1 * dot2 < 0 && dot1 * dot3 < 0){
        return false;
    }
    else if(dot1 * dot2 * dot3 == 0){
        return false;
    }

    return true;
}


bool TriangleWithTriangle::IntersectionOfTriangleAndTriangle() {
    double ep = epsilon;

    if(DegenerationCheck() == false){
        return false;//退化
    }

    Vector pnv1 = triangle1.normal_vector_unit();
    if(SignalCheck(triangle2,pnv1,triangle1.D) == false){
        return false;
    }

    if(triangle1.A == triangle2.A && triangle1.B == triangle2.B && triangle1.C == triangle2.C){
        if(triangle1.D != triangle2.D){//共面
            return false;
        }
    }

    Vector pnv2 = triangle2.normal_vector_unit();
    if (SignalCheck(triangle1,pnv2,triangle2.D) == false){
        return false;
    }

    PlaneWithPlane pwp(triangle1,triangle2);
    if(pwp.IntersectionOfPlaneAndPlane() == false){
        return false;
    }
    Vector d = pwp.GetSegment();



    return true;
}

Vector TriangleWithTriangle::GetSegment() {
    return segment;
}