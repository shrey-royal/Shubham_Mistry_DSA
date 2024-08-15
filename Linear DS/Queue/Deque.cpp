#include<iostream>
using namespace std;

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque (int initCapacity=10) {
        front = 0;
        rear = -1;
        size = 0;
        capacity = initCapacity;
        arr = new int[capacity];
    }

    ~Deque () {
        delete[] arr;
    }

    void enqueueFront(int value) {
        if (size == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        size++;
    }

    void enqueueRear(int value) {
        if (size == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    bool isEmpty() {
        return size == 0;
    }

    int dequeueFront() {
        if(isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int dequeueRear() {
        if(isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int value = arr[rear];
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return value;
    }

    int peekFront() {
        if(isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    int peekRear() {
        if(isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    void display() {
        if(isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i=front; i != (rear + 1) % capacity; i = (i+1) % capacity) {
            cout << arr[i] << ", ";
        }
        cout << endl;
    }
};

int main() {
    Deque deque;
    int choice, value;

    do {
        system("cls");
        deque.display();
        cout << "\n\nDeque Menu: \n";
        cout << "\n1. Enqueue Front";
        cout << "\n2. Enqueue Rear";
        cout << "\n3. Dequeue Front";
        cout << "\n4. Dequeue Rear";
        cout << "\n5. Peek Front";
        cout << "\n6. Peek Rear";
        cout << "\n7. Display";
        cout << "\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue at front: ";
                cin >> value;
                deque.enqueueFront(value);
                break;
            case 2:
                cout << "Enter value to enqueue at rear: ";
                cin >> value;
                deque.enqueueRear(value);
                break;
            case 3:
                value = deque.dequeueFront();
                if (value != -1) {
                    cout << "Dequeued value from front: " << value << endl;
                }
                system("pause");
                break;
            case 4:
                value = deque.dequeueRear();
                if (value != -1) {
                    cout << "Dequeued value from rear: " << value << endl;
                }
                system("pause");
                break;
            case 5:
                value = deque.peekFront();
                if (value != -1) {
                    cout << "Front value: " << value << endl;
                }
                system("pause");
                break;
            case 6:
                value = deque.peekRear();
                if (value != -1) {
                    cout << "Rear value: " << value << endl;
                }
                system("pause");
                break;
            case 7:
                deque.display();
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