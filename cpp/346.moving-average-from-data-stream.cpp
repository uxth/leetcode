/*
Question
Formatted question description: https://leetcode.ca/all/346.html

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
 

Example 1:

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
 

Constraints:

1 <= size <= 1000
-105 <= val <= 105
At most 104 calls will be made to next.
Algorithm
This first-in, first-out feature is most suitable for using queues, and we also need a double variable sum to record the sum of all current numbers.

After entering this new number,

If the limit is not exceeded, sum plus this number,
If it exceeds, then sum first subtracts the earliest number, then adds this number, and then returns the number of sum divided by the queue
*/

// OJ: https://leetcode.com/problems/moving-average-from-data-stream/
// Time:
//     MovingAverage: O(1)
//     next: O(1)
// Space: O(S)
class MovingAverage {
private:
    queue<int> q;
    int size, sum = 0;
public:
    MovingAverage(int size) : size(size) { }
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return (double)sum / q.size();
    }
};