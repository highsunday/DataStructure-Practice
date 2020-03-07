#include <iostream>
#include <vector>
#include <string>
#include "Heap.h"
using namespace std;
//Max heap

int main() {
    std::cout << "Hello, World!" << std::endl;
    Heap heap;
    heap.insert(5);
    heap.insert(9);
    heap.insert(11);
    heap.insert(3);
    heap.insert(300);
    heap.printArray();
    int max=heap.deleteMax();
    cout<<"delete max:"<<max<<endl;
    heap.printArray();
    max=heap.deleteMax();
    cout<<"delete max:"<<max<<endl;
    heap.printArray();

    return 0;
}