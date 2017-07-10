// Фролов Максим Павлович БПИ162
// Задание №2 день 1
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
/// Сдвиг всех нулевых элементов из массива в его конец.
/// </summary>
void move(int* arr, int n) {
    int count = 0;

    // Проходимся по массиву и все ненулевые элементы копируем в начало массива.
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            arr[count++] = arr[i];
    }

    // Заполняем конец массива нулями.
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

    return 0;
}
