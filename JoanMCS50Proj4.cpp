// main.cpp
//
// Mariam Joan
// Project 4
// Program to print principal, interest rate and loan period
// Due: July 19, 2020
//

#include <iostream>
#include <math.h>

int main() {

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
    void printFinalStatement(float a, float b, float c, float d, float e);
    
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
    printFinalStatement(balance, monthlyIntRate, monthlyPayment, interest, deductions);
}

// create function to return monthly payment
float calculateMonthlyPayment(float p, float m, int n) {
    // principal * monthly interest rate / pow(monthly interest rate num months)
    return (p * m) / (1.0 - 1.0 / pow(1 + m, n));
}

// create void function to print out final loan statement
void printFinalStatement(float b, float m, float p, float i, float d) {
    for (int num=1; num<=24; num++ ) {
        // amount of loan used for interest
        i = b * m;
        // amount of loan reduces balance
        d = p - i;
        // adjusted balance
        b -= d;
        // print final statement
        printf("%4d      %8.2f      %8.2f     %8.2f\n", num, i, d, b);
    }
}
