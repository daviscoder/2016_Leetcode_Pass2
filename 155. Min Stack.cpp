/**
 * All operations are O(1).
 * minStack 始终保持和s size相等，但是栈顶元素始终是当前s中的最小值.
 */

class MinStack {
public:
    stack<int> s;
    stack<int> minStack;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if (minStack.empty()) {
            minStack.push(x);
        }
        else {
            int tmp = min (minStack.top(), x);
            minStack.push(tmp);
        }
    }
    
    void pop() {
        minStack.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
