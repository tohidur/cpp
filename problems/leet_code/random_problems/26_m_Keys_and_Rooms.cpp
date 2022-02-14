/* Keys and Rooms
 *
 * There are n rooms lebeled from 0 to n-1 and all the rooms are locked except for room 0.
 * Your goal is to visit all the rooms. However, you cannot enter a locked room without having its keys.
 *
 * When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, donoting which
 * room it unlocks, and you can take all of them with you to unlock the other rooms.
 *
 * Given an array `rooms` where rooms[i] is the set of keys that you can obtain if you visited room i, return true
 * if you can visit all the rooms, or false otherwise.
 */

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, int> um;
        um[0] = 1;

        for (vector<int> vec : rooms)
            for (int k : vec)
                um[k] = 1;

        return rooms.size() == um.size();
    }
};


int main() {
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    Solution *sol = new Solution();
    cout << sol->canVisitAllRooms(rooms) << endl;
}

