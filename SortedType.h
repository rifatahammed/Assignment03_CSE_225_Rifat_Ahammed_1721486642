//
// Created by SHAIKH SHAWON AREFIN SHIMON on 11/21/18.
//

#ifndef ASSIGNMENT_02_SORTED_LIST_SORTEDTYPE_H
#define ASSIGNMENT_02_SORTED_LIST_SORTEDTYPE_H

#include <iostream>

const int MAX_LENGTH = 15;

template <class ItemType> class SortedType;

template <class ItemType>
std::ostream &operator<<(std::ostream &output, const SortedType<ItemType>& uTypeObj);

template <class ItemType>
class SortedType
{
public:
    struct NodeType {
        ItemType info;
        NodeType* next;

        NodeType(ItemType newInfo = ItemType()
                , NodeType* newNext = nullptr)
                :   info(newInfo)
                ,   next(newNext)
        {
        }
    };

    SortedType();
    SortedType(const SortedType& src);
    SortedType& operator=(const SortedType& src);
    ~SortedType();

    bool IsFull() const;
    int GetLength() const;
    void MakeEmpty();
    bool IsEmpty() const;
    ItemType GetItem(ItemType item, bool& found) const;
    bool PutItem(ItemType item);
    bool DeleteItem(ItemType item);

    //Iterator Operations
    void ResetList();
    bool HasNextItem() const;
    ItemType GetNextItem();

    friend std::ostream &operator<<(std::ostream &output, const SortedType<ItemType>& uTypeObj){
        auto curr = uTypeObj.listData;
        while (curr != nullptr) {
            output << curr->info;
            curr = curr->next;
        }
        output << "List size: " << uTypeObj.length << "\n";
        return output;
    }

private:
    NodeType* listData = nullptr;
    int length = 0;
    NodeType* currentPos = nullptr;
};

#endif //ASSIGNMENT_02_SORTED_LIST_SORTEDTYPE_H

