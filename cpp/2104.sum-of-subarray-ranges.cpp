/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 */

// @lc code=start
class Solution {
public:
    long long bruteForce(vector<int>& nums){
        int n = nums.size();
        long long res = 0;
        vector<vector<long long>> minValue(n, vector<long long>(n)), maxValue(n, vector<long long>(n));
        for(int i=0; i<n; ++i) minValue[i][i] = maxValue[i][i] = nums[i];
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                minValue[i][j] = min(minValue[i][j-1], (long long)nums[j]);
                maxValue[i][j] = max(maxValue[i][j-1], (long long)nums[j]);
                res += maxValue[i][j] - minValue[i][j];
            }
        }
        return res;

    }
    long long stackSolution(vector<int>& nums){
        long res = 0, n = nums.size();
        stack<int> s;
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && nums[s.top()] > (i == n ? INT_MIN : nums[i])) {
                int j = s.top();
                s.pop();
                int k = s.empty() ? -1 : s.top();
                res -= (long)nums[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        s = stack<int>();
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && nums[s.top()] < (i == n ? INT_MAX : nums[i])) {
                int j = s.top();
                s.pop();
                int k = s.empty() ? -1 : s.top();
                res += (long)nums[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return res;
    }
    long long subArrayRanges(vector<int>& nums) {
        // return bruteForce(nums);
        return stackSolution(nums);
    }
};
// @lc code=end
/*
[1,3,3]
[4,-2,-3,4,1]
[-31372,86677,70463,37727,-91683,-41347,-90576,-82174,-84198,-5148,-12591,-34156,49770,9666,-77075,-57678,-31101,-47531,-86306,-91337,-89507,-24917,-87692,-39171,98075,17787,-42549,34352,-70752,71832,70055,-1026,3784,2190,-36669,959,50619,97129,77088,54049,51707,72052,59230,-96834,-14048,-9619,84853,99362,69885,74086,-28737,23060,-63323,13156,-72998,94336,-75409,58266,-86800,-54564,80773,40687,-47207,43609,-56556,21192,-48024,-58907,1629,-65561,-68397,31862,-2201,-34966,43542,-59201,-3637,-21936,-93559,49435,23249,-54299,70508,-90795,-3620,-33894,43927,10208,-7390,86931,48175,81859,95058,-16614,38066,-99361,63621,-99285,-47111,29933,73901,60455,46586,-84117,35256,-89853,33383,-91662,82979,-48835,-93877,-80929,-98904,-47773,69451,85183,-14449,-51496,75765,35062,12456,35254,-16363,80792,-3414,9244,62961,-52057,56344,-50277,-26870,-63323,54993,75596,-93637,-78526,-3058,-30560,82233,-50795,-5290,-641,-83040,13524,86725,23735,29280,43938,-43995,-8992,-83717,-62090,74538,58682,-56550,-8638,61528,-87974]
*/
