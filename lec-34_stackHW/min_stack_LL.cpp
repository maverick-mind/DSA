class MinStack {
        stack<int> main_stack;
        stack<int> min_stack;
public:
    MinStack() { // initialises the stack object

    }

    void push(int val) {
        main_stack.push(val);
        if (!min_stack.empty() or val < min_stack.top()) {
            min_stack.push(val);
        }
    }

    void pop() {
        if (!main_stack.empty()) {
            int val = main_stack.top();
            main_stack.pop();
            if (val == min_stack.top())
            {
                min_stack.pop();
            }
        }
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_stack.top() ;
    }
};