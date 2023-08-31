/*
 * @lc app=leetcode id=1494 lang=cpp
 *
 * [1494] Parallel Courses II
 *
 * https://leetcode.com/problems/parallel-courses-ii/description/
 *
 * algorithms
 * Hard (32.20%)
 * Likes:    218
 * Dislikes: 26
 * Total Accepted:    4.2K
 * Total Submissions: 13.5K
 * Testcase Example:  '4\n[[2,1],[3,1],[1,4]]\n2'
 *
 * Given the integer n representing the number of courses at some university
 * labeled from 1 to n, and the array dependencies where dependencies[i] = [xi,
 * yi]  represents a prerequisite relationship, that is, the course xi must be
 * taken before the course yi.  Also, you are given the integer k.
 * 
 * In one semester you can take at most k courses as long as you have taken all
 * the prerequisites for the courses you are taking.
 * 
 * Return the minimum number of semesters to take all courses. It is guaranteed
 * that you can take all courses in some way.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, dependencies = [[2,1],[3,1],[1,4]], k = 2
 * Output: 3 
 * Explanation: The figure above represents the given graph. In this case we
 * can take courses 2 and 3 in the first semester, then take course 1 in the
 * second semester and finally take course 4 in the third semester.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 5, dependencies = [[2,1],[3,1],[4,1],[1,5]], k = 2
 * Output: 4 
 * Explanation: The figure above represents the given graph. In this case one
 * optimal way to take all courses is: take courses 2 and 3 in the first
 * semester and take course 4 in the second semester, then take course 1 in the
 * third semester and finally take course 5 in the fourth semester.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 11, dependencies = [], k = 2
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 15
 * 1 <= k <= n
 * 0 <= dependencies.length <= n * (n-1) / 2
 * dependencies[i].length == 2
 * 1 <= xi, yi <= n
 * xi != yi
 * All prerequisite relationships are distinct, that is, dependencies[i] !=
 * dependencies[j].
 * The given graph is a directed acyclic graph.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getK(vector<int>& degree, int k)
    {
        vector<vector<int>> data{{}};
        int maxsize = 0;
        for(int i=1; i<degree.size(); ++i)
        {
            if(degree[i]!=0) continue;
            int size = data.size();
            for(int j=0; j<size; ++j)
            {
                if(data[j].size() >= k) continue;
                vector<int> temp = data[j];
                temp.push_back(i);
                maxsize = max(maxsize, (int)temp.size());
                data.push_back(temp);
            }
        }
        vector<vector<int>> res;
        for(auto& i : data)if(i.size()==maxsize)res.push_back(i);
        return res;
    }
    void dfs(unordered_map<int, vector<int>>& con, vector<int>& degree, int k, int step, int& res)
    {
        for(auto& s : getK(degree, k))
        {
            for(int next : s)
            {
                degree[next]--;
                for(int n : con[next]) {--degree[n];}
            }
            if(all_of(degree.begin(), degree.end(), [](int i){return i<=0;}))
            {
                res = min(res, step + (int)ceil((float) count(degree.begin(), degree.end(), 0) / k));
                for(int next : s)
                {
                    for(int n : con[next]) {++degree[n];}
                    degree[next]++;
                }
                return;
            }
            dfs(con, degree, k, step+1, res);
            
            for(int next : s)
            {
                for(int n : con[next]) {++degree[n];}
                degree[next]++;
            }
        }
        return;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        unordered_map<int, vector<int>> con;
        vector<int> degree(n+1, 0);
        degree[0] = -1;
        for(auto& i : dependencies)
        {
            con[i[0]].push_back(i[1]);
            degree[i[1]]++;
        }
        if(all_of(degree.begin(), degree.end(), [](int i){return i<=0;}))
        {
            return ceil((float) count(degree.begin(), degree.end(), 0) / k);
        }
        int res = INT_MAX;
        dfs(con, degree, k, 1, res);
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
// 5\n[[2,1],[3,1],[4,1],[1,5]]\n2
// 11\n[]\n2
// 12\n[[1,2],[1,3],[7,5],[7,6],[4,8],[8,9],[9,10],[10,11],[11,12]]\n2
// 5\n[[5,1],[3,1],[5,4],[4,1],[2,3]]\n3
// 12\n[[1,2],[2,3],[4,5],[5,6],[7,8],[8,9],[10,11],[11,12]]\n3
// 12\n[[11,10],[6,3],[2,5],[9,2],[4,12],[8,7],[9,5],[6,2],[7,2],[7,4],[9,3],[11,1],[4,3]]\n3

// 11\n[[1,2],[2,3],[3,4],[5,8],[5,9],[5,10],[5,11],[6,8],[6,9],[6,10],[6,11],[7,8],[7,9],[7,10],[7,11]]\n3

// 15\n[[2,1]]\n4

// 5\n[[2,1],[3,1],[4,1],[1,5]]\n2
// 5\n[[3,1]]\n4

// 12\n[[1,2],[1,3],[7,5],[7,6],[4,8],[8,9],[9,10],[10,11],[11,12]]\n2