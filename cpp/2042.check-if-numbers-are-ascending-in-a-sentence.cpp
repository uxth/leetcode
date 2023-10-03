/*
 * @lc app=leetcode id=2042 lang=cpp
 *
 * [2042] Check if Numbers Are Ascending in a Sentence
 */

// @lc code=start
class Solution {
public:
    bool areNumbersAscending(string s) {
        istringstream iss(s);
        string w;
        auto isNumber = [](string& s){
            return all_of(begin(s), end(s), [](char c){
                return isdigit(c);
            });
        };
        int last = INT_MIN;
        while(iss >> w){
            if(isNumber(w)){
                int cur = stoi(w);
                if(cur <= last) return false;
                last = cur;
            }
        }
        return true;
    }
};
// @lc code=end
/*
""hello world 5 x 5""
""sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s""
*/
