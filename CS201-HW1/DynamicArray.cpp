#include "DynamicArray.h"
#include "Branch.h"
#include "Customer.h"
#include "Account.h"

template <typename T>
DynamicArray<T>::DynamicArray() = default;

template <typename T>
DynamicArray<T>::DynamicArray(int size) :
    array_{new T[size]}, size_{size} {}


template <typename T>
DynamicArray<T>::~DynamicArray() {
    if(array_)
        delete[] array_;
}


template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
    if(array_)
        delete[] array_;

    array_ = new T[other.size_];
    size_ = other.size_;
    for(int i = 0; i < size_; i++) {
        array_[i] = other.array_[i];
    }

    return *this;
}

template class DynamicArray<int>;
template class DynamicArray<Branch>;
template class DynamicArray<Customer>;
template class DynamicArray<Account>;