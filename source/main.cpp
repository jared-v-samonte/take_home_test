#include <iostream>
#include "fromjson.h"
#include "linesegment.h"
#include "math.h"
#include "deserialize.h"
#include <forward_list>

int main() 
{
    std::cout << "main" << std::endl;
    const char *filename = "../test/assets/1-reference.json";
    compareEveryLine(deserialize_from_string(jsonToString(filename)));
    return 0;
}