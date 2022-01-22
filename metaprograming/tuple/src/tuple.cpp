//============================================================================
// Name        : tuple.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Section 28.5 Compile-Time List: Tuple
//============================================================================

#include <iostream>
#include "select.cpp"

class Nil {};

template<typename T1=Nil, typename T2=Nil, typename T3=Nil, typename T4=Nil>
struct Tuple;

template<typename Ret, int N>
struct getNth {                 // getNth() remembers the type (Ret) of the Nth element
    template<typename T>
    static Ret& get(T& t)       // get the value element N from t’s Base
    {
        return getNth<Ret,N-1>::get(*t.base());
    }

    template<typename T>
    static const Ret& get(const T& t) // get the value element N from t’s Base
    {
        return getNth<Ret,N-1>::get(*t.base());
    }
};

template<typename Ret>
struct getNth<Ret,0> {
    template<typename T> static Ret& get(T& t) { return t.x; }
    template<typename T> static const Ret& get(const T& t) { return t.x; }
};

template<int N, typename T1, typename T2, typename T3, typename T4>
Select<N, T1, T2, T3, T4>& get(Tuple<T1, T2, T3, T4>& t)
{
    return getNth<Select<N, T1, T2, T3, T4>,N>::get(t);
}

template<int N, typename T1, typename T2, typename T3>
const Select<N, T1, T2, T3>& get(const Tuple<T1, T2, T3>& t)
{
    return getNth<Select<N, T1, T2, T3>,N>::get(t);
}

template<typename T1, typename T2, typename T3, typename T4>
struct Tuple : Tuple<T2, T3, T4> {                                          // layout: {T2,T3,T4} before T1
    T1 x;
    using Base = Tuple<T2, T3, T4>;
          Base* base()       { return static_cast<Base*>(this); }
    const Base* base() const { return static_cast<const Base*>(this); }
    Tuple(const T1& t1, const T2& t2, const T3& t3, const T4& t4) : Base{t2,t3,t4}, x{t1} { }
};

template<>
struct Tuple<> { Tuple() {} };                      // 0-tuple

template<typename T1>
struct Tuple<T1> : Tuple<> {                        // 1-tuple
    T1 x;
    using Base = Tuple<>;
          Base* base()       { return static_cast<Base*>(this); }
    const Base* base() const { return static_cast<const Base*>(this); }
    Tuple(const T1& t1) : Base{}, x{t1} { }
};

template<typename T1, typename T2>
struct Tuple<T1, T2> : Tuple<T2> {                  // 2-tuple, lay out: T2 before T1
    T1 x;
    using Base = Tuple<T2>;
          Base* base()       { return static_cast<Base*>(this); }
    const Base* base() const { return static_cast<const Base*>(this); }
    Tuple(const T1& t1, const T2& t2) : Base{t2}, x{t1} { }
};

template<typename T1, typename T2, typename T3>
struct Tuple<T1, T2, T3> : Tuple<T2, T3> {          // 3-tuple, lay out: {T2,T3} before T1
    T1 x;
    using Base = Tuple<T2, T3>;
          Base* base()       { return static_cast<Base*>(this); }
    const Base* base() const { return static_cast<const Base*>(this); }
    Tuple(const T1& t1, const T2& t2, const T3& t3) : Base{t2, t3}, x{t1} { }
};

template<typename T1, typename T2, typename T3, typename T4>
void print_elements(std::ostream& os, const Tuple<T1,T2,T3,T4>& t)
{
    os << t.x << ", ";              // t’s x
    print_elements(os, *t.base());
}

template<typename T1, typename T2, typename T3>
void print_elements(std::ostream& os, const Tuple<T1,T2,T3>& t)
{
    os << t.x << ", ";              // t’s x
    print_elements(os, *t.base());
}

template<typename T1, typename T2>
void print_elements(std::ostream& os, const Tuple<T1,T2>& t)
{
    os << t.x << ", ";              // t’s x
    print_elements(os, *t.base());
}

template<typename T1>
void print_elements(std::ostream& os, const Tuple<T1>& t)
{
    os << t.x << ", ";              // t’s x
}

template<>
void print_elements(std::ostream& os, const Tuple<>& t)
{
    os << "";
}

template<typename T1, typename T2, typename T3, typename T4>
std::ostream& operator<<(std::ostream& os, const Tuple<T1,T2,T3,T4>& t)
{
    os << "{ ";
    print_elements(os,t);
    os << " }";
    return os;
}

template<typename T1, typename T2, typename T3, typename T4>
Tuple<T1, T2, T3, T4> make_tuple(const T1& t1, const T2& t2, const T3& t3, const T4& t4)
{
    return Tuple<T1, T2, T3, T4>{t1, t2, t3,t4};
}

int main() {
    Tuple<double, int, char> x {1.1, 42, 'a'};
    std::cout << x << "\n";

    std::cout << "{ "
    << get<0>(x) << ", "
    << get<1>(x) << ", "
    << get<2>(x) << " }\n"; // write { 1.1, 42, a }

    const Tuple<double , int, char> xx {11.1, 422, 'b'};
    char cc = get<2>(xx); // OK: reading from const
    std::cout << xx << "\n";

    auto xxx = make_tuple(1.2, 3, 'x', 122);
    std::cout << xxx << "\n";

	return 0;
}
