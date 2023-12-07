#ifndef SORTEDDLL_H_
#define SORTEDDLL_H_
#include "DoublyNode.h"

template<class ItemType>
class SortedDLL
{
    DoublyNode<ItemType>* head_; //pointer to the first node
    int itemCount_; //number of elements in the list

public:
    SortedDLL();
    SortedDLL(const SortedDLL<ItemType>& list);
    ~SortedDLL();
    bool isEmpty() const;
    int getLength() const;
    void insert(int newPos, const ItemType& item);
    void remove(int pos);
    void clear();

    ItemType& getEntryRef(int position);
    ItemType getEntry(int pos) const;
    ItemType replace(int pos, const ItemType& new_item);
};

#endif