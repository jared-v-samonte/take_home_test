//
// Created by Jared V. Samonte on 2021-12-23
//
// Stub code to test the framework. Feel free to ignore or change.
//

#include <iostream>
#include <forward_list>
#include "math.h"
#include "linesegment.h"
#include "deserialize.h"



float getSlope(Linesegment line)
{
    float x_difference = line.getStartPoint().point_x - line.getEndPoint().point_x;
    float  y_difference = line.getStartPoint().point_y - line.getEndPoint().point_y;
    float solution = y_difference/x_difference;
    return solution;
}

bool hasSameSlope(Linesegment line_1, Linesegment line_2)
{
    return (getSlope(line_1) && getSlope(line_2));
}

bool isOnSegment(Linesegment line, double point)
{
    bool solution = true;
    if (point <= std::max(line.getStartPoint().point_x, line.getEndPoint().point_x))
    {
        solution = false;
    }
    if (point >= std::min(line.getStartPoint().point_x, line.getEndPoint().point_x))
    {
        solution = false;
    }
    if (point <= std::max(line.getStartPoint().point_y, line.getEndPoint().point_y))
    {
        solution = false;
    }
    if (point >= std::min(line.getStartPoint().point_y, line.getEndPoint().point_y))
    {
        solution = false;
    }
    return solution;
}

bool isIntercepting(Linesegment line_1, Linesegment line_2)
{
    bool solution = true;
    if (!isOnSegment(line_1, line_2.getStartPoint().point_x))
    {
        solution = false;
    }
    if (!isOnSegment(line_1, line_2.getStartPoint().point_y))
    {
        solution = false;
    }
    if (!isOnSegment(line_1, line_2.getEndPoint().point_x))
    {
        solution = false;
    }
    if (!isOnSegment(line_1, line_2.getEndPoint().point_y))
    {
        solution = false;
    }
    return solution;
}


bool isMerging(Linesegment line_1, Linesegment line_2)
{
    return (hasSameSlope(line_1, line_2), isIntercepting(line_1, line_2));
}

void printMergingLines(Linesegment line_1, Linesegment line_2)
{
    std::cout << "--------The following lines merge---------"<< std::endl;
    line_1.print();
    line_2.print();
    std::cout << "------------------------------------------" << std::endl << std::endl;
}
void printNotMergingLines(Linesegment line_1, Linesegment line_2)
{
    std::cout << "--------The following do NOT merge---------"<< std::endl;
    line_1.print();
    line_2.print();
    std::cout << "------------------------------------------" << std::endl << std::endl;
}

void printMergingResults(Linesegment line_1, Linesegment line_2)
{
    if(isMerging(line_1, line_2))
    {
        printMergingLines(line_1, line_2);
    }
    else
    {
        printNotMergingLines(line_1, line_2);
    }
}


void compareEveryLine(std::forward_list<Linesegment> list)
{
    std::forward_list<Linesegment>::iterator iterator_erase = list.before_begin();
    for (std::forward_list<Linesegment>::iterator iterator_i = list.begin(); iterator_i != list.end(); ++iterator_i)
    {
        for (std::forward_list<Linesegment>::iterator iterator_j = list.begin(); iterator_j != list.end(); ++iterator_j)
        {
            printMergingResults(*iterator_i, *iterator_j);
        }
        list.erase_after(iterator_erase);
        iterator_erase = iterator_i;
    }
}
