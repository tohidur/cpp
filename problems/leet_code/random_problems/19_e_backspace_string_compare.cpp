/* Backspace String Compare
 *
 * Given two strings s and t, return true if they are equal when both are typed
 * into empty text editors. '#' means a backspace.
 *
 * Backspacing an empty text, the text will continue empty.
 */

#include<iostream>
#include<string>
#include<forward_list>

using namespace std;


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string::iterator sit, tit;
        forward_list<char> rs, rt;

        sit = s.begin(), tit = t.begin();
        for (; (sit != s.end() || tit != t.end()); )
        {
            if (sit != s.end())
            {
                if (*sit == '#')
                    rs.pop_front();
                else
                    rs.push_front(*sit);
                sit++;
            }

            if (tit != t.end())
            {
                if (*tit == '#')
                    rt.pop_front();
                else
                    rt.push_front(*tit);
                tit++;
            }
        }

        forward_list<char>::iterator rsit, rtit;
        rsit = rs.begin(), rtit = rt.begin();
        for (; (rsit != rs.end() && rtit != rt.end()); rsit++, rtit++)
                if (*rsit != *rtit) return false;

        if (rsit == rs.end() && rtit == rt.end()) return true;
        return false;
    }

    bool backspaceCompareItr1(string S, string T) {
        for (int i = S.length() - 1, j = T.length() - 1; i >= 0 || j >= 0;
                --i, --j) {
            if (findNextChar(S, &i) != findNextChar(T, &j)) {
                return false;
            }
        }
        return true;
    }
private:
    char findNextChar(const string& s, int *i) {
        int skip = 0;
        for (; *i >= 0; --(*i)) {
            if (s[*i] == '#') {
                ++skip;
            } else if (skip > 0) {
                --skip;
            } else {
                return s[*i];
            }
        }
        return '\0';
    }
};


int main()
{
    Solution *sol = new Solution();
    string s = "aab#c", t = "ad#c";
    cout << sol->backspaceCompare(s, t) << endl;
    cout << sol->backspaceCompareItr1(s, t) << endl;
}

