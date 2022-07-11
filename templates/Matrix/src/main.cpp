#include <iostream>
#include <vector>
#include <type_traits>
#include <typeinfo>

template<typename T, size_t N>
struct Matrix_base {

};

template<typename T, size_t N>
struct Matrix_init {
    using type = std::initializer_list<typename Matrix_init<T,N-1>::type>;
};

template<typename T>
struct Matrix_init<T,1> {
    using type = std::initializer_list<T>;
};

template<typename T>
struct Matrix_init<T,0>;

template<typename T, size_t N>
struct Matrix_ref {
    Matrix_ref(const Matrix_slice<N>& s, T* p) : desc{s}, ptr{p} {}

private:
    Matrix_slice<N> desc;
    T* ptr;
};

template<size_t N>
struct Matrix_slice {
    Matrix_slice() = default;
    Matrix_slice(size_t s, std::initializer_list<size_t> exts) {}
    Matrix_slice(size_t s, std::initializer_list<size_t> exts, std::initializer_list<size_t> strs) {}

    template<typename... Dims>
    Matrix_slice(Dims... dims) {}

    size_t size;
    size_t start;
    std::array<size_t,N> extents;
    std::array<size_t,N> strides;

};

template<typename T, size_t N>
struct Matrix {
    static constexpr size_t order = N;
    using value_type = T;
    
    Matrix() = default;
    Matrxi(Matrix&&) = default;
    Matrix& operator=(Matrix&&) = default;
    Matrxi(Matrix const&) = default;
    Matrix& operator=(Matrix const&) = default;
    ~Matrix() = default;
    
    static constexpr size_t order() { return N; }
    // size_t extents(size_t n) const { return exts.ex
    size_t size() const { return elems.size(); }
    const Matrix_slice<N>& descriptor() const { return desc; }

    template<typename T, size_t N>
    template<typename... Extents>
    Matrix<T,N> :: Matrix(Extends... e) : exts{e...}, elems(exts.size()) {}

private:
    Matrix_slice<N> exts;
    std::vector<T> elems;
};


int main() {

}