/*
Question
Formatted question description: https://leetcode.ca/all/252.html

Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106
Algorithm
To find whether there is an intersection of intervals, the easiest way is to compare every two intervals to see if there is an overlap. If so, just return false.

Compare whether there is overlap between the two intervals a and b, you can detect two cases,

If the start position of a is greater than or equal to the start position of b, and the start position of a is less than the end position of b, there must be overlap,
Another situation is that a and b exchange positions. If the start position of b is greater than or equal to the start position of a, and the start position of b is less than the end position of a, then there must be overlap

*/

// OJ: https://leetcode.com/problems/meeting-rooms/
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](Interval &a, Interval &b) {
            return a.start < b.start;
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }
        return true;
    }
};