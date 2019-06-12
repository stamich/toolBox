//
// Created by Michal S. on 2018-06-28.
//

#ifndef TOOLBOX_COMPARISION_H
#define TOOLBOX_COMPARISION_H

#include <iostream>
#include <cmath>
#include <boost/lexical_cast.hpp>

// comparision two doubles (left-right) with precision (epsilon)

bool doubleLess(double left, double right, double epsilon, bool orEqual = false){
    if (fabs(left - right) < epsilon){
        return (orEqual);
    }
    return (left < right);
}

bool doubleEquals(double left, double right, double epsilon){
    return (fabs(left - right) < epsilon);
}

bool doubleGreater(double left, double right, double epsilon, bool orEqual = false){
    if (fabs(left - right) < epsilon){
        return (orEqual);
    }
    return (left > right);
}

template <typename T>
bool stringIsValidNumber(const std::string & number) {
    bool result = true;
    try {
        T temp = boost::lexical_cast<T>(number);
    } catch (boost::bad_lexical_cast &e) {
        result = false;
    }
    return (result);
}

#endif //TOOLBOX_COMPARISION_H
