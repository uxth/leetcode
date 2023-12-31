/*
 * @lc app=leetcode id=1488 lang=cpp
 *
 * [1488] Avoid Flood in The City
 *
 * https://leetcode.com/problems/avoid-flood-in-the-city/description/
 *
 * algorithms
 * Medium (25.27%)
 * Likes:    357
 * Dislikes: 68
 * Total Accepted:    9.9K
 * Total Submissions: 38.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Your country has an infinite number of lakes. Initially, all the lakes are
 * empty, but when it rains over the nth lake, the nth lake becomes full of
 * water. If it rains over a lake which is full of water, there will be a
 * flood. Your goal is to avoid the flood in any lake.
 * 
 * Given an integer array rains where:
 * 
 * 
 * rains[i] > 0 means there will be rains over the rains[i] lake.
 * rains[i] == 0 means there are no rains this day and you can choose one lake
 * this day and dry it.
 * 
 * 
 * Return an array ans where:
 * 
 * 
 * ans.length == rains.length
 * ans[i] == -1 if rains[i] > 0.
 * ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
 * 
 * 
 * If there are multiple valid answers return any of them. If it is impossible
 * to avoid flood return an empty array.
 * 
 * Notice that if you chose to dry a full lake, it becomes empty, but if you
 * chose to dry an empty lake, nothing changes. (see example 4)
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: rains = [1,2,3,4]
 * Output: [-1,-1,-1,-1]
 * Explanation: After the first day full lakes are [1]
 * After the second day full lakes are [1,2]
 * After the third day full lakes are [1,2,3]
 * After the fourth day full lakes are [1,2,3,4]
 * There's no day to dry any lake and there is no flood in any lake.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: rains = [1,2,0,0,2,1]
 * Output: [-1,-1,2,1,-1,-1]
 * Explanation: After the first day full lakes are [1]
 * After the second day full lakes are [1,2]
 * After the third day, we dry lake 2. Full lakes are [1]
 * After the fourth day, we dry lake 1. There is no full lakes.
 * After the fifth day, full lakes are [2].
 * After the sixth day, full lakes are [1,2].
 * It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another
 * acceptable scenario.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: rains = [1,2,0,1,2]
 * Output: []
 * Explanation: After the second day, full lakes are  [1,2]. We have to dry one
 * lake in the third day.
 * After that, it will rain over lakes [1,2]. It's easy to prove that no matter
 * which lake you choose to dry in the 3rd day, the other one will flood.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: rains = [69,0,0,0,69]
 * Output: [-1,69,1,1,-1]
 * Explanation: Any solution on one of the forms [-1,69,x,y,-1], [-1,x,69,y,-1]
 * or [-1,x,y,69,-1] is acceptable where 1 <= x,y <= 10^9
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: rains = [10,20,20]
 * Output: []
 * Explanation: It will rain over lake 20 two consecutive days. There is no
 * chance to dry any lake.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= rains.length <= 10^5
 * 0 <= rains[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<int> avoidFlood(vector<int>& rains) {
    //     vector<int> ans; // Store the final answer here.
    //     int n = rains.size(); 
    //     unordered_map<int, int> fulllakes; // Lake number -> day on which it became full.
    //     set<int> drydays;     // Set of available days that can be used for drying a full lake.
    //     for (int i=0; i<n; i++) {  // For each day - 
    //         if (rains[i] == 0) {  // No rain on this day.
    //             drydays.insert(i); // This day can be used as a day to dry some lake.
    //                                // We don't know which lake to prioritize for drying yet.
    //             ans.push_back(1);  // Any number would be ok. This will get overwritten eventually.
    //                                // If it doesn't get overwritten, its totally ok to dry a lake
    //                                // irrespective of whether it is full or empty.
    //         } else { // Rained in rains[i]-th lake.
    //             int lake = rains[i]; 
    //             if (fulllakes.find(lake) != fulllakes.end()) { // If it is already full -
    //                 // We must dry this lake before it rains in this lake.
    //                 // So find a day in "drydays" to dry this lake. Obviously, that day must be
    //                 // a day that is after the day on which the lake was full.
    //                 // i.e. if the lake got full on 7th day, we must find a dry day that is 
    //                 // greater than 7.
    //                 auto it = drydays.lower_bound(fulllakes[lake]);
    //                 if (it == drydays.end()) { // If there is no available dry day to dry the lake,
    //                                            // flooding is inevitable.
    //                     return {}; // Sorry, couldn't stop flooding.
    //                 }
    //                 int dryday = *it; // Great, we found a day which we can use to dry this lake.
    //                 ans[dryday] = lake; // Overwrite the "1" and dry "lake"-th lake instead.
    //                 drydays.erase(dryday); // We dried "lake"-th lake on "dryday", and we can't use
    //                                        // the same day to dry any other lake, so remove the day
    //                                        // from the set of available drydays.
    //             }
    //             fulllakes[lake] = i; // Update that the "lake" became full on "i"-th day.
    //             ans.push_back(-1); // As the problem statement expects.
    //         }
    //     }
    //     return ans; // Congratualtions, you avoided flooding.
    // }

    vector<int> avoidFlood(vector<int>& rains) 
    {
        unordered_map<int,int> fulllakes;
        set<int> drydays;
        vector<int> res(rains.size());
        for(int i=0; i<rains.size(); ++i)
        {
            if(rains[i] == 0)
            {
                drydays.insert(i);
                res[i] = 1;
            }
            else
            {
                res[i]=-1;
                if(fulllakes.count(rains[i]))
                {
                    auto it = drydays.upper_bound(fulllakes[rains[i]]);
                    if(it == drydays.end()) return {};
                    res[*it] = rains[i];
                    drydays.erase(it);
                }
                fulllakes[rains[i]] = i;

            }
            
        }
        return res;
    }
};
// @lc code=end
// [1,2,0,1,2]
// [1,2,0,0,2,1]
// [69,0,0,0,69]
// [1,0,2,0,2,1]
// [1,2,0,2,3,0,1]