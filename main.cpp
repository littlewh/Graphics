#include <iostream>
#include <cstdio>
#include "Vector.h"
#include "Point.h"
#include "Segment.h"
#include "Plane.h"
#include "SegmentWithPlane.h"
#include "TriangleWithPlane.h"
#include "TriangleWithTriangle.h"

void VectorTest(){
    Vector v1(1.5, 2.5, 3.5);
    Vector v2(4.5, 5.5, 6.5);
    Vector v3 = v1 + v2;

    std::cout<<"和测试"<<std::endl;
    v3.output();

    std::cout<<"差测试"<<std::endl;
    v3 = v1 - v2;
    v3.output();

    std::cout<<"数乘测试"<<std::endl;
    v3 = v1 * 2;
    v3.output();

    std::cout<<"点乘测试"<<std::endl;
    int ans_dot = v1.dot(v2);
    std::cout<<ans_dot<<std::endl;

    std::cout<<"叉乘测试"<<std::endl;
    v3 = v1.cross(v2);
    v3.output();

    std::cout<<"模测试"<<std::endl;
    std::cout<<v1.length()<<std::endl;
    std::cout<<v2.length()<<std::endl;

    std::cout<<"夹角测试"<<std::endl;
    std::cout<<v1.angle(v2)<<std::endl;
}
void PointTest()
{
    Point p1(1,2,3);
    Point p2(4,5,6);
    p1.output();
    p2.output();
    Vector v(p1,p2);
    v.output();
}
void SegWithPlane()
{
    Point e(0.0,0.0,0.0);
    Point s(0.0,0.0,1.0);
    Segment l(s,e);
    Point a(1.0,0.0,1.0);
    Point b(-9.0,0.0,0.0);
    Point c(0.0,8.0,0.0);
    Plane t(a,b,c);
    SegmentWithPlane ans(t,l);

    if(ans.SegmentInsertPlane() == true){
        printf("线段与平面相交相交,交点坐标为: \n");
        Point point = ans.GetPoint();
        point.output();
    }
    else {
        printf("线段与平面不相交\n");
    }
}

void TriWithPlane(){
    Point a(1.0,0.0,1.0);
    Point b(-9.0,0.0,0.0);
    Point c(0.0,8.0,0.0);
    Plane p(a,b,c);
    Point a2(11.0,0.0,1.0);
    Point b2(-9.0,0.0,3.0);
    Point c2(2.0,-1.0,0.0);
    Plane t(a2,b2,c2);
    TriangleWithPlane ans(p,t);

    if(ans.IntersectionDfTriangleAndPlane() == true){
        printf("三角面片与平面相交,交线的坐标为: \n");
        Segment segment = ans.GetSegment();
        segment.output();
    }
    else {
        printf("三角面片与平面不相交\n");
    }
}
void TriWithTri(){
    Point a(1.0,0.0,1.0);
    Point b(-9.0,0.0,0.0);
    Point c(0.0,8.0,0.0);
    Plane p(a,b,c);
    Point a2(11.0,0.0,1.0);
    Point b2(-9.0,0.0,3.0);
    Point c2(2.0,-1.0,0.0);
    Plane t(a2,b2,c2);

}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    VectorTest();
//    PointTest();
//    SegWithPlane();
    TriWithTri();
    return 0;
}
