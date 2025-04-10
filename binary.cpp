#include <bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (x == array[mid])
            return mid;

        if (x > array[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int array[1000];  // Assuming max size of 1000

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "Enter the number to search: ";
    cin >> x;

    int result = binarySearch(array, x, 0, n - 1);

    if (result == -1)
        cout << "Not found" << endl;
    else
        cout << "Element is found at index " << result << endl;

    return 0;
}
