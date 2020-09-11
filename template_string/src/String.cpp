/*
 * String.cpp
 *
 *  Created on: Mar 30, 2020
 *      Author: osboxes
 */

#include "String.hpp"
#include <cstring>

template<typename C>
String<C>::String()
: sz{0},
  ptr{ch} { ch[0]=0; }

template<typename C>
String<C>::String(const C* p)
: sz{strlen(p)},
  ptr{ (sz <= short_max) ? ch : new C[sz+1] }, space{0} {
    strcpy(ptr, p);
}

template<typename C>
String<C>::String(const String<C>& x) {
    copy_from(x);
}

template<typename C>
String<C>& String<C>::operator=(const String<C>& x) {
    if (this==&x) return *this;                 //deal with self-assignment
    C* p = (short_max<sz) ? ptr : 0;
    copy_from(x);
    delete[] p;                                 //have 2 copies of x
    return *this;
}

template<typename C>
String<C>::String(String<C>&& x) {
    move_from(x);
}

template<typename C>
String<C>& String<C>::operator=(String<C>&& x) {
    if (this==&x) return *this;                 // deal with self-assignment (x = move(x) is insanity)
    if (short_max<sz) delete[] ptr;             // delete target
    move_from(x);                               // does not throw
    return *this;
}

template<typename C>
String<C>& String<C>::operator+=(C c) {
    if (sz==short_max) {                        // expand to long string
        size_t n = sz+sz+2;                     // double the allocation (+2 because of the terminating 0)
        ptr = expand(ptr,n);
        space = n-sz-2;
    }
    else if (short_max<sz) {
        if (space==0) {                         // expand in free store
            int n = sz+sz+2;                    // double the allocation (+2 because of the terminating 0)
            C* p = expand(ptr,n);
            delete[] ptr;
            ptr = p;
            space = n-sz-2;
    }
    else
        --space;
    }

    ptr[sz] = c;                                // add c at end
    ptr[++sz] = 0;                              // increase size and set terminator
    return *this;
}

template<typename C>
void String<C>::copy_from(const String& x)
{
                                    // make *this a copy of x
    if (x.sz <= short_max) {        // copy *this
        memcpy(this, &x, sizeof(x));
        ptr = ch;
    }
    else {
        // copy the elements
        ptr = expand(x.ptr, x.sz+1);
        sz = x.sz;
        space = 0;
    }
}

template<typename C>
void String<C>::move_from(String& x)
{
    if (x.sz<=short_max) {
                                        // copy *this
        memcpy(this, &x, sizeof(x));
        ptr = ch;
    }
    else {                              // grab the elements
        ptr     = x.ptr;
        sz      = x.sz;
        space   = x.space;
        x.ptr   = x.ch;                 // x = ""
        x.sz    = 0;
        x.ch[0] =0;
    }
}

//*************** HELPER FUNCTIONS *************
template<typename C>
char* expand(const C* ptr, int n)    // expand into free store
{
    char* p = new C[n];
    strcpy(p,ptr);
    return p;
}

template<typename C>
const C* begin(const String<C>& x)
{
    return x.c_str();
}

template<typename C>
const C* end(const String<C>& x)
{
    return x.c_str()+x.size();
}

template<typename C>
std::ostream& operator<<(std::ostream& os, const String<C>& s)
{
    return os << s.c_str();
}

template<typename C>
std::istream& operator>>(std::istream& is, String<C>& s)
{
    s = "";                         // clear the target string
    is>>std::ws;                    // skip whitespace (§38.4.5.1)
    char ch = ' ';
    while(is.get(ch) && !isspace(ch))
        s += ch;
    return is;
}

template<typename C>
String<C>& operator+=(String<C>& a, const String<C>& b) // concatenation
{
    for (auto x : b)
        a+=x;
    return a;
}

template<typename C>
String<C> operator+(const String<C>& a, const String<C>& b) // concatenation
{
    String<C> res {a};
    res += b;
    return res;
}

template<typename C>
bool operator==(const String<C>& a, const String<C>& b)
{
    if (a.size()!=b.size())
        return false;

    for (int i = 0; i!=a.size(); ++i)
        if (a[i]!=b[i])
            return false;

    return true;
}

template<typename C>
bool operator!=(const String<C>& a, const String<C>& b)
{
    return !(a==b);
}

template<typename C>
bool operator<(const String<C>& s1, const String<C>& s2)
{
    //static_assert(Ordered<C>(),"String's character type not ordered");
    bool eq = true;
    for (int i=0; i!=s1.size() && i!=s2.size(); ++i) {
        if (s2[i]<s1[i]) return false;
        if (s1[i]<s2[i]) eq = false;                   // not s1==s2
    }
    if (s2.size()<s1.size()) return false;             // s2 is shorter than s1
    if (s1.size()==s2.size() && eq) return false;      // s1==s2
    return true;
}
