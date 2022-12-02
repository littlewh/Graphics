//
// Created by little_www on 2022/12/2.
//

#include "Point.h"
#include <iostream>

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point Point:: operator+ (const Point &p2)
{
    return Point(this->x + p2.x, this->y + p2.y, this->z + p2.z);
}

Point Point:: operator- (const Point &p2)
{
    return Point(this->x - p2.x, this->y - p2.y, this->z - p2.z);
}

void Point::output()
{
    std::cout << "(" << x << "," << y << "," << z << ")" << std::endl;
}

Point::Point() {

}

