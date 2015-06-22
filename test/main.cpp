#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "Finder.h"
#include <boost/filesystem.hpp>

bool findFile(const boost::filesystem::path &dirPath, std::string* textToFind) {
    if (!exists(dirPath)) {
        std::cout << "path does not exist!";
        return false;
    }
    boost::filesystem::directory_iterator endElement;
    for (boost::filesystem::directory_iterator currEl(dirPath); currEl != endElement; ++currEl) {
        if (is_directory(currEl->status())) {
            std::cout << currEl->path().string() << " dirrectory" << std::endl;
            return findFile(currEl->path(), textToFind);
        } else {
            std::cout << currEl->path().string() << " file" << std::endl;
            boost::filesystem::path p = currEl->path();
            FileReader *fileReader = new FileReader(currEl->path().string());
            std::string textFile = fileReader->readFileToString();
            try {
                Finder* finder = new Finder(&textFile, textToFind);
                unsigned long position = finder->find();
                if (position) {
                    std::cout << "find string at position = " << position << " in file " << p.string() << std::endl;
                    return true;
                }
            } catch (std::exception e) {
                std::cout << "can't create Finder instance" << std::endl;
                return false;
            }
        }
    }
    return false;
}

int main() {
    std::string textForFind;
    std::cout << "Input substring for find" << std::endl;
    cin >> textForFind;
    boost::filesystem::path* path = new boost::filesystem::path("/Users/excelsior/OneDrive/books");
    if(!findFile(*path, &textForFind)) {
        std::cout << "Cannot find substring!";
    }
    return 0;
}