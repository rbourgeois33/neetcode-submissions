class MinStack {
public:
    MinStack() {
        index_=-1;
    }
    
    void push(int val) {
        if((index_==-1) || (val<=minstack_.top())) minstack_.push(val);
        index_++;
        vector_[index_]=val;
        
    }
    
    void pop() {
        if ((vector_[index_]==minstack_.top()))minstack_.pop();
        index_--;
    }
    
    int top() {
        return vector_[index_];
    }
    
    int getMin() {
        return minstack_.top();
    }
private:
    std::array<int,3*10*10*10*10> vector_{};
    std::stack<int> minstack_;
    int index_;
};
