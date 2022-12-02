#include <iostream>
#include "Vector.h"
//#include "Vector.cpp"

void TestInt(){
    Vector<int> v1(1, 2, 3);
    Vector<int> v2(4, 5, 6);
    Vector<int> v3 = v1 + v2;

    std::cout<<"�Ͳ���"<<std::endl;
    v3.output();

    std::cout<<"�����"<<std::endl;
    v3 = v1 - v2;
    v3.output();

    std::cout<<"���˲���"<<std::endl;
    v3 = v1 * 2;
    v3.output();

    std::cout<<"��˲���"<<std::endl;
    int ans_dot = v1.dot(v2);
    std::cout<<ans_dot<<std::endl;

    std::cout<<"��˲���"<<std::endl;
    v3 = v1.cross(v2);
    v3.output();

    std::cout<<"ģ����"<<std::endl;
    std::cout<<v1.norm()<<std::endl;
    std::cout<<v2.norm()<<std::endl;

    std::cout<<"�нǲ���"<<std::endl;
    std::cout<<v1.angle(v2)<<std::endl;
}
void TestDouble(){
    Vector<double> v1(1.5, 2.5, 3.5);
    Vector<double> v2(4.5, 5.5, 6.5);
    Vector<double> v3 = v1 + v2;

    std::cout<<"�Ͳ���"<<std::endl;
    v3.output();

    std::cout<<"�����"<<std::endl;
    v3 = v1 - v2;
    v3.output();

    std::cout<<"���˲���"<<std::endl;
    v3 = v1 * 2;
    v3.output();

    std::cout<<"��˲���"<<std::endl;
    int ans_dot = v1.dot(v2);
    std::cout<<ans_dot<<std::endl;

    std::cout<<"��˲���"<<std::endl;
    v3 = v1.cross(v2);
    v3.output();

    std::cout<<"ģ����"<<std::endl;
    std::cout<<v1.norm()<<std::endl;
    std::cout<<v2.norm()<<std::endl;

    std::cout<<"�нǲ���"<<std::endl;
    std::cout<<v1.angle(v2)<<std::endl;
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
    TestDouble();
    TestInt();
    return 0;
}
