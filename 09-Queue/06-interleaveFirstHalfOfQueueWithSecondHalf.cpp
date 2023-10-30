void interleaveQueue(queue<int> &q) {
        //Step A: separate both halves
        int n = q.size();
        if(q.empty())
                return;
        int k = n/2;
        int count = 0;
        queue<int> q2;

        while(!q.empty()) {
                int temp = q.front();
                q.pop();
                q2.push(temp);
                count++;

                if(count == k)
                        break;
        }

        //stepB: interleaving start krdo
        while(!q.empty() && !q2.empty()) {
                int first = q2.front();
                q2.pop();

                q.push(first);

                int second = q.front();
                q.pop();

                q.push(second);
        }
        //odd wala case : ek extra element remains in q
        if(n&1) {
               int element = q.front();
               q.pop();
               q.push(element);
        }
}