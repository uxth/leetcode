/*
 * @lc app=leetcode id=1453 lang=cpp
 *
 * [1453] Maximum Number of Darts Inside of a Circular Dartboard
 *
 * https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/description/
 *
 * algorithms
 * Hard (33.68%)
 * Likes:    79
 * Dislikes: 198
 * Total Accepted:    3.4K
 * Total Submissions: 9.9K
 * Testcase Example:  '[[-2,0],[2,0],[0,2],[0,-2]]\n2'
 *
 * You have a very large square wall and a circular dartboard placed on the
 * wall. You have been challenged to throw darts into the board blindfolded.
 * Darts thrown at the wall are represented as an array of points on a 2D
 * plane. 
 * 
 * Return the maximum number of points that are within or lie on any circular
 * dartboard of radius r.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
 * Output: 4
 * Explanation: Circle dartboard with center in (0,0) and radius = 2 contain
 * all points.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: points = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
 * Output: 5
 * Explanation: Circle dartboard with center in (0,4) and radius = 5 contain
 * all points except the point (7,8).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: points = [[-2,0],[2,0],[0,2],[0,-2]], r = 1
 * Output: 1
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: points = [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]], r = 2
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= points.length <= 100
 * points[i].length == 2
 * -10^4 <= points[i][0], points[i][1] <= 10^4
 * 1 <= r <= 5000
 * 
 */

// @lc code=start
class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int res=0;
        double PI = 3.14159265;
        for(auto& p : points)
        {
            for(int deg = 0; deg<360; ++deg)
            {
                double alpha = (double) deg / 180 * PI;
                double y = p[0] + r * sin(alpha);
                double x = p[1] + r * cos(alpha);
                int count = 0;
                for(auto& next : points)
                {
                    if((next[0]-y)*(next[0]-y) + (next[1]-x)*(next[1]-x) <= r*r) count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
// @lc code=end
// [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]]\n5
// [[-2,0],[2,0],[0,2],[0,-2]]\n1
// [[1,2],[3,5],[1,-1],[2,3],[4,1],[1,3]]\n2
// [[-23,0],[23,22],[15,1],[-15,2],[30,-25],[2,19],[18,12],[9,21],[17,11],[20,-22],[-21,26],[25,0],[-18,15],[16,-18],[-5,-6],[10,4],[18,-20],[-19,-8],[-14,-28],[-5,3],[-16,-10],[-7,1]]\n23
// [[0,0],[7,-2],[8,0]]\n4