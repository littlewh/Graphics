#include <iostream>
#include <cstdio>
#include "Vector.h"
#include "Point.h"
#include "Segment.h"
#include "Plane.h"
#include "SegmentWithPlane.h"

void VectorTest(){
    Vector v1(1.5, 2.5, 3.5);
    Vector v2(4.5, 5.5, 6.5);
    Vector v3 = v1 + v2;

    std::cout<<"ºÍ²âÊÔ"<<std::endl;
    v3.output();

    std::cout<<"²î²âÊÔ"<<std::endl;
    v3 = v1 - v2;
    v3.output();

    std::cout<<"Êý³Ë²âÊÔ"<<std::endl;
    v3 = v1 * 2;
    v3.output();

    std::cout<<"µã³Ë²âÊÔ"<<std::endl;
    int ans_dot = v1.dot(v2);
    std::cout<<ans_dot<<std::endl;

    std::cout<<"²æ³Ë²âÊÔ"<<std::endl;
    v3 = v1.cross(v2);
    v3.output();

    std::cout<<"Ä£²âÊÔ"<<std::endl;
    std::cout<<v1.length()<<std::endl;
    std::cout<<v2.length()<<std::endl;

    std::cout<<"¼Ð½Ç²âÊÔ"<<std::endl;
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
        printf("Ïà½»\n");
    }
    else {
        printf("²»Ïà½»\n");
    }
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    VectorTest();
//    PointTest();
    SegWithPlane();
    return 0;
}
