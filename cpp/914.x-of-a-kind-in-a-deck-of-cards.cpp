/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 *
 * https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
 *
 * algorithms
 * Easy (34.84%)
 * Likes:    568
 * Dislikes: 140
 * Total Accepted:    46.3K
 * Total Submissions: 132K
 * Testcase Example:  '[1,2,3,4,4,3,2,1]'
 *
 * In a deck of cards, each card has an integer written on it.
 * 
 * Return true if and only if you can choose X >= 2 such that it is possible to
 * split the entire deck into 1 or more groups of cards, where:
 * 
 * 
 * Each group has exactly X cards.
 * All the cards in each group have the same integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: deck = [1,2,3,4,4,3,2,1]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: deck = [1,1,1,2,2,2,3,3]
 * Output: false´
 * Explanation: No possible partition.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: deck = [1]
 * Output: false
 * Explanation: No possible partition.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: deck = [1,1]
 * Output: true
 * Explanation: Possible partition [1,1].
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: deck = [1,1,2,2,2,2]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[2,2].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= deck.length <= 10^4
 * 0 <= deck[i] < 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> m;
        for(int i : deck) ++m[i];
        vector<pair<int,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b){return a.second < b.second;});
        int n = v.front().second;
        if(n<2) return false;
        for(int i=2; i<=n; ++i)
        {
            if(all_of(v.begin(), v.end(), [&](pair<int,int>& j){return j.second % i == 0;}))
                return true;
        }
        return false;
    }

};
// @lc code=end

