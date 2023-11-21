/*

Description
Design an in-memory file system to simulate the following functions:

ls: Given a path in string format. If it is a file path, return a list that only contains this file’s name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.

mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don’t exist either, you should create them as well. This function has void return type.

addContentToFile: Given a file path and file content in string format. If the file doesn’t exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.

readContentFromFile: Given a file path, return its content in string format.

Example:

Input:

[“FileSystem”,”ls”,”mkdir”,”addContentToFile”,”ls”,”readContentFromFile”] [[],[”/”],[“/a/b/c”],[“/a/b/c/d”,”hello”],[”/”],[“/a/b/c/d”]]

Output:

[null,[],null,null,[“a”],”hello”]

Explanation:

Image text

Note:

You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
You can assume that all directory names and file names only contain lower-case letters, and same names won’t exist in the same directory.
Solution
Define a class Node. Each object of Node has a data field String path, a data field boolean isFile, and a data field List<Node> children. In FileSystem class, create a root of type Node. Besides, create a map that stores each file path with its corresponding content.

For the constructor, initialize the root and the map.

For method ls, find the node at the end of the path, and obtain the node’s children. If the node is a file, then use a list to store the file’s name and return the list. Otherwise, use a list to store the children’s paths and return the list.

For method mkdir, find all the nodes in the given path, and create the nodes if they do not exist.

For method addContentToFile, like mkdir, find all the nodes in the given path and create the nodes if they do not exist. For the last node which is the file, create the file using isFile = true. Then obtain the content of the file if it already exists, or an empty string otherwise, append the new content to the content, and update the file path with the updated content.

For method readContentFromFile, simply obtain the content from the map using the file path and return the content.

*/


// OJ: https://leetcode.com/problems/design-in-memory-file-system/
struct File {
    bool isDirectory = true;
    map<string, File*> contents;
    string name, content;
    File(string name) : name(name) {}
};
class FileSystem {
    File root = File("");
    File *getFile(string path, bool createFile = false) {
        istringstream ss(path);
        string name;
        auto fp = &root;
        getline(ss, name, '/');
        while (getline(ss, name, '/')) {
            if (fp->contents.count(name) == 0) {
                fp->contents[name] = new File(name);
            }
            fp = fp->contents[name];
        }
        if (createFile) fp->isDirectory = false;
        return fp;
    }
public:
    FileSystem() {}
    vector<string> ls(string path) {
        auto fp = getFile(path);
        if (fp->isDirectory) {
            vector<string> ans;
            for (auto &[name, fp] : fp->contents) {
                ans.push_back(name);
            }
            return ans;
        }
        return { fp->name };
    }
    void mkdir(string path) {
        getFile(path);
    }
    void addContentToFile(string filePath, string content) {
        getFile(filePath, true)->content += content;
    }
    string readContentFromFile(string filePath) {
        return getFile(filePath)->content;
    }
};