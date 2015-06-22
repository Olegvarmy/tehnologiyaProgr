//
//  CustomException.h
//  test
//
//  Created by Excelsior on 22.06.15.
//  Copyright (c) 2015 Excelsior. All rights reserved.
//

#ifndef __test__CustomException__
#define __test__CustomException__

#include <stdio.h>
#include <exception>

class CustomException : public std::exception {
public:
    virtual const char* what() const throw();
};

#endif /* defined(__test__CustomException__) */
