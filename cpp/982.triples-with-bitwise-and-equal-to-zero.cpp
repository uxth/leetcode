/*
 * @lc app=leetcode id=982 lang=cpp
 *
 * [982] Triples with Bitwise AND Equal To Zero
 *
 * https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/
 *
 * algorithms
 * Hard (55.92%)
 * Likes:    135
 * Dislikes: 150
 * Total Accepted:    9.2K
 * Total Submissions: 16.5K
 * Testcase Example:  '[2,1,3]'
 *
 * Given an array of integers A, find the number of triples of indices (i, j,
 * k) such that:
 * 
 * 
 * 0 <= i < A.length
 * 0 <= j < A.length
 * 0 <= k < A.length
 * A[i] & A[j] & A[k] == 0, where & represents the bitwise-AND operator.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,1,3]
 * Output: 12
 * Explanation: We could choose the following i, j, k triples:
 * (i=0, j=0, k=1) : 2 & 2 & 1
 * (i=0, j=1, k=0) : 2 & 1 & 2
 * (i=0, j=1, k=1) : 2 & 1 & 1
 * (i=0, j=1, k=2) : 2 & 1 & 3
 * (i=0, j=2, k=1) : 2 & 3 & 1
 * (i=1, j=0, k=0) : 1 & 2 & 2
 * (i=1, j=0, k=1) : 1 & 2 & 1
 * (i=1, j=0, k=2) : 1 & 2 & 3
 * (i=1, j=1, k=0) : 1 & 1 & 2
 * (i=1, j=2, k=0) : 1 & 3 & 2
 * (i=2, j=0, k=1) : 3 & 2 & 1
 * (i=2, j=1, k=0) : 3 & 1 & 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 0 <= A[i] < 2^16
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int countTriplets(vector<int>& A) {
    //     int res = 0;
    //     unordered_map<int,int> counts;
    //     for(int i=0; i<A.size(); ++i) for(int j=0;j<A.size();++j)
    //         counts[A[i]&A[j]]++;
    //     for(int i=0; i<A.size(); ++i) for(auto& [k,v] : counts)
    //         if((A[i] & k) == 0) res += v;
    //     return res;
    // }

    int countTriplets(vector<int>& A)
    {
        int arr[1<<16]={0},res=0,mx=-1;
        for(int a:A) for(int b:A)
        {
            int t=a&b;
            arr[t]++;
            mx=max(mx,t);
        }
        for(int a:A) for(int j=0;j<=mx;j++)
        {
            if(a&j)  j += (a & j)-1;
            else res += arr[j];
        }
        return res;
    }
};
// @lc code=end
// [1,1,2,3]
