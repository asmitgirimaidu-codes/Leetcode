class Solution {
private:
    unordered_map<string, string> mapIdToUrl;
    unordered_map<string, string> mapUrlToId;
    int id = 0;
    const string base = "http://tinyurl.com/";

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (mapUrlToId.find(longUrl) != mapUrlToId.end()) {
            return base + mapUrlToId[longUrl];
        }
        string shortKey = to_string(++id);
        mapIdToUrl[shortKey] = longUrl;
        mapUrlToId[longUrl] = shortKey;
        return base + shortKey;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string shortKey = shortUrl.substr(base.length());
        return mapIdToUrl[shortKey];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));