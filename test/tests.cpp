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
    std::cout << "stub_5" << std::endl;
    Py_Initialize();

    PyRun_SimpleString("print('Hello World from Embedded Python!!!')");
    
    Py_Finalize();
    REQUIRE(true);
}

TEST_CASE("stub_6","current directory"){
    std::cout << "stub_6" << std::endl;
    const char *filename = "../test/current_dirt.py";
    Py_Initialize();
    runFromPyton(filename);
    Py_Finalize();
    REQUIRE(true);
}

/*
TEST_CASE("stub_7","test graphs"){
    std::cout << "stub_7" << std::endl;
    const char *filename = "../test/assets/graph.py";
    Py_Initialize();
    runFromPyton(filename);
    Py_Finalize();
    REQUIRE(true);
}
*/



TEST_CASE("stub_8","values from CPP to Python and back"){
    Py_Initialize();
    std::cout << "stub_8" << std::endl;
    const char *filename_list = "../test/assets/1-split.json";
    std::forward_list<Linesegment> list = deserialize_from_string(stringFromJSON(filename_list));
    function_from_python(list);
    Py_Finalize();
    REQUIRE(true);
}

