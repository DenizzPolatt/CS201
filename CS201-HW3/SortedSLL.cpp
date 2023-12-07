#include "SortedSLL.h"
#include "SinglyNode.h"
#include "Course.h"
#include <iostream>
#include <string>

template<class ItemType>
SortedSLL<ItemType>::SortedSLL() : head_(nullptr), itemCount_(0) {}

//copy constructor
template<class ItemType>
SortedSLL<ItemType>::SortedSLL(const SortedSLL<ItemType>& ssll) 
{
    itemCount_ = ssll.itemCount_;
    SinglyNode<ItemType>* orgLPtr = ssll.head_;

    if (orgLPtr == nullptr)
    {
        head_ = nullptr; // org list is empty, so is the copy
    }
    else
    {
        // copying first node 
        head_ = new SinglyNode<ItemType>();
        (*head_).setItem((*orgLPtr).getItem());

        // remaining nodes
        SinglyNode<ItemType>* newLPtr = head_;
        orgLPtr = (*orgLPtr).getNext();

        while (orgLPtr != nullptr)
        {
            ItemType next_item = (*orgLPtr).getItem();
            SinglyNode<ItemType>* new_node = new SinglyNode<ItemType>(next_item);
            (*newLPtr).setNext(new_node);

            newLPtr = (*newLPtr).getNext();
            orgLPtr = (*orgLPtr).getNext();
        }

        (*newLPtr).setNext(nullptr);
    }
}


template<class ItemType>
SortedSLL<ItemType>::~SortedSLL()
{
    clear();
}

template<class ItemType>
bool SortedSLL<ItemType>::isEmpty() const
{
    return itemCount_ == 0;
}

template<class ItemType>
int SortedSLL<ItemType>::getLength() const
{
    return itemCount_;
}

template<typename ItemType>
void SortedSLL<ItemType>::insert(int newPos, const ItemType& item)
{
    if (newPos < 1 || newPos > itemCount_ + 1) {
        std::cout << "Invalid position." << std::endl;
        return;
    }

    SinglyNode<ItemType>* new_node = new SinglyNode<ItemType>(item);

    if (newPos == 1 || isEmpty()) {
        
        (*new_node).setNext(head_); 
        head_ = new_node; 
    } 
    else {
        
        SinglyNode<ItemType>* prev = nullptr;
        SinglyNode<ItemType>* curr = head_;
        
        
        for (int i = 1; i < newPos; i++) {
            prev = curr;
            curr = (*curr).getNext();
        }

        
        (*new_node).setNext(curr);
        (*prev).setNext(new_node);
    }

    itemCount_++;
}




template<class ItemType>
void SortedSLL<ItemType>::remove(int pos)
{
    if (pos >= 1 && pos <= itemCount_)
    {
        SinglyNode<ItemType>* curr = head_;
        SinglyNode<ItemType>* prev = nullptr;

        for(int i = 0; i < pos; i++)
        {
            prev = curr;
            curr = (*curr).getNext();
        }

        if (prev == nullptr) //first node (no prev)
        {
            head_ = (*curr).getNext(); 
        }
        else
        {
            (*prev).setNext((*curr).getNext());
        }

        delete curr;
        itemCount_--;
    } 
}

template<class ItemType>
void SortedSLL<ItemType>::clear()
{
    SinglyNode<ItemType>* curr = head_;

    while (curr != nullptr)
    {
        SinglyNode<ItemType>* temp = curr;
        curr = (*curr).getNext();
        delete temp;
    }

    head_ = nullptr;
    itemCount_ = 0;
}

template<class ItemType>
ItemType SortedSLL<ItemType>::getEntry(int pos) const
{
    if (pos >= 1 && pos <= itemCount_)
    {
        SinglyNode<ItemType>* curr = head_;

        for(int i = 1; i < pos; ++i)
        {
            curr = (*curr).getNext();
        }

        return (*curr).getItem();
    }

    std::cout << "Invalid position." << std::endl;
    return ItemType();
}

template<class ItemType>
ItemType SortedSLL<ItemType>::replace(int pos, const ItemType& newEntry)
{
    if (pos >= 1 && pos <= itemCount_)
    {
        SinglyNode<ItemType>* curr = head_;
        
        for(int i = 1; i < pos; ++i)
        {
            curr = (*curr).getNext();
        }

        ItemType oldEntry = (*curr).getItem();
        (*curr).setItem(newEntry);
        return oldEntry;
    }
    
    std::cout << "Invalid position." << std::endl;
    return ItemType();
}


template class SortedSLL<Course>;
template class SortedSLL<int>;
