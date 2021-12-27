//
// Created by Jared V. Samonte on 2021-12-23
//
#include "fromjson.h"


#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace rapidjson;

std::string jsonToString(const char* filename)
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

