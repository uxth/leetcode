/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (55.48%)
 * Likes:    5474
 * Dislikes: 630
 * Total Accepted:    379.6K
 * Total Submissions: 678.7K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 * 
 * There is only one duplicate number in nums, return this duplicate number.
 * 
 * Follow-ups:
 * 
 * 
 * How can we prove that at least one duplicate number must exist in nums? 
 * Can you solve the problem without modifying the array nums?
 * Can you solve the problem using only constant, O(1) extra space?
 * Can you solve the problem with runtime complexity less than O(n^2)?
 * 
 * 
 * 
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 * Example 3:
 * Input: nums = [1,1]
 * Output: 1
 * Example 4:
 * Input: nums = [1,1,2]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 3 * 10^4
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer
 * which appears two or more times.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int hashSet(vector<int>& nums){
        unordered_set<int> s;
        for(int i : nums){
            if(s.count(i)) return i;
            s.insert(i);
        }
        return -1;
    }
    int hashMap(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i : nums)if(++m[i]>=2)return i;
        return -1;
    }
    int markingVisited(vector<int>& nums){
        int n = nums.size();
        for(int i : nums){
            int idx = abs(i);
            if(nums[idx] < 0) return idx;
            nums[idx] = -nums[idx];
        }
        return -1;
    }
    int sorting(vector<int>& nums){
        sort(begin(nums), end(nums));
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] == nums[i-1]) return nums[i];
        }
        return -1;
    }
    int indexSort(vector<int>& nums){
        int len = nums.size();
        for (int i = 0; i < len; ) {
            int n = nums[i];
            if (n == i + 1) {
                i++;
            } else if (n == nums[n - 1]) {
                return n;
            } else {
                nums[i] = nums[n - 1];
                nums[n - 1] = n;
            }
        }
        return -1;
    }
    int binarySearch(vector<int>& nums){
        int len = nums.size();
        int low = 1;
        int high = len - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }

            if (cnt <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;       
    }
    int bitMask(vector<int>& nums){
        int n = nums.size();
        int ans = 0;
        int bit_max = 31;
        while (((n - 1) >> bit_max) == 0) {
            bit_max -= 1;
        }

        for (int bit = 0; bit <= bit_max; ++bit) {
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i) {
                if ((nums[i] & (1 << bit)) != 0) {
                    x += 1;
                }
                if (i >= 1 && ((i & (1 << bit)) != 0)) {
                    y += 1;
                }
            }
            if (x > y) {
                ans |= 1 << bit;
            }
        }

        return ans;
    }
    int fastSlowPointers(vector<int>& nums){
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    int findDuplicate(vector<int>& nums) {
        // return hashMap(nums);
        // return hashSet(nums);
        // return markingVisited(nums);
        // return sorting(nums);
        // return indexSort(nums);
        // return binarySearch(nums);
        // return bitMask(nums);
        return fastSlowPointers(nums);
    }
};
// @lc code=end

