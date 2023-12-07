#ifndef DOUBLYNODE_H_
#define DOUBLYNODE_H_

template<class ItemType>
class DoublyNode
{
    ItemType item_;
    DoublyNode<ItemType>* prev_; //pointer to previous node
    DoublyNode<ItemType>* next_; //pointer to next node

public:
    DoublyNode();
    DoublyNode(const ItemType& item);
    DoublyNode(const ItemType& item, DoublyNode<ItemType>* prev, DoublyNode<ItemType>* next);
    void setItem(const ItemType& item);
    void setPrev(DoublyNode<ItemType>* prev);
    void setNext(DoublyNode<ItemType>* next);
    ItemType& getItem();
    DoublyNode<ItemType>* getPrev() const;
    DoublyNode<ItemType>* getNext() const;
};

#endif