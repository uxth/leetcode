/*

Description
Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

Example 1

Input:

48
Output:

68
Example 2

Input:

15
Output:

35
Solution
If a is less than 10, then simply return a. Otherwise, first check the prime factors of a. If there exists a prime factor of a that is greater than 10, then it is impossible to represent a using the multiplication of several one-digit numbers, so return 0.

To find the smallest positive integer b, b must have the shortest length, so consider the maximum possible one-digit factor first. Therefore, loop over i from 9 to 2, and divide a by i until a can’t be divisible by i. Store the factors and append them in the reversing order to form b, and return.

*/

class Solution {
public:
    int smallestFactorization(int num) {
        if (num < 2) {
            return num;
        }
        long long ans = 0, mul = 1;
        for (int i = 9; i >= 2; --i) {
            if (num % i == 0) {
                while (num % i == 0) {
                    num /= i;
                    ans = mul * i + ans;
                    mul *= 10;
                }
            }
        }
        return num < 2 && ans <= INT_MAX ? ans : 0;
    }
};