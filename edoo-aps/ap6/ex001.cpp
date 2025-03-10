#include <iostream>
#include <stdexcept>

// Function to splice two arrays
int* splice(const int* arr1, int len1, const int* arr2, int len2, int position) {
    // Validate the position
    if (position < 0 || position > len1) {
        throw std::out_of_range("Position out of range.");
    }

    // Allocate memory for the new array
    int* result = new int[len1 + len2];

    // Copy elements from the first array up to the position
    for (int i = 0; i < position; ++i) {
        result[i] = arr1[i];
    }

    // Copy elements from the second array
    for (int i = 0; i < len2; ++i) {
        result[position + i] = arr2[i];
    }

    // Copy the remaining elements from the first array
    for (int i = position; i < len1; ++i) {
        result[len2 + i] = arr1[i];
    }

    return result;
}

// Test the splice function
int main() {
    try {
        int arr1[] = {1, 2, 3, 4, 5};
        int arr2[] = {10, 20, 30};

        int len1 = sizeof(arr1) / sizeof(arr1[0]);
        int len2 = sizeof(arr2) / sizeof(arr2[0]);

        int position = 2;

        // Call splice function
        int* splicedArray = splice(arr1, len1, arr2, len2, position);

        // Output the resulting array
        std::cout << "Spliced array: ";
        for (int i = 0; i < len1 + len2; ++i) {
            std::cout << splicedArray[i] << " ";
        }
        std::cout << "\n";

        // Free allocated memory
        delete[] splicedArray;

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    return 0;
}
