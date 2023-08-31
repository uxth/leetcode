/*
 * @lc app=leetcode id=1115 lang=cpp
 *
 * [1115] Print FooBar Alternately
 *
 * https://leetcode.com/problems/print-foobar-alternately/description/
 *
 * concurrency
 * Medium (59.03%)
 * Likes:    325
 * Dislikes: 28
 * Total Accepted:    32.8K
 * Total Submissions: 55.5K
 * Testcase Example:  '1'
 *
 * Suppose you are given the following code:
 * 
 * 
 * class FooBar {
 * ⁠ public void foo() {
 * for (int i = 0; i < n; i++) {
 * print("foo");
 * }
 * ⁠ }
 * 
 * ⁠ public void bar() {
 * for (int i = 0; i < n; i++) {
 * print("bar");
 * }
 * ⁠ }
 * }
 * 
 * 
 * The same instance of FooBar will be passed to two different threads. Thread
 * A will call foo() while thread B will call bar(). Modify the given program
 * to output "foobar" n times.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: "foobar"
 * Explanation: There are two threads being fired asynchronously. One of them
 * calls foo(), while the other calls bar(). "foobar" is being output 1 time.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: "foobarfoobar"
 * Explanation: "foobar" is being output 2 times.
 * 
 * 
 */

// @lc code=start
class FooBar {
private:
    int n;
    std::mutex l1, l2;
public:
    FooBar(int n) {
        this->n = n;
        l2.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            l1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            l2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            l2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            l1.unlock();
        }
        l2.unlock();
    }
};

// @lc code=end

