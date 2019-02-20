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


/**
 * Find the pivot point of the array by partitioning it
 * @param a Array to partition
 * @param beg Beginning of the array
 * @param end End of the array
 * @return The pivot point of the array
 */
int SortingAlgos::partition(int a[], int beg, int end) {
    int p = beg, pivot = a[beg], location;
    for (location = beg + 1; location <= end; location++) {
        if (pivot>a[location]) {
            a[p] = a[location];
            a[location] = a[p + 1];
            a[p + 1] = pivot;
            p++;
        }
    }
    return p;
}

/**
 * Sort an array using the Quick Sort algorithm
 * @param a Array to sort
 * @param beg Beginning of array
 * @param end end of array
 * @param length size of the array
 */
void SortingAlgos::quickSort(int a[], int beg, int end, int length) {
    if (beg<end) {
        int pivot = partition(a, beg, end); // find pivot
        quickSort(a, beg, pivot - 1, length); // subsort left
        quickSort(a, pivot + 1, end, length); // subsort right
    }
}


/**
 * Overload so we don't always have to pass in the beginning and end
 * @param a
 * @param length
 */
void SortingAlgos::quickSort(int a[], int length) {
    quickSort(a, 0, length - 1, length);
}


/**
 * Merge arrays
 * @param a array
 * @param left left index
 * @param middle middle point
 * @param right right index
 */
void SortingAlgos::merge(int a[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 =  right - middle;

    // temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) L[i] = a[left + i];
    for (j = 0; j < n2; j++) R[j] = a[middle + 1+ j];

    // merge temp arrays
    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = left; // initial index of merged subarray
    while (i < n1 && j < n2) { // while the index of the subarrays are less than n1 and n2 respectively
        if (L[i] <= R[j]) { // if the left array value is smaller, assign it's position in the main array
            a[k] = L[i];
            i++;
        } else { // otherwise assign the right array value
            a[k] = R[j];
            j++;
        }
        k++; // increment merged array index either way
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Perform Merge Sort on given array
 * @param a array to sort
 * @param left left index
 * @param right right index
 */
void SortingAlgos::mergeSort(int a[], int left, int right) {
    if (left < right) {
        // get middle to split in two
        int mid = left+(right-left)/2;

        // sort first and second halves
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);

        // merge the halves
        merge(a, left, mid, right);
    }
}


/**
 * Sort array using Radix Sort
 * @param a array to sort
 * @param length size of the array
 */
void SortingAlgos::radixSort(int a[], int length) {
    // TODO: Radix Sort
}


