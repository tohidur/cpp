/* Reverse String
 * Write a function to reverse a string the input string is given as an
 * array of charecters.
 *
 * Do not alocate extra space for another array
 * All chars are printable ASCII chars
 */
#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0, r=s.size()-1;
        while (l < r) {
            this->swap_vector(s, l, r);
            l++;
            r--;
        }
    }
private:
    void swap_vector(vector<char>& s, int i, int j) {
        char a = s[i];
        s[i] = s[j];
        s[j] = a;
    }
};

int main()
{
    vector<char> s {'h', 'e', 'l', 'l', 'o'};
    Solution *sol = new Solution();
    sol->reverseString(s);
    for (char a : s)
        cout << a << endl;
}

