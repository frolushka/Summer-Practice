// Фролов Максим Павлович БПИ162
// БОЛЬШОЙ ПРОЕКТ
// Разработано в CLion 2017.1.3
// 2017 год

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

union uint_256 
{
    unsigned int num;
    char chars[4];
};

const int TIMES = 50;

// Secondary functions.
void swap(unsigned int*, int, int);
unsigned int* arrayCopy(unsigned int*, int);
int binarySearch(unsigned int*, int, int, int);
int getMax(int, int);
uint_256* getUintArray(unsigned int*, int);
unsigned int* getIntArray(uint_256*, int);

// Test generators.
unsigned int* getArray1(int);
unsigned int* getArray2(int);
unsigned int* getArray3(int);
unsigned int* getArray4(int);

bool sortValidation(unsigned int*, int);

// Sorts.
unsigned int* bubbleSort(unsigned int*, int);
unsigned int* bubbleSortIv1(unsigned int*, int);
unsigned int* bubbleSortIv2(unsigned int*, int);
unsigned int* insertionSort(unsigned int*, int);
unsigned int* insertionSortBin(unsigned int*, int);
unsigned int* countingSort(unsigned int*, int, int);
uint_256* radixSort(uint_256*, int, int);

// =======================================================================================
// =======================================================================================

