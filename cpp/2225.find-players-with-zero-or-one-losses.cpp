/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lose, win;
        set<int> players;
        int player_count = 0;
        for(auto& m : matches){
            ++win[m[0]];
            ++lose[m[1]];
            players.insert(m[0]);
            players.insert(m[1]);
        }
        vector<vector<int>> res(2);
        for(int i : players){
            if(win.count(i) && lose.count(i) == 0) res[0].push_back(i);
            if(lose[i] == 1) res[1].push_back(i);
        }
        return res;
    }
};
// @lc code=end
/*

[[2,3],[1,3],[5,4],[6,4]]
[[1,100000]]
 
 */

