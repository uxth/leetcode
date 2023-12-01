/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 *
 * https://leetcode.com/problems/best-team-with-no-conflicts/description/
 *
 * algorithms
 * Medium (40.67%)
 * Likes:    2856
 * Dislikes: 92
 * Total Accepted:    78.4K
 * Total Submissions: 155.1K
 * Testcase Example:  '[1,3,5,10,15]\n[1,2,3,4,5]'
 *
 * You are the manager of a basketball team. For the upcoming tournament, you
 * want to choose the team with the highest overall score. The score of the
 * team is the sum of scores of all the players in the team.
 *
 * However, the basketball team is not allowed to have conflicts. A conflict
 * exists if a younger player has a strictly higher score than an older player.
 * A conflict does not occur between players of the same age.
 *
 * Given two lists, scores and ages, where each scores[i] and ages[i]
 * represents the score and age of the i^th player, respectively, return the
 * highest overall score of all possible basketball teams.
 *
 *
 * Example 1:
 *
 *
 * Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
 * Output: 34
 * Explanation: You can choose all the players.
 *
 *
 * Example 2:
 *
 *
 * Input: scores = [4,5,6,5], ages = [2,1,2,1]
 * Output: 16
 * Explanation: It is best to choose the last 3 players. Notice that you are
 * allowed to choose multiple people of the same age.
 *
 *
 * Example 3:
 *
 *
 * Input: scores = [1,2,3,5], ages = [8,9,10,1]
 * Output: 6
 * Explanation: It is best to choose the first 3 players.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= scores.length, ages.length <= 1000
 * scores.length == ages.length
 * 1 <= scores[i] <= 10^6
 * 1 <= ages[i] <= 1000
 *
 *
 */

// @lc code=start
class Solution
{
public:
    // int dp(vector<int> &scores, vector<int> &ages)
    // {
    //     int n = ages.size();
    //     vector<pair<int,int>> team;
    //     for(int i=0; i<n; ++i) team.push_back({ages[i], scores[i]});
    //     sort(begin(team), end(team), [](auto& a, auto& b){
    //         if(a.first == b.first) return a.second < b.second;
    //         return a.first < b.first;
    //     });

    //     int res = 0;
    //     vector<int> dp(n, 0);
    //     for(int i=0; i<n; ++i){
    //         dp[i] = team[i].second;
    //         for(int j=0; j<i; ++j){
    //             if(team[j].first == team[i].first || team[j].second <= team[i].second && team[j].first < team[i].first){
    //                 dp[i] = max(dp[i], dp[j]+team[i].second);
    //             }
    //         }
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }

/////////////////////////////////////////////////////////////////////////
    // static constexpr int MX = 1000;
    // vector<int> tr;


    // int lowbit(int x) {
    //     return x & -x;  // ^= x - 1
    // }

    // int query(int idx) {
    //     int res = 0;
    //     for (int i = idx; i > 0; i -= lowbit(i)) {  // &= i - 1
    //         res = max(res, tr[i]);
    //     }
    //     return res;
    // }

    // void update(int idx, int x) {
    //     for (int i = idx; i <= MX; i += lowbit(i)) {
    //         tr[i] = max(tr[i], x);
    //     }
    // }
    
    // int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    //     int n = scores.size();
    //     pair<int, int> a[n];
    //     for (int i = 0; i < n; i++) {
    //         a[i] = {scores[i], ages[i]};
    //     }
    //     sort(a, a + n);
        
    //     n = *max_element(ages.begin(), ages.end());
    //     tr.resize(MX + 1);
    //     for (auto &[score, age] : a) {
    //         update(age, query(age) + score);
    //     }
    //     return query(n);
    // }

/////////////////////////////////////////////////
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<tuple<int,int>> items;
        for (int i = 0; i < size(scores); ++i) 
            items.push_back({scores[i], ages[i]});
        sort(begin(items), end(items));

        map<int,int> res; res[0] = 0;
        for(auto [sc, ag] : items) {
            auto it0 = res.upper_bound(ag);
            int sc2 = sc + (--it0)->second;
            auto it = res.insert(it0, {ag, sc2});
            if (it->second < sc2) 
                it->second = sc2;
            ++it;
            while (it != res.end() && it->second <= sc2) {
                auto it2 = it++;
                res.erase(it2);
            }
        }
        return res.rbegin()->second;
    }



//////////////////////////////////////////////////////

    // int dp[1005][1005];
    // // i is the index of g
    // // age is the max age so far
    // int dfs(vector<pair<int, int>>& g, int i, int age) {
    //     // if i reaches the end, then return 0
    //     if (i == g.size()) return 0;
    //     // if dp[i][age] is calculated before, return it directly
    //     if (dp[i][age] != -1) return dp[i][age];
    //     // we have two choices - either take this player or skip it
    //     // we first calculate the score if we skip this player
    //     int res = dfs(g, i + 1, age);
    //     // if we want to take this player, we need to check if there is a conflict
    //     // since the score is sorted, we just need to check the age
    //     // if we take this player, the score will be increased by g[i].first
    //     // then we add the result from `dfs(g, i + 1, g[i].second)`
    //     // since we take this player, we need ti mark the age as g[i].second
    //     if (g[i].second >= age) res = max(res, g[i].first + dfs(g, i + 1, g[i].second));
    //     // memo it
    //     return dp[i][age] = res;
    // }
    // int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    //     // init dp with initial value -1
    //     memset(dp, -1, sizeof(dp));
    //     // we sort by score, then age
    //     vector<pair<int, int>> g;
    //     for (int i = 0; i < scores.size(); i++) {
    //         g.push_back({scores[i], ages[i]});
    //     }
    //     sort(g.begin(), g.end());
    //     return dfs(g, 0, 0);
    // }
};
// @lc code=end
/*
[1,2,3,5]\n[8,9,10,1]
[4,5,6,5]\n[2,1,2,1]
*/