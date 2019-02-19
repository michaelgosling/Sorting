// Header file for SortingAlgos source file
// Created by Michael Gosling on 2/18/19.
//

#ifndef SORTING_SORTINGALGOS_H
#define SORTING_SORTINGALGOS_H


class SortingAlgos {
public:
    // Bubble Sort
    static void bubbleSort(int a[], int length);
    static void swap(int *xp, int *yp);

    // Selection Sort
    static void selectionSort(int a[], int length);

    // Insertion Sort
    static void insertionSort(int a[], int length);

    // Shell Sort
    static void shellSort(int a[], int length);

    // Quick Sort
    static int partition(int *array, int beg, int end);
    static void quickSort(int *array, int beg, int end, int size);
    static void quickSort(int *array, int size);

};


#endif //SORTING_SORTINGALGOS_H
