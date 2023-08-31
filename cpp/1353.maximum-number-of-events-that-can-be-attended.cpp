/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 *
 * https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/
 *
 * algorithms
 * Medium (30.45%)
 * Likes:    473
 * Dislikes: 67
 * Total Accepted:    13.6K
 * Total Submissions: 45K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]\r'
 *
 * Given an array of events where events[i] = [startDayi, endDayi]. Every event
 * i starts at startDayi and ends at endDayi.
 * 
 * You can attend an event i at any day d where startTimei <= d <= endTimei.
 * Notice that you can only attend one event at any time d.
 * 
 * Return the maximum number of events you can attend.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: events = [[1,2],[2,3],[3,4]]
 * Output: 3
 * Explanation: You can attend all the three events.
 * One way to attend them all is as shown.
 * Attend the first event on day 1.
 * Attend the second event on day 2.
 * Attend the third event on day 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: events= [[1,2],[2,3],[3,4],[1,2]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: events = [[1,100000]]
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= events.length <= 10^5
 * events[i].length == 2
 * 1 <= events[i][0] <= events[i][1] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> data;
        int start=INT_MAX;
        int end=INT_MIN;
        for(auto& e : events) 
        {
            start=min(start, e[0]);
            end=max(end, e[1]);
            data[e[0]].push_back(e[1]);
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        int res = 0;
        for(int day=start; day<=end; ++day)
        {
            for(int i : data[day]) {pq.push(i);}
            while(!pq.empty() && pq.top()<day) pq.pop();
            if(!pq.empty())
            {
                pq.pop(); res++;
            }
        }
        return res;
    }
};
// @lc code=end
// [[1,4],[4,4],[2,2],[3,4],[1,1]]
// [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
// [[1,5],[1,5],[1,5],[2,3],[2,3]]