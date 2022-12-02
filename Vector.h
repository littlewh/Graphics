//
// Created by little_www on 2022/12/1.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include "Point.h"

class Vector {
    friend class SegmentWithPlane;
public:
    Vector(double x, double y, double z);
    Vector(Point p1,Point p2);
    Vector operator+(const Vector &v2);//加
    Vector operator-(const Vector &v2);//减
    Vector operator*(double number);//数乘
    Vector operator/(double number);//除法
    double dot(const Vector &v2);//点乘
    Vector cross(const Vector &v2);//叉乘
    double length();//模
    double angle(Vector v2);//求夹角
    void output();//输出
private:
    double x;
    double y;
    double z;
};



#endif //VECTOR_VECTOR_H
