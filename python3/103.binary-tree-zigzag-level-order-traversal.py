#
# @lc app=leetcode id=103 lang=python3
#
# [103] Binary Tree Zigzag Level Order Traversal
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if not root:
            return res
        import queue
        q = queue.Queue()
        q.put(root)
        level = 0
        while not q.empty():
            size = q.qsize()
            data = []
            for _ in range(size):
                f = q.get()
                data.append(f.val)
                if f.left:
                    q.put(f.left)
                if f.right:
                    q.put(f.right)
            if level % 2 == 1:
                data.reverse()
            res.append(data)
            level = level + 1
        return res


# @lc code=end

