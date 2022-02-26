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
#include <limits>




// gets slope of a line
float getSlope(Linesegment line)
{
    double x_difference = line.getStartPoint().point_x - line.getEndPoint().point_x;
    double  y_difference = line.getStartPoint().point_y - line.getEndPoint().point_y;
    double solution = y_difference/x_difference;
    return (float)solution;
}

// checks if two lines have the same slope
bool hasSameSlope(Linesegment line_1, Linesegment line_2)
{
    return std::abs(getSlope(line_1) - getSlope(line_2)) < std::numeric_limits<float>::epsilon();
}

bool isStartMidEnd(double start, double mid, double end)
{
    return (((start <= mid) && (mid <= end)) || ((end <= mid) && (mid <= start)));
}


// checks if a a point is on a line
bool isPointOnSegment(Linesegment line, Linesegment::point point)
{  
    return ((isStartMidEnd(line.getStartPoint().point_x, point.point_x, line.getEndPoint().point_x)) && 
    //checks if the Y value is between the start and end point's Y values
   (isStartMidEnd(line.getStartPoint().point_y, point.point_y, line.getEndPoint().point_y)));
}

// checks if two linces a intercepts
bool isIntercepting(Linesegment line_1, Linesegment line_2)
{
    if (isPointOnSegment(line_1, line_2.getStartPoint())) return true;
    if (isPointOnSegment(line_1, line_2.getEndPoint())) return true;
    if (isPointOnSegment(line_2, line_1.getStartPoint())) return true;
    if (isPointOnSegment(line_2, line_1.getEndPoint())) return true;
    return false;
}



// checks is two lines are parallels and intercepts
bool isMerging(Linesegment line_1, Linesegment line_2)
{
    return (hasSameSlope(line_1, line_2) && isIntercepting(line_1, line_2));
}

// not yet used
double yEndFromLineArray(Linesegment lines[])
{
    double end;
    end = std::max(lines[0].getStartPoint().point_y, lines[0].getEndPoint().point_y);
    end = std::max(end, lines[1].getStartPoint().point_y);
    end = std::max(end, lines[1].getEndPoint().point_y);
    return end;
}

// not yet used
double yStartFromLineArray(Linesegment lines[])
{
    double start;
    start = std::min(lines[0].getStartPoint().point_y, lines[0].getEndPoint().point_y);
    start = std::min(start, lines[1].getStartPoint().point_y);
    start = std::min(start, lines[1].getEndPoint().point_y);
    return start;
}

// gets X point from the end point
double xEndFromLines(Linesegment line_1, Linesegment line_2)
{
    double end;
    end = std::max(line_1.getStartPoint().point_x, line_1.getEndPoint().point_x);
    end = std::max(end, line_2.getStartPoint().point_x);
    end = std::max(end, line_2.getEndPoint().point_x);
    return end;
}

// gets X point from the start point
double xStartFromLines(Linesegment line_1, Linesegment line_2)
{
    double start;
    start = std::min(line_1.getStartPoint().point_x, line_1.getEndPoint().point_x);
    start = std::min(start, line_2.getStartPoint().point_x);
    start = std::min(start, line_2.getEndPoint().point_x);
    return start;
}

// checks both points form lines to find y point
double yFromXAndLines(double x_value, Linesegment line[])
{
    double y_value;
    if(x_value == line[0].getStartPoint().point_x)
    {
        y_value = line[0].getStartPoint().point_y;
    }
    else if(x_value == line[0].getEndPoint().point_x)
    {
        y_value = line[0].getEndPoint().point_y;
    }
    else if(x_value == line[1].getStartPoint().point_x)
    {
        y_value = line[1].getStartPoint().point_y;
    }
    else if(x_value == line[1].getEndPoint().point_x)
    {
        y_value = line[1].getEndPoint().point_y;
    }
    return y_value;
}

// merge the two Linesegment objects into one
Linesegment mergeLines(Linesegment line_1, Linesegment line_2)
{
    Linesegment new_segment;
    Linesegment lines[2] = {line_1, line_2};
    double start_x = xStartFromLines(line_1, line_2);
    double end_x = xEndFromLines(line_1, line_2);
    double start_y = yFromXAndLines(start_x, lines);
    double end_y = yFromXAndLines(end_x, lines);
    new_segment.setStartX(start_x);
    new_segment.setStartY(start_y);
    new_segment.setEndX(end_x);
    new_segment.setEndY(end_y);
    return new_segment;
}

// checks if a Linesegment is already in the list
bool isLineAlreadyinList(Linesegment line, std::forward_list<Linesegment> list)
{
    bool already_in_list = false;
    for (std::forward_list<Linesegment>::iterator iterator = list.begin(); iterator != list.end() && (!(already_in_list)); ++iterator)
    {
        if (line.isSegmentSame(*iterator))
        {
            already_in_list = true;
        }
    } 
    return already_in_list;
}

// inputs new Linesegment htat are merged into a new forward list
std::forward_list<Linesegment> compareEveryLine(std::forward_list<Linesegment> list)
{
    std::forward_list<Linesegment> merged_list;
    std::forward_list<Linesegment>::iterator new_line_iterator = merged_list.before_begin();
    for (std::forward_list<Linesegment>::iterator iterator_i = list.begin(); iterator_i != list.end(); ++iterator_i)
    {
        for (std::forward_list<Linesegment>::iterator iterator_j = list.begin(); iterator_j != list.end(); ++iterator_j)
        {
            if(isMerging(*iterator_i, *iterator_j))
            {
                Linesegment new_segment = mergeLines(*iterator_i, *iterator_j); 
                if (((!isLineAlreadyinList(new_segment, list))) && (!isLineAlreadyinList(new_segment, merged_list)))
                {
                    new_line_iterator = merged_list.insert_after(new_line_iterator, new_segment);
                }
            }
        }
    }
    return merged_list;
}