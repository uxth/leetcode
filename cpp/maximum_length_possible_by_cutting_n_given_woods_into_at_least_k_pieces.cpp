/*
Given an array wood[] of size N, representing the length of N pieces of wood and an integer K, at least K pieces of the same length need to be cut from the given wooden pieces. The task is to find the maximum possible length of these K wooden pieces that can be obtained.

Examples:

Input: wood[] = {5, 9, 7}, K = 3
Output: 5
Explanation:
Cut arr[0] = 5 = 5
Cut arr[1] = 9 = 5 + 4
Cut arr[2] = 7 = 5 + 2
Therefore, the maximum length that can be obtained by cutting the woods into 3 pieces is 5.

Input: wood[] = {5, 9, 7}, K = 4
Output: 4
Explanation:
Cut arr[0] = 5 = 4 + 1
Cut arr[1] = 9 = 2 * 4 + 1
Cut arr[2] = 7 = 4 + 3
Therefore, the maximum length that can be obtained by cutting the woods into 4 pieces is 4.
*/

/*
Approach: The problem can be solved using a Binary search. Follow the steps below to solve the problem:

Find the maximum element from the array wood[] and store it in a variable, say Max.
The value of L must lie in the range [1, Max]. Therefore, apply binary search over the range [1, Max].
Initialize two variables say, left = 1 and right = Max to store the range in which the value of L lies.
Check if it is possible to cut the woods into K pieces with length of each piece equal to (left + right) / 2 or not. If found to be true, then update left = (left + right) / 2.
Otherwise, update right = (left + right) / 2 .
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to cut
// woods into K pieces of length len
bool isValid(int wood[], int N, int len, int K)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        count += wood[i] / len;
    }
    return count >= K;
}

// Function to find the maximum value of L
int findMaxLen(int wood[], int N, int K)
{
    int left = 1;
    int right = *max_element(wood, wood + N);

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isValid(wood, N, mid, K))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return right;
}

int main()
{
    int wood[] = {5, 9, 7};
    int N = sizeof(wood) / sizeof(wood[0]);
    int K = 4;
    cout << findMaxLen(wood, N, K);
}