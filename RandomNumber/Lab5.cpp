#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    int wins = 0;
    int losses = 0;

    do {
        // Generate a random number between 0 and 100
        int secretNumber = rand() % 101;

        int guess;
        int attempts = 0;
        const int maxAttempts = 20;

        cout << "Welcome to the Number Guessing Game!\n";
        cout << "I have selected a random number between 0 and 100.\n";
        cout << "Try to guess it in less than 20 attempts.\n\n";

        do {
            cout << "Enter your guess: ";
            cin >> guess;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a valid number.\n";
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue; // Skip the rest of the loop
            }

            attempts++;

            if (guess == secretNumber) {
                // Winning messages
                switch (rand() % 10) {
                case 0:
                    cout << "Congratulations! You're a mind reader!\n";
                    break;
                case 1:
                    cout << "Wow! You got it! Are you psychic?\n";
                    break;
                    // Add more winning messages as needed
                default:
                    cout << "You nailed it! Great job!\n";
                }
                wins++;
                break;
            }
            else if (guess < secretNumber) {
                cout << "Too low! Try again.\n";
            }
            else {
                cout << "Too high! Try again.\n";
            }

            if (attempts == maxAttempts) {
                // Losing messages
                switch (rand() % 10) {
                case 0:
                    cout << "Sorry, you've run out of attempts. Better luck next time!\n";
                    break;
                case 1:
                    cout << "Time's up! The correct number was " << secretNumber << ". You can do better!\n";
                    break;
                default:
                    cout << "You gave it a good try, but the correct number was " << secretNumber << ".\n";
                }
                losses++;
                break;
            }

            cout << "Remaining attempts: " << maxAttempts - attempts << "\n\n";

        } while (true);

        // Ask if the user wants to play again
        cout << "Do you want to play again? (1 for Yes, 0 for No): ";
        int playAgain;
        cin >> playAgain;

        if (playAgain != 1) {
            break;
        }

    } while (true);

    // Display total wins and losses
    cout << "Thanks for playing!\n";
    cout << "Total Wins: " << wins << "\n";
    cout << "Total Losses: " << losses << "\n";

    return 0;
}
