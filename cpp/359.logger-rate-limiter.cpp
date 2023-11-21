/*
Question
Formatted question description: https://leetcode.ca/all/359.html

Design a logger system that receives a stream of messages along with their timestamps. Each unique message should only be printed at most every 10 seconds (i.e. a message printed at timestamp t will prevent other identical messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several messages may arrive at the same timestamp.

Implement the Logger class:

Logger() Initializes the logger object.
bool shouldPrintMessage(int timestamp, string message) Returns true if the message should be printed in the given timestamp, otherwise returns false.
 

Example 1:

Input
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
Output
[null, true, true, false, false, false, true]

Explanation
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 < 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 < 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 < 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 >= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
 

Constraints:

0 <= timestamp <= 109
Every timestamp will be passed in non-decreasing order (chronological order).
1 <= message.length <= 30
At most 104 calls will be made to shouldPrintMessage.
Algorithm
Use a hash table to create a mapping between the message and the timestamp,

If a message is no longer in the hash table, we create a mapping between it and the timestamp and return true.
If it is in the hash table, we see if the current timestamp is 10 greater than the timestamp stored in the hash table,
If yes, update the hash table and return true
Otherwise, return false
*/

// OJ: https://leetcode.com/problems/logger-rate-limiter/
// Time: O(1)
// Space: O(M)
class Logger {
private:
    unordered_map<string, int> m;
public:
    Logger() {}
    bool shouldPrintMessage(int timestamp, string message) {
        bool ans = m.find(message) == m.end() || timestamp - m[message] >= 10;
        if (ans) m[message] = timestamp;
        return ans;
    }
};