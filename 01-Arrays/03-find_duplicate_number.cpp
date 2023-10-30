int findDuplicate(vector<int>& nums) {
        // I) Sort and compare approach
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size()-1; i++){
        //     if(nums[i]==nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return -1;

        // II) visited solution(Negative marking method)
        // int ans = -1;
        // for(int i=0; i<nums.size(); i++){
        //     int index = abs(nums[i]);
        //     if(nums[index] < 0){
        //         ans = index;
        //         break;
        //     }

        //     //marked visited
        //     nums[index] *= -1;
        // }
        // return ans;

        // III) Positioning method
        while(nums[0] != nums[nums[0]]){
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];