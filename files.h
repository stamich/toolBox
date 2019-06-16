//
// Created by Michal S. on 2019-02-10.
//

#ifndef TOOLBOX_FILES_H
#define TOOLBOX_FILES_H

#include <iostream>
#include <string>

std::string getFileExtension(const std::string& s){

    size_t i = s.rfind('.', s.length());
    if (i != std::string::npos){
        return (s.substr(i + 1, s.length() - i));
    }
}

std::string getFileName(const std::string& s){

    char separator = '/';

#ifdef _WIN32
    separator = '\\';
#endif

    size_t i = s.rfind(separator, s.length());
    if (i != std::string::npos){
        return (s.substr(i + 1, s.length() - 1));
    }
    return ("");
}

std::string pathAppend(const std::string& p1, const std::string& p2){

    char separator = '/';
    std::string temp = p1;

#ifdef _WIN32
    separator = '\\';
#endif

    if (p1[p1.length()] != separator){
        temp += separator;
        return (temp + p2);
    } else {
        return (p1 + p2);
    }
}

void replaceExtension(std::string& s, const std::string& newExtension){
    std::string::size_type i = s.rfind('.', s.length());

    if (i != std::string::npos){
        s.replace(i + 1, newExtension.length(), newExtension);
    }
}

#endif //TOOLBOX_FILES_H
