//
//  Finder.h
//  test
//
//  Created by Excelsior on 22.06.15.
//  Copyright (c) 2015 Excelsior. All rights reserved.
//

#ifndef __test__Finder__
#define __test__Finder__

#include <stdio.h>
#include <iosfwd>
#include <vector>
using namespace std;

class Finder {
    std::string* substringForFind;
    std::string* text;
public:
    Finder(std::string* string, std::string* substringForFind);
    unsigned long find(bool last);
};
#endif /* defined(__test__Finder__) */
