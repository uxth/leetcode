/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (46.76%)
 * Likes:    4141
 * Dislikes: 429
 * Total Accepted:    633.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution {
public:
    unordered_map<char, vector<char>> m{
        // {'1',{}},
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}}
    };
    // void dfs(string& digits, int start, vector<char>& path, vector<string>& res)
    // {
    //     if(start == digits.size())
    //     {
    //         res.push_back(string(path.begin(), path.end()));
    //         return;
    //     }
    //     for(auto& i : m[digits[start]])
    //     {
    //         path.push_back(i);
    //         dfs(digits, start+1, path, res);
    //         path.pop_back();
    //     }
    // }
    // vector<string> letterCombinations(string digits) {
    //     if(digits.empty()) return {};
    //     vector<char> path;
    //     vector<string> res;
    //     dfs(digits, 0, path, res);
    //     return res;
    // }

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty()) return {};
        queue<string> q;
        q.push("");
        // for(auto& next : m[digits[0]]) q.push(next);
        vector<string> res;
        for(int i=0; i<digits.size(); ++i)
        {
            int size = q.size();
            while(size--)
            {
                string f = q.front();q.pop();
                for(char next : m[digits[i]])
                {
                    q.push(f+next);
                }
            }
        }
        while(!q.empty()){ res.push_back(q.front()); q.pop();}
        return res;
    }
};
// @lc code=end

