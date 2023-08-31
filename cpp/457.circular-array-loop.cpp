/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 *
 * https://leetcode.com/problems/circular-array-loop/description/
 *
 * algorithms
 * Medium (29.37%)
 * Likes:    388
 * Dislikes: 1337
 * Total Accepted:    35.5K
 * Total Submissions: 120.7K
 * Testcase Example:  '[2,-1,1,2,2]'
 *
 * You are given a circular array nums of positive and negative integers. If a
 * number k at an index is positive, then move forward k steps. Conversely, if
 * it's negative (-k), move backward k steps. Since the array is circular, you
 * may assume that the last element's next element is the first element, and
 * the first element's previous element is the last element.
 * 
 * Determine if there is a loop (or a cycle) in nums. A cycle must start and
 * end at the same index and the cycle's length > 1. Furthermore, movements in
 * a cycle must all follow a single direction. In other words, a cycle must not
 * consist of both forward and backward movements.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,-1,1,2,2]
 * Output: true
 * Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's
 * length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,2]
 * Output: false
 * Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because
 * the cycle's length is 1. By definition the cycle's length must be greater
 * than 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [-2,1,-1,-2,-2]
 * Output: false
 * Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle,
 * because movement from index 1 -> 2 is a forward movement, but movement from
 * index 2 -> 1 is a backward movement. All movements in a cycle must follow a
 * single direction.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * -1000 ≤ nums[i] ≤ 1000
 * nums[i] ≠ 0
 * 1 ≤ nums.length ≤ 5000
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * Could you solve it in O(n) time complexity and O(1) extra space complexity?
 */

// @lc code=start
class Solution {
public:
    int next(vector<int>& nums, int i){
        int n = nums.size();
        return (n+nums[i]+i)%n;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        // we can use slow and fast pointer to check whether there is loop or not
        for(int &num: nums)
            num %= n;
        for(int i=0;i<n;i++){
            int slow = i,
                fast = i;
            while(nums[slow]*nums[next(nums,fast)]>0 && nums[slow]*nums[next(nums,next(nums,fast))]>0){
                slow = next(nums,slow);
                fast = next(nums,next(nums,fast));
                if(slow==fast){
                    if(slow==next(nums,slow)) // single length
                        return false;
                    return true;
                }
            }
			/// DONOT TRAVERSE WHERE THERE IS NO PATH TO GET LOOP.
            int j = i;
            int val = nums[i];
            while (nums[j] * val > 0) {
                int nexx = next(nums,j);
                nums[j] = 0;
                j = nexx;
            }
        }
        
        return false;
    }
};
// @lc code=end

