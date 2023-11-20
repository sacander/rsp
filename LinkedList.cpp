#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {
    SingleNode<int>* singlyLinkedList = new SingleNode(0);
    SingleNode<int>* current = singlyLinkedList;
    for (int i = 1; i < 10; i++) {
        current->next = new SingleNode(i);
        current = current->next;
    }

    current = singlyLinkedList;
    while (current->next != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << " ";
    cout << endl;

    SingleNode<int>::insert(singlyLinkedList, 5, 50);

    current = singlyLinkedList;
    while (current->next != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << " ";
    cout << endl;

    singlyLinkedList = SingleNode<int>::deleteNode(singlyLinkedList, 7);

    current = singlyLinkedList;
    while (current->next != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << " ";
    cout << endl;

    // DoubleNode<int>* doublyLinkedList = new DoubleNode(0);
    // DoubleNode<int>* current = doublyLinkedList;
    // for (int i = 1; i < 10; i++) {
    //     current->next = new DoubleNode(i);
    //     current->next->prev = current;
    //     current = current->next;
    // }

    // current = doublyLinkedList;
    // while (current->next != nullptr) {
    //     cout << current->data << " ";
    //     current = current->next;
    // }
    // cout << current->data << " ";
    // cout << endl;
    // while (current->prev != nullptr) {
    //     cout << current->data << " ";
    //     current = current->prev;
    // }
    // cout << current->data << " ";
    // cout << endl;

    return 0;
}