//
// Created by nikolay shulga on 2019-06-18.
//

#include "deserialize.h"

// STL
#include <string>

// RapidJSON
#include "document.h"
#include "rapidjson.h"
#include "Linesegment.h"
#include <iostream>
#include <forward_list>

using namespace rapidjson;


// Input data format/parsing.
// Input is a JSON file. The root object is an array called "lines". These are line segments.
// Each line segment has an id "id" (string), starting point "start and an end point "end".
// Points are represented as an array of two doubles. These correspond to X and Y cartesian coordinates.


std::forward_list<Linesegment> deserialize(Document& doc) 
{
    std::forward_list<Linesegment> line_list;
    std::forward_list<Linesegment>::iterator line_iterator = line_list.before_begin();
    auto const& lines_json = doc["lines"];
    if (lines_json.IsArray()){
        auto lines_array = lines_json.GetArray();
        for (auto& line : lines_array) {
            Linesegment new_segment;
            auto const& id_json = line["id"];
            auto const& start_json = line["start"];
            auto const& end_json = line["end"];
            if (id_json.IsString() && start_json.IsArray() && end_json.IsArray()) {
                auto start_x = start_json.GetArray()[0].GetDouble(),
                    start_y = start_json.GetArray()[1].GetDouble(),
                    end_x = end_json.GetArray()[0].GetDouble(),
                    end_y = end_json.GetArray()[1].GetDouble();
                new_segment.setStartX(start_x);
                new_segment.setStartY(start_y);
                new_segment.setEndX(end_x);
                new_segment.setEndY(end_y);
                auto id = id_json.GetString();
                line_iterator = line_list.insert_after(line_iterator, new_segment);
            }
        }
    }
    return line_list;
}

std::forward_list<Linesegment> deserialize_from_string(std::string const &json_data)
{
    Document doc;
    doc.Parse(json_data.c_str());
    return deserialize(doc);
}