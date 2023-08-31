/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (40.08%)
 * Likes:    4671
 * Dislikes: 424
 * Total Accepted:    561.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
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
    // bool isPalindrome(ListNode* head) {
    //     vector<int> data;
    //     ListNode* h = head;
    //     while(h)
    //     {
    //         data.push_back(h->val);
    //         h=h->next;
    //     }
    //     for(int i=0,j=data.size()-1; i<j; ++i,--j)
    //         if(data[i]!=data[j]) return false;
    //     return true;
    // }

    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* h = head;
        while(h){n++;h=h->next;}
        h = head;
        ListNode* dummy = new ListNode(0);
        for(int i=0;i<n/2;++i)
        {
            ListNode* tmp = h->next;
            h->next = dummy->next;
            dummy->next = h;
            h = tmp;
        }
        ListNode* a = dummy->next;
        ListNode* b = n%2==1? h->next: h;
        while(a && b)
        {
            if(a->val != b->val) return false;
            a=a->next;
            b=b->next;
        }
        return true;
    }
};
// @lc code=end

