//
// Created by SHAIKH SHAWON AREFIN SHIMON on 11/21/18.
//

#include "SortedType.h"
#include <exception>
#include <iostream>

template <class ItemType>
SortedType<ItemType>::SortedType()
        :   length(0)
        ,   listData(nullptr)
        ,   currentPos(nullptr)
{
    length = 0;
    listData = nullptr;
    currentPos = nullptr;
}


template<class ItemType>
SortedType<ItemType>::SortedType(const SortedType& src)
        :   length(0)
        ,   listData(nullptr)
        ,   currentPos(nullptr)
{
    NodeType* node = src.listData;
    while (node != nullptr) {
        this->PutItem(node->info);
        node = node->next;
    }
}

template<class ItemType>
SortedType<ItemType>& SortedType<ItemType>::operator=(const SortedType& src) {
    if(this == &src)
        return *this;

    this->MakeEmpty();
    NodeType* node = src.listData;
    while (node != nullptr) {
        this->PutItem(node->info);
        node = node->next;
    }

    return *this;
}

template<class ItemType>
SortedType<ItemType>::~SortedType(){
    MakeEmpty();
}

template<class ItemType>
bool SortedType<ItemType>::IsFull() const{
    try{
        NodeType* newNode = new NodeType();
        delete newNode;
    }
    catch (std::bad_alloc exception){
        //This means a new node can not be allocated
        //From the dynamic memory.
        //This means we have reached capacity.
        return true;
    }

    return (length > MAX_LENGTH);
}

template<class ItemType>
int SortedType<ItemType>::GetLength() const{
    return length;
}

template<class ItemType>
void SortedType<ItemType>::MakeEmpty(){
    NodeType* locationToDelete = nullptr;
    while (listData != nullptr){
        locationToDelete = listData;
        listData = listData->next;
        if (currentPos == locationToDelete){
            //Iterator is pointing to the item to be deleted
            currentPos = currentPos->next;
        }

        delete locationToDelete;
        length--;
    }
}

template<class ItemType>
bool SortedType<ItemType>::IsEmpty() const{
    return (length == 0 && listData == nullptr);
}

template<class ItemType>
ItemType SortedType<ItemType>::GetItem(ItemType item, bool & found) const{
    NodeType* curr = listData;
    found = false;
    ItemType returnVal = item;
    while (curr != nullptr && !found){
        if (curr->info != item)
            curr = curr->next;
        else{
            //Found a copy of the item inside the linked list.
            //return the fresh copy of the item inside the list.
            found = true;
            returnVal = curr->info;
        }
    }

    return returnVal;
}

template<class ItemType>
bool SortedType<ItemType>::PutItem(ItemType item){
    if (IsFull())
        return false;

    NodeType* curr = this->listData;
    NodeType* prev = nullptr;
    bool found = false;
    while(curr != nullptr && !found){

        if(curr->info < item){
            prev = curr;
            curr = curr->next;
        }else{
            if(prev){
                prev->next = new NodeType(item, curr);
            } else {
                NodeType* newNode = new NodeType(item, curr);
                listData = newNode;
            }
            found = true;
        }
    }

    if(!found){
        NodeType* newNode = new NodeType(item, curr);
        if(prev)
            prev->next = newNode;
        else
            listData = newNode;
    }

    length++;
    return true;
}

template<class ItemType>
bool SortedType<ItemType>::DeleteItem(ItemType item){
    if(IsEmpty())
        return false;

    NodeType* curr = listData;
    NodeType* prev = nullptr;
    bool found = false;
    while (curr != nullptr && !found){
        if (curr->info == item) {
            found = true;
            if (prev == nullptr) {
                //This means, the item to delete is the linked list
                //Head. This means, after deleteing current node,
                //we need to update listData head pointer.
                listData = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
            length--;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return found;
}

template<class ItemType>
void SortedType<ItemType>::ResetList(){
    currentPos = nullptr;
}

template<class ItemType>
bool SortedType<ItemType>::HasNextItem() const{
    if (currentPos == nullptr)
        return (listData != nullptr);

    return (currentPos->next != nullptr);
}

template<class ItemType>
ItemType SortedType<ItemType>::GetNextItem(){

    currentPos = ((currentPos == nullptr) ? listData : currentPos->next);
    return currentPos->info;
}


