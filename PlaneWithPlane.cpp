//
// Created by little_www on 2022/12/5.
//

#include "PlaneWithPlane.h"

PlaneWithPlane::PlaneWithPlane(Plane plane1, Plane plane2) {
    this->plane1 = plane1;
    this->plane2 = plane2;
}

bool PlaneWithPlane::IntersectionOfPlaneAndPlane() {
    Vector d = plane1.normal_vector_unit().cross(plane2.normal_vector_unit());

    if(d.length() == 0){
        return false;
    }
    double s1 = plane1.D;
    double s2 = plane2.D;

    double n1n2dot = plane1.normal_vector_unit().dot(plane2.normal_vector_unit());
    double n1dot = plane1.normal_vector_unit().dot(plane1.normal_vector_unit());
    double n2dot = plane2.normal_vector_unit().dot(plane2.normal_vector_unit());
    double a = (s2 * n1n2dot - s1 * n2dot) / (n1n2dot * n1n2dot - n1dot * n2dot);
    double b = (s1 * n1n2dot - s2 * n2dot) / (n1n2dot * n1n2dot - n1dot * n2dot);

    segment = (plane1.normal_vector_unit()*a) + (plane2.normal_vector_unit()*b);

    return true;
}

Vector PlaneWithPlane::GetSegment() {
    return segment;
}