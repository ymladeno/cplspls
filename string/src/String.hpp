/*
 * String.hpp
 *
 *  Created on: Mar 30, 2020
 *      Author: osboxes
 */

#ifndef STRING_HPP_
#define STRING_HPP_

#include <stdexcept>
#include <iostream>

class String {
public:
    String();                                           //default ctor
    String(const char* p);

    String(const String& x);
    String& operator=(const String&);                   // copy assignment

    String(String&& x);                                 // move constr uctor
    String& operator=(String&& x);                      // move assignment

    ~String() {
        if (short_max<sz)
            delete[] ptr;
    }

    char& operator[](int n)       { return ptr[n]; }    // unchecked element access
    char operator [](int n) const { return ptr[n]; }

    char& at(int n)       { check(n); return ptr[n]; }  // range-checked element access
    char  at(int n) const { check(n); return ptr[n]; }

    String& operator+=(char c);                         // add c at end

    const char* c_str()       { return ptr; }           // C-style string access
    const char* c_str() const { return ptr; }

    int size() const { return sz; }                     // number of elements
    int capacity() const
    {
        return (sz<=short_max) ? short_max : sz+space;
    }

private:
    static const int    short_max = 15;
    size_t              sz;                             // number of characters
    char*               ptr;
    union {
        int space;                                      // unused allocated space
        char ch[short_max+1];                           // leave space for terminating 0
    };

    void check(size_t n) const                             // range check
    {
        if (sz<=n)
            throw std::out_of_range("String::at()");
    }

    // ancillary member functions:
    void copy_from(const String& x);
    void move_from(String& x);
};

char*         expand(const char* ptr, int n);
const char*   begin (const String& x);
const char*   end   (const String& x);
std::ostream& operator<<(std::ostream& os, const String& s);
std::istream& operator>>(std::istream& is, String& s);
String&       operator+=(String& a     ,  const String& b);
String        operator+ (const String& a, const String& b);
bool          operator==(const String& a, const String& b);
bool          operator!=(const String& a, const String& b);

#endif /* STRING_HPP_ */
