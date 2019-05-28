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

// splitting a string
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

// join sequence of strings
void join(const std::vector<std::string>& v, char c, std::string& s){
    s.clear();
    for (std::vector<std::string>::const_iterator p = v.begin(); p != v.end(); p++) {
        s += *p;
        if (p != v.end() - 1){
            s += c;
        }
    }
}

// counting unique characters
template<typename T>
int countUnique(const std::basic_string<T>& s){
    using std::basic_string;

    basic_string<T> chars;

    for (typename basic_string<T>::const_iterator p = s.begin(); p != s.end(); ++p) {
        if (chars.find(*p) == basic_string<T>::npos){
            chars += *p;
        }
    }
    return (chars.length());
}

// tokenizing a string
class StringTokenizer{
private:
    StringTokenizer(){};
    std::string delimiter_;
    std::string str;
    int counter;
    int begin;
    int end;
public:
    StringTokenizer(const std::string& s, const char* delimiter = NULL):
    str(s), counter(-1), begin(0), end(0){
        if (delimiter){
            delimiter_ = "\f\n\r\t\v"; // default to whitespace
        } else {
            delimiter_ = delimiter;
        }

        begin = str.find_first_not_of(delimiter_);
        end = str.find_first_of(delimiter_, begin);
    }

    size_t countTokens(){
        if (counter >= 0){
            return counter;
        }

        std::string::size_type n = 0;
        std::string::size_type i = 0;

        for (;;){
            if ((i = str.find_first_not_of(delimiter_, i)) == std::string::npos){
                break;
            }

            i = str.find_first_of(delimiter_, i + 1);
            n++;
            if (i == std::string::npos){
                break;
            }
        }
        return (counter = n);
    }

    bool hasMoreTokens(){
        return (begin != end);
    }

    void nextToken(std::string& s){
        if (begin != std::string::npos && end != std::string::npos){
            s = str.substr(begin, end - begin);
            begin = str.find_first_not_of(delimiter_, end);
            end = str.find_first_of(delimiter_, begin);
        } else if (begin != std::string::npos && end == std::string::npos){
            s = str.substr(begin, str.length() - begin);
            begin = str.find_first_not_of(delimiter_, end);
        }
    }
};

#endif //TOOLBOX_STRING_MASTER_H
