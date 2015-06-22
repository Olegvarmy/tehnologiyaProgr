//
//  FileReader.cpp
//  test
//
//  Created by Excelsior on 22.06.15.
//  Copyright (c) 2015 Excelsior. All rights reserved.
//

#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "FileReader.h"

FileReader::FileReader(std::string filename) {
    this->inStream = new std::ifstream;
    inStream->open(filename);
    if (!inStream->is_open()) {
        std::cout << "Cannot open inputsream!" << std::endl;
        return;
    }
}

FileReader::~FileReader() {
    if(inStream != nullptr && inStream->is_open()) {
        inStream->close();
        delete inStream;
    }
}

std::string FileReader::readFileToString() {
    std::vector<std::string> vector;
    if(inStream == nullptr) {
        std::cout << "Can't read from file!" << std::endl;
        return "";
    }
    std::string line;
    while (std::getline(*inStream, line))
    {
        vector.push_back(line);
    }
    std::ostringstream oss;
    
    if (!vector.empty()) {
        std::copy(vector.begin(), vector.end() - 1, std::ostream_iterator<std::string>(oss, "\n"));
        oss << vector.back();
    } else {
        return "";
    }
    return oss.str();
}
