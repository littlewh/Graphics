//
// Created by little_www on 2022/12/1.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <iostream>
template <typename Type>
class Vector {
public:
    Vector(Type x, Type y, Type z);
    Vector operator+(const Vector<Type> &v2);//加
    Vector operator-(const Vector<Type> &v2);//减
    Vector operator*(int number);//数乘
    Type dot(const Vector<Type> &v2);//点乘
    Vector cross(const Vector<Type> &v2);//叉乘
    Type norm();//模的平方
    Type angle(Vector<Type> v2);//求夹角
    void output();//输出
private:
    Type x;
    Type y;
    Type z;
};

#endif //VECTOR_VECTOR_H
