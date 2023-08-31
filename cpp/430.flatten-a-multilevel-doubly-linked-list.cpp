/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    Node* tail;
public:
    void helper(Node* head) {
        if(head==nullptr) return;
        Node* next = head->next;
        Node* child = head->child;
        head->prev = head->next = head->child = nullptr;
        tail->next = head;
        head->prev = tail;
        tail = head;
        helper(child);
        helper(next);

    }
    Node* dfs(Node* head) {
        if(head==nullptr) return head;
        tail = new Node();
        Node* res = tail;
        helper(head);
        res->next->prev = nullptr;
        return res->next;
    }
    Node* bfs(Node* head) {
        stack<Node*> pending;
        for( Node *cur = head ; cur != NULL ; cur = cur->next ){
            
            if( cur->child ){
                if( cur->next )
                    pending.push(cur->next);
                cur->next = cur->child;
                if( cur->next ){
                    cur->next->prev = cur;
                }
                cur->child = NULL;
            }
            else if( cur->next == NULL && pending.size() != 0 ){
                cur->next = pending.top();
                pending.pop();
                if( cur->next ){
                    cur->next->prev = cur;
                }
            }
            
        }
        
        return head;
    }
    Node* flatten(Node* head) {
        // return bfs(head);
        return dfs(head);
    }
};
// @lc code=end

