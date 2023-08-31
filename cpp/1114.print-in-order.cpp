/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 *
 * https://leetcode.com/problems/print-in-order/description/
 *
 * concurrency
 * Easy (65.69%)
 * Likes:    525
 * Dislikes: 89
 * Total Accepted:    54.5K
 * Total Submissions: 82.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Suppose we have a class:
 * 
 * 
 * public class Foo {
 * public void first() { print("first"); }
 * public void second() { print("second"); }
 * public void third() { print("third"); }
 * }
 * 
 * 
 * The same instance of Foo will be passed to three different threads. Thread A
 * will call first(), thread B will call second(), and thread C will call
 * third(). Design a mechanism and modify the program to ensure that second()
 * is executed after first(), and third() is executed after second().
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: "firstsecondthird"
 * Explanation: There are three threads being fired asynchronously. The input
 * [1,2,3] means thread A calls first(), thread B calls second(), and thread C
 * calls third(). "firstsecondthird" is the correct output.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,2]
 * Output: "firstsecondthird"
 * Explanation: The input [1,3,2] means thread A calls first(), thread B calls
 * third(), and thread C calls second(). "firstsecondthird" is the correct
 * output.
 * 
 * 
 * 
 * Note:
 * 
 * We do not know how the threads will be scheduled in the operating system,
 * even though the numbers in the input seems to imply the ordering. The input
 * format you see is mainly to ensure our tests' comprehensiveness.
 * 
 */

// @lc code=start
// class Foo {   
//     mutex m1, m2;
// public:
//     Foo() {
//         m1.lock(), m2.lock();
//     }

//     void first(function<void()> printFirst) {
//         // printFirst() outputs "first". Do not change or remove this line.
//         printFirst();
//         m1.unlock();
//     }

//     void second(function<void()> printSecond) {
//         m1.lock();
//         // printSecond() outputs "second". Do not change or remove this line.
//         printSecond();
//         m1.unlock();
//         m2.unlock();
//     }

//     void third(function<void()> printThird) {
//         m2.lock();
//         // printThird() outputs "third". Do not change or remove this line.
//         printThird();
//         m2.unlock();
//     }
// };


class Foo {
private:
  std::promise<void> p1;
  std::promise<void> p2;

public:
  void first(function<void()> printFirst) {
    printFirst();
    p1.set_value();
  }

  void second(function<void()> printSecond) {
    p1.get_future().wait();
    printSecond();
    p2.set_value();
  }

  void third(function<void()> printThird) {
    p2.get_future().wait();
    printThird();
  }
};

// @lc code=end

