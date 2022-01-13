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

static PyObject *get_python_class()
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

void add_linesegment_fromPython(Linesegment line)
{
  PyObject *module_name, *module, *dict, *python_class, *object, *add_linesegment, *value, *value_1, *value_2, *value_3, *value_4;

  value_1 = PyFloat_FromDouble(line.getStartPoint().point_x);
  value_2 = PyFloat_FromDouble(line.getStartPoint().point_y);
  value_3 = PyFloat_FromDouble(line.getEndPoint().point_x);
  value_4 = PyFloat_FromDouble(line.getEndPoint().point_y);

  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append(\"../test/assets\")");

  module_name = PyUnicode_FromString("functions"); 
  module = PyImport_Import(module_name);
  
  // dict is a borrowed reference.
  dict = PyModule_GetDict(module);

  // Builds the name of a callable class
  python_class = PyDict_GetItemString(dict, "List");


  // Creates an instance of the class
  object = PyObject_CallObject(python_class, nullptr);
  add_linesegment = PyUnicode_FromString("add_linesegment");


  //executr method
  PyObject_CallMethodObjArgs(object, add_linesegment, value_1, value_2, value_3, value_4, NULL);
}

void print_list_fromPython()
{
  PyObject *module_name, *module, *dict, *python_class, *object, *print_link_list;


  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append(\"../test/assets\")");

  module_name = PyUnicode_FromString("functions"); 
  module = PyImport_Import(module_name);
  

  // dict is a borrowed reference.
  dict = PyModule_GetDict(module);

  // Builds the name of a callable class
  python_class = PyObject_CallObject(python_class, nullptr);//get_python_class();

  // Creates an instance of the class
  object = PyObject_CallObject(python_class, nullptr);

  print_link_list = PyUnicode_FromString("print_link_list");

  PyObject_CallMethodObjArgs(object, print_link_list, NULL);
}

void print_value_fromPython(double input, double input2)
{
  PyObject *module_name, *module, *dict, *python_class, *object,* method, *value_1, *value_2, *value;

  
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append(\"../test/assets\")");

  

  module_name = PyUnicode_FromString("functions"); 
  module = PyImport_Import(module_name);
  

  // dict is a borrowed reference.
  dict = PyModule_GetDict(module);
  
  // Builds the name of a callable class
  python_class = PyDict_GetItemString(dict, "Testing");

  // Creates an instance of the class
  object = PyObject_CallObject(python_class, nullptr);//get_python_class();


  method = PyUnicode_FromString("print_double");

  value_1 = PyFloat_FromDouble(input);
  value_2 = PyFloat_FromDouble(input2);

  //executr method 
  PyObject_CallMethodObjArgs(object, method, value_1, value_2, NULL);


}

void display_fromPython()
{
  PyObject *module_name, *module, *dict, *python_class, *object, *method, *value;
  

  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append(\"../test/assets\")");

  module_name = PyUnicode_FromString("functions"); 
  module = PyImport_Import(module_name);
  

  // dict is a borrowed reference.
  dict = PyModule_GetDict(module);
  
  // Builds the name of a callable class
  python_class = PyDict_GetItemString(dict, "Testing");//get_python_class();
  
  // Creates an instance of the class
  object = PyObject_CallObject(python_class, nullptr);//get_python_class();

  method = PyUnicode_FromString("display");

  //executr method
  value = PyObject_CallMethodObjArgs(object, method, NULL);

}

void class_list_transfer(std::forward_list<Linesegment> list)
{
  //PyObject* python_instance = PyBytes_FromString(python_class, NULL, NULL);
  std::forward_list<Linesegment>::iterator iterator_erase = list.before_begin();
  for (std::forward_list<Linesegment>::iterator iterator_i = list.begin(); iterator_i != list.end(); ++iterator_i)
  {
    Linesegment temp = *iterator_i;
    add_linesegment_fromPython(temp);
  }
}

void function_from_python(std::forward_list<Linesegment> list)
{

  print_value_fromPython(20.2, 4.44);
  display_fromPython();
}
