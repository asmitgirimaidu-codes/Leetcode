#include <vector>
#include <map>

class SummaryRanges {
private:
    std::map<int, int> intervals;

public:
    SummaryRanges() {}
    
    void addNum(int value) {
        // Find the first interval whose start is greater than value
        auto it = intervals.upper_bound(value);
        
        int start = value;
        int end = value;
        
        // Check the interval before upper_bound (it might overlap or merge with value)
        if (it != intervals.begin()) {
            auto prev_it = std::prev(it);
            // If the value is already inside this interval, do nothing
            if (prev_it->first <= value && value <= prev_it->second) {
                return;
            }
            // If the interval ends just before the value, we can merge
            if (prev_it->second + 1 == value) {
                start = prev_it->first;
                intervals.erase(prev_it);
            }
        }
        
        // Check the interval at upper_bound (it might merge with value from the right)
        if (it != intervals.end() && it->first == value + 1) {
            end = it->second;
            intervals.erase(it);
        }
        
        intervals[start] = end;
    }
    
    std::vector<std::vector<int>> getIntervals() {
        std::vector<std::vector<int>> result;
        for (auto& pair : intervals) {
            result.push_back({pair.first, pair.second});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */