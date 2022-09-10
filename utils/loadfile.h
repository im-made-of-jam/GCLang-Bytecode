#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

bool loadFile(std::vector<std::string>& lines, const std::string& filename){
    std::ifstream file;

    file.open(filename);

    if(!std::filesystem::exists(filename)){
        return false;
    }

    if (file.bad()){
        return false;
    }

    std::string line;
    while(std::getline(file, line)){
        lines.push_back(line);
    }

    return true;
}