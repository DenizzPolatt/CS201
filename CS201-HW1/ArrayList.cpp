#include "ArrayList.h"
#include "Branch.h"
#include "Customer.h"
#include "Account.h"
#include <iostream>

template <typename T>
void ArrayList<T>::add(const T& value)
{
    DynamicArray<T> new_array{array_.size_ + 1};
    for(int i = 0; i < array_.size_; ++i)
    {
        new_array.array_[i] = array_.array_[i];
    }

    new_array.array_[array_.size_] = value;
    array_ = new_array;
    size_++;
}

template <typename T>
void ArrayList<T>::remove(const T& value)
{
    if(array_.size_ == 0) return;

    DynamicArray<T> new_array{array_.size_ - 1};
    
    int remove_index {find(value)};

    if(remove_index == -1) return;

    for(int i = 0; i < remove_index; ++i)
    {
        new_array.array_[i] = array_.array_[i];
    }

    for(int i = remove_index; i < array_.size_ - 1; ++i)
    {
        new_array.array_[i] = array_.array_[i + 1];
    }

    array_ = new_array;
    size_--;
}

template <typename T>
T& ArrayList<T>::get(int index) 
{
    return array_.array_[index];
}

template <typename T>
const T& ArrayList<T>::get(int index) const
{
    return array_.array_[index];
}

template <typename T>
int ArrayList<T>::size() const
{
    return size_;
}

template <typename T>
int ArrayList<T>::find(const T& value) const
{
    for(int i = 0; i < array_.size_; ++i)
    {
        if(array_.array_[i] == value)
        {
            return i;
        }
    }

    return -1;
}

template class ArrayList<int>;
template class ArrayList<Branch>;
template class ArrayList<Customer>;
template class ArrayList<Account>;

