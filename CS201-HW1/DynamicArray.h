#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

template <typename T>
class DynamicArray {

public:
    T* array_{nullptr};
    int size_{};

    DynamicArray();
    DynamicArray(int size);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other) = delete;
    DynamicArray& operator=(const DynamicArray& other);

};

#endif // DYNAMICARRAY_H_