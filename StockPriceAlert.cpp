//******************************************************************
// Real-Time Stock Price Alert System
// Programmer: Biruk Teklu
// Completed : 03/05/2025
// Status    : Complete
//
// Did your program pass the testing? : Yes
// If you answered "No", what testing did not pass?
// Did your program meet the requirements? : Yes
// If you answered "No", what requirements were not met?
//
// This program simulates stock price fluctuations and alerts the user
// when a specified price threshold is reached. It uses multithreading
// to continuously monitor price changes in real time.
//******************************************************************

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function Prototypes
double getStockPrice(double &currentPrice, double threshold);
void setStockAlert(string stockSymbol, double threshold, string user);

//******************************************************************
// Function: main
// Purpose : Collects user input and starts the stock monitoring thread.
//******************************************************************
int main() {
    string stockSymbol; // Holds the stock symbol entered by the user
    double threshold;   // Price threshold for alert
    string user;        // User name for personalized alert
    
    // Get user input for stock monitoring
    cout << "Enter stock symbol: ";
    cin >> stockSymbol;
    cout << "Enter price alert threshold: ";
    cin >> threshold;
    cout << "Enter username: ";
    cin >> user;
    
    // Start stock monitoring in a separate thread
    thread alertThread(setStockAlert, stockSymbol, threshold, user);
    alertThread.join();
    
    return 0;
}

//******************************************************************
// Function: getStockPrice
// Purpose : Simulates stock price fluctuations with an upward trend
//******************************************************************
double getStockPrice(double &currentPrice, double threshold) {
    double change;
    int bias = rand() % 100; // Random bias for upward trend
    
    if (bias < 65) { // 65% chance to go up
        change = (rand() % 200) / 100.0; // Increase by 0.00 to 2.00
    } else { // 35% chance to go down
        change = -(rand() % 100) / 100.0; // Decrease by 0.00 to 1.00
    }
    
    currentPrice += change;
    if (currentPrice < 1) currentPrice = 1; // Ensure price stays positive
    return currentPrice;
}

//******************************************************************
// Function: setStockAlert
// Purpose : Monitors stock price fluctuations and alerts the user
//           when the price reaches the defined threshold.
//******************************************************************
void setStockAlert(string stockSymbol, double threshold, string user) {
    srand(time(0)); // Seed random number generator
    double stockPrice = threshold - 20; // Start price further below threshold

    // Continuously check stock price until threshold is met
    while (true) {
        stockPrice = getStockPrice(stockPrice, threshold);
        cout << "Current price of " << stockSymbol << ": $" << stockPrice << endl;
        
        // Check if price reaches or exceeds threshold
        if (stockPrice >= threshold) {
            cout << "ALERT: " << user << " - " << stockSymbol << " price reached $" << threshold << "!" << endl;
            break;
        }
        
        this_thread::sleep_for(chrono::milliseconds(500)); // Update every 0.5 seconds
    }
}
