//******************************************************************
// Movie Data Program - Enhanced Version
// Programmer: Biruk Teklu
// Completed: 4/21/2025
// Status: Complete

// This program collects and sorts movie-watching data from students,
// then calculates and displays the average, median, and mode.
//******************************************************************

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

// Function prototypes
void getMovieData(vector<int>& arr);
void sortData(vector<int>& arr);
void displayData(const vector<int>& arr);
double calculateAverage(const vector<int>& arr);
double calculateMedian(const vector<int>& arr);
int calculateMode(const vector<int>& arr);
void saveToFile(const vector<int>& arr, double average, double median, int mode);

int main() {
    vector<int> moviesWatched;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter Movie Data\n";
        cout << "2. Display Sorted Data\n";
        cout << "3. Save Results to File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                getMovieData(moviesWatched);
                break;
            case 2:
                sortData(moviesWatched);
                cout << "\nSorted Movies Watched:\n";
                displayData(moviesWatched);
                cout << "Average: " << calculateAverage(moviesWatched) << endl;
                cout << "Median: " << calculateMedian(moviesWatched) << endl;
                cout << "Mode: " << calculateMode(moviesWatched) << endl;
                break;
            case 3:
                sortData(moviesWatched);
                saveToFile(moviesWatched, calculateAverage(moviesWatched), calculateMedian(moviesWatched), calculateMode(moviesWatched));
                cout << "Data saved to file successfully.\n";
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void getMovieData(vector<int>& arr) {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    arr.clear();
    for (int i = 0; i < numStudents; i++) {
        int movies;
        do {
            cout << "Enter number of movies student " << (i + 1) << " watched: ";
            cin >> movies;
            if (movies < 0) cout << "Please enter a non-negative number.\n";
        } while (movies < 0);
        arr.push_back(movies);
    }
}

void sortData(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

void displayData(const vector<int>& arr) {
    cout << left << setw(10) << "Student" << "Movies Watched" << endl;
    cout << "-----------------------------\n";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << left << setw(10) << (i + 1) << arr[i] << endl;
    }
}

double calculateAverage(const vector<int>& arr) {
    int sum = 0;
    for (int val : arr) {
        sum += val;
    }
    return arr.empty() ? 0.0 : static_cast<double>(sum) / arr.size();
}

double calculateMedian(const vector<int>& arr) {
    if (arr.empty()) return 0.0;
    int size = arr.size();
    if (size % 2 == 0)
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    else
        return arr[size / 2];
}

int calculateMode(const vector<int>& arr) {
    if (arr.empty()) return 0;
    int mode = arr[0];
    int maxCount = 1, count = 1;
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
            if (count > maxCount) {
                maxCount = count;
                mode = arr[i];
            }
        } else {
            count = 1;
        }
    }
    return mode;
}

void saveToFile(const vector<int>& arr, double average, double median, int mode) {
    ofstream outFile("movies_data.txt");
    outFile << "Student\tMovies Watched\n";
    for (size_t i = 0; i < arr.size(); i++) {
        outFile << (i + 1) << "\t" << arr[i] << "\n";
    }
    outFile << "\nAverage: " << average << "\n";
    outFile << "Median: " << median << "\n";
    outFile << "Mode: " << mode << endl;
    outFile.close();
}