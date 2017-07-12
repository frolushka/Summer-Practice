// Фролов Максим Павлович БПИ162
// БОЛЬШОЙ ПРОЕКТ
// Разработано в CLion 2017.1.3
// 2017 год

#include <iostream>

// Secondary functions.
void swap(int*, int, int);
int* arrayCopy(int*, int);
int binarySearch(int*, int, int, int);

// Sorts.
void bubbleSort(int*, int);
void bubbleSortIv1(int*, int);
void bubbleSortIv2(int*, int);
void insertionSort(int*, int);
void insertionSortBin(int*, int);
void countingSort(int*, int, int, int);
void radixSort(int*, int, int, int);

/// <summary>
/// Swap two array elements.
/// </summary>
void swap(int* arr, int ind1, int ind2) 
{
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

/// <summary>
/// Get reference to arr copy.
/// </summary>
int* arrayCopy(int* arr, int n) 
{
    int* res = new int[n];
    for (int i = 0; i < n; ++i)
        res[i] = arr[i];
    return res;
}

/// <summary>
/// Binary search for el in first n elements of arr.
/// </summary>
int binarySearch(int* arr, int l, int r, int el) 
{
    if (abs(l - r) <= 1)
      return r;
    int mid = l + (r - l)/2; // Center of range (l, r).
    if (arr[mid] == el)
        return mid;
    if (arr[mid] > el)
        return binarySearch(arr, l, mid, el);
    return binarySearch(arr, mid, r, el);
}

/// <summary>
/// Bubble sort.
/// </summary>
void bubbleSort(int* arr, int n) 
{
    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}

/// <summary>
/// Bubble sort with first Iverson condition.
/// </summary>
void bubbleSortIv1(int* arr, int n) 
{
    bool unsorted = true;
    while(unsorted) 
    {
        unsorted = false;
        for (int j = 0; j < n - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr, j, j + 1);
                unsorted = true;
            }
        }
    }
}

/// <summary>
/// Bubble sort with second Iverson condition.
/// </summary>
void bubbleSortIv2(int* arr, int n) 
{
    int bound = n - 1;    
    while(bound != 0) 
    {
        int last_swap = 0;
        for (int j = 0; j < bound; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr, j, j + 1);
                last_swap = j;
            }
        }
        bound = last_swap;
    }
}

/// <summary>
/// Insertion sort.
/// </summary>
void insertionSort(int* arr, int n) 
{
    for (int i = 1; i < n; ++i) 
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > temp; --j) 
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

/// <summary>
/// Binary insertion sort.
/// </summary>
void insertionSortBin(int* arr, int n) 
{
    for (int i = 1; i < n; ++i) 
    {
        if (arr[i - 1] > arr[i]) 
        {
            int temp = arr[i];
            int ind;
            if (temp <= arr[0])
                ind = 0;
            else
                ind = binarySearch(arr, 0, i - 1, temp);
            for (int j = i - 1; j >= ind; --j) 
            {
                arr[j + 1] = arr[j];
            }
            arr[ind] = temp;
        }
    }
}

/// <summary>
/// Counting sort.
/// </summary>
void countingSort(int* arr, int n, int min, int max) 
{
    int* counter = new int[max - min + 1];
    int* sorted = new int[n];

    for (int i = 0; i < max - min + 1; ++i) 
        counter[i] = 0;
    for (int i = 0; i < n; ++i)
        ++counter[arr[i] - min];
    for (int j = 1; j < max - min + 1; ++j)
        counter[j] += counter[j - 1];
    for (int i = n - 1; i >= 0; --i) 
    {
        --counter[arr[i] - min];
        sorted[counter[arr[i] - min]] = arr[i];
    }
    arr = arrayCopy(sorted, n);
    
    delete [] sorted;
    delete [] counter;
}

/// <summary>
/// Radix sort with union.
/// </summary>
void radixSort(int* arr, int n, int min, int max) 
{
    union uint_256 
    {
        unsigned int num;
        char chars[4];
    };

    uint_256* uarr = new uint_256[n];
    for(int i = 0; i < n; ++i) 
    {
        uarr[i].num = (unsigned int)arr[i];
    }

    int* counter = new int[max - min + 1];
    uint_256 sorted[256];

    for (int dig = 3; dig >= 0; --dig) 
    {
        for (int i = 0; i < max - min + 1; ++i)
            counter[i] = 0;
        for (int i = 0; i < n; ++i)
            ++counter[uarr[i].chars[dig] - min];
        for (int j = 1; j < max - min + 1; ++j)
            counter[j] += counter[j - 1];
        for (int i = n - 1; i >= 0; --i) 
        {
            --counter[uarr[i].chars[dig] - min];
            sorted[counter[uarr[i].chars[dig] - min]] = uarr[i];
        }
    }
    
    delete [] uarr;
    delete [] counter;

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i].num;
    }
}
