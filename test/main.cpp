#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "Finder.h"
#include <boost/filesystem.hpp>
#include <map>

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
//    std::string textForFind;
//    std::cout << "Input substring for find" << std::endl;
//    cin >> textForFind;
//    boost::filesystem::path* path = new boost::filesystem::path("/Users/excelsior/OneDrive/books");
//    if(!findFile(*path, &textForFind)) {
//        std::cout << "Cannot find substring!";
//    }
    
    std::string filePath;
    std::cout << "input filename with full path" << endl;
    std::cin >> filePath;
    boost::filesystem::path* file = new boost::filesystem::path(filePath);
    if (!exists(*file)) {
        std::cout << "file does not exists" << endl;
        throw std::exception();
    }
    std::string word;
    std::ifstream inStream;
    inStream.open(filePath);
    std::map<std::string, unsigned int> m;
    while (inStream >> word) {
//        std::cout << word << " ";
        if (m.find(word) == m.end()) {
            m[word] = 0;
        } else {
            unsigned int value = m[word];
            m[word] = value + 1;
        }
    }
    std::vector<std::pair<unsigned int, std::string>> items;
    
    for(std::map<std::string, unsigned int>::const_iterator it = m.begin(); it != m.end(); ++it) {
        std::pair<unsigned int, std::string> pair;
        pair = std::make_pair(it->second, it->first);
        items.push_back(pair);
//        std::cout << it->first << " => " << it->second << endl;
    }
    std::sort(items.rbegin(), items.rend());
    for(std::vector<std::pair<unsigned int, std::string>>::iterator it = items.begin(); it != items.end(); ++it) {
        std::pair<unsigned int, std::string> pair = *it;
        std::cout << pair.first << " = > " << pair.second << endl;
    }

    return 0;
}