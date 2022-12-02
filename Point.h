//
// Created by little_www on 2022/12/2.
//

#ifndef VECTOR_POINT_H
#define VECTOR_POINT_H

class Point {
    friend class Vector;
    friend class Segment;
    friend class Plane;
    friend class SegmentWithPlane;
    friend class TriangleWithPlane;
public:
    Point(double x, double y, double z);
    Point();
    Point operator+(const Point &p2);//加 点
    Point operator-(const Point &p2);//减
    void output();//输出
private:
    double x;
    double y;
    double z;
};


#endif //VECTOR_POINT_H
