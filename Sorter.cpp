//
// Created by michael on 2/18/19.
//

#include <iostream>
#include "Sorter.h"
#include <cstring>
#include <cstdio>
#include "SortingAlgos.h"


void Sorter::createUnsortedArray(int array[]) {
    srand((unsigned)time(nullptr));
    for (auto i = 0; i < arraySize; i++)
        array[i] = rand() % 32767;
}

void Sorter::writeArrToFile(int array[]) {
    // TODO: Writing array to file
}

void Sorter::resetSortingArray(){
    std::memcpy(sortingArray, &unsortedArray, sizeof(unsortedArray));
}

void Sorter::runSort(Algo algo) {
    resetSortingArray(); // reset sorting array to unsorted state
    start = std::clock(); // start time
    switch (algo) {
        case Bubble:
            SortingAlgos::bubbleSort(sortingArray, arraySize);
            break;
        case Selection:
            SortingAlgos::selectionSort(sortingArray, arraySize);
            break;
        case Insertion:
            SortingAlgos::insertionSort(sortingArray, arraySize);
            break;
        case Shell:
            SortingAlgos::shellSort(sortingArray, arraySize);
            break;
        case Quick:
            SortingAlgos::quickSort(sortingArray, arraySize);
            break;
    }
    end = std::clock(); // end time
    duration = (end - start) / (double) CLOCKS_PER_SEC; // duration
    if (arraySize == 1000)
        writeArrToFile(sortingArray);
    else
        std::cout << "Start: " << start << ", End: " << end << ", Duration: " << duration << std::endl << std::endl;
}

Sorter::Sorter(int size) {
    arraySize = size;
    // create unsorted array
    unsortedArray = new int[arraySize];
    createUnsortedArray(unsortedArray);
    // copy array to sorting array
    sortingArray = new int[arraySize];
    std::memcpy(sortingArray, &unsortedArray, sizeof(unsortedArray));
}