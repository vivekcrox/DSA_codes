    int kthSmallest(int arr[], int l, int r, int k) {
        int n = r-l+1;
        if(n < k){
            return -1;
        }
        priority_queue<int> pq;  // max heap
        // storing first k elements on heap
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        // if element > pq.top() -> then pop top and push this element after that return pq.top
        for(int i=k; i<n; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
    /****************************************************************************/
    int findKthLargest(vector<int>& nums, int k) {
        // //Approach 1: 
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];
        
//         // Approach 2: max heap
//         priority_queue<int> pq(nums.begin(), nums.end());
        
//         int ans = 0;
//         while(k--){
//             ans = pq.top();
//             pq.pop();
//         }
        
//         return ans;
        
        // Approach 3: min heap (better approach)
        priority_queue<int, vector<int>, greater<int>> pq;  // Min Heap
        
        for(auto x: nums){
            pq.push(x);
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        return pq.top(); 
    }
