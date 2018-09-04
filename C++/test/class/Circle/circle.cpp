#include"circle.h"
const double PI = 3.14;
Circle::Circle()
{
    radius = 1.0;
}

Circle::Circle(double radius)
{
    this->radius = radius;

}

double Circle::getArea()
{
    return radius * radius * PI;
}

void Circle::setRadius()
{
    this->radius = 23;
}

double Circle::getRadius()
{
    return radius;
}