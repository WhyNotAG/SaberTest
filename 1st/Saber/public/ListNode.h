//
// Created by Aleksandr on 07.04.2023.
//

#ifndef SABER_LISTNODE_H
#define SABER_LISTNODE_H


#include <string>

class ListNode {

public:
    ListNode *Prev;
    ListNode *Next;
    ListNode *Rand;
    std::string Data;

    ListNode();
    explicit ListNode(std::string Data);
};


#endif //SABER_LISTNODE_H
