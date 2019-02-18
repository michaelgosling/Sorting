#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include "SortingAlgos.h"

static void createUnsortedArray(int array[], int length) {
    time_t t;
    srand((unsigned)time(&t));
    for (auto i = 0; i < length; i++)
        array[i] = rand() % 32767;
}

void writeArrToFile(int array[]) {
    // TODO: Writing array to file
}

int main() {
    SortingAlgos sorts;
    std::string userInput;
    std::clock_t start;
    std::clock_t end;
    double duration;

    // get array size from user
    std::cout << "Enter an array size: ";
    std::cin >> userInput;
    int arraySize = stoi(userInput);

    // create unsorted array
    int unsortedArray[arraySize];
    createUnsortedArray(unsortedArray, arraySize);

    // copy array to sorting array
    int sortingArray[arraySize];
    std::memcpy(sortingArray, unsortedArray, sizeof(unsortedArray));

    /*
     * Bubble Sort
     */
    std::cout << "_Bubble Sort_" << std::endl;
    start = std::clock();
    sorts.bubbleSort(sortingArray, arraySize);
    end = std::clock();
    duration = (end - start) / (double) CLOCKS_PER_SEC;
    if (arraySize == 1000)
        writeArrToFile(sortingArray);
    else
        std::cout << "Start: " << start << ", End: " << end << ", Duration: " << duration << std::endl << std::endl;

    // reset sorting array to original
    std::memcpy(sortingArray, unsortedArray, sizeof(unsortedArray));

    /*
     * Selection Sort
     */
    std::cout << "_Selection Sort_" << std::endl;
    start = std::clock();
    sorts.selectionSort(sortingArray, arraySize);
    end = std::clock();
    duration = (end - start) / (double) CLOCKS_PER_SEC;
    if (arraySize == 1000)
        writeArrToFile(sortingArray);
    else
        std::cout << "Start: " << start << ", End: " << end << ", Duration: " << duration << std::endl << std::endl;

    // reset sorting array to original
    std::memcpy(sortingArray, unsortedArray, sizeof(unsortedArray));

    /*
     * Insertion Sort
     */
    std::cout << "_Insertion Sort_" << std::endl;
    start = std::clock();
    sorts.insertionSort(sortingArray, arraySize);
    end = std::clock();
    duration = (end - start) / (double) CLOCKS_PER_SEC;
    if (arraySize == 1000)
        writeArrToFile(sortingArray);
    else
        std::cout << "Start: " << start << ", End: " << end << ", Duration: " << duration << std::endl << std::endl;

    // reset sorting array to original
    std::memcpy(sortingArray, unsortedArray, sizeof(unsortedArray));

    /*
     * Shell Sort
     */
    std::cout << "_Shell Sort_" << std::endl;
    start = std::clock();
    sorts.shellSort(sortingArray, arraySize);
    end = std::clock();
    duration = (end - start) / (double) CLOCKS_PER_SEC;
    if (arraySize == 1000)
        writeArrToFile(sortingArray);
    else
        std::cout << "Start: " << start << ", End: " << end << ", Duration: " << duration << std::endl << std::endl;

    // reset sorting array to original
    std::memcpy(sortingArray, unsortedArray, sizeof(unsortedArray));

    /*
     * Quick Sort
     */
    std::cout << "_Quick Sort_" << std::endl;
    start = std::clock();
    sorts.quickSort(sortingArray, arraySize);
    end = std::clock();
    duration = (end - start) / (double) CLOCKS_PER_SEC;
    if (arraySize == 1000)
        writeArrToFile(sortingArray);
    else
        std::cout << "Start: " << start << ", End: " << end << ", Duration: " << duration << std::endl << std::endl;

    return 0;
}