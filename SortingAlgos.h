//
// Created by mgosling94 on 2/18/19.
//

#ifndef SORTING_SORTINGALGOS_H
#define SORTING_SORTINGALGOS_H


class SortingAlgos {
public:
    // Bubble Sort
    static void bubbleSort(int a[]);

    // Selection Sort
    static void selectionSort(int a[]);

    // Insertion Sort
    static void insertionSort(int a[], int length);

    // Shell Sort
    static void shellSort(int a[], int length);

    // Quick Sort
    static int Partition(int *array, int beg, int end);
    static void QuickSort(int *array, int beg, int end, int size);
    static void QuickSort(int *array, int size);

};


#endif //SORTING_SORTINGALGOS_H
