/*


Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
Solution
In the constructor, split out each term that is a (character, count) pair. Then for each pair, split out the character and the count. Use two arrays to store the letters and the corresponding counts respectively. Both arrays have the same length. Initialize the index to 0.

For next operation, if there exists a next character, then obtain the character at the index as the return value, decrease the count at the index by 1. If the count at the index becomes 0 after decreasing, move to the next index. Return the character which is the return value. If there doesn’t exist a next character, return a space.

For hasNext operation, simply return whether the index is less than the length of both arrays.

*/

// OJ: https://leetcode.com/problems/design-compressed-string-iterator
// Time: O(1)
// Space: O(1)
class StringIterator {
private:
  string str;
  int index = 0, nextIndex = 0, cnt = 0;
  void load() {
    while (index < str.size() && !cnt) {
      index = nextIndex;
      nextIndex = index + 1;
      while (nextIndex < str.size() && isdigit(str[nextIndex])) cnt = cnt * 10 + str[nextIndex++] - '0';
    }
  }
public:
  StringIterator(string compressedString) : str(compressedString) {
    load();
  }

  char next() {
    if (!hasNext()) return ' ';
    char ans = str[index];
    --cnt;
    load();
    return ans;
  }

  bool hasNext() {
    return index < str.size();
  }
};