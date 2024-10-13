#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

void randomnum(int a[], int size) {
    const int MIN_VALUE = -1;
    const int MAX_VALUE = 10;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);

    for (int i = 0; i < size; ++i) {
        a[i] = distribution(generator);
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

int countzeroElements(int* a, int n) {
    int zeroCount = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zeroCount++;
        }
    }
    return zeroCount;
}

double sumAfterLastMin(int arr[], int n) {
    if (n == 0) return 0;

    double minValue = arr[0];
    int lastMinIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] <= minValue) {
            minValue = arr[i];
            lastMinIndex = i;
        }
    }

    double sum = 0;
    for (int i = lastMinIndex + 1; i < n; ++i) {
        sum += arr[i];
    }

    return sum;

}

void bubbleSortOddByAbs(int a[], int size) {
   
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
          
            if (a[j] % 2 != 0 && a[j + 1] % 2 != 0) {
                
                if (abs(a[j]) > abs(a[j + 1])) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }
}


int main() {
    const int SIZE = 10;
    int arr[SIZE];

    randomnum(arr, SIZE);
    cout << "Original array: ";
    printArray(arr, SIZE);

    bubbleSortOddByAbs(arr, SIZE);
    cout << "Array after sorting odd elements by absolute values: ";
    printArray(arr, SIZE);


    int zeroCount = countzeroElements(arr, SIZE);
    cout << "Number of zero elements: " << zeroCount << endl;

    double sum = sumAfterLastMin(arr, SIZE);
    cout << "Sum after the last minimum element: " << sum << endl;


    return 0;
}