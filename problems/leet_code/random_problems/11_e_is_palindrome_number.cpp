/*
 * Is Palindrome Number
 */

#include<iostream>
#include<math.h>

using namespace std;


bool is_palindrome(int n)
{
    if (n == 0) return true;
    if (n < 0 || n % 10 == 0) return false;

    int temp = n;
    int c = -1;

    while (temp > 0) {
        c+=1;
        temp = temp/10;
    }

    temp = n;
    int reversed = 0;
    while (temp > 0) {
        int n = temp%10;
        reversed += pow(10,c)*n;
        temp = temp/10;
        c--;
    }

    temp = n;
    while (temp > 0) {
        int a = temp%10;
        int b = reversed%10;

        if (a != b)
            return false;

        temp /= 10;
        reversed /= 10;
    }
    
    return true;
}


bool is_palindrome_itr2(int x)
{
    // number 0 is palindrome.
    if (x == 0) return true;

    // if last digit 0 or number is negative then it's not a palindrome.
    if (x < 0 || x % 10 == 0) return false;

    /* Reverse the number
     *
     * 1.
     * Each time we need to create a space in the base 0 position of reverse.
     * For that we can  multiply current reverse by 10. 
     * - If 3 then (3*10) = 30. We created a 0 in base. Now add the new number.
     *
     * This can be done instead of doning power the position. This is
     * more easier then doing power.
     *
     * 2.
     * To check for while loop termination compare reverse with remaining 
     * actual  number. Remaining because one each reverse calculation
     * iteration actual number will be reduced by 1 digit.
     *
     * The check would be x > reverse(current at some point)
     *
     * At one point when half of the number if parsed
     * - If number consists of odd number of digits or number is not palidrome
     *   then when n/2+1 number of digits are in reverse.
     * - If even number of digits and a palindrome then it will break
     *   when equal. Else if not palindrome then when reverse will have
     *   n/2+1 number of digits.
     *
     * 3.
     * At the end to verfiy if it's a plindrome, reverse will be
     * equal to the actual number. Or if number of digits in reverse is one
     * more than actual number then (reverse /10 == actual number).
     */

    int reverse = 0;
    while (x > reverse) {
        int pop = x % 10;
        x /= 10;
        reverse = (reverse * 10) + pop;
    }

    if (reverse == x || x == reverse/10) return true;
    return false;
}


int main()
{
    int n;
    cin >> n;
    cout << is_palindrome_itr2(n);
}

