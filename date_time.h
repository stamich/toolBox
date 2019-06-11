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
#include <fstream>

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

template<class Policy_T>
struct ConstrainedValue{
public:
    // public typedefs
    typedef typename Policy_T::policy_type;
    typedef typename Policy_T::value_type value_type;
    typedef ConstrainedValue self;

    // default constructor
    ConstrainedValue( ) : m(Policy_T::default_value) { }
    ConstrainedValue(const self& x) : m(x.m) {  }
    ConstrainedValue(const value_type& x) { Policy_T::assign(m, x); }
    operator value_type( ) const { return m; }

    // uses the policy defined assign function
    void assign(const value_type& x) {
        Policy_T::assign(m, x);
    }

    // assignment operations
    self& operator=(const value_type& x) { assign(x); return *this; }
    self& operator+=(const value_type& x) { assign(m + x); return *this; }
    self& operator-=(const value_type& x) { assign(m - x); return *this; }
    self& operator*=(const value_type& x) { assign(m * x); return *this; }
    self& operator/=(const value_type& x) { assign(m / x); return *this; }
    self& operator%=(const value_type& x) { assign(m % x); return *this; }
    self& operator>>=(int x) { assign(m >> x); return *this; }
    self& operator<<=(int x) { assign(m << x); return *this; }

    // unary operations
    self operator-( ) { return self(-m); }
    self operator+( ) { return self(-m); }
    self operator!( ) { return self(!m); }
    self operator~( ) { return self(~m); }

    // binary operations
    friend self operator+(self x, const value_type& y) { return x += y; }
    friend self operator-(self x, const value_type& y) { return x -= y; }
    friend self operator*(self x, const value_type& y) { return x *= y; }
    friend self operator/(self x, const value_type& y) { return x /= y; }
    friend self operator%(self x, const value_type& y) { return x %= y; }
    friend self operator+(const value_type& y, self x) { return x += y; }
    friend self operator-(const value_type& y, self x) { return x -= y; }
    friend self operator*(const value_type& y, self x) { return x *= y; }
    friend self operator/(const value_type& y, self x) { return x /= y; }
    friend self operator%(const value_type& y, self x) { return x %= y; }
    friend self operator>>(self x, int y) { return x >>= y; }
    friend self operator<<(self x, int y) { return x <<= y; }

    // stream operators
    friend std::ostream& operator<<(std::ostream& o, self x) { o << x.m; return o; }
    friend std::istream& operator>>(std::istream& i, self x) {
        value_type tmp; i >> tmp; x.assign(tmp); return i;
    }

    // comparison operators
    friend bool operator<(const self& x, const self& y) { return x.m < y.m; }
    friend bool operator>(const self& x, const self& y) { return x.m > y.m; }
    friend bool operator<=(const self& x, const self& y) { return x.m <= y.m; }
    friend bool operator>=(const self& x, const self& y) { return x.m >= y.m; }
    friend bool operator==(const self& x, const self& y) { return x.m == y.m; }
    friend bool operator!=(const self& x, const self& y) { return x.m != y.m; }
private:
    value_type m;
};

template<int Min_N, int Max_N>
struct RangedIntPolicy
{
    typedef int value_type;
    const static value_type default_value = Min_N;
    static void assign(value_type& lvalue, const value_type& rvalue) {
        if ((rvalue < Min_N) || (rvalue > Max_N)) {
            throw std::range_error("out of valid range");
        }
        lvalue = rvalue;
    }
};

#endif //TOOLBOX_DATE_TIME_H
