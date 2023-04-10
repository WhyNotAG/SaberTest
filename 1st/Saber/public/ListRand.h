//
// Created by Aleksandr on 07.04.2023.
//

#ifndef SABER_LISTRAND_H
#define SABER_LISTRAND_H


#include "ListNode.h"

class ListRand {
public:
    ListNode *Head;
    ListNode *Tail;
    int Count;

    ListNode* PushFront(std::string Data);
    ListNode* PushBack(std::string Data);
    ListNode* PushBackNode(ListNode* Node);
    void Serialize(std::ofstream &Stream) const;
    void Deserialize(std::ifstream &Stream);
};

#endif //SABER_LISTRAND_H
