/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 *
 * https://leetcode.com/problems/iterator-for-combination/description/
 *
 * algorithms
 * Medium (68.13%)
 * Likes:    460
 * Dislikes: 40
 * Total Accepted:    33.2K
 * Total Submissions: 47.1K
 * Testcase Example:  '["CombinationIterator","next","hasNext","next","hasNext","next","hasNext"]\r\n' +
  '[["abc",2],[],[],[],[],[],[]]\r'
 *
 * Design an Iterator class, which has:
 * 
 * 
 * A constructor that takes a string characters of sorted distinct lowercase
 * English letters and a number combinationLength as arguments.
 * A function next() that returns the next combination of length
 * combinationLength in lexicographical order.
 * A function hasNext() that returns True if and only if there exists a next
 * combination.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * CombinationIterator iterator = new CombinationIterator("abc", 2); // creates
 * the iterator.
 * 
 * iterator.next(); // returns "ab"
 * iterator.hasNext(); // returns true
 * iterator.next(); // returns "ac"
 * iterator.hasNext(); // returns true
 * iterator.next(); // returns "bc"
 * iterator.hasNext(); // returns false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= combinationLength <= characters.length <= 15
 * There will be at most 10^4 function calls per test.
 * It's guaranteed that all calls of the function next are valid.
 * 
 * 
 */

// @lc code=start
set<string> GenaretallComb(string s,int len){
    int mask = 1<<s.length();
    set<string>hold;
    string comString = "";
    for(int no=1;no<mask;no++){
        int num = no,i = 0;
        while(num){
            if(num&1)comString = comString + s[i];
            i++,num>>=1;
        }
        if(comString.length()==len)hold.insert(comString);
        comString = "";
    }
    return hold;
}

class CombinationIterator {
public:
    set<string>st;
    set <string> :: iterator cur;
    CombinationIterator(string characters, int combinationLength) {
        this->st = GenaretallComb(characters,combinationLength);
        this->cur = begin(st);
    }
    
    string next() {
        return cur==end(st)?"":*cur++;
    }
    
    bool hasNext() {
        return cur!=end(st);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

