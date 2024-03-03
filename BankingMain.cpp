/*
Elong Mirco
CS 210
20240210
*/

#include <iostream>  
#include <limits> 
#include "Banking.h"  

// Use specific members from the std namespace to avoid namespace pollution
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;


void PrintHomeScreen(Banking& myInvestment);  // Prototype for PrintHomeScreen function
int validIntInput();  // Prototype for function to validate integer input
double validDoubleInput();  // Prototype for function to validate double input
void clearCin();  // Prototype for function to clear the input buffer

int main() {
    Banking myInvestment;  // Create an instance of Banking class
    char user_input = 'a';  // Variable to hold user's choice for continuing or quitting

    // Initial display of investment details before any user input
    myInvestment.DisplayInvestmentDetails();

    // Loop to keep the program running until the user decides to quit
    while (user_input != 'q' && user_input != 'Q') {
        PrintHomeScreen(myInvestment);  // Call to display the home screen and take user inputs

        // Prompt user for quitting or continuing
        cout << "\nPress 'q' to quit. Press any other key to run again: ";
        cin >> user_input;
        clearCin();  
    }

    return 0;  
}

// Function to display the home screen and take user inputs for investment details
void PrintHomeScreen(Banking& myInvestment) {
    cout << "\n## Data Input ##\n";  // Heading for the input section
    cout << "Initial Investment $: ";  // Prompt for initial investment
    myInvestment.SetInitialInvestment(validDoubleInput());  // Set initial investment in the Banking object

    cout << "Monthly Deposit $: ";  // Prompt for monthly deposit
    myInvestment.SetMonthlyDeposit(validDoubleInput());  // Set monthly deposit in the Banking object

    cout << "Annual Interest %: ";  // Prompt for annual interest rate
    myInvestment.SetInterestRate(validDoubleInput());  // Set annual interest rate in the Banking object

    cout << "Number of years: ";  // Prompt for number of years
    myInvestment.SetNumberOfYears(validIntInput());  // Set number of years in the Banking object

    // Call Banking class methods to calculate and display balances
    myInvestment.calcBalanceWithoutMonthlyDeposit();
    myInvestment.balanceWithMonthlyDeposit();
}

// Function to validate and return a positive integer input from the user
int validIntInput() {
    int value;
    while (!(cin >> value) || value < 0) {  // Loop until a valid positive integer is entered
        cout << "Invalid input. Enter a positive integer: ";  // Prompt for valid input
        clearCin();  // Clear the input buffer
    }
    return value;  // Return the validated input
}

// Function to validate and return a positive double input from the user
double validDoubleInput() {
    double value;
    while (!(cin >> value) || value < 0.0) {  // Loop until a valid positive double is entered
        cout << "Invalid input. Enter a positive number: ";  // Prompt for valid input
        clearCin();  // Clear the input buffer
    }
    return value;  // Return the validated input
}

// Function to clear the input buffer, ensuring clean reads for subsequent inputs
void clearCin() {
    cin.clear();  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
}
