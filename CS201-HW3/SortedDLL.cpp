#include "SortedDLL.h"
#include "DoublyNode.h"
#include "Student.h"
#include <iostream>

template<class ItemType>
SortedDLL<ItemType>::SortedDLL() : head_(nullptr), itemCount_(0) {}

template<class ItemType>
SortedDLL<ItemType>::SortedDLL(const SortedDLL<ItemType>& sdll)
{
    itemCount_ = sdll.itemCount_;
    DoublyNode<ItemType>* orgLPtr = sdll.head_;

    if (orgLPtr == nullptr)
    {
        head_ = nullptr; //org list is empty, so is the copy
    }
    else
    {
        head_ = new DoublyNode<ItemType>();
        head_->setItem(orgLPtr->getItem());
        head_->setPrev(nullptr);

        DoublyNode<ItemType>* newLPtr = head_;
        orgLPtr = orgLPtr->getNext();

        while (orgLPtr != nullptr)
        {
            ItemType next_item = orgLPtr->getItem();
            DoublyNode<ItemType>* new_node_ptr = new DoublyNode<ItemType>(next_item);
            new_node_ptr->setPrev(newLPtr);
            newLPtr->setNext(new_node_ptr);

            newLPtr = newLPtr->getNext();
            orgLPtr = orgLPtr->getNext();
        }

        newLPtr->setNext(nullptr);
    }
}

template<class ItemType>
SortedDLL<ItemType>::~SortedDLL()
{
    clear();
}

template<class ItemType>
bool SortedDLL<ItemType>::isEmpty() const
{
    return itemCount_ == 0;
}

template<class ItemType>
int SortedDLL<ItemType>::getLength() const
{
    return itemCount_;
}

template<class ItemType>
void SortedDLL<ItemType>::insert(int newPos, const ItemType& item)
{
    //check if the position is valid
    if (newPos < 1 || newPos > itemCount_ + 1) {
        std::cout << "Invalid position." << std::endl;
        return;
    }

    DoublyNode<ItemType>* new_node = new DoublyNode<ItemType>(item); //allocation for the new node

    if (newPos == 1 || isEmpty()) {
        (*new_node).setNext(head_); //new node's next pointer is now pointing to the head of the linked list.
        //head is apointer to the first node. check if the first node exists. 
        if (head_ != nullptr) //head is a valid pointer
        {
            (*head_).setPrev(new_node); //traverse to reverse to set prev of nead to new node.
        }

        head_ = new_node; //now new_node is the head a.k.a the leading node of the list.
    } 
    else 
    {
    
        DoublyNode<ItemType>* prev = nullptr;
        DoublyNode<ItemType>* curr = head_;
        
        //move each element to right. 
        for(int i = 1; i < newPos; i++)
        {
            prev = curr;
            curr = (*curr).getNext();
        }

        //inserting new node between curr and prev
        (*new_node).setNext(curr); 
        (*new_node).setPrev(prev);
        (*prev).setNext(new_node);

        if (curr != nullptr) {
            (*curr).setPrev(new_node);
        }
    }

    itemCount_++; //increment the size of the linked list
}

template<class ItemType>
void SortedDLL<ItemType>::remove(int pos)
{
    //check if the node will be deleted is at a valid position 
    if (pos < 1 || pos > itemCount_) {
        std::cout << "Invalid position." << std::endl;
        return;
    }

    DoublyNode<ItemType>* curr = head_;

    //first node
    if (pos == 1) {
        head_ = (*head_).getNext();
        if (head_ != nullptr) 
        {
            head_->setPrev(nullptr);
        }
    } 
    else
    {
        DoublyNode<ItemType>* prev = nullptr;
        int count = 1;

        while (count < pos) {
            prev = curr;
            curr = (*curr).getNext();
            count++;
        }

        prev->setNext((*curr).getNext());
        if (curr->getNext() != nullptr) {
            curr->getNext()->setPrev(prev);
        }
    }

    delete curr; //deallocation
    itemCount_--;
}

template<class ItemType>
void SortedDLL<ItemType>::clear()
{
    int first_pos = 1;
    while (!isEmpty())
    {
        remove(first_pos); //remove from the beginning
        //now first is updated since the list is updated.
    }

}

template<class ItemType>
ItemType SortedDLL<ItemType>::getEntry(int position) const
{
    if (position < 1 || position > itemCount_) {
        std::cout << "Invalid position." << std::endl;
        return ItemType();
    }

    DoublyNode<ItemType>* curr = head_;
    int count = 1;

    while (count < position) {
        curr = (*curr).getNext();
        count++;
    }

    return (*curr).getItem();
}

template<class ItemType>
ItemType& SortedDLL<ItemType>::getEntryRef(int position)
{
    if (position < 1 || position > itemCount_) {
        throw std::out_of_range("Invalid position");
    }

    DoublyNode<ItemType>* curr = head_;

    for(int i = 1; i < position; ++i)
    {
        curr = (*curr).getNext();
    }

    return (*curr).getItem();
}


template<class ItemType>
ItemType SortedDLL<ItemType>::replace(int position, const ItemType& new_item)
{
    if (position < 1 || position > itemCount_) {
        std::cout << "Invalid position." << std::endl;
        return ItemType();
    }

    DoublyNode<ItemType>* curr = head_;
    int count = 1;

    while (count < position) {
        curr = (*curr).getNext();
        count++;
    }

    ItemType old_item = (*curr).getItem();
    (*curr).setItem(new_item);
    return old_item;
}

template class SortedDLL<Student>;  
