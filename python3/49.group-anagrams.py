#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map = defaultdict(list)
        for word in strs:
            key = ''.join(sorted(word))
            map[key].append(word)
        return list(map.values())
# @lc code=end

