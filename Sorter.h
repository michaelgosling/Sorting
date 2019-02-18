//
// Created by michael on 2/18/19.
//

#ifndef SORTING_SORTER_H
#define SORTING_SORTER_H

#include <ctime>

enum Algo {
    Bubble, Selection, Insertion, Shell, Quick
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
    void writeArrToFile(int array[]);
public:
    Sorter(int size);
    void runSort(Algo algo);

};


#endif //SORTING_SORTER_H
