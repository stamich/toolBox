//
// Created by EB79OJ on 2018-06-28.
//

#ifndef TOOLBOX_CONVERSION_H
#define TOOLBOX_CONVERSION_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>

long hexToInt(const std::string hexString){
    char *offset;
    if (hexString.length() > 2){
        if (hexString[0] == '0' && hexString[1] == 'x'){
            return strtol(hexString.c_str(), &offset, 0);
        }
    }
    return strtol(hexString.c_str(), &offset, 16);
}

template <typename T>
std::string intToHex(T t){
    std::stringstream stream;
    stream << "0x" << std::setfill('0') << std::setw(sizeof(T)*2) << std::hex << t;
    return stream.str();
}

#endif //TOOLBOX_CONVERSION_H
