#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    MinStack() {
       stack = {}; 
    }
    
    void push(int val) {
        if (stack.empty()) {
            stack.push_back({val, val});
        } else{
            stack.push_back({val, min(val, stack.back().second)});
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first; 
    }
    
    int getMin() {
        return stack.back().second;
    }
private:
    vector<pair<int,int>> stack;
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top(); // return 0
    minStack.getMin(); // return -2
    return 0;
}
