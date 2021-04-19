#include "heapsort.h"

void HeapSortMin (int data[], int arrayLength)
{
	int i;
	printf ("Perubahan Array:\n");
	BuildMaxHeapify (data, arrayLength);
	
	// Sorting Process
	for (i = arrayLength - 1; i > 0; i--)
	{
		Swap (data, 0, i);
		Array__Display (data, arrayLength);
		MaxHeapify (data, i, 0, arrayLength);
	}
}

void HeapSortMax (int data[], int arrayLength)
{
	int i;
	printf ("Perubahan Array:\n");
	BuildMinHeapify (data, arrayLength);
	
	// Sorting Process
	for (i = arrayLength - 1; i > 0; i--)
	{
		Swap (data, 0, i);
		Array__Display (data, arrayLength);
		MinHeapify (data, i, 0, arrayLength);
	}
}
void BuildMinHeapify (int data[], int arrayLength)
{
	int startIndex = getParentIndex (arrayLength - 1);
	int heapSize = arrayLength;
	int i;
	
	for (i = startIndex; i >= 0; i--)
	{
		MinHeapify (data, heapSize, i, arrayLength);
	}
}

void BuildMaxHeapify (int data[], int arrayLength)
{
	int startIndex = getParentIndex (arrayLength - 1);
	int heapSize = arrayLength;
	int i;
	
	for (i = startIndex; i >= 0; i--)
	{
		MaxHeapify (data, heapSize, i, arrayLength);
	}
}

void MinHeapify (int data[], int heapSize, int index, int arrayLength)
{
	int smallest = index;
	int leftChild = getChildLeftIndex (index);
	int rightChild = getChildRightIndex (index);

	if (leftChild < heapSize && data[leftChild] < data[smallest])
	{
		smallest = leftChild;
	}
	
	if (rightChild < heapSize && data[rightChild] < data[smallest])
	{
		smallest = rightChild;
	}
	
	if (smallest != index)
	{
		Swap (data, index, smallest);
		Array__Display (data, arrayLength);
		MinHeapify (data, heapSize, smallest, arrayLength);
	}
}

void MaxHeapify (int data[], int heapSize, int index, int arrayLength)
{
	int largest = index;
	int leftChild = getChildLeftIndex (index);
	int rightChild = getChildRightIndex (index);

	if (leftChild < heapSize && data[leftChild] > data[largest])
	{
		largest = leftChild;
	}
	
	if (rightChild < heapSize && data[rightChild] > data[largest])
	{
		largest = rightChild;
	}
	
	if (largest != index)
	{
		Swap (data, index, largest);
		Array__Display (data, arrayLength);
		MaxHeapify (data, heapSize, largest, arrayLength);
	}
}

int getParentIndex (int curr)
{
	return (curr - 1) / 2;
}

int getChildLeftIndex (int curr)
{
	return 2*curr + 1;
}

int getChildRightIndex (int curr)
{
	return 2*curr + 2;
}

void Swap (int data[], int i, int j)
{
	int temp;
	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
