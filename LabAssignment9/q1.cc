#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i, bool isMax) {
    int largest_smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (isMax) {
        if (left < n && arr[left] > arr[largest_smallest])
            largest_smallest = left;
        if (right < n && arr[right] > arr[largest_smallest])
            largest_smallest = right;
    } else {
        if (left < n && arr[left] < arr[largest_smallest])
            largest_smallest = left;
        if (right < n && arr[right] < arr[largest_smallest])
            largest_smallest = right;
    }

    if (largest_smallest != i) {
        swap(arr[i], arr[largest_smallest]);
        heapify(arr, n, largest_smallest, isMax);
    }
}

void heapSort(vector<int>& arr, bool increasing = true) {
    int n = arr.size();
    bool isMax = increasing; // For increasing → max heap

    // Build heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMax);

    // Extract elements
    for (int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMax);
    }
}

int main() {
    vector<int> arr = {20, 5, 15, 22, 9, 13};

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr, true);
    cout << "Increasing Order: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr, false);
    cout << "Decreasing Order: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
