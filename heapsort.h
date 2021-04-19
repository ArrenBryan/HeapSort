/**
 *	Heap Sort Program.
 *
 *	Author:	Alifia Ghea Putri (191511004).
 *			Bryan Azriel Parulian (191511008).
 *			Mohammad Ichwan (191511022).
 *
 *	Created on:	14 Juni 2020.
 *
 *	Referance: https://www.geeksforgeeks.org/heap-sort/
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <stdio.h>

/**
 * Heap Sort from minimum numbers to maximum numbers.
 *
 * @param data data array of numbers.
 * @param arrayLength length of the array.
 */
void HeapSortMin (int data[], int arrayLength);

/**
 * Heap Sort from maximum numbers to minimum numbers.
 *
 * @param data data array of numbers.
 * @param arrayLength length of the array.
 */
void HeapSortMax (int data[], int arrayLength);

/**
 * Build minimum heap.
 *
 * @param data data array of numbers.
 * @param arrayLength length of the array.
 */
void BuildMinHeapify (int data[], int arrayLength);

/**
 * Build maximum heap.
 *
 * @param data data array of numbers.
 * @param arrayLength length of the array.
 */
void BuildMaxHeapify (int data[], int arrayLength);

/**
 * Build minimum heap.
 *
 * @param data data array of numbers.
 * @param heapSize size of the heap.
 * @param index index node / index array.
 * @param arrayLength length of the array.
 */
void MinHeapify (int data[], int heapSize, int index, int arrayLength);

/**
 * Build maximum heap.
 *
 * @param data data array of numbers.
 * @param heapSize size of the heap.
 * @param index index node / index array.
 * @param arrayLength length of the array.
 */
void MaxHeapify (int data[], int heapSize, int index, int arrayLength);

/**
 * Get index of its parent.
 *
 * @param curr current index
 * @return index of its parent.
 */
int getParentIndex (int curr);

/**
 * Get index of its leftchild.
 *
 * @param curr current index
 * @return index of its leftchild.
 */
int getChildLeftIndex (int curr);

/**
 * Get index of its rightchild.
 *
 * @param curr current index
 * @return index of its rightchild.
 */
int getChildRightIndex (int curr);

/**
 * Swap numbers on array.
 *
 * @param data data array of numbers.
 * @param i the index that will swap.
 * @param j the index that will swap.
 */
void Swap (int data[], int i, int j);

#endif
