#include<iostream>
using namespace std;

int main() {
    // int arr[5]; // array declaration with garbage values
    // int arr[5] = {1, 2, 3, 4, 5}; // array declaration with initial values
    // int arr[] = {1, 2, 3, 4, 5}; // array declaration with initial values and size is automatically calculated
    // int arr[3] = {}; // array declaration with initial values and size is automatically calculated
    // int arr[5] = {0}; // array declaration with initial values and size is automatically calculated
    // int arr[3] = {1}; // array declaration with initial values and size is automatically calculated

    int n = 4, arr[n] = {1, 2, 3, 4}; // array declaration with initial values and size is automatically calculated

    for(int i: arr) { // for each loop
        cout << i << " ";
    }

    // for (size_t i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    

    return 0;
}

/*
Advantages of Arrays:
1. Random access of elements is possible
2. Cache friendly -> elements are stored in contiguous memory locations
3. Easy to implement
4. Traversal is easy
5. sorting is easy

Disadvantages of Arrays:
1. Size is fixed
2. Insertion and deletion is difficult

*/