//
// Created by Jared V. Samonte on 2021-12-23
//
// Stub code to test the framework. Feel free to ignore or change.
//

#ifndef TAKE_HOME_TEST_FROMFILE_H
#define TAKE_HOME_TEST_FROMFILE_H

// STL
#include <string>
#include <forward_list>
#include "linesegment.h"

std::string stringFromJSON(const char* filename);
void functionsFromPython(std::forward_list<Linesegment> before_list, std::forward_list<Linesegment> after_list);

#endif //TAKE_HOME_TEST_FROMFILE_H
