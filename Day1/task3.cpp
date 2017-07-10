// Фролов Максим Павлович БПИ162
// Задание №3 день 1
// Разработано в CLion 2017.1.3

#include <iostream>
using namespace std;

/// <summary>
/// Вывод переданного массива на экран.
/// </summary>
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/// <summary>
/// Обмен местами двух элементов массива.
/// </summary>
void swap(int* arr, int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

/// <summary>
/// Сортировка пузырьком.
/// </summary>
void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
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

    cout << "Array before bubble sort: " << endl;
    print(arr, n);

    bubble_sort(arr, n);

    cout << "Array after bubble sort: " << endl;
    print(arr, n);

    return 0;
}
