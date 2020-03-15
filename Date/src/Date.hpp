/*
 * Date.hpp
 *
 *  Created on: Mar 15, 2020
 *      Author: osboxes
 */

#ifndef DATE_HPP_
#define DATE_HPP_

#include <iostream>

namespace Chronos {

enum class Month {jan=1, feb};

class Date {
public:
    struct Bad_date {};
    explicit Date(int d = {}, Month m = {}, int y ={});

    int   day  () const { return _day;   }
    Month month() const { return _month; }
    int   year () const { return _year;  }

    Date& add_day  (int d);
    Date& add_month(Month m);
    Date& add_year (int y);

private:
    bool is_valid();

private:
    int   _day;
    Month _month;
    int   _year;
};

int  diff   (Date d1, Date d2);
bool is_date(int d, Month m, int y);
const Date& default_date();

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

Date& operator+(Date d, const int n);
Date& operator-(Date d, const int n);

Date& operator++(Date& d);
Date& operator--(Date& d);

Date& operator+=(Date& d, const int n);
Date& operator-=(Date& d, const int n);

std::ostream& operator<<(std::ostream& os, const Date& d);
std::istream& operator>>(std::istream& os, Date& d);

} /* namespace Chronos */

#endif /* DATE_HPP_ */
