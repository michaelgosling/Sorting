// Source file for Sorter
// Created by Michael Gosling on 2/18/19.
//

#include <iostream>
#include <fstream>
#include "Sorter.h"
#include <cstring>
#include <iterator>
#include "SortingAlgos.h"


void Sorter::createUnsortedArray(int array[]) {
    srand((unsigned)time(nullptr));
    for (auto i = 0; i < arraySize; i++)
        array[i] = rand() % 32767;
}

void Sorter::writeArrToFile(int array[], std::string fileName) {
    std::ofstream outputFile;
    outputFile.open(fileName);
    if (outputFile.is_open()){
        outputFile << "[";
        for (auto i = 0; i < arraySize; i++){
            outputFile << array[i];
            if (i != arraySize-1)
                outputFile << ", ";
        }
        outputFile << "]";
        outputFile.close();
    } else
        std::cout << "Failed to open file" << std::endl;
}

void Sorter::resetSortingArray(){
    for (auto i = 0; i < arraySize; i++){
        sortingArray[i] = unsortedArray[i];
    }
}

void Sorter::runSort(Algo algo) {
    resetSortingArray(); // reset sorting array to unsorted state
    std::string fileName;
    start = std::clock(); // start time
    switch (algo) {
        case Bubble:
            fileName = "BubbleSort.txt";
            SortingAlgos::bubbleSort(sortingArray, arraySize);
            break;
        case Selection:
            fileName = "SelectionSort.txt";
            SortingAlgos::selectionSort(sortingArray, arraySize);
            break;
        case Insertion:
            fileName = "InsertionSort.txt";
            SortingAlgos::insertionSort(sortingArray, arraySize);
            break;
        case Shell:
            fileName = "ShellSort.txt";
            SortingAlgos::shellSort(sortingArray, arraySize);
            break;
        case Quick:
            fileName = "QuickSort.txt";
            SortingAlgos::quickSort(sortingArray, arraySize);
            break;
        case Merge:
            fileName = "MergeSort.txt";
            SortingAlgos::mergeSort(sortingArray, 0, arraySize-1);
            break;
        case Radix:
            break;
    }
    end = std::clock(); // end time
    duration = (end - start) / (double) CLOCKS_PER_SEC; // duration
    if (arraySize == 1000) {
        writeArrToFile(sortingArray, fileName);
        std::cout << "Written to file!" << std::endl << std::endl;
    }
    else
        std::cout << "Start: " << start << std::endl << "End: " << end << std::endl << "Duration: " << duration << "s" << std::endl << std::endl;
}

Sorter::Sorter(int size) {
    arraySize = size;
    // create unsorted array
    unsortedArray = new int[arraySize];
    createUnsortedArray(unsortedArray);
    // create sorting array of same size
    sortingArray = new int[arraySize];
}