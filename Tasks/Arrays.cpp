#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findPairWithDifference(int arr[], int size, int n) {
    bubbleSort(arr, size);
    
    int left = 0, right = 1;
    
    while (left < size && right < size) {
        if (left != right && arr[right] - arr[left] == n) {
            cout << "Pair Found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            return;
        } else if (arr[right] - arr[left] < n) {
            right++;
        } else {
            left++;
        }
    }
    
    cout << "No Such Pair" << endl;
}

int main() {
    int arr1[] = {5, 20, 3, 2, 50, 80};
    int n1 = 78;
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {90, 70, 20, 80, 50};
    int n2 = 45;
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    findPairWithDifference(arr1, size1, n1);
    findPairWithDifference(arr2, size2, n2);
    
    return 0;
}
