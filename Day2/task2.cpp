// Фролов Максим Павлович БПИ162
// Задание №2 день 2
// Разработано в CLion 2017.1.3

#include <iostream>
#include <ctime>
using namespace std;

void print(int*, int);
void swap(int*, int, int);
void insertion_sort(int*, int);
void insertion_sort1(int*, int);
int binary_search(int*, int, int, int);
int* array_copy(int*, int);

int main() {
    srand(time(0));

    int n;
    cout << "Enter array size: ";
    cin >> n;

    // Определяем, как задавать элементы массива: с клавиатуры или с помощью
    // генератора случайных чисел. Некорректный ввод не учитываем.
    char c;
    cout << "Enter\n[i array_elements] to manually set array elements "
         << "or\n[r lower_bound higher_bound] for random generation: " << endl;
    cin >> c;

    int arr[n];
    if (c == 'r') {
        int l, h;
        cin >> l >> h;
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (h - l) + l;
    }
    else if (c == 'i'){
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }
    else {
        cout << "Invalid input.";
        return 0;
    }

    insertion_sort(array_copy(arr, n), n);
    insertion_sort1(array_copy(arr, n), n);

    return 0;
}

/// <summary>
/// Вывод переданного массива на экран.
/// </summary>
void print(int* arr, int n) {
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
/// Сортировка вставками.
/// </summary>
void insertion_sort(int* arr, int n) {
    cout << "------------------------" << endl;
    cout << "Array before insertion sort: " << endl;
    print(arr, n);

    int scount = 0; // Количество свапов.
    int icount = 0; // Колличество итераций алгоритма.

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
            arr[j + 1] = arr[j];
            icount++;
            scount++;
        }
        arr[j + 1] = temp;
        scount++;
    }

    cout << "Array after insertion sort: " << endl;
    print(arr, n);
    cout << "Iterations done: " << icount << endl;
    cout << "Swaps done: " << scount << endl;
}

/// <summary>
/// Сортировка бинарными вставками.
/// </summary>
void insertion_sort1(int* arr, int n) {
    cout << "------------------------" << endl;
    cout << "Array before insertion sort (modified 1): " << endl;
    print(arr, n);

    int scount = 0; // Количество свапов.
    int icount = 0; // Колличество итераций алгоритма.

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            int temp = arr[i];
            int ind = binary_search(arr, 0, i - 1, temp);
            for (int j = i - 1; j >= ind; j--) {
                arr[j + 1] = arr[j];
                icount++;
                scount++;
            }
            arr[ind] = temp;
            scount++;
        }
    }

    cout << "Array after insertion sort: " << endl;
    print(arr, n);
    cout << "Iterations done: " << icount << endl;
    cout << "Swaps done: " << scount << endl;
}

/// <summary>
/// Бинарный поиск элемента el в первых n элементах массива arr.
/// </summary>
int binary_search(int* arr, int l, int r, int el) {
    if (el >= arr[r])
        return r;
    if (arr[l] >= el)
        return l;

    int mid = l + (r - l)/2; // Центр границы, заданной l и r.
    if (arr[mid] == el)
        return mid;
    if (arr[mid] > el)
        return binary_search(arr, l, mid - 1, el);
    return binary_search(arr, mid + 1, r, el);
}

/// <summary>
/// Получение ссылки на массив, идентичный arr.
/// </summary>
int* array_copy(int* arr, int n) {
    int* res = new int[n];
    for (int i = 0; i < n; i++)
        res[i] = arr[i];
    return res;
}

