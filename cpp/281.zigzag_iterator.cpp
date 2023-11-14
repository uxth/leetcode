/*

Question
Formatted question description: https://leetcode.ca/all/281.html

Given two vectors of integers v1 and v2, implement an iterator to return their elements alternately.

Implement the ZigzagIterator class:

ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two vectors v1 and v2.
boolean hasNext() returns true if the iterator still has elements, and false otherwise.
int next() returns the current element of the iterator and moves the iterator to the next element.
 

Example 1:

Input: v1 = [1,2], v2 = [3,4,5,6]
Output: [1,3,2,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,3,2,4,5,6].
Example 2:

Input: v1 = [1], v2 = []
Output: [1]
Example 3:

Input: v1 = [], v2 = [1]
Output: [1]
 

Constraints:

0 <= v1.length, v2.length <= 1000
1 <= v1.length + v2.length <= 2000
-231 <= v1[i], v2[i] <= 231 - 1
 

Follow up: What if you are given k vectors? How well can your code be extended to such cases?

Clarification for the follow-up question:

The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic".

Follow-up Example:

Input: v1 = [1,2,3], v2 = [4,5,6,7], v3 = [8,9]
Output: [1,4,8,2,5,9,3,6,7]
Algorithm
Extra space to save
For class initialization, the two arrays are stored in another one-bit array in the order of zigzag, then the values in the new array are printed in order.

need extra space
No extra space
Use two variables i and j to record the current element positions of the two vectors, and initialize them to 0.

Then when i<=j, it means that you need to print the elements of v1 array, otherwise, print the elements of v2 array.

In the hasNext() function, when i or j is printed equal to the length of the corresponding array, assign it to an extra large value, which does not affect the printing of the value of the other array, only when i and j both exceed the length of the lattice array, return false.

Follow up, K iterators
Queue to hold a pair of iterators/indexes. During initialization, add iterator/index pairs and put them in the queue for every iterator. At initialization, each pair stores the the first and last index of the iterator.

In the next() function, take out a pair at the head of the queue. If the current iterator is not equal to end(), store the pari (iterator and the next index) to the queue, and then return the value at the current index.

In the hasNext() function, you only need to see if the queue is empty.
*/

// OJ: https://leetcode.com/problems/zigzag-iterator/
// Time:
//   ZigzagIterator: O(K)
//   next: O(1)
//   hasNext: O(1)
// Space: O(K) where K is the number of input vectors
class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.begin() != v1.end()) q.push(make_pair(v1.begin(), v1.end()));
        if (v2.begin() != v2.end()) q.push(make_pair(v2.begin(), v2.end()));
    }
    int next() {
        auto p = q.front();
        q.pop();
        int val = *p.first;
        p.first++;
        if (p.first != p.second) q.push(p);
        return val;
    }
    bool hasNext() {
        return q.size();
    }
};