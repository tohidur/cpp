/* Number of Islands
 *
 * Given a 2d grid map 1's land and 0's water, count the number of islands.
 * An island is surrounded by water and is formed by connecting adjancent
 * lands horizontally or vertically. You may assume all four edges of the grid
 * are all surrounded by water.
 *
 *
 * Example 1
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 * Example 2
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 */

#include<iostream>
#include<vector>

using namespace std;


void callBFS(vector<vector<char>>& grid, int i, int j)
{
    if (i<0||i>=grid.size()||j<0||j>grid[i].size()||grid[i][j]=='0')
        return;
    grid[i][j] = '0';
    callBFS(grid,i+1,j);
    callBFS(grid,i-1,j);
    callBFS(grid,i,j+1);
    callBFS(grid,i,j-1);
}


int number_of_islands(vector<vector<char>>& grid)
{
    int count = 0;
    for (int i=0;i!=grid.size();i++) {
        for (int j=0;j!=grid[i].size();j++) {
            if (grid[i][j] == '1') {
                count += 1;
                callBFS(grid,i,j);
            }
        }
    }
    return count;
}


int main()
{
    vector<vector<char>> grid = \
        {{'1', '1', '0', '1', '0'}, \
         {'1', '1', '0', '0', '0'}, \
         {'0', '0', '1', '0', '0'}, \
         {'0', '0', '0', '1', '1'}};

    cout << number_of_islands(grid) << '\n';

    // for (vector<char> i : grid)
    //    for (char j : i)
    //        cout << j << '\n';
}

