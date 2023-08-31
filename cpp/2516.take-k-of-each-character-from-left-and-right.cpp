/*
 * @lc app=leetcode id=2516 lang=cpp
 *
 * [2516] Take K of Each Character From Left and Right
 */

// @lc code=start
class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k<=0) return 0;
        int n = s.size();
        if(n < 3*k) return -1;
        vector<int> count(3, 0);
        int left = n-1;
        while(left >= 0){
            ++count[s[left--]-'a'];
            if(all_of(begin(count), end(count), [&](int x){return x>= k;})) break;
        }
        if(any_of(begin(count), end(count), [&](int x){return x < k;})) return -1;
        
        int right = 0;
        int res = right+n - left - 1;
        
        ++left;
        while(left < n && right <= left){
            while(right<=left && s[right] != s[left]) {
                ++count[s[right++]-'a'];
            }
            count[s[right++]-'a']++;
            count[s[left++]-'a']--;
            while(left<n && count[s[left]-'a'] > k){
                --count[s[left++]-'a'];
            }
            res = min(res, right+n-left);
        }
        return res;        
    }
};
// @lc code=end

