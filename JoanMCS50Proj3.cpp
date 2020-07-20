//
// main.cpp
//
// Mariam Joan
// Project 3
// Program to read in numbers, and find min, max, count, total, and average, enter 0 to exit
// Due: July 10, 2020
// Copyright © 2020 Mariam Joan. All rights reserved.

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(void)
{
    // declare variables
    int num=0;
   
    int count=0;
    int total=0;
    
    int min=0;
    int max=0;
    float avg=0;
    
    // prompt user to enter number and read number with scanf
    printf("Enter a number (enter 0 to stop): ");
    scanf("%d", &num);
    
    // set min and max to current num
    min=num;
    max=num;
    
    // initialize while loop
    while (num!=0)
    {

        // add num to total
        total+=num;
        // increment count
        count++;
        
        // if new num is < than current min then assign it new min
        if (num<min)
            min=num;
        
        // if new num is > than current max then assign it new max
        if (num>max)
            max=num;
        
        // then prompt user and read next num
        printf("Enter a number (enter 0 to stop): ");
        scanf("%d", &num);
    }
    
    // print new line
    printf("\n");
        
    if (count==0)
        printf("No number is read\n");
    else
    {
        // assign avg to total/count cast as type float
        avg=(float)total/count;
        
        // print accumulated count
        printf("Count of input numbers: %d\n", count);
        
        // if no new num is read, max is current num
        if (max==0)
            printf("No number is read\n");
        else
            printf("Maximum is: %d\n", max);

        // if no new num is read, min is current num
        if (min==0)
            printf("No number is read\n");
        else
            printf("Minimum is: %d\n", min);
        
        // if no num is read print total
        if (total==0)
            printf("No number is read\n");
        else
            printf("Total is: %d\n", total);
        
        // print average
        printf("Average is: %6.2f\n", avg);
    }
}
           

