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
void runFromPyton(const char* filename);
void lines_from_list(const char* filename);
void function_from_python(std::forward_list<Linesegment> list);

#endif //TAKE_HOME_TEST_FROMFILE_H
