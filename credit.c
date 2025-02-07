#include <cs50.h>
#include <stdio.h>

bool check_result(long long number);
int digit_number(long long number);
int first_number(long long number, int digit);

int main()
{
    long long number = get_long("Enter your Credit Card number: ");
    bool result = check_result(number);
    if (!result)
    {
        printf("INVALID\n");
        return 0;
    }

    int digit = digit_number(number);

    int first_digits = first_number(number, digit);
    int first_digit = first_digits / 10;

    if (digit == 15 && (first_digits == 37 || first_digits == 35))
    {
        printf("AMEX\n");
    }
    else if (digit == 16 && (first_digits >= 51 && first_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((digit == 16 || digit == 13) && (first_digit == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool check_result(long long number)
{
    int sum = 0;
    bool alt = false;

    while (number > 0)
    {

        int digit = number % 10;

        if (alt)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
        }

        alt = !alt;
        sum += digit;
        number /= 10;
    }

    return (sum % 10 == 0);
}

int digit_number(long long number)
{
    int digit = 0;
    while (number > 0)
    {
        number /= 10;
        digit++;
    }

    return digit;
}

int first_number(long long number, int digit)
{
    while (digit > 2)
    {
        number /= 10;
        digit--;
    }

    return (int) number;
}
