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
    return (getSlope(line_1) == getSlope(line_2));
}

bool isStartMidEnd(double start, double mid, double end)
{
    bool solution = false;
    // start is lower than end
    if((start <= mid) && (mid <= end))
    {
        solution = true;     
    }
    // if end is lower than start
    else if((end <= mid) && (mid <= start))
    {
        solution = true;     
    }
    return solution;
}


bool isOnSegment(Linesegment line, Linesegment::point point)
{
    bool solution = false;
    //checks if the X value is between the start and end point's X values
    if((isStartMidEnd(line.getStartPoint().point_x, point.point_x, line.getEndPoint().point_x)) 
    //checks if the Y value is between the start and end point's Y values
    && (isStartMidEnd(line.getStartPoint().point_y, point.point_y, line.getEndPoint().point_y)))
    {
        solution = true;
    }    
    return (solution);
}

/*
def within(p, q, r):
    "Return true iff q is between p and r (inclusive)."
    return p <= q <= r or r <= q <= p
*/

bool isIntercepting(Linesegment line_1, Linesegment line_2)
{
    bool solution = false;
    if (isOnSegment(line_1, line_2.getStartPoint()))
    {
        solution = true;
    }
    if (isOnSegment(line_1, line_2.getEndPoint()))
    {
        solution = true;
    }
    if (isOnSegment(line_2, line_1.getStartPoint()))
    {
        solution = true;
    }
    if (isOnSegment(line_2, line_1.getEndPoint()))
    {
        solution = true;
    }
    return solution;
}


bool isMerging(Linesegment line_1, Linesegment line_2)
{
    return (hasSameSlope(line_1, line_2) && isIntercepting(line_1, line_2));
}

void printMergingLines(Linesegment line_1, Linesegment line_2)
{
    if(line_1.isSegmentSame(line_2))
    {
        std::cout << std::endl <<"--------The lines are identical---------"<< std::endl;
        line_1.print();
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl <<"--------The following lines merge---------"<< std::endl;
        line_1.print();
        line_2.print();
        std::cout << "------------------------------------------" << std::endl;
    }
}


void compareEveryLine(std::forward_list<Linesegment> list)
{
    std::cout << std::endl;
    std::forward_list<Linesegment>::iterator iterator_erase = list.before_begin();
    for (std::forward_list<Linesegment>::iterator iterator_i = list.begin(); iterator_i != list.end(); ++iterator_i)
    {
        for (std::forward_list<Linesegment>::iterator iterator_j = list.begin(); iterator_j != list.end(); ++iterator_j)
        {
            if(isMerging(*iterator_i, *iterator_j))
            {
                printMergingLines(*iterator_i, *iterator_j);;
            }
        }
        //list.erase_after(iterator_erase);
        //iterator_erase = iterator_i;
    }
    std::cout << std::endl;
}