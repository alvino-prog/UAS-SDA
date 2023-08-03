#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            index = mid;
            break;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return index;
}

int main() {
    int arr[] = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Test Case 1
    int x1 = 1;
    int index1 = binarySearch(arr, n, x1);
    if (index1 != -1) {
        cout << "Angka " << x1 << " ada di indeks ke " << index1 << endl;
    } else {
        cout << "Angka " << x1 << " tidak ada dalam array" << endl;
    }

    // Test Case 2
    int x2 = 50;
    int index2 = binarySearch(arr, n, x2);
    if (index2 != -1) {
        cout << "Angka " << x2 << " ada di indeks ke " << index2;
        while (arr[index2] == x2 && index2 < n) {
            cout << " dan " << index2;
            index2++;
        }
        cout << endl;
    } else {
        cout << "Angka " << x2 << " tidak ada dalam array" << endl;
    }

    // Test Case 3
    int x3 = 100;
    int index3 = binarySearch(arr, n, x3);
    if (index3 != -1) {
        cout << "Angka " << x3 << " ada di indeks ke " << index3 << endl;
    } else {
        cout << "Angka " << x3 << " tidak ada dalam array" << endl;
    }

    return 0;
}

