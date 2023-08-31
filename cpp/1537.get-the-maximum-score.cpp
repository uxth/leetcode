/*
 * @lc app=leetcode id=1537 lang=cpp
 *
 * [1537] Get the Maximum Score
 *
 * https://leetcode.com/problems/get-the-maximum-score/description/
 *
 * algorithms
 * Hard (35.69%)
 * Likes:    207
 * Dislikes: 16
 * Total Accepted:    6.5K
 * Total Submissions: 18.3K
 * Testcase Example:  '[2,4,5,8,10]\n[4,6,8,9]'
 *
 * You are given two sorted arrays of distinct integers nums1 and nums2.
 * 
 * A valid path is defined as follows:
 * 
 * 
 * Choose array nums1 or nums2 to traverse (from index-0).
 * Traverse the current array from left to right.
 * If you are reading any value that is present in nums1 and nums2 you are
 * allowed to change your path to the other array. (Only one repeated value is
 * considered in the valid path).
 * 
 * 
 * Score is defined as the sum of uniques values in a valid path.
 * 
 * Return the maximum score you can obtain of all possible valid paths.
 * 
 * Since the answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
 * Output: 30
 * Explanation: Valid paths:
 * [2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
 * [4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
 * The maximum is obtained with the path in green [2,4,6,8,10].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
 * Output: 109
 * Explanation: Maximum sum is obtained with the path [1,3,5,100].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
 * Output: 40
 * Explanation: There are no common elements between nums1 and nums2.
 * Maximum sum is obtained with the path [6,7,8,9,10].
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
 * Output: 61
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length <= 10^5
 * 1 <= nums2.length <= 10^5
 * 1 <= nums1[i], nums2[i] <= 10^7
 * nums1 and nums2 are strictly increasing.
 * 
 * 
 */

// @lc code=start
class Solution {
    const int mx = 1000000007;
    struct node
    {
        node(int i, int j, int d){it1=i; it2=j; dis=d;}
        int it1;
        int it2;
        int dis;
    };
public:
    // int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
    //     unordered_map<int,int> mp1, mp2;
    //     for(int i=0; i<nums1.size(); ++i)mp1[nums1[i]] = i;
    //     for(int j=0; j<nums2.size(); ++j)mp2[nums2[j]] = j;
    //     queue<node> q;
    //     q.push(node(0, -1, 0));
    //     q.push(node(-1, 0, 0));
    //     int res = 0;
    //     while(!q.empty())
    //     {
    //         int it1 = q.front().it1;
    //         int it2 = q.front().it2;
    //         int dis = q.front().dis;
    //         res = max(res, dis);
    //         // cout << it1 << " " << it2 << " " << dis << endl;
    //         q.pop();
    //         if(it1 >= 0)
    //         {
    //             if(it1 < nums1.size())
    //             {
    //                 q.push(node(it1 + 1, -1, dis + nums1[it1]));
    //                 if(mp2.count(nums1[it1]) && mp2[nums1[it1]] < nums2.size())
    //                 {
    //                     q.push(node(-1, mp2[nums1[it1]]+1, dis + nums1[it1]));
    //                 }
    //             }
                
    //         }
    //         else
    //         {
    //             if(it2 < nums2.size())
    //             {
    //                 q.push(node(-1, it2 + 1, dis + nums2[it2]));
    //                 if(mp1.count(nums2[it2]) && mp1[nums2[it2]] < nums1.size())
    //                 {
    //                     q.push(node(mp1[nums2[it2]] + 1, -1, dis + nums2[it2]));
    //                 }
    //             }
                
    //         }
            
    //     }
    //     return res;
    // }

    // vector<int> construct(vector<int>& nums, unordered_set<int>& st)
    // {
    //     vector<int> data;
    //     int i=0;
    //     int sum = 0;
    //     while(i<nums.size())
    //     {
    //         while(i < nums.size() && st.count(nums[i]) == 0)
    //         {
    //             sum += nums[i++];
    //         }
    //         if(i<nums.size()) sum+=nums[i++];
    //         data.push_back(sum);
    //         sum = 0;
    //     }
    //     data.push_back(sum); 
    //     return data;    
    // }
    // int maxSum(vector<int>& nums1, vector<int>& nums2)
    // {
        
    //     unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
    //     vector<int> data1=move(construct(nums1, st2)), data2=move(construct(nums2, st1));

