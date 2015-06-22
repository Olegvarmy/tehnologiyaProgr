#include "CustomException.h"

const char* CustomException::what() const throw() {
    return "My exception happened";
}