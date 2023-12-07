#ifndef SORTEDSLL_H_
#define SORTEDSLL_H_
#include "SinglyNode.h"

template<class ItemType>
class SortedSLL
{
    SinglyNode<ItemType>* head_;
    int itemCount_;

public:
    SortedSLL();
    SortedSLL(const SortedSLL<ItemType>& ssll);
    ~SortedSLL();
    bool isEmpty() const;
    int getLength() const;
    //insert method inserts the new item in a sorted order (ascending).
    void insert(int newPos, const ItemType& item);
    void remove(int pos);
    void clear();

    ItemType getEntry(int pos) const;
    ItemType replace(int pos, const ItemType& newEntry);
};

#endif