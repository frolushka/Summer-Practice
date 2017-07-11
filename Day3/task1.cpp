// Фролов Максим Павлович БПИ162
// Задание №1 день 3
// Разработано в CLion 2017.1.3

#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

void print(int*, int);
void swap(int*, int, int);
void counting_sort(int*, int, int, int);
int* array_copy(int*, int);

int main() {
    srand(time(0));

    int n, min = INT_MAX, max = 0; // Размер массива и максимальный элемент массива.

    // Определяем, как задавать элементы массива: из файла или с помощью
    // генератора случайных чисел. Некорректный ввод не учитываем.
    char c;
    cout << "Enter\n[f file_path] to read input from file "
         << "or\n[r array_size lower_bound higher_bound] for random generation: " << endl;
    cin >> c;

    int* arr;
    if (c == 'r') {
        int l, h;
        cin >> n >> l >> h;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (h - l) + l;
            if (arr[i] > max)
                max = arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
    }
    else if (c == 'f'){
        string path = "";
        cin >> path;
        ifstream input;
        input.open(path);
        if (input.is_open()) {
            input >> n;
            arr = new int[5];
            for (int i = 0; i < 5; i++) {
                input >> arr[i];
                if (arr[i] > max)
                    max = arr[i];
                if (arr[i] < min)
                    min = arr[i];
            }
        }
    }
    else {
        cout << "Invalid input.";
        return 0;
    }

    counting_sort(array_copy(arr, n), n, min, max);

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
/// Сортировка подсчетом.
/// </summary>
void counting_sort(int* arr, int n, int min, int max) {
    cout << "------------------------" << endl;
    cout << "Array before counting sort (stable): " << endl;
    print(arr, n);

    int scount = 0; // Количество свапов.
    int icount = 0; // Колличество итераций алгоритма.

    int* counter = new int[max - min + 1];
    int* sorted = new int[n];

    for (int i = 0; i < max - min + 1; i++) {
        icount++;
        counter[i] = 0;
    }
    for (int i = 0; i < n; i++){
        icount++;
        counter[arr[i] - min]++;
    }
    for (int j = 1; j < max - min + 1; j++) {
        icount++;
        counter[j] += counter[j - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        icount++;
        counter[arr[i] - min]--;
        scount++;
        sorted[counter[arr[i] - min]] = arr[i];
    }
    arr = sorted;

    cout << "Array after counting sort (stable): " << endl;
    print(arr, n);
    cout << "Iterations done: " << icount << endl;
    cout << "Swaps done: " << scount << endl;
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
