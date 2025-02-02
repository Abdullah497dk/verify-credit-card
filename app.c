#include <cs50.h>
#include <stdio.h>

bool check_luhn(long long number);
int get_digit_count(long long number);
int get_first_digits(long long number, int digit_count);

int main()
{
    // Get credit card number from user
    long long card_number = get_long("Enter your credit card number: ");

    // Check if the number is valid using Luhn's Algorithm
    if (!check_luhn(card_number))
    {
        printf("INVALID\n");
        return 0;
    }

    // Get the number of digits in the card number
    int digit_count = get_digit_count(card_number);

    // Extract the first two digits for validation
    int first_digits = get_first_digits(card_number, digit_count);
    int first_digit = first_digits / 10; // First digit only

    // Check for AMEX
    if (digit_count == 15 && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX\n");
    }
    // Check for MASTERCARD
    else if (digit_count == 16 && (first_digits >= 51 && first_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    // Check for VISA
    else if ((digit_count == 13 || digit_count == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

// Function to check Luhn’s Algorithm
bool check_luhn(long long number)
{
    int sum = 0;
    bool alternate = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + 1; // Sum digits if greater than 9
            }
        }

        sum += digit;
        alternate = !alternate;
        number /= 10;
    }

    return (sum % 10 == 0);
}

// Function to count the number of digits
int get_digit_count(long long number)
{
    int count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

// Function to get the first two digits of the card
int get_first_digits(long long number, int digit_count)
{
    while (digit_count > 2)
    {
        number /= 10;
        digit_count--;
    }
    return (int)number;
}
