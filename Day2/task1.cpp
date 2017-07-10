// Фролов Максим Павлович БПИ162
// Задание №1 день 2
// Разработано в CLion 2017.1.3

#include <iostream>
#include <ctime>
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

int* array_copy(int* arr, int n) {
    int* res = new int[n];
    for (int i = 0; i < n; i++)
        res[i] = arr[i];
    return res;
}

/// <summary>
/// Сортировка пузырьком.
/// </summary>
void bubble_sort(int* arr, int n) {
    cout << "------------------------" << endl;
    cout << "Array before bubble sort: " << endl;
    print(arr, n);

    int scount = 0; // Количество свапов.
    int icount = 0; // Колличество итераций алгоритма.

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            icount++;
            if (arr[j] > arr[j + 1]) {
                scount++;
                swap(arr, j, j + 1);
            }
        }
    }
    cout << "Array after bubble sort: " << endl;
    print(arr, n);
    cout << "Iterations done: " << icount << endl;
    cout << "Swaps done: " << scount << endl;
}

/// <summary>
/// Сортировка пузырьком с условием Айверсона 1.
/// </summary>
void bubble_sort1(int* arr, int n) {
    cout << "------------------------" << endl;
    cout << "Array before bubble sort (modified 1): " << endl;
    print(arr, n);

    int scount = 0; // Количество свапов.
    int icount = 0; // Колличество итераций алгоритма.

    bool unsorted = true;
    while(unsorted) {
        unsorted = false;
        for (int j = 0; j < n - 1; j++) {
            icount++;
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                unsorted = true;
                scount++;
            }
        }
    }

    cout << "Array after bubble sort (modified 1): " << endl;
    print(arr, n);
    cout << "Iterations done: " << icount << endl;
    cout << "Swaps done: " << scount << endl;
}

/// <summary>
/// Сортировка пузырьком с условием Айверсона 2.
/// </summary>
void bubble_sort2(int* arr, int n) {
    cout << "------------------------" << endl;
    cout << "Array before bubble sort (modified 2): " << endl;
    print(arr, n);

    int scount = 0; // Количество свапов.
    int icount = 0; // Колличество итераций алгоритма.

    int bound = n - 1;
    int last_swap;
    while(bound != 0) {
        last_swap = 0;
        for (int j = 0; j < bound; j++) {
            icount++;
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                last_swap = j;
                scount++;
            }
        }
        bound = last_swap;
    }

    cout << "Array after bubble sort (modified 2): " << endl;
    print(arr, n);
    cout << "Iterations done: " << icount << endl;
    cout << "Swaps done: " << scount << endl;
}


int main() {
    srand(time(0));

    int n;
    cout << "Enter array size: ";
    cin >> n;

    int l, h;
    cout << "Enter range for array elements (lower and higher bound): ";
    cin >> l >> h;

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (l - h + 1) + l;
    }

    bubble_sort(array_copy(arr, n), n);
    bubble_sort1(array_copy(arr, n), n);
    bubble_sort2(array_copy(arr, n), n);

    return 0;
}