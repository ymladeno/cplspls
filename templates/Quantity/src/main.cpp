#include <iostream>
#include <vector>
#include <type_traits>
#include <typeinfo>

template<int M, int K, int S>
struct Unit {
    enum { m=M, kg=K, s=S };
};

using M = Unit<1,0,0>;
using S = Unit<0,0,1>;

template<typename U>
struct Quantity {
    long double val;
    explicit constexpr Quantity(long double d) : val{d} {}
};

template<typename U1, typename U2>
struct Uplus {
    using type = Unit<U1::m+U2::m,U1::kg+U2::kg,U1::s+U2::s>;
};

template<typename U1, typename U2>
struct Uminus {
    using type = Unit<U1::m-U2::m,U1::kg-U2::kg,U1::s-U2::s>;
};

template<typename U>
Quantity<U> operator+(Quantity<U> x, Quantity<U> y) { return Quantity<U>{x.val + y.val}; }

template<typename U>
Quantity<U> operator-(Quantity<U> x, Quantity<U> y) { return Quantity<U>{x.val - y.val}; }

template<typename U1, typename U2>
Quantity<typename Uplus<U1,U2>::type> operator*(Quantity<U1> x, Quantity<U2> y) { return Quantity<typename Uplus<U1,U2>::type>{x.val * y.val}; }

template<typename U1, typename U2>
Quantity<typename Uminus<U1,U2>::type> operator/(Quantity<U1> x, Quantity<U2> y) { return Quantity<typename Uminus<U1,U2>::type>{x.val / y.val}; }

constexpr Quantity<M> operator""_m(long double d) { return Quantity<M>{d}; }
constexpr Quantity<S> operator""_s(long double d) { return Quantity<S>{d}; }

template<typename U>
bool operator==(Quantity<U> x, Quantity<U> y) { return x.val == y.val; }

template<typename U>
bool operator!=(Quantity<U> x, Quantity<U> y) { return x.val != y.val; }

template<typename U>
std::ostream& operator<<(std::ostream& os, Quantity<U> q) { return os << q.val; }
int main() {
    // auto distance = Quantity<M>{20.1};
    // auto time = Quantity<S>{10};
    // auto speed = distance / time;
    
    auto distance = 20.1_m;
    auto time = 10.0_s;
    auto speed = distance / time;
    auto speed1 = 15.0_m / 3.0_s;

    // decltype(speed) y;
    if (speed == (15.0_m / 3.0_s)) {}
    
    std::cout << speed;
}