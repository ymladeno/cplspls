//============================================================================
// Name        : std_tuple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28.6.4 Standard-library tuple
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include "select.cpp"
#include "enable_if.cpp"

template<class T> struct remove_reference      { typedef T type; };
template<class T> struct remove_reference<T&>  { typedef T type; };
template<class T> struct remove_reference<T&&> { typedef T type; };

template<typename T>
using Add_const_reference = typename remove_reference<T>::type const&;

template<typename T>
using Add_reference = typename remove_reference<T>::type&;

template<typename... Elements>
class tuple;

template<typename Head, typename... Tail>
class tuple<Head, Tail...>
    : private tuple<Tail...> {                      // here is the recursion

    /*
    Basically, a tuple stores its head (first (type,value) pairs)
    and derives from the tuple of its tail (the rest of the (type/value) pairs).
    Note that the type is encoded in the type, not stored as data
    */

typedef tuple<Tail...> inherited;

public:
    constexpr tuple() {}                            // default: the empty tuple

    // Construct tuple from separate arguments:
    tuple(Add_const_reference<Head> v, Add_const_reference<Tail>... vtail)
    : inherited(vtail...), m_head(v) { }

    // Construct tuple from another tuple:
    template<typename... VValues>
    tuple(const tuple<VValues...>& other)
    : m_head(other.head()), inherited(other.tail()) { }

    template<typename... VValues>
    tuple& operator=(const tuple<VValues...>& other)    // assignment
    {
        m_head = other.head();
        tail() = other.tail();
        return *this;
    }

    Add_reference<Head>             head()       { return m_head; }
    Add_const_reference<const Head> head() const { return m_head; }
    inherited& tail()             { return *this; }
    const inherited& tail() const { return *this; }

// ...
protected:
    Head m_head;

private:

};

template<typename Head>
class tuple<Head> {
public:
    tuple(Add_const_reference<Head> v)
    : m_head(v) { }

    Add_reference<Head>             head()       { return m_head; }
    Add_const_reference<const Head> head() const { return m_head; }
    tuple<Head>& tail()             { return *this; }
    const tuple<Head>& tail() const { return *this; }

protected:
    Head m_head;

private:

};

template<typename Ret, int N>
struct getNth {                 // getNth() remembers the type (Ret) of the Nth element
    template<typename T>
    static Ret& get(T& t)       // get the value element N from t’s Base
    {
        return getNth<Ret,N-1>::get(t.tail());
    }

    template<typename T>
    static const Ret& get(const T& t) // get the value element N from t’s Base
    {
        return getNth<Ret,N-1>::get(t.tail());
    }
};

template<typename Ret>
struct getNth<Ret,0> {
    template<typename T> static Ret& get(T& t)             { return t.head(); }
    template<typename T> static const Ret& get(const T& t) { return t.head(); }
};

template<int N, typename... Elements>
Select<N, Elements...>& get(tuple<Elements...>& t)
{
    return getNth<Select<N, Elements...>,N>::get(t);
}

template<int N, typename... Elements>
const Select<N, Elements...>& get(const tuple<Elements...>& t)
{
    return getNth<Select<N, Elements...>,N>::get(t);
}

template<typename... Types>
tuple<Types...> make_tuple(Types&&... t)
{
    return tuple<Types...>(t...);
}

template<size_t N>                                      // print element N and following elements
struct print_tuple {
    template<typename... T>
    static typename enable_if<(N<sizeof...(T))>::type
    print(std::ostream& os, const tuple<T...>& t)       // nonempty tuple
    {
        os << ", " << get<N>(t);                        // print an element
        print_tuple<N+1>::print(os,t);                  // print the rest of the elements
    }

    template<typename... T>
    static typename enable_if<!(N<sizeof...(T))>::type         // empty tuple
    print(std::ostream&, const tuple<T...>&)
    {
    }
};

std::ostream& operator << (std::ostream& os, const tuple<>&) // the empty tuple
{
    return os << "{}";
}

template<typename T0, typename ...T>
std::ostream& operator<<(std::ostream& os, const tuple<T0, T...>& t) // a nonempty tuple
{
    os << '{' << get<0>(t);                                          // print first element
    print_tuple<1>::print(os,t);                                     // print the rest of the elements
    return os << '}';
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) // a nonempty tuple
{
    os << '{';
    for(const auto& l :v) {
        os << l << ',';
    }
    return os << '}';
}

int main() {
    tuple<std::string,std::vector<int>,double> tt("hello",{1,2,3,4},1.2);
    auto d = get<2>(tt);
    std::cout << d << std::endl;

    auto t = make_tuple("New start", 1.4, 20);
    auto i = get<2>(t);
    std::cout << i << std::endl;

    std::cout << tt << std::endl;
    std::cout << t << std::endl;

	return 0;
}
