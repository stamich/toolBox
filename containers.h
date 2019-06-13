//
// Created by Michal S. on 2019-06-12.
//

#ifndef TOOLBOX_CONTAINERS_H
#define TOOLBOX_CONTAINERS_H

#include <iostream>
#include <string>
#include <hash_set>
#include <set>

std::string hashedString(std::string& s){

    __gnu_cxx::hash_set<std::string> hashString;

    hashString.insert(s);

    for (__gnu_cxx::hash_set<std::string>::const_iterator p = hashString.begin(); p != hashString.end(); ++p){
        std::cout << *p << std::endl;
    }
}

std::string hashedInt(int& i){

    __gnu_cxx::hash_set<int> hashInt;

    hashInt.insert(i);

    for (__gnu_cxx::hash_set<int>::const_iterator p = hashInt.begin(); p != hashInt.end(); ++p){
        std::cout << *p << std::endl;
    }
}

template<typename T>
void printRange(T first, T last, char delimiter =',', std::ostream& out = std::cout){
    out << "{";
    while (first != last){
        out << *first;
        if (++first != last){
            out << delimiter << ' ';
        }
    }
    out << "}" << std::endl;
}

template<typename U>
void printContainer(const U& u, char delimiter = ',', std::ostream& out = std::cout){
    printRange(u.begin(), u.end(), delimiter, out);
}

//std::string sortedString(std::string& s, ...){
//    std::set<std::string> setStr;
//    setStr.insert(s);
//
//    for (std::set<std::string>::const_iterator p = setStr.begin(); p != setStr.end(); ++p){
//        std::cout << *p << std::endl;
//    }
//}

#endif //TOOLBOX_CONTAINERS_H
