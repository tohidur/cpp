/* Pascal's Triangle
 *
 * Given a non-negative integer numRows, generate the first numRows of pascals
 * triangle.
 *
 * Input: 5
 * Output: 
 * [
 *      [1]
 *     [1, 1]
 *    [1, 2, 1]
 *  [1, 3,  3, 1]
 * ]
 */

#include<iostream>
#include<vector>
#include<memory>

using namespace std;

unique_ptr<vector<vector<int>>> generate(int n)
{
    unique_ptr<vector<vector<int>>> result{new vector<vector<int>>};
    if (n<=0) return result;

    result->push_back({1});

    for (int i=1;i<n;++i) {
        vector<int> prev_row = (*result)[i-1];
        vector<int> row;
        row.push_back(1);
        for (int j=1;j<i;++j) {
            row.push_back(prev_row[j-1]+prev_row[j]);
        }
        row.push_back(1);
        result->push_back(row);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    unique_ptr<vector<vector<int>>> result = generate(n);

    for (vector<int> i : *result) {
        cout << '\n';
        for (int j : i)
            cout << j << ' ';
        cout << '\n';
    }
}

