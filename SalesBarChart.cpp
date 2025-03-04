//******************************************************************
// Sales Bar Chart Program
// Programmer: Biruk Teklu
// Completed : March 3, 2025
// Status : Complete

// Did your program pass the testing? : Yes
// If you answered "No", what testing did not pass?
// Did your program meet the requirements? : Yes
// If you answered "No", what requirements were not met?
//
// This program takes sales input for three stores, validates the input, 
// rounds sales to the nearest $100, and displays a bar chart using 
// asterisks where each represents $100 of sales.
//******************************************************************

#include <iostream>  // For input and output

using namespace std;

// Function prototype
void displayBarChart(int sales1, int sales2, int sales3);

int main() {
    int sales1, sales2, sales3;  // Sales input for three stores

    // Prompt user for input and validate sales for Store 1
    do {
        cout << "Enter today's sales for store 1: ";
        cin >> sales1;
        if (sales1 < 0) {
            cout << "Error: Sales must be a non-negative value.\n";
        }
    } while (sales1 < 0);

    // Prompt user for input and validate sales for Store 2
    do {
        cout << "Enter today's sales for store 2: ";
        cin >> sales2;
        if (sales2 < 0) {
            cout << "Error: Sales must be a non-negative value.\n";
        }
    } while (sales2 < 0);

    // Prompt user for input and validate sales for Store 3
    do {
        cout << "Enter today's sales for store 3: ";
        cin >> sales3;
        if (sales3 < 0) {
            cout << "Error: Sales must be a non-negative value.\n";
        }
    } while (sales3 < 0);

    // Call function to display the bar chart
    displayBarChart(sales1, sales2, sales3);

    return 0;
}

// Function to display the bar chart using asterisks
void displayBarChart(int sales1, int sales2, int sales3) {
    // Convert sales to number of asterisks (each $100 -> 1 asterisk)
    int stars1 = (sales1 + 50) / 100;  // Rounds to the nearest 100
    int stars2 = (sales2 + 50) / 100;
    int stars3 = (sales3 + 50) / 100;

    // Print the sales bar chart
    cout << "\nSALES BAR CHART\n";
    cout << "Each * = $100\n\n";

    cout << "Store 1: ";
    for (int i = 0; i < stars1; i++) {
        cout << "*";
    }
    cout << endl;

    cout << "Store 2: ";
    for (int i = 0; i < stars2; i++) {
        cout << "*";
    }
    cout << endl;

    cout << "Store 3: ";
    for (int i = 0; i < stars3; i++) {
        cout << "*";
    }
    cout << endl;
}
