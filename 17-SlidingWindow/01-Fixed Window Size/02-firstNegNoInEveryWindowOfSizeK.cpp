vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
                                                 
                                                 
    long long int i=0, j=0;
    vector<long long int> ans;
    deque<long long int> dq;
    
    while(j < N){
        if(A[j] < 0){
            dq.push_back(A[j]);
        }
        if(j-i+1 < K){
            j++;
        }
        else if(j-i+1 == K){
            if(dq.size() == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(dq.front());
                if(A[i]==dq.front()){
                    dq.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return ans;
 }