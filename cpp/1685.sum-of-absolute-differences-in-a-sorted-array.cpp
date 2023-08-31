/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 *
 * https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (60.83%)
 * Likes:    231
 * Dislikes: 6
 * Total Accepted:    8.1K
 * Total Submissions: 13.1K
 * Testcase Example:  '[2,3,5]'
 *
 * You are given an integer array nums sorted in non-decreasing order.
 * 
 * Build and return an integer array result with the same length as nums such
 * that result[i] is equal to the summation of absolute differences between
 * nums[i] and all the other elements in the array.
 * 
 * In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j <
 * nums.length and j != i (0-indexed).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,5]
 * Output: [4,3,5]
 * Explanation: Assuming the arrays are 0-indexed, then
 * result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
 * result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
 * result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,4,6,8,10]
 * Output: [24,15,13,15,21]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * 1 <= nums[i] <= nums[i + 1] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int size = nums.size();
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> result(size, 0);
        for (int i = 0; i < size; i++) {
            rightSum -= nums[i];
            leftSum += nums[i];
            result[i] += nums[i] * (i + 1) - leftSum;
            result[i] += (rightSum - nums[i] * (size - i - 1));
        }
        return result;
    }
};
// @lc code=end
// [1,3,4,4,4,7,8,13,16,17,18,20,22,29,31,34,37,39,39,46,50,51,51,60,64,67,68,70,76,76,79,80,80,81,83,83,84,88,89,90,93,94,94,95,95,100,101,109,111,112,112,121,121,123,123,126,128,135,135,136,137,138,141,146,147,148,151,151,153,153,153,153,156,156,158,159,161,164,164,165,166,166,167,175,175,176,177,178,178,179,180,185,191,193,196,203,204,206,209,209,210,211,212,212,216,217,218,218,219,222,223,229,229,231,232,233,236,236,237,241,242,243,243,245,245,246,251,256,264,264,265,272,274,277,280,283,288,291,292,296,301,306,308,310,316,324,333,333,334,338,338,339,339,341,345,353,354,354,368,373,373,373,377,380,380,382,386,387,387,388,388,388,389,391,394,395,396,398,401,402,405,408,408,409,412,416,419,420,423,424,424,424,424,433,439,439,440,445,449,451,451,452,455,457,462,466,467,472,473,476,483,486,486,487,489,492,493,493,495,495,506,510,510,514,516,517,518,521,524,525,530,530,530,533,533,536,537,545,546,547,549,549,552,554,562,563,567,568,570,571,571,572,572,574,574,579,581,581,583,591,592,594,595,599,608,609,617,617,620,627,628,629,630,631,632,633,637,638,642,648,648,652,653,656,659,659,662,668,669,676,677,678,678,681,684,685,686,686,688,700,703,709,711,712,715,717,717,717,720,720,721,721,727,734,736,739,740,742,745,745,747,749,754,756,756,756,760,764,764,768,768,769,772,772,776,776,783,783,787,789,790,790,794,797,798,801,802,803,803,803,804,807,808,813,813,813,816,817,821,829,829,837,840,840,841,841,842,845,845,847,851,852,854,856,860,866,866,867,871,876,883,884,888,889,893,894,896,896,903,905,906,912,920,922,925,926,928,929,930,938,946,950,951,952,955,957,957,958,965,965,967,971,975,980,983,985,988,988,990,992,994,995,996,1000,1001,1003,1004,1005,1005,1006,1011,1013,1014,1016,1016,1017,1018,1020,1020,1025,1029,1032,1032,1033,1034,1034,1034,1036,1038,1040,1043,1046,1048,1052,1053,1056,1058,1060,1060,1063,1066,1070,1072,1073,1078,1080,1083,1083,1088,1089,1094,1094,1095,1100,1102,1106,1108,1108,1110,1111,1114,1116,1118,1119,1120,1122,1122,1128,1132,1137,1140,1143,1146,1146,1148,1153,1155,1159,1160,1160,1166,1167,1170,1170,1170,1173,1176,1183,1183,1186,1187,1188,1198,1207,1211,1220,1221,1223,1229,1229,1232,1237,1242,1244,1249,1258,1260,1262,1263,1264,1269,1271,1275,1284,1287,1287,1289,1290,1291,1292,1293,1300,1305,1308,1309,1310,1311,1312,1313,1319,1321,1325,1325,1329,1332,1332,1336,1336,1347,1350,1354,1355,1355,1356,1358,1358,1367,1370,1374,1375,1377,1377,1377,1377,1390,1391,1392,1395,1397,1404,1405,1408,1413,1415,1415,1415,1415,1417,1422,1423,1424,1425,1427,1428,1429,1430,1434,1434,1434,1436,1437,1438,1439,1445,1446,1448,1451,1452,1455,1457,1462,1463,1465,1467,1468,1469,1472,1474,1475,1475,1477,1477,1477,1479,1483,1485,1486,1487,1488,1489,1494,1496,1497,1503,1507,1507,1510,1512,1512,1522,1522,1526,1526,1528,1529,1535,1537,1539,1540,1542,1542,1542,1543,1543,1544,1545,1550,1551,1554,1555,1556,1560,1562,1565,1566,1573,1573,1576,1576,1578,1582,1585,1586,1587,1591,1592,1597,1597,1599,1599,1601,1606,1616,1620,1627,1632,1635,1635,1635,1637,1641,1641,1642,1642,1644,1647,1648,1648,1649,1649,1650,1652,1655,1656,1669,1670,1672,1678,1688,1688,1696,1696,1707,1709,1713,1714,1716,1717,1719,1724,1725,1734,1738,1740,1747,1748,1751,1758,1763,1764,1767,1768,1770,1779,1779,1779,1782,1784,1785,1785,1785,1790,1792,1792,1792,1795,1800,1800,1803,1806,1808,1810,1811,1814,1816,1817,1817,1818,1821,1822,1825,1828,1830,1835,1841,1841,1842,1843,1845,1846,1847,1848,1852,1855,1856,1858,1860,1862,1863,1864,1867,1869,1870,1875,1880,1885,1890,1891,1892,1893,1896,1911,1911,1916,1916,1917,1918,1924,1925,1926,1927,1928,1931,1932,1936,1936,1943,1947,1948,1952,1953,1966,1966,1967,1968,1969,1972,1974,1976,1980,1981,1983,1991,1991,1994,1994,1995,1999,2001,2009,2010,2011,2011,2014,2015,2017,2018,2023,2026,2033,2035,2035,2036,2039,2040,2049,2054,2057,2057,2060,2062,2063,2064,2070,2072,2074,2078,2079,2082,2083,2085,2094,2096,2096,2105,2108,2110,2113,2115,2124,2124,2126,2126,2128,2136,2141,2144,2145,2152,2154,2163,2165,2167,2172,2175,2175,2176,2179,2180,2181,2189,2191,2195,2197,2198,2199,2202,2202,2204,2204,2205,2207,2208,2209,2211,2212,2213,2213,2213,2214,2218,2223,2237,2237,2238,2239,2239,2241,2242,2244,2245,2248,2249,2250,2251,2251,2254,2258,2265,2268,2274,2275,2277,2279,2281,2284,2285,2286,2287,2289,2296,2303,2307,2308,2310,2313,2315,2318,2320,2324,2325,2326,2326,2327,2330,2331,2332,2336,2337,2338,2340,2348,2349,2351,2353,2358,2360,2361,2361,2361,2365,2366,2369,2370,2371,2372,2372,2374,2375,2376,2376,2381,2382,2386,2389,2396,2396,2399,2402,2406,2408,2413,2414,2414,2415,2417,2420,2420,2423,2423,2424,2425,2426,2427,2438,2440,2441,2443,2444,2445,2450,2454,2455,2457,2458,2463,2464,2469,2469,2470,2471,2472,2473,2474,2474,2476,2489,2491,2491,2491,2492,2493,2496,2498,2499,2500,2501,2502,2504,2515,2516,2520,2521,2521,2525,2525,2525,2530,2530,2533,2536,2536,2540,2544,2545,2547,2555,2556,2558,2562,2564,2567,2569,2575,2576,2578,2578,2579,2581,2583,2583,2584,2587,2587,2589,2589,2591,2592,2593,2598,2605,2605,2607,2615,2622,2623,2625,2628,2629,2629,2630,2631,2631,2632,2633,2633,2640,2652,2656,2657,2660,2663,2666,2666,2670,2670,2674,2680,2681,2690,2692,2693,2694,2694,2696,2696,2699,2700,2702,2706,2706,2711,2714,2715,2720,2722,2727,2728,2729,2739,2742,2742,2744,2745,2749,2751,2757,2764,2765,2766,2768,2770,2777,2777,2778,2779,2780,2781,2782,2784,2784,2785,2792,2792,2794,2801,2802,2802,2804,2806,2806,2807,2814,2815,2817,2820,2821,2822,2825,2827,2828,2835,2837,2840,2841,2841,2843,2849,2849,2851,2853,2863,2864,2867,2868,2869,2872,2872,2875,2878,2878,2882,2882,2882,2884,2885,2890,2890,2896,2897,2898,2900,2904,2909,2911,2913,2917,2917,2924,2925,2925,2928,2928,2932,2934,2935,2937,2937,2940,2941,2944,2946,2947,2948,2949,2949,2951,2953,2957,2961,2965,2967,2968,2968,2970,2971,2974,2975,2975,2980,2985,2987,2989,2990,2995,2995,2995,2998,3001,3002,3002,3003,3006,3007,3010,3014,3020,3023,3026,3034,3037,3038,3040,3041,3043,3045,3045,3051,3054,3056,3063,3067,3067,3069,3070,3071,3073,3078,3080,3081,3084,3086,3087,3087,3088,3090,3101,3110,3114,3114,3123,3127,3127,3133,3133,3135,3135,3137,3137,3141,3149,3150,3150,3159,3160,3160,3164,3165,3168,3168,3169,3171,3172,3176,3176,3180,3181,3183,3184,3187,3187,3189,3189,3194,3194,3197,3198,3200,3210,3212,3214,3218,3219,3222,3226,3228,3229,3231,3233,3251,3253,3257,3258,3260,3262,3262,3263,3264,3270,3270,3273,3275,3282,3282,3286,3290,3290,3291,3292,3293,3304,3308,3312,3313,3315,3316,3318,3319,3319,3325,3327,3327,3330,3331,3332,3334,3338,3339,3345,3353,3354,3355,3360,3365,3379,3385,3385,3385,3390,3391,3398,3398,3399,3405,3406,3410,3411,3413,3415,3419,3425,3425,3431,3431,3431,3434,3435,3441,3442,3443,3443,3444,3446,3447,3449,3451,3453,3454,3456,3456,3459,3461,3462,3462,3463,3465,3468,3471,3471,3472,3475,3475,3475,3477,3483,3484,3485,3492,3492,3496,3499,3501,3510,3511,3513,3514,3514,3515,3520,3523,3525,3526,3526,3526,3528,3529,3530,3539,3540,3542,3546,3549,3551,3552,3553,3555,3556,3557,3559,3562,3566,3567,3581,3583,3585,3585,3585,3585,3591,3592,3595,3597,3599,3601,3602,3607,3609,3610,3610,3611,3611,3615,3618,3623,3627,3627,3628,3629,3631,3631,3640,3640,3640,3646,3648,3649,3650,3651,3652,3655,3659,3659,3661,3666,3669,3670,3673,3673,3675,3677,3678,3680,3682,3689,3690,3692,3703,3703,3703,3707,3707,3712,3713,3722,3722,3723,3726,3726,3730,3734,3737,3744,3745,3748,3752,3757,3759,3760,3761,3765,3779,3779,3780,3780,3782,3784,3786,3787,3792,3792,3793,3796,3801,3802,3802,3803,3805,3809,3809,3810,3811,3812,3815,3817,3819,3819,3820,3822,3830,3832,3833,3834,3839,3840,3840,3844,3845,3848,3849,3850,3851,3852,3854,3854,3856,3856,3857,3862,3865,3871,3871,3876,3880,3881,3882,3887,3899,3902,3904,3904,3910,3916,3916,3919,3921,3925,3938,3958,3959,3959,3969,3981,3987,3988,3988,3992,3994,3996,3997,3998,3999,4005,4008,4010,4016,4018,4018,4019,4019,4025,4026,4026,4030,4030,4032,4032,4036,4039,4046,4048,4048,4049,4050,4053,4054,4055,4058,4061,4062,4063,4070,4072,4076,4079,4083,4090,4092,4096,4098,4101,4102,4108,4112,4115,4124,4130,4132,4133,4146,4152,4152,4152,4156,4157,4157,4161,4172,4173,4178,4180,4186,4188,4189,4192,4193,4194,4196,4197,4198,4198,4200,4201,4201,4201,4202,4203,4205,4206,4213,4214,4220,4223,4224,4224,4225,4226,4229,4236,4237,4239,4239,4244,4247,4248,4248,4248,4250,4251,4251,4253,4254,4256,4256,4266,4269,4272,4272,4275,4275,4278,4278,4285,4285,4285,4285,4286,4294,4295,4304,4309,4310,4312,4312,4320,4322,4324,4325,4330,4330,4331,4332,4340,4341,4342,4347,4351,4352,4354,4356,4356,4358,4367,4369,4371,4378,4380,4383,4383,4386,4389,4391,4396,4397,4399,4404,4404,4405,4406,4408,4408,4408,4410,4414,4414,4416,4419,4419,4421,4422,4422,4422,4422,4423,4424,4428,4429,4430,4431,4432,4434,4437,4439,4440,4441,4441,4442,4443,4445,4452,4453,4457,4458,4458,4463,4465,4466,4467,4467,4469,4470,4473,4477,4480,4481,4486,4486,4487,4494,4495,4496,4497,4501,4504,4506,4508,4510,4511,4512,4514,4515,4518,4519,4536,4538,4539,4542,4543,4547,4551,4555,4559,4561,4564,4570,4571,4572,4574,4577,4581,4581,4584,4584,4585,4601,4604,4606,4610,4611,4613,4613,4616,4620,4620,4622,4622,4622,4625,4627,4628,4633,4635,4637,4641,4642,4644,4646,4647,4647,4648,4650,4654,4659,4659,4662,4663,4663,4665,4665,4666,4669,4679,4683,4689,4689,4690,4690,4695,4696,4698,4702,4710,4710,4711,4713,4714,4716,4727,4738,4742,4743,4751,4751,4751,4753,4758,4758,4765,4766,4768,4771,4775,4775,4777,4779,4780,4782,4784,4790,4791,4793,4794,4799,4807,4808,4815,4817,4818,4823,4825,4829,4830,4837,4837,4839,4842,4846,4847,4848,4851,4853,4859,4860,4860,4864,4865,4869,4872,4878,4879,4879,4880,4888,4889,4891,4898,4901,4902,4904,4905,4908,4908,4910,4910,4910,4916,4917,4923,4927,4928,4928,4934,4934,4944,4945,4946,4947,4953,4960,4963,4964,4966,4967,4967,4969,4977,4980,4980,4980,4982,4984,4985,4985,4986,4986,4991,4993,4993,4997,4998,5001,5002,5003,5005,5006,5009,5011,5016,5018,5018,5018,5018,5022,5024,5025,5030,5031,5032,5033,5034,5040,5045,5045,5047,5047,5049,5058,5062,5067,5070,5072,5073,5077,5081,5082,5083,5083,5086,5087,5088,5092,5095,5097,5104,5104,5105,5106,5113,5113,5116,5117,5120,5122,5127,5127,5132,5133,5136,5139,5140,5141,5149,5155,5157,5159,5160,5161,5162,5163,5166,5166,5170,5173,5174,5178,5183,5184,5194,5195,5196,5201,5207,5207,5207,5208,5208,5209,5210,5211,5213,5232,5234,5236,5240,5240,5248,5249,5250,5253,5254,5264,5266,5266,5269,5278,5279,5280,5281,5285,5287,5288,5288,5295,5302,5305,5310,5311,5312,5313,5314,5314,5315,5316,5319,5320,5320,5327,5327,5328,5330,5331,5332,5333,5333,5340,5341,5346,5351,5353,5355,5356,5358,5358,5360,5360,5362,5373,5373,5373,5375,5375,5379,5379,5387,5390,5390,5392,5394,5395,5395,5395,5397,5402,5408,5413,5414,5415,5416,5416,5417,5417,5418,5424,5426,5426,5427,5430,5432,5445,5445,5447,5448,5450,5455,5466,5467,5468,5469,5469,5470,5473,5473,5473,5476,5478,5478,5480,5480,5481,5486,5486,5492,5496,5499,5501,5504,5511,5511,5512,5512,5515,5519,5523,5524,5525,5526,5529,5531,5535,5538,5538,5542,5542,5543,5543,5544,5547,5550,5551,5554,5557,5558,5571,5573,5573,5574,5585,5587,5594,5594,5595,5598,5599,5604,5613,5615,5618,5622,5623,5626,5628,5629,5629,5629,5633,5634,5634,5634,5642,5647,5651,5661,5662,5664,5667,5669,5674,5675,5676,5677,5680,5681,5682,5682,5683,5689,5692,5693,5694,5697,5701,5702,5703,5708,5709,5710,5710,5711,5714,5716,5717,5720,5721,5728,5738,5743,5745,5747,5748,5749,5750,5752,5757,5760,5766,5767,5772,5773,5774,5774,5775,5776,5777,5780,5789,5790,5796,5796,5796,5797,5801,5801,5805,5808,5813,5817,5819,5820,5823,5828,5832,5842,5844,5844,5845,5846,5849,5851,5859,5859,5861,5866,5866,5867,5877,5883,5884,5888,5890,5892,5894,5895,5898,5900,5900,5903,5905,5908,5910,5911,5915,5922,5924,5925,5931,5937,5938,5940,5941,5944,5945,5947,5948,5949,5951,5955,5965,5971,5975,5975,5976,5977,5984,5984,5986,5987,5988,5996,5998,6005,6006,6007,6010,6014,6016,6018,6018,6020,6020,6023,6027,6029,6030,6031,6031,6032,6033,6039,6040,6040,6040,6041,6049,6058,6060,6061,6062,6066,6067,6068,6070,6070,6070,6072,6073,6074,6076,6076,6076,6079,6081,6084,6085,6088,6088,6088,6089,6090,6093,6094,6097,6099,6102,6105,6107,6109,6112,6115,6115,6117,6119,6119,6119,6125,6125,6127,6128,6130,6134,6134,6139,6144,6144,6146,6147,6152,6157,6158,6162,6162,6169,6169,6171,6176,6183,6184,6188,6191,6193,6197,6199,6203,6213,6213,6216,6217,6220,6220,6220,6222,6225,6227,6230,6234,6238,6238,6242,6249,6254,6256,6257,6261,6262,6263,6265,6265,6268,6270,6271,6273,6273,6274,6278,6282,6286,6287,6305,6305,6311,6315,6318,6320,6320,6323,6326,6328,6331,6332,6334,6334,6335,6335,6336,6337,6342,6344,6347,6348,6352,6353,6354,6355,6355,6372,6373,6376,6384,6385,6387,6389,6394,6396,6397,6399,6399,6402,6404,6407,6410,6410,6411,6412,6419,6426,6427,6431,6431,6433,6438,6439,6447,6455,6456,6457,6457,6465,6469,6470,6472,6478,6478,6479,6480,6483,6483,6484,6493,6494,6499,6502,6508,6509,6510,6511,6513,6514,6517,6519,6525,6527,6531,6531,6538,6539,6545,6547,6550,6566,6567,6570,6571,6573,6574,6576,6577,6577,6578,6579,6584,6587,6588,6591,6592,6592,6607,6614,6615,6617,6624,6626,6628,6628,6628,6644,6647,6647,6652,6652,6655,6656,6660,6663,6663,6666,6666,6667,6671,6675,6683,6685,6689,6690,6691,6691,6693,6694,6695,6696,6702,6703,6713,6714,6716,6718,6719,6722,6726,6728,6728,6729,6731,6733,6734,6738,6740,6741,6742,6743,6745,6747,6748,6754,6756,6756,6758,6760,6761,6764,6764,6764,6766,6768,6770,6772,6778,6778,6779,6782,6782,6786,6787,6789,6791,6793,6793,6804,6807,6809,6810,6811,6812,6817,6818,6823,6827,6828,6837,6842,6848,6848,6854,6855,6856,6858,6858,6858,6859,6862,6865,6865,6868,6869,6869,6871,6875,6880,6881,6890,6893,6900,6901,6902,6904,6905,6905,6907,6908,6910,6910,6913,6923,6925,6928,6929,6930,6936,6937,6945,6945,6946,6947,6948,6948,6948,6950,6952,6953,6956,6957,6960,6966,6966,6969,6970,6975,6980,6986,6993,6993,6993,6994,6994,6995,6999,7000,7002,7004,7006,7009,7012,7014,7015,7015,7020,7021,7029,7030,7039,7039,7040,7040,7048,7050,7051,7053,7054,7056,7063,7073,7075,7076,7079,7082,7082,7088,7088,7092,7094,7096,7100,7100,7102,7103,7105,7106,7107,7108,7109,7109,7111,7115,7116,7117,7118,7120,7120,7121,7128,7129,7136,7146,7147,7147,7154,7156,7160,7162,7164,7165,7168,7174,7177,7178,7181,7183,7184,7188,7188,7188,7192,7195,7196,7198,7202,7208,7219,7224,7224,7224,7224,7228,7229,7229,7230,7231,7239,7245,7246,7246,7249,7250,7254,7257,7263,7265,7271,7273,7275,7280,7281,7282,7288,7290,7290,7290,7296,7300,7305,7307,7309,7316,7317,7317,7322,7322,7331,7332,7335,7335,7338,7339,7341,7347,7349,7350,7351,7353,7357,7359,7361,7361,7364,7365,7370,7372,7373,7378,7383,7386,7388,7391,7392,7395,7396,7398,7403,7405,7406,7409,7410,7412,7414,7419,7419,7420,7421,7424,7425,7428,7435,7438,7439,7441,7441,7444,7445,7446,7448,7452,7457,7458,7460,7460,7463,7479,7482,7483,7486,7486,7487,7487,7491,7492,7495,7497,7502,7503,7505,7506,7509,7510,7511,7512,7517,7517,7522,7525,7526,7528,7528,7530,7530,7532,7537,7541,7542,7544,7547,7547,7548,7552,7553,7563,7563,7570,7571,7573,7573,7577,7578,7581,7586,7587,7590,7591,7591,7601,7605,7609,7612,7613,7613,7614,7614,7619,7620,7620,7621,7623,7629,7630,7638,7639,7641,7643,7643,7644,7645,7647,7652,7656,7657,7662,7663,7664,7666,7666,7669,7670,7679,7680,7680,7681,7684,7686,7688,7689,7689,7690,7695,7707,7708,7709,7712,7712,7714,7716,7718,7721,7722,7727,7730,7731,7733,7738,7742,7744,7746,7751,7757,7758,7764,7771,7779,7784,7787,7788,7790,7790,7792,7793,7795,7795,7800,7814,7817,7817,7818,7819,7821,7825,7827,7830,7832,7833,7834,7835,7835,7836,7840,7840,7840,7846,7852,7854,7855,7858,7863,7868,7873,7874,7874,7878,7879,7883,7884,7886,7890,7893,7901,7905,7905,7910,7912,7922,7924,7927,7939,7943,7945,7953,7954,7956,7960,7961,7964,7966,7968,7976,7976,7979,7979,7981,7982,7986,7989,7991,7991,8000,8001,8005,8009,8011,8014,8016,8016,8019,8021,8023,8026,8028,8030,8032,8036,8037,8045,8046,8050,8050,8051,8053,8054,8063,8064,8066,8066,8069,8073,8073,8074,8075,8079,8081,8087,8088,8092,8093,8097,8098,8103,8105,8105,8111,8113,8114,8120,8120,8129,8132,8133,8138,8139,8142,8143,8144,8145,8151,8152,8155,8156,8157,8158,8159,8161,8165,8167,8167,8168,8170,8170,8171,8171,8176,8176,8180,8186,8191,8193,8195,8200,8200,8201,8207,8209,8213,8221,8226,8229,8241,8244,8248,8248,8249,8249,8255,8258,8259,8271,8273,8275,8275,8278,8279,8280,8282,8285,8289,8292,8294,8298,8300,8303,8305,8311,8313,8314,8317,8319,8321,8325,8332,8332,8341,8342,8343,8344,8344,8346,8346,8347,8347,8347,8356,8357,8361,8369,8369,8370,8376,8378,8385,8386,8388,8388,8389,8390,8391,8395,8399,8406,8408,8409,8412,8413,8419,8420,8421,8421,8422,8436,8440,8441,8442,8447,8448,8461,8467,8467,8467,8470,8475,8476,8480,8480,8481,8484,8488,8488,8489,8494,8494,8502,8504,8504,8504,8505,8511,8514,8518,8518,8518,8520,8521,8523,8525,8527,8528,8528,8530,8533,8533,8535,8535,8536,8539,8539,8543,8543,8546,8547,8547,8549,8551,8553,8554,8556,8557,8557,8561,8565,8565,8567,8569,8571,8572,8574,8579,8582,8584,8586,8589,8593,8594,8596,8596,8596,8596,8598,8599,8599,8602,8602,8604,8606,8614,8614,8615,8617,8617,8618,8619,8620,8624,8629,8633,8637,8640,8641,8642,8643,8644,8651,8652,8653,8656,8658,8660,8661,8661,8662,8664,8671,8672,8678,8679,8684,8686,8687,8691,8694,8702,8706,8706,8707,8708,8710,8716,8721,8722,8725,8727,8728,8731,8732,8732,8739,8740,8740,8741,8751,8754,8756,8759,8763,8764,8764,8778,8779,8780,8781,8790,8796,8796,8798,8804,8804,8807,8808,8812,8815,8818,8821,8825,8826,8830,8834,8835,8838,8844,8845,8845,8846,8847,8848,8849,8850,8855,8858,8862,8864,8864,8867,8872,8872,8873,8875,8878,8881,8882,8885,8887,8887,8897,8905,8907,8909,8915,8915,8915,8919,8930,8932,8936,8940,8940,8941,8944,8946,8946,8947,8947,8952,8952,8955,8958,8963,8967,8969,8979,8982,8983,8986,8986,8986,8990,8993,8997,8998,9000,9002,9002,9005,9009,9012,9013,9014,9019,9021,9026,9026,9028,9031,9031,9032,9032,9035,9039,9044,9046,9048,9048,9050,9052,9054,9056,9056,9061,9063,9066,9067,9069,9070,9073,9074,9075,9075,9077,9083,9083,9091,9094,9094,9098,9100,9101,9104,9108,9108,9115,9116,9117,9120,9125,9128,9133,9135,9135,9140,9144,9144,9148,9153,9159,9161,9166,9166,9171,9177,9177,9183,9186,9187,9187,9189,9191,9193,9194,9197,9203,9204,9205,9206,9214,9215,9215,9215,9217,9219,9226,9226,9227,9229,9230,9230,9231,9233,9236,9237,9240,9240,9241,9241,9241,9243,9245,9248,9251,9255,9256,9256,9259,9260,9261,9262,9263,9266,9268,9274,9274,9275,9278,9281,9283,9285,9286,9290,9295,9296,9297,9297,9299,9299,9301,9303,9305,9308,9310,9311,9312,9312,9312,9316,9317,9318,9318,9319,9323,9329,9330,9333,9335,9336,9340,9340,9341,9343,9343,9343,9343,9346,9349,9352,9353,9356,9363,9363,9368,9369,9373,9374,9379,9381,9385,9387,9387,9393,9394,9405,9408,9410,9413,9414,9416,9420,9421,9423,9426,9430,9441,9443,9443,9445,9446,9446,9448,9450,9450,9456,9466,9468,9473,9473,9475,9480,9482,9483,9485,9489,9492,9498,9500,9503,9506,9507,9509,9515,9518,9520,9522,9525,9526,9530,9531,9536,9547,9547,9548,9548,9551,9554,9555,9558,9558,9559,9567,9574,9582,9584,9584,9590,9592,9593,9598,9598,9599,9602,9602,9604,9606,9608,9610,9614,9620,9624,9633,9634,9638,9639,9642,9646,9649,9652,9657,9657,9660,9662,9663,9663,9664,9664,9669,9673,9678,9681,9684,9685,9687,9690,9691,9692,9697,9703,9706,9708,9709,9712,9715,9717,9718,9719,9720,9721,9726,9729,9729,9732,9734,9736,9742,9744,9744,9746,9748,9749,9749,9750,9751,9751,9756,9762,9762,9771,9772,9772,9779,9782,9785,9790,9792,9798,9801,9802,9804,9807,9814,9816,9822,9823,9825,9831,9832,9832,9832,9835,9844,9844,9845,9848,9851,9862,9862,9865,9869,9872,9874,9877,9883,9886,9888,9888,9889,9890,9890,9892,9893,9893,9895,9897,9898,9898,9905,9906,9908,9910,9911,9912,9920,9924,9926,9926,9926,9927,9928,9931,9932,9939,9941,9943,9944,9948,9952,9954,9954,9954,9956,9957,9967,9968,9974,9974,9979,9982,9983,9992,9992,9996,9998]