int main() 
{
    srand(time(0));
    
    std::cout << "Start..." << std::endl;
    
    unsigned int** arrays = new unsigned int*[4];
    
    arrays[0] = getArray1(9000);
    arrays[1] = getArray2(9000);
    arrays[2] = getArray3(9000);
    arrays[3] = getArray4(9000);
    
    std::cout << "4 arrays generated..." << std::endl;
    
    unsigned int* temp;
    
    clock_t** t = new clock_t*[7];
    for (int i = 0; i < 7; ++i)
        t[i] = new clock_t[9];
    
    clock_t start, end;
    
    for (int i = 0; i < 4; ++i) 
    {
        clock_t ttemp;
        for (int n = 1; n <= 9; ++n)
        {
            // BUBBLE SORT.
            // Compiler setup for bubbleSort.
            for (int it = 0; it < 5; ++it)
            {
                temp = arrayCopy(arrays[i], 1000 * n);
                temp = bubbleSort(temp, 1000 * n);
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in bubbleSort." << std::endl;
                    return -1;
                }
            }
            
            ttemp = 0;
            
            // Test for bubbleSort.
            for (int it = 0; it < TIMES; ++it)
            {
                std::cout << "bubbleSort: array: " << i << " size: " << 1000 * n << " test: " << it << std::endl;
                temp = arrayCopy(arrays[i], 1000 * n);
                start = clock();
                temp = bubbleSort(temp, 1000 * n);
                end = clock();
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in bubbleSort." << std::endl;
                    return -1;
                }
                else
                {
                    ttemp += end - start;
                }
            }
            
            ttemp /= TIMES;
            std::cout << "For bubbleSort in " << 1000 * n << " els ttemp = " << ttemp << std::endl;
            t[0][n] = ttemp;
            
            // BUBBLE SORT IV 1.
            // Compiler setup for bubbleSortIv1.
            for (int it = 0; it < 5; ++it)
            {
                temp = arrayCopy(arrays[i], 1000 * n);
                temp = bubbleSortIv1(temp, 1000 * n);
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in bubbleSortIv1." << std::endl;
                    return -1;
                }
            }
            
            ttemp = 0;
            
            // Test for bubbleSortIv1.
            for (int it = 0; it < TIMES; ++it)
            {
                std::cout << "bubbleSortIv1: array: " << i << " size: " << 1000 * n << " test: " << it << std::endl;
                temp = arrayCopy(arrays[i], 1000 * n);
                start = clock();
                temp = bubbleSortIv1(temp, 1000 * n);
                end = clock();
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in bubbleSortIv1." << std::endl;
                    return -1;
                }
                else
                {
                    ttemp += end - start;
                }
            }
            
            ttemp /= TIMES;
            std::cout << "For bubbleSortIv1 in " << 1000 * n << " els ttemp = " << ttemp << std::endl;
            t[1][n] = ttemp;
            
            // BUBBLE SORT IV 2.
            // Compiler setup for bubbleSortIv2.
            for (int it = 0; it < 5; ++it)
            {
                temp = arrayCopy(arrays[i], 1000 * n);
                temp = bubbleSortIv2(temp, 1000 * n);
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in bubbleSortIv2." << std::endl;
                    return -1;
                }
            }
            
            ttemp = 0;
            
            // Test for bubbleSortIv2.
            for (int it = 0; it < TIMES; ++it)
            {
                std::cout << "bubbleSortIv2: array: " << i << " size: " << 1000 * n << " test: " << it << std::endl;
                temp = arrayCopy(arrays[i], 1000 * n);
                start = clock();
                temp = bubbleSortIv2(temp, 1000 * n);
                end = clock();
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in bubbleSortIv2." << std::endl;
                    return -1;
                }
                else
                {
                    ttemp += end - start;
                }
            }
            
            ttemp /= TIMES;
            std::cout << "For bubbleSortIv2 in " << 1000 * n << " els ttemp = " << ttemp << std::endl;
            t[2][n] = ttemp;
            
            // INSERTION SORT.
            // Compiler setup for insertionSort.
            for (int it = 0; it < 5; ++it)
            {
                temp = arrayCopy(arrays[i], 1000 * n);
                temp = insertionSort(temp, 1000 * n);
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in insertionSort." << std::endl;
                    return -1;
                }
            }
            
            ttemp = 0;
            
            // Test for insertionSort.
            for (int it = 0; it < TIMES; ++it)
            {
                std::cout << "insertionSort: array: " << i << " size: " << 1000 * n << " test: " << it << std::endl;
                temp = arrayCopy(arrays[i], 1000 * n);
                start = clock();
                temp = insertionSort(temp, 1000 * n);
                end = clock();
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in insertionSort." << std::endl;
                    return -1;
                }
                else
                {
                    ttemp += end - start;
                }
            }
            
            ttemp /= TIMES;
            std::cout << "For insertionSort in " << 1000 * n << " els ttemp = " << ttemp << std::endl;
            t[3][n] = ttemp;
            
            // BINARY INSERTION SORT.
            // Compiler setup for insertionSortBin.
            for (int it = 0; it < 5; ++it)
            {
                temp = arrayCopy(arrays[i], 1000 * n);
                temp = insertionSortBin(temp, 1000 * n);
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in insertionSortBin." << std::endl;
                    return -1;
                }
            }
            
            ttemp = 0;
            
            // Test for insertionSortBin.
            for (int it = 0; it < TIMES; ++it)
            {
                std::cout << "insertionSortBin: array: " << i << " size: " << 1000 * n << " test: " << it << std::endl;
                temp = arrayCopy(arrays[i], 1000 * n);
                start = clock();
                temp = insertionSortBin(temp, 1000 * n);
                end = clock();
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in insertionSortBin." << std::endl;
                    return -1;
                }
                else
                {
                    ttemp += end - start;
                }
            }
            
            ttemp /= TIMES;
            std::cout << "For insertionSortBin in " << 1000 * n << " els ttemp = " << ttemp << std::endl;
            t[4][n] = ttemp;
            
            // COUNTING SORT.
            int max = getMax(i, n);
            
            // Compiler setup for countingSort.
            for (int it = 0; it < 5; ++it)
            {
                temp = arrayCopy(arrays[i], 1000 * n);
                temp = countingSort(temp, 1000 * n, max);
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in countingSort." << std::endl;
                    return -1;
                }
            }
            
            ttemp = 0;
            
            // Test for countingSort.
            for (int it = 0; it < TIMES; ++it)
            {
                std::cout << "countingSort: array: " << i << " size: " << 1000 * n << " test: " << it << std::endl;
                temp = arrayCopy(arrays[i], 1000 * n);
                start = clock();
                temp = countingSort(temp, 1000 * n, max);
                end = clock();
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in countingSort." << std::endl;
                    return -1;
                }
                else
                {
                    ttemp += end - start;
                }
            }
            
            ttemp /= TIMES;
            std::cout << "For countingSort in " << 1000 * n << " els ttemp = " << ttemp << std::endl;
            t[5][n] = ttemp;
            
            // RADIX SORT.
            uint_256* utemp;
            // Compiler setup for radixSort.
            for (int it = 0; it < 5; ++it)
            {
                utemp = getUintArray(arrayCopy(arrays[i], 1000 * n), 1000 * n);
                utemp = radixSort(utemp, 1000 * n, 256);
                temp = getIntArray(utemp, 1000 * n);
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in countingSort." << std::endl;
                    return -1;
                }
            }
            
            ttemp = 0;
            
            // Test for countingSort.
            for (int it = 0; it < TIMES; ++it)
            {
                std::cout << "countingSort: array: " << i << " size: " << 1000 * n << " test: " << it << std::endl;
                utemp = getUintArray(arrayCopy(arrays[i], 1000 * n), 1000 * n);
                start = clock();
                utemp = radixSort(utemp, 1000 * n, 256);
                end = clock();
                temp = getIntArray(utemp, 1000 * n);
                if (!sortValidation(temp, 1000 * n))
                {
                    std::cout << "Error in countingSort." << std::endl;
                    return -1;
                }
                else
                {
                    ttemp += end - start;
                }
            }
            
            ttemp /= TIMES;
            std::cout << "For countingSort in " << 1000 * n << " els ttemp = " << ttemp << std::endl;
            t[6][n] = ttemp;
        }
    }
}

// =======================================================================================
// =======================================================================================

