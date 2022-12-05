//
// Created by little_www on 2022/12/1.
//

#include "Vector.h"
#include <iostream>
#include <cmath>
#include "cassert"
#define PI 3.1415926;

Vector::Vector(double x,double y,double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(Point p1,Point p2)
{
    this->x = p2.x - p1.x;
    this->y = p2.y - p1.y;
    this->z = p2.z - p1.z;
}

Vector Vector:: operator+ (const Vector &v2)
{
    return Vector(this->x + v2.x, this->y + v2.y, this->z + v2.z);
}

Vector Vector:: operator- (const Vector &v2)
{
    return Vector(this->x - v2.x, this->y - v2.y, this->z - v2.z);
}

Vector Vector::operator*(double number)
{
    return Vector(this->x * number, this->y * number, this->z * number);
}

Vector Vector::operator/(double number)
{
    assert(number != 0);
    return Vector(this->x / number, this->y / number, this->z / number);
}

double Vector::dot(const Vector &v2)
{
    return (this->x * v2.x) + (this->y * v2.y) + (this->z * v2.z);
}

Vector Vector::cross(const Vector &v2)
{
    int x1 = this->x;
    int x2 = v2.x;
    int y1 = this->y;
    int y2 = v2.y;
    int z1 = this->z;
    int z2 = v2.z;
    return Vector((y1 * z2) - (y2 * z1),(z1 * x2) - (z2 * x1),(x1 * y2) - (x2 * y1));
}

double Vector::length()
{
    double length = (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
    return sqrt(length);
}

double Vector::angle(Vector v2)
{
    double norm_v1 = this->length();
    double norm_v2 = v2.length();
    assert(0 != (norm_v1 * norm_v2));//除数为零
    double cos_angle  = this->dot(v2) / (norm_v1 * norm_v2);
//    return cos_angle;
    if ((this->x * v2.y - v2.x - this->y) > 0){//夹角方向
        return (acos(cos_angle)) * 180 / PI
    }
    else {
        return -1 * (acos(cos_angle)) * 180 / PI
    }

}

void Vector::output()
{
    std::cout << "[" << x << "," << y << "," << z << "]" << std::endl;
}

Vector::Vector() {}
