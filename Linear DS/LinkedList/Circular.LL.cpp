#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

//global head
Node* head = nullptr;

void insertAtBeginning(int val) {
    Node* newNode = new Node(val);

    if(head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
}

void printList() {
    if(head == nullptr) {
        cout << "List Is Empty!" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
}

int main() {
    insertAtBeginning(23);
    insertAtBeginning(45);
    insertAtBeginning(43);
    insertAtBeginning(2);
    insertAtBeginning(21);
    insertAtBeginning(66);
    insertAtBeginning(7);

    printList();

    return 0;
}