// Фролов Максим Павлович БПИ162
// БОЛЬШОЙ ПРОЕКТ
// Разработано в CLion 2017.1.3
// 2017 год
// + Реализация всех сортировок
// + Автоматическая генерация тестов
// + Автоматическое тестирование сортировок
// + Вывод информации в csv файл

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <intrin.h>

union uint_256
{
    unsigned int num;
    unsigned char chars[4];
};

const int TIMES = 100;

static std::string sortFunctionsNames[7] =
        { "getBubbleSortTime", "getBubbleSortIv1Time", "getBubbleSortIv2Time", "getInsertionSortTime", "getInsertionSortBinTime", "getCountingSortTime", "getRadixSortTime" };

// Secondary functions.
void swap(unsigned int*, int, int);
unsigned int* copyArray(unsigned int*, int);
int binarySearch(unsigned int*, int, int, int);
unsigned int getMax(unsigned int*, int);
void printInfo(__int64[4][7][9], std::ostream&);

// Test generators.
unsigned int* getArray1(int);
unsigned int* getArray2(int);
unsigned int* getArray3(int);
unsigned int* getArray4(int);

bool sortValidation(unsigned int*, int);

// Sorts.
long long int getBubbleSortTime(unsigned int*, int);
long long int getBubbleSortIv1Time(unsigned int*, int);
long long int getBubbleSortIv2Time(unsigned int*, int);
long long int getInsertionSortTime(unsigned int*, int);
long long int getInsertionSortBinTime(unsigned int*, int);
long long int getCountingSortTime(unsigned int*, int);
long long int getRadixSortTime(unsigned int*, int);

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

    __int64 t[4][7][9];

    long long int (*sortFunctions[7])(unsigned int*, int) =
            { getBubbleSortTime, getBubbleSortIv1Time, getBubbleSortIv2Time, getInsertionSortTime, getInsertionSortBinTime, getCountingSortTime, getRadixSortTime };

    for (int arr = 0; arr < 4; ++arr) {
        for (int func = 0; func < 7; ++func) {
            for (int size = 1000; size <= 9000; size += 1000) {
                long long int tactsTemp = 0;
                for (int it = 0; it < TIMES; ++it) {
                    unsigned int* arrTemp = copyArray(arrays[arr], size);
                    std::cout << "Function: " << sortFunctionsNames[func] << ", array: " << arr << ", size: " << size
                              << ", test: " << it << std::endl;
                    // Если вдруг массив уже отсортирован.
                    if (sortValidation(arrTemp, size))
                    {
                        for (int i = 0; i < size; i++) {
                            std::cout << arrTemp[i] << " ";
                        }
                        std::cout << std::endl;
                        std::cout << "Array already sorted." << std::endl;
                        system("pause");
                        return -1;
                    }
                    long long int loopTemp = (*sortFunctions[func])(arrTemp, size);
                    std::cout << loopTemp << std::endl;
                    if (it < 3)
                        continue;
                    tactsTemp += loopTemp;
                    // Если после сортировки массив не стал сортированным.
                    if (!sortValidation(arrTemp, size)) {
                        for (int i = 0; i < size; i++) {
                            std::cout << arrTemp[i] << " ";
                        }
                        std::cout << std::endl;
                        std::cout << "Error in function " << sortFunctionsNames[func] << ". Not sorted." << std::endl;
                        system("pause");
                        return -1;
                    }
                }
                tactsTemp /= (TIMES - 3);
                std::cout << "---------------------------------------------------" << std::endl;
                std::cout << "For function " << sortFunctionsNames[func] << " for array " << arr << " with " << size
                          << " elements time = " << tactsTemp << std::endl;
                std::cout << "---------------------------------------------------" << std::endl;
                t[arr][func][size / 1000 - 1] = tactsTemp;
            }
        }
    }

    printInfo(t, std::cout);

    std::ofstream output("../output.csv");
    if (output.is_open())
    {
        printInfo(t, output);
    }

    system("pause");
}

// =======================================================================================
// =======================================================================================

/// <summary>
/// Swap two array elements.
/// </summary>
void swap(unsigned int* arr, int ind1, int ind2)
{
    unsigned int temp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = temp;
}

