Merge Sort using Recursion (C++)

Merge Sort is a popular divide and conquer algorithm used to sort elements in an array.
It works by dividing the array into smaller parts, sorting them, and then merging them back together.

How It Works
Divide the array into two halves
Recursively sort each half
Merge the sorted halves into one sorted array

Algorithm (Step-by-Step)
Divide the array into two halves
Recursively apply Merge Sort on both halves
Merge the two sorted halves
Repeat until the entire array is sorted

C++ Program (Recursive Merge Sort)
#include <iostream>
using namespace std;

// Merge function to combine two sorted halves
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    int temp[100]; // temporary array

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (int x = low; x <= high; x++)
        arr[x] = temp[x];
}

// Recursive Merge Sort function
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);       // left half
        mergeSort(arr, mid + 1, high);  // right half
        merge(arr, low, mid, high);     // merge
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

Time Complexity
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)

Space Complexity
O(n)
Because a temporary array is used during merging
