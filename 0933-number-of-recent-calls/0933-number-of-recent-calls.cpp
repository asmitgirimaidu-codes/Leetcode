#include <queue>

class RecentCounter {
private:
    std::queue<int> q;

public:
    RecentCounter() {
        // Initialization handled by std::queue constructor
    }
    
    int ping(int t) {
        // Add the new request timestamp
        q.push(t);
        
        // Remove requests that are older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        // The size of the queue is the number of requests in the [t - 3000, t] range
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */