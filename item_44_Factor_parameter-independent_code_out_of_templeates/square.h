#include <iostream>


// version 1
template<typename T, std::size_t n>
class SquareMatrixV1 {
public:
    void invert() {}
};


// version 2
template<typename T>
class SquareMatrixBaseV2{
protected:
    void invert(std::size_t _matrix_size) { std::cout << "base invert" << std::endl; }
};

template<typename T, std::size_t n>
class SquareMatrixV2 : private SquareMatrixBaseV2<T> {
private:
    // 避免遮掩 base 版的 invert
    using  SquareMatrixBaseV2<T>::invert;
public:
    void invert() { this->invert(n); }
    // void invert(std::size_t _size) { std::cout << "driver invert()" << std::endl; }
};



// version3
template<typename T>
class SquareMatrixBaseV3
{
protected:
    SquareMatrixBaseV3(std::size_t n, T *_pmem)
    : size_(n), pdata_(_pmem){}

    void SetDataPtr(T *ptr) { pdata_ = ptr};
private:
    T * pdata_;
    std::size_t size_;
};


template<typename T, std::size_t n>
class SquareMatrixV3 : private SquareMatrixBaseV3<T>
{
public:
    SquareMatrixV3() : SquareMatrixBaseV3<T>(n, data) {}

private:
    T data[n*n];
};
