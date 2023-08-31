/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (55.68%)
 * Likes:    3228
 * Dislikes: 169
 * Total Accepted:    236.1K
 * Total Submissions: 422.2K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

// @lc code=start
class Solution {
public:
    int bfs(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        for(int i=0; i<matrix.size(); ++i) pq.push({matrix[i][0], {i,0}});
        vector<int> res;
        while(res.size() < k)
        {
            int val = pq.top().first;
            auto [i,j] = pq.top().second;
            pq.pop();
            res.push_back(val);
            if(j<matrix[i].size()-1)
                pq.push({matrix[i][j+1], {i,j+1}});
        }
        return res.back();
    }

    int getcount(vector<vector<int>> &matrix,int mid)
    {
        int i=matrix.size()-1,j=0,count=0;
        while(i>=0&j<matrix.size())
        {
            if(matrix[i][j]>mid)
                i--;
            else
            {
                count=count+i+1;
                j++;
            }
        }
        return count;
    }
    int bs(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1],ans=low;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(getcount(matrix,mid)>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        // return bfs(marix, k);
        return bs(matrix, k);
    }
};
// @lc code=end

