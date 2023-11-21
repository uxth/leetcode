/*

Question
Formatted question description: https://leetcode.ca/all/323.html

Level
Medium

Description
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output: 1
Note: You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Algorithm
DFS
One solution is to use DFS. The idea is to give each node a flag to mark whether it has been visited. For an unvisited node, we will increment the result by 1, because this must be a new connected region. , And then we traverse the neighboring nodes through the adjacency list and mark them as visited.

After traversing all connected nodes, we continue to look for the next unvisited node, and so on until all nodes have been visited, then the number of connected regions is also calculated at this time

Union Find
Create a root array with the same subscript and node value. At this time, root[i] indicates that node i belongs to group i. We initialized n parts (res = n), assuming that each node belongs to a separate interval at the beginning .

Then we start to traverse all the edges. For two points of an edge, their values in the root at the beginning are not the same. At this time, we reduce the result by 1, which means one interval is missing. Then update the root of one of the nodes Value to make the root value of the two nodes the same.

Then we can mark the root values of all nodes in the connected interval as the same value, and the root values of different connected intervals are different, so that we can also find the number of connected intervals.

*/

// OJ: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// Time: O(E + N)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int n) : cnt(n), id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        --cnt;
    }
    int getCount() {
        return cnt;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& E) {
        UnionFind uf(n);
        for (auto &e : E) {
            uf.connect(e[0], e[1]);
        }
        return uf.getCount();
    }
};