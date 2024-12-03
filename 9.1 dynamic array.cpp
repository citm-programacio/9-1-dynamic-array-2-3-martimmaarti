/*Write a program that asks for numbers from the user, one by one.
Every time a number is entered, it is added to an array. But the array must always keep the numbers in order.
    189 -> [189]
    59 -> [59,189]
    111 -> [59,111,189]
Print the complete array every time a new number is entered.
You must not declare a static array with arbitrary length!
Create a new dynamic array bigger every time, deleting the old one.*/

#include <iostream>
using namespace std;

// Function to insert a number into the array, keeping it sorted
int* insertSorted(int* array, int& size, int number) {
    // Create a new array with increased size
    int* newArray = new int[size + 1];

    int i = 0, j = 0;
    bool inserted = false;

    // Merge old array into new array while inserting the new number
    while (i < size) {
        if (!inserted && (j >= size || number < array[j])) {
            newArray[i++] = number;
            inserted = true;
        } else {
            newArray[i++] = array[j++];
        }
    }

    // Add the number at the end if it hasn't been inserted yet
    if (!inserted) {
        newArray[i] = number;
    }

    // Delete the old array
    delete[] array;

    // Update the size
    size++;

    return newArray;
}

int main() {
    int* array = nullptr; // Start with an empty dynamic array
    int size = 0;

    while (true) {
        int number;
        cout << "Enter a number (or -1 to stop): ";
        cin >> number;

        if (number == -1) {
            break; // Exit the loop
        }

        // Insert the new number into the array, keeping it sorted
        array = insertSorted(array, size, number);

        // Print the array
        cout << "Current array: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Clean up the memory before exiting
    delete[] array;

    return 0;
}
