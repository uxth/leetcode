/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 *
 * https://leetcode.com/problems/my-calendar-iii/description/
 *
 * algorithms
 * Hard (59.92%)
 * Likes:    377
 * Dislikes: 101
 * Total Accepted:    22.1K
 * Total Submissions: 36.6K
 * Testcase Example:  '["MyCalendarThree","book","book","book","book","book","book"]\n' +
  '[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]'
 *
 * Implement a MyCalendarThree class to store your events. A new event can
 * always be added.
 * 
 * Your class will have one method, book(int start, int end). Formally, this
 * represents a booking on the half open interval [start, end), the range of
 * real numbers x such that start <= x < end.
 * 
 * A K-booking happens when K events have some non-empty intersection (ie.,
 * there is some time that is common to all K events.)
 * 
 * For each call to the method MyCalendar.book, return an integer K
 * representing the largest integer such that there exists a K-booking in the
 * calendar.
 * Your class will be called like this: MyCalendarThree cal = new
 * MyCalendarThree(); MyCalendarThree.book(start, end)
 * 
 * Example 1:
 * 
 * 
 * MyCalendarThree();
 * MyCalendarThree.book(10, 20); // returns 1
 * MyCalendarThree.book(50, 60); // returns 1
 * MyCalendarThree.book(10, 40); // returns 2
 * MyCalendarThree.book(5, 15); // returns 3
 * MyCalendarThree.book(5, 10); // returns 3
 * MyCalendarThree.book(25, 55); // returns 3
 * Explanation: 
 * The first two events can be booked and are disjoint, so the maximum
 * K-booking is a 1-booking.
 * The third event [10, 40) intersects the first event, and the maximum
 * K-booking is a 2-booking.
 * The remaining events cause the maximum K-booking to be only a 3-booking.
 * Note that the last event locally causes a 2-booking, but the answer is still
 * 3 because
 * eg. [10, 20), [10, 40), and [5, 15) are still triple booked.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of calls to MyCalendarThree.book per test case will be at most
 * 400.
 * In calls to MyCalendarThree.book(start, end), start and end are integers in
 * the range [0, 10^9].
 * 
 * 
 * 
 */

// @lc code=start
// class MyCalendarThree{
// public:
//     MyCalendarThree() {
//         // Add -1 as a guardian entry, so later on we don't have to worry the --lower_bound(..) operation will cross the map's boundary.
//         events_.emplace(-1, 0);
//     }
    
//     int book(int start, int end) {
//         // Insert start event, copy existing event's count.
//         auto exist_ev = prev(events_.lower_bound(start));
//         auto start_it = events_.emplace(start, exist_ev->second).first; 
//         // Insert end event, copy existing event's count.
//         // Though the end point is exclusive, we should still copy previous event's count:
//         // Either it falls into some event's range, so the count should be this event's count;
//         // Or it's not in any existing event's range, so it should copy previous event's end point, hence 0.
//         // And we need end event in the map to let following event know the previous event has ended.
//         exist_ev = prev(events_.lower_bound(end));
//         auto end_it = events_.emplace(end, exist_ev->second).first;
//         for(auto it = start_it; it != end_it; it++){
//             count_ = max(count_, ++(it->second)); // increase the counter for all events inside the range, update max overbook count.
//         }
//         return count_;
//     }
    
// private:
//     map<int, int> events_;
//     int count_ = 0;
// };

class MyCalendarThree {
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        ++freq[start];
        --freq[end];
        int cnt = 0, mx = 0;
        for (auto f : freq) {
            cnt += f.second;
            mx = max(mx, cnt);
        }
        return mx;
    }
    
private:
    map<int, int> freq;
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

