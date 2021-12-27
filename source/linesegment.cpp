//
// Created by Jared V. Samonte on 2021-12-26
//
#include "linesegment.h"
#include <iostream>


linesegment::linesegment(){}
linesegment::linesegment(double start_x, double start_y, double end_x, double end_y)
{
    setStartX(start_x);
    setStartY(start_y);
    setEndX(end_x);
    setEndY(end_y);
}

// Member Functions()
void linesegment::setStartX(double start_x)
{
    linesegment::start_point.point_x = start_x;
}
void linesegment::setStartY(double start_y)
{
    linesegment::start_point.point_y = start_y;
}
void linesegment::setEndX(double end_x)
{
    linesegment::end_point.point_x = end_x;
}
void linesegment::setEndY(double end_y)
{
    linesegment::end_point.point_y = end_y;
}
void linesegment::print()
{
    double temp;
    std::cout << "Start of String" << std::endl;
    std::cout <<  "Start Point X Coordiante" << getStartPoint().point_x << std::endl;
    std::cout <<  "Start Point X Coordiante" << getStartPoint().point_y << std::endl;
    std::cout <<  "End Point X Coordiante" << getEndPoint().point_x << std::endl;
    std::cout <<  "End Point Y Coordiante" << getEndPoint().point_y << std::endl;
    std::cout << "End of String" << std::endl;

}
linesegment::point linesegment::getStartPoint()
{
    return start_point;
}
linesegment::point linesegment::getEndPoint()
{
    return end_point;
}