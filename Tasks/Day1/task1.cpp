#include <iostream>

using namespace std;

/**
 * Reverse the order of the elements at indices [begin; end] in the array
 * @param arr The array whose elements are to be reversed
 * @param begin Start index (inclusive) of the interval to be reversed
 * @param end Start index (inclusive) of the interval to be reversed
 */
void reserse_array(int* arr, int begin, int end)
{
    for(int i = 0; i < (end - begin + 1) / 2; i++) {
        int temp = arr[begin + i];
        arr[begin + i] = arr[end - i];
        arr[end - i] = temp;
    }
}

int main(int argc, char* argv[])
{
    int N, k;

    cout << "Enter N: ";
    cin >> N;

    cout << "Enter k: ";
    cin >> k;

    int* arr = new int[N];

    cout << "Array is:" << endl;

    for(int i = 0; i < N; i++) {
        arr[i] = i + 1;
        cout << arr[i] << "; ";
    }

    k %= N;

    /*
     * Shift array to the left by k positions in O(n) time
     */
    reserse_array(arr, 0, k - 1);
    reserse_array(arr, k, N - 1);
    reserse_array(arr, 0, N - 1);

    cout << endl << "Array after shifting is:" << endl;

    for(int i = 0; i < N; i++) {
        cout << arr[i] << "; ";
    }

    delete[] arr;

    return 0;
}
