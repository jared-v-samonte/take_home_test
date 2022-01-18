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

bool Linesegment::isPointSame(double point_1, double point_2)
{
    return (point_1 == point_2);
}

// Compare Function
bool Linesegment::isSegmentSame(Linesegment segment)
{

    return ((
    (Linesegment::isPointSame(start_point.point_x, segment.getStartPoint().point_x)) && 
    (Linesegment::isPointSame(start_point.point_y, segment.getStartPoint().point_y)) &&
    (Linesegment::isPointSame(end_point.point_x, segment.getEndPoint().point_x)) &&
    (Linesegment::isPointSame(end_point.point_y, segment.getEndPoint().point_y)))
    ||
    ((Linesegment::isPointSame(end_point.point_x, segment.getStartPoint().point_x)) && 
    (Linesegment::isPointSame(end_point.point_y, segment.getStartPoint().point_y)) &&
    (Linesegment::isPointSame(start_point.point_x, segment.getEndPoint().point_x)) &&
    (Linesegment::isPointSame(start_point.point_y, segment.getEndPoint().point_y))));
}

// Print Function
void Linesegment::print()
{
    std::cout <<  "Line Segment: (" << getStartPoint().point_x << "," << getStartPoint().point_y << ") (" << getEndPoint().point_x << "," << getEndPoint().point_y << ")" << std::endl;
}
