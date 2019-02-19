// Source file for SortingAlgos.h
// Created by Michael Gosling on 2/18/19.

#include "SortingAlgos.h"

/**
 * Sort an array using the bubble sort algorithm
 * @param a Array to sort
 * @param length array length
 */
void SortingAlgos::bubbleSort(int a[], int length) {
    int i, j;
    for (i = 0; i < length-1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/**
 * Sort an array using the selection sort algorithm
 * @param a Array to sort
 * @param length length of array
 */
void SortingAlgos::selectionSort(int a[], int length) {
    int outer, inner, min;
    for (outer = 0; outer < length - 1; outer++) { // outer counts down
        min = outer;
        for (inner = outer + 1; inner < length; inner++) {
            if (a[inner] < a[min])
                min = inner;
        }
        // a[min] is least among a[outer]..a[a.length - 1]
        int temp = a[outer];
        a[outer] = a[min];
        a[min] = temp;
    }
}

/**
 * Sort an array using the insertion sort algorithm
 * @param a Array to sort
 * @param length Length of the array
 */
void SortingAlgos::insertionSort(int a[], int length) {
    int i, j, tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
            j--;
        }
    }
}

/**
 * Sort an array using the Shell sort algorithm
 * @param a Array to sort
 * @param length Length of the array
 */
void SortingAlgos::shellSort(int a[], int length) {
    int i, j, increment;
    for (increment = length / 2; increment > 0; increment /= 2) {
        for (i = increment; i < length; i++) {
            auto temp = a[i];
            for (j = i; j >= increment; j -= increment) {
                if (temp < a[j - increment])
                    a[j] = a[j - increment];
                else
                    break;
            }
            a[j] = temp;
        }
    }
}

/*
 * [Quick Sort]
 */

/**
 * Find the pivot point of the array by partitioning it
 * @param array Array to partition
 * @param beg Beginning of the array
 * @param end End of the array
 * @return The pivot point of the array
 */
int SortingAlgos::partition(int *array, int beg, int end) {
    int p = beg, pivot = array[beg], location;
    for (location = beg + 1; location <= end; location++) {
        if (pivot>array[location]) {
            array[p] = array[location];
            array[location] = array[p + 1];
            array[p + 1] = pivot;
            p++;
        }
    }
    return p;
}

/**
 * Sort an array using the Quick Sort algorithm
 * @param array Array to sort
 * @param beg Beginning of array
 * @param end end of array
 * @param size size of the array
 */
void SortingAlgos::quickSort(int *array, int beg, int end, int size) {
    if (beg<end) {
        int pivot = partition(array, beg, end); // find pivot
        quickSort(array, beg, pivot - 1, size); // subsort left
        quickSort(array, pivot + 1, end, size); // subsort right
    }
}


/**
 * Overload so we don't always have to pass in the beginning and end
 * @param array
 * @param size
 */
void SortingAlgos::quickSort(int *array, int size) {
    quickSort(array, 0, size - 1, size);
}


/*
 * [Radix Sort]
 */
// TODO: Radix Sort