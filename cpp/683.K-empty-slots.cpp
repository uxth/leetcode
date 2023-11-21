/*

Description
You have N bulbs in a row numbered from 1 to N. Initially, all the bulbs are turned off. We turn on exactly one bulb everyday until all bulbs are on after N days.

You are given an array bulbs of length N where bulbs[i] = x means that on the (i+1)th day, we will turn on the bulb at position x where i is 0-indexed and x is 1-indexed.

Given an integer K, find out the minimum day number such that there exists two turned on bulbs that have exactly K bulbs between them that are all turned off.

If there isn’t such day, return -1.

Example 1:

Input:

bulbs: [1,3,2]

K: 1

Output: 2

Explanation:

On the first day: bulbs[0] = 1, first bulb is turned on: [1,0,0]

On the second day: bulbs[1] = 3, third bulb is turned on: [1,0,1]

On the third day: bulbs[2] = 2, second bulb is turned on: [1,1,1]

We return 2 because on the second day, there were two on bulbs with one off bulb between them.

Example 2:

Input:

bulbs: [1,2,3]

K: 1

Output: -1

Note:

1 <= N <= 20000
1 <= bulbs[i] <= N
bulbs is a permutation of numbers from 1 to N.
0 <= K <= 20000
Solution
Create a class Interval that represents continuous intervals of turned off bulbs. Each object of Interval has data fields start and end that represents the start position and the end position. The intervals are compared according to start in ascending order and then according to end in ascending order.

Maintain a map that stores each day and the index of the bulb that is turned on. Also maintain a tree set to store the intervals, where the intervals are sorted in ascending order. Initially, the tree set contains a single interval [1, N]. On the first day, since only one bulb is turned on, there do not exist two bulbs that are turned on, so simply update the tree set after the first bulb is turned on. After the first day, the tree set man contain one interval or two intervals. From the second day, each day obtain the maximum interval that has start less than or equal to the current bulb’s index, which contains the current bulb’s index. It is guaranteed that such an interval exists, since all turned off bulbs are in the intervals.

If the current bulb’s index equals the start of the interval or the end of the interval, then if K is 0 and the bulb is not at any end of the row (that is, the bulb is not at index 1 or index N), return the current day. Otherwise, remove the previous interval and add one new interval to the tree set.

If the current bulb’s index is in the middle of the interval (not at the start or the end of the interval), then the current interval will be split after the current bulb is turned on. Check the two intervals. If one interval has length K and its start position is not 1 and its end position is not N, then return the current day. Otherwise, remove the previous interval and add two new intervals to the tree set.

If an interval of length K that is not at the start or the end of the row is found, return -1.

*/

class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        for (int i = 0; i < n; ++i) {
            int x = bulbs[i];
            tree->update(x, 1);
            bool case1 = x - k - 1 > 0 && tree->query(x - k - 1) - tree->query(x - k - 2) == 1 && tree->query(x - 1) - tree->query(x - k - 1) == 0;
            bool case2 = x + k + 1 <= n && tree->query(x + k + 1) - tree->query(x + k) == 1 && tree->query(x + k) - tree->query(x) == 0;
            if (case1 || case2) return i + 1;
        }
        return -1;
    }
};
