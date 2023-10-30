void reverseK(queue<int> &q, int k){
    //stepA: queue --> k elements in stack
    stack<int> s;
    int count = 0;
    int n = q.size();

    if(k<=0 || k>n)
        return;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k)
            break;
    }

    //stepB: stack -> q me wapas
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
        count++;
        if(count==k)
            break;
    }

    //stepC: n-k elements of Q pop krke push Q me
    count = 0;
    while(!q.empty() && n-k != 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k)
            break;
    }
}