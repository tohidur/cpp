/*
 * AND - &
 * OR - |
 * XOR - ^ => Result 1 if two bit are different
 * Left shift - << => number of places to shift bits on left
 * Right shift - >> => number of places to shift bits on Right
 * NOR - ~
 */

#include <iostream>
using namespace std;

void basic()
{
    // a   = 0101
    // b   = 1001

    //and  = 0001
    //or   = 1101
    //xor  = 1100
    //a << 2 = 010100
    //a >> 2 = 01
    unsigned int a = 5, b = 9;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a&b = " << (a & b) << endl;
    cout << "a|b = " << (a | b) << endl;
    cout << "a^b = " << (a ^ b) << endl;
    cout << "a<<2 = " << (a << 2) << endl;
    cout << "a>>2 = " << (a >> 2) << endl;
}

int findOdd(int arr[], int n) 
{ 
    int res = 0, i; 
    for (i = 0; i < n; i++)
        cout << (res ^= arr[i]) << endl;
    return res; 
} 

void details()
{
    // << and >> should not be used with negative numbers
    // -1 << 1 and 1 << -1 -- undefined
    // 1 << 33 -- undefined, if stored in 32 bit system

    // find odd
    int arr[] = { 12, 12, 90, 14, 14, 14, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << findOdd(arr, n);
    cout << (12 ^ 12) << endl;

    // & - to check if number is odd or even
    // (x & 1) ? printf("Odd") : printf("Even");

    // The left-shift and right-shift operators are equivalent to multiplication and division by 2 respectively.

}

int main()
{
    basic();
    details();
    return 0;
}
