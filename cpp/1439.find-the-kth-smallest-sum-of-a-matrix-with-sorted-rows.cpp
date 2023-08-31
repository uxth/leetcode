/*
 * @lc app=leetcode id=1439 lang=cpp
 *
 * [1439] Find the Kth Smallest Sum of a Matrix With Sorted Rows
 *
 * https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/
 *
 * algorithms
 * Hard (59.91%)
 * Likes:    436
 * Dislikes: 5
 * Total Accepted:    13.1K
 * Total Submissions: 21.9K
 * Testcase Example:  '[[1,3,11],[2,4,6]]\n5'
 *
 * You are given an m * n matrix, mat, and an integer k, which has its rows
 * sorted in non-decreasing order.
 * 
 * You are allowed to choose exactly 1 element from each row to form an array.
 * Return the Kth smallest array sum among all possible arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,3,11],[2,4,6]], k = 5
 * Output: 7
 * Explanation: Choosing one element from each row, the first k smallest sum
 * are:
 * [1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1,3,11],[2,4,6]], k = 9
 * Output: 17
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
 * Output: 9
 * Explanation: Choosing one element from each row, the first k smallest sum
 * are:
 * [1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th
 * sum is 9.  
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: mat = [[1,1,10],[2,2,9]], k = 7
 * Output: 12
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat.length[i]
 * 1 <= m, n <= 40
 * 1 <= k <= min(200, n ^ m)
 * 1 <= mat[i][j] <= 5000
 * mat[i] is a non decreasing array.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string hash(vector<int>& index)
    {
        string res = to_string(index[0]);
        for(int i=1; i<index.size(); ++i) res += ',' + to_string(index[i]);
        return res;
    }
    int bfs(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>> > pq;
        int n = mat.size();
        int sum = 0;
        for(int i=0;i<n; ++i) sum+=mat[i][0];
        vector<int> init(n, 0);
        pq.push({sum, init});
        unordered_set<string> visited;
        vector<int> res;
        while(res.size()<k)
        {
            int s = pq.top().first;
            auto index = pq.top().second;
            pq.pop();

            string hashcode = hash(index);
            if(visited.count(hashcode)) continue;
            visited.insert(hashcode);
            res.push_back(s);
            for(int i=0; i<n; ++i)
            {
                if(index[i]+1>=mat[i].size()) continue;
                vector<int> newindex = index;
                newindex[i]++;
                
                int newsum = s + mat[i][index[i]+1] - mat[i][index[i]];
                pq.push({newsum, newindex});
            }
        }
        return res.back();
    }
    

    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        // return bfs(mat, k);
        return bs(mat, k);
    }
    int bs(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        int left=m,right=m*5000;
        while(left<right){
            int mid=left+(right-left)/2;
            int cnt=findcnt(mat,m,n,0,mid,k);
            if(cnt<k)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
    int findcnt(vector<vector<int>>& mat,int &m,int &n,int r,int target,int k){
        if(target<0)return 0;
        if(m==r)return 1;
        int res=0;
        for(int i=0;i<n;i++){
            target-=mat[r][i];
            int cnt = findcnt(mat,m,n,r+1,target,k-res);
            target+=mat[r][i];
            if(cnt==0)break;
            res+=cnt;
            if(res>k)break;
        }
        return res;
    }
};
// @lc code=end

