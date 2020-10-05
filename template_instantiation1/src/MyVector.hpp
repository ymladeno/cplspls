#include <iostream>

template<typename T>
class MyVector {
public:
    T*& operator[](int);
};

template<>
class MyVector<int> {
private:
    static constexpr const size_t CMAX = 100;

public:
    int& operator[](int i) {
        return arr[i];
    }

private:
    int arr[CMAX];

};

extern template class MyVector<int>;
