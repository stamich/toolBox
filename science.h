//
// Created by EB79OJ on 2019-06-13.
//

#ifndef TOOLBOX_SCIENCE_H
#define TOOLBOX_SCIENCE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iterator>

template<class T, class U>
T getMean(U first, U last){

    if (first == last) throw std::domain_error("mean is undefined");
    T sum;
    int count = 0;
    while (first != last){
        sum += *first++;
        ++count;
    }
    return sum / count;

    //return static_cast<double>(accumulate(first, last, 0.0)) / distance(first, last);
}

int getMaxInt(std::vector<int>& v){
    return *max_element(v.begin(), v.end());
}

int getMinInt(std::vector<int>& v){
    return *min_element(v.begin(), v.end());
}

template<class T, class U>
void getMinAndMax(T first, T last, U& min, U& max){
    min = *min_element(first, last);
    max = *max_element(first, last);
}

#endif //TOOLBOX_SCIENCE_H
