/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (54.52%)
 * Likes:    1559
 * Dislikes: 160
 * Total Accepted:    168K
 * Total Submissions: 307.3K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
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
    ListNode* reverse(ListNode* l, int& len)
    {
        ListNode* dummy = new ListNode(0);
        while(l)
        {
            ListNode* next = l->next;
            l->next = dummy->next;
            dummy->next = l;
            l = next;
            len++;
        }
        return dummy->next;
    }
    ListNode* addNumbers2(ListNode* l1, ListNode* l2)
    {
        if(l1==nullptr || l2==nullptr) return l1 == nullptr ? l2 : l1;
        int len1 = 0, len2 = 0;
        l1 = reverse(l1, len1);
        l2 = reverse(l2, len2);
        if(len2 > len1) swap(l1, l2);
        ListNode* h1 = l1;
        int carry = 0;
        while(l1 || l2)
        {
            int num = carry;
            num+=l1->val;
            if(l2) num+=l2->val;
            carry = num / 10;
            l1->val = num % 10;
            l1=l1->next;
            if(l2) l2 = l2->next;
        }
        ListNode* res = reverse(h1, len1);
        
        if(carry)
        {
            ListNode* temp = new ListNode(carry);
            temp->next = res;
            res = temp;
        }
        return res;
    }
    ListNode* addNumbers(ListNode* l1, ListNode* l2)
    {
        stack<ListNode*> s1, s2;
        ListNode* t = l1;
        while(t) {s1.push(t); t=t->next;}
        t = l2;
        while(t) {s2.push(t); t=t->next;}
        int carry = 0;
        if(s1.size()<s2.size())
            {swap(s1, s2);swap(l1,l2);}
        while(!s1.empty())
        {
            int b = 0;
            if(!s2.empty())
            {
                b = s2.top()->val;
                s2.pop();
            }
            int a = s1.top()->val; 
            s1.top()->val = (a+b+carry)%10;
            carry = (a+b+carry)/10;
            s1.pop();
        }
        ListNode* res = l1;
        if(carry)
        {
            res = new ListNode(carry);
            res->next = l1;
        }

        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return addNumbers(l1, l2);
        return addNumbers2(l1, l2);
    }
};
// @lc code=end

