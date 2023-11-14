/*

Question
Formatted question description: https://leetcode.ca/all/325.html

Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. If there is not one, return 0 instead.

 

Example 1:

Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
 

Constraints:

1 <= nums.length <= 2 * 105
-104 <= nums[i] <= 104
-109 <= k <= 109
Algorithm
Need to use hash table and cumulative sum, then the benefit of establishing cumulative sum is obvious, if the current cumulative sum is exactly equal to k, then the sub-array from the beginning to this position is a satisfactory solution, but not necessarily the longest Sub-array, and use a hash table to establish the mapping between the cumulative sum and its coordinates, we analyze from the example given in the title:

nums: [1, -1, 5, -2, 3], k = 3

sums: [1, 0, 5, 3, 6]
We can see that the fourth number of the cumulative sum is 3, which is the same as k, which means that the first four numbers are a sub-array that meets the meaning of the question. Let’s look at the second example:

nums: [-2, -1, 2, 1], k = 1

sums: [-2, -3, -1, 0]
We find that no number in the cumulative sum is equal to k, but we know that the answer to this example is [-1, 2], then we look at the first and third numbers of the cumulative sum array, can we see some rules, no Wrong, the third number -1 is subtracted from k to get the first number. This is the law. This is also the method of accumulating and summing the interval. However, there may be repeated numbers in the accumulative sum array, and the key of the hash table The characters cannot be the same, such as the following example:

nums: [1, 0, -1], k = -1

sums: [1, 1, 0]
We found that the first and second numbers of the cumulative sum array are both 1, so how to create a mapping? What I think is to store them in a one-dimensional array, and then compare the first one in the array when comparing Number, when we build the hash table, we start to traverse the hash table. When the cumulative sum is the same as k, we update res. If it is not the same, we check whether the value obtained by subtracting k from the current value is stored in the hash table. Exist, update the result if it exists.

*/

// OJ: https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSubArrayLen(vector<int>& A, int k) {
        unordered_map<int, int> m{ {0,-1} }; // prefix sum -> first index
        int ans = 0;
        for (int i = 0, sum = 0; i < A.size(); ++i) {
            sum += A[i];
            int target = sum - k;
            if (m.count(target)) ans = max(ans, i - m[target]);
            if (m.count(sum) == 0) m[sum] = i;
        }
        return ans;
    }
};