/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 *
 * https://leetcode.com/problems/path-crossing/description/
 *
 * algorithms
 * Easy (55.90%)
 * Likes:    157
 * Dislikes: 5
 * Total Accepted:    15.8K
 * Total Submissions: 28.2K
 * Testcase Example:  '"NES"'
 *
 * Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing
 * moving one unit north, south, east, or west, respectively. You start at the
 * origin (0, 0) on a 2D plane and walk on the path specified by path.
 * 
 * Return True if the path crosses itself at any point, that is, if at any time
 * you are on a location you've previously visited. Return False otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: path = "NES"
 * Output: false 
 * Explanation: Notice that the path doesn't cross any point more than once.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: path = "NESWW"
 * Output: true
 * Explanation: Notice that the path visits the origin twice.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= path.length <= 10^4
 * path will only consist of characters in {'N', 'S', 'E', 'W}
 * 
 * 
 */

// @lc code=start
class Solution {
public:
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
    bool isPathCrossing(string path) {
        unordered_set<pair<int,int>, pair_hash> s{{0,0}};
        int y = 0; int x = 0;
        for(char c : path)
        {
            switch (c)
            {
            case 'N':y--;break;
            case 'S':y++;break;
            case 'E':x++;break;
            case 'W':x--;break;
            default:break;
            }
            if(s.count({y,x})) return true;
            s.insert({y,x});
        }
        return false;
    }
};
// @lc code=end

