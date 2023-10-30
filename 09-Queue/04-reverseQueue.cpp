void reverseQ(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        
        s.push(element);
    }

    // put all element from stack to Q
    while(!s.empty()){
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

//Using Recursion
void revQRE(queue<int> &q){
    //base
    if(q.empty()){
        return;
    }

    int temp = q.front();
    q.pop();

    revQRE(q);

    q.push(temp);
}