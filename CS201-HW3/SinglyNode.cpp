#include "SinglyNode.h"
#include <cstddef>
#include "Course.h"

template<class ItemType>
SinglyNode<ItemType>::SinglyNode() : next_(nullptr) {}

template<class ItemType>
SinglyNode<ItemType>::SinglyNode(const ItemType& item) : item_(item), next_(nullptr) {}

template<class ItemType>
SinglyNode<ItemType>::SinglyNode(const ItemType& item, SinglyNode<ItemType>* next) : item_(item), next_(next) {}

template<class ItemType>
void SinglyNode<ItemType>::setItem(const ItemType& item)
{
    item_ = item;
}

template<class ItemType>
void SinglyNode<ItemType>::setNext(SinglyNode<ItemType>* next)
{
    next_ = next;
}

template<class ItemType>
ItemType SinglyNode<ItemType>::getItem() const
{
    return item_;
}

template<class ItemType>
SinglyNode<ItemType>* SinglyNode<ItemType>::getNext() const
{
    return next_;
}

template class SinglyNode<Course>;
template class SinglyNode<int>;