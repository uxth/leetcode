/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (79.85%)
 * Likes:    684
 * Dislikes: 1496
 * Total Accepted:    111.1K
 * Total Submissions: 138.8K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 * 
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 * 
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 * 
 */

// @lc code=start
class Solution {
private:
    string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    unordered_map<string, string> longToshort, shortTolong;
    int idx;
    string generate()
    {
        int n = idx++;
        string res;
        while(n)
        {
            res += n%base64_chars.size();
            n/=base64_chars.size();
        }
        return res;
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(longToshort.count(longUrl)) return longToshort[longUrl];
        string url = generate();
        longToshort[longUrl] = url;
        shortTolong[url] = longUrl;
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortTolong.count(shortUrl)) return shortTolong[shortUrl];
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end

