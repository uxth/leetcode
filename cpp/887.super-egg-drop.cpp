/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 *
 * https://leetcode.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (27.02%)
 * Likes:    1106
 * Dislikes: 91
 * Total Accepted:    24.3K
 * Total Submissions: 89.7K
 * Testcase Example:  '1\n2'
 *
 * You are given K eggs, and you have access to a building with N floors from 1
 * to N. 
 * 
 * Each egg is identical in function, and if an egg breaks, you cannot drop it
 * again.
 * 
 * You know that there exists a floor F with 0 <= F <= N such that any egg
 * dropped at a floor higher than F will break, and any egg dropped at or below
 * floor F will not break.
 * 
 * Each move, you may take an egg (if you have an unbroken one) and drop it
 * from any floor X (with 1 <= X <= N). 
 * 
 * Your goal is to know with certainty what the value of F is.
 * 
 * What is the minimum number of moves that you need to know with certainty
 * what F is, regardless of the initial value of F?
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: K = 1, N = 2
 * Output: 2
 * Explanation: 
 * Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 * Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty
 * that F = 1.
 * If it didn't break, then we know with certainty F = 2.
 * Hence, we needed 2 moves in the worst case to know what F is with
 * certainty.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: K = 2, N = 6
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: K = 3, N = 14
 * Output: 4
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= 100
 * 1 <= N <= 10000
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int bottomupdp(int K, int N)
    {
        vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
        for(int k = 0; k <= K; k++)
            dp[1][k] = 1;
        for(int n = 1; n <= N; n++)
            dp[n][1] = n;

        for(int n=2; n<=N; ++n) for(int k=2; k<=K; ++k)
        {
            dp[n][k] = INT_MAX;
            int low = 2; int high = n;
            while(low < high)
            {
                int mid = (low + high) / 2;
                if(dp[mid-1][k-1] > dp[n-mid][k]) high = mid-1;
                else if(dp[mid-1][k-1] < dp[n-mid][k]) low = mid + 1;
                else low=high=mid;
            }
            dp[n][k] = 1+max(dp[low-1][k-1], dp[n-low][k]);
        }
        return dp[N][K];
    }
    int dp(int K, int N)
    {
        int ans=0;
        vector<int> dp(K+1,0);
        while(dp[K]<N){
            ans++;
            for(int i=K;i>0;i--)
                dp[i]+=dp[i-1]+1;
        }
        return ans;
    }
    int dp2(int K, int N)
    {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1));
        int m = 0;
        while (dp[m][K] < N) {
            ++m;
            for (int j = 1; j <= K; ++j) {
                dp[m][j] = dp[m - 1][j - 1] + dp[m - 1][j] + 1;
                cout << dp[m][j] << " ";
            }
            cout << endl;
        }
        return m;
    }
    int superEggDrop(int K, int N) {
        // return bottomupdp(K, N);
        // return dp(K, N);
        return dp2(K, N);
    }
};

// @lc code=end

