/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 *
 * https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/
 *
 * algorithms
 * Hard (49.55%)
 * Likes:    952
 * Dislikes: 97
 * Total Accepted:    31.5K
 * Total Submissions: 63.3K
 * Testcase Example:  '[10,20,5]\n[70,50,30]\n2'
 *
 * There are N workers.  The i-th worker has a quality[i] and a minimum wage
 * expectation wage[i].
 * 
 * Now we want to hire exactly K workers to form a paid group.  When hiring a
 * group of K workers, we must pay them according to the following rules:
 * 
 * 
 * Every worker in the paid group should be paid in the ratio of their quality
 * compared to other workers in the paid group.
 * Every worker in the paid group must be paid at least their minimum wage
 * expectation.
 * 
 * 
 * Return the least amount of money needed to form a paid group satisfying the
 * above conditions.
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
 * Input: quality = [10,20,5], wage = [70,50,30], K = 2
 * Output: 105.00000
 * Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
 * Output: 30.66667
 * Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers
 * seperately. 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= N <= 10000, where N = quality.length = wage.length
 * 1 <= quality[i] <= 10000
 * 1 <= wage[i] <= 10000
 * Answers within 10^-5 of the correct answer will be considered correct.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<vector<double>> workers;
        for (int i = 0; i < quality.size(); ++i)
            workers.push_back({(double)(wage[i]) / quality[i], (double)quality[i]});
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker: workers) {
            qsum += worker[1], pq.push(worker[1]);
            if (pq.size() > K) qsum -= pq.top(), pq.pop();
            if (pq.size() == K) res = min(res, qsum * worker[0]);
        }
        return res;
    }
};
// @lc code=end
// [3,1,10,10,1]\n[4,8,2,2,7]\n3
// [86,15,92,47,63,12,99,54,6,16,52,28,86,38,73,16,52,37,30,84,81,46,97,84,17,21,14,52,19,74,20,20,56,89,7,34,21,75,6,93,30,5,13,19,98,46,16,9,10,29]\n[281,29,346,275,475,466,233,15,148,206,143,370,47,52,72,403,259,116,286,380,293,92,330,128,432,233,161,479,9,335,258,263,427,58,177,8,204,173,261,319,448,268,420,492,335,42,401,500,256,328]\n10