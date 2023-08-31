/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 *
 * https://leetcode.com/problems/car-pooling/description/
 *
 * algorithms
 * Medium (56.69%)
 * Likes:    576
 * Dislikes: 27
 * Total Accepted:    32.2K
 * Total Submissions: 56.7K
 * Testcase Example:  '[[2,1,5],[3,3,7]]\n4'
 *
 * You are driving a vehicle that has capacity empty seats initially available
 * for passengers.  The vehicle only drives east (ie. it cannot turn around and
 * drive west.)
 * 
 * Given a list of trips, trip[i] = [num_passengers, start_location,
 * end_location] contains information about the i-th trip: the number of
 * passengers that must be picked up, and the locations to pick them up and
 * drop them off.  The locations are given as the number of kilometers due east
 * from your vehicle's initial location.
 * 
 * Return true if and only if it is possible to pick up and drop off all
 * passengers for all the given trips. 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 4
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 5
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: trips = [[2,1,5],[3,5,7]], capacity = 3
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
 * Output: true
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * trips.length <= 1000
 * trips[i].length == 3
 * 1 <= trips[i][0] <= 100
 * 0 <= trips[i][1] < trips[i][2] <= 1000
 * 1 <= capacity <= 100000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        if(trips.empty() || capacity == 0) return false;
        map<int,vector<int>> m;
        for(auto& t : trips)
        {
            m[t[1]].push_back(t[0]);
            m[t[2]].push_back(-t[0]);
        }

        int pass = 0;
        for(auto& i : m)
        {
            for(int j : i.second)
            {
                pass += j;
            }
            if(pass > capacity) return false;
        }
        return true;
    }
};
// @lc code=end
// [[4,5,6],[6,4,7],[4,3,5],[2,3,5]]\n13
