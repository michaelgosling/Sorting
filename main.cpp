#include <iostream>
#include "SortingAlgos.h"

int* createUnsortedArray(int length) {
    int array[length];
    time_t t;
    srand((unsigned)time(&t));
    for (auto i = 0; i < length; i++)
        array[i] = rand() % 32767;

    return array;
}

int main() {
    SortingAlgos sorts;
    int arraySize;
    std::cout << "Enter an array size: ";
    std::cin >> arraySize;

    int* array = createUnsortedArray(arraySize);


    return 0;
}