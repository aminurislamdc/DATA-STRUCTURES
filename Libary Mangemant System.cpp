#include <bits/stdc++.h> // Includes all standard libraries

using namespace std;

// Global variables to store book data
vector<int> books;
int comparisons = 0;
int shifts = 0;

// Function to display the current list of books
void printBooks(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Insertion Sort Function
void insertionSort() {
    int n = books.size();
    if (n == 0) {
        cout << "No books to sort! Please insert data first." << endl;
        return;
    }

    // Reset counters
    comparisons = 0;
    shifts = 0;

    cout << "\n--- Starting Insertion Sort ---" << endl;
    cout << "Initial List: ";
    printBooks(books);

    for (int i = 1; i < n; i++) {
        int key = books[i];
        int j = i - 1;

        // We track if we entered the loop to count the final failed comparison accurately
        bool loopEntered = false;

        // Move elements of books[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0) {
            comparisons++; // Count the comparison we are about to make
            if (books[j] > key) {
                books[j + 1] = books[j];
                shifts++; // Count the shift
                j = j - 1;
                loopEntered = true;
            } else {
                break; // Stop if we find an element smaller than key
            }
        }

        books[j + 1] = key;

        // Display the list after this pass
        cout << "After Pass " << i << " (Inserted " << key << "): ";
        printBooks(books);
    }

    cout << "\n--- Sorting Complete ---" << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Shifts: " << shifts << endl;
    cout << "Final Sorted List: ";
    printBooks(books);
}

// Function to handle Input
void inputBooks() {
    int n, pages;
    cout << "Enter the number of books: ";
    cin >> n;

    books.clear(); // Clear any previous data
    cout << "Enter the page number of books (" << n << " books): ";
    for (int i = 0; i < n; i++) {
        cin >> pages;
        books.push_back(pages);
    }
    cout << "Data inserted successfully!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n=== Library Management System ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputBooks();
                break;
            case 2:
                // We run the sort when the user asks to Display,
                // as per the requirement to show passes/counts.
                insertionSort();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
