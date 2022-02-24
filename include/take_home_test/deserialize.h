//
// Created by the professor on 2019-06-18.
//
// Stub code to test the framework. Feel free to ignore or change.
//

#ifndef TAKE_HOME_TEST_DESERIALIZE_H
#define TAKE_HOME_TEST_DESERIALIZE_H

// STL
#include <string>
#include <forward_list>
#include "linesegment.h"

std::forward_list<Linesegment> deserialize_from_string(std::string const& json_data);

#endif //TAKE_HOME_TEST_DESERIALIZE_H

