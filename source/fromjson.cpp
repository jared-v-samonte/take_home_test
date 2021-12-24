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

void jsonToString(const char* filename)
{
  char readBuffer[80000];

  FILE* filepointer = fopen("../test/assets/1-reference.json", "r");
  FileReadStream is(filepointer, readBuffer, sizeof(readBuffer));

  Document jsonDocument;
  jsonDocument.ParseStream(is);
  fclose(filepointer);

  StringBuffer buffer;
  Writer<StringBuffer> writer(buffer);
  jsonDocument.Accept(writer);
  std::string jsonString(buffer.GetString(), buffer.GetSize());
  std::cout << jsonString << std::endl;
  return ;
}

