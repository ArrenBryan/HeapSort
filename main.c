#include <stdlib.h>
#include <stdbool.h>
#include "heapsort.h"

/**
 * Create the data (numbers) from user's input.
 *
 * @param arrayLength length of the array.
 * @return array instance.
 */
int *Array__Create (int arrayLength);

/**
 * Create the data (numbers) from file.
 *
 * @param arrayLength length of the array.
 * @return array instance.
 */
int *Array__CreateFile (int arrayLength);

/**
 * Create the data (numbers) from user's input.
 *
 * @param data data array of numbers
 * @param arrayLength length of the array.
 * @return array instance.
 */
int *Array__Duplicate (int data[], int arrayLength);

/**
 * Print the data (numbers).
 *
 * @param data data array of numbers.
 * @param arrayLength length of the array.
 */
void Array__Display (int data[], int arrayLength);

/**
 * Get total numbers in file.
 * 
 * @return total numbers in file.
 */
int getArrayLengthFile();

/**
 * Write sorted data (min to max) to file.
 *
 * @param data data array of numbers.
 * @param arrayLength length of the array.
 */
void WriteDataFileMin (int data[], int arrayLength);

/**
 * Write sorted data (max to min) to file.
 *
 * @param data data array of numbers.
 * @param arrayLength length of the array.
 */
void WriteDataFileMax (int data[], int arrayLength);

/**
 * Checking if the file is empty or not.
 */
bool isFileEmpty();

/**
 * Collection of Algorihms for sorting element from user's input.
 */
void InputManual();

/**
 * Collection of Algorihms for sorting element from file.
 */
void SortingFile();

int main()
{
	while (1)
	{
		int ans;
		
		printf ("===========================================================\n");
		printf ("1. Input Manual\n");
		printf ("2. Sorting via File\n");
		printf ("3. Exit\n");
		printf ("===========================================================\n");
		printf ("   Input Pilihan Menu: ");
		while (scanf ("%d", &ans) == 0)
		{
			system ("cls");
			printf ("===========================================================\n");
			printf ("1. Input Manual\n");
			printf ("2. Sorting via File\n");
			printf ("3. Exit\n");
			printf ("===========================================================\n");
			printf ("   Inputan bukan merupakan angka!\n");
			printf ("   Input Pilihan Menu: ");
			fflush(stdin);
		}

		system ("cls");
		
		switch (ans)
		{
			case 1:
			{
				InputManual();
				break;
			}
			
			case 2:
			{
				SortingFile();
				break;
			}
			
			case 3:
			{
				exit(0);	
			}
			
			default:
			{
				printf ("===========================================================\n");
				printf ("   Inputan Salah!\n");
				printf ("===========================================================\n");
				break;
			}
		}
		
		printf ("Press any key to Main Menu ....");
		getch();
		system ("cls");
	}
	
	return 0;
}

int *Array__Create (int arrayLength)
{
	int i;
	int *data = (int*) malloc (arrayLength * sizeof(int));
	
	for (i = 0; i < arrayLength; i++)
	{
		fflush(stdin);
		printf ("Input No. %d: ", i + 1);
		while (scanf ("%d", &data[i]) == 0)
		{
			printf ("Inputan bukan merupakan angka!\n");
			printf ("Input No. %d: ", i + 1);
			fflush(stdin);
		}
	}
	
	system ("cls");
	return data;
}

int *Array__CreateFile (int arrayLength)
{
	FILE *fPointer;
	fPointer = fopen ("Datas/GivenData.txt", "r");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int i;
	int *data = (int*) malloc (arrayLength * sizeof(int));
	
	for (i = 0; i < arrayLength; i++)
	{
		fscanf (fPointer, "%d", &data[i]);
	}

	fclose (fPointer);
	return data;
}

int *Array__Duplicate (int data[], int arrayLength)
{
	int i;
	int *newData = (int*) malloc (arrayLength * sizeof(int));
	
	for (i = 0; i < arrayLength; i++)
	{
		newData[i] = data[i];
	}
	
	return newData;
}

void Array__Display (int data[], int arrayLength)
{
	int i; 
	for (i = 0; i < arrayLength; i++)
	{
		printf("%d ", data[i]);
	}
	printf ("\n");
}

