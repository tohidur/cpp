/* First Bad Version
 *
 * A particualr version is bad, so all the version after that is also bad.
 * So you want to find the first bad version.
 *
 * You should try to minimize the number of calls.
 * 1 2 3 4 5 6 7 8 9 10 11 12
 */

#include<iostream>

using namespace std;


class VersionControl {
public:
    bool isBadVersion(int n) {
        return (n >= 4) ? true : false;
    }
};


class Solution : public VersionControl {
public:
    int firstBadVersion(int n) {
        int l=1, r=n, mid;
        while (l <= r) {
            mid = l + (r-l)/2;
            bool is_bad = this->isBadVersion(mid);
            if (is_bad && !this->isBadVersion(mid-1)) {
                return mid;
            } else if (is_bad) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};


int main()
{
    Solution *sol = new Solution();
    cout << sol->firstBadVersion(9) << endl;
}

