/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 *
 * https://leetcode.com/problems/shopping-offers/description/
 *
 * algorithms
 * Medium (51.47%)
 * Likes:    618
 * Dislikes: 485
 * Total Accepted:    32.8K
 * Total Submissions: 63.1K
 * Testcase Example:  '[2,5]\n[[3,0,5],[1,2,10]]\n[3,2]'
 *
 * 
 * In LeetCode Store, there are some kinds of items to sell. Each item has a
 * price.
 * 
 * 
 * 
 * However, there are some special offers, and a special offer consists of one
 * or more different kinds of items with a sale price.
 * 
 * 
 * 
 * You are given the each item's price, a set of special offers, and the number
 * we need to buy for each item.
 * The job is to output the lowest price you have to pay for exactly certain
 * items as given, where you could make optimal use of the special offers.
 * 
 * 
 * 
 * Each special offer is represented in the form of an array, the last number
 * represents the price you need to pay for this special offer, other numbers
 * represents how many specific items you could get if you buy this offer.
 * 
 * 
 * You could use any of special offers as many times as you want.
 * 
 * Example 1:
 * 
 * Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
 * Output: 14
 * Explanation: 
 * There are two kinds of items, A and B. Their prices are $2 and $5
 * respectively. 
 * In special offer 1, you can pay $5 for 3A and 0B
 * In special offer 2, you can pay $10 for 1A and 2B. 
 * You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer
 * #2), and $4 for 2A.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
 * Output: 11
 * Explanation: 
 * The price of A is $2, and $3 for B, $4 for C. 
 * You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
 * You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special
 * offer #1), and $3 for 1B, $4 for 1C. 
 * You cannot add more items, though only $9 for 2A ,2B and 1C.
 * 
 * 
 * 
 * Note:
 * 
 * There are at most 6 kinds of items, 100 special offers.
 * For each item, you need to buy at most 6 of them.
 * You are not allowed to buy more items than you want, even if that would
 * lower the overall price.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int purchaseWithOriPrice(vector<int>& price, vector<int> needs)
    // {
    //     int res = 0;
    //     for(int i=0; i<price.size(); ++i)
    //     {
    //         res += price[i] * needs[i];
    //     }
    //     return res;
    // }
    // int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int index)
    // {
    //     if (index == special.size())
    //         return purchaseWithOriPrice(price, needs);
    //     int i;
    //     vector<int> newNeeds(needs);
    //     for(i=0; i<special[index].size() - 1; ++i)
    //     {
    //         int remain = needs[i] - special[index][i];
    //         if (remain < 0) break;
    //         else newNeeds[i] = remain;
    //     }
    //     if (i == special[index].size() - 1)
    //         return min(special[index].back() +dfs(price, special, newNeeds, index), dfs(price, special, needs, index + 1));
    //     return  dfs(price, special, needs, index + 1);
    // }
    // int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    // {
    //     return dfs(price, special, needs, 0);
    // }


    bool match(vector<int>& c, vector<int>& s, vector<int>& needs)
    {
        for(int i=0; i<needs.size(); ++i)
            if(c[i]+s[i]>needs[i]) return false;
        return true;
    }
    int bfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        int n = price.size();
        int res = 0;
        for(int i=0; i<n; ++i) res+=price[i]*needs[i];
        queue<vector<int>> q;
        q.push(vector<int>(n+1));
        while(!q.empty())
        {
            auto f = move(q.front());
            q.pop();
            for(auto& s : special)
            {
                if(match(f, s, needs))
                {
                    vector<int> next(n+1);
                    for(int i=0; i<=n; ++i) next[i]=f[i]+s[i];
                    int data = next.back();
                    for(int i=0;i<n;++i) data+=(needs[i]-next[i])*price[i];
                    res = min(res, data);
                    q.push(next);
                }
            }
        }
        return res;
    }
    void helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost, int& res)
    {
        if(any_of(needs.begin(), needs.end(), [](int i){return i<0;})) return;
        int c = cost;
        for(int i=0; i<price.size(); ++i) c += price[i]*needs[i];
        res = min(res, c);
        for(auto& s : special)
        {
            vector<int> nn(needs);
            for(int i=0;i<nn.size(); ++i) nn[i]-=s[i];
            helper(price, special, nn, cost + s.back(), res);
        }

    }
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        int res = 0;
        for(int i=0; i<price.size(); ++i) res+=price[i]*needs[i];
        helper(price, special, needs, 0, res);
        return res;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        // return bfs(price, special, needs);
        return dfs(price, special, needs);
    }
};
// @lc code=end
// [2,3,4]\n[[1,1,0,4],[2,2,1,9]]\n[1,2,1]
// [0,0,0]\n[[1,1,0,4],[2,2,1,9]]\n[1,1,1]
// [9,9]\n[[1,1,1]]\n[2,2]
// [3,10,5,7,7,3]\n[[3,2,2,6,2,5,30],[4,6,5,2,3,2,12],[1,0,4,6,3,3,23],[0,5,3,2,4,2,8],[4,1,2,6,3,2,33],[3,0,6,5,5,2,33],[1,4,4,0,2,6,10],[5,1,0,5,6,3,16],[3,4,5,6,3,5,5],[6,0,6,0,5,5,22],[3,0,4,4,2,6,15],[5,4,2,3,5,0,9],[4,4,5,5,6,1,23],[2,6,5,6,6,4,4],[5,0,2,1,0,4,21],[1,4,6,6,1,6,4],[4,0,5,6,2,2,17],[1,3,5,1,3,3,25],[0,1,4,5,6,4,7],[0,2,0,6,4,4,17],[3,2,3,5,2,2,27],[2,2,6,1,5,4,31],[6,6,0,0,5,2,6],[4,6,6,2,6,6,2],[1,2,4,4,4,6,22],[4,6,4,4,1,4,2],[6,6,5,6,3,5,31],[6,5,0,4,2,5,8],[2,2,4,3,4,6,24],[6,5,6,1,4,4,25],[5,6,1,3,3,6,2],[5,2,4,4,0,2,6],[3,0,4,3,3,6,27],[5,5,3,3,4,3,10],[1,5,1,5,2,2,9],[3,2,1,1,4,5,8],[3,5,3,6,6,5,13],[0,4,6,5,3,1,17],[5,2,4,6,5,5,23],[0,5,3,1,0,4,20],[3,0,0,4,6,1,28],[3,0,1,3,4,0,3],[5,6,6,3,1,1,22],[6,4,3,4,2,0,10],[1,2,0,2,1,5,28],[5,6,5,6,6,6,8],[2,4,6,0,4,3,4],[3,2,5,1,6,1,15],[0,6,2,1,2,2,7],[1,0,5,4,5,3,21],[4,2,3,6,4,2,29],[1,4,2,3,6,0,28],[4,1,0,4,1,3,22],[1,3,4,0,2,2,27],[0,3,0,2,3,3,18],[0,3,5,0,5,0,31],[5,0,0,0,6,5,33],[5,1,0,6,3,2,32],[3,4,1,1,5,6,29],[1,2,1,1,4,6,34],[2,6,4,5,4,2,24],[4,1,2,2,0,0,22],[3,2,4,4,4,4,7],[2,3,2,3,4,1,8],[1,1,2,3,5,5,25],[3,0,5,0,6,1,17],[0,1,5,1,2,3,16],[6,5,2,0,6,2,32],[3,4,4,2,5,0,23],[3,3,4,6,3,2,17],[1,3,3,1,3,1,14],[5,2,4,2,0,0,11],[0,2,4,1,6,1,16],[2,6,1,4,2,5,20],[4,0,6,5,2,0,19],[3,1,2,1,4,0,8],[2,5,4,0,0,1,19],[5,0,4,5,5,5,23],[5,1,4,2,1,1,34],[1,1,2,4,0,3,3],[2,3,5,5,1,2,24],[6,1,5,2,1,2,18],[4,5,3,3,6,5,26],[6,6,2,0,0,2,32],[6,5,6,1,6,4,15],[0,6,3,5,5,6,5],[5,2,6,2,5,3,24],[5,6,0,4,6,2,7],[4,2,5,3,1,5,8],[5,2,2,6,0,3,34],[5,3,0,3,3,0,5],[1,1,0,6,0,0,21],[6,0,4,2,3,2,13],[2,0,1,0,1,4,32],[1,0,4,4,1,5,2],[4,5,3,6,6,1,34],[6,2,5,4,2,2,12],[3,2,2,3,3,4,28],[2,6,4,1,4,2,25],[6,0,2,1,3,3,11]]\n[2,5,4,6,5,2]