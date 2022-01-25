/* Two sum I - input array is not sorted
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
#include<unordered_map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target)
{
    for (int i=0;i<nums.size();++i) {
        for (int j=i+1;j<nums.size();++j) {
            if (nums[i]+nums[j] == target)
                return vector<int>{i+1,j+1};
        }
    }
    return vector<int>{-1,-1};
}


vector<int> twoSumOnePassMap(vector<int>& nums, int target)
{
    unordered_map<int, int> um{};
    for (int i=0;i!=nums.size();++i) {
        int complement = target - nums[i];
        if (um.find(complement) != um.end())
            return vector<int>{um.at(complement)+1,i+1};
        um[nums[i]] = i;
    }
    return vector<int>{-1,-1};
}


int main()
{
    vector<int> nums{2,7,11,15};
    for (int i : twoSum(nums,9)) cout << i << endl;
    for (int i : twoSumOnePassMap(nums,9)) cout << i << endl;
}

