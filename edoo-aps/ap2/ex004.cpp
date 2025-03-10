#include <iostream>
#include <iomanip> // For std::setw to format output

int main() {
    const int size = 10; // Size of the multiplication table

    // Print the header row
    std::cout << std::setw(4) << ""; // Leading space for alignment
    for (int i = 1; i <= size; ++i) {
        std::cout << std::setw(4) << i;
    }
    std::cout << std::endl;

    // Print the multiplication table
    for (int i = 1; i <= size; ++i) {
        std::cout << std::setw(4) << i; // Row header
        for (int j = 1; j <= size; ++j) {
            std::cout << std::setw(4) << i * j;
        }
        std::cout << std::endl;
    }

    return 0;
}
