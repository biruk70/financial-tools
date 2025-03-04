//**************************************************************************
// Basketball Player Height Conversion
// Programmer: Biruk Teklu
// Completed: 02/10/2025
// Status: Complete
//
// Did your program pass the testing? : Yes
// Did your program meet the requirements? : Yes
//
// This program converts a basketball player's height from inches
// into feet and inches format.
//
//**************************************************************************

#include <iostream>  // For input and output

using namespace std;

int main() {
    // Declare variables
    int totalInches = 75;        // Total height in inches
    int feet = totalInches / 12; // Convert inches to feet
    int inches = totalInches % 12; // Remaining inches after conversion

    // Output result
    cout << "A 75 inch tall basketball player is " << feet << " feet " << inches << " inches tall." << endl;

    return 0;
}
