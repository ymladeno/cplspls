template<typename T, int N>
struct Array_type {
    using type = T;
    static const int dim = N;
};

template<int N>
struct Integer {
    using Error = void;
    using type = Select<N,Error,signed char,short,Error,int,Error,Error,Error,long>;
};

int main() {
    using Array = Array_type<int,3>;
    Array::type x;
    constexpr int s = Array::dim;

    typename Integer<4>::type i4 = 8;
    typename Integer<8>::type i1 = 9;
}