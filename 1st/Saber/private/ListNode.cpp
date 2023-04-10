//
// Created by Aleksandr on 07.04.2023.
//

#include <utility>

#include "../public/ListNode.h"

ListNode::ListNode() {
    Next = Prev = Rand = nullptr;
}

ListNode::ListNode(std::string Data) {
    Next = Prev = Rand = nullptr;
    this->Data = std::move(Data);
}