    //     int res = 0;
    //     // for_each(data1.begin(), data1.end(), [](int i){cout << i << " ";}), cout << endl;
    //     // for_each(data2.begin(), data2.end(), [](int i){cout << i << " ";}), cout << endl;
    //     int i = 0;
    //     while(i < min(data1.size(), data2.size()))
    //     {
    //         res += max(data1[i], data2[i]);
    //         res %= mx;
    //         i++;
    //     }
        
    //     if(i == data1.size())
    //     {
    //         while(i < data2.size())
    //         {
    //             res += data2[i++];
    //             res %= mx;
    //         }
    //     }
    //     else
    //     {
    //         while(i < data1.size())
    //         {
    //             res += data1[i++];
    //             res %= mx;
    //         }
    //     }
        
    //     return res;
    // }

    int maxSum(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0, n = A.size(), m = B.size();
        long a = 0, b = 0, mod = 1e9 + 7;
        while (i < n || j < m) {
            if (i < n && (j == m || A[i] < B[j])) {
                a += A[i++];
            } else if (j < m && (i == n || A[i] > B[j])) {
                b += B[j++];
            } else {
                a = b = max(a, b) + A[i];
                i++, j++;
            }
        }
        return max(a, b) % mod;
    }
};
// @lc code=end

// [5,9,11,15,17,25,29]\n[6,12,15]


// [10,27,32,44,55,68,73,83,93,104,106,122,123,139,152,156,161,163,177,190,206,221,234,237,253,256,270,275,279,290,295,300,304,318,332,334,339,356,358,376,381,385,390,406,408,411,429,430,431,442,458,460,480,496,501,503,508,524,528,540,543,546,547,562,566,569,574,588,606,623,634,645,650,668,673,689,694,712,727,728,739,742,762,780,782,785,787,807,812,817,833,844,845,865,870,871,873,878,879,896,900,912,927,929,932,935,947,950,952,969,987,999,1013,1024,1025,1036,1047,1060,1077,1080,1096,1108,1111,1116,1117,1120,1133,1153,1154,1172,1175,1189,1190,1204,1214,1219,1237,1239,1243,1256,1259,1261,1276,1292,1306,1320,1330,1332,1333,1336,1337,1356,1370,1385,1400,1404,1424,1425,1430,1450,1453,1465,1478,1497,1499,1510,1527,1543,1545,1548,1559,1575,1578,1598,1610,1624,1635,1653,1670,1672,1692,1697,1712,1715,1726,1731,1735,1749,1762,1767]\n[5,6,10,11,30,47,64,69,72,74,75,87,92,97,116,131,135,150,151,168,172,175,177,180,183,188,201,215,234,237,256,268,272,275,291,296,307,309,312,329,332,335,339,356,361,363,367,371,375,390,391,394,411,429,439,442,452,462,463,475,477,479,480,482,496,500,504,507,510,530,535,537,542,547,551,562,565,569,580,581,583,585,602,612,626,631,634,646,648,662,675,678,697,702,705,707,708,711,727,729,731,742,747,763,768,771,789,799,809,829,847,850,855,868,870,887,897,901,914,930,941,943,945,949,950,965,966,968,987,990,1002,1017,1019,1037,1052,1056,1059,1063,1064,1066,1070,1073,1088,1090,1110,1128,1132,1152,1155,1159,1175,1189,1201,1219,1235,1236,1239,1257,1260,1274,1278,1292,1302,1305,1319,1331,1334,1351,1366,1377,1379,1398,1399,1413,1417,1429,1432,1433,1436,1447,1451,1468,1487,1488,1501,1505,1525,1530,1535,1539,1558,1560,1561,1576,1579,1581,1594,1599,1603,1616,1628,1633,1644,1647,1660,1661,1666,1669,1688,1692,1697,1700,1718,1722,1741,1759,1773,1787,1800,1817,1830,1833,1837,1850,1860,1861,1878,1894,1904,1909,1913,1926,1946,1966,1968,1988,1993,2008,2009,2020,2038,2040,2050,2055,2069,2072,2076,2096,2098,2103,2113,2118,2135,2136,2138,2155,2160,2164,2166,2167,2183,2202,2203,2206,2226,2230,2242,2261,2276,2289,2305,2310,2314,2316,2318,2321,2340,2353,2358,2363,2367,2381,2391,2404,2406,2407,2420,2422,2427,2447,2461,2462,2472,2476,2478,2482,2502,2505,2506,2510,2525,2539,2541,2555,2568,2569,2572,2574,2579,2583,2593,2603,2617,2633,2638,2641,2645,2655,2675,2693,2697,2715,2735,2753,2768,2772,2787,2807,2817,2822,2825,2842]
