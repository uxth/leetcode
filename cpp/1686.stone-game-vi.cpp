/*
 * @lc app=leetcode id=1686 lang=cpp
 *
 * [1686] Stone Game VI
 *
 * https://leetcode.com/problems/stone-game-vi/description/
 *
 * algorithms
 * Medium (48.26%)
 * Likes:    158
 * Dislikes: 10
 * Total Accepted:    3.8K
 * Total Submissions: 8K
 * Testcase Example:  '[1,3]\n[2,1]'
 *
 * Alice and Bob take turns playing a game, with Alice starting first.
 * 
 * There are n stones in a pile. On each player's turn, they can remove a stone
 * from the pile and receive points based on the stone's value. Alice and Bob
 * may value the stones differently.
 * 
 * You are given two integer arrays of length n, aliceValues and bobValues.
 * Each aliceValues[i] and bobValues[i] represents how Alice and Bob,
 * respectively, value the i^th stone.
 * 
 * The winner is the person with the most points after all the stones are
 * chosen. If both players have the same amount of points, the game results in
 * a draw. Both players will play optimally. Both players know the other's
 * values.
 * 
 * Determine the result of the game, and:
 * 
 * 
 * If Alice wins, return 1.
 * If Bob wins, return -1.
 * If the game results in a draw, return 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: aliceValues = [1,3], bobValues = [2,1]
 * Output: 1
 * Explanation:
 * If Alice takes stone 1 (0-indexed) first, Alice will receive 3 points.
 * Bob can only choose stone 0, and will only receive 2 points.
 * Alice wins.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: aliceValues = [1,2], bobValues = [3,1]
 * Output: 0
 * Explanation:
 * If Alice takes stone 0, and Bob takes stone 1, they will both have 1 point.
 * Draw.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: aliceValues = [2,4,3], bobValues = [1,6,7]
 * Output: -1
 * Explanation:
 * Regardless of how Alice plays, Bob will be able to have more points than
 * Alice.
 * For example, if Alice takes stone 1, Bob can take stone 2, and Alice takes
 * stone 0, Alice will have 6 points to Bob's 7.
 * Bob wins.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == aliceValues.length == bobValues.length
 * 1 <= n <= 10^5
 * 1 <= aliceValues[i], bobValues[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<pair<int,int>> data;
        
        for(int i=0; i<aliceValues.size(); ++i)
            data.push_back({aliceValues[i]+bobValues[i], i});
        sort(data.begin(), data.end(), greater<pair<int,int>>());
        int alice = 0; int bob = 0;
        for(int i=0; i<data.size(); ++i)
        {
            if(i%2==0)
                alice += aliceValues[data[i].second];
            else
                bob += bobValues[data[i].second];
        }
        return alice==bob?0:(alice<bob?-1:1);
    }
};
// @lc code=end
// [1,5,1]\n[1,1,1]
// [1,2]\n[3,1]
// [9,8,3,8]\n[10,6,9,5]