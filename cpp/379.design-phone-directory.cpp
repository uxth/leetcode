/*

Question
Formatted question description: https://leetcode.ca/all/379.html

Design a phone directory that initially has maxNumbers empty slots that can store numbers. The directory should store numbers, check if a certain slot is empty or not, and empty a given slot.

Implement the PhoneDirectory class:

PhoneDirectory(int maxNumbers) Initializes the phone directory with the number of available slots maxNumbers.
int get() Provides a number that is not assigned to anyone. Returns -1 if no number is available.
bool check(int number) Returns true if the slot number is available and false otherwise.
void release(int number) Recycles or releases the slot number.
 

Example 1:

Input
["PhoneDirectory", "get", "get", "check", "get", "check", "release", "check"]
[[3], [], [], [2], [], [2], [2], [2]]
Output
[null, 0, 1, true, 2, false, null, true]

Explanation
PhoneDirectory phoneDirectory = new PhoneDirectory(3);
phoneDirectory.get();      // It can return any available phone number. Here we assume it returns 0.
phoneDirectory.get();      // Assume it returns 1.
phoneDirectory.check(2);   // The number 2 is available, so return true.
phoneDirectory.get();      // It returns 2, the only number that is left.
phoneDirectory.check(2);   // The number 2 is no longer available, so return false.
phoneDirectory.release(2); // Release number 2 back to the pool.
phoneDirectory.check(2);   // Number 2 is available again, return true.
 

Constraints:

1 <= maxNumbers <= 104
0 <= number < maxNumbers
At most 2 * 104 calls will be made to get, check, and release.
Algorithm
Since numbers are to be allocated, an array nums is definitely needed to store all the numbers that can be allocated. Note that it must be initialized to different numbers. Then use an array of equal length used to mark whether the number at a certain position has been used, and use a variable idx to indicate the position currently allocated.

In the get() function, first judge

If idx is less than 0, it means that no number can be allocated, and -1 is returned.
Otherwise, take out nums[idx] and mark that the number has been used. Note that idx will also be decremented by 1, and return to the previously taken number.
For the check() function, directly check whether the corresponding value is 0 in the used function.

Finally, implement the release() function. If the number has not been used, return directly; otherwise, increment idx by 1, and assign the number to nums[idx], and then mark it as 0 in used

Another Algorithm, lightweighted.
A Phone Directory can be designed using an array and a queue. The array stores whether a number is available. The queue stores the numbers that are not assigned to anyone.

In the constructor, initialize the array and the queue. Initially, all elements in the array are true, and all numbers from 0 to maxNumbers - 1 are offered to the queue.

For operation get, check whether the queue is empty or not. If the queue is empty, then there is no available number, so return -1. If the queue is not empty, then poll a number from the queue, set the state of the polled number in the array to false, and return the number.

For operation check, simply check the array to see whether the number is available or not. If the number is out of bound (less than 0 or greater than or equal to maxNumbers), then return false directly.

For operation release, there is a trick that should pay attention to. It is possible to release a number that is already available, so if the number is already available, do not do any operation. Only if the number is used, it should be released. Offer the number to the queue and set the state of the number in the array to true.

*/

// OJ: https://leetcode.com/problems/design-phone-directory/
// Time: O(1)
// Space: O(N)
class PhoneDirectory {
private:
    unordered_set<int> pool;
public:
    PhoneDirectory(int maxNumbers) {
        while (maxNumbers--) pool.insert(maxNumbers);
    }
    int get() {
        if (pool.empty()) return -1;
        int ans = *pool.begin();
        pool.erase(pool.begin());
        return ans;
    }
    bool check(int number) {
        return pool.find(number) != pool.end();
    }
    void release(int number) {
        if (check(number)) return;
        pool.insert(number);
    }
};