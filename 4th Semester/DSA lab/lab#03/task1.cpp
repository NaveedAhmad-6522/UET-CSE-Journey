#include <iostream>

template <typename Type>
class Node {
private:
    int data;
    Node<Type>* next;

public:
    // Constructor
    Node(int value, Node<Type>* ptr = nullptr) : data(value), next(ptr) {}

    // Getter and setter for data
    int getData() const { return data; }
    void setData(int value) { data = value; }

    // Getter and setter for next
    //Node<Type>* getNext() const { return next; }
    void setNext(Node<Type>* ptr) { next = ptr; }
};

int main() {
    Node<int>* head = nullptr;
    Node<int>* newnode1 = new Node<int>(3,nullptr);
    Node<int>* newnode2 = new Node<int>(4);
    Node<int>* newnode3 = new Node<int>(5);
    Node<int>* newnode4 = new Node<int>(6);


    newnode1->setNext(newnode2);
    newnode2->setNext(newnode3);
    newnode3->setNext(newnode4);

    // Traverse the linked list and print data
    Node<int>* i = newnode1;
    while (i != nullptr) {
        std::cout << i->getData() << " ";
        i = i->getNext();
    }

    // Deallocate memory
    delete newnode1;
    delete newnode2;
    delete newnode3;
    delete newnode4;

    return 0;
}