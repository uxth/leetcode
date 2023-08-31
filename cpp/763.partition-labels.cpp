/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (76.03%)
 * Likes:    2561
 * Dislikes: 122
 * Total Accepted:    135.9K
 * Total Submissions: 178.5K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * A string S of lowercase English letters is given. We want to partition this
 * string into as many parts as possible so that each letter appears in at most
 * one part, and return a list of integers representing the size of these
 * parts.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits S into less parts.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S will have length in range [1, 500].
 * S will consist of lowercase English letters ('a' to 'z') only.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> left, right;
        for(int i=0; i<S.size(); ++i)
        {
            if(left.count(S[i]) == 0) left[S[i]] = i;
            right[S[i]] = i;
        }
        vector<int> res;
        int l = left[S[0]]; int r = right[S[0]];

        for(int i=1; i<S.size(); ++i)
        {
            if(left[S[i]] <= r)
                r = max(r, right[S[i]]);
            else
            {
                res.push_back(r-l + 1);
                l=left[S[i]];
                r=right[S[i]];
            }
        }

        res.push_back(r-l+1);
        return res;
     }
};
// @lc code=end

