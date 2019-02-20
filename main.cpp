#include <iostream>
#include "Sorter.h"

int main() {
    std::string userInput;

    // get array size from user
    std::cout << "Enter an array size: ";
    std::cin >> userInput;
    int arraySize = stoi(userInput);

    // create sorter
    Sorter sorter(arraySize);
    std::cout << std::endl;

    // run bubble sort
    std::cout << "_Bubble Sort_" << std::endl;
    sorter.runSort(Bubble);

    // run selection sort
    std::cout << "_Selection Sort_" << std::endl;
    sorter.runSort(Selection);

    // run insertion sort
    std::cout << "_Insertion Sort_" << std::endl;
    sorter.runSort(Insertion);

    // run shell sort
    std::cout << "_Shell Sort_" << std::endl;
    sorter.runSort(Shell);

    // run quick sort
    std::cout << "_Quick Sort" << std::endl;
    sorter.runSort(Quick);

    // run merge sort
    std::cout << "_Merge Sort_" << std::endl;
    sorter.runSort(Merge);

    return 0;
}