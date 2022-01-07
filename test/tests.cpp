//
// Created by Nikolay Shulga on 2019-06-18.
//

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <fcntl.h>

#include "fromFile.h"
#include "linesegment.h"
#include "math.h"
#include "deserialize.h"
#include <forward_list>
#include <stdio.h>
#include <curses.h>
#include <Python.h>



// stub to test the framework. Replace/modify as needed.
TEST_CASE("stub_1","[deserialize_lines]"){
    std::cout << "stub_1" << std::endl;
    std::string input{"{\"lines\":[{\"id\":\"0-1\",\"start\":[373.44034013711515,-582.9714893905727],\"end\":[562.5097926743379,67.6201009971137]},{\"id\":\"0-2\",\"start\":[-395.24361297250138,-598.0232377709511],\"end\":[373.44034013711515,-582.9714893905727]}]}"};
    deserialize_from_string(input);
    REQUIRE(true);
}


TEST_CASE("stub_2","[readfile]"){
    std::cout << "stub_2" << std::endl;
    const char *filename = "../test/assets/1-split.json";
    std::cout << stringFromJSON(filename);
    REQUIRE(true);
}

TEST_CASE("stub_3","[deserialize_lines + readfile]"){
    std::cout << "stub_3" << std::endl;
    const char *filename = "../test/assets/1-split.json";
    deserialize_from_string(stringFromJSON(filename));
    REQUIRE(true);
}


TEST_CASE("stub_4","math]"){
    std::cout << "stub_4" << std::endl;
    const char *filename = "../test/assets/1-split.json";
    compareEveryLine(deserialize_from_string(stringFromJSON(filename)));
    REQUIRE(true);
}

TEST_CASE("stub_5","python_message"){
    Py_Initialize();

    PyRun_SimpleString("print('Hello World from Embedded Python!!!')");
    
    Py_Finalize();
    REQUIRE(true);
}

TEST_CASE("stub_6","python_file"){
    const char *filename = "../test/assets/test.py";
    runFromPyton(filename);
    REQUIRE(true);
}


TEST_CASE("stub_7","python_gui"){
    const char *filename = "../test/assets/gui.py";
    runFromPyton(filename);
    REQUIRE(true);
}

