/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* res = new ListNode();
        while(head){
            ListNode* cur = res;
            while(cur->next && cur->next->val < head->val){
                cur = cur->next;
            }
            ListNode* t = head;
            head = head->next;
            t->next = cur->next;
            cur->next = t;
        }
        return res->next;
    }
};
// @lc code=end

