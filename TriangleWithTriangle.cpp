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

bool TriangleWithTriangle::OverlayCheck(double a, double b, double c, double d) {
    if(a < c && c < b && b < d){
        return true;
    }
    if(c < a && a < d && d < b){
        return true;
    }
    if(a < c && c < d && d < b){
        return true;
    }
    if(c < a && a < b && b < d){
        return true;
    }
    if(a == c && b == d && c < d){
        return true;
    }

    return false;
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

    Vector v01_temp(triangle1.p0.x,triangle1.p0.y,triangle1.p0.z);
    double v01 = d.dot(v01_temp);
    Vector v02_temp(triangle1.p1.x,triangle1.p1.y,triangle1.p1.z);
    double v02 = d.dot(v02_temp);
    Vector v03_temp(triangle1.p2.x,triangle1.p2.y,triangle1.p2.z);
    double v03 = d.dot(v03_temp);

    Point point(0,0,0);
    Vector tpv1(point,triangle1.p0);
    Vector tpv2(point,triangle1.p1);
    Vector tpv3(point,triangle1.p2);
    double dot1 = pnv2.dot(tpv1) + triangle2.D;
    double dot2 = pnv2.dot(tpv2) + triangle2.D;
    double dot3 = pnv2.dot(tpv3) + triangle2.D;

    if(dot1 - dot3 == 0 || dot2 - dot3 == 0){
        return false;
    }
    double t00 = v01 + (v03 - v01)*dot1/(dot1 - dot3);
    double t01 = v02 + (v03 - v02)*dot2/(dot2 - dot3);

    Vector v11_temp(triangle2.p0.x,triangle2.p0.y,triangle2.p0.z);
    double v11 = d.dot(v11_temp);
    Vector v12_temp(triangle2.p1.x,triangle2.p1.y,triangle2.p1.z);
    double v12 = d.dot(v12_temp);
    Vector v13_temp(triangle2.p2.x,triangle2.p2.y,triangle2.p2.z);
    double v13 = d.dot(v13_temp);

    Vector tpv11(point,triangle2.p0);
    Vector tpv12(point,triangle2.p1);
    Vector tpv13(point,triangle2.p2);
    double dot11 = pnv1.dot(tpv11) + triangle1.D;
    double dot12 = pnv1.dot(tpv12) + triangle1.D;
    double dot13 = pnv1.dot(tpv13) + triangle1.D;

    if(dot11 - dot13 == 0 || dot12 - dot13 == 0){
        return false;
    }
    double t10 = v11 + (v13 - v11)*dot11/(dot11 - dot13);
    double t11 = v12 + (v13 - v12)*dot12/(dot12 - dot13);

    if(OverlayCheck(t00,t01,t10,t11) == false){
        return false;
    }
    double t = std::max(std::max(t00,t01),std::max(t10,t11));
    segment = d * t;

    return true;
}

Vector TriangleWithTriangle::GetSegment() {
    return segment;
}