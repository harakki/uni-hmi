#include "areacalc.h"

#include <math.h>

double AreaCalc::calculateSquare(double side)
{
    return side * side;
}

double AreaCalc::calculateRectangle(double length, double width)
{
    return length * width;
}

double AreaCalc::calculateParallelogram(double base, double height)
{
    return base * height;
}

double AreaCalc::calculateRhombus(double diagonal1, double diagonal2)
{
    return (diagonal1 * diagonal2) / 2;
}

double AreaCalc::calculateTriangle(double base, double height)
{
    return (base * height) / 2;
}

double AreaCalc::calculateTrapezoid(double base1, double base2, double height)
{
    return ((base1 + base2) / 2) * height;
}

double AreaCalc::calculateCircle(double radius)
{
    return M_PI * (radius * radius);
}

double AreaCalc::calculateSector(double radius, double angle)
{
    return (angle / 360.0) * M_PI * (radius * radius);
}
