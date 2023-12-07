#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "DynamicArray.h"

template <typename T>
class ArrayList
{
    DynamicArray<T> array_{};
    int size_{};

public:
    void add(const T& value);
    void remove(const T& value);
    T& get(int index);
    const T& get(int index) const;
    int size() const;
    int find(const T& value) const;
};


#endif //ARRAYLIST_H_