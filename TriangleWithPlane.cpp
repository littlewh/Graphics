//
// Created by little_www on 2022/12/2.
//

#include "TriangleWithPlane.h"
#include <cmath>
#include "Segment.h"
#include "SegmentWithPlane.h"
#include "iostream"

#define epsilon 1e-16;

TriangleWithPlane::TriangleWithPlane(Plane plane, Plane triangle) {
    this->plane = plane;
    this->triangle = triangle;
    this->segment = {};
}

bool TriangleWithPlane::IntersectionDfTriangleAndPlane() {
    double ep = epsilon;

    Vector pnv = plane.normal_vector_unit();
    Vector tpv1(plane.p0,triangle.p0);
    Vector tpv2(plane.p0,triangle.p1);
    Vector tpv3(plane.p0,triangle.p2);
    double dot1 = pnv.dot(tpv1);
    double dot2 = pnv.dot(tpv2);
    double dot3 = pnv.dot(tpv3);

    if(fabs(dot1) < ep){
        dot1 = 0.0;
    }
    if(fabs(dot2) < ep){
        dot2 = 0.0;
    }
    if(fabs(dot3) < ep){
        dot3 = 0.0;
    }

//    std::cout<<"dot123: "<<dot1<<" "<<dot2<<" "<<dot3<<std::endl;

    if(dot1 * dot2 > 0 && dot1 * dot3 > 0){
        return false;//三角形在上侧
    }
    else if(dot1 * dot2 < 0 && dot1 * dot3 < 0){
        return false;//三角形在下侧
    }
    else if(dot1 * dot2 * dot3 == 0){
        return false;//共面、点在面上
    }

    if((dot1 > 0 && dot2 > 0 && dot3 < 0) || (dot1 < 0 && dot2 < 0 && dot3 > 0)){
        Segment l1(triangle.p0,triangle.p2);
        Segment l2(triangle.p1,triangle.p2);

        SegmentWithPlane segmentWithPlane1(plane,l1);
        segmentWithPlane1.SegmentInsertPlane();
        Point p1 = segmentWithPlane1.GetPoint();
        SegmentWithPlane segmentWithPlane2(plane,l2);
        segmentWithPlane2.SegmentInsertPlane();
        Point p2 = segmentWithPlane2.GetPoint();

        segment = Segment(p1,p2);
        return true;
    }
    else if((dot2 > 0 && dot3 > 0 && dot1 < 0) || (dot2 < 0 && dot3 < 0 && dot1 > 0)){
        Segment l1(triangle.p1,triangle.p0);
        Segment l2(triangle.p2,triangle.p0);

        SegmentWithPlane segmentWithPlane1(plane,l1);
        segmentWithPlane1.SegmentInsertPlane();
        Point p1 = segmentWithPlane1.GetPoint();
        SegmentWithPlane segmentWithPlane2(plane,l2);
        segmentWithPlane2.SegmentInsertPlane();
        Point p2 = segmentWithPlane2.GetPoint();

        segment = Segment(p1,p2);
        return true;
    }
    else if((dot1 > 0 && dot3 > 0 && dot2 < 0) || (dot1 < 0 && dot3 < 0 && dot2 > 0)){
        Segment l1(triangle.p0,triangle.p1);
        Segment l2(triangle.p2,triangle.p1);

        SegmentWithPlane segmentWithPlane1(plane,l1);
        segmentWithPlane1.SegmentInsertPlane();
        Point p1 = segmentWithPlane1.GetPoint();
        SegmentWithPlane segmentWithPlane2(plane,l2);
        segmentWithPlane2.SegmentInsertPlane();
        Point p2 = segmentWithPlane2.GetPoint();

        segment = Segment(p1,p2);
        return true;
    }
    return false;
}

Segment TriangleWithPlane::GetSegment() {
    return segment;
}