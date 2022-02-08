/* Robot returned to origin
 *
 * There is a robot starting at position 0,0 the origin on a 2D plane.
 * Given a sequence of its moves, judge if this robot ends up at (0,0) after
 * it complets it moves.
 *
 * The moves sequence is represented by a string, and the character moves[i]
 * rempresents it's ith move. Valid moves are R, L, U, D
 */

#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'U')
                y++;
            else if (c == 'D')
                y--;
            else if (c == 'R')
                x++;
            else if (c == 'L')
                x--;
        }
        return x == 0 && y == 0;
    }
};


int main() {
    Solution *sol = new Solution();
    string moves {"UDRLLRD"};
    cout << sol->judgeCircle(moves) << endl;
}

