#include <stack>
#include <utility>

class StockSpanner {
private:
    // Stack to store pairs of {price, span}
    std::stack<std::pair<int, int>> st;

public:
    StockSpanner() {
        // Initialization handled by std::stack constructor
    }
    
    int next(int price) {
        int span = 1;
        
        // Combine spans of all previous prices that are less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push the current price and its computed span onto the stack
        st.push({price, span});
        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */