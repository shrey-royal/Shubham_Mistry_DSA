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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for(int j=low; j<=high-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);


        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i=0; i<n1; i++) {
        L[i] = arr[left+i];
    }

    for(int i=0; i<n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i < n1) {
        arr[k++] = L[i++];
    }

    while(j < n2) {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);


    cout << "Unsorted array: ";
    printArray(arr, size);

    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size);
    // quickSort(arr, 0, size-1);
    mergeSort(arr, 0, size-1);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}