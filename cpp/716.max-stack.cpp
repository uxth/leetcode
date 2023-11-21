/*

Description
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) – Push element x onto stack.
pop() – Remove the element on top of the stack and return it.
top() – Get the element on the top.
peekMax() – Retrieve the maximum element in the stack.
popMax() – Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:

MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:

-1e7 <= x <= 1e7
Number of operations won’t exceed 10000.
The last four operations won’t be called when stack is empty.
Solution
A stack supports push, pop, and top already, so only the last two operations need to be implemented. Use two stacks.

One stack works as the normal stack,
and the other stack which is called the maximum stack stores the maximum element so far.
Both stacks are initialized in the constructor. The other three functions should be modified as well.

The push() function. Push the element into the normal stack, and for the maximum stack, if the maximum stack is empty, then simply push the element into the maximum stack, otherwise push the maximum element between the current element and the element at the top of the maximum stack.

The pop() function. Simply pop both the normal stack and the maximum stack, and return the element popped from the normal stack.

The top() function. Simply return the top element of the normal stack.

The peekMax() function. Simply return the top element of the maximum stack. The reason why this works is that, each time the push function is called, the element pushed into the maximum stack is guaranteed to be the maximum element so far, so at any time, the top element of the maximum stack is the maximum element among all the elements pushed.

The popMax() function. This is a highly complex function that requires careful handling. Since the maximum element may not always be at the top of the normal stack, it may be necessary to first pop some elements from the normal stack in order to locate it. The top element of the normal stack is considered the maximum only if it is identical to the top element of the maximum stack. Once the maximum element has been popped, any other elements that were previously removed from the normal stack must be re-added. To accomplish this, a new stack is used to store all the popped elements until the maximum element is identified. Once the maximum element has been popped and retrieved, each element in the new stack must be pushed back onto the normal stack, to ensure that both the normal stack and the maximum stack contain the correct values.

*/


// OJ: https://leetcode.com/problems/max-stack/
// Time:
//      MaxStack, top, peekMax: O(1)
//      push: log(N)
//      pop, popMax: O(logN) amortized
// Space: O(N)
class MaxStack {
    map<int, vector<int>> m;
    vector<int> v;
    void pop(int n) {
        int i = m[n].back();
        v[i] = INT_MIN;
        m[n].pop_back();
        if (m[n].empty()) m.erase(n);
        while (v.size() && v.back() == INT_MIN) v.pop_back();
    }
public:
    MaxStack() {}
    void push(int x) {
        m[x].push_back(v.size());
        v.push_back(x);
    }
    int pop() {
        int n = v.back();
        pop(n);
        return n;
    }
    int top() {
        return v.back();
    }
    int peekMax() {
        return m.rbegin()->first;
    }
    int popMax() {
        int n = peekMax();
        pop(n);
        return n;
    }
};