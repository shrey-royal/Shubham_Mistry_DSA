/*
Sorting algos:

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Quick Sort
5. Merge Sort

*/

#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    int swapped=0;

    //outer loop for each pass
    for (int i = 0; i < size-1; i++) {
        // swapped = false;
        //inner loop for each comparision in the pass
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                //swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                // swapped = true;
            }
        }

        //if no elements were swapped, the array is already sorted
        // if(!swapped) {
        //     break;
        // }
        cout << "Pass " << swapped++ << ": ";
        printArray(arr, size);
        cout << endl;
    }
}

void selectionSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int size) {
    for(int i=0; i<size; i++) {
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);


    cout << "Unsorted array: ";
    printArray(arr, size);

    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    insertionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}