/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 *
 * https://leetcode.com/problems/camelcase-matching/description/
 *
 * algorithms
 * Medium (57.00%)
 * Likes:    238
 * Dislikes: 139
 * Total Accepted:    18.7K
 * Total Submissions: 32.8K
 * Testcase Example:  '["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]\n"FB"'
 *
 * A query word matches a given pattern if we can insert lowercase letters to
 * the pattern word so that it equals the query. (We may insert each character
 * at any position, and may insert 0 characters.)
 * 
 * Given a list of queries, and a pattern, return an answer list of booleans,
 * where answer[i] is true if and only if queries[i] matches the pattern.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FB"
 * Output: [true,false,true,true,false]
 * Explanation: 
 * "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
 * "FootBall" can be generated like this "F" + "oot" + "B" + "all".
 * "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
 * 
 * Example 2:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FoBa"
 * Output: [true,false,true,false,false]
 * Explanation: 
 * "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
 * "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: queries =
 * ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern =
 * "FoBaT"
 * Output: [false,true,false,false,false]
 * Explanation: 
 * "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" +
 * "est".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= queries.length <= 100
 * 1 <= queries[i].length <= 100
 * 1 <= pattern.length <= 100
 * All strings consists only of lower and upper case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getCaps(string& s)
    {
        int caps = 0;
        for(char c : s) caps += c>='A'&&c<='Z';
        return caps;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int caps = getCaps(pattern);
        vector<bool> res(queries.size());
        for(int i=0; i<queries.size(); ++i)
        {
            if(caps != getCaps(queries[i]))continue;
            int j=0;
            for(int k=0; k<queries[i].size(); ++k)
            {
                if(j<pattern.size() && pattern[j] == queries[i][k])j++;
            }
            res[i] = j==pattern.size();
        }
        return res;
    }
};
// @lc code=end

