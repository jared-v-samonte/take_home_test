#include "fromFile.h"
#include "linesegment.h"
#include "math.h"
#include "deserialize.h"
#include <forward_list>
#include <curses.h>
#include <Python.h>

int main(int argc, char * argv[])
{
    Py_Initialize();
    const char *filename = "../test/assets/1-split.json"; //1-reference.json";
    std::forward_list<Linesegment> old_list = deserialize_from_string(stringFromJSON(filename));
    std::forward_list<Linesegment> merged_list = compareEveryLine(deserialize_from_string(stringFromJSON(filename)));
    functionsFromPython(old_list, merged_list);
    Py_Finalize();
}
