/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 *
 * https://leetcode.com/problems/keys-and-rooms/description/
 *
 * algorithms
 * Medium (64.29%)
 * Likes:    1064
 * Dislikes: 84
 * Total Accepted:    79.7K
 * Total Submissions: 123.7K
 * Testcase Example:  '[[1],[2],[3],[]]'
 *
 * There are N rooms and you start in room 0.  Each room has a distinct number
 * in 0, 1, 2, ..., N-1, and each room may have some keys to access the next
 * room. 
 * 
 * Formally, each room i has a list of keys rooms[i], and each key rooms[i][j]
 * is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j]
 * = v opens the room with number v.
 * 
 * Initially, all the rooms start locked (except for room 0). 
 * 
 * You can walk back and forth between rooms freely.
 * 
 * Return true if and only if you can enter every room.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1],[2],[3],[]]
 * Output: true
 * Explanation:  
 * We start in room 0, and pick up key 1.
 * We then go to room 1, and pick up key 2.
 * We then go to room 2, and pick up key 3.
 * We then go to room 3.  Since we were able to go to every room, we return
 * true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,3],[3,0,1],[2],[0]]
 * Output: false
 * Explanation: We can't enter the room with number 2.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= rooms.length <= 1000
 * 0 <= rooms[i].length <= 1000
 * The number of keys in all rooms combined is at most 3000.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // bool canVisitAllRooms(vector<vector<int>>& rooms) {
    //     unordered_set<int> visit;
    //     for(int i=1; i<rooms.size(); ++i)visit.insert(i);
    //     queue<int> q;
    //     q.push(0);

    //     while(!q.empty())
    //     {
    //         int f = q.front(); q.pop();
    //         for(int j : rooms[f])
    //         {
    //             if(visit.count(j) == 0) continue;
    //             visit.erase(j);
    //             q.push(j);
    //         }
    //     }
    //     return visit.empty();
    // }

    // bool canVisitAllRooms(vector<vector<int>>& rooms)
    // {
    //     vector<int> res{0}; 
    //     unordered_set<int> visited{0};

    //     for(int i=0; i<res.size(); ++i)
    //     {
    //         for(int j : rooms[res[i]])
    //         {
    //             if(visited.count(j)) continue;
    //             res.push_back(j);
    //             visited.insert(j);
    //         }
    //     }
    //     return res.size() == rooms.size();
    // }

    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        queue<int> q; q.push(0);
        vector<bool> visited(rooms.size(), false);
        int count = 0;
        while(!q.empty())
        {
            int f = q.front(); q.pop();
            if(visited[f]) continue;
            visited[f] = true;
            count++;
            for(int next : rooms[f]) q.push(next);
        }
        return count == rooms.size();
    }

};
// @lc code=end
// [[1,3],[3,0,1],[2],[0]]
