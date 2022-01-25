/* Binary Search - return index of the element
 */

#include<iostream>
#include<vector>

using namespace std;


int binary_search(vector<int>& nums, int n)
{
    int l=0, r=nums.size(), mid;
    if (r == 0) return -1;

    r -= 1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == n)
            return mid;
        else if (nums[mid] < n)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}


int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    cout << binary_search(nums, -1) << endl;
}

