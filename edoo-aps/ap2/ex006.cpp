#include <iostream>
#include <stdlib.h> // Prototypes of srand() and rand()
#include <time.h>   // Prototype of time()

int main() {
    char playAgain;
    do {
        // Seed the random number generator with the current time
        long long sec;
        time(&sec);
        srand((unsigned)sec);

        // Generate a random number between 1 and 15
        int randomNumber = (rand() % 15) + 1;
        int attempts = 3; // Total attempts allowed
        bool guessedCorrectly = false;

        std::cout << "I have chosen a number between 1 and 15. You have 3 attempts to guess it!\n";

        for (int i = 1; i <= attempts; ++i) {
            int guess;
            std::cout << "Attempt " << i << ": Enter your guess: ";
            std::cin >> guess;

            if (guess == randomNumber) {
                std::cout << "Congratulations! You guessed the number!\n";
                guessedCorrectly = true;
                break;
            } else if (guess < randomNumber) {
                std::cout << "Too low!\n";
            } else {
                std::cout << "Too high!\n";
            }
        }

        if (!guessedCorrectly) {
            std::cout << "Sorry, you used all your attempts. The number was: " << randomNumber << "\n";
        }

        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing! Goodbye!\n";
    return 0;
}
