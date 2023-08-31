/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 *
 * https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (47.34%)
 * Likes:    215
 * Dislikes: 120
 * Total Accepted:    24.9K
 * Total Submissions: 52.7K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j]
 * = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that
 * is, one domino can be rotated to be equal to another domino.
 * 
 * Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
 * and dominoes[i] is equivalent to dominoes[j].
 * 
 * 
 * Example 1:
 * Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 * 
 */

// @lc code=start
class Solution {
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator () (std::pair<T1, T2> const &pair) const
    {
        std::size_t h1 = std::hash<T1>()(pair.first);
        std::size_t h2 = std::hash<T2>()(pair.second);

        return h1 ^ h2;
    }
};
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,unordered_map<int,int>> m;
        for(auto& i : dominoes)
        {
            if(i[0] > i[1]) swap(i[0], i[1]);
            m[i[0]][i[1]]++;
        }

        int res = 0;
        for(auto& i : m)
        {
            for(auto& j : i.second)
            {
                if(j.second > 1) res+=(j.second-1)*j.second/2;
            }
        }
        return res;
    }
};
// @lc code=end
// [[1,1],[2,2],[1,1],[1,2],[1,2],[1,1]]
