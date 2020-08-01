// JoanMCS50Proj4.cpp
//
// Mariam Joan
// Project 4
// Program to print principal, interest rate and loan period
// Due: July 19, 2020
//

#include <iostream>
#include <math.h>

int main()
{

    // declare variables data types
    float principal;
    float annualIntRate;
    float monthlyIntRate;

    int numberYears;
    int numberMonths;

    float monthlyPayment;
    float totalPayment;
    float interest = 0.0;
    float deductions = 0.0;
    float balance;
    
    float calculateMonthlyPayment(float x, float y, int z);
    // include pointers in function prototype
    void printFinalStatement(float *a, float b, float c, float p, float *d, float *e);
    

    // prompt and read loan components
    printf("\nEnter principal, annual interest rate and loan period, in years: ");
    scanf("%f %f %d", &principal, &annualIntRate, &numberYears);
    
    // calculate monthly and total payment
    monthlyIntRate = annualIntRate  / 1200;
    numberMonths = numberYears * 12;
    
    // use one value returning function
    monthlyPayment = calculateMonthlyPayment(principal, monthlyIntRate, numberMonths);
        
    // calculate total payment
    totalPayment = monthlyPayment * numberMonths;
    
    // print out results
    printf("\n");
    printf("Principal = %.2f\n", principal);
    printf("Annual Interest Rate = %.2f\n", annualIntRate);
    printf("Years of Loan = %d\n", numberYears);
    printf("Monthly Payment = %.2f\n", monthlyPayment);
    printf("Total Payment = %.2f\n", totalPayment);
    printf("\n");
    
    // calculate loan balance for 24 months
    printf("Month    To Interest   To Principal   Balance\n");
    printf("---------------------------------------------\n");
    
    // original balance entire loan
    balance = principal;
    for (int num=1; num<=24; num++ ) {
        // using a for loop pass pointer address & to function for new values
        printFinalStatement(&balance, monthlyIntRate, monthlyPayment, principal, &interest, &deductions);
        // print new values from pointer address
        printf("%4d      %8.2f      %8.2f     %8.2f\n", num, interest, deductions, balance);
    }
}

// create function to return monthly payment
float calculateMonthlyPayment(float p, float m, int n)
{
    // principal * monthly interest rate / pow(monthly interest rate num months)
    return (p * m) / (1.0 - 1.0 / pow(1 + m, n));
}

// create void function to print out final loan statement with pointers
void printFinalStatement(float *balance, float monthlyIntRate, float monthlyPayment,
                         float principal, float *interest, float *deductions)
{
    // amount of loan used for interest
    *interest = *balance * monthlyIntRate;
    // amount of loan reduces balance
    *deductions = monthlyPayment - *interest;
    // adjusted balance
    *balance -= *deductions;
    // print final statement
}
