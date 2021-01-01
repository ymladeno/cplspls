//============================================================================
// Name        : printf.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28.6.1 Type-safe printf
//============================================================================

#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
constexpr bool Is_integral() { return std::is_integral<T>::value; }

template<typename T>
constexpr bool Is_floating_point() { return std::is_floating_point<T>::value; }

template<typename T>
struct is_string {
    static const bool value = false;
};

template<class T, class Traits, class Alloc>
struct is_string<std::basic_string<T, Traits, Alloc>> {
    static const bool value = true;
};

template<typename T>
constexpr bool Is_string() { return is_string<T>::value; }

template<typename T>
struct is_C_style_string {
    static const bool value = false;
};

template<>
struct is_C_style_string<const char *> {
    static const bool value = true;
};

template<typename T>
constexpr bool Is_C_style_string() { return is_C_style_string<T>::value; }

void myprintf(const char* s)
{
    if (s==nullptr) return;

    while (*s) {
        if (*s=='%' && *++s!='%') // make sure no more arguments are expected
            // %% represents plain % in a format string
            throw std::runtime_error("invalid format: missing arguments");
        std::cout << *s++;
    }
}

template<typename T, typename ... Args>                 // variadic template argument list: one or more arguments
void myprintf(const char* s, T value , Args... args)    // function argument list: two or more arguments
{
    while (s && *s) {
        if (*s=='%') {          // a format specifier (ignore which one it is)
            switch (*++s) {
            case '%':           // not format specifier
                break;
            case 's':
                if (!Is_C_style_string<T>() && !Is_string<T>())
                    throw std::runtime_error("Bad printf() format");
                break;
            case 'd':
                if (!Is_integral<T>())
                    throw std::runtime_error("Bad printf() format");
                break;
            case 'g':
                if (!Is_floating_point<T>())
                    throw std::runtime_error("Bad printf() format");
                break;
            }
            std::cout << value;             // use first non-format argument
            return myprintf(++s, args...);  // do a recursive call with the tail of the argument list
        }

        std::cout << *s++;
    }
    throw std::runtime_error("extra arguments provided to printf");
}

int main() {
    //std::string name = "target";
    const char * name = "target";
    myprintf("The value of %s\n", name);

    //myprintf("The value of %s is %g\n",7);
    //myprintf("%s");
	return 0;
}
