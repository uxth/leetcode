/*

Question
Formatted question description: https://leetcode.ca/all/296.html

Given an m x n binary grid grid where each 1 marks the home of one friend, return the minimal total travel distance.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

 

Example 1:



Input: grid = [[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 6
Explanation: Given three friends living at (0,0), (0,4), and (2,2).
The point (0,2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.
So return 6.
Example 2:

Input: grid = [[1,1]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
grid[i][j] is either 0 or 1.
There will be at least two friends in the grid.
Algorithm
First look at the situation where there are two points A and B in one dimension.

______A_____P_______B_______
It can be found that as long as the meeting is that the location P is in the interval [A, B], no matter where it is, the sum of the distances is the distance between A and B. If P is not between [A, B], then the sum of the distances is Will be greater than the distance between A and B, now add two more points C and D:

______C_____A_____P_______B______D______
The best position of point P is in the interval [A, B], so that the sum of the distances from the four points is the AB distance plus the CD distance.

Just sort the positions, then subtract the first coordinate from the last coordinate, which is the CD distance, and subtract the second coordinate from the penultimate, the second coordinate, which is the AB distance. And so on, until the middle stop.

The one-dimensional situation is analyzed, and the two-dimensional situation is the addition of two one-dimensional results.

*/

// OJ: https://leetcode.com/problems/best-meeting-point/
// Time: O(MN^2)
// Space: O(MN)
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = INT_MAX, dist[201][201] = {}, up[201][201] = {}, down[201][201] = {}, cnt[201] = {};
        for (int i = 0; i < M; ++i) {
            int sum = 0, left = 0, right = 0;
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0) continue;
                sum += j;
                right++;
            }
            for (int j = 0; j < N; ++j) {
                dist[i][j] = sum;
                if (A[i][j]) ++left, --right;
                sum += left - right;
            }
            cnt[i] = left;
        }
        int c = cnt[0];
        for (int i = 1; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int mn = INT_MAX;
                for (int k = 0; k < N; ++k) {
                    mn = min(mn, dist[i - 1][k] + (abs(j - k) + 1) * c);
                }
                up[i][j] = up[i - 1][j] + mn;
            }
            c += cnt[i];
        }
        c = cnt[M - 1];
        for (int i = M - 2; i >= 0; --i) {
            for (int j = 0; j < N; ++j) {
                int mn = INT_MAX;
                for (int k = 0; k < N; ++k) {
                    mn = min(mn, dist[i + 1][k] + (abs(j - k) + 1) * c);
                }
                down[i][j] = down[i + 1][j] + mn;
            }
            c += cnt[i];
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans = min(ans, dist[i][j] + up[i][j] + down[i][j]);
            }
        }
        return ans;
    }
};