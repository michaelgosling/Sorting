// Source file for Sorter
// Created by Michael Gosling on 2/18/19.
//

#include <iostream>
#include <fstream>
#include "Sorter.h"
#include <cstring>
#include <iterator>
#include "SortingAlgos.h"


/**
 * Fills an array with random unsorted values
 * @param array Array to fill
 */
void Sorter::createUnsortedArray(int array[]) {
    // seed rand
    srand((unsigned)time(nullptr));
    for (auto i = 0; i < arraySize; i++)
        array[i] = rand() % 32767; // random num between 0 and 32767
}


/**
 * Write an array to a file
 * @param array Array to write
 * @param fileName Filename to write to
 */
void Sorter::writeArrToFile(int array[], std::string fileName) {
    std::ofstream outputFile; // output file
    outputFile.open(fileName); // open file name
    // if the file is open
    if (outputFile.is_open()){
        // write each integer in the array to the file followed by a comma, unless it's the last
        for (auto i = 0; i < arraySize; i++){
            outputFile << array[i];
            if (i != arraySize-1) outputFile << ",";
        }
        outputFile.close(); // close file
    } else
        std::cout << "Failed to open file" << std::endl; // display console message if file isn't not open
}

/**
 * Reset the sorting array to the initial unsorted values
 */
void Sorter::resetSortingArray(){
    for (auto i = 0; i < arraySize; i++)
        sortingArray[i] = unsortedArray[i];
}

/**
 * Run the given sorting algorithm
 * @param algo Algorithm to use
 */
void Sorter::runSort(Algo algo) {
    resetSortingArray(); // reset sorting array to unsorted state
    std::string fileName; // output filename
    start = std::clock(); // start time
    // depending on the given algorithm, set the file name and run the corresponding sort algo
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
            fileName = "RadixSort.txt";
            SortingAlgos::radixSort(sortingArray, arraySize);
            break;
    }
    end = std::clock(); // end time
    duration = (end - start) / (double) CLOCKS_PER_SEC; // duration
    // if the array is 1000 items long, just write it to file and tell the user it's written.
    // otherwise, display the timing values
    if (arraySize == 1000) {
        writeArrToFile(sortingArray, fileName);
        std::cout << "Written to file!" << std::endl << std::endl;
    } else
        std::cout << "Start: " << start << std::endl << "End: " << end << std::endl <<
                  "Duration: " << duration << "s" << std::endl << std::endl;
}

/**
 * Constructor
 * @param size Size of the array
 */
Sorter::Sorter(int size) {
    arraySize = size;
    // create unsorted array
    unsortedArray = new int[arraySize];
    createUnsortedArray(unsortedArray);
    // create sorting array of same size
    sortingArray = new int[arraySize];
}