//
//  Finder.cpp
//  test
//
//  Created by Excelsior on 22.06.15.
//  Copyright (c) 2015 Excelsior. All rights reserved.
//

#include "Finder.h"
#include <string>
#include <iostream>
#include "Finder.h"
#include "CustomException.h"

Finder::Finder(std::string* text, std::string* substringForFind) {
    if (text == nullptr || substringForFind == nullptr) {
        std::cout << "incorrect params!" << std::endl;
        CustomException e;
        throw e;
    }
    this->text = text;
    this->substringForFind = substringForFind;
    
}

unsigned long Finder::find(bool last) {
    unsigned long position;
    if (last) {
        position = text->find_last_of(*substringForFind);
    } else {
        position = text->find(*substringForFind);
    }
    if (position == std::string::npos) {
        return 0;
    }
    return position;
}
