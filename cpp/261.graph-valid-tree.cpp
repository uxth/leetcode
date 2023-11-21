/*

Question
Formatted question description: https://leetcode.ca/all/261.html

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

Example 1:



Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
Example 2:



Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.
Algorithm
If it is a tree:

all nodes must be connected, that is, it must be a connected graph
and there must be no cycles
Use queue to assist the traversal. Here, instead of using a one-dimensional vector to mark whether the node has been visited, a HashSet is used. If a node is traversed and there is no HashSet in the HashSet, the HashSet is added. If it already exists, false is returned.

*/

// OJ: https://leetcode.com/problems/graph-valid-tree/
// Time: O(N + E)
// Space: O(N)
class UnionFind {
    vector<int> id;
    int cnt;
public:
    UnionFind(int N) : id(N), cnt(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int a, int b) {
        id[find(a)] = find(b);
        --cnt;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int getCount() { return cnt; }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& E) {
        UnionFind uf(n);
        for (auto &e : E) {
            if (uf.connected(e[0], e[1])) return false;
            uf.connect(e[0], e[1]);
        }
        return uf.getCount() == 1;
    }
};