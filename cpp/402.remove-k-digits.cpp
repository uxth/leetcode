/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 *
 * https://leetcode.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (30.48%)
 * Likes:    8359
 * Dislikes: 365
 * Total Accepted:    343.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"1432219"\n3'
 *
 * Given string num representing a non-negative integer num, and an integer k,
 * return the smallest possible integer after removing k digits from num.
 *
 *
 * Example 1:
 *
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219
 * which is the smallest.
 *
 *
 * Example 2:
 *
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the
 * output must not contain leading zeroes.
 *
 *
 * Example 3:
 *
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with
 * nothing which is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= num.length <= 10^5
 * num consists of only digits.
 * num does not have any leading zeros except for the zero itself.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans = "";
        for (auto it : num)
        {
            while (ans.size() && it < ans.back() && k)
            {
                ans.pop_back();
                k--;
            }
            if (ans.size() + (it - '0'))
                ans.push_back(it);
        }
        while (k-- && ans.size())
            ans.pop_back();
        if (ans.empty())
            return "0";
        return ans;
    }
    // string removeKdigits(string num, int k) {
    //     if(num.length()<=k){
    //         return "0";
    //     }
    //     if(k==0){
    //         return num;
    //     }

    //     stack<char> st;
    //     string res;

    //     st.push(num[0]);

    //     for(int i=1;i<num.length();i++){
    //         while(k!=0 && !st.empty() && num[i]<st.top()){
    //             --k;
    //             st.pop();
    //         }
    //         st.push(num[i]);

    //         if(num[i]=='0' && st.size()==1){
    //             st.pop();
    //         }

    //     }

    //     while(k && !st.empty()){
    //         --k;
    //         st.pop();
    //     }

    //     while(!st.empty()){
    //         res.push_back(st.top());
    //         st.pop();
    //     }
    //     reverse(res.begin(),res.end());
    //     if(res.length()==0){
    //         return "0";
    //     }
    //     return res;
    // }
};
// @lc code=end
