/*
 * @lc app=leetcode id=1340 lang=cpp
 *
 * [1340] Jump Game V
 *
 * https://leetcode.com/problems/jump-game-v/description/
 *
 * algorithms
 * Hard (57.50%)
 * Likes:    226
 * Dislikes: 11
 * Total Accepted:    8.4K
 * Total Submissions: 14.6K
 * Testcase Example:  '[6,4,14,6,8,13,9,7,10,6,12]\n2'
 *
 * Given an array of integers arr and an integer d. In one step you can jump
 * from index i to index:
 * 
 * 
 * i + x where: i + x < arr.length and  0 < x <= d.
 * i - x where: i - x >= 0 and  0 < x <= d.
 * 
 * 
 * In addition, you can only jump from index i to index j if arr[i] > arr[j]
 * and arr[i] > arr[k] for all indices k between i and j (More formally min(i,
 * j) < k < max(i, j)).
 * 
 * You can choose any index of the array and start jumping. Return the maximum
 * number of indices you can visit.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
 * Output: 4
 * Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as
 * shown.
 * Note that if you start at index 6 you can only jump to index 7. You cannot
 * jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5
 * is between index 4 and 6 and 13 > 9.
 * Similarly You cannot jump from index 3 to index 2 or index 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [3,3,3,3,3], d = 3
 * Output: 1
 * Explanation: You can start at any index. You always cannot jump to any
 * index.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [7,6,5,4,3,2,1], d = 1
 * Output: 7
 * Explanation: Start at index 0. You can visit all the indicies. 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [7,1,7,1,7,1], d = 2
 * Output: 2
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: arr = [66], d = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 10^5
 * 1 <= d <= arr.length
 * 
 */

// @lc code=start
class Solution {
public:

    int dfs(vector<int>& arr,int d, int pos, vector<int>& dp)
    {
        if(pos < 0 || pos >= arr.size()) return 0;
        if(dp[pos] > 1) return dp[pos];
        int jump = 1;
        for(int i=pos+1; i<=pos+d && i<arr.size() && arr[pos] > arr[i]; ++i)
        {
            jump = max(jump, 1+dfs(arr, d, i, dp));
        }
        for(int i=pos-1; i>=pos-d && i>=0 && arr[pos] > arr[i]; --i)
        {
            jump = max(jump, 1+dfs(arr, d, i, dp));
        
        }
        dp[pos] = jump;
        return dp[pos];
    }
    int maxJumps(vector<int>& arr, int d)
    {
        vector<int> dp(arr.size(), 1);
        int res=0;
        for(int i=0;i<arr.size(); ++i) res = max(res, dfs(arr, d, i, dp));
        // for_each(dp.begin(), dp.end(), [](int i){cout << i << " ";}), cout << endl;
        return res;
    }
};
// @lc code=end
// [63186,44416,36598,66119,86981,18503,72119,18725,55969,61809,1162,37718,80080,67028,26351,54774,35181,38298,36051,21044,1812,17706,49172,74089,12962,16891,69116,60226,1632,36228,98750,97431,11255,34518,7546,83844,11070,7671,18202,91375,68788,74922,30853,35409,93789,59585,93743,82035,8622,62010,89821,19365,13904,98621,8545,35993,18123,32540,35168,33890,36558,38959,78579,87102,62818,52634,85444,95925,70864,64924,55626,5866,7196,97838,21331,19177,33301,58583,49501,36063,1094,93249,70981,15396,94021,48781,87816,33969,40732,5347,90117,80108,39049,98601,73617,23140,11076,21527,77200,93844,31499,55444,3062,76216,90734,91197,34641,99847,40920,21048,57171,98962,57269,3856,22489,98445,31160,96928,21253,59341,75140,29065,40686,40375,88314,26776,52078,86901,68171,66455,56329,48269,33780,12221,9510,49936,39391,81072,64501,65290,75183,83586,80643,1549,83715,11474,70941,47286,33601,69038,85654,33581,75828,17553,99364,31075,84500,66665,27854,73913,60405,12431,26839,54830,54897,81149,53553,71003,8977,44921,55393,48004,90065,67289,89537,28983,43004,89211,86241,8102,64886,29314,49867,1440,48346,95080,53703,97555,31798,36820,2253,72540,96272,71815,89461,11633,87729,8518,74700,90255,63607,96895,59185,50962,21770,34361,51307,50088,80217,14700,84829,14340,9295,67939,67700,78913,82184]\n170

// [3,3,3,3,3,3]\n3

// [7,6,5,4,3,2,1]\n1

//[6,4,14,6,8,13,9,7,10,6,12]\n2