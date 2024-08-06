#include<iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size=10) {
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }

    void push(int value) {
        if(isFull()) {
            cout << "Stack is Full!" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if(isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if(isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }

        cout << "Stack elememts: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << ", ";
        }
        cout << endl;

    }
};

int main() {
    Stack stack(5); //default size is 10
    int choice, value;

    do {
        cout << "\n\nStack operations: ";
        cout << "\n1. Push()";
        cout << "\n2. Pop()";
        cout << "\n3. Peek()";
        cout << "\n4. isEmpty?";
        cout << "\n5. isFull?";
        cout << "\n6. size()";
        cout << "\n7. display()";
        cout << "\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
            case 3:
                value = stack.peek();
                if (value != -1) {
                    cout << "Top value: " << value << endl;
                }
                break;
            case 4:
                cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << endl;
                break;
            case 5:
                cout << "Stack is " << (stack.isFull() ? "full" : "not full") << endl;
                break;
            case 6:
                cout << "Stack size: " << stack.size() << endl;
                break;
            case 7:
                stack.display();
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