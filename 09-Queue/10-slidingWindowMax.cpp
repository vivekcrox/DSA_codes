// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        //first window k size
        for(int i=0; i<k; i++){
            //chote element remove krdo.
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            //inserting index, so that we can check out of window element.
            dq.push_back(i);
        }

        //store answer for first window.
        ans.push_back(nums[dq.front()]);

        //remaining window ko process.
        for(int i=k; i<nums.size(); i++){
            //out of window element ko remove krdia.
            if(!dq.empty() && i-dq.front() >= k){
                dq.pop_front();
            }

            //ab firse curr element k liye chotte element ko remove krna h.
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            //current element ka ans store krna h.
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};