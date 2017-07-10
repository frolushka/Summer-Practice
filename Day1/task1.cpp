// Фролов Максим Павлович БПИ162
// Задание №1 день 1
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
/// Перевернуть элементы массива с индексами между ind1 и ind2.
/// </summary>
void reverse(int* arr, int ind1, int ind2) {
    for (int i = 0; i < (ind2 - ind1 + 1) / 2; i++) {
        swap(arr, ind1 + i, ind2 - i);
    }
}

/// <summary>
/// Сдвиг массива на k элементов влево.
/// </summary>
void shift(int* arr, int n, int k) {
    k %= n;
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

int main() {
    unsigned int n;
    cout << "Enter array size (n): ";
    cin >> n;

    unsigned int k;
    cout << "Enter shift (k): ";
    cin >> k;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before shift: " << endl;
    print(arr, n);

    shift(arr, n, k);

    cout << "Array after shift: " << endl;
    print(arr, n);

    return 0;
}
