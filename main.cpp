/*
 * Main.cpp - Get Array size from the user, generate new array and sort it.
 * Author: Michael Gosling
 */

#include <iostream>
#include "Sorter.h"
#include <regex>

int main() {
    std::string userInput; // holds user input
    std::regex reg("\\d+"); // validates user input

    // while the userinput doesn't match the regex
    while (!std::regex_match(userInput, reg)) {
        // get array size from user
        std::cout << "Enter an array size: ";
        std::cin >> userInput;
        if (!std::regex_match(userInput, reg))
            std::cout << "Invalid input, try again" << std::endl; // if input is invalid, tell them.
    }

    // once input is valid, translate it to int.
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
    std::cout << "_Quick Sort_" << std::endl;
    sorter.runSort(Quick);

    // run merge sort
    std::cout << "_Merge Sort_" << std::endl;
    sorter.runSort(Merge);

    // run radix sort
    std::cout << "_Radix Sort_" << std::endl;
    sorter.runSort(Radix);

    return 0;
}