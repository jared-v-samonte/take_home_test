//
// Created by Nikolay Shulga on 2019-06-18.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include "deserialize.h"
#include "fromjson.h"
#include "linesegment.h"

// stub to test the framework. Replace/modify as needed.
TEST_CASE("stub_1","[deserialize_lines]"){
    std::string input{"{\"lines\":[{\"id\":\"0-1\",\"start\":[373.44034013711515,-582.9714893905727],\"end\":[562.5097926743379,67.6201009971137]},{\"id\":\"0-2\",\"start\":[-395.24361297250138,-598.0232377709511],\"end\":[373.44034013711515,-582.9714893905727]}]}"};
    deserialize_from_string(input);
    REQUIRE(true);
}


TEST_CASE("stub_2","[readfile]"){
    const char *filename = "../test/assets/1-reference.json";
    std::cout << jsonToString(filename);
    REQUIRE(true);
}

TEST_CASE("stub_3","[deserialize_lines + readfile]"){
    const char *filename = "../test/assets/1-reference.json";
    deserialize_from_string(jsonToString(filename));
    REQUIRE(true);
}


TEST_CASE("stub_4","math]"){
    std::string input{"{\"lines\":[{\"id\":\"0-1\",\"start\":[373.44034013711515,-582.9714893905727],\"end\":[562.5097926743379,67.6201009971137]},{\"id\":\"0-2\",\"start\":[-395.24361297250138,-598.0232377709511],\"end\":[373.44034013711515,-582.9714893905727]}]}"};
    deserialize_from_string(input);
    REQUIRE(true);
}
