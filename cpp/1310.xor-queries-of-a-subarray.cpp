/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 *
 * https://leetcode.com/problems/xor-queries-of-a-subarray/description/
 *
 * algorithms
 * Medium (69.10%)
 * Likes:    417
 * Dislikes: 23
 * Total Accepted:    21.1K
 * Total Submissions: 30.5K
 * Testcase Example:  '[1,3,4,8]\n[[0,1],[1,2],[0,3],[3,3]]'
 *
 * Given the array arr of positive integers and the array queries where
 * queries[i] = [Li, Ri], for each query i compute the XOR of elements from Li
 * to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). Return an array
 * containing the result for the given queries.
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
 * Output: [2,7,14,8] 
 * Explanation: 
 * The binary representation of the elements in the array are:
 * 1 = 0001 
 * 3 = 0011 
 * 4 = 0100 
 * 8 = 1000 
 * The XOR values for queries are:
 * [0,1] = 1 xor 3 = 2 
 * [1,2] = 3 xor 4 = 7 
 * [0,3] = 1 xor 3 xor 4 xor 8 = 14 
 * [3,3] = 8
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
 * Output: [8,0,4,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 3 * 10^4
 * 1 <= arr[i] <= 10^9
 * 1 <= queries.length <= 3 * 10^4
 * queries[i].length == 2
 * 0 <= queries[i][0] <= queries[i][1] < arr.length
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res(arr.size());
        
        res[0] = arr[0];
        for(int i = 1 ; i < arr.size() ; i++)
            res[i] = arr[i] ^ res[i - 1];
        
        vector<int> ans(queries.size());
    
        int i = 0;
        for(auto val : queries)
        {
            if(val[0] == 0)
                ans[i++] = res[val[1]];
            else
                ans[i++] = res[val[1]] ^ res[val[0] - 1];
        }
        return ans;
    }
};
// @lc code=end

