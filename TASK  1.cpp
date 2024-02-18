//task 1


#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0)); 
    int number_to_guess = rand() % 100 + 1; 
    int guess;
    int num_tries=1;

    std::cout << "Guess a number between 1 and 100: ";
    while (std::cin >> guess) {
        if (guess < number_to_guess) {
            std::cout << "Too low! Try again: ";
            num_tries++;
        } else if (guess > number_to_guess) {
            std::cout << "Too high! Try again: ";
            num_tries++;
        } else {
            std::cout << "Congratulations! You guessed the number.\n";
            std::cout << "Number of Tries " << num_tries;
            break;
        }
    }

    return 0;
}



