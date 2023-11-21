/*

Description
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:

Input:

org: [1,2,3], seqs: [[1,2],[1,3]]

Output:

false

Explanation:

[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

Example 2:

Input:

org: [1,2,3], seqs: [[1,2]]

Output:

false

Explanation:

The reconstructed sequence can only be [1,2].

Example 3:

Input:

org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

Output:

true

Explanation:

The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].

Example 4:

Input:

org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

Output:

true

Solution
If only one sequence can be reconstructed from seqs, then seqs must contain all adjacent subsequences of length 2 in org. It is possible that seqs contains a subsequence that has length greater than 2 and the elements in the subsequence are all adjacent in org. Besides, seqs must contain all the numbers in org but can’t contain any number that is not in org.

Use a map to store each number and its corresponding index in org. Use an array of type boolean to store whether each adjacent subsequence is contained in seqs. Use a set to store the numbers in seqs.

Loop over org to fill in the map. For each sequence in seqs, first check all the numbers in the sequence. If a number is greater than org.length, then the number can’t be in org, so return false. Otherwise, add the number to the set. Then check each pair of adjacent numbers. If two adjacet numbers’ indices in org are adjacent and the former number’s index is less than the latter number’s index, then set the element at the former number’s index in the boolean array to true. If the former number’s index is greater than or equal to the latter number’s index, then there is a conflict, so return false.

After the loop, check the set’s size. If the set’s size is less than org.length, then return false. Then check all the elements in the boolean array. If there is a false, then return false. Otherwise, return true.

*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (auto& seq : sequences) {
            for (int i = 1; i < seq.size(); ++i) {
                int a = seq[i - 1] - 1, b = seq[i] - 1;
                g[a].push_back(b);
                ++indeg[b];
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
            if (q.size() > 1) return false;
            int i = q.front();
            q.pop();
            for (int j : g[i])
                if (--indeg[j] == 0) q.push(j);
        }
        return true;
    }
};