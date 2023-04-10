//
// Created by Aleksandr on 07.04.2023.
//

#include <iostream>
#include <fstream>
#include <utility>
#include <unordered_map>
#include <cstring>
#include <sstream>
#include "../public/ListRand.h"

void ListRand::Serialize(std::ofstream &Stream) const {

    for (auto *Node = Head; Node; Node = Node->Next) {
        Stream << Node << " ";
        Stream << Node->Rand << " ";
        Stream << Node->Data << " ";
        Stream << std::endl;
    }
}

void ListRand::Deserialize(std::ifstream &Stream) {
    std::unordered_map<std::string, ListNode *> RandMap;

    std::string Id, RandId, Data;
    std::string line;

    ListNode *Node;
    while (std::getline(Stream, line)) {


        std::istringstream iss(line);
        iss >> Id >> RandId >> Data;

        if (RandMap.find(Id) != RandMap.end()) {
            Node = RandMap[Id];
        } else {
            Node = new ListNode();
            RandMap.insert({Id, Node});
        }

        if (RandId != "0") {
            if(RandId == Id) Node->Rand = Node;
            else if (RandMap.find(RandId) == RandMap.end()) {
                auto RandNode = new ListNode();
                RandMap.insert({RandId, RandNode});
                Node->Rand = RandNode;
            }
            else {
                Node->Rand = RandMap[RandId];
            }
        }
        Node->Data = Data;
        PushBackNode(Node);

    }
}

ListNode *ListRand::PushFront(std::string Data) {
    auto Ptr = new ListNode(std::move(Data));
    Ptr->Next = Head;

    if (Head != nullptr) {
        Head->Prev = Ptr;
    }

    if (Tail == nullptr) {
        Tail = Ptr;
    }

    Head = Ptr;
    Count++;

    return Ptr;
}

ListNode *ListRand::PushBack(std::string Data) {
    auto Ptr = new ListNode(std::move(Data));
    Ptr->Prev = Tail;

    if (Tail != nullptr) {
        Tail->Next = Ptr;
    }

    if (Head == nullptr) {
        Head = Ptr;
    }

    Tail = Ptr;
    Count++;

    return Ptr;
}

ListNode *ListRand::PushBackNode(ListNode *Node) {
    if (Tail != nullptr) {
        Tail->Next = Node;
    }

    if (Head == nullptr) {
        Head = Node;
    }

    Tail = Node;
    Count++;

    return Node;
}
