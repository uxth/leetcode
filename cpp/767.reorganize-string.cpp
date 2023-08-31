/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (48.66%)
 * Likes:    1880
 * Dislikes: 83
 * Total Accepted:    94.3K
 * Total Submissions: 192.4K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 * 
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "aab"
 * Output: "aba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "aaab"
 * Output: ""
 * 
 * 
 * Note:
 * 
 * 
 * S will consist of lowercase letters and have length in range [1, 500].
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char,int> m;
        char cha; int count=0;
        for(char c : S) 
        {
            if(++m[c] > count){count=m[c]; cha=c;}
        }
        if(count > (S.size()+1)/2) return "";

        vector<pair<char,int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(),[](auto& a, auto& b){return a.second<b.second;});
        
        string res=S;
        int j=vec.size()-1;
        for(int k=0; k<=1; ++k)
            for(int i=k; i<res.size(); i+=2)
            {
                res[i] = vec[j].first;
                if(--vec[j].second == 0) j--;
            }
        return res;
    }
};
// @lc code=end
//"ogccckcwmbmxtsbmozli"