/// <summary>
/// Get reference to arr copy.
/// </summary>
unsigned int* copyArray(unsigned int *arr, int n)
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
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Get max element for counting sort.
/// </summary>
unsigned int getMax(unsigned int* arr, int n)
{
    unsigned int max = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

/// <summary>
/// Print info about sorts.
/// </summary>
void printInfo(__int64 arr[4][7][9], std::ostream& out)
{
    for (int i = 0; i < 4; ++i)
    {
        // out << "For array " << i << std::endl;
        for (int j = 0; j < 7; ++j)
        {
            // out << "\tFor function " << sortFunctionsNames[j] << std::endl;
            // out << "\t";
            for (int k = 0; k < 9; ++k)
            {
                out << arr[i][j][k] << ";";
            }
            out << "\n";
        }
        out << "\n\n";
    }
}

// =======================================================================================
// =======================================================================================

unsigned int* getArray1(int n)
{
    unsigned int* arr = new unsigned int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = (unsigned int)(rand() % 7); // Fill array with values from [0,7).
    return arr;
}

unsigned int* getArray2(int n)
{
    unsigned int* arr = new unsigned int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = (unsigned int)(rand()); // Fill array with values from [0,INT_MAX).
    return arr;
}

unsigned int* getArray3(int n)
{
    unsigned int* arr = new unsigned int[n];
    for (unsigned int i = 0; i < n; ++i)
        arr[i] = i; // Fill array with sorted values.

    // Select two random pairs from arr and swap it.
    int first, second;
    for (int i = 0; i < 5; ++i)
    {
        first = rand() % 1000;
        second = rand() % n;
        swap(arr, first, second);
    }
    return arr;
}

unsigned int* getArray4(int n)
{
    unsigned int* arr = new unsigned int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = (unsigned int)(n - i - 1); // Fill array with descending sorted values.
    return arr;
}

// =======================================================================================
// =======================================================================================

/// <summary>
/// Get time of bubble sort.
/// </summary>
__int64 getBubbleSortTime(unsigned int* arr, int n)
{
    __int64 start, end;
    start = __rdtsc();
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
    end = __rdtsc();
    return end - start;
}

/// <summary>
/// Get time of bubble sort with first Iverson condition.
/// </summary>
__int64 getBubbleSortIv1Time(unsigned int* arr, int n)
{
    __int64 start, end;
    start = __rdtsc();
    bool unsorted = true;
    for (int i = 1; i < n && unsorted; ++i)
    {
        unsorted = false;
        for (int j = 0; j < n - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                unsorted = true;
            }
        }
    }
    end = __rdtsc();
    return end - start;
}

/// <summary>
/// Get time of bubble sort with second Iverson condition.
/// </summary>
__int64 getBubbleSortIv2Time(unsigned int* arr, int n)
{
    __int64 start, end;
    start = __rdtsc();
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
    end = __rdtsc();
    return end - start;
}

/// <summary>
/// Get time of isertion sort.
/// On each iteration find greatest element and put it to the end.
/// </summary>
__int64 getInsertionSortTime(unsigned int* arr, int n)
{
    __int64 start, end;
    start = __rdtsc();
    for (int i = 1; i < n; ++i)
    {
        unsigned int t = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > t; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = t;
    }
    end = __rdtsc();
    return end - start;
}

/// <summary>
/// Get time of binary insertion sort.
/// Find greatest element with binary search.
/// </summary>
__int64 getInsertionSortBinTime(unsigned int* arr, int n)
{
    __int64 start, end;
    start = __rdtsc();
    for (int i = 1; i < n; ++i)
    {
        if (arr[i - 1] > arr[i])
        {
            unsigned int t = arr[i];
            int ind;
            if (t <= arr[0])
                ind = 0;
            else
                ind = binarySearch(arr, 0, i - 1, t);
            for (int j = i - 1; j >= ind; --j)
            {
                arr[j + 1] = arr[j];
            }
            arr[ind] = t;
        }
    }
    end = __rdtsc();
    return end - start;
}

/// <summary>
/// Get time of counting sort.
/// </summary>
__int64 getCountingSortTime(unsigned int* arr, int n)
{
    unsigned int max = getMax(arr, n);
    unsigned int* counter = new unsigned int[max + 1];
    unsigned int* sorted = new unsigned int[n];

    __int64 start, end;
    start = __rdtsc();
    for (int i = 0; i < max + 1; ++i)
        counter[i] = 0;
    for (int i = 0; i < n; ++i)
        ++counter[arr[i]];
    for (int j = 1; j < max + 1; ++j)
        counter[j] += counter[j - 1];
    for (int i = n - 1; i >= 0; --i)
    {
        --counter[arr[i]];
        sorted[counter[arr[i]]] = arr[i];
    }
    end = __rdtsc();

    for (int i = 0; i < n; ++i)
        arr[i] = sorted[i];

    delete [] counter;
    delete [] sorted;
    return end - start;
}

/// <summary>
/// Get time of radix sort with union.
/// </summary>
__int64 getRadixSortTime(unsigned int* arr, int n)
{
    unsigned int max = 256;

    uint_256* sorted = new uint_256[n];

    __int64 start, end;
    start = __rdtsc();
    for (int dig = 0; dig < 4; ++dig)
    {
        for (int i = 0; i < n; ++i) {
            sorted[i].num = arr[i];
        }
        unsigned int* counter = new unsigned int[max];
        for (int i = 0; i < max; ++i)
            counter[i] = 0;
        for (int i = 0; i < n; ++i)
            ++counter[sorted[i].chars[dig]];
        unsigned int sum = 0, k;
        for (int i = 0; i < max; i++)
        {
            k = counter[i];
            counter[i] = sum;
            sum += k;
        }
        for (int i = 0; i < n; i++) {
            int tempIndex = sorted[i].chars[dig];
            arr[counter[tempIndex]] = sorted[i].num;
            counter[tempIndex]++;
        }
        /*for (int j = 1; j < max; ++j)
            counter[j] += counter[j - 1];
        for (int i = n - 1; i >= 0; --i)
        {
            --counter[sorted[i].chars[dig]];
            std::cout << sorted[i].chars[dig] << " " ;
            sorted[counter[sorted[i].chars[dig]]] = sorted[i];
        }*/
        delete [] counter;
    }
    end = __rdtsc();

    for (int i = 0; i < n; i++)
        arr[i] = sorted[i].num;

    delete [] sorted;
    return end - start;
}
