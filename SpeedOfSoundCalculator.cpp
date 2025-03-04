//******************************************************************
// Speed of Sound Calculator
// Programmer: Biru Teklu
// Completed : 24 February 2025
// Status : Complete

// Did your program pass the testing? : Yes
// If you answered "No", what testing did not pass?
// Did your program meet the requirements? : Yes
// If you answered "No", what requirements were not met?
//
// This program calculates the time it takes for a sound wave 
// to travel a given distance through a selected medium: air, 
// water, or steel. The user selects a medium and enters a 
// distance in feet, and the program computes and displays the 
// time in seconds.
//******************************************************************

#include <iostream>   // For input and output operations
#include <iomanip>    // For formatting output

using namespace std;

// Function prototype
void displayMenu(); // Displays the selection menu

int main() {
    // Named constants for speed of sound in different mediums
    const double SPEED_AIR = 1100.0;   // Speed in feet per second in air
    const double SPEED_WATER = 4900.0; // Speed in feet per second in water
    const double SPEED_STEEL = 16400.0; // Speed in feet per second in steel
    
    int choice;    // User's menu selection
    double distance, time; // Distance to travel and calculated time

    // Display the menu
    displayMenu();
    cin >> choice;

    // Validate user input
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice. Program will terminate.\n";
        return 1; // Exit program if invalid choice is made
    }

    // Prompt user for distance
    cout << "\nEnter the number of feet the sound wave will travel: ";
    cin >> distance;

    // Calculate time based on user's choice
    if (choice == 1) {
        time = distance / SPEED_AIR;
        cout << "The sound wave will travel " << distance << " feet through air in ";
    } 
    else if (choice == 2) {
        time = distance / SPEED_WATER;
        cout << "The sound wave will travel " << distance << " feet through water in ";
    } 
    else {
        time = distance / SPEED_STEEL;
        cout << "The sound wave will travel " << distance << " feet through steel in ";
    }

    // Display result with four decimal places
    cout << fixed << setprecision(4) << time << " seconds.\n";

    return 0;
}

// Function: displayMenu
//
// Purpose: Displays the menu options for selecting a medium
void displayMenu() {
    cout << "This program will tell you how long it takes a sound wave\n"
         << "to travel a specific distance through a particular medium.\n\n";
    
    cout << "Select a substance for the sound to travel through:\n"
         << "1. Air\n"
         << "2. Water\n"
         << "3. Steel\n"
         << "Enter your choice: ";
}
