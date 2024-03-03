/*
Elong Mirco
CS 210
20240210
*/

#include "Banking.h"  
#include <iostream>  
#include <iomanip>  

// Use specific elements from the std namespace to avoid namespace pollution
using std::cout;
using std::endl;
using std::fixed;
using std::left;
using std::setprecision;
using std::setw;

// Sets the initial investment amount
void Banking::SetInitialInvestment(double value) { initialInvestment = value; }

// Sets the monthly deposit amount
void Banking::SetMonthlyDeposit(double value) { monthlyDeposit = value; }

// Sets the annual interest rate
void Banking::SetInterestRate(double value) { annualInterest = value; }

// Sets the number of years for the investment
void Banking::SetNumberOfYears(int value) { numberOfYears = value; }

// Displays the investment details by calling the calculation methods
void Banking::DisplayInvestmentDetails() const {
    calcBalanceWithoutMonthlyDeposit();  // Calculate and display balance without monthly deposits
    balanceWithMonthlyDeposit();  // Calculate and display balance with monthly deposits
}

// Calculates and displays the balance without considering monthly deposits
void Banking::calcBalanceWithoutMonthlyDeposit() const {
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << std::string(70, '-') << endl;  
    cout << setw(10) << "Year" << setw(20) << "End of Year Balance" << setw(30) << "Year End Earned Interest" << endl;
    cout << std::string(70, '-') << endl;  

    double totalAmount = initialInvestment;  // Initialize total amount with the initial investment
    // Loop over each year to calculate interest and total amount
    for (int i = 1; i <= numberOfYears; ++i) {
        double interestAmount = totalAmount * (annualInterest / 100);  // Calculate the interest for the year
        totalAmount += interestAmount;  // Add the interest to the total amount
        // Display the year, total amount, and interest amount
        cout << setw(10) << i << setw(20) << fixed << setprecision(2) << totalAmount << setw(30) << interestAmount << endl;
    }
}

// Calculates and displays the balance considering monthly deposits
void Banking::balanceWithMonthlyDeposit() const {
    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << std::string(60, '-') << endl;  
    cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
    cout << std::string(60, '-') << endl;  

    double totalAmount = initialInvestment;  // Initialize total amount with the initial investment
    for (int i = 1; i <= numberOfYears; ++i) {
        double yearlyInterestTotal = 0;  // Initialize yearly interest total
        // Loop over each month
        for (int j = 0; j < 12; ++j) {
            double monthlyInterest = (totalAmount + monthlyDeposit) * (annualInterest / 100 / 12);  // Calculate monthly interest
            yearlyInterestTotal += monthlyInterest;  // Add monthly interest to yearly total
            totalAmount += monthlyDeposit + monthlyInterest;  // Update total amount with deposit and interest
        }
        // Display the year, total amount, and yearly interest total
        cout << setw(10) << i << setw(20) << fixed << setprecision(2) << totalAmount << setw(30) << yearlyInterestTotal << endl;
    }
}
