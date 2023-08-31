/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (44.91%)
 * Likes:    576
 * Dislikes: 5
 * Total Accepted:    21K
 * Total Submissions: 46.3K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * Given an array equations of strings that represent relationships between
 * variables, each string equations[i] has length 4 and takes one of two
 * different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not
 * necessarily different) that represent one-letter variable names.
 * 
 * Return true if and only if it is possible to assign integers to variable
 * names so as to satisfy all the given equations.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is
 * satisfied, but not the second.  There is no way to assign the variables to
 * satisfy both equations.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["a==b","b==c","a==c"]
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: ["a==b","b!=c","c==a"]
 * Output: false
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: ["c==c","b==d","x!=z"]
 * Output: true
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] and equations[i][3] are lowercase letters
 * equations[i][1] is either '=' or '!'
 * equations[i][2] is '='
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:   
    struct UnionFind
    {
        vector<int> data;
        int size;
        UnionFind(int n){data.assign(n, -1); size = n;}
        int find(int x)
        {
            if(data[x] == -1) return x;
            data[x] = find(data[x]);
            return data[x];
        }
        void join(int i, int j)
        {
            int ri = find(i);
            int rj = find(j);
            if(ri!=rj)
            {
                data[rj] = ri;
                size--;
            }
        }
        void erase(int x)
        {
            data[x] = INT_MAX;
            size--;
        }
        int count()
        {
            return size;
        }
    };
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (string& e : equations)
            if (e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a');
        for (string& e : equations)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }

    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};
// @lc code=end
// ["a==b","b!=c","c==a"]
// ["f==d","y!=g","i!=u","b==l","r!=e","s!=d","a!=y","p==e","w!=f","l==c","r==n","o!=h","x==f","g==v","q!=a","l==l","e==p","o!=r","f!=o","n==n"]