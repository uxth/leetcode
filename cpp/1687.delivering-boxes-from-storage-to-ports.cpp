/*
 * @lc app=leetcode id=1687 lang=cpp
 *
 * [1687] Delivering Boxes from Storage to Ports
 *
 * https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/description/
 *
 * algorithms
 * Hard (34.30%)
 * Likes:    109
 * Dislikes: 10
 * Total Accepted:    1.8K
 * Total Submissions: 5.1K
 * Testcase Example:  '[[1,1],[2,1],[1,1]]\n2\n3\n3'
 *
 * You have the task of delivering some boxes from storage to their ports using
 * only one ship. However, this ship has a limit on the number of boxes and the
 * total weight that it can carry.
 * 
 * You are given an array boxes, where boxes[i] = [ports​​i​, weighti], and
 * three integers portsCount, maxBoxes, and maxWeight.
 * 
 * 
 * ports​​i is the port where you need to deliver the i^th box and weightsi is
 * the weight of the i^th box.
 * portsCount is the number of ports.
 * maxBoxes and maxWeight are the respective box and weight limits of the
 * ship.
 * 
 * 
 * The boxes need to be delivered in the order they are given. The ship will
 * follow these steps:
 * 
 * 
 * The ship will take some number of boxes from the boxes queue, not violating
 * the maxBoxes and maxWeight constraints.
 * For each loaded box in order, the ship will make a trip to the port the box
 * needs to be delivered to and deliver it. If the ship is already at the
 * correct port, no trip is needed, and the box can immediately be
 * delivered.
 * The ship then makes a return trip to storage to take more boxes from the
 * queue.
 * 
 * 
 * The ship must end at storage after all the boxes have been delivered.
 * 
 * Return the minimum number of trips the ship needs to make to deliver all
 * boxes to their respective ports.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: boxes = [[1,1],[2,1],[1,1]], portsCount = 2, maxBoxes = 3, maxWeight
 * = 3
 * Output: 4
 * Explanation: The optimal strategy is as follows: 
 * - The ship takes all the boxes in the queue, goes to port 1, then port 2,
 * then port 1 again, then returns to storage. 4 trips.
 * So the total number of trips is 4.
 * Note that the first and third boxes cannot be delivered together because the
 * boxes need to be delivered in order (i.e. the second box needs to be
 * delivered at port 2 before the third box).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: boxes = [[1,2],[3,3],[3,1],[3,1],[2,4]], portsCount = 3, maxBoxes =
 * 3, maxWeight = 6
 * Output: 6
 * Explanation: The optimal strategy is as follows: 
 * - The ship takes the first box, goes to port 1, then returns to storage. 2
 * trips.
 * - The ship takes the second, third and fourth boxes, goes to port 3, then
 * returns to storage. 2 trips.
 * - The ship takes the fifth box, goes to port 3, then returns to storage. 2
 * trips.
 * So the total number of trips is 2 + 2 + 2 = 6.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: boxes = [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]], portsCount = 3,
 * maxBoxes = 6, maxWeight = 7
 * Output: 6
 * Explanation: The optimal strategy is as follows:
 * - The ship takes the first and second boxes, goes to port 1, then returns to
 * storage. 2 trips.
 * - The ship takes the third and fourth boxes, goes to port 2, then returns to
 * storage. 2 trips.
 * - The ship takes the fifth and sixth boxes, goes to port 3, then returns to
 * storage. 2 trips.
 * So the total number of trips is 2 + 2 + 2 = 6.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: boxes = [[2,4],[2,5],[3,1],[3,2],[3,7],[3,1],[4,4],[1,3],[5,2]],
 * portsCount = 5, maxBoxes = 5, maxWeight = 7
 * Output: 14
 * Explanation: The optimal strategy is as follows:
 * - The ship takes the first box, goes to port 2, then storage. 2 trips.
 * - The ship takes the second box, goes to port 2, then storage. 2 trips.
 * - The ship takes the third and fourth boxes, goes to port 3, then storage. 2
 * trips.
 * - The ship takes the fifth box, goes to port 3, then storage. 2 trips.
 * - The ship takes the sixth and seventh boxes, goes to port 3, then port 4,
 * then storage. 3 trips. 
 * - The ship takes the eighth and ninth boxes, goes to port 1, then port 5,
 * then storage. 3 trips.
 * So the total number of trips is 2 + 2 + 2 + 2 + 3 + 3 = 14.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= boxes.length <= 10^5
 * 1 <= portsCount, maxBoxes, maxWeight <= 10^5
 * 1 <= ports​​i <= portsCount
 * 1 <= weightsi <= maxWeight
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int topdowndp(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight)
    {
        int n = boxes.size(), need = 0, j = 0, lastj = 0;
        vector<int> dp(n + 1, 200000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && maxBoxes > 0 && maxWeight >= boxes[j][1]) {
                maxBoxes -= 1;
                maxWeight -= boxes[j][1];
                if (j == 0 || boxes[j][0] != boxes[j - 1][0]) {
                    lastj = j;
                    need++;
                }
                j++;
            }
            dp[j] = min(dp[j], dp[i] + need + 1);
            dp[lastj] = min(dp[lastj], dp[i] + need);
            maxBoxes += 1;
            maxWeight += boxes[i][1];
            if (i == n - 1 || boxes[i][0] != boxes[i + 1][0]) {
                need--;
            }
        }
        return dp[n];
    }
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        return topdowndp(boxes, portsCount, maxBoxes, maxWeight);
    }
};
// @lc code=end
// [[1,2],[3,3],[3,1],[3,1],[2,4]]\n3\n3\n6
// [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]]\n3\n6\n7
// [[2,4],[2,5],[3,1],[3,2],[3,7],[3,1],[4,4],[1,3],[5,2]]\n5\n5\n7
// [[48,52899],[47,19850],[33,29679],[69,33222],[58,701],[30,76794],[25,81170],[73,23227],[55,20126],[44,36120],[45,31939],[67,19736],[68,38178],[17,83260],[38,15272],[38,78703],[35,17238],[75,18299],[8,20643],[23,49506],[64,11294],[57,52676],[50,72049],[18,62783],[72,47322],[58,17174],[33,91245],[41,20540],[9,52226],[8,56422],[38,67101],[55,84871],[10,22701],[13,65749],[10,75225],[27,13437],[5,82776],[53,69170],[40,19975],[71,52129],[56,92827],[77,91290],[34,52128],[49,42076],[65,14024],[11,20086],[54,72018],[64,64707],[43,53637],[18,81304],[34,769],[33,7418],[60,1473],[44,16057],[45,81799],[50,91388],[2,88844],[50,19037],[50,24485],[2,79102],[3,34503],[49,89167],[18,18198],[30,76362],[61,51312],[53,25332],[53,85378],[43,31053],[74,8190],[55,22288],[56,48727],[66,45387],[12,53165],[46,66319],[48,47049],[34,4879],[20,35950],[27,80365],[59,42479],[50,17398],[63,26273],[27,78622],[57,27062],[16,53519],[42,31522],[39,26623],[35,71692],[33,72780],[23,17746],[2,939],[47,3748],[63,71487],[25,92114],[58,48662],[24,45749],[64,63233],[26,92359],[29,11382],[58,785],[59,11024],[60,55275],[50,66923],[10,6771],[61,31311],[76,61562],[69,22497],[29,24471],[43,90635],[38,40760],[64,87184],[7,19793],[47,47690],[69,9570],[39,16271],[75,87064],[26,26233],[53,69585],[29,68502],[37,16523],[34,10484],[22,88729],[31,80116],[10,17864],[33,47739],[53,67300],[21,68588],[69,58835],[75,79944],[76,13923]]\n77\n17\n93070