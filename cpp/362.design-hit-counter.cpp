/*

Question
Formatted question description: https://leetcode.ca/all/362.html

Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the HitCounter class:

HitCounter() Initializes the object of the hit counter system.
void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).
 

Example 1:

Input
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
Output
[null, null, null, null, 3, null, 4, 3]

Explanation
HitCounter hitCounter = new HitCounter();
hitCounter.hit(1);       // hit at timestamp 1.
hitCounter.hit(2);       // hit at timestamp 2.
hitCounter.hit(3);       // hit at timestamp 3.
hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
hitCounter.hit(300);     // hit at timestamp 300.
hitCounter.getHits(300); // get hits at timestamp 300, return 4.
hitCounter.getHits(301); // get hits at timestamp 301, return 3.
 

Constraints:

1 <= timestamp <= 2 * 109
All the calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing).
At most 300 calls will be made to hit and getHits.
 

Follow up: What if the number of hits per second could be huge? Does your design scale?

Algorithm
Use a queue, add the current timestamp to the queue every time you click, and then when you need to get the number of clicks, we start from the beginning of the queue,

If the time stamp at the beginning is beyond 5 minutes, delete it until the time stamp at the beginning stops within 5 minutes
Then the number of elements returned to the queue is the requested number of clicks
Follow-up question
Two one-dimensional arrays times[] and hits[] with a size of 300 are defined, which are used to store timestamps and hits respectively.

In the click function, take the time stamp to 300, and then check whether the previously saved time stamp in this position is the same as the current time stamp. It also means that it is the same time stamp, then the corresponding number of clicks will increase by 1, if not the same, it means that five minutes have passed, then reset the corresponding number of clicks to 1.

Then when returning the number of hits, we need to traverse the times array to find all the positions within 5 minutes, and then add up the number of clicks in the corresponding positions in hits.

Need further clarify:
real-time getHits() ?
batch off-line process, then getHits() ?
1st thought is map reduce, distribute to multiple hosts, so when getHits() need a broadcast to collect all data

options: 1. use a lock 2. equal distribution each machine works independently to count its own users from the past minute. When we request the global number, we just need to add all counters together.

*/

// OJ: https://leetcode.com/problems/design-hit-counter/
// Time:
//      HitCounter: O(1)
//      hit, getHits: amortized O(1)
// Space: O(N)
class HitCounter {
    queue<int> q;
    void clear(int timestamp) {
        int start = timestamp - 300;
        while (q.size() && q.front() <= start) q.pop();
    }
public:
    HitCounter() {}
    void hit(int timestamp) {
        clear(timestamp);
        q.push(timestamp);
    }
    int getHits(int timestamp) {
        clear(timestamp);
        return q.size();
    }
};