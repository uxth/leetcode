/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 *
 * https://leetcode.com/problems/jump-game-iv/description/
 *
 * algorithms
 * Hard (38.12%)
 * Likes:    210
 * Dislikes: 16
 * Total Accepted:    10.5K
 * Total Submissions: 27.4K
 * Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
 *
 * Given an array of integers arr, you are initially positioned at the first
 * index of the array.
 * 
 * In one step you can jump from index i to index:
 * 
 * 
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 * 
 * 
 * Return the minimum number of steps to reach the last index of the array.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
 * index 9 is the last index of the array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You don't need to jump.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last
 * index of the array.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [6,1,9]
 * Output: 2
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * -10^8 <= arr[i] <= 10^8
 * 
 */

// @lc code=start
class Solution {
public:
    struct node
    {
        node(vector<int>& arr, int start)
        {
            this->arr = arr;
            que.push(start);
            visited.assign(arr.size(), false);
            visited[start] = true;
            head.insert(start);
        }
        queue<int> que;
        vector<bool> visited;
        unordered_set<int> head;
        vector<int> arr;
        
        bool step(unordered_map<int, vector<int>>& m, unordered_set<int>& inter)
        {
            head.clear();
            int size = que.size();
            while(size--)
            {
                int f = que.front(); que.pop();
                if(inter.count(f)) return true;
                vector<int>& next = m[arr[f]];
                next.push_back(f-1);
                next.push_back(f+1);
                
                for(int i : next)
                {
                    if(i!=f && i>=0 && i<arr.size() && !visited[i])
                    {
                        que.push(i);
                        visited[i] = true;
                        head.insert(i);
                        if(inter.count(i)) return true;
                    }
                }
            }
            return false;
        }
    };
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        unordered_map<int, vector<int>> m;
        for(int i=0; i<arr.size(); ++i)
        {
            m[arr[i]].push_back(i);
        }
        node forward(arr, 0);
        node backward(arr, arr.size() - 1);
        int move = 0;
        while(true)
        {
            if(++move % 2)
            {
                if(forward.step(m, backward.head))
                    break;
            }
            else
            {
                if(backward.step(m, forward.head))
                    break;
            }
        }
        return move;
    }

    // int minJumps(vector<int>& arr) {
    //     int n = arr.size();
    //     unordered_map<int, vector<int>> indicesOfValue;
    //     for (int i = 0; i < n; i++)
    //         indicesOfValue[arr[i]].push_back(i);
    //     vector<bool> visited(n); visited[0] = true;
    //     queue<int> q; q.push(0);
    //     int step = 0;
    //     while (!q.empty()) {
    //         for (int size = q.size(); size > 0; --size) {
    //             int i = q.front(); q.pop();
    //             if (i == n - 1) return step; // Reached to last index
    //             vector<int>& next = indicesOfValue[arr[i]];
    //             next.push_back(i - 1); next.push_back(i + 1);
    //             for (int j : next) {
    //                 if (j >= 0 && j < n && !visited[j]) {
    //                     visited[j] = true;
    //                     q.push(j);
    //                 }
    //             }
    //             next.clear(); // avoid later lookup indicesOfValue arr[i]
    //         }
    //         step++;
    //     }
    //     return 0;
    // }
};
// @lc code=end