/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 */

// @lc code=start
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res{first};
        for(int i=0; i<encoded.size(); ++i) 
            res.push_back(res[i] ^ encoded[i]);
        return res;
    }
};
// @lc code=end
/*
[6,2,7,3]\n4
*/
