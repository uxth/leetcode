/*
 * @lc app=leetcode id=1195 lang=cpp
 *
 * [1195] Fizz Buzz Multithreaded
 *
 * https://leetcode.com/problems/fizz-buzz-multithreaded/description/
 *
 * concurrency
 * Medium (68.28%)
 * Likes:    161
 * Dislikes: 93
 * Total Accepted:    11.1K
 * Total Submissions: 16.2K
 * Testcase Example:  '15'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n, however:
 * 
 * 
 * If the number is divisible by 3, output "fizz".
 * If the number is divisible by 5, output "buzz".
 * If the number is divisible by both 3 and 5, output "fizzbuzz".
 * 
 * 
 * For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz,
 * buzz, 11, fizz, 13, 14, fizzbuzz.
 * 
 * Suppose you are given the following code:
 * 
 * 
 * class FizzBuzz {
 * public FizzBuzz(int n) { ... }               // constructor
 * ⁠ public void fizz(printFizz) { ... }          // only output "fizz"
 * ⁠ public void buzz(printBuzz) { ... }          // only output "buzz"
 * ⁠ public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
 * ⁠ public void number(printNumber) { ... }      // only output the numbers
 * }
 * 
 * Implement a multithreaded version of FizzBuzz with four threads. The same
 * instance of FizzBuzz will be passed to four different threads:
 * 
 * 
 * Thread A will call fizz() to check for divisibility of 3 and outputs
 * fizz.
 * Thread B will call buzz() to check for divisibility of 5 and outputs
 * buzz.
 * Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and
 * outputs fizzbuzz.
 * Thread D will call number() which should only output the numbers.
 * 
 * 
 */

// @lc code=start
class FizzBuzz {
private:
    int n;
    int count;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->count = 1;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 3 != 0 || count % 5 == 0))
                cv.wait(lock);
            if (count > n) return;
            printFizz();
            ++count;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 == 0))
                cv.wait(lock);
            if (count > n) return;
            printBuzz();
            ++count;
            cv.notify_all();
        }
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 != 0 || count % 3 != 0))
                cv.wait(lock);
            if (count > n) return;
            printFizzBuzz();
            ++count;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (count <= n && (count % 5 == 0 || count % 3 == 0))
                cv.wait(lock);
            if (count > n) return;
            printNumber(count++);
            cv.notify_all();
        }
    }
};
// @lc code=end

