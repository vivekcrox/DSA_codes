int sumMaxMinSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;   //store max
        deque<int> dq2;  //store min
        int ans = 0;
        
        //first window k size
        for(int i=0; i<k; i++){
            //chote element remove krdo.
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            //bada element remove krdo.
            while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
                dq2.pop_back();
            }
            //inserting index, so that we can check out of window element.
            dq.push_back(i);
            dq2.push_back(i);
        }

        //store answer for first window.
        ans += nums[dq.front()] + nums[dq2.front()];

        //remaining window ko process.
        for(int i=k; i<nums.size(); i++){
            //out of window element ko remove krdia.
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }
            if(!dq2.empty() && i-dq2.front() >= k){
                dq2.pop_front();
            }

            //ab firse curr element k liye chotte element ko remove krna h.
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            //ab firse curr element k liye baade element ko remove krna h.
            while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
                dq2.pop_back();
            }
            dq.push_back(i);
            dq2push_back(i);

            //current element ka ans store krna h.
            ans += nums[dq.front()] + nums[dq2.front()];
        }
        return ans;
    }