#include<iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int initCapacity = 10) {
        front = 0;
        rear = -1;
        size = 0;
        capacity = initCapacity;
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if(size == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        ++size;
    }

    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        --size;
        return value;
    }

    int peekFront() {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int peekRear() {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if(isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Queue Elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        system("cls");
        queue.display();
        cout << "\n\nQueue Menu: \n";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peekfront and Peekrear";
        cout << "\n4. Display";
        cout << "\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                value = queue.dequeue();
                if (value != -1) {
                    cout << "Dequeued value: " << value << endl;
                }
                system("pause");
                break;
            case 3:
                value = queue.peekFront();
                if (value != -1) {
                    cout << "Front value: " << value << endl;
                }
                value = queue.peekRear();
                if (value != -1) {
                    cout << "Rear value: " << value << endl;
                }
                system("pause");
                break;
            case 4:
                queue.display();
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