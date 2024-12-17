#include <iostream>
#include <cstdarg> // For variadic functions
#include <limits>  // For numeric limits

// Function to compute the minimum of given positive numbers
unsigned int min(unsigned int first, ...) {
    // Ensure the first argument is positive
    if (first == 0) {
        throw std::invalid_argument("The first number cannot be 0.");
    }

    unsigned int minValue = first;

    // Initialize the variadic argument list
    va_list args;
    va_start(args, first);

    while (true) {
        unsigned int next = va_arg(args, unsigned int);

        if (next == 0) {
            break; // End of argument list
        }

        if (next < minValue) {
            minValue = next;
        }
    }

    va_end(args);
    return minValue;
}

// Test the min function
int main() {
    try {
        unsigned int result = min(10, 20, 5, 30, 15, 0);
        std::cout << "Minimum value: " << result << "\n";

        result = min(50, 40, 0);
        std::cout << "Minimum value: " << result << "\n";

        // Test with invalid input
        // unsigned int invalidResult = min(0); // Uncomment to test exception
        // std::cout << "Minimum value: " << invalidResult << "\n";

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    return 0;
}
