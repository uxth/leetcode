/*

Description
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

Image text

as [1 [3[5 6] 2 4]]. Note that this is just an example, you do not necessarily need to follow this format.

Or you can follow LeetCode’s level order traversal serialization format, where each group of children is separated by the null value.

Image text

For example, the above tree may be serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

You do not necessarily need to follow the above suggested formats, there are many more different formats that work so please be creative and come up with different approaches yourself.

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between `[0, 10^4]
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Solution
1). Serialization
If the tree is empty, return an empty string.

Do preorder traversal on the N-ary tree.

Use a stack to store the nodes to be visited.
Use parentheses to represent different levels and the children of each node.
2). Deserialization
If the serialization string is empty, return null.

Split the serialization string using ' '. Each term is a value of a node, a left parenthesis or a right parenthesis.

Use two stacks to store the nodes and the split terms.
Also use a map to store each node’s parent.
Loop over the split terms. If a left parenthesis is met, then the next term will be the previous node’s child. If a right parenthesis is met, then move to the parent of the current node. Otherwise, create a node using the current value. Finally, return the root.
*/
class Solution {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }
    
    void serializeHelper(Node* node, string& res) {
        if (!node) res += "#";
        else {
            res += to_string(node->val) + " " + to_string(node->children.size()) + " ";
            for (auto child : node->children) {
                serializeHelper(child, res);
            }
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
    Node* deserializeHelper(istringstream& iss) {
        string val = "", size = "";
        iss >> val;
        if (val == "#") return NULL;
        iss >> size;
        Node *node = new Node(stoi(val), {});
        for (int i = 0; i < stoi(size); ++i) {
            node->children.push_back(deserializeHelper(iss));
        }
        return node;
    }
};