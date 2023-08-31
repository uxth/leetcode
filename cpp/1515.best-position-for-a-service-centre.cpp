/*
 * @lc app=leetcode id=1515 lang=cpp
 *
 * [1515] Best Position for a Service Centre
 *
 * https://leetcode.com/problems/best-position-for-a-service-centre/description/
 *
 * algorithms
 * Hard (35.78%)
 * Likes:    85
 * Dislikes: 126
 * Total Accepted:    4.8K
 * Total Submissions: 13.1K
 * Testcase Example:  '[[0,1],[1,0],[1,2],[2,1]]'
 *
 * A delivery company wants to build a new service centre in a new city. The
 * company knows the positions of all the customers in this city on a 2D-Map
 * and wants to build the new centre in a position such that the sum of the
 * euclidean distances to all customers is minimum.
 * 
 * Given an array positions where positions[i] = [xi, yi] is the position of
 * the ith customer on the map, return the minimum sum of the euclidean
 * distances to all customers.
 * 
 * In other words, you need to choose the position of the service centre
 * [xcentre, ycentre] such that the following formula is minimized:
 * 
 * Answers within 10^-5 of the actual value will be accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: positions = [[0,1],[1,0],[1,2],[2,1]]
 * Output: 4.00000
 * Explanation: As shown, you can see that choosing [xcentre, ycentre] = [1, 1]
 * will make the distance to each customer = 1, the sum of all distances is 4
 * which is the minimum possible we can achieve.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: positions = [[1,1],[3,3]]
 * Output: 2.82843
 * Explanation: The minimum possible sum of distances = sqrt(2) + sqrt(2) =
 * 2.82843
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: positions = [[1,1]]
 * Output: 0.00000
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: positions = [[1,1],[0,0],[2,0]]
 * Output: 2.73205
 * Explanation: At the first glance, you may think that locating the centre at
 * [1, 0] will achieve the minimum sum, but locating it at [1, 0] will make the
 * sum of distances = 3.
 * Try to locate the centre at [1.0, 0.5773502711] you will see that the sum of
 * distances is 2.73205.
 * Be careful with the precision!
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: positions = [[0,1],[3,2],[4,5],[7,6],[8,9],[11,1],[2,12]]
 * Output: 32.94036
 * Explanation: You can use [4.3460852395, 4.9813795505] as the position of the
 * centre.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= positions.length <= 50
 * positions[i].length == 2
 * 0 <= positions[i][0], positions[i][1] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double finddist(double x,double y,vector<vector<int>>& positions)
    {
        double dist=0;
        for(int i=0;i<positions.size();i++)
        {
            dist+=sqrt((positions[i][0]-x)*(positions[i][0]-x)+(positions[i][1]-y)*(positions[i][1]-y));
        }
        return dist;
        
    }
    
    int row[4]={1,0,-1,0};
    int col[4]={0,-1,0,1};
    double getMinDistSum(vector<vector<int>>& positions) 
    {
        double x=0,y=0;
        for(int i=0;i<positions.size();i++)
        {
            x+=positions[i][0];
            y+=positions[i][1];
        }
        x=x/positions.size();
        y=y/positions.size();
        double dist=finddist(x,y,positions);
        double step=100;
        double limit=pow(10,-6);
        while(step>limit)
        {
            bool updated=false;
            for(int k=0;k<4;k++)
            {
                double newdist=finddist(x+row[k]*step,y+col[k]*step,positions);
                if(newdist<dist)
                {
                    updated=true;
                    dist=newdist;
                    x=x+row[k]*step;
                    y=y+col[k]*step;
                    break;
                }
            }
            if(updated==false)
                step=step/5;
        }
        return dist;
    }
};
// @lc code=end

