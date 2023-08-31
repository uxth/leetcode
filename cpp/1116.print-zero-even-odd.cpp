/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 *
 * https://leetcode.com/problems/print-zero-even-odd/description/
 *
 * concurrency
 * Medium (56.02%)
 * Likes:    185
 * Dislikes: 115
 * Total Accepted:    15.2K
 * Total Submissions: 27.1K
 * Testcase Example:  '2'
 *
 * Suppose you are given the following code:
 * 
 * 
 * class ZeroEvenOdd {
 * public ZeroEvenOdd(int n) { ... }      // constructor
 * ⁠ public void zero(printNumber) { ... }  // only output 0's
 * ⁠ public void even(printNumber) { ... }  // only output even numbers
 * ⁠ public void odd(printNumber) { ... }   // only output odd numbers
 * }
 * 
 * 
 * The same instance of ZeroEvenOdd will be passed to three different
 * threads:
 * 
 * 
 * Thread A will call zero() which should only output 0's.
 * Thread B will call even() which should only ouput even numbers.
 * Thread C will call odd() which should only output odd numbers.
 * 
 * 
 * Each of the threads is given a printNumber method to output an integer.
 * Modify the given program to output the series 010203040506... where the
 * length of the series must be 2n.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: "0102"
 * Explanation: There are three threads being fired asynchronously. One of them
 * calls zero(), the other calls even(), and the last one calls odd(). "0102"
 * is the correct output.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5
 * Output: "0102030405"
 * 
 * 
 */

// @lc code=start
#include<semaphore.h>
class ZeroEvenOdd {
protected:
    sem_t z;
    sem_t e;
    sem_t o;
private:
    int n;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&z, 0, 1);
        sem_init(&e, 0, 0);
        sem_init(&o, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            sem_wait(&z);
            printNumber(0);
            if (i % 2)
                sem_post(&o);
            else
                sem_post(&e);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&e);
            printNumber(i);
            sem_post(&z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&o);
            printNumber(i);
            sem_post(&z);
        }
    }
};
// @lc code=end

