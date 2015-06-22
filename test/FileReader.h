//
//  FileReader.h
//  test
//
//  Created by Excelsior on 22.06.15.
//  Copyright (c) 2015 Excelsior. All rights reserved.
//

#ifndef __test__FileReader__
#define __test__FileReader__

#include <stdio.h>

#include <iosfwd>
#include <string>
#include <vector>

class FileReader {
    
public:
    FileReader(std::string filename);
    std::string readFileToString();
private:
    std::ifstream *inStream;
    ~FileReader();
};

#endif /* defined(__test__FileReader__) */
