//
// Created by Jared V. Samonte on 2021-12-23
//
#include <stdio.h>
#include <curses.h>
#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>


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
  //const char* open = "exec(open(\"";
  //const char* read = "\").read())";
  //char *execute_code = new char[strlen(open)+strlen("filename")+strlen(read)+1];
  //strcpy(execute_code,open);
  //strcat(execute_code,filename);
  //strcat(execute_code,read);


	Py_Initialize();

	filepointer = _Py_fopen(filename, "r");
	PyRun_SimpleFile(filepointer, filename);
  //PyRun_SimpleString(execute_code);
	Py_Finalize();
}

