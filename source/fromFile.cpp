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
//#include <pyhelper.hpp>



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

void runFromPyton(const char* filename)
{
	FILE* filepointer;

	filepointer = _Py_fopen(filename, "r");
	PyRun_SimpleFile(filepointer, filename);
  std::cout << filename << std::endl;
}

extern "C" PyObject *get_python_class()
{
  PyObject *module_name, *module, *dict, *python_class, *object;
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append(\"../test/assets\")");

  module_name = PyUnicode_FromString("functions"); 
  module = PyImport_Import(module_name);
  
  // dict is a borrowed reference.
  dict = PyModule_GetDict(module);

  // Builds the name of a callable class
  python_class = PyDict_GetItemString(dict, "List");

  object = PyObject_CallObject(python_class, nullptr);

  return object;
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

void old_append_linesegment(Linesegment line, PyObject* object)
{
  PyObject *add_linesegment, *value_1, *value_2, *value_3, *value_4, values;

  // gets line values and turns them into PyObjects
  value_1 = PyFloat_FromDouble(line.getStartPoint().point_x);
  value_2 = PyFloat_FromDouble(line.getStartPoint().point_y);
  value_3 = PyFloat_FromDouble(line.getEndPoint().point_x);
  value_4 = PyFloat_FromDouble(line.getEndPoint().point_y);
  //values = get_line_values(line, object);

  // gets the method name
  add_linesegment = PyUnicode_FromString("addLineToOriginal");

  //executr method
  PyObject_CallMethodObjArgs(object, add_linesegment, value_1, value_2, value_3, value_4, NULL);
}

void new_append_linesegment(Linesegment line, PyObject* object)
{
  PyObject *add_linesegment, *value_1, *value_2, *value_3, *value_4;

  // gets line values and turns them into PyObjects
  value_1 = PyFloat_FromDouble(line.getStartPoint().point_x);
  value_2 = PyFloat_FromDouble(line.getStartPoint().point_y);
  value_3 = PyFloat_FromDouble(line.getEndPoint().point_x);
  value_4 = PyFloat_FromDouble(line.getEndPoint().point_y);

  // gets the method name
  add_linesegment = PyUnicode_FromString("addLineToNew");

  //executr method
  PyObject_CallMethodObjArgs(object, add_linesegment, value_1, value_2, value_3, value_4, NULL);
}

void printNewList(PyObject* object)
{
  PyObject *print_link_list = PyUnicode_FromString("printNewList");

  PyObject_CallMethodObjArgs(object, print_link_list, NULL);
}

void printOriginalList(PyObject* object)
{
  PyObject *print_link_list = PyUnicode_FromString("printOriginalList");

  PyObject_CallMethodObjArgs(object, print_link_list, NULL);
}

void display_results(PyObject* object)
{
  PyObject * method = PyUnicode_FromString("display");

  PyObject_CallMethodObjArgs(object, method, NULL);
}

void oldListTransfer(std::forward_list<Linesegment> list, PyObject* object)
{
  for (std::forward_list<Linesegment>::iterator iterator_i = list.begin(); iterator_i != list.end(); ++iterator_i)
  {
    old_append_linesegment(*iterator_i, object);
  }
}

void newListTransfer(std::forward_list<Linesegment> list, PyObject* object)
{
  for (std::forward_list<Linesegment>::iterator iterator_i = list.begin(); iterator_i != list.end(); ++iterator_i)
  {
    new_append_linesegment(*iterator_i, object);
  }
}

void functionsFromPython(std::forward_list<Linesegment> old_list, std::forward_list<Linesegment> new_list)
{
  PyObject *object = get_python_class();
  oldListTransfer(old_list, object);
  newListTransfer(new_list, object);
  display_results(object);
}