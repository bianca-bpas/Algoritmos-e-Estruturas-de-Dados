#include <iostream>
#include <random> // For random number generation

int main() {
    // Prompt the user for a seed value
    std::cout << "Enter an integer between 0 and 65535 to seed the random number generator: ";
    unsigned int seed;
    std::cin >> seed;

    // Validate the seed input
    if (seed > 65535) {
        std::cout << "Error: The number must be between 0 and 65535." << std::endl;
        return 1;
    }

    // Seed the random number generator
    std::mt19937 generator(seed); // Mersenne Twister random number generator
    std::uniform_int_distribution<int> distribution(1, 100); // Range: 1 to 100

    // Generate and display 20 random numbers
    std::cout << "20 random numbers between 1 and 100:" << std::endl;
    for (int i = 0; i < 20; ++i) {
        std::cout << distribution(generator) << " ";
    }
    std::cout << std::endl;

    return 0;
}
