#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#

# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        nums = set(nums)
        for num in nums:
            if num - 1 not in nums:
                next = num + 1
                while next in nums:
                    next += 1
                res = max(res, next-num)
        return res
# @lc code=end

