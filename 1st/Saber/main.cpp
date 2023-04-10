#include <iostream>
#include <fstream>
#include "public/ListNode.h"
#include "public/ListRand.h"


int main() {
    auto List = new ListRand();
    auto t = List->PushBack("s");
    auto t2 = List->PushBack("a");
    auto t3 = List->PushBack("b");
    auto t4 = List->PushBack("e");
    auto t5 = List->PushBack("r");

    t->Rand = t5;
    t2->Rand = t2;
    t3->Rand = t4;
    t4->Rand = t3;
    t5->Rand = t;

    std::ofstream TestFile;
    TestFile.open("C:/Dev/CPP/Saber/TestFile.txt", std::ios::in | std::ios::trunc);

    List->Serialize(TestFile);
    TestFile.close();

    std::ifstream my_file2;
    my_file2.open("C:/Dev/CPP/Saber/TestFile.txt", std::ios::out);
    auto List2 = new ListRand();

    List2->Deserialize(my_file2);

    my_file2.close();

    for(auto Node = List2->Head; Node; Node = Node->Next) {
        std::cout << std::endl << Node->Data << " ";
        if(Node->Rand) {
            std::cout << Node->Rand->Data;
        } else {
            std::cout << "Without rand";
        }
    }

    return 0;
}
