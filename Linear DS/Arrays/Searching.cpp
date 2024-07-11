#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int target) {
    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] < target) {
            left = mid + 1;
        } else if(arr[mid] > target) {
            right = mid - 1;
        }
    }

    return -1;
}


int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;

    cout << "\nEnter target: ";
    cin >> target;

    // int result = linearSearch(arr, size, target);
    int result = binarySearch(arr, 0, size-1, target);

    if(result != -1) {
        cout << target  << " found at index " << result << endl;
    } else {
        cout << target << " not found!" << endl;
    }

    return 0;
}

/*

Tasks:

1. Library Book Search
Scenario: You are in a library looking for a specific book by its title.

- Linear Search: If the books are not arranged in any particular order, you would go through each book one by one until you find the one you are looking for.
- Binary Search: If the books are sorted alphabetically by title, you could use binary search to find the book more efficiently. Start at the middle of the shelf and decide whether to search the left or right half based on the title's position.

2. Contact List Search in a Phone
Scenario: Searching for a contact's phone number in your smartphone's contact list.

- Linear Search: If your contacts are not sorted, you would scroll through the list one contact at a time until you find the desired contact.
- Binary Search: If your contacts are sorted alphabetically, you could use binary search by starting in the middle of the list and narrowing down the search based on the alphabetical order.

3. Inventory Search in a Warehouse
Scenario: A warehouse manager needs to find a specific item in the warehouse.

- Linear Search: If items are stored randomly, the manager would need to check each item one by one.
- Binary Search: If items are organized in a sorted manner, for example by item number or name, the manager can quickly locate the item using binary search.

4. Employee Record Search in a Database
Scenario: An HR manager needs to find an employee's record by their ID number.

- Linear Search: If the employee records are stored without any order, the manager would have to go through each record sequentially.
- Binary Search: If the records are sorted by employee ID, the manager can quickly locate the record using binary search by comparing the target ID with the middle ID of the current search range.

5. Password Lookup in a Password Manager
Scenario: A user wants to find a specific password in their password manager.

- Linear Search: If the passwords are stored in no particular order, the user would have to check each entry one by one.
- Binary Search: If the passwords are sorted by the associated service names, the user can perform a binary search to quickly find the desired password by comparing the target service name with the middle entry of the current search range.

*/