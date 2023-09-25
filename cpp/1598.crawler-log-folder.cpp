/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res = 0;
        for(string& log : logs){
            if(log[0] != '.') res++;
            else if(log[1] == '.') res = max(0, --res);
        }
        return res;
    }
};
// @lc code=end
/*
["d1/","d2/","./","d3/","../","d31/"]
["d1/","../","../","../"]
*/
