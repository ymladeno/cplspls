//============================================================================
// Name        : Date.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Date.hpp"
#include <chrono>

namespace Chronos {

Date::Date(int d, Month m, int y)
: _day{d}, _month{m}, _year{y} {
    if (_day == 0)          _day   = default_date().day();
    if (_month == Month {}) _month = default_date().month();
    if (_year == 0)         _year  = default_date().year();

    if (!is_valid()) throw Bad_date();
}

Date& Date::add_day  (int d) {
    return *this;
}

Date& Date::add_month(Month m) {

    switch(m) {
    case Month::jan:
        break;
    case Month::feb:
        break;
    default:
        break;
    }

    return *this;
}

Date& Date::add_year (int y) {
    return *this;
}

//**************** class private ***********************
bool Date::is_valid() {
    return is_date(_day, _month, _year);
}

//**************** helper functions ********************

int diff(Date d1, Date d2) {
    return 0;
}

bool is_date(int d, Month m, int y) {
    return true;
}

const Date& default_date() {
    static Date d{1, Month::jan, 1870};
    return d;
}

bool operator==(const Date& a, const Date& b) {
    return true;
}

bool operator!=(const Date& a, const Date& b) {
    return true;
}

Date& operator+(Date d, const int n) {
    return d+=n;
}

Date& operator-(Date d, const int n) {
    return d-=n;
}

Date& operator++(Date& d) {
    return d.add_day(1);
}

Date& operator--(Date& d) {
    return d.add_day(-1);
}

Date& operator+=(Date& d, const int n) {
    return d.add_day(n);
}

Date& operator-=(Date& d, const int n) {
    return d.add_day(-n);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    return os;
}

std::istream& operator>>(std::istream& is, Date& d) {
    return is;
}

} /* namespace Chronos */
