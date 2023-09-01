#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#

# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res, prod = -math.inf, 1
        for _, v in enumerate(nums):
            prod *= v
            res = max(res, prod)
            if prod == 0:
                prod = 1
        prod = 1
        for _, v in enumerate(reversed(nums)):
            prod *= v
            res = max(res, prod)
            if prod == 0:
                prod = 1
        return res
# @lc code=end

