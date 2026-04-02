inary Search is an efficient algorithm used to search for an element in a sorted array.
Instead of checking each element one by one, it repeatedly divides the array into smaller parts.

In this implementation, we use a recursive approach, where the function keeps calling itself until the element is found or the search space becomes empty
Note: The array must be sorted for Binary Search to work.

How It Works
Find the middle element of the array
Compare it with the target value
If equal → element found ✅
If smaller → search in the left half
If larger → search in the right half
Repeat the process using recursion

Algorithm (Recursive Steps)
Define a function with parameters: arr, low, high, key
If low > high → element not found (return -1)

Find middle index:

mid = (low + high) / 2
Compare:
If arr[mid] == key → return index
If key < arr[mid] → call function for left half
If key > arr[mid] → call function for right half
Repeat until result is found

C++ Program (Recursive Binary Search)
#include <iostream>
using namespace std;

// Recursive Binary Search Function
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
