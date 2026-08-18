#include <stack>

class MyQueue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

    // Helper function to transfer elements if outputStack is empty
    void transfer() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        transfer();
        int val = outputStack.top();
        outputStack.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */