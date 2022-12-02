//
// Created by little_www on 2022/12/1.
//

#include "Vector.h"
#include <iostream>
#include <cmath>
#include "assert.h"
#define PI 3.1415926;

template <typename Type>
Vector<Type>::Vector(Type x,Type y,Type z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

template <typename Type>
Vector<Type> Vector<Type>:: operator+ (const Vector<Type> &v2)
{
    return Vector<Type>(this->x + v2.x, this->y + v2.y, this->z + v2.z);
}

template <typename Type>
Vector<Type> Vector<Type>:: operator- (const Vector<Type> &v2)
{
    return Vector<Type>(this->x - v2.x, this->y - v2.y, this->z - v2.z);
}

template <typename Type>
Vector<Type> Vector<Type>::operator*(int number)
{
    return Vector<Type>(this->x * number, this->y * number, this->z * number);
}

template <typename Type>
Type Vector<Type>::dot(const Vector<Type> &v2)
{
    return (this->x * v2.x) + (this->y * v2.y) + (this->z * v2.z);
}

template <typename Type>
Vector<Type> Vector<Type>::cross(const Vector<Type> &v2)
{
    int x1 = this->x;
    int x2 = v2.x;
    int y1 = this->y;
    int y2 = v2.y;
    int z1 = this->z;
    int z2 = v2.z;
    return Vector<Type>((y1 * z2) - (y2 * z1),(z1 * x2) - (z2 * x1),(x1 * y2) - (x2 * y1));
}

template <typename Type>
Type Vector<Type>::norm()
{
    return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
}

template <typename Type>
Type Vector<Type>::angle(Vector<Type> v2)
{
    double norm_v1 = sqrt(this->norm());
    double norm_v2 = sqrt(v2.norm());
    assert(0 != (norm_v1 * norm_v2));
    double cos_angle  = this->dot(v2) / (norm_v1 * norm_v2);
//    return cos_angle;
    if ((this->x * v2.y - v2.x - this->y) > 0){//夹角方向
        return (acos(cos_angle)) * 180 / PI;
    }
    else {
        return -1 * (acos(cos_angle)) * 180 / PI;
    }

}

template <typename Type>
void Vector<Type>::output()
{
    std::cout << "[" << x << "," << y << "," << z << "]" << std::endl;
}
template class Vector<int>;
template class Vector<double>;