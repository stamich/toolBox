//
// Created by EB79OJ on 2019-05-29.
//

#ifndef TOOLBOX_DATE_TIME_H
#define TOOLBOX_DATE_TIME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <stdexcept>
#include <iterator>
#include <sstream>

std::ostream& formatDateTime(std::ostream out, const tm& t, const char* fmt){
    const std::time_put<char>& dateWriter = std::use_facet<std::time_put<char>>(out.getloc());
    int n = strlen(fmt);
    if (dateWriter.put(out, out, ' ', &t, fmt, fmt + n).failed()){
        throw std::runtime_error("failure to format date time");
    }
    return out;
}

std::string dateTimeToString(const tm& t, const char* format){
    std::stringstream s;
    formatDateTime(s, t, format);
    return s.str();
}

std::tm now(){
    time_t now = time(0);
    return *localtime(&now);
}

#endif //TOOLBOX_DATE_TIME_H
