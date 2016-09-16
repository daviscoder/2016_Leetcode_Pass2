/**
 * 注意最后返回前检查stack是否为空栈.
 * 
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                myStack.push (s[i]);
            else if (s[i] == '}') {
                if (myStack.empty() || myStack.top() != '{')
                    return false;
                myStack.pop();
            }
            else if (s[i] == ']') {
                if (myStack.empty() || myStack.top() != '[')
                    return false;
                myStack.pop();
            }
            else {
                if (myStack.empty() || myStack.top() != '(')
                    return false;
                myStack.pop();
            }
        }
        return myStack.empty();
    }
};
