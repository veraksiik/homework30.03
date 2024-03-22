#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;



void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; 
    }
}


int findMinSequenceStart(int arr[], int start) {
    if (start > 90) {
        return -1; 
    }

    int minSum = arr[start] + arr[start + 1] + arr[start + 2] + arr[start + 3] + arr[start + 4] +
        arr[start + 5] + arr[start + 6] + arr[start + 7] + arr[start + 8] + arr[start + 9];

    int nextMinSumPos = findMinSequenceStart(arr, start + 1);

    if (nextMinSumPos == -1) {
        return start;
    }

    int nextMinSum = arr[nextMinSumPos] + arr[nextMinSumPos + 1] + arr[nextMinSumPos + 2] +
        arr[nextMinSumPos + 3] + arr[nextMinSumPos + 4] + arr[nextMinSumPos + 5] +
        arr[nextMinSumPos + 6] + arr[nextMinSumPos + 7] + arr[nextMinSumPos + 8] +
        arr[nextMinSumPos + 9];

    return (minSum < nextMinSum) ? start : nextMinSumPos;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMax(int arr[][3], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int findMax(int arr[][3][2], int x, int y, int z) {
    int max = arr[0][0][0];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                if (arr[i][j][k] > max) {
                    max = arr[i][j][k];
                }
            }
        }
    }
    return max;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int findMax(int a, int b, int c) {
    return max(a, b), c;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);   

    cout << "Задание 4 " <<  endl;


    int arr[100];
    generateRandomArray(arr, 100);

    int startPos = findMinSequenceStart(arr, 0);

    cout << "Позиция, с которой начинается последовательность из 10 чисел с минимальной суммой: " << startPos << endl;

    cout << "Задание 5 " << endl;

    int arr1D[] = { 3, 7, 2, 8, 1, 9, 6, 4, 5 };
    int arr2D[2][3] = { {1, 5, 3}, {9, 2, 6} };
    int arr3D[1][3][2] = { { {4, 8}, {3, 1}, {7, 2} } };

    cout << "Максимальное значение в одномерном массиве: " << findMax(arr1D, 9) << endl;
    cout << "Максимальное значение в двумерном массиве: " << findMax(arr2D, 2, 3) << endl;
    cout << "Максимальное значение в трехмерном массиве: " << findMax(arr3D, 1, 3, 2) << endl;
    cout << "Максимальное значение из двух чисел: " << findMax(10, 5) << endl;
    cout << "Максимальное значение из трех чисел: " << findMax(3, 7, 2) << endl;



    system("pause");
    return 0;
}

