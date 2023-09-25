/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    vector<ListNode*> data;
public:
    Solution(ListNode* head) {
        while(head){
            data.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        return data[rand()%data.size()]->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

