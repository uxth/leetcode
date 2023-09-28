/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>& b){
                if(a[0]==b[0])
                    return a[1]>b[1];
                return a[0]<b[0];
            });
        int i, j, n=envelopes.size();
        vector<int>lis;
        
        for(i=0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            if(it==lis.end()){lis.push_back(envelopes[i][1]);}
            else{*it = envelopes[i][1];}
        }
        return lis.size();
    }
};
// @lc code=end

