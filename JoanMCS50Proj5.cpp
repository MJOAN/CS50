// JoanMCS50Proj5.cpp
//
// Mariam Joan
// Project 5
// Program to print array functions (min, max, sorting, searching, median, average)
// Due: July 28, 2020
//

#include <iostream>
#include <time.h>

#define ARRAY_SIZE 10
#define UPPER_LIMIT 20
#define LOWER_LIMIT 80
#define FALSE 0
#define TRUE 1

/* void function prototype */
void randomizeArray (int[], int, int, int);
void printArray (int[], int, int);
void bubbleSort (int[], int);

/* int function prototype */
int findMax (int[], int);
int findMin (int[], int);
int seqSearch (int[], int, int);

/* float function prototype */
float median (int[], int);
float average (int[], int);

int main()
{
    printf("\nProject 5\n\n");
    int samples[ARRAY_SIZE];
 
    /* call srand to seed random nums */
    srand(time_t(0));
    
    /* randomize array and print */
    randomizeArray(samples, ARRAY_SIZE, LOWER_LIMIT, UPPER_LIMIT);
    printf("Array size: %d, Array Element: \n", ARRAY_SIZE);
    printArray(samples, 0, ARRAY_SIZE);
    
    /* find max, min, average, and print */
    printf("\nMaximum: %d", findMax (samples, ARRAY_SIZE));
    printf("\nMinimum: %d", findMin (samples, ARRAY_SIZE));
    printf("\nAverage: %6.2f", average (samples, ARRAY_SIZE));
    
    /* get a random number and search for it linearly */
    int searchElement = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
    int searchIndex = seqSearch(samples,  ARRAY_SIZE, searchElement);
     
    if (searchIndex >=0 )
        printf("\nItem: %d was found at index %d\n", searchElement, searchIndex);
    else
        printf("\nItem: %d was not found\n", searchElement);
     
    /* get a random number and search for in quadratic time */
    printf("\nSorting: \n");
    bubbleSort(samples, ARRAY_SIZE);

    /* find median */
    printf("\nMedian: %6.2f\n", median(samples, ARRAY_SIZE));
}

void randomizeArray(int samples[], int arraySize, int lowLim, int upLim)
{
    for (int i = 0; i < arraySize; i++) {
        samples[i] = rand() % (upLim + lowLim) + lowLim;
        printf(" %d ", samples[i]);
    }
}

void printArray(int samples[], int fromElem, int toElem)
{
    for (int i = fromElem; i < toElem; i++)
        printf(" %d ", samples[i]);
    printf("\n");
        
}

int findMax(int samples[], int arraySize)
{
    /* set maximum to first element in array  */
    int max = samples[0];
    for (int i = 0; i < arraySize; i++)
        /* if max is < array element set that to new max */
        if (max < samples[i])
            max = samples[i];
    return max;
}

int findMin(int samples[], int arraySize)
{
    /* set minimum to first element in array  */
    int min = samples[0];
    for (int i = 0; i < arraySize; i++)
        /* if min is > array element set that to new min */
        if (min > samples[i])
            min = samples[i];
    return min;
}

float average(int samples[], int arraySize)
{
    int sum = 0;
    for (int i = 0; i < arraySize; i++)
        /* add each array element on each loop iteration */
        sum += samples[i];
    
    /* divide sum by array size for average  */
    int average = sum / arraySize;
    return average;
}

int seqSearch(int samples[], int arraySize, int searchItem)
{
    int searchIndex = 0;
    /* iterate over array */
    for (int i = 0; i < arraySize; i++)
        /* if search item == array element return index */
        if (searchItem == samples[i])
            searchIndex = i;
    return searchIndex;
}

void bubbleSort(int samples[], int arraySize)
{
    /* set sorted to false */
    int sorted = FALSE;
    while (!sorted)
    {
        sorted = TRUE;
        
        /* iterate over unsorted array */
        for (int i = 0; i < arraySize - 1; i++)
        {
            /* if index i value is > index i + 1 then swap values using temp var */
            if (samples[i]  > samples[i+ 1])
            {
                int temp = samples[i];
                samples[i] = samples[i+1];
                samples[i+1] = temp;
                sorted = FALSE;
            }
        }
        /* print sorted array  */
        for (int i = 0; i < arraySize; i++)
            printf(" %d ", samples[i]);
        printf("\n");
    }
}

float median(int samples[], int arraySize)
{
    int median;
    /* check array size is even int */
    if (arraySize % 2 != 0)
        /* if array size is even divide by 2 as new index == median */
        median = samples[arraySize / 2];
    else
        /* else divide by 2 - 1 as new index + divide by 2 index, overall divide by 2 */
        median = (samples[arraySize / 2 - 1] + samples[arraySize / 2]) / 2;
    return median;
}



