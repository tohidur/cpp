/* Contains Duplicate
 *
 * Give an array of integers, find if the array contains any duplicates.
 *
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


bool contains_duplicates(const vector<int>& arr) {
    unordered_map<int, int> umap;
    umap[arr[0]] = 1;
    for (int i=1;i<arr.size();++i)
        if (umap.find(arr[i]) != umap.end()) return true;
    return false;
}


bool contains_duplicates_sort(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    for (int i=1;i<arr.size();++i)
        if (arr[i]==arr[i-1])
            return true;
    return false;
}


int main()
{
    vector<int> arr{1,2,3,4,1};
    cout << contains_duplicates(arr) << '\n';
    cout << contains_duplicates_sort(arr) << '\n';
}

