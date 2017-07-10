// Фролов Максим Павлович БПИ162
// Задание №3 день 1
// Разработано в CLion 2017.1.3

#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int* arr, int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                swap(arr, i, j);
        }
    }
}

void main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before bubble sort: " << endl;
    print(arr, n);

    bubble_sort(arr, n);

    cout << "Array after bubble sort: " << endl;
    print(arr, n);
}
