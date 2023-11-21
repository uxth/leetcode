/*

Description
There’s a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

Example 1:

Input:

Height : 5

Width : 7

Tree position : [2,2]

Squirrel : [4,4]

Nuts : [[3,0], [2,5]]

Output: 12

Explanation:

Image text

Note:

All given positions won’t overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.
Solution
After the squirrel takes one nut to the tree, for the rest of the nuts, the squirrel must go to the nut from the tree, take the nut, and go back to the tree. Since the positions of the tree and all the nuts are determined, the total distance are also determined. The only facter that determines the total distance is which nut the squirrel takes first.

First, calculate all distances between the tree and each nut, and sum up the distances multiplied by 2 as the total distance, since the squirrel goes to each nut and goes back to the tree, which has a moving distance twice as the distance between the tree and the nut.

Next, calculate all distances between the squirrel and each nut, and find the nut that has the max difference between the distance between the tree and the nut and the distance between the squirrel and the nut. Figure out the max difference and subtract the max difference from the total distance.

Finally, the total distance is the result.
*/


// OJ: https://leetcode.com/problems/squirrel-simulation/
// Time: O(N)
// Space: O(1)
class Solution {
    int dist(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0, mn = INT_MAX;
        for (auto &n : nuts) {
            sum += dist(tree, n);
            mn = min(mn, dist(squirrel, n) - dist(tree, n));
        }
        return 2 * sum + mn;
    }
};