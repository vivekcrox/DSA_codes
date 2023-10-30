int binSearch(vector<int> nums, int s, int target){
        int e = nums.size()-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return -1;
    }    
    int findPairs(vector<int>& nums, int k) {
        //(I)Using two pointers approach
        // sort(nums.begin(), nums.end());
        // set<pair<int,int> > ans;
        // int i = 0, j = 1;
        // while(j < nums.size()){
        //     int diff = nums[j] - nums[i];
        //     if(diff == k){
        //         ans.insert({nums[i], nums[j]});
        //         i++; j++;
        //     }else if(diff > k){
        //         i++;
        //     }else{
        //         j++;
        //     }
            
        //     if(i==j){
        //         j++;
        //     }
        // }
        // return ans.size();

        //(II)Using Binary Search

        

        sort(nums.begin(), nums.end());
        set<pair<int,int> > ans;

        for(int i = 0; i < nums.size(); i++){
            if(binSearch(nums, i+1, nums[i]+k) != -1){
                ans.insert({nums[i], nums[i]+k});
            }
        }
        return ans.size();
    }