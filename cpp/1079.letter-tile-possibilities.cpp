/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 *
 * https://leetcode.com/problems/letter-tile-possibilities/description/
 *
 * algorithms
 * Medium (75.43%)
 * Likes:    800
 * Dislikes: 31
 * Total Accepted:    38K
 * Total Submissions: 50.3K
 * Testcase Example:  '"AAB"'
 *
 * You have n  tiles, where each tile has one letter tiles[i] printed on it.
 * 
 * Return the number of possible non-empty sequences of letters you can make
 * using the letters printed on those tiles.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tiles = "AAB"
 * Output: 8
 * Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB",
 * "ABA", "BAA".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tiles = "AAABBC"
 * Output: 188
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: tiles = "V"
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= tiles.length <= 7
 * tiles consists of uppercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int numTilePossibilities(string tiles) {
    //     unordered_set<string> data{""};
    //     for(char c : tiles)
    //     {
    //         unordered_set<string> st;
    //         for(auto& s : data)
    //         {
    //             for(int i=0; i<s.size(); ++i)
    //             {
    //                 st.insert(s.substr(0,i)+c+s.substr(i));
    //             }
    //             st.insert(s+c);
    //         }
    //         data.insert(st.begin(), st.end());
    //     }
    //     return data.size()-1;
    // }

    int dfs(vector<int>& data)
    {
        int sum = 0;
        for(int i=0; i<26; ++i)
        {
            if(data[i] == 0) continue;
            sum++;
            data[i]--;
            sum += dfs(data);
            data[i]++;
        }
        return sum;
    }
    int numTilePossibilities(string tiles) {
        vector<int> data(26, 0);
        for(char c : tiles) data[c-'A']++;
        return dfs(data);
    }
};
// @lc code=end

