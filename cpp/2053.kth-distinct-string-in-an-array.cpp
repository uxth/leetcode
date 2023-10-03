/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 */

// @lc code=start
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> count;
        for(string& s : arr) count[s]++;
        for(string& s : arr){
            if(count[s] == 1 && --k==0)
                return s;
        }
        return "";
    }
};
// @lc code=end
/*
["aaa","aa","a"]\n1
["a","b","a"]\n3
*/
