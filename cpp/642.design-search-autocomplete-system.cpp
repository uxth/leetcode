/*

Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#').

You are given a string array sentences and an integer array times both of length n where sentences[i] is a previously typed sentence and times[i] is the corresponding number of times the sentence was typed. For each input character except '#', return the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.

Here are the specific rules:

The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
If less than 3 hot sentences exist, return as many as you can.
When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.
Implement the AutocompleteSystem class:

AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
List<String> input(char c) This indicates that the user typed the character c.
Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed. If there are fewer than 3 matches, return them all.
 

Example 1:

Input
["AutocompleteSystem", "input", "input", "input", "input"]
[[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
Output
[null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]

Explanation
AutocompleteSystem obj = new AutocompleteSystem(["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]);
obj.input("i"); // return ["i love you", "island", "i love leetcode"]. There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.
obj.input(" "); // return ["i love you", "i love leetcode"]. There are only two sentences that have prefix "i ".
obj.input("a"); // return []. There are no sentences that have prefix "i a".
obj.input("#"); // return []. The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.
 

Constraints:

n == sentences.length
n == times.length
1 <= n <= 100
1 <= sentences[i].length <= 100
1 <= times[i] <= 50
c is a lowercase English letter, a hash '#', or space ' '.
Each tested sentence will be a sequence of characters c that end with the character '#'.
Each tested sentence will have a length in the range [1, 200].
The words in each input sentence are separated by single spaces.
At most 5000 calls will be made to input.
Algorithm
Thinking direction
For text search, there is no doubt that you need to use Prefix tree, trie.
Find all possible word/leaf, two options:
After Trie is built, do prefix search, then DFS/BFS return all leaf items. [high runtime complexity]
Store all possible words in TrieNode. [high space usage]
in memory space should not be a big problem, so we can choose to store all possible words
Given k words, find top k frequent items. MinHeap must be used, but there are two options:
Store MinHeap with TrieNode: Because it will continue to search for new entries, the same prefix (especially at higher level) will be searched multiple times.
[complexity: need to update heaps across all visited TrieNodes once new sentence is completed]
Compute MinHeap on the fly: Of course, we can’t come to a DFS every time, otherwise it will be very slow, so we must store a list of possible candidates in TrieNode.
The Map<String, freq> in Top K Frequent Words is used here, so O(m) is actually very convenient to construct min-heap.
Train the system
Every time an entry is marked after # to be added into search history. Then insert it into trie.
This one can be done after meeting # at the end, very concise
The problem is very long, but not too difficult, it can be solved with Trie, but you need to pay attention:

In input(), you need to read and write, but note that it must be read and then written, otherwise the sentence just inserted in will be detected
When encountering’#’, return to empty list
To return the sentences stored in Trie, one approach is to add a member variable str to Trie to store the str formed on the path from root to curr. Another approach is to pass str as a parameter to child when querying. This topic uses the latter idea.
In dfs trie, you must now add root to the result set, and then traverse the children! Otherwise, the root at the bottom of the stack will be missed. This is very important. Trie’s queries must be written like this.
In findTopK(), you can use PriorityQueue to do it, you can also use List to do and then sort.

*/