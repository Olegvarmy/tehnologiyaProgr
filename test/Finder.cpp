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

Finder::Finder(std::string* text, std::string* substringForFind) {
    if (text == nullptr || substringForFind == nullptr) {
        std::cout << "incorrect params!" << std::endl;
        throw std::exception();
    }
    this->text = text;
    this->substringForFind = substringForFind;
    
}

unsigned long Finder::find() {
    unsigned long position =  text->find(*substringForFind);
    if (position == std::string::npos) {
        return 0;
    }
    return position;
}
