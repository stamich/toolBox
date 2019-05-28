//
// Created by EB79OJ on 2019-01-09.
//

#ifndef TOOLBOX_STRING_MASTER_H
#define TOOLBOX_STRING_MASTER_H

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void padString(std::basic_string<T> &s, typename std::basic_string<T>::sizeType st, T t){
    if (st > s.length()){
        s.append(st - s.length(), t);
    }
}

void rightTrim(std::string& s, char c){
    if (s.empty())
        return;

    std::string::iterator it;
    for (it = s.end(); it != s.begin() && *--it == c;);

    if (*it != c){
        it++;
    }
    s.erase(it, s.end());
}

void splitString(const std::string &s, char c, std::vector<std::string> &v){
    std::string::size_type i = 0;
    std::string::size_type j = s.find(c);

    while (j != std::string::npos){
        v.push_back(s.substr(i, j - i));
        i = ++j;
        j = s.find(c, j);

        if (j == std::string::npos){
            v.push_back(s.substr(i, s.length()));
        }
    }
}

template <typename T>
void splitAnyType(const std::basic_string<T>& s, T t, std::vector<std::basic_string<T>>& v){
    std::string::size_type i = 0;
    std::string::size_type j = s.find(t);

    while (j != std::basic_string<T>::npos){
        v.push_back(s.substr(i, j - i));
        i = ++j;
        j = s.find(t, j);

        if (j == std::basic_string<T>::npos){
            v.push_back(s.substr(i, s.length()));
        }
    }
}

#endif //TOOLBOX_STRING_MASTER_H
