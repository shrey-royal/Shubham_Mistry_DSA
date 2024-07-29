#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if(head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode; 
        }
    }

    void printListFromBeginning() {
        Node* temp = head;
        cout << "NULL <-> ";
        while(temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void reverseList() {
        Node* curr = head;
        Node* temp = nullptr;

        while(curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if(temp != nullptr) {
            head = temp->prev;
        }
    }

    void deleteAtBeginning() {
        if(head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head != nullptr) {
            head->prev  = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void deleteAtPosition(int pos) {
        if(head == nullptr || pos < 1) {
            cout << "Invalid Position or List is empty!" << endl;
            return;
        }

        if(pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; temp != nullptr && i < pos; i++) {
            temp = temp->next;
        }

        if(temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        if(temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        if(temp == tail) {
            tail = temp->prev;
        }
        delete temp;
    }

};

int main() {
    DoublyLinkedList list;
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
            // case 2:
            //     cout << "Enter value: ";
            //     cin >> value;
            //     list.insertAtEnd(value);
            //     break;
            // case 3:
            //     cout << "Enter position and value: ";
            //     cin >> position >> value;
            //     list.insertAtPosition(position, value);
            //     break;
            // case 4:
            //     cout << "Enter value to search: ";
            //     cin >> value;
            //     if (list.searchByValue(value)) {
            //         cout << "Value found in the list." << endl;
            //     } else {
            //         cout << "Value not found in the list." << endl;
            //     }
            //     break;
            // case 5:
            //     cout << "Length of the list: " << list.length() << endl;
            //     break;
            case 6:
                list.reverseList();
                cout << "List reversed." << endl;
                break;
            case 7:
                list.deleteAtBeginning();
                cout << "Deleted at beginning." << endl;
                break;
            // case 8:
            //     list.deleteAtEnd();
            //     cout << "Deleted at end." << endl;
            //     break;
            case 9:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            case 10:
                list.printListFromBeginning();
                break;
            // case 11:
            //     list.printListFromEnd();
            //     break;
            case 0:
                cout << "Exiting..." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}