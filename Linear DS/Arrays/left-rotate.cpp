#include<iostream>
using namespace std;

void leftRotation(int arr[], int left_rotations, int size) {
    int temp[size];

    int k = 0;
    for (int i = left_rotations; i < size; i++) {
        temp[k++] = arr[i];
    }

    for (int i = 0; i < left_rotations; i++) {
        temp[k++] = arr[i];
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout  << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int left_rotations = 2;

    leftRotation(arr, left_rotations, size);
    printArray(arr, size);

    return 0;
}