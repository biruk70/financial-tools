//**************************************************************************
// Flash Drive Price Calculation
// Programmer: Biruk Teklu
// Completed: 02/10/2025
// Status: Complete
//
// Did your program pass the testing? : Yes
// Did your program meet the requirements? : Yes
//
// This program calculates the selling price of a 64GB USB flash drive
// if a company wants to make a 35% profit on its production cost.
//
//**************************************************************************

#include <iostream>  // For input and output

using namespace std;

int main() {
    // Declare variables
    double cost = 8.00;          // Cost per flash drive
    double profit = cost * 0.35; // 35% profit amount
    double sellingPrice = cost + profit; // Total selling price

    // Output result
    cout << "To have a 35% profit, the flash drive should sell for $" << sellingPrice << endl;

    return 0;
}
