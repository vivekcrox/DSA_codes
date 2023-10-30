//** Method-1 : push: O(1) , pop & peek: O(n).
class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {  //here pop is always done after push. that's why no need to check emptiness of stacks.
        int val = -1;
        if(!st2.empty()){
            val = st2.top();
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            val = st2.top();
        }
        st2.pop();
        return val;
    }
    
    int peek() {
        int front = -1;
        if(!st2.empty()){
            front = st2.top();
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            front = st2.top();
        }
        return front;
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()){
            return true;
        }
        return false;
    }
};

/***********************/
//** Method-1 : push: O(n) , pop & peek: O(1).
class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st1.empty()){
            st1.push(x);
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            //add x to st1
            st1.push(x);
            //again push elements from st2 to st1.
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    
    int pop() {
        int val = -1;
        if(!st1.empty()){
            val = st1.top();
            st1.pop();
        }
        return val;
    }
    
    int peek() {
        int val = -1;
        if(!st1.empty()){
            val = st1.top();
        }
        return val;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};