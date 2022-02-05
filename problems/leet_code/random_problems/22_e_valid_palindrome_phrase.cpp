/* Valid Palindrome Phrase
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads
 * the same forward and backward.
 */

// #include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;


// void to_lower(string& s) {
//    transform(s.begin(), s.end(), s.begin(), ::tolower);
// }


class Solution {
public:
    bool should_skip(char a) {
        if (a == ' ' || a == '\n' || a == '\t' || !isalnum(a))
            return true;
        return false;
    }

    bool isPalindrome(string& s) {
        int b=0, e = s.length();
        if (e == 0) return true;

        while (b < e) {
            char bc = tolower(s[b]), ec = tolower(s[e]);

            if (should_skip(bc))
                b++;
            else if (should_skip(ec))
                e--;
            else if (bc!=ec) 
                return false;
            else {
                b++;
                e--;
            }
        }

        return true;
    }
};


int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution *sol = new Solution();
    cout << sol->isPalindrome(s) << endl;
}

