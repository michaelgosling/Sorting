// Header file for Sorter
// Created by Michael Gosling on 2/18/19.
//

#ifndef SORTING_SORTER_H
#define SORTING_SORTER_H

#include <ctime>

enum Algo {
    Bubble, Selection, Insertion, Shell, Quick, Merge, Radix
};

class Sorter {
private:
    std::clock_t start;
    std::clock_t end;
    double duration;
    int* unsortedArray;
    int* sortingArray;
    int arraySize;

    void resetSortingArray();
    void createUnsortedArray(int array[]);
    void writeArrToFile(int array[], std::string fileName);
public:
    Sorter(int size);
    void runSort(Algo algo);

};


#endif //SORTING_SORTER_H
