//******************************************************************
// Program Name: To-Do List Application
// Programmer: Biruk Teklu
// Completed: 02/17/2025
// Status: Complete
//
// Did your program pass the testing? : Yes
// If you answered "No", what testing did not pass?
// Did your program meet the requirements? : Yes
// If you answered "No", what requirements were not met?
//
// Description:
// This program allows users to create, view, and delete tasks
// in a simple to-do list. Users can interact with a menu system
// to manage their tasks.
//
//******************************************************************
 
 #include <iostream>
#include <vector>

using namespace std;

vector<string> tasks;

void addTask();
void viewTasks();
void deleteTask();

int main() {
    int choice;
    
    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline

        switch(choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}

void addTask() {
    string newTask;
    cout << "Enter a new task: ";
    getline(cin, newTask);
    tasks.push_back(newTask);
    cout << "Task added!\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }
    cout << "\nYour To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask() {
    viewTasks();
    if (tasks.empty()) return;
    
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    cin.ignore();
    
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}
