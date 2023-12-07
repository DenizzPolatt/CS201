#ifndef SINGLYNODE_H_
#define SINGLYNODE_H_

template<class ItemType>
class SinglyNode
{
    ItemType item_;
    SinglyNode<ItemType>* next_; //pointer to next node
public:
    SinglyNode();
    SinglyNode(const ItemType& item);
    SinglyNode(const ItemType& item, SinglyNode<ItemType>* next);
    void setItem(const ItemType& item);
    void setNext(SinglyNode<ItemType>* next);
    ItemType getItem() const; //access item
    SinglyNode<ItemType>* getNext() const; //access pointer
};
#endif