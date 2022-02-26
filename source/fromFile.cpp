//
// Created by Jared V. Samonte on 2021-12-23
//
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <Python.h>
#include <cmath>
#include "linesegment.h"



using namespace rapidjson;

std::string stringFromJSON(const char* filename)
{
  char readBuffer[80000];

  //opens stream and reads file with buffer
  FILE* filepointer = fopen(filename, "r");
  FileReadStream is(filepointer, readBuffer, sizeof(readBuffer));

  // uses rapidjson and the close stream
  Document jsonDocument;
  jsonDocument.ParseStream(is);
  fclose(filepointer);

  // uses rapid json again writes from json to string
  StringBuffer buffer;
  Writer<StringBuffer> writer(buffer);
  jsonDocument.Accept(writer);
  std::string jsonString(buffer.GetString(), buffer.GetSize());

  //return solution 
  return jsonString;
}

//runs python file entered through string format
//***(warning) location of python file must be kept in mind in regards of THIS files location***
void runFromPyton(const char* filename)
{
	FILE* filepointer;

	filepointer = _Py_fopen(filename, "r");
	PyRun_SimpleFile(filepointer, filename);
  std::cout << filename << std::endl;
}

PyObject * get_line_values(Linesegment line, PyObject* object)
{
  PyObject *values;
  double value_1, value_2, value_3, value_4; 
  int dimensions = 1;

  value_1 = line.getStartPoint().point_x;
  value_2 = line.getStartPoint().point_y;
  value_3 = line.getEndPoint().point_x;
  value_4 = line.getEndPoint().point_y;

  double line_points[] = {value_1, value_2, value_3, value_2};

  //values = PyArray_SimpleNew(dimensions, line_points, NPY_DOUBLE);
  return values;
}

// intializes PyObject of the file and class noted
extern "C" PyObject *get_python_class()
{
  PyObject *module_name, *module, *dict, *python_class, *object;
  PyRun_SimpleString("import sys");
  // finds python file based on this file's location
  PyRun_SimpleString("sys.path.append(\"../test/assets\")");

  // python file location
  module_name = PyUnicode_FromString("functions"); 
  module = PyImport_Import(module_name);
  
  // dict is a borrowed reference.
  dict = PyModule_GetDict(module);

  // Builds the name of a callable class
  // selects python class to be used
  python_class = PyDict_GetItemString(dict, "List");

  object = PyObject_CallObject(python_class, nullptr);

  return object;
}


//the method 
void appendSegmentByMethodToPyObject(Linesegment line, const char* methodName, PyObject* object)
{
  PyObject *add_linesegment, *value_1, *value_2, *value_3, *value_4;

  // gets line values and turns them into PyObjects
  value_1 = PyFloat_FromDouble(line.getStartPoint().point_x);
  value_2 = PyFloat_FromDouble(line.getStartPoint().point_y);
  value_3 = PyFloat_FromDouble(line.getEndPoint().point_x);
  value_4 = PyFloat_FromDouble(line.getEndPoint().point_y);

  // gets the method name
  add_linesegment = PyUnicode_FromString(methodName);

  //execute method
  PyObject_CallMethodObjArgs(object, add_linesegment, value_1, value_2, value_3, value_4, NULL);
}


void display_results(PyObject* object)
{
  PyObject * method = PyUnicode_FromString("display");

  PyObject_CallMethodObjArgs(object, method, NULL);
}


void transferSegmentByMethodToPyObject(std::forward_list<Linesegment> list, const char* methodName, PyObject* object)
{
  for (std::forward_list<Linesegment>::iterator iterator_i = list.begin(); iterator_i != list.end(); ++iterator_i)
  {
    appendSegmentByMethodToPyObject(*iterator_i, methodName, object);
  }
}

void functionsFromPython(std::forward_list<Linesegment> old_list, std::forward_list<Linesegment> new_list)
{
  PyObject *object = get_python_class();
  transferSegmentByMethodToPyObject(old_list, "addLineToOriginal", object);
  transferSegmentByMethodToPyObject(new_list, "addLineToNew" ,object);
  display_results(object);
}