int getArrayLengthFile()
{
	FILE *fPointer;
	fPointer = fopen ("Datas/GivenData.txt", "r");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int arrayLength = 0;
	int tempData;

	while (!feof(fPointer))
	{
		fscanf(fPointer, "%d", &tempData);
		arrayLength++;
		if ((fscanf(fPointer, "%d", &tempData)) == 0)
		{
			printf ("===========================================================\n");
			printf ("  Terdapat data yang tidak sesuai pada file!\n");
			printf ("  Data yang diinputkan harus berupa integer!\n");
			printf ("===========================================================");
			exit(0);
		}
		else 
		{
			arrayLength++;
		}
	}
	
	fclose (fPointer);
	return arrayLength;
}

void WriteDataFileMin (int data[], int arrayLength)
{
	FILE *fPointer;
	fPointer = fopen ("Datas/MinToMax.txt", "w");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int i;
	for (i = 0; i < arrayLength; i++)
	{
		fprintf (fPointer, "%d ", data[i]);
	}
	
	fclose (fPointer);
}

void WriteDataFileMax (int data[], int arrayLength)
{
	FILE *fPointer;
	fPointer = fopen ("Datas/MaxToMin.txt", "w");
	
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	int i;
	for (i = 0; i < arrayLength; i++)
	{
		fprintf (fPointer, "%d ", data[i]);
	}
	
	fclose (fPointer);
}

bool isFileEmpty()
{
	FILE *fPointer;
	fPointer = fopen ("Datas/GivenData.txt", "r");
		
	if (fPointer == NULL)
	{
		perror ("Error opening file!");
		exit (1);
	}
	
	fseek(fPointer, 0, SEEK_END);
	if (ftell(fPointer) == 0)
	{
		fclose (fPointer);
		return true;
	}
	
	fclose (fPointer);
	return false;
}

void InputManual()
{
	int arrayLength;
	printf ("Input Total Number: ");
	while (scanf ("%d", &arrayLength) == 0)
	{
		system ("cls");
		printf ("Inputan bukan merupakan angka!\n");
		printf ("Input Total Number: ");
		fflush(stdin);
	}
	
	if (arrayLength == 0)
	{
		printf ("Input sama dengan 0, tidak ada data yang akan di inputkan!\n");
		return;
	}

	system ("cls");
	
	int *dataMin = Array__Create (arrayLength);
	int *dataMax = Array__Duplicate (dataMin, arrayLength);
	
	printf ("===========================================================\n");
	
	printf("Given Data:\n");
	Array__Display (dataMin, arrayLength);
	printf ("\n");
	
	HeapSortMin (dataMin, arrayLength);
	printf("\nSorted Data (Min to Max):\n");
	Array__Display (dataMin, arrayLength);
	
	printf ("===========================================================\n");
	
	printf("Given Data:\n");
	Array__Display (dataMax, arrayLength);
	printf ("\n");
	
	HeapSortMax (dataMax, arrayLength);
	printf("\nSorted Data (Max to Min):\n");
	Array__Display (dataMax, arrayLength);
	
	printf ("===========================================================\n");
}

void SortingFile()
{
	if (isFileEmpty())
	{
		printf ("===========================================================\n");
		printf ("  Error! Tidak ada data dalam file!\n");
		printf ("  Silahkan masukan data dalam file terlebih dahulu!\n");
		printf ("===========================================================\n");
		return;
	}
	
	int arrayLength = getArrayLengthFile();
	int *dataMin = Array__CreateFile (arrayLength);
	int *dataMax = Array__Duplicate (dataMin, arrayLength);
	
	printf ("===========================================================\n");
	
	printf("Given Data:\n");
	Array__Display (dataMin, arrayLength);
	printf ("\n");
	
	HeapSortMin (dataMin, arrayLength);
	printf("\nSorted Data (Min to Max):\n");
	Array__Display (dataMin, arrayLength);
	WriteDataFileMin (dataMin, arrayLength);
	
	printf ("===========================================================\n");
	
	printf("Given Data:\n");
	Array__Display (dataMax, arrayLength);
	printf ("\n");
	
	HeapSortMax (dataMax, arrayLength);
	printf("\nSorted Data (Max to Min):\n");
	Array__Display (dataMax, arrayLength);
	WriteDataFileMax (dataMax, arrayLength);
	
	printf ("===========================================================\n");
}
