//
// Created by Jared V. Samonte on 2021-12-26
//
// Stub code to test the framework. Feel free to ignore or change.
//

#ifndef TAKE_HOME_TEST_LINESEGMENT_H
#define TAKE_HOME_TEST_LINESEGMENT_H

class linesegment
{
    // Access specifier
    public:
    struct point
    {
        double point_x;
        double point_y;
    };
    void setStartX(double start_x);
    void setStartY(double start_Y);
    void setEndX(double end_x);
    void setEndY(double end_y);
    point getStartPoint();
    point getEndPoint();
    void print();
    linesegment();
    linesegment(double start_x, double start_y, double end_x, double end_y);

    private:
    point start_point;
    point end_point;

};


#endif //TAKE_HOME_TEST_LINESEGMENT_H
