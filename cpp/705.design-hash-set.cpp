/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 *
 * https://leetcode.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (64.31%)
 * Likes:    497
 * Dislikes: 86
 * Total Accepted:    94.7K
 * Total Submissions: 147.2K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * Design a HashSet without using any built-in hash table libraries.
 * 
 * To be specific, your design should include these functions:
 * 
 * 
 * add(value): Insert a value into the HashSet. 
 * contains(value) : Return whether the value exists in the HashSet or not.
 * remove(value): Remove a value in the HashSet. If the value does not exist in
 * the HashSet, do nothing.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // returns true
 * hashSet.contains(3);    // returns false (not found)
 * hashSet.add(2);          
 * hashSet.contains(2);    // returns true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // returns false (already removed)
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 * 
 * 
 */

// @lc code=start
class MyHashSet {
private:
    vector<list<int>> data;
    const int n = 100;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data.resize(n);
    }
    
    void add(int key) {
        for(auto it=data[key%n].begin(); it!=data[key%n].end(); ++it) if(*it==key) return;
        data[key%n].push_back(key);
    }
    
    void remove(int key) {
        for(auto it=data[key%n].begin(); it!=data[key%n].end(); ++it) if(*it == key) {data[key%n].erase(it);return;}

    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(auto it=data[key%n].begin(); it!=data[key%n].end(); ++it) if(*it==key) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