/// <summary>
/// Swap two array elements.
/// </summary>
void swap(unsigned int* arr, int ind1, int ind2) 
{
    int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

/// <summary>
/// Get reference to arr copy.
/// </summary>
unsigned int* arrayCopy(unsigned int* arr, int n) 
{
    unsigned int* res = new unsigned int[n];
    for (int i = 0; i < n; ++i)
        res[i] = arr[i];
    return res;
}

/// <summary>
/// Binary search for el in first n elements of arr.
/// </summary>
int binarySearch(unsigned int* arr, int l, int r, int el) 
{
    if (abs(l - r) <= 1)
        return r;
    int mid = l + (r - l)/2; // Center of range (l, r).
    
    // Find position of el relative to the center.
    if (arr[mid] == el)
        return mid;
    if (arr[mid] > el)
        return binarySearch(arr, l, mid, el);
    return binarySearch(arr, mid, r, el);
}

/// <summary>
/// Check is sorted done correctly.
/// </summary>
bool sortValidation(unsigned int* arr, int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

/// <summary>
/// Get max element for counting sort.
/// </summary>
int getMax(int i, int n) {
    switch(i) 
    {
        case 0:
            return 7;
        case 1:
            return INT_MAX;
        case 2:
        case 3:
            return 1000 * n;
    }
}

uint_256* getUintArray(unsigned int* arr, int n) 
{
    uint_256* uarr = new uint_256[n];
    for(int i = 0; i < n; ++i) {
        uarr[i].num = arr[i];
    }
    return uarr;
}

unsigned int* getIntArray(uint_256* uarr, int n)
{
    unsigned int* arr = new unsigned int[n];
    for(int i = 0; i < n; ++i) {
        arr[i] = uarr[i].num;
    }
    return arr;
}

// =======================================================================================
// =======================================================================================

unsigned int* getArray1(int n) 
{
    unsigned int* arr = new unsigned int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 7; // Fill array with values from [0,7).
    return arr;
}

unsigned int* getArray2(int n) 
{
    unsigned int* arr = new unsigned int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand(); // Fill array with values from [0,INT_MAX).
    return arr;
}

unsigned int* getArray3(int n) 
{
    unsigned int* arr = new unsigned int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = i; // Fill array with sorted values.
    
    // Select two random pairs from arr and swap it.
    int first, second;
    for (int i = 0; i < 5; ++i) 
    {
        first = rand() % n;
        second = rand() % n;
        swap(arr, first, second);
    }
    return arr;
}

unsigned int* getArray4(int n) 
{
    unsigned int* arr = new unsigned int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = n - i - 1; // Fill array with descending sorted values.
    return arr;
}

// =======================================================================================
// =======================================================================================

/// <summary>
/// Bubble sort.
/// </summary>
unsigned int* bubbleSort(unsigned int* arr, int n) 
{
    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
    return arr;
}

/// <summary>
/// Bubble sort with first Iverson condition.
/// </summary>
unsigned int* bubbleSortIv1(unsigned int* arr, int n) 
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
    return arr;
}

/// <summary>
/// Bubble sort with second Iverson condition.
/// </summary>
unsigned int* bubbleSortIv2(unsigned int* arr, int n) 
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
    return arr;
}

/// <summary>
/// Insertion sort.
/// On each iteration find greatest element and put it to the end. 
/// </summary>
unsigned int* insertionSort(unsigned int* arr, int n) 
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
    return arr;
}

/// <summary>
/// Binary insertion sort.
/// Find greatest element with binary search.
/// </summary>
unsigned int* insertionSortBin(unsigned int* arr, int n) 
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
    return arr;
}

/// <summary>
/// Counting sort.
/// </summary>
unsigned int* countingSort(unsigned int* arr, int n, int max) 
{
    unsigned int* counter = new unsigned int[max];
    unsigned int* sorted = new unsigned int[n];

    for (int i = 0; i < max; ++i) 
        counter[i] = 0;
    for (int i = 0; i < n; ++i)
        ++counter[arr[i]];
    for (int j = 1; j < max; ++j)
        counter[j] += counter[j - 1];
    for (int i = n - 1; i >= 0; --i) 
    {
        --counter[arr[i]];
        sorted[counter[arr[i]]] = arr[i];
    }
    
    delete [] arr;
    delete [] counter;
    
    return sorted;
}

/// <summary>
/// Radix sort with union.
/// </summary>
uint_256* radixSort(uint_256* arr, int n, int max) 
{
    unsigned int* counter = new unsigned int[max];
    uint_256* sorted = new uint_256[n];

    for (int dig = 3; dig >= 0; --dig) 
    {
        for (int i = 0; i < max; ++i)
            counter[i] = 0;
        for (int i = 0; i < n; ++i)
            ++counter[arr[i].chars[dig]];
        for (int j = 1; j < max; ++j)
            counter[j] += counter[j - 1];
        for (int i = n - 1; i >= 0; --i) 
        {
            --counter[arr[i].chars[dig]];
            sorted[counter[arr[i].chars[dig]]] = arr[i];
        }
    }
    
    delete [] counter;
    delete [] arr;
    
    return sorted;
}
