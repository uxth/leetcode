/*

Description
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined). Also, we wouldn’t include intervals like [5, 5] in our answer, as they have zero length.

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]

Output: [[3,4]]

Explanation: There are a total of three employees, and all common free time intervals would be [-inf, 1], [3, 4], [10, inf].

We discard any intervals that contain inf as they aren’t finite.

Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]

Output: [[5,6],[7,9]]

Constraints:

1 <= schedule.length , schedule[i].length <= 50
0 <= schedule[i].start < schedule[i].end <= 10^8
Solution
First, use a list to store all the intervals in schedule, and merge the overlapping intervals. This is done by first sorting the intervals in the list according to the start points in ascending order, then update the current interval’s end time once an overlapping interval is met, and add the merged intervals to a new list.

Next, loop over the new list that contains merged intervals, which are sorted. For each pair of adjacent intervals, use the first interval’s end time and the second interval’s start time to create an interval of free time and add the free time interval to the result list. Finally, return the result list.

*/

// OJ: https://leetcode.com/problems/employee-free-time/
// Time: O(NlogT + T) where N is the total number of intervals, and T is the total number of unique times.
// Space: O(T)
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> A) {
        map<int, int> m;
        for (auto &v : A) {
            for (auto &it : v) {
                m[it.start]++;
                m[it.end]--;
            }
        }
        vector<Interval> ans;
        int cnt = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            cnt += it->second;
            if (cnt) continue;
            int start = it->first;
            ++it;
            if (it == m.end()) break;
            cnt += it->second;
            ans.emplace_back(start, it->first);
        }
        return ans;
    }
};
