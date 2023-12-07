#include "DoublyNode.h"
#include "Student.h"
#include <cstddef>

template<class ItemType>
DoublyNode<ItemType>::DoublyNode() : prev_(nullptr), next_(nullptr) {}

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& item) : item_(item), prev_(nullptr), next_(nullptr) {}

template<class ItemType>
DoublyNode<ItemType>::DoublyNode(const ItemType& item, DoublyNode<ItemType>* prev, DoublyNode<ItemType>* next) : item_(item), prev_(prev), next_(next) {}

template<class ItemType>
void DoublyNode<ItemType>::setItem(const ItemType& item)
{
    item_ = item;
}

template<class ItemType>
void DoublyNode<ItemType>::setPrev(DoublyNode<ItemType>* prev)
{
    prev_ = prev;
}

template<class ItemType>
void DoublyNode<ItemType>::setNext(DoublyNode<ItemType>* next)
{
    next_ = next;
}

template<class ItemType>
ItemType& DoublyNode<ItemType>::getItem()
{
    return item_;
}

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getPrev() const
{
    return prev_;
}

template<class ItemType>
DoublyNode<ItemType>* DoublyNode<ItemType>::getNext() const
{
    return next_;
}

template class DoublyNode<Student>;
