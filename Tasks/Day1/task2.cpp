/*
Фролов Максим Павлович БПИ162
Задание №2
Разработано в CLion 2017.1.3
*/

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

void move(int* arr, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            arr[count++] = arr[i];
    }

    while (count < n)
        arr[count++] = 0;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before move: " << endl;
    print(arr, n);

    move(arr, n);

    cout << "Array after move: " << endl;
    print(arr, n);
}
