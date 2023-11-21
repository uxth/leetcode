/*

Question
Formatted question description: https://leetcode.ca/all/360.html

Given a sorted integer array nums and three integers a, b and c, apply a quadratic function of the form f(x) = ax2 + bx + c to each element nums[i] in the array, and return the array in a sorted order.

 

Example 1:

Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
Example 2:

Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
 

Constraints:

1 <= nums.length <= 200
-100 <= nums[i], a, b, c <= 100
nums is sorted in ascending order.
 

Follow up: Could you solve it in O(n) time?

Algorithm
This question uses a lot of high school mathematical knowledge about parabola. We know that for an equation f(x) = ax2 + bx + c,

If a>0, the opening of the parabola is upward, and the value at both ends is greater than the middle,
If a<0, the opening of the parabola faces downward, and the values at both ends are smaller than the middle.
When a=0, it is a straight line method, which is monotonically increasing or decreasing.
Then we can use this property to solve the problem. The title shows that the given array nums is ordered. If it is not ordered, I think it is difficult to have an O(n) solution. Because the input array is in order, we can discuss the situation according to a:

When a>0, it means that the value at both ends is greater than the value in the middle. At this time, we fill in from the result after res, and use two pointers to point to the beginning and end of the nums array respectively. The two numbers pointed to are parabolic At the end of the number, the larger of them is stored at the end of res, and then the pointer is moved to the middle, and the comparison process is repeated until the res is filled.

When a<0, it means that the value at both ends is smaller than the middle, then we fill in from the front of res and use two pointers to point to the beginning and the end of the nums array respectively. The two numbers pointed to are the numbers at both ends of the parabola. The smaller number among them is first stored at the beginning of res, and then the pointer moves to the middle, and the comparison process is repeated until all res is filled.

When a=0, the function is monotonically increasing or decreasing, then fill in from front to back and fill in from back to front can be done, we can combine this situation with a>0

*/

// OJ: https://leetcode.com/problems/sort-transformed-array/
// Time: O(N)
// Space: O(1)
class Solution {
private:
    int eval(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        float mid = (float)-b / (2 * a);
        int j = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
        int i = j - 1, N = nums.size(), nil = a > 0 ? INT_MAX : INT_MIN;
        vector<int> ans(N);
        for (int k = 0; k < N; ++k) {
            int m = i >= 0 ? eval(nums[i], a, b, c) : nil;
            int n = j < N ? eval(nums[j], a, b, c) : nil;
            if (a > 0 ? m < n : n < m) {
                ans[k] = m;
                --i;
            } else {
                ans[k] = n;
                ++j;
            }
        }
        if (a < 0) reverse(ans.begin(), ans.end());
        return ans;
    }
};