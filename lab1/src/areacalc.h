#ifndef AREACALC_H
#define AREACALC_H

class AreaCalc
{
public:
    double calculateSquare(double side);

    double calculateRectangle(double length, double width);

    double calculateParallelogram(double base, double height);

    double calculateRhombus(double diagonal1, double diagonal2);

    double calculateTriangle(double base, double height);

    double calculateTrapezoid(double base1, double base2, double height);

    double calculateCircle(double radius);

    double calculateSector(double radius, double angle);
};

#endif // AREACALC_H
