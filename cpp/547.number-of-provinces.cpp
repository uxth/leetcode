/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        queue<int> q;
        for(int i=0; i<n; ++i){
            if(visited[i]) continue;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int f = q.front();
                q.pop();
                for(int next = 0; next < n; ++next){
                    if(visited[next] || isConnected[f][next] == 0) continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            ++res;
        }
        return res;
    }
};
// @lc code=end
// [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]
