//
// Created by Jared V. Samonte on 2021-12-26
//
#include "Linesegment.h"
#include <forward_list>
#include <iostream>


Linesegment::Linesegment(){}
Linesegment::Linesegment(double start_x, double start_y, double end_x, double end_y)
{
    setStartX(start_x);
    setStartY(start_y);
    setEndX(end_x);
    setEndY(end_y);
}

// Member Functions()

// Setter Functions
void Linesegment::setStartX(double start_x)
{
    start_point.point_x = start_x;
}
void Linesegment::setStartY(double start_y)
{
    start_point.point_y = start_y;
}
void Linesegment::setEndX(double end_x)
{
    end_point.point_x = end_x;
}
void Linesegment::setEndY(double end_y)
{
    end_point.point_y = end_y;
}

// Getter Functions
Linesegment::point Linesegment::getStartPoint()
{
    return start_point;
}
Linesegment::point Linesegment::getEndPoint()
{
    return end_point;
}

// Compare Function
bool Linesegment::isSegmentSame(Linesegment segment)
{
    bool solution = true;
    if (start_point.point_x != segment.getStartPoint().point_x) {solution = false;}
    if (start_point.point_y != segment.getStartPoint().point_y) {solution = false;}
    if (end_point.point_x != segment.getEndPoint().point_x) {solution = false;}
    if (end_point.point_y != segment.getEndPoint().point_y) {solution = false;}
    return solution;
}

// Print Function
void Linesegment::print()
{
    std::cout << "Start of String" << std::endl;
    std::cout <<  "Start Point X Coordiante " << getStartPoint().point_x << std::endl;
    std::cout <<  "Start Point X Coordiante " << getStartPoint().point_y << std::endl;
    std::cout <<  "End Point X Coordiante " << getEndPoint().point_x << std::endl;
    std::cout <<  "End Point Y Coordiante " << getEndPoint().point_y << std::endl;
    std::cout << "End of String" << std::endl;
}
