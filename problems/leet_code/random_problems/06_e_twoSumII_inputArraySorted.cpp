/* Two sum II - input array is sorted
 *
 * Given an array of integers that is already sorted in ascending order, find
 * two numbers such that they add up to a specific target number
 *
 * The function should return indices of the two numbers, where index1 must be
 * less than index2.
 *
 * - You may assume that each input would have exactly one solution and you
 *   may not use the same element twice.
 *
 * Input: [2, 7, 11, 15], target = 9
 * Output: [1,2]
 */

#include<iostream>
#include<vector>
#include<memory>


using namespace std;

unique_ptr<int[]> twoSum(const vector<int>& arr, int t)
{
    unique_ptr<int[]> r{new int[]{-1,-1}};
    int b=0, e=arr.size()-1;

    while (b < e) {
        int sum = arr[b]+arr[e];
        if (sum > t) {
            e-=1;
        }
        else if (sum < t) {
            b+=1;
        }
        else {
            r[0]=b+1;
            r[1]=e+1;
            return r;
        }
    }

    return r;
}


int main()
{
    vector<int> arr{2,8,9,13,19};
    unique_ptr<int[]> r = twoSum(arr, 22);
    cout << r[0] << "-" << r[1] << endl;
}

