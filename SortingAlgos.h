// Header file for SortingAlgos source file
// Created by Michael Gosling on 2/18/19.
//

#ifndef SORTING_SORTINGALGOS_H
#define SORTING_SORTINGALGOS_H


class SortingAlgos {
private:
    // Quick Sort Helper Functions
    static int partition(int a[], int beg, int end);
    static void quickSort(int a[], int beg, int end, int length);

    // Merge Sort Helper functions
    static void merge(int a[], int left, int middle, int right);

    // Radix Sort helper functions
    static int getMax(int a[], int length);
    static void countSort(int a[], int length, int e);
public:
    // Bubble Sort
    static void bubbleSort(int a[], int length);

    // Selection Sort
    static void selectionSort(int a[], int length);

    // Insertion Sort
    static void insertionSort(int a[], int length);

    // Shell Sort
    static void shellSort(int a[], int length);

    // Quick Sort
    static void quickSort(int a[], int length);

    // Merge Sort
    static void mergeSort(int a[], int left, int right);

    // Radix Sort
    static void radixSort(int a[], int length);

};


#endif //SORTING_SORTINGALGOS_H
