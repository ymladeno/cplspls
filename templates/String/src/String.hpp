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

template<typename C>
class String {
public:
    String();                                           //default ctor
    explicit String(const C* p);

    String(const String& x);
    String& operator=(const String&);                   // copy assignment

    String(String&& x);                                 // move constr uctor
    String& operator=(String&& x);                      // move assignment

    ~String() {
        if (short_max<sz)
            delete[] ptr;
    }

    C& operator[](int n)       { return ptr[n]; }    // unchecked element access
    C operator [](int n) const { return ptr[n]; }

    C& at(int n)       { check(n); return ptr[n]; }  // range-checked element access
    C  at(int n) const { check(n); return ptr[n]; }

    String& operator+=(C c);                         // add c at end

    const C* c_str()       { return ptr; }           // C-style string access
    const C* c_str() const { return ptr; }

    int size() const { return sz; }                     // number of elements
    int capacity() const
    {
        return (sz<=short_max) ? short_max : sz+space;
    }

private:
    static const int    short_max = 15;
    size_t              sz;                             // number of Cacters
    C*               ptr;
    union {
        int space;                                      // unused allocated space
        C ch[short_max+1];                           // leave space for terminating 0
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

template<typename C> C* expand(const C* ptr, int n);
template<typename C> const C*   begin (const String<C>& x);
template<typename C> const C*   end   (const String<C>& x);
template<typename C> std::ostream& operator<<(std::ostream& os, const String<C>& s);
template<typename C> std::istream& operator>>(std::istream& is, String<C>& s);
template<typename C> String<C>&    operator+=(String<C>& a     ,  const String<C>& b);
template<typename C> String<C>     operator+ (const String<C>& a, const String<C>& b);
template<typename C> bool          operator==(const String<C>& a, const String<C>& b);
template<typename C> bool          operator!=(const String<C>& a, const String<C>& b);

//make String Ordered
template<typename C>
bool operator<(const String<C>& s1, const String<C>& s2);

#endif /* STRING_HPP_ */
