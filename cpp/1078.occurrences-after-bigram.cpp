/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 *
 * https://leetcode.com/problems/occurrences-after-bigram/description/
 *
 * algorithms
 * Easy (64.73%)
 * Likes:    145
 * Dislikes: 184
 * Total Accepted:    29.8K
 * Total Submissions: 46.1K
 * Testcase Example:  '"alice is a good girl she is a good student"\n"a"\n"good"'
 *
 * Given words first and second, consider occurrences in some text of the form
 * "first second third", where second comes immediately after first, and third
 * comes immediately after second.
 * 
 * For each such occurrence, add "third" to the answer, and return the
 * answer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: text = "alice is a good girl she is a good student", first = "a",
 * second = "good"
 * Output: ["girl","student"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: text = "we will we will rock you", first = "we", second = "will"
 * Output: ["we","rock"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= text.length <= 1000
 * text consists of space separated words, where each word consists of
 * lowercase English letters.
 * 1 <= first.length, second.length <= 10
 * first and second consist of lowercase English letters.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> split(string s)
    {
        vector<string> res;
        int left = -1;
        for(int i=0; i<=s.size(); ++i)
        {
            if(s[i] == ' ' || i == s.size())
            {
                res.push_back(s.substr(left+1, i-left-1));
                left = i;
            }
        }
        return res;
    }
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> strs = split(text);
        vector<string> res;
        if(strs.size() < 3) return {};
        for(int i=2; i<strs.size(); ++i)
        {
            if(strs[i-2] == first && strs[i-1] == second) 
                res.push_back(strs[i]);
        }
        return res;
    }


    // ////////////////////////////////
    // vector<string> findOcurrences(string text, string first, string second)
    // {
    //     vector<string> res;
    //     istringstream iss(text);
    //     string w;
    //     int i = 0;
    //     while (iss >> w)
    //     {
    //         if(i==2) {res.push_back(w);i=0;}

    //         if(w == first) i++;
    //         else if(w == second && i == 1) i++;
    //         else i=0;
    //     }
    //     return res;
    // }
};
// @lc code=end

