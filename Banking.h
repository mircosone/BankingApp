/*
Elong Mirco
CS 210
20240210
*/

#ifndef BANKING_H  // Begin include guard to prevent multiple inclusions
#define BANKING_H

class Banking {  // Declaration of the Banking class
public:
    void SetInitialInvestment(double amount);  // Sets the initial amount invested
    void SetMonthlyDeposit(double amount);  // Sets the amount to be deposited monthly
    void SetInterestRate(double rate);  // Sets the annual interest rate in percentage
    void SetNumberOfYears(int years);  // Sets the investment duration in years

    // Display method to showcase investment details based on provided inputs
    void DisplayInvestmentDetails() const;  // Displays a summary of investment details

    // Calculation methods for investment growth
    void calcBalanceWithoutMonthlyDeposit() const;  // Calculates the balance without considering monthly deposits
    void balanceWithMonthlyDeposit() const;  // Calculates the balance including monthly deposits

private:
    // Private member variables to store investment details
    double initialInvestment = 0.0;  
    double monthlyDeposit = 0.0;  
    double annualInterest = 0.0;  
    int numberOfYears = 0;  
};

#endif  // End include guard


