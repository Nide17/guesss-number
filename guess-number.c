/*
 * guess-number.c
 *
 * Determines the number that has been picked by the user by guessing numbers and then asking the user whether the answer is higher or lower than the guess
 *
 * Author: Parmenide <parmenin@andrew.cmu.edu>
 */

#include <stdio.h>
#define GUESS_RANGE 100

int main()
{
    int low = 1;
    int high = GUESS_RANGE;
    int current_guess = GUESS_RANGE / 2;
    char response;
    int guess_count = 0;

    while (response != '=')
    {
        printf("I guess %d.\nIf the answer is HIGHER than my guess, enter 'H'.\nIf the answer is LOWER than my guess, enter 'L'.\nIf my guess is correct, enter '='.\n", current_guess);
        guess_count++;

        // CHECK IF GUESS COUNT DOES NOT EXCEED 7 ATTEMPTS
        if (guess_count > 7)
        {
            printf("You ran out of allowed 7 attempts!\n");
        }

        printf("Response: ");
        scanf(" %c", &response);

        // CHECKING FOR INCONSISTENT ANSWERS
        if ((response == 'L' && current_guess <= low) || (response == 'H' && current_guess >= high))
        {
            printf("Is it possible you answered the questions inconsistently?\n");
            break;
        }

        if (response == 'L')
        {
            high = current_guess - 1;
            current_guess = low + ((high - low) / 2);
        }
        else if (response == 'H')
        {
            low = current_guess + 1;
            current_guess = low + ((high - low) / 2);
        }
        else if (response == '=')
        {
            printf("Got the right number with %d guesses!\n", guess_count);
        }
        else
        {
            printf("Invalid entry '%c'. Please enter H, L, or =\n", response);
        }
    }
    return 0;
}
