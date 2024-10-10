#include <iostream>
#include <vector> 

using namespace std;

class MyQueue {
public:
    MyQueue() {
        inStack = {};
    }
    
    void push(int x) {
        inStack.push_back(x); 
    }
    
    int pop() {
        const int n = inStack.front();
        inStack.erase(inStack.begin());
        return n;
    }
    
    int peek() {
        return inStack.front(); 
    }
    
    bool empty() {
        return inStack.size() == 0; 
    }
private:
    vector<int> inStack; 
};

int main() {
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false
    return 0;
}