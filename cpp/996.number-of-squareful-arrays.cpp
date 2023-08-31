/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 *
 * https://leetcode.com/problems/number-of-squareful-arrays/description/
 *
 * algorithms
 * Hard (47.86%)
 * Likes:    324
 * Dislikes: 21
 * Total Accepted:    13.2K
 * Total Submissions: 27.6K
 * Testcase Example:  '[1,17,8]'
 *
 * Given an array A of non-negative integers, the array is squareful if for
 * every pair of adjacent elements, their sum is a perfect square.
 * 
 * Return the number of permutations of A that are squareful.  Two permutations
 * A1 and A2 differ if and only if there is some index i such that A1[i] !=
 * A2[i].
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,17,8]
 * Output: 2
 * Explanation: 
 * [1,8,17] and [17,8,1] are the valid permutations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2]
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 12
 * 0 <= A[i] <= 1e9
 * 
 */

// @lc code=start
class Solution {
public:
    void dfs(int x, int left, unordered_map<int,int>& m, unordered_map<int,vector<int>>& graph, int& res)
    {
        --m[x];
        if(!left) res++;
        for(int y : graph[x])
            if(m[y] > 0) dfs(y, left-1, m, graph, res);
        ++m[x];
    }
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int,int> m;
        for(int i : A) ++m[i];
        for(auto& i : m)
        {
            for(auto& j : m)
            {
                int x = i.first;
                int y = j.first;
                int sqt = sqrt(x+y);
                if(sqt*sqt == x+y)
                    graph[x].push_back(y);
            }
        }
        int res = 0;
        for(auto& i : m)
            dfs(i.first, A.size()-1, m, graph, res);
        return res;

    }
};
// @lc code=end

