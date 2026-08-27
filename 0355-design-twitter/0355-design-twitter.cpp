#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Twitter {
private:
    int timeStamp;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> list of (timeStamp, tweetId)
    unordered_map<int, unordered_set<int>> following;  // userId -> set of followeeIds

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Max-heap to store (timeStamp, tweetId)
        priority_queue<pair<int, int>> maxHeap;
        
        // Add user's own tweets
        if (tweets.count(userId)) {
            for (const auto& tweet : tweets[userId]) {
                maxHeap.push(tweet);
            }
        }
        
        // Add followees' tweets
        if (following.count(userId)) {
            for (int followeeId : following[userId]) {
                if (tweets.count(followeeId)) {
                    for (const auto& tweet : tweets[followeeId]) {
                        maxHeap.push(tweet);
                    }
                }
            }
        }
        
        // Extract up to 10 most recent tweets
        vector<int> res;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */