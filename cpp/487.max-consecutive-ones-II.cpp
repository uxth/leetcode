/*

Question
Formatted question description: https://leetcode.ca/all/487.html

Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

 

Example 1:

Input: nums = [1,0,1,1,0]
Output: 4
Explanation: 
- If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3 consecutive ones.
The max number of consecutive ones is 4.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 4
Explanation: 
- If we flip the first zero, nums becomes [1,1,1,1,0,1] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1,1] and we have 4 consecutive ones.
The max number of consecutive ones is 4.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
 

Follow up: What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?

Algorithm
What if the question says that it can be flipped k times?

It is best to use a general solution to deal with this kind of problem. A window [left,right] can be maintained to hold at least k zeros. When it encounters 0, it accumulates the number of zero, and then judges if the number of 0 is greater than k at this time, then shifts the left boundary left to the right, and if the removed nums[left] is 0, then zero decrements by 1. If it is not greater than k, use the number of digits in the window to update res.

Follow up
The above method cannot be used in the case of follow up, because nums[left] needs to access the previous number. We can save all the positions of 0 we encountered in a queue, so that we know where to move when we need to move left.

*/

// OJ: https://leetcode.com/problems/max-consecutive-ones-ii/
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int zero = 0, i = 0, j = 0, N = A.size(), ans = 0;
        while (j < N) {
            zero += A[j++] == 0;
            while (zero > 1) zero -= A[i++] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};