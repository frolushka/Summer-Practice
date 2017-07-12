// Фролов Максим Павлович БПИ162
// БОЛЬШОЙ ПРОЕКТ
// Разработано в CLion 2017.1.3
// 2017 год

#include <iostream>
using namespace std;

// Secondary functions.
void swap(int*, int, int);
int* array_copy(int*, int);
int binary_search(int*, int, int, int);

// Sorts.
void bubble_sort(int*, int);
void bubble_sort_iv1(int*, int);
void bubble_sort_iv2(int*, int);
void insertion_sort(int*, int);
void insertion_sort_bin(int*, int);

/// <summary>
/// Swap two array elements.
/// </summary>
void swap(int* arr, int ind1, int ind2) {
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

/// <summary>
/// Get reference to copy of arr.
/// </summary>
int* array_copy(int* arr, int n) {
    int* res = new int[n];
    for (int i = 0; i < n; i++)
        res[i] = arr[i];
    return res;
}

/// <summary>
/// Bubble sort.
/// </summary>
void bubble_sort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}

/// <summary>
/// Bubble sort with first Iverson condition.
/// </summary>
void bubble_sort_iv1(int* arr, int n) {
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
}

/// <summary>
/// Сортировка пузырьком с условием Айверсона 2.
/// </summary>
void bubble_sort_iv2(int* arr, int n) {
    int bound = n - 1;    
    while(bound != 0) {
        int last_swap = 0;
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
}
