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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);  //creating new node
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if(head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int pos, int val) {
        if(pos < 1) {
            cout << "Invalid Position" << endl;
            return;
        }

        if(pos == 1) {
            insertAtBeginning(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i=1; temp!=nullptr && i<pos-1; i++) {
            temp = temp->next;
        }

        if(temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    bool searchByValue(int val) {
        Node* temp = head;
        while(temp != nullptr) {
            if(temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }    

    int length() {
        int len = 0;
        Node* temp = head;

        while(temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void reverseList() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void deleteAtBeginning() {
        if(head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if(head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos) {
        if(head == nullptr || pos < 1) {
            cout << "Invalid position or list is empty!" << endl;
            return;
        }

        if(pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i=1; temp!=nullptr && i<pos-1; i++) {
            temp = temp->next;
        }

        if(temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void printListFromBeginning() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void printListFromEndRecursive(Node* node) {
        if(node == nullptr) {
            return;
        }
        printListFromEndRecursive(node->next);
        cout << node->data << " -> ";
    }

    void printListFromEnd() {
        printListFromEndRecursive(head);
        cout << "NULL" << endl;
    }

};

int main() {
    SinglyLinkedList list;
    int choice, value, position;

    do {
        system("cls");  //to clear the terminal screen
        list.printListFromBeginning();

        cout << "\n\n\n1. Insert at beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Position";
        cout << "\n4. Search By Value";
        cout << "\n5. Length of the list";
        cout << "\n6. Reverse the List";
        cout << "\n7. Delete at beginning";
        cout << "\n8. Delete at end";
        cout << "\n9. Delete at Position";
        cout << "\n10. Print list from beginning";
        cout << "\n11. Print list from end";
        cout << "\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter position and value: ";
                cin >> position >> value;
                list.insertAtPosition(position, value);
                system("pause");
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (list.searchByValue(value)) {
                    cout << "Value found in the list." << endl;
                } else {
                    cout << "Value not found in the list." << endl;
                }
                system("pause");
                break;
            case 5:
                cout << "Length of the list: " << list.length() << endl;
                system("pause");
                break;
            case 6:
                list.reverseList();
                cout << "List reversed." << endl;
                break;
            case 7:
                list.deleteAtBeginning();
                cout << "Deleted at beginning." << endl;
                break;
            case 8:
                list.deleteAtEnd();
                cout << "Deleted at end." << endl;
                break;
            case 9:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                system("pause");
                break;
            case 10:
                list.printListFromBeginning();
                system("pause");
                break;
            case 11:
                list.printListFromEnd();
                system("pause");
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

/*
Scenario: Managing Flight Schedules
Imagine you work for an airline that needs to manage its daily flight schedules. Each flight has a unique 
identifier, a departure time, and a destination. You want to maintain a list of flights for a specific day, 
allowing you to efficiently add, remove, and traverse through the flights.

You can use a singly linked list to represent this list of flights. Each node in the list represents a 
flight, and the linked list allows you to dynamically manage the schedule without needing to know the total 
number of flights in advance.

*/