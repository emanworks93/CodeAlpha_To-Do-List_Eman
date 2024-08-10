//
//  main.cpp
//  CSC102-OOP1
//
//  Created by MAC BOOK on 14/03/2024.
//  Copyright © 2024 MAC BOOK. All rights reserved.
//


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
public:
    int id;
    string description;
    bool isDone;
    
    Task(int id, string desc) : id(id), description(desc), isDone(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;
    int nextId;
    
public:
    ToDoList() : nextId(1) {}
    
    void addTask(const string &description) {
        tasks.push_back(Task(nextId++, description));
        cout << "\nTask added successfully.\n";
    }
    
    void viewTasks() const {
        if (tasks.empty()) {
            cout << "\nNo tasks available.\n";
            return;
        }
        for (const auto &task : tasks) {
            cout << (task.isDone ? " [✔]  " : " [ ]  ") << task.id << ". " << task.description << "\n";
        }
    }
    
    void markTaskAsDone(int id) {
        for (auto &task : tasks) {
            if (task.id == id) {
                task.isDone = true;
                cout << "\nTask marked as done.\n";
                return;
            }
        }
        cout << "\nTask not found.\n";
    }
    
    void deleteTask(int id) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->id == id) {
                tasks.erase(it);
                cout << "\nTask deleted successfully.\n";
                return;
            }
        }
        cout << "\nTask not found.\n";
    }
};

void showMenu() {
    cout << "\n\nTo-Do List Menu:\n";
    cout << " 1. Add Task\n";
    cout << " 2. View Tasks\n";
    cout << " 3. Mark Task as Done\n";
    cout << " 4. Delete Task\n";
    cout << " 5. Exit\n";
    cout << "\nEnter your choice: ";
}

int main() {
    ToDoList toDoList;
    int choice;
    
    while (true) {
        showMenu();
        cin >> choice;
        
        if (choice == 1) {
            string description;
            cin.ignore(); // Ignore the newline left in the buffer
            cout << "\nEnter task description: ";
            getline(cin, description);
            toDoList.addTask(description);
        } else if (choice == 2) {
            toDoList.viewTasks();
        } else if (choice == 3) {
            int id;
            cout << "\nEnter task number to mark as done: ";
            cin >> id;
            toDoList.markTaskAsDone(id);
        } else if (choice == 4) {
            int id;
            cout << "\nEnter task number to delete: ";
            cin >> id;
            toDoList.deleteTask(id);
        } else if (choice == 5) {
            cout << "\nExiting...\n";
            break;
        } else {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
    return 0;
}
