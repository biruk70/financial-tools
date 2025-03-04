//******************************************************************
// Property Tax Calculation Program
// Programmer: Biruk Teklu
// Completed: 02/17/2025
// Status: Complete

// Did your program pass the testing? : Yes
// If you answered "No", what testing did not pass?
// Did your program meet the requirements? : Yes
// If you answered "No", what requirements were not met?

// This program calculates the assessed value of a property and the
// property tax based on user input for actual property value and 
// tax rate per $100 of assessed value.
//******************************************************************

#include <iostream>  // For input and output operations
#include <iomanip>   // For setprecision and fixed
using namespace std;

int main() {
    // Variable declarations
    double actualValue;   // Actual property value entered by user
    double assessedValue; // Assessed value, which is 60% of actual value
    double taxRate;       // Tax rate per $100 of assessed value
    double propertyTax;   // Calculated property tax

    // Prompt user for actual property value
    cout << "Enter the actual property value: $ ";
    cin >> actualValue;

    // Prompt user for tax rate per $100 of assessed value
    cout << "Enter the amount of tax per $100 of assessed value: $";
    cin >> taxRate;

    // Calculate assessed value (60% of actual value)
    assessedValue = actualValue * 0.60;

    // Calculate property tax using the formula:
    // property tax = (assessed value / 100) * tax rate
    propertyTax = (assessedValue / 100) * taxRate;
 
    // Ensure output displays exactly 2 decimal places
    cout << fixed << setprecision(2);

    // Display results
    cout << "\nProperty Value:   $ " << actualValue << endl;
    cout << "Assessed Value:   $ " << assessedValue << endl;
    cout << "Property Tax:     $ " << propertyTax << endl;

    return 0;
}